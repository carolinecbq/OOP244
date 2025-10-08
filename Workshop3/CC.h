/* Citation and Sources...
-----------------------------------------------------------
Workshop 3
Module: CC
Filename: CC.h
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

#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
    class CC {
        void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;
        void prnNumber(unsigned long long no) const;
        bool validate(const char* cardHolderName, unsigned long long cardNumber,short cvv, short expYear, short expMonth) const;
        char* cardHolderName;
        short cvv;
        short expYear;
        short expMonth;
        unsigned long long cardNumber;
        void aloCopy(const char* name);
        void deallocate();
    public:
        void set();
        bool isEmpty() const;
        void set(const char* cc_name, unsigned long long cc_number, short cvv, short expYear, short expMonth);
        void display() const;
        CC();
        CC(const char* cc_name, unsigned long long cc_number, short cvv, short expYear = 26, short expMonth = 12);
        ~CC();


    };

}
#endif // !SENECA_CC_H_

