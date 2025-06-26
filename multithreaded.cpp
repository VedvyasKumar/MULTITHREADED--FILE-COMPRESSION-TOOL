#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Function to perform RLE compression
string compressRLE(const string &data) {
    string result;
    int count = 1;

    for (size_t i = 1; i <= data.length(); i++) {
        if (data[i] == data[i - 1]) {
            count++;
        } else {
            result += data[i - 1] + to_string(count);
            count = 1;
        }
    }

    return result;
}

// Function to perform RLE decompression
string decompressRLE(const string &data) {
    string result;
    for (size_t i = 0; i < data.length(); i++) {
        char ch = data[i];
        string num = "";

        while (isdigit(data[++i])) {
            num += data[i];
        }
        i--; // step back after the while loop
        result.append(stoi(num), ch);
    }
    return result;
}

int main() {
    string inputFile, outputFile;
    int choice;

    cout << "1. Compress File\n2. Decompress File\nEnter your choice: ";
    cin >> choice;

    cout << "Enter input file name: ";
    cin >> inputFile;
    cout << "Enter output file name: ";
    cin >> outputFile;

    ifstream in(inputFile);
    if (!in.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    string data((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    string output;

    if (choice == 1) {
        output = compressRLE(data);
    } else if (choice == 2) {
        output = decompressRLE(data);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    ofstream out(outputFile);
    if (!out.is_open()) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    out << output;
    out.close();

    cout << (choice == 1 ? "Compression" : "Decompression")
         << " completed. Output saved to " << outputFile << endl;

    return 0;
} 
