/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.h
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
    const int NameMaxLen = 30;
    class Account {
        double m_balance; //balance of the account
        int m_number; //account number
        char m_holderName[NameMaxLen + 1]; //account holder name
        void cpyName(const char* src); // copies the src into the m_holderName array
        bool isValidNumber(int number)const; // returns true if number is a valid account number
    public:
        Account(const char* holderName = nullptr); //One-argument constructor - Sets the account as new with a balance of 0.0
        Account(const char* holderName, int number, double balance); //Three-argument constructor - Sets the account with all info if all three are valid, otherwise sets to invalid empty state
        std::ostream& display()const; //displays information on the screen
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char*() const;
        char& operator[](int index);
        const char operator[](int index)const;
        Account& operator=(int accNumber);
        Account& operator=(double accBalance);
        Account& operator+=(double accBalance);
        Account& operator-=(double accBalance);
        Account& operator<<(Account& from);
        Account& operator>>(Account& to);
        bool operator~() const;
        Account& operator++();
        Account operator++(int);
        Account& operator--();
        Account operator--(int);
    };


}
#endif // SENECA_ACCOUNT_H_