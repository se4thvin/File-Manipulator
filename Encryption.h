#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "FileFilter.h"

class Encryption : public FileFilter {
private:
    int key;
    int transformChar(int ch) const;

public:
    Encryption();            // default constructor (key = 5)
    Encryption(int k);       // overloaded constructor
    void setKey(int k);      // mutator for key
    virtual void doFilter(std::ifstream &in, std::ofstream &out);
};

#endif