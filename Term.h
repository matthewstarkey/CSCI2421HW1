//
// Created by Matth on 6/16/2021.
//
#pragma once
#ifndef HW1_TERM_H
#define HW1_TERM_H
class Term {
private:
    int coeff, degree;
    Term* next;
public:
    Term();
    Term(int c, int d);
    Term(int c, int d, Term* n);
    ~Term();
    void setNext(Term* nextTerm);
    Term* getNext();
    int getCoeff();
    void setCoeff(int c);
    int getDegree();
    void setDegree(int d);
    bool friend operator==(Term left, Term right);


};
#endif //HW1_TERM_H
