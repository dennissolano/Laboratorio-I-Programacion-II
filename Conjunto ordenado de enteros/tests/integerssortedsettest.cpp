/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   integerssortedsettest.cpp
 * Author: B59304
 *
 * Created on 10 de agosto de 2017, 12:06 PM
 */

#include <stdlib.h>
#include <iostream>
#include "IntegerSortedSet.h"

// Constructor por defecto.

void testIntegerSortedSet()
{
    IntegerSortedSet integerSortedSet;

    if( integerSortedSet.toStr( ) != "{}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testIntegerSortedSet (integerssortedsettest) message= El constructor por defecto o el método toStr falló." << std::endl;
    }
}

// Constructor de copia.

void testIntegerSortedSet2()
{
    // Primer caso: Conjunto vacío.

    IntegerSortedSet other; // Conjunto vacío "other".
    IntegerSortedSet integerSortedSet( other ); // "integerSortedSet" es una copia idéntica de "other".

    if( integerSortedSet.toStr( ) != "{}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testIntegerSortedSet2 (integerssortedsettest) message= El constructor de copia con el conjunto vacío o el método toStr falló." << std::endl;
    }

    // Segundo caso: Conjunto con al menos un elemento o más.

    other.insertSorted( 0 );
    other.insertSorted( 3 );
    other.insertSorted( 7 );
    other.insertSorted( 11 );

    IntegerSortedSet integerSortedSet2( other );

    if( integerSortedSet2.toStr( ) != "{0,3,7,11}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testIntegerSortedSet2 (integerssortedsettest) message= El constructor de copia con un conjunto no vacío o el método toStr falló." << std::endl;
    }
}

void testInsertSorted()
{
    // Prueba: retorna falso al insertar un número.

    bool result = true;
    IntegerSortedSet integerSortedSet; // Creación de un conjunto vacío.
    result = integerSortedSet.insertSorted( 0 ); // Inserta el elemento "0" en el conjunto.

    if( !result || integerSortedSet.toStr( ) != "{0}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertSorted (integerssortedsettest) message= Falló en el método insertSorted con x  == 0" << std::endl;
    }


    result = integerSortedSet.insertSorted( 3 );

    if( !result || integerSortedSet.toStr( ) != "{0,3}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertSorted (integerssortedsettest) message= Falló en el método insertSorted con x  == 0, 3" << std::endl;
    }


    result = integerSortedSet.insertSorted( 7 );

    if( !result || integerSortedSet.toStr( ) != "{0,3,7}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testInsertSorted (integerssortedsettest) message= Falló en el método insertSorted con x  == 0, 3, 7" << std::endl;
    }
}

void testDeleteNumber()
{
    bool result = true;

    // Primer caso: Conjunto vacío.

    IntegerSortedSet integerSortedSet;
    result = integerSortedSet.deleteNumber( 0 );

    if( result )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDeleteNumber (integerssortedsettest) message= Falló el método deleteStr con el conjunto vacío." << std::endl;
    }

    // Inserción de números al conjunto "integerSortedSet" para casos restantes.

    integerSortedSet.insertSorted( 0 );
    integerSortedSet.insertSorted( 3 );
    integerSortedSet.insertSorted( 7 );
    integerSortedSet.insertSorted( 11 );

    // Conjunto resultante: "{0,3,7,11}"

    // Segundo caso: Eliminación de elemento que no pertenece al conjunto.

    result = integerSortedSet.deleteNumber( 5 );

    if( result )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDeleteNumber (integerssortedsettest) message= Falló el método deleteStr(5) en  el conjunto {0,3,7,11} " << std::endl;
    }

    // Tercer caso: Eliminar el primer elemento del conjunto.

    IntegerSortedSet integerSortedSet2( integerSortedSet );
    result = integerSortedSet2.deleteNumber( 0 );

    if( !result || integerSortedSet2.toStr( ) != "{3,7,11}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDeleteNumber (integerssortedsettest) message= Falló el método deleteStr(0) en  el conjunto {0,3,7,11} " << std::endl;
    }

    // Cuarto caso: Eliminar el último elemento del conjunto.

    IntegerSortedSet integerSortedSet3( integerSortedSet );
    result = integerSortedSet3.deleteNumber( 11 );

    if( !result || integerSortedSet3.toStr( ) != "{0,3,7}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDeleteNumber (integerssortedsettest) message= Falló el método deleteStr(11) en  el conjunto {0,3,7,11} " << std::endl;
    }

    // Quinto caso: Eliminar elemento que está en el medio.

    IntegerSortedSet integerSortedSet4( integerSortedSet );
    result = integerSortedSet4.deleteNumber( 7 );

    if( !result || integerSortedSet4.toStr( ) != "{0,3,11}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDeleteNumber (integerssortedsettest) message= Falló el método deleteStr(7) en  el conjunto {0,3,7,11} " << std::endl;
    }

}

