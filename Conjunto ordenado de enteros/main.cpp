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
    IntegerSortedSet setA, setB, setC;

    // Inicialización de apuntador inteligente.
    // std::shared_ptr<IntegerSortedSet> setE( new IntegerSortedSet( ) );

    setA.insertSorted( 4 );
    setA.insertSorted( 9 );
    setA.insertSorted( 11 );
    setA.insertSorted( 13 );
    setA.insertSorted( 15 );
    setA.insertSorted( 18 );
    setA.insertSorted( 20 );

    setB.insertSorted( 7 );
    setB.insertSorted( 8 );
    setB.insertSorted( 9 );
    setB.insertSorted( 10 );
    setB.insertSorted( 11 );
    setB.insertSorted( 15 );
    setB.insertSorted( 18 );

    setC = setA + setB;

    std::cout << "A:" << setA.toStr( ) << std::endl;
    std::cout << "B:" << setB.toStr( ) << std::endl;
    std::cout << "A+B" << setC.toStr( ) << std::endl << std::endl;

    return 0;
}
