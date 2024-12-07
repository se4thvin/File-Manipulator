#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include "FileFilter.h"

class Encryption : public FileFilter {
    private: 
    int key; 
    int transformChar(int ch) const;

    public:
    Encryption(){key = 5;}; //Default constructor
    Encryption(int k); //Overloaded constructor
    void setKey(int k){key = k;}; //Mutator for key 

    virtual void doFilter(std::ifstream &in, std::ofstream &out);
};

#endif