void testSearch()
{
    bool result = true;
    IntegerSortedSet integerSortedSet;

    // Primer caso: Buscar un elemento en el conjunto vació.

    result = integerSortedSet.search( 5 );

    if( result )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testSearch (integerssortedsettest) message= Falló el método search(5) en el conjunto {}" << std::endl;
    }

    // Inserción de números al conjunto "integerSortedSet" para casos restantes.

    integerSortedSet.insertSorted( 0 );
    integerSortedSet.insertSorted( 3 );
    integerSortedSet.insertSorted( 7 );
    integerSortedSet.insertSorted( 11 );

    // Conjunto resultante: "{0,3,7,11}"

    // Segundo caso: Buscar un elemento que no existe en el conjunto.

    // Resultado esperado result = false.
    result = integerSortedSet.search( 5 );

    if( result )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testSearch (integerssortedsettest) message= Falló el método search(5) en el conjunto {0,3,7,11}" << std::endl;
    }

    // Tercer caso: Buscar el primer elemento del conjunto.

    IntegerSortedSet integerSortedSet2( integerSortedSet );
    result = integerSortedSet2.search( 0 );

    if( !result )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testSearch (integerssortedsettest) message= Falló el método search(0) en el conjunto {0,3,7,11}" << std::endl;
    }

    // Cuarto caso: Buscar el último elemento del conjunto.

    IntegerSortedSet integerSortedSet3( integerSortedSet );
    result = integerSortedSet3.search( 11 );

    if( !result )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testSearch (integerssortedsettest) message= Falló el método search(11) en el conjunto {0,3,7,11}" << std::endl;
    }

    // Quinto caso: Buscar el elemento del medio.

    IntegerSortedSet integerSortedSet4( integerSortedSet );
    result = integerSortedSet4.search( 7 );

    if( !result )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testSearch (integerssortedsettest) message= Falló el método search(7) en el conjunto {0,3,7,11}" << std::endl;
    }
}

void testUnion()
{
    IntegerSortedSet setA;
    IntegerSortedSet setB;
    IntegerSortedSet setC;
    IntegerSortedSet setD;
    IntegerSortedSet r1;
    IntegerSortedSet r2;
    IntegerSortedSet r3;

    setA.insertSorted( 4 );
    setA.insertSorted( 8 );
    setA.insertSorted( 12 );

    setB.insertSorted( 0 );
    setB.insertSorted( 1 );

    setC.insertSorted( 14 );

    setD.insertSorted( 5 );
    setD.insertSorted( 9 );

    // Primer caso: Elementos del conjunto *this son mayores que los elementos del "other".

    // Resultado esperado: {0,1,4,8,12}
    r1 = setA + setB;

    if( r1.toStr( ) != "{0,1,4,8,12}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testUnion (integerssortedsettest) message= Falló la unión de A = {4,8,12} y B = {0,1}" << std::endl;
    }

    // Segundo caso: Elementos del conjunto "other" son mayores que los elementos del conjunto *this. 

    // Resultado esperado: {4,8,12,14}
    r2 = setA + setC;

    if( r2.toStr( ) != "{4,8,12,14}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testUnion (integerssortedsettest) message= Falló la unión de A = {4,8,12} y C = {14}" << std::endl;
    }

    // Tercer caso: Intercalación de valores numéricos entre el conjunto "other" y *this.

    // Resultado esperado: {4, 5, 8, 9, 12}
    r3 = setA + setD;

    if( r3.toStr( ) != "{4,5,8,9,12}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testUnion (integerssortedsettest) message= Falló la unión de A = {4,8,12} y D = {5,9}" << std::endl;
    }
}

void testSetDifference()
{
    IntegerSortedSet setA;
    IntegerSortedSet setB;
    IntegerSortedSet setC;
    IntegerSortedSet setD;
    IntegerSortedSet setE;
    IntegerSortedSet r1;
    IntegerSortedSet r2;
    IntegerSortedSet r3;
    IntegerSortedSet r4;

    // Primer caso: diferencia de dos conjuntos sin elementos en común.

    setA.insertSorted( 4 );
    setA.insertSorted( 8 );
    setA.insertSorted( 10 );
    setA.insertSorted( 12 );

    setB.insertSorted( 5 );
    setB.insertSorted( 7 );
    setB.insertSorted( 9 );

    //Resultado esperado: {4,8,10,12}
    r1 = setA - setB;

    if( r1.toStr( ) != "{4,8,10,12}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDifference (integerssortedsettest) message= Falló la diferencia de A = {4,8,10,12} y B = {5,7,9}" << std::endl;
    }

    // Segundo caso: el conjunto "other" es subconjunto de *this.
    setC.insertSorted( 4 );
    setC.insertSorted( 8 );

    // Resultado esperado: {10,12}
    r2 = setA - setC;

    if( r2.toStr( ) != "{10,12}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDifference (integerssortedsettest) message= Falló la diferencia de A = {4,8,10,12} y C = {4,8}" << std::endl;
    }

    // Tercer caso: el conjunto *this es subconjunto de "other".

    setD.insertSorted( 5 );
    setD.insertSorted( 7 );
    setD.insertSorted( 9 );
    setD.insertSorted( 11 );

    // Resultado esperado: {}.
    r3 = setB - setD;

    if( r3.toStr( ) != "{}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDifference (integerssortedsettest) message= Falló la diferencia de B = {5,7,9} y D = {5,7,9,11}" << std::endl;
    }

    // Cuarto caso: diferencia de dos conjuntos que tienen elementos en común.

    setE.insertSorted( 7 );
    setE.insertSorted( 8 );
    setE.insertSorted( 11 );
    setE.insertSorted( 12 );

    // Resultado esperado: {5,9}.
    r4 = setD - setE;

    if( r4.toStr( ) != "{5,9}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testDifference (integerssortedsettest) message= Falló la diferencia de D = {5,7,9,11} y E = {7,8,11,12}" << std::endl;
    }

}

