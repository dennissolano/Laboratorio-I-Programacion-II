/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerSortedSet.h
 * Author: B59304
 *
 * Created on 10 de agosto de 2017, 11:19 AM
 */

#ifndef INTEGERSORTEDSET_H
#define INTEGERSORTEDSET_H

#include <iostream>
#include <sstream>
#include <memory>

//  Representa un conjunto ordenado de enteros.

class IntegerSortedSet
{
private:

    struct Node
    {
        int data;
        std::shared_ptr<Node> next;

        Node(int number)
        : data{ number }
        , next{ nullptr }
        {
        }

        ~Node()
        {
            std::cout << "Borrando: " << data << std::endl;
        }
    };

    std::shared_ptr<Node> head;

public:
    // EFE: Construye un nuevo conjunto de enteros vacío.
    IntegerSortedSet();

    // EFE: Construye una copia idéntica e independiente de "other".
    IntegerSortedSet(const IntegerSortedSet& other);

    ~IntegerSortedSet();

    // MOD: *this.
    // EFE: Si "number" no pertenece a *this, lo agrega preservando el orden y retorna verdadero,
    // en caso contrario no tiene efecto y retorna falso.
    bool insertSorted(int number);

    // MOD: *this.
    // EFE: Si "number" pertenece a *this, entonces lo elimina preservando el orden y retorna verdadero,
    // en caso contrario no tiene efecto y retorna falso.
    bool deleteNumber(int number);

    // EFE: Si "number" pertenece a *this, entonces retorna verdadero, en caso contrario retorna falso.
    bool search(int number) const;

    // EFE: Retorna un nuevo conjunto ordenado que representa la unión de *this con "other".
    IntegerSortedSet& operator+(const IntegerSortedSet& other) const;

    // EFE: Retorna un nuevo conjunto ordenado que representa la diferencia de *this con "other".
    IntegerSortedSet& operator-(const IntegerSortedSet& other) const;

    // EFE: Retorna un nuevo conjunto ordenado que representa la intersección de *this con "other".
    IntegerSortedSet& operator*(const IntegerSortedSet& other) const;

    // EFE: Retorna un nuevo conjunto ordenado que representa la diferencia simétrica de *this con "other".
    IntegerSortedSet& operator/(const IntegerSortedSet& other) const;

    // EFE: Retorna una hilera que representa a *this.
    std::string toStr() const;
};

#endif /* INTEGERSORTEDSET_H */