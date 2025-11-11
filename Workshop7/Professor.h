/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Professor
Filename: Professor.h
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
#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Employee.h"

using namespace std;
namespace seneca {
    class Professor : public Employee {
        char* subjectName{};
        int numberOfSections = 0;
    public:
        Professor();
        Professor(const char* name, const char* subjectName, int numberOfSections, int employeeNum, int salary);
        ~Professor();

        double devPay() const;

        istream& read(istream& istr = cin);
        ostream& write(ostream& ostr = cout) const;
        ostream& title(ostream& ostr = cout) const;

        friend ostream& operator<<(ostream& os, Professor& P);
        friend istream& operator>>(istream& is, Professor& P);

    };







}

#endif