//
// Created by Matthew Starkey on 6/16/2021.
//
#pragma once
#ifndef HW1_SPARSEPOLY_H
#define HW1_SPARSEPOLY_H
#include "SparsePolyImp.h"
#include <iostream>



class SparsePoly : public SparsePolyImp {
private:
    Term* head;
    int size;
    Term* getPointerTo(int degree, Term* termPtr);
    double evaluate(float x, Term* curr) const;
public:
    SparsePoly();
    bool add(int coeff, int degree);
    bool remove(int degree);
    void clear();
    double evaluate(float x) const;
    friend std::ostream& operator<< (std::ostream& out, SparsePoly poly);
};


#endif //HW1_SPARSEPOLY_H
