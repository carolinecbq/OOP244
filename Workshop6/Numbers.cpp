//
// Created by carol on 2025-11-04.
//
/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include <set>
#include <iomanip>

#include "Numbers.h"
using namespace std;
namespace seneca {

   Numbers::~Numbers() {
      if (m_isOriginal)
         save();
      delete[] m_numbers;
      delete[] m_filename;
   }

   Numbers::Numbers(const Numbers& src) {
      setEmpty();
      m_isOriginal = false;

      if (!src.isEmpty()) {
         m_numCount = src.m_numCount;

         m_numbers = new double[m_numCount];

         for (int i = 0; i < m_numCount; i++) {
            m_numbers[i] = src.m_numbers[i];
         }
      }
   }

   Numbers& Numbers::operator=(const Numbers& src) {
      if (this != &src) {
         delete[] m_numbers;
         m_numCount = src.m_numCount;
         m_numbers = new double[m_numCount];

         for (int i = 0; i < m_numCount; i++) {
            m_numbers[i] = src.m_numbers[i];
         }
      }

      return *this;
   }

   int Numbers::numberCount() const {
      int count = 0;
      char character;

      std::ifstream file(m_filename);

      if (file.is_open()) {
         while (file.get(character)) {
            if (character == '\n') {
               count++;
            }
         }
      }

      return count;
   }

   bool Numbers::load() {
      bool success = false;

      if (m_numCount > 0) {
         m_numbers = new double[m_numCount];
         ifstream file (m_filename);

         int i = 0;
         while (!file.fail() && i < m_numCount) {
            file >> m_numbers[i];
            if (!file.fail())
               i++;
         }

         if (i == m_numCount) {
            success = true;
         } else {
            delete[] m_numbers;
            setEmpty();
         }
      }

      return success;
   }

   void Numbers::save() {
      if (m_isOriginal && !isEmpty()) {
         ofstream file(m_filename);
         for (int i = 0; i < m_numCount; i++) {
            file << m_numbers[i] << endl;
         }
      }
   }

   Numbers& Numbers::operator+=(double value) {
      if (!isEmpty()) {
         double *temp = new double[m_numCount + 1];
         for (int i = 0; i < m_numCount; i++) {
            temp[i] = m_numbers[i];
         }
         m_numCount += 1;
         temp[m_numCount - 1] = value;

         delete[] m_numbers;
         m_numbers = temp;

         sort();
      }

      return *this;
   }

   ostream& Numbers::display(ostream& ostr) const {
      ostr.setf(ios::fixed);
      ostr.precision(2);

      if (isEmpty()) {
         ostr << "Empty list";
      } else {
         ostr << "=========================" << endl;

         if (m_isOriginal) {
            ostr << m_filename << endl;
         } else {
            ostr << "*** COPY ***" << endl;
         }

         for (int i = 0; i < m_numCount; i++) {
            ostr << m_numbers[i];
            if (i < m_numCount - 1)
               ostr << ", ";
         }
         ostr << endl;

         ostr << "-------------------------" << endl;
         ostr << "Total of " << m_numCount << " number(s)" << endl;
         ostr << "Largest number:  " << max() << endl;
         ostr << "Smallest number: " << min() << endl;
         ostr << "Average:         " << average() << endl;
         ostr << "=========================";
      }

      return ostr;
   }

   ostream& operator<<(ostream& os, const Numbers& N) {
      return N.display(os);
   }

   istream& operator>>(istream& istr, Numbers& N) {
      double value;
      istr >> value;
      if (istr) {
         N += value;
      }
      return istr;
   }

}