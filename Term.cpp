//
// Created by Matthew Starkey on 6/16/2021.
//
#include "Term.h"
Term::Term(): coeff(0), degree(0),next(nullptr){}
Term::Term(int c, int d):coeff(c), degree(d),next(nullptr){}
Term::Term(int c, int d, Term* n):coeff(c),degree(d),next(n){}
Term::~Term() {

}
void Term::setNext(Term* nextTerm) {
    next = nextTerm;
}
Term* Term::getNext() {
    return next;
}
int Term::getCoeff() {
    return coeff;
}
void Term::setCoeff(int c) {
    coeff = c;
}
int Term::getDegree() {
    return degree;
}
void Term::setDegree(int d) {
    degree = d;
}
bool operator==(Term left, Term right) {
    return (left.degree == right.degree && left.coeff == right.coeff);
}

