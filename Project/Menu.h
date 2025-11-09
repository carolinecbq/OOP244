//
// Created by carol on 2025-10-30.
//
/* Citation and Sources...
Final Project Milestone 1:
Module: Menu
Filename: Menu.h
Version 1.0
Author: Caroline Chen, StNo: 112747241, Email: cchen247@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/10/31  Forgot the & symbol in the ostream display function and the default cout
-----------------------------------------------------------
Citation to indicate that you have done all the work yourself
-----------------------------------------------------------*/
#ifndef MILESTONE1_MENU_H
#define MILESTONE1_MENU_H
#include <iostream>
#include <iomanip>
#include "constants.h"
using namespace std;
namespace seneca {

    class Menu;

    class MenuItem {
        char* m_content{};
        unsigned int indents{};
        unsigned int indentSize{};
        int rowNum{};

        MenuItem();
        MenuItem(const char* content, unsigned int indentations, unsigned int indent_size, int rowValue);
        ~MenuItem();

        ostream& display(ostream& ostr = cout) const;

        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;

        operator bool() const;

        friend class Menu;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    class Menu {
        unsigned int indents{};
        unsigned int indentSize{};
        unsigned int itemCount{};

        MenuItem title;
        MenuItem exitOption;
        MenuItem entryPrompt;

        MenuItem* items[MaximumNumberOfMenuItems]{};

    public:
        Menu(const char* title, const char* exitOption = "Exit", unsigned int indents = 0, unsigned int indentSize = 3);
        ~Menu();

        Menu& operator<<(const char* m_content);

        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        size_t select() const;

        friend size_t operator<<(ostream& ostr, const Menu& m);

    };



}
#endif //MILESTONE1_MENU_H