void testIntersection()
{
    IntegerSortedSet setA;
    IntegerSortedSet setB;
    IntegerSortedSet setC;
    IntegerSortedSet setD;
    IntegerSortedSet setE;
    IntegerSortedSet r1;
    IntegerSortedSet r2;
    IntegerSortedSet r3;
    IntegerSortedSet r4;

    // Primer caso: intersección de dos conjuntos sin elementos en común.

    setA.insertSorted( 4 );
    setA.insertSorted( 8 );
    setA.insertSorted( 10 );
    setA.insertSorted( 12 );

    setB.insertSorted( 5 );
    setB.insertSorted( 7 );
    setB.insertSorted( 9 );

    // Resultado esperado: {}.
    r1 = setA * setB;

    if( r1.toStr( ) != "{}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testIntersection (integerssortedsettest) message= Falló la intersección de A = {4,8,10,12} y B = {5,7,9}" << std::endl;
    }

    // Segundo caso: instersección de dos conjuntos con un elemento en común.

    setC.insertSorted( 4 );

    // Resultado esperado: {4}
    r2 = setA * setC;

    if( r2.toStr( ) != "{4}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testIntersection (integerssortedsettest) message= Falló la intersección de A = {4,8,10,12} y C = {4}" << std::endl;
    }

    // Tercer caso: intersección de dos conjuntos con dos elementos en común.

    setD.insertSorted( 8 );
    setD.insertSorted( 10 );

    // Resultado esperado: {8, 10}.
    r3 = setA * setD;

    if( r3.toStr( ) != "{8,10}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testIntersection (integerssortedsettest) message= Falló la intersección de A = {4,8,10,12} y D = {8,10}" << std::endl;
    }


    // Cuarto caso: intersección de dos conjuntos con tres elementos en común.

    setE.insertSorted( 8 );
    setE.insertSorted( 10 );
    setE.insertSorted( 12 );

    // Resultado esperado: {8,10,12}.
    r4 = setA * setE;

    if( r4.toStr( ) != "{8,10,12}" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=testIntersection (integerssortedsettest) message= Falló la intersección de A = {4,8,10,12} y E = {8,10,12}" << std::endl;
    }
}

// La prueba de la diferencia simétrica no se implementa porque por definición ( A/B = A-B U B-A ), hace uso de los operadores de unión, diferencia e intersección y si los tres 
// anteriores funcionan correctamente la diferenecia simétrica también lo hará.

int main(int argc, char** argv)
{
    std::cout << "%SUITE_STARTING% integerssortedsettest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testIntegerSortedSet (integerssortedsettest)" << std::endl;
    testIntegerSortedSet( );
    std::cout << "%TEST_FINISHED% time=0 testIntegerSortedSet (integerssortedsettest)" << std::endl;

    std::cout << "%TEST_STARTED% testIntegerSortedSet2 (integerssortedsettest)" << std::endl;
    testIntegerSortedSet2( );
    std::cout << "%TEST_FINISHED% time=0 testIntegerSortedSet2 (integerssortedsettest)" << std::endl;

    std::cout << "%TEST_STARTED% testInsertSorted (integerssortedsettest)" << std::endl;
    testInsertSorted( );
    std::cout << "%TEST_FINISHED% time=0 testInsertSorted (integerssortedsettest)" << std::endl;

    std::cout << "%TEST_STARTED% testDeleteNumber (integerssortedsettest)" << std::endl;
    testDeleteNumber( );
    std::cout << "%TEST_FINISHED% time=0 testDeleteNumber (integerssortedsettest)" << std::endl;

    std::cout << "%TEST_STARTED% testSearch (integerssortedsettest)" << std::endl;
    testSearch( );
    std::cout << "%TEST_FINISHED% time=0 testSearch (integerssortedsettest)" << std::endl;

    std::cout << "%TEST_STARTED% testUnion (integerssortedsettest)" << std::endl;
    testUnion( );
    std::cout << "%TEST_FINISHED% time=0 testUnion (integerssortedsettest)" << std::endl;

    std::cout << "%TEST_STARTED% testIntersection (integerssortedsettest)" << std::endl;
    testIntersection( );
    std::cout << "%TEST_FINISHED% time=0 testIntersection (integerssortedsettest)" << std::endl;

    std::cout << "%TEST_STARTED% testSetDifference (integerssortedsettest)" << std::endl;
    testSetDifference( );
    std::cout << "%TEST_FINISHED% time=0 testSetDifference (integerssortedsettest)" << std::endl;


    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return(EXIT_SUCCESS );
}
