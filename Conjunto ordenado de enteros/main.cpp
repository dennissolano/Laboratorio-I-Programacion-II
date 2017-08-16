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
    IntegerSortedSet setA, setB; // a = {1, 2, 3} y b = {10, 11, 13}

    /*setA.insertSorted( 1 );
    setA.insertSorted( 2 );
    setA.insertSorted( 3 );

    std::cout << setA.toStr( ) << std::endl;

    setB.insertSorted( 10 );
    setB.insertSorted( 11 );
    setB.insertSorted( 13 );

    std::cout << setB.toStr( ) << std::endl;

    Inicialización de apuntador inteligente.
    std::shared_ptr<IntegerSortedSet> setE( new IntegerSortedSet( ) );

    setE->insertSorted( 12 );
     setE->insertSorted( 9 );
    setE->insertSorted( 6 );

    std::cout << setE->toStr( ) << std::endl;*/

    /*setA.insertSorted( 1 );
    setA.insertSorted( 4 );
    setA.insertSorted( 9 );
    setA.insertSorted( 11 );
    setA.insertSorted( 13 );
    setA.insertSorted( 15 );
    setA.insertSorted( 18 );*/


    setA.insertSorted( 7 );
    setA.insertSorted( 8 );
    setA.insertSorted( 9 );
    setA.insertSorted( 10 );
    setA.insertSorted( 11 );
    setA.insertSorted( 15 );
    setA.insertSorted( 18 );


    // setA.insertSorted( 4 );
    // setA.insertSorted( 8 );

    setB.insertSorted( 4 );
    setB.insertSorted( 8 );
    setB.insertSorted( 10 );
    setB.insertSorted( 12 );
    setB.insertSorted( 9 );


    std::cout << "A:" << setA.toStr( ) << std::endl;



    /* setB.insertSorted( 7 );
     setB.insertSorted( 8 );
     setB.insertSorted( 9 );
     setB.insertSorted( 10 );
     setB.insertSorted( 11 );
     setB.insertSorted( 15 );
     setB.insertSorted( 18 );*/


    std::cout << "B:" << setB.toStr( ) << std::endl;

    IntegerSortedSet setC = setA - setB; // Unión del conjunto A con el conjunto B.

    std::cout << "A+B:" << setC.toStr( ) << std::endl;

    //IntegerSortedSet setD = setA / setB; // diferencia simétrica de los conjuntos A y B.

    return 0;
}
