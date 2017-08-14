/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IntegerSortedSet.cpp
 * Author: B59304
 * 
 * Created on 10 de agosto de 2017, 11:19 AM
 */

#include "IntegerSortedSet.h"

IntegerSortedSet::IntegerSortedSet()
: head{nullptr}
{
}

IntegerSortedSet::IntegerSortedSet(const IntegerSortedSet& other)
{
    Node* current = other.head;
    Node* last = nullptr;

    if( !current ) // Conjunto vacío.
    {
        head = nullptr;
    }
    else
    {
        head = new Node( current->data );
        last = this->head;

        while( ( current = current->next ) )
        {
            last->next = new Node( current->data );
            last = last->next;
        }
    }
}

IntegerSortedSet::~IntegerSortedSet()
{
    Node* current = head;
    Node* next = nullptr;

    while( current )
    {
        next = current->next;
        delete current;
        current = next;
    }
}

bool IntegerSortedSet::insertSorted(int number)
{
    bool result = false;
    Node* current = head;
    Node* previous = nullptr;

    if( !head ) // Conjunto vació. Agrega elemento a *this.
    {
        head = new Node( number );
        result = true;
    }
    else
    {
        if( head->data > number ) // Insertar antes del inicio de la lista.
        {
            current = new Node( number );
            current->next = head;
            head = current;
            result = true;
        }
        else
        {
            while( current )
            {
                if( current->data == number ) // Elemento ya insertado, no se agrega.
                {
                    current = nullptr;
                }
                else
                {
                    if( current->data < number )
                    {
                        previous = current;
                        current = current->next;
                    }
                    else
                    {
                        result = true; // Agregar elemento.
                        current = nullptr;
                    }
                }
            }

            if( result ) // Agregar elemento en medio y al final.
            {
                current = previous->next;
                previous->next = new Node( number );
                previous->next->next = current;
            }
        }

    }

    return result;
}

bool IntegerSortedSet::deleteNumber(int number)
{
    Node* current = head;
    Node* previous = nullptr;
    bool result = false;

    // Lista tiene al menos un elemento y el elemento al inicio es menor que el que se busca elminar. 
    // Si la primera condición no se cumple, la lista está vacía. Si la segunda condición no se cumple el número a eliminar 
    // no está en la lista ya que es menor que el primer número de la lista.

    if( head && head->data <= number )
    {
        if( current->data == number ) // Eliminar al inicio.
        {
            current = head->next;
            delete head;
            head = current;
            result = true;
        }
        else
        {
            while( current ) // Continuar buscando al elemento.
            {
                if( current->data == number ) // Elemento a eliminar encontrado.
                {
                    current = nullptr;
                    result = true;
                }
                else
                {
                    if( current->data < number ) // Si el dato apuntado por el nodo actual es menor que el numero a eliminar.
                    {
                        previous = current;
                        current = current->next;
                    }
                    else // El dato apuntado por el nodo actual es mayor al elemento a eliminar, por lo tanto no está en el conjunto.
                    {
                        current = nullptr;
                    }
                }
            }

            if( result ) // Eliminar al medio o al final.
            {
                current = previous->next->next; // Guardar el nodo siguiente al que se va a eliminar.
                delete previous->next; // Elimina el nodo objetivo.
                previous->next = current;

            }
        }
    }

    return result;
}

bool IntegerSortedSet::search(int number) const
{
    Node* current = head;
    bool resutl = false;

    while( current )
    {
        if( current->data == number )
        {
            resutl = true; // Elemento encontrado.
            current = nullptr;
        }
        else // Continúa búsqueda de elemento.
        {
            // El elemento del nodo actual es menor que el elemento buscado, por lo tanto se puede seguir avanzando en la lista.
            if( current->data < number )
            {
                current = current->next;
            }
            else
            {
                // El elemento del nodo actual es mayor que el elemento buscado, esto no puede
                //suceder ya que es una lista ordendada, por lo tanto el elemento no está en la lista.
                current = nullptr;
            }
        }
    }

    return resutl;
}

IntegerSortedSet& IntegerSortedSet::operator+(const IntegerSortedSet& other ) const
{
}

IntegerSortedSet& IntegerSortedSet::operator-(const IntegerSortedSet& other ) const
{
}

IntegerSortedSet& IntegerSortedSet::operator*(const IntegerSortedSet& other ) const
{
}

IntegerSortedSet& IntegerSortedSet::operator/(const IntegerSortedSet& other ) const
{
}

std::string IntegerSortedSet::toStr() const
{
}
