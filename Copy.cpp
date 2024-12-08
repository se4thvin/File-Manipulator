#include "Copy.h"
#include <iostream>

using namespace std;

void Copy::doFilter(ifstream &in, ofstream &out) {
    char ch;
    while (in.get(ch)) {
        out.put(ch);
    }
}