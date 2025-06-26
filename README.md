# MULTITHREADED--FILE-COMPRESSION-TOOL

COMPANY NAME:CODETECH IT SOLUTION

NAME: VEDVYAS KUMAR

INTERN ID:CT04DF160

DOMAIN:C++

MENTOR:NEELA SANTOSH

#DESCRIPTION

the provided C++ program implements a basic Run-Length Encoding (RLE) algorithm, a simple yet effective data compression technique. The goal of RLE is to reduce the size of repetitive data by replacing sequences of the same character with a single instance of that character followed by the number of times it appears consecutively. This program allows users to compress or decompress text data stored in files using the RLE method.

Overview
Upon execution, the program presents a simple menu to the user with two options:

Compress a file

Decompress a file

The user is prompted to select one of the options and then enter the names of the input and output files. Depending on the choice, the program reads the input file, applies compression or decompression, and writes the result to the output file.

Compression Logic
The core of the compression functionality lies in the compressRLE() function. This function takes a string of data and compresses it using RLE by counting the number of times each character repeats in sequence. For instance, the input string AAABBBCCDAA is compressed into A3B3C2D1A2. The function starts with an initial character and iterates through the string, comparing each character to the one before it. If the characters match, it increments a counter; otherwise, it appends the current character and its count to the result string and resets the counter. This process continues until the entire string is processed.

However, the function must be implemented carefully to avoid out-of-bounds errors, especially when handling strings with a single character or an empty input. These edge cases can cause runtime errors if not properly managed.

Decompression Logic
The decompressRLE() function reverses the compression process. It reads characters and the digits that follow them (indicating repetition count) from the compressed string and reconstructs the original data. For example, the input A3B3C2D1A2 is expanded back to AAABBBCCDAA. This function must accurately parse multi-digit numbers, which can be tricky. For instance, in a compressed string like A12, the function should recognize 12 as the count for the character A.

To ensure safety and correctness, the function must verify that it does not read beyond the end of the string when checking if the next character is a digit. Failing to do so can result in undefined behavior or runtime errors.

File Handling
The program uses standard file input/output (ifstream and ofstream) to read from and write to files. It reads the entire content of the input file into a string, performs the necessary operation (compression or decompression), and writes the result to the output file. Before performing file operations, the program checks whether the files were opened successfully. If any file cannot be opened, an error message is displayed and the program exits.

User Interaction
The program uses simple cout and cin statements for user interaction. While functional, the interface could be improved. For example, using getline() instead of cin >> for file names would allow file names with spaces. Additionally, adding input validation would enhance robustness, such as verifying that the user entered a valid choice or that the file contents are suitable for decompression.

Potential Improvements
Several enhancements can make the program more robust and user-friendly:

Edge Case Handling: Safely manage empty strings or malformed compressed data to prevent crashes.

Whitespace Support: Currently, spaces and newlines are compressed, but their treatment can be made more explicit.

Error Handling: Use exception handling for better robustness during numeric conversions and file operations.

User Experience: Improve the interface for smoother interaction, such as support for command-line arguments or GUI.

Conclusion
This RLE program serves as a clear and practical example of how basic data compression algorithms can be implemented in C++. It demonstrates file handling, string manipulation, and control structures effectively. With a few modifications, it can be made more robust and suitable for real-world use.





