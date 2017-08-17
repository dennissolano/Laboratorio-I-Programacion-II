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
    std::shared_ptr<Node> current = other.head;
    std::shared_ptr<Node> last = nullptr;

    if( !current ) // Conjunto vacío.
    {
        head = nullptr;
    }
    else
    {
        head = std::shared_ptr<Node>( new Node( current->data ) );
        last = this->head;

        while( ( current = current->next ) )
        {
            last->next = std::shared_ptr<Node>( new Node( current->data ) );
            last = last->next;
        }
    }
}

// Apuntadores inteligentes, no se necesita más el destructor.

IntegerSortedSet::~IntegerSortedSet()
{
    std::shared_ptr<Node> current = head;
    std::shared_ptr<Node> next = nullptr;

    while( current )
    {
        next = current->next;
        // delete current;
        current = next;
    }
}

bool IntegerSortedSet::insertSorted(int number)
{
    bool result = false;
    std::shared_ptr<Node> current = head;
    std::shared_ptr<Node> previous = nullptr;

    if( !head ) // Conjunto vació. Agrega elemento a *this.
    {
        head = std::shared_ptr<Node>( new Node( number ) );
        result = true;
    }
    else
    {
        if( head->data > number ) // Insertar antes del inicio de la lista.
        {
            current = std::shared_ptr<Node>( new Node( number ) );
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

                        if( !current ) // Insertar al final.
                        {
                            result = true;
                        }
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
                previous->next = std::shared_ptr<Node>( new Node( number ) );
                previous->next->next = current;
            }
        }

    }

    return result;
}

bool IntegerSortedSet::deleteNumber(int number)
{
    std::shared_ptr<Node> current = head;
    std::shared_ptr<Node> previous = nullptr;
    bool result = false;

    // Lista tiene al menos un elemento y el elemento al inicio es menor que el que se busca elminar. 
    // Si la primera condición no se cumple, la lista está vacía. Si la segunda condición no se cumple el número a eliminar 
    // no está en la lista ya que es menor que el primer número de la lista.

    if( head && head->data <= number )
    {
        if( current->data == number ) // Eliminar al inicio.
        {
            current = head->next;
            // delete head;
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
                // delete previous->next; // Elimina el nodo objetivo.
                previous->next = current;

            }
        }
    }

    return result;
}

bool IntegerSortedSet::search(int number) const
{
    std::shared_ptr<Node> current = head;
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
    IntegerSortedSet * setUnion = new IntegerSortedSet( );
    std::shared_ptr<Node> p = this->head;
    std::shared_ptr<Node> q = other.head;
    std::shared_ptr<Node> last = nullptr;

    while( p && q ) // Mientras haya elementos por recorrer en ambos conjuntos.
    {
        if( p->data < q->data )
        {
            if( !last )
            {
                setUnion->head = std::shared_ptr<Node>( new Node( p->data ) );
                last = setUnion->head;
            }
            else
            {
                last->next = std::shared_ptr<Node>( new Node( p->data ) );
                last = last->next;
            }

            p = p->next;
        }
        else
        {
            if( q->data < p->data )
            {
                if( !last )
                {
                    setUnion->head = std::shared_ptr<Node>( new Node( q->data ) );
                    last = setUnion->head;
                }
                else
                {
                    last->next = std::shared_ptr<Node>( new Node( q->data ) );
                    last = last->next;
                }

                q = q->next;
            }
            else // Elementos idénticos.
            {
                if( !last )
                {
                    setUnion->head = std::shared_ptr<Node>( new Node( p->data ) );
                    last = setUnion->head;
                }
                else
                {
                    last->next = std::shared_ptr<Node>( new Node( p->data ) );
                    last = last->next;
                }

                p = p->next;
                q = q->next;
            }
        }
    } // No hay más elementos por recorrer en *this o en other, alguno de los dos conjuntos es vacío o ambos conjuntos son vacíos.


    if( !last ) // El conjunto resultanto está vacío, por lo tanto ambos conjuntos son vacíos o uno de ellos dos es vacío.
    {
        if( p && !q ) // *this es conjunto no vacío y other es conjunto vacío.
        {
            // return *( new IntegerSortedSet( *this ) );

            setUnion->head = std::shared_ptr<Node>( new Node( p->data ) );
            last = setUnion->head;
        }
        else
        {
            if( !p && q ) // *this es conjunto vacío y other es conjunto no vacío.
            {
                // return *(new IntegerSortedSet(other));

                setUnion->head = std::shared_ptr<Node>( new Node( q->data ) );
                last = setUnion->head;
            }
        }
    }


    while( p ) // No hay más elementos que recorrer en other.
    {
        last->next = std::shared_ptr<Node>( new Node( p->data ) );
        last = last->next;
        p = p->next;
    }

    while( q ) // No hay más elementos que recorrer en *this.
    {
        last->next = std::shared_ptr<Node>( new Node( q->data ) );
        last = last->next;
        q = q->next;
    }


    return *setUnion;
}

