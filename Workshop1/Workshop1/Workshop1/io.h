#ifndef SENECA_IO_H
#define SENECA_IO_H

#include <cstdio> //FILE*, ...

namespace seneca {

struct PhoneRec {
    char firstName[15];
    char lastName[25];
    long long phoneNumber;
};

void read(char* name); //or char name []

void print(long long phoneNumber);

void print(const PhoneRec& rec, size_t& rowNumber, const char* filter = nullptr);

bool read(PhoneRec& rec, FILE* fp);

void print(PhoneRec* arrayPointer[], size_t size, const char* filter = nullptr);

void setPointers(PhoneRec* arrayPointer[], PhoneRec recs[], size_t size);

void sort(PhoneRec* arrayPointer[], size_t size, bool byLastName);

}

#endif
