#include <iostream>
#include <fstream>
#include "Encryption.h"
#include "Uppercase.h"
#include "Copy.h"

using namespace std;

int main() {
    string inputFileName;
    cout << "Enter the input file name: ";
    cin >> inputFileName;

    // Encryption with default key (5)
    {
        ifstream in(inputFileName);
        ofstream out("EncryptionDefault.txt");
        if (!in || !out) {
            cerr << "Error opening files for EncryptionDefault." << endl;
            return 1;
        }
        Encryption encDefault; 
        encDefault.doFilter(in, out);
    }

    // Encryption with key = 12
    {
        ifstream in(inputFileName);
        ofstream out("Encryption12.txt");
        if (!in || !out) {
            cerr << "Error opening files for Encryption12." << endl;
            return 1;
        }
        Encryption enc12(12);
        enc12.doFilter(in, out);
    }

    // Encryption with key = -4
    {
        ifstream in(inputFileName);
        ofstream out("Encryption-4.txt");
        if (!in || !out) {
            cerr << "Error opening files for Encryption-4." << endl;
            return 1;
        }
        Encryption encNeg(-4);
        encNeg.doFilter(in, out);
    }

    // Uppercase
    {
        ifstream in(inputFileName);
        ofstream out("Uppercase.txt");
        if (!in || !out) {
            cerr << "Error opening files for Uppercase." << endl;
            return 1;
        }
        Uppercase upper;
        upper.doFilter(in, out);
    }

    // Copy
    {
        ifstream in(inputFileName);
        ofstream out("Copy.txt");
        if (!in || !out) {
            cerr << "Error opening files for Copy." << endl;
            return 1;
        }
        Copy copyFilter;
        copyFilter.doFilter(in, out);
    }

    cout << "Processing complete. Check the output files." << endl;
    return 0;
}