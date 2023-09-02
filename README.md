# LibraryManagementSystem
This project helps to manage the library . This will help to add, delete, view , search ,issue a book in the library. This has the various functions for  managing the library management.
Features
Add Books: Allows users to add new books to the library database by providing book ID, book name, and author name.

Delete Books: Enables users to delete books from the library database by specifying the book ID.

View Books: Displays a list of all books in the library database.

Search Book: Allows users to search for a specific book by its ID and displays its details if found.

Issue Books: Lets users issue books to students by specifying the book ID and student name.

Close Application: Exits the program.

Usage
Upon running the program, you will be presented with a main menu.

Choose an option by entering the corresponding number:

1: Add Books
2: Delete Books
3: View Books
4: Search Book
5: Issue Books
6: Close Application
Follow the on-screen prompts to perform the selected operation.

After each operation, the program will indicate whether it was successful or not.

You can continue using the program until you choose to close it.

Data Storage
The program stores book data in a binary file named bookLibrary.dat.

When you add, delete, or issue books, the program modifies this binary file.

Notes
Book names and author names are limited to 19 characters to ensure data fits within the defined data structures.

Error handling is included to handle file I/O issues and invalid inputs.

