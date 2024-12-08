#include "Uppercase.h"
#include <iostream>

using namespace std;

char Uppercase::transform(char ch) {
    //Convert lowercase to upper manually // lowercase = 97, uppercase = 65
    if(ch >= 'a' && ch <= 'z') {
        return static_cast<char>(ch-32); 
    }
    return ch; 
}

void Uppercase::doFilter(std::ifstream &in, std::ofstream &out) {
    char ch; 
    while (in.get(ch)) {
        out.put(transform(ch)); 
    }
}

