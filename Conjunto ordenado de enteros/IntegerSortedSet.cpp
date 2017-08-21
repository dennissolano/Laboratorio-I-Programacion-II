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

std::shared_ptr<IntegerSortedSet> IntegerSortedSet::result(nullptr);

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
    if( result )
    {
        result.reset( );
    }

    result = std::shared_ptr<IntegerSortedSet>( new IntegerSortedSet( ) );
    std::shared_ptr<Node> temp1 = this->head;
    std::shared_ptr<Node> temp2 = other.head;
    std::shared_ptr<Node> last = nullptr;

    while( temp1 && temp2 ) // Mientras haya elementos por recorrer en ambos conjuntos.
    {
        if( temp1->data < temp2->data )
        {
            if( !last )
            {
                result->head = std::shared_ptr<Node>( new Node( temp1->data ) );
                last = result->head;
            }
            else
            {
                last->next = std::shared_ptr<Node>( new Node( temp1->data ) );
                last = last->next;
            }

            temp1 = temp1->next;
        }
        else
        {
            if( temp2->data < temp1->data )
            {
                if( !last )
                {
                    result->head = std::shared_ptr<Node>( new Node( temp2->data ) );
                    last = result->head;
                }
                else
                {
                    last->next = std::shared_ptr<Node>( new Node( temp2->data ) );
                    last = last->next;
                }

                temp2 = temp2->next;
            }
            else // Elementos idénticos. Se agrega solamente uno.
            {
                if( !last )
                {
                    result->head = std::shared_ptr<Node>( new Node( temp1->data ) );
                    last = result->head;
                }
                else
                {
                    last->next = std::shared_ptr<Node>( new Node( temp1->data ) );
                    last = last->next;
                }

                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    } // No hay más elementos por recorrer en *this o en other, alguno de los dos conjuntos es vacío o ambos conjuntos son vacíos.


    if( !last ) // El conjunto resultanto está vacío, por lo tanto ambos conjuntos son vacíos o uno de ellos dos es vacío.
    {
        if( temp1 && !temp2 ) // *this es conjunto no vacío y other es conjunto vacío.
        {
            result->head = std::shared_ptr<Node>( new Node( temp1->data ) );
            last = result->head;
            temp1 = temp1->next;
        }
        else
        {
            if( !temp1 && temp2 ) // *this es conjunto vacío y other es conjunto no vacío.
            {
                result->head = std::shared_ptr<Node>( new Node( temp2->data ) );
                last = result->head;
                temp2 = temp2->next;
            }
        }
    }

    // Para los siguiente ciclos se asume que el conjunto resultante tiene al menos un elemento. 
    // Además si ambos conjuntos *this y other son vacíos no tienen ningún efecto sobre los ciclos.

    while( temp1 ) // No hay más elementos que recorrer en other u other es conjunto vacío.
    {
        last->next = std::shared_ptr<Node>( new Node( temp1->data ) );
        last = last->next;
        temp1 = temp1->next;
    }

    while( temp2 ) // No hay más elementos que recorrer en *this o *this es conjunto vacío.
    {
        last->next = std::shared_ptr<Node>( new Node( temp2->data ) );
        last = last->next;
        temp2 = temp2->next;
    }

    return *result; // En caso de que *this y other sean conjuntos vacíos retorna un conjunto vacío.
}

IntegerSortedSet& IntegerSortedSet::operator-(const IntegerSortedSet& other ) const
{
    if( result )
    {
        result.reset( );
    }

    result = std::shared_ptr<IntegerSortedSet>( new IntegerSortedSet( ) );
    std::shared_ptr<Node> temp1 = this->head;
    std::shared_ptr<Node> temp2 = other.head;
    std::shared_ptr<Node> last = nullptr;

    while( temp1 && temp2 )
    {
        if( temp1->data < temp2->data )
        {
            if( !last ) // Lista vacía.
            {
                result->head = std::shared_ptr<Node>( new Node( temp1->data ) );
                last = result->head;
            }
            else
            {
                last->next = std::shared_ptr<Node>( new Node( temp1->data ) );
                last = last->next;
            }

            temp1 = temp1->next;
        }
        else
        {
            if( temp2->data < temp1->data )
            {
                temp2 = temp2->next;
            }
            else // Elementos iguales.
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }

    if( !last ) // Conjunto resultante está vacío, por lo tanto ambos conjuntos están vacíos o alguno de ellos está vacío.
    {
        if( temp1 && !temp2 ) // *this es un conjunto no vacío y other es conjunto vacío. Único caso relevante.
        {
            result->head = std::shared_ptr<Node>( new Node( temp1->data ) );
            last = result->head;
            temp1 = temp1->next;
        }
    }

    while( temp1 )
    {
        last->next = std::shared_ptr<Node>( new Node( temp1->data ) );
        last = last->next;
        temp1 = temp1->next;
    }

    return *result; // Si ambos conjuntos son vacíos o *this es conjunto vacío se retorna un conjunto vacío.
}

IntegerSortedSet& IntegerSortedSet::operator*(const IntegerSortedSet& other ) const
{
    if( result )
    {
        result.reset( );
    }

    result = std::shared_ptr<IntegerSortedSet>( new IntegerSortedSet( ) );
    std::shared_ptr<Node> temp1 = this->head;
    std::shared_ptr<Node> temp2 = other.head;
    std::shared_ptr<Node> last = nullptr;

    while( temp1 && temp2 )
    {
        if( temp1->data < temp2->data )
        {
            temp1 = temp1->next;
        }
        else
        {
            if( temp2->data < temp1->data )
            {
                temp2 = temp2->next;
            }
            else // Elemento en ambos conjuntos.
            {
                if( !last ) // Conjunto resultante vacío.
                {
                    result->head = std::shared_ptr<Node>( new Node( temp1->data ) );
                    last = result->head;
                }
                else // Emparejamiento.
                {
                    last->next = std::shared_ptr<Node>( new Node( temp1->data ) );
                    last = last->next;
                }

                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }

    return *result;

}

IntegerSortedSet& IntegerSortedSet::operator/(const IntegerSortedSet& other ) const
{
    if( result )
    {
        result.reset( );
    }

    result = std::shared_ptr<IntegerSortedSet>( new IntegerSortedSet( ) );
    std::shared_ptr<Node> temp1 = this->head;
    std::shared_ptr<Node> temp2 = other.head;
    std::shared_ptr<Node> last = nullptr;

    while( temp1 && temp2 ) // Mientras haya elementos por recorrer en ambos conjuntos.
    {
        if( temp1->data < temp2->data )
        {
            if( !last )
            {
                result->head = std::shared_ptr<Node>( new Node( temp1->data ) );
                last = result->head;
            }
            else
            {
                last->next = std::shared_ptr<Node>( new Node( temp1->data ) );
                last = last->next;
            }

            temp1 = temp1->next;
        }
        else
        {
            if( temp2->data < temp1->data )
            {
                if( !last )
                {
                    result->head = std::shared_ptr<Node>( new Node( temp2->data ) );
                    last = result->head;
                }
                else
                {
                    last->next = std::shared_ptr<Node>( new Node( temp2->data ) );
                    last = last->next;
                }

                temp2 = temp2->next;
            }
            else // Elementos iguales, son ignorados.
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
    }

    if( !last ) // Conjunto resultante no tiene elementos, por lo tanto ambos conjuntos son vacíos o alguno de ellos es conjunto vacío.
    {
        if( temp1 && !temp2 ) // *this es conjunto no vacío y other es conjunto vacío.
        {
            result->head = std::shared_ptr<Node>( new Node( temp1->data ) );
            last = result->head;
            temp1 = temp1->next;
        }
        else
        {
            if( !temp1 && temp2 ) // *this es conjunto vacío y other es conjunto no vacío.
            {
                result->head = std::shared_ptr<Node>( new Node( temp2->data ) );
                last = result->head;
                temp2 = temp2->next;
            }
        } // El caso en que ambos conjuntos son vacíos es irrelevante.
    }

    //Asumimos que el conjunto resultante tiene al menos un elemento.

    while( temp1 ) // Ya no hay más elementos por recorrer en other, pero sí en *this.
    {
        last->next = std::shared_ptr<Node>( new Node( temp1->data ) );
        last = last->next;
        temp1 = temp1->next;
    }

    while( temp2 ) // Ya no hay más elementos por recorrer en *this, pero sí en other.
    {
        last->next = std::shared_ptr<Node>( new Node( temp2->data ) );
        last = last->next;
        temp2 = temp2->next;
    }

    return *result; // En caso de que ambos conjuntos sean vacíos se retorna un conjunto vacío.
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
