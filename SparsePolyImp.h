//
// Created by Matthew Starkey on 6/16/2021.
//
#pragma once
#ifndef HW1_SPARSEPOLYIMP_H
#define HW1_SPARSEPOLYIMP_H
#include "Term.h"
class SparsePolyImp {
private:
    virtual Term* getPointerTo(int degree, Term* termPtr) = 0;
    virtual double evaluate(float x, Term* termPtr) const = 0;
public:
    virtual bool add(int coeff, int degree) = 0;
    virtual bool remove(int degree)  = 0;
    virtual void clear()  = 0;
    virtual double evaluate(float x) const = 0;

};
#endif //HW1_SPARSEPOLYIMP_H
