/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: B59304
 *
 * Created on 10 de agosto de 2017, 11:19 AM
 */

#include <cstdlib>
#include <iostream>

#include "IntegerSortedSet.h"

int main(int argc, char** argv)
{
    IntegerSortedSet a, b; // a = {1, 2, 3} y b = {10, 11, 13}

    a.insertSorted( 1 );
    a.insertSorted( 2 );
    a.insertSorted( 3 );

    std::cout << a.toStr( ) << std::endl;

    b.insertSorted( 10 );
    b.insertSorted( 11 );
    b.insertSorted( 13 );

    std::cout << b.toStr( ) << std::endl;

    IntegerSortedSet c = a + b; // Unión del conjunto A con el conjunto B.

    IntegerSortedSet d = a / b; // diferencia simétrica de los conjuntos A y B.

    return 0;
}
