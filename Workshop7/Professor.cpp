/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Professor
Filename: Professor.cpp
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
#include <iostream>
#include "Employee.h"
#include "Utils.h"
#include "Professor.h"

#include <cstring>
#include <iomanip>
using namespace std;
namespace seneca {

    Professor::Professor()
        : Employee()
    {
        subjectName = nullptr;
        numberOfSections = 0;
    }

    Professor::Professor(const char* name, const char* subject, int NumSections, int employeeNum, int salary)
        :Employee(name, employeeNum, salary)
    {
        if (subject != nullptr && subject[0] != '\0') {
            subjectName = new char[strlen(subject) + 1];
            strcpy(subjectName, subject);
        } else {
            subjectName = nullptr;
        }

        numberOfSections = NumSections;
    }

    Professor::~Professor() {
        delete[] subjectName;
        subjectName = nullptr;
    }

    double Professor::devPay() const {
        return (salary() * 0.01) * numberOfSections;
    }

    istream& Professor::read(istream& istr) {
        Employee::read(istr);

        delete[] subjectName;
        subjectName = nullptr;

        char tempSubject[1024];
        istr.ignore(1, ',');
        istr.getline(tempSubject, 1024, ',');

        if (tempSubject[0] != '\0') {
            subjectName = new char[strlen(tempSubject) + 1];
            strcpy(subjectName, tempSubject);
        } else {
            subjectName = nullptr;
        }

        istr >> numberOfSections;

        return istr;
    }

    ostream& Professor::write(ostream& ostr) const {
        ostr << left << setfill(' ');
        Employee::write(ostr);

        ostr << " " << left << setw(20) << string(subjectName).substr(0, 20);
        ostr << " | " << right << setw(5) << numberOfSections;
        ostr << " | " << right << setw(8) << fixed << setprecision(2) << devPay() << " |";

        return ostr;
    }

    ostream& Professor::title(ostream& ostr) const {
        Employee::title(ostr);
        ostr << " Teaching Subject     | Sec # | $Dev Pay |";

        return ostr;
    }

    ostream& operator<<(ostream& os, Professor& P) {
        return P.write(os);
    }

    istream& operator>>(istream& is, Professor& P) {
        return P.read(is);
    }







}