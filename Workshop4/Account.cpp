/***********************************************************************
// OOP244 Workshop 4 lab: Account Module
//
// File	Account.cpp
// Version 0.5
// Date	2025/06/03
// Partialy implemented by	Fardad Soleimanloo
// to be completed by the students
// You may modify any code in this file to suit your requirements.
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Account.h"

#include <cstring>

using namespace std;
namespace seneca {


   void Account::cpyName(const char* src) {
      int i;
      for (i = 0; src && src[i] && i < NameMaxLen; i++) {
         m_holderName[i] = src[i];
      }
      m_holderName[i] = char(0);
   }
   bool Account::isValidNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }
   Account::Account(const char* holderName) {
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0]) {
         cpyName(holderName);
         m_number = 0;
      }
   }
   Account::Account(const char* holderName, int number, double balance ) {
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0] && isValidNumber(number)
         && balance > 0) {
         cpyName(holderName);
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(NameMaxLen);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " | ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(30);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " |  NEW  |         0.00 ";
      }
      else {
         cout << " Bad Account                    | ----- | ------------ ";
      }
      return cout;
   }

   Account::operator bool() const {
      return isValidNumber(m_number);
   }

   Account::operator int() const {
      return m_number;
   }


   Account::operator double() const {
      return m_balance;
   }


   Account::operator const char*() const{
      return m_holderName;
   }

   char& Account::operator[](int index) {
      int length = strlen(m_holderName);

      if (index < 0 || index >= length) {
         index = 0;
      }
      return m_holderName[index];
   }

   const char Account::operator[](int index)const {
      int length = strlen(m_holderName);

      if (index < 0 || index >= length) {
         index = 0;
      }
      return m_holderName[index];
   }

   Account& Account::operator=(int accNumber) {
      if (m_number == 0) {
         if (isValidNumber(accNumber) == true) {
            m_number = accNumber;
         } else {
            m_holderName[0] = '\0';
            m_number = -1;
            m_balance = 0.0;
         }
      }
      return *this;
   }

   Account& Account::operator=(double accBalance) {
      if (accBalance >= 0.0) {
         m_balance = accBalance;
      } else {
         m_holderName[0] = '\0';
         m_number = -1;
         m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator+=(double accBalance) {
      if (accBalance >= 0.0) {
         m_balance += accBalance;
      }
      return *this;
   }

   Account& Account::operator-=(double accBalance) {
      if (accBalance >= 0.0 && m_balance > accBalance) {
         m_balance -= accBalance;
      }
      return *this;
   }

   Account& Account::operator<<(Account& from) {
      if (this != &from && *this && from) {   // valid & distinct
         m_balance += from.m_balance;
         from.m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& to) {
      if (this != &to && *this && to) {
         to.m_balance += m_balance;
         m_balance = 0.0;
      }
      return *this;
   }


   bool Account::operator~() const{
      if (m_number == 0) {
         return true;
      } else {
         return false;
      }
   }

   Account& Account::operator++() {
      m_balance += 1.0;

      return *this;

   }

   Account Account::operator++(int) {
      Account temp = *this;  // copy current state
      m_balance += 1.0;

      return temp;
   }

   Account& Account::operator--() {
      if (m_balance >= 1.0) {
         m_balance -= 1.0;
      }
         return *this;

      }


   Account Account::operator--(int) {
      Account temp = *this;
      if (*this && m_balance >= 1.0) {
         m_balance -= 1.0;
      }
      return temp;
   }

   }

