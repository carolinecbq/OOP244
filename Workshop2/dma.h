//
// Created by Caroline Chen on 2025-09-23.
//
/* Citation and Sources...
-----------------------------------------------------------
Workshop 2
Module: dma
Filename: dma.h
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
#ifndef WORKSHOP2_DMA_H
#define WORKSHOP2_DMA_H

struct Samples {
    char* m_title; //Dynamically allocated title
    int* m_data; // Dynamically allocated array of integers
    int m_size; // Number of elements in m_data
};

Samples* CreateSamples(const char* title);

void add(Samples& S, const int data[], int size);

void append(int*& data, int size, const int appendedData[], int dataSize);

void freemem(Samples*& s);

#endif //WORKSHOP2_DMA_H