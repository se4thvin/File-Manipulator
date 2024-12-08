#include "Encryption.h"
#include <iostream> 

using namespace std; 

Encryption::Encryption(int k) : key(k) {}

int Encryption::transformChar(int ch) const {
    const int MIN = 32; 
    const int MAX = 126; 
    const int RANGE = (MAX- MIN + 1); 

    int val = ch + key; 
    //Adjust if out of range 
    if (val > MAX) {
        val -= MIN + (val - MAX - 1); 
    } else if (val < MIN) {
        val += MAX - (MIN - val - 1); 
    }
    return val;
}

void Encryption::doFilter(std::ifstream &in, std::ofstream &out) {
    char ch; 
    while (in.get(ch)) {
        out.put(static_cast<char>(transformChar(static_cast<int>(ch)))); 
    }
}



