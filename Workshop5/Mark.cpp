/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File	Mark.cpp
// Version 1.0
// Date	2025/06/12
// Author	partially done by Fardad Soleimanloo
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
Workshop 5
Module: Mark
Filename: Mark.cpp
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
#include <cmath> // for round function
#include "Mark.h"
#include <limits>

#include <iomanip>
using namespace std;
namespace seneca {
   bool Mark::isValid()const {
      return  (m_value >= 0 && m_value <= 100);
   }
   Mark::Mark(int value, char type) {
      *this = type;
      m_value = double(value);
   }

   Mark::Mark(double value) {
      m_type = MARK;
      m_value = value;
   }

   Mark& Mark::operator+=(const Mark& M) {
      m_value += M.m_value;
      return *this;
   }

   Mark& Mark::operator-=(const Mark& M) {
      m_value -= M.m_value;
      return *this;
   }

   Mark Mark::operator+(const Mark& M) const {
      return Mark(*this) += M;
   }

   Mark Mark::operator-(const Mark& M)const {
      return Mark(*this) -= M;
   }

   Mark& Mark::operator/=(int other) {
      m_value = m_value / other;
      return *this;
   }

   Mark Mark::operator/(int other) const {
      return Mark(m_value / other);
   }

   Mark& Mark::operator=(int value) {
      m_value = value;
      return *this;
   }

   Mark& Mark::operator=(char type) {
      m_type = MARK;
      if (type == GRADE || type == GPA) {
         m_type = type;
      }
      return *this;
   }

   double Mark::raw() const {
      return m_value;
   }

   Mark::operator int() const {
      int value = -1;
      if (isValid()) {
         value = int(std::round(m_value < 0 ? 0 : m_value));
      }
      return value;
   }
   Mark::operator bool() const {
      return isValid();
   }


   // returns the GPA not the m_value!!!
   Mark::operator double() const {
      double gpa = 0;
      if (!isValid()) gpa = -1;
      else gpa = m_value * 0.04;
      return gpa;
   }

   Mark::operator const char* () const {
      // removes the constantness of m_grade!
      // You will learn this at the end of the semester.
      char* grade = const_cast<char*>(m_grade);

      int value = int(*this);
      grade[1] = grade[2] = '\0';
      if (value < 0 || value > 100) grade[0] = 'X';
      else if (value >= 90) grade[0] = 'A', grade[1] = '+';
      else if (value >= 80) grade[0] = 'A';
      else if (value >= 75) grade[0] = 'B', grade[1] = '+';
      else if (value >= 70) grade[0] = 'B';
      else if (value >= 65) grade[0] = 'C', grade[1] = '+';
      else if (value >= 60) grade[0] = 'C';
      else if (value >= 55) grade[0] = 'D', grade[1] = '+';
      else if (value >= 50) grade[0] = 'D';
      else grade[0] = 'F';
      return m_grade;
   }

   // student helper function implementations go here
   std::ostream& Mark::display(std::ostream& os) const {
      if (!isValid()) {
         if (m_type == GRADE) {
            os << "**";
         } else {
            os << "***";
         }
      } else {
         switch (m_type) {
            case GPA:
               os << fixed
                  << setprecision(1)
                  << setw(3)
                  << right
                  << static_cast<double>(*this);
               os.unsetf(ios::fixed);
               break;
            case MARK:
               os << setw(3)
                  << setfill('_')
                  << right
                  << static_cast<int>(*this);
               os << setfill(' ');

               break;
            case GRADE:
               os << setw(3)
                  << setfill(' ')
                  << left
                  << static_cast<const char*>(*this);
               break;
            default:
               os << "Error";
               break;
         }
      }
      return os;
   }

   double operator/(double d, const Mark& mark) {
      return d / mark.m_value;
   }

   int operator/(int i, const Mark& mark) {
      int rounded = static_cast<int>(mark.m_value);
      return i / rounded;
   }


   std::ostream& display(const Mark& mark, char type, std::ostream& os) {
      mark.display(os);

      if (type != MARK) {
         os << ": ";
         Mark temp = mark;
         temp = type;
         temp.display(os);
      }
      return os;
   }

   std::ostream& operator<<(std::ostream& os, const Mark& mark) {
      return mark.display(os);
   }

   std::istream& operator>>(std::istream& is, Mark& mark) {
      int num{};
      char character{};

      while (true) {
         if (!(is >> num)) {
            cout << "Invalid integer, try again.\n> ";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;
            continue;
         }

         character = is.peek();
         if (character != '\n' && character != ' ') {
            cout << "Invalid trailing characters. Please enter only an integer.\n> ";
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;
            continue;
         }

         if (num < 0 || num > 100) {
            cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');;
            continue;
         }

         mark = num;
         break;

      }
      return is;

   }

   std::ifstream& operator>>(std::ifstream& ifs, Mark& mark) {
      int num{};
      char type{};
      char comma{};

      if (ifs >> num >> comma >> type) {
         if (comma == ',') {
            mark = num;
            mark = type;
         }
      }
      return ifs;
   }

   double operator+(double d, const Mark& mark) {
      return d + mark.raw();
   }

   int operator+(int i, const Mark& mark){
      return i + static_cast<int>(mark);
   }

   double operator-(double d, const Mark& mark) {
      return d - mark.raw();
   }

   int operator-(int i, const Mark& mark) {
      return i - static_cast<int>(mark);
   }


}