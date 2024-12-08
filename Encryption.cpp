#include "Encryption.h"
#include <iostream>

using namespace std;

Encryption::Encryption() : key(5) {}
Encryption::Encryption(int k) : key(k) {}
void Encryption::setKey(int k) {
    key = k;
}

int Encryption::transformChar(int ch) const {
    // If this character is a newline (or carriage return), don't encrypt it.
    if (ch == '\n' || ch == '\r') {
        return ch;
    }

    const int MIN = 32;
    const int MAX = 126;
    int val = ch + key;

    while (val > MAX) {
        val = MIN + (val - MAX - 1);
    }
    while (val < MIN) {
        val = MAX - (MIN - val - 1);
    }

    return val;
}


void Encryption::doFilter(ifstream &in, ofstream &out) {
    char ch;
    while (in.get(ch)) {
        out.put(static_cast<char>(transformChar(static_cast<int>(ch))));
    }
}