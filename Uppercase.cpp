#include "Uppercase.h"
#include <iostream>

using namespace std;

char Uppercase::transform(char ch) {
    // Convert lowercase to uppercase manually
    if (ch >= 'a' && ch <= 'z') {
        return static_cast<char>(ch - 32);
    }
    return ch;
}

void Uppercase::doFilter(ifstream &in, ofstream &out) {
    char ch;
    while (in.get(ch)) {
        out.put(transform(ch));
    }
}