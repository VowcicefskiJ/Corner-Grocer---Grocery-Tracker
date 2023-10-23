Grocery Frequency Tracker
Overview
The Grocery Frequency Tracker is a C++ program designed to manage and analyze the frequency of grocery items. The program reads data from an input file containing grocery items and their respective quantities, and then provides various functionalities such as searching for an item's frequency, listing all items with their frequencies, displaying a histogram of item frequencies, and creating a backup data file.

Features
Load Data: Reads items and their quantities from an input file (CS210_Project_Three_Input_File.txt) and populates a map with this data.

List Items: Lists all the grocery items along with their frequencies.

Search for an Item: Allows the user to search for a specific item and displays its frequency.

Display Histogram: Displays a histogram where each item is represented by a number of asterisks corresponding to its frequency.

Create Backup: Creates a backup data file (frequency.dat) containing all the items and their frequencies.

Usage
Ensure the input file CS210_Project_Three_Input_File.txt is present in the same directory as the program.
Compile and run the program.
Interact with the menu to perform various operations:
Search for an item's frequency
List all items with their frequencies
Display a histogram of item frequencies
Create a backup data file
Exit the program
Error Handling
The program provides comprehensive error handling, especially when dealing with file operations. If there's an issue opening the input or output file, the program will display an error message and exit.

Future Enhancements

Implement a more user-friendly interface, perhaps with a GUI.
Add further validation checks, especially when reading data from the input file.
Consider implementing a database instead of file-based storage for enhanced data security and scalability.

Contribution
Feel free to fork this repository and contribute to enhancing the features of the Grocery Frequency Tracker. Any contributions, bug reports, bug fixes, documentation improvements, enhancements, and ideas are welcome.
