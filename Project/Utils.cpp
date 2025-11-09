/***********************************************************************
// OOP244 Project, Utils Module
//
// File	Utils.h
// Version 0.1
// started by Fardad
// Description
// utility function to be used in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
***********************************************************************/
/* Citation and Sources...
Final Project Milestone 2:
Module: Utils
Filename: Utils.cpp
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/11/09 Added Milestone 2 functions
-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/
#include <iostream>
#include "Utils.h"
#include <limits>
using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

   int Utils::getInt() {
      int value = 0;
      bool validity = false;

      while (!validity) {
         if (!(cin >> value)) {
            cout << "Invalid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
         else {
            char character;
            cin.get(character);

            if (character != '\n') {
               cout << "Only an integer please: ";
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
               validity = true;
            }
         }
      }
      return value;
   }



   int Utils::getInt(int min, int max) {
      int value = 0;


      value = getInt();

      if (value < min || value > max) {
         cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
      }

      return value;
   }


}