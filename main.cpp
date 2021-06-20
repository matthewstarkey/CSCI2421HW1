/**
 * Laboratory #1 - CSCI2421 - Summer 2021
 * File: main.cpp
 *
 * Disclaimer:
 *              This is a sample program. It does not represent comprehensive test of your homework.
 */

#include <iostream>
#include <string>
#include "SparsePolynomial.h"

using namespace std;

/**
 * Sample Test program for Hwk 1.
 * @return
 */
int main()
{
    cout << string(80, '*')  << endl;
    cout << string(30, ' ')<< "Homework #1"  << endl;
    cout << string(80, '*')  << endl;

    SparsePolynomial* poly = new SparsePolynomial();

    poly->add(8,0);
    poly->add(-1,2);
    poly->add(3,7);

    cout << "The Polynomial is:" << *poly << endl;

    float values[] = {2, 5,15,1.5};
    double results[] = {388, 234358, 512577908, 57.0078125};
    int testValuesQty = 4;

    for (int i=0; i < testValuesQty; i++){
        cout << "Polynomial evaluation for x="<<values[i]<< " is "<<poly->evaluate(values[i])
        << " and it should be "<< results[i]<<endl;

    }

    cout<<"Removing degree 7. Operation result:" << poly->remove(7)<<endl;
    cout << "Now the Polynomial is:" << *poly << endl;

    poly->add(5,3);
    poly->add(2,4);
    poly->add(3,3);
    poly->add(4,9);
    cout << *poly << endl;
    poly->remove(4);
    poly->remove(0);
    cout << *poly << endl;

    delete poly;

    cout << "Program Terminated." <<endl;
};
