# File Filtering Project

This project demonstrates object-oriented programming concepts in C++ by creating a hierarchy of file filtering classes. It includes an abstract base class and three derived classes that transform input files into output files in various ways.

## Overview

The project provides:

1. **FileFilter (Abstract Base Class)**  
   - Defines a pure virtual function `doFilter(ifstream &in, ofstream &out)`.
   - Serves as the base for all specialized file filters.

2. **Encryption (Derived Class)**  
   - Modifies each character in the input file by adding a key to its ASCII value.
   - If the resulting ASCII code falls outside the printable range (32 to 126), it "rolls over" to ensure it always maps to a valid character in that range.
   - A positive or negative key can be used. Rolling over means that values above 126 wrap around to 32, and values below 32 wrap around to 126.
   - Constructors:
     - Default constructor sets `key = 5`
     - Overloaded constructor allows setting a custom `key`
   - Mutator function allows changing the key after construction.

3. **Uppercase (Derived Class)**  
   - Converts all lowercase letters in the input file to uppercase letters.
   - Does **not** use functions like `toupper`; it does manual ASCII conversions.
   - Non-alphabetic and already uppercase letters remain unchanged.

4. **Copy (Derived Class)**  
   - Simply copies the input file to the output file without any modifications.

## File Structure

- **FileFilter.h**:  
  Defines the `FileFilter` abstract class with the pure virtual `doFilter` method.
  
- **Encryption.h** and **Encryption.cpp**:  
  Defines the `Encryption` class. Implements the `doFilter` function to apply character-by-character encryption.
  
- **Uppercase.h** and **Uppercase.cpp**:  
  Defines the `Uppercase` class. Implements the `doFilter` function to convert all lowercase letters to uppercase.
  
- **Copy.h** and **Copy.cpp**:  
  Defines the `Copy` class. Implements the `doFilter` function to copy the file as is.
  
- **main.cpp**:  
  A driver program that:
  1. Prompts the user for an input file name.
  2. Uses an `Encryption` object with various keys (default 5, 12, and -4) to create encrypted files.
  3. Uses an `Uppercase` object to create an uppercase version of the file.
  4. Uses a `Copy` object to create a direct copy of the file.

## How to Use

1. **Compile the Project**  
   Run your preferred C++ compiler (e.g., `g++`) and compile all `.cpp` files:
   ```bash
   g++ -o filefilter main.cpp Encryption.cpp Uppercase.cpp Copy.cpp