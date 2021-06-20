//
// Created by Matth on 6/20/2021.
//

#ifndef HW1_SPARSEPOLYNOMIAL_H
#define HW1_SPARSEPOLYNOMIAL_H
#include "SparsePolyImp.h"
#include <iostream>

class SparsePolynomial : public SparsePolyImp{
private:
    Term* head;
    int size;
    Term* getPointerTo(int degree, Term* termPtr);
    double evaluate(float x, Term* curr) const;
public:
    SparsePolynomial();
    bool add(int coeff, int degree);
    bool remove(int degree);
    void clear();
    double evaluate(float x) const;
    friend std::ostream& operator<< (std::ostream& out, SparsePolynomial poly);
};


#endif //HW1_SPARSEPOLYNOMIAL_H
