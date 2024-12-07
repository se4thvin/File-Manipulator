#ifndef FILEFILTER_H
#define FILEFILTER_H

#include <fstream> 

class FileFilter {
    public:
        virtual void doFileter(std::ifstream &in, std::ofstream &out) = 0; // pure virtual function
        virtual ~FileFilter() {} // virtual destructor
};

#endif