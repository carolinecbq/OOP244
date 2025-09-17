#include <iostream>
#include "io.h"
using namespace std; //or add std:: in front of wherever needed

namespace seneca {

void read(char* name){
    cout << "name>\n" << endl;
    cin >> name; 
}

void print(long long phoneNumber){ //1234567890
    cout << "(";
    cout << phoneNumber / 10000000; //123
    cout << ")";
    cout << " ";
    long long phoneNumber2 = phoneNumber % 10000000; 
    cout << phoneNumber2 / 10000; //456
    cout << "-";
    cout << phoneNumber2 % 10000; //7890
}

void print(const PhoneRec& rec, size_t& rowNumber, const char* filter = nullptr){
    if (filter == nullptr || strstr(rec.firstName, filter) || strstr(rec.lastName, filter)){
        cout << rowNumber << ":" << rec.firstName << " " << rec.lastName << " " << rec.phoneNumber << endl;
        rowNumber++;
    }
}

bool read(struct PhoneRec& rec, FILE* fp){
    int result = fscanf(fp, "%s %s %lld", rec.firstName, rec.lastName, &rec.phoneNumber);
    return result == 3;
    
}

void print(PhoneRec* arrayPointer[], size_t size, const char* filter = nullptr){
    size_t rowNumber = 1;
    for(size_t i = 0; i < size; i++){
        if (arrayPointer[i])              
            print(*arrayPointer[i], rowNumber, filter);  
            ++rowNumber;  
    }
}

void setPointers(PhoneRec* arrayPointer[], PhoneRec recs[], size_t size){
    for(size_t i = 0; i < size; i++){
        arrayPointer[i] = &recs[i];
    }
}

void sort(PhoneRec* arrayPointer[], size_t size, bool byLastName){
    for(size_t i = 0; i < size; i++){
        for(size_t j = 0; j < size; j++){

            if (byLastName == true){
                if (strcmp(arrayPointer[i]->lastName, arrayPointer[j]->lastName) > 0) {
                    PhoneRec* temp = arrayPointer[i];
                    arrayPointer[i] = arrayPointer[j];
                    arrayPointer[j] = temp;
                }
            } else {
                if (strcmp(arrayPointer[i]->firstName, arrayPointer[j]->firstName) > 0) {
                    PhoneRec* temp = arrayPointer[i];
                    arrayPointer[i] = arrayPointer[j];
                    arrayPointer[j] = temp;
            }
        }
    }
}
}}