/***********************************************************************
// OOP244 workshop 9, Transcript module
//
// File	Transcript.h
// Version 1.0
// started by Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
/* Citation and Sources...
-----------------------------------------------------------
Workshop 9
Module: Transcript
Filename: Transcript.h
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
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"
using namespace std;
namespace seneca {
    class Transcript :
       public Marks {
        // character pointer student name
        char* studentName{};
        // unsigned integer or size_t student number
        size_t studentNumber{};
    public:
        // Constructor
        Transcript(const char* studentName, size_t studentNumber);
        // Rule of Three
        Transcript(const Transcript& src);
        Transcript& operator=(const Transcript& src);
        // Destructor
        ~Transcript();

        ostream& display(ostream& ostr = cout) const;

    };
}
#endif // !SENECA_TRANSCRIPT_H

