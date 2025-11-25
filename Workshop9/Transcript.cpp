/* Citation and Sources...
-----------------------------------------------------------
Workshop 9
Module: Transcript
Filename: Transcript.cpp
-----------------------------------------------------------
Author: Caroline Chen
Student number: 112747241
Email: cchen247@myseneca.ca
Subject: OOP244NRA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#include "Transcript.h"

#include <cstring>
using namespace std;
namespace seneca {
    Transcript::Transcript(const char* name, size_t studentNum) : Marks(){
        if (name != nullptr) {
            studentName = new char[strlen(name) + 1];
            strcpy(studentName, name);
        }
        studentNumber = studentNum;
    }

    Transcript::Transcript(const Transcript& src) : Marks(src) {
        studentNumber = src.studentNumber;

        if (src.studentName != nullptr) {
            studentName = new char[strlen(src.studentName) + 1];
            for (size_t i = 0; i < strlen(src.studentName); i++) {
                studentName[i] = src.studentName[i];
            }
        } else {
            studentName = nullptr;
        }
    }

    Transcript& Transcript::operator=(const Transcript& src) {
        if (this != &src) {
            Marks::operator=(src);

            studentNumber = src.studentNumber;

            delete [] studentName;
            if (src.studentName != nullptr) {
                studentName = new char[strlen(src.studentName) + 1];
                for (size_t i = 0; i <= strlen(src.studentName); i++) {
                    studentName[i] = src.studentName[i];
                }
            } else {
                studentName = nullptr;
            }
        }
        return *this;
    }

    Transcript::~Transcript() {
        delete [] studentName;
        studentName = nullptr;
    }

    ostream& Transcript::display(ostream& ostr) const{
        ostr << studentName << " (" << studentNumber << ")" << endl;
        ostr << "--------------------------------------------------------------------------" << endl;

        Marks::display(ostr);

        return ostr;
    }
}