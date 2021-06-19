//
// Created by Matthew Starkey on 6/16/2021.
//
#include "SparsePoly.h"
#include <cmath>

SparsePoly::SparsePoly():head(nullptr),size(0){}

Term* SparsePoly::getPointerTo(int degree, Term* termPtr) {
    if(termPtr->getDegree() == degree) {
        return termPtr;
    } else if (termPtr == nullptr) {
        return nullptr;
    } else {
        return getPointerTo(degree, termPtr->getNext());
    }
}
double SparsePoly::evaluate(float x, Term* curr) const {
    if(curr == nullptr) {
        return 0;
    } else {
        int d = curr->getDegree();
        int c = curr-> getCoeff();
        float num = std::pow(x,d) * c;

        return num + evaluate(x,curr->getNext());
    }
}

bool SparsePoly::add(int coeff, int degree) {
    if(head == nullptr) {
        head = new Term(coeff,degree);
        size++;
        return true;
    } else if (head->getNext() == nullptr) {
        if(head->getDegree() == degree) {
            head->setCoeff(head->getCoeff() + coeff);
            return true;
        } else {
            head->setNext(new Term(coeff,degree));
            size++;
            return true;
        }
    }
    Term* curr = head;
    while(curr->getNext() != nullptr) {
        if(curr->getDegree() == degree) {
            curr->setCoeff(curr->getCoeff() + coeff);
            return true;
        }
        curr = curr->getNext();
    }
    curr->setNext(new Term(coeff,degree));
    size++;
    return true;
}


bool removeHelper(int target, Term* ptr) {
    //assumes head is not target
    if(ptr == nullptr) {
        return false;
    }
    Term* next = ptr->getNext();
    if(next != nullptr) {
        if(next->getDegree() == target){
            //remove next from list
            ptr->setNext(next->getNext());
            return true;
        } else {
            return removeHelper(target, next);
        }
    } else {
        return false;
    }
}

bool SparsePoly::remove(int degree) {
    if(head == nullptr) {
        return false;
    } else if (head->getDegree() == degree) {
        head = head->getNext();
        size--;
        return true;
    } else {
        if(removeHelper(degree,head)){
            size--;
            return true;
        }
        return false;
    }

}

void SparsePoly::clear() {
    size = 0;
    head = nullptr;
}

double SparsePoly::evaluate(float x) const {
    return evaluate(x,head);
    }


std::ostream& operator<< (std::ostream& out, SparsePoly poly) {
    Term* curr = poly.head;
    if(curr == nullptr) {
        return out;
    } else if(curr->getNext() == nullptr) {
        if(curr->getDegree() == 0) {
            return out << curr->getCoeff();
        } else {
            return out << curr->getCoeff() << "x^" << curr->getDegree();
        }
    }
    while(curr->getNext() != nullptr) {
        bool isZero = curr->getDegree() == 0;
        if (curr->getNext()->getNext() == nullptr) {
            if (isZero) {
                out << curr->getCoeff() << " + ";
            } else {
                out << curr->getCoeff() << "x^" << curr->getDegree() << " + ";
            }
        } else {
            if (isZero) {
                out << curr->getCoeff() << " + ";
            } else {
                out << curr->getCoeff() << "x^" << curr->getDegree() << " + ";
            }
        }
        curr = curr->getNext();
    }
    if(curr->getDegree() != 0) {
        return out << curr->getCoeff() << "x^" << curr->getDegree() << std::endl;
    }else{
            return out << curr->getCoeff() << std::endl;
        }
}