IntegerSortedSet& IntegerSortedSet::operator-(const IntegerSortedSet& other ) const
{
    IntegerSortedSet* difference = new IntegerSortedSet( );
    std::shared_ptr<Node> p = this->head;
    std::shared_ptr<Node> q = other.head;
    std::shared_ptr<Node> last = nullptr;

    while( p ) // Mientras haya elementos que recorrer en *this.
    {
        if( p && !q ) // Ya no hay más elementos en other(q) u other(q) es conjunto vacío, pero sí hay en *this(p) y todos se copian a la diferencia.
        {
            if( !last ) // Lista vacía.
            {
                difference->head = std::shared_ptr<Node>( new Node( p->data ) );
                last = difference->head;
                p = p->next;
            }
            while( p )
            {
                last->next = std::shared_ptr<Node>( new Node( p->data ) );
                last = last->next;
                p = p->next;
            }
        }
        else
        {
            if( p->data < q->data )
            {
                if( !last ) // Lista vacía.
                {
                    difference->head = std::shared_ptr<Node>( new Node( p->data ) );
                    last = difference->head;
                    p = p->next;
                }
                else
                {
                    last->next = std::shared_ptr<Node>( new Node( p->data ) );
                    last = last->next;
                    p = p->next;
                }
            }
            else
            {
                if( q->data < p->data )
                {
                    q = q->next;
                }
                else // Elementos iguales.
                {
                    p = p->next;
                    q = q->next;
                }
            }
        }
    }

    return *difference;
}

IntegerSortedSet& IntegerSortedSet::operator*(const IntegerSortedSet& other ) const
{
    IntegerSortedSet* intersection = new IntegerSortedSet( );
    std::shared_ptr<Node> currentThis = this->head;
    std::shared_ptr<Node> currentOther = other.head;
    std::shared_ptr<Node> last = nullptr;

    while( currentThis && currentOther )
    {
        if( currentThis->data < currentOther->data )
        {
            currentThis = currentThis->next;
        }
        else
        {
            if( currentOther->data < currentThis->data )
            {
                currentOther = currentOther->next;
            }
            else // Elemento en ambos conjuntos.
            {
                if( !last ) // Conjunto vacío.
                {
                    intersection->head = std::shared_ptr<Node>( new Node( currentThis->data ) );
                    last = intersection->head;
                }
                else // Emparejamiento.
                {
                    last->next = std::shared_ptr<Node>( new Node( currentThis->data ) );
                    last = last->next;
                }

                currentThis = currentThis->next;
                currentOther = currentOther->next;
            }
        }
    }

    return *intersection;

}

IntegerSortedSet& IntegerSortedSet::operator/(const IntegerSortedSet& other ) const
{
    // Implementar utilizando lógica de emparejamiento.
}

std::string IntegerSortedSet::toStr() const
{
    std::stringstream buffer; // Instancia de flujo de salida.
    std::shared_ptr<Node> current = head;
    buffer << '{';

    while( current )
    {
        buffer << current->data;
        current = current->next;

        if( current )
        {
            buffer << ',';
        }
    }

    buffer << '}';

    return buffer.str( );
}
