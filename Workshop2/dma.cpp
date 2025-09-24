/* Citation and Sources...
-----------------------------------------------------------
Workshop 2
Module: dma
Filename: dma.cpp
-----------------------------------------------------------
Author: Caroline Chen
Student number: 112747241
Email: cchen247@myseneca.ca
Subject: OOP244 NRA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#include <iostream>
#include "dma.h"
#include "cstr.h"
using namespace seneca;

Samples* CreateSamples(const char* title) {
    Samples* s = new Samples;
    size_t length = seneca::strlen(title) + 1;
    s->m_title = new char[length];

    seneca::strcpy(s->m_title, title);

    s->m_data = nullptr;
    s->m_size = 0;

    return s;
}

void add(Samples& S, const int data[], int size) {
    if (S.m_data == nullptr) {
        S.m_data = new int[size];
        for (int i = 0; i < size; i++) {
            S.m_data[i] = data[i];
        }
        S.m_size = size;
    } else {
        append(S.m_data, S.m_size, data, size);
        S.m_size += size;
    }
}

void append(int*& data, int size, const int appendedData[], int dataSize) {
    int* newData = new int[size + dataSize];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    for (int j = 0; j < dataSize; j++) {
        newData[size + j] = appendedData[j];
    }
    delete[] data;
    data = newData;
}

void freemem(Samples*& s) {
    delete [] s->m_title;
    delete [] s->m_data;
    delete s;

    s = nullptr;
}
////////////////////////////////////////////////////////////////////////

void testCreateSamples() {
    std::cout << "Test: CreateSamples()... ";

    const char title[] = "Test Data Set";
    Samples* s = CreateSamples(title);

    bool ok = s && s->m_title && seneca::strcmp(s->m_title, title) == 0
              && s->m_data == nullptr && s->m_size == 0;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] s->m_title;
    delete s;
}

void testAppend() {
    std::cout << "Test: append()... ";

    int original[] = {1, 2, 3};
    int toAppend[] = {4, 5};
    int* data = new int[3];
    for (int i = 0; i < 3; ++i) data[i] = original[i];

    append(data, 3, toAppend, 2);

    bool ok = data[0] == 1 && data[1] == 2 && data[2] == 3 &&
              data[3] == 4 && data[4] == 5;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] data;
}

void testAdd() {
    std::cout << "Test: add()... ";

    Samples s;
    s.m_title = nullptr;
    s.m_data = nullptr;
    s.m_size = 0;

    int values1[] = {10, 20};
    int values2[] = {30};

    add(s, values1, 2); // Adds [10, 20]
    add(s, values2, 1); // Appends [30]

    bool ok = s.m_size == 3 &&
              s.m_data[0] == 10 &&
              s.m_data[1] == 20 &&
              s.m_data[2] == 30;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] s.m_data;
}

void testFreemem() {
    std::cout << "Test: freemem()... ";

    Samples* s = new Samples;
    s->m_title = new char[6];
    seneca::strcpy(s->m_title, "Hello");

    s->m_data = new int[3]{1, 2, 3};
    s->m_size = 3;

    freemem(s);

    bool ok = (s == nullptr);

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;
}