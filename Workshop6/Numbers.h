//
// Created by carol on 2025-11-04.
//
/***********************************************************************
// OOP244 Workshop 6 lab
//
// File	Numbers.h
// Version 0.1
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.h
-----------------------------------------------------------
Author: Caroline Chen
Student number: 112747241
Email: cchen247@myseneca.ca
Subject: OOP224NRA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
using namespace std;
namespace seneca {
    class Numbers {
        double* m_numbers;
        char* m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty()const;
        void setEmpty();
        void setFilename(const char* filename);
        void sort();
        int numberCount() const;
    public:
        Numbers();
        Numbers(const char* filename);
        ~Numbers();
        Numbers(const Numbers& src);
        Numbers& operator=(const Numbers& src);
        double average()const;
        double max()const;
        double min()const;
        bool load();
        void save();
        Numbers& operator+=(double value);
        std::ostream& display(ostream& ostr) const;

    };

    ostream& operator<<(ostream& os, const Numbers& N);
    istream& operator>>(istream& istr, Numbers& N);
}
#endif // !SENECA_NUMBERS_H_

