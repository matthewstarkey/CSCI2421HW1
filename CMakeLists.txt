cmake_minimum_required(VERSION 3.19)
project(HW1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW1
    main.cpp
        SparsePolynomial.cpp
        SparsePolynomial.h
    SparsePolyImp.h
    Term.cpp
    Term.h)
