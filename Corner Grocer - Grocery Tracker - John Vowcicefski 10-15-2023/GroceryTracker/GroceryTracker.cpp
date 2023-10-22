#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Function to load data from the input file into a map
// This function reads items and their quantities from the file and updates the map accordingly
void loadData(map<string, int>& groceryMap)
{
    // Open the input file for reading
    ifstream inputFile("CS210_Project_Three_Input_File.txt");

    // Check if the file was opened successfully
    if (!inputFile)
    {
        cerr << "Error: Cannot open input file." << endl;
        exit(1);
    }

    string item; // Variable to store the item name
    int quantity; // Variable to store the item quantity

    // Read item and quantity from the file until end of file is reached
    while (inputFile >> item >> quantity)
    {
        // Update the map with the item and its quantity
        groceryMap[item] += quantity;
    }

    // Close the input file
    inputFile.close();
}

// Function to list all items with their frequencies
// This function iterates over the map and prints each item and its frequency
void listItems(const map<string, int>& groceryMap)
{
    for (const auto& entry : groceryMap)
    {
        cout << entry.first << " " << entry.second << endl;
    }
}

// Function to display a histogram of item frequencies
// For each item, this function prints a number of asterisks corresponding to its frequency
void displayHistogram(const map<string, int>& groceryMap)
{
    for (const auto& entry : groceryMap)
    {
        cout << entry.first << " ";
        for (int i = 0; i < entry.second; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// Function to create a backup data file
// This function writes the contents of the map to a file named frequency.dat
void createDataBackup(const map<string, int>& groceryMap)
{
    // Open the output file for writing
    ofstream outputFile("frequency.dat");

    // Check if the file was opened successfully
    if (!outputFile)
    {
        cerr << "Error: Cannot create data backup file." << endl;
        exit(1);
    }

    // Write each item and its frequency to the file
    for (const auto& entry : groceryMap)
    {
        outputFile << entry.first << " " << entry.second << endl;
    }

    // Close the output file
    outputFile.close();
}

int main()
{
    // Map to store items and their frequencies
    map<string, int> groceryMap;

    // Load data from the input file into the map
    loadData(groceryMap);

    string searchItem; // Variable to store the item to be searched
    int choice; // Variable to store the user's menu choice

    do
    {
        // Display the menu options
        cout << "Menu Options:\n";
        cout << "1. Search for an item's frequency\n";
        cout << "2. List all items with their frequencies\n";
        cout << "3. Display a histogram of item frequencies\n";
        cout << "4. Create a backup data file\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";

        // Read the user's choice and validate the input
        while (!(cin >> choice) || choice < 1 || choice > 5)
        {
            cout << "Invalid choice. Please select a valid option (1-5): ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        // Process the user's choice
        switch (choice)
        {
        case 1:
            // Menu Option One: Search for an item's frequency
            cout << "Enter the item you want to search for: ";
            cin >> searchItem;
            if (groceryMap.find(searchItem) != groceryMap.end())
            {
                cout << "Frequency of " << searchItem << ": " << groceryMap[searchItem] << endl;
            }
            else
            {
                cout << "Item not found in the records." << endl;
            }
            break;

        case 2:
            // Menu Option Two: List all items with their frequencies
            listItems(groceryMap);
            break;

        case 3:
            // Menu Option Three: Display a histogram of item frequencies
            displayHistogram(groceryMap);
            break;

        case 4:
            // Menu Option Four: Create a backup data file
            createDataBackup(groceryMap);
            cout << "Backup data file 'frequency.dat' created." << endl;
            break;

        case 5:
            // Menu Option Five: Exit
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice. Please select a valid option (1-5)." << endl;
            break;
        }
    } while (choice != 5); // Repeat until the user chooses to exit

    return 0;
}
