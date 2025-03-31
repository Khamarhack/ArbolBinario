/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

using namespace std;

template<class T>
class NodoBinario {
protected:
    T dato; // Dato almacenado en el nodo
    NodoBinario<T> *hijoIzq; // Hijo izquierdo
    NodoBinario<T> *hijoDer; // Hijo derecho

public:
    // Constructor por defecto
    NodoBinario();
    
    // Obtiene el dato almacenado en el nodo
    T& obtenerDato();
    
    // Establece el dato del nodo
    void fijarDato(T& val);
    
    // Obtiene el hijo izquierdo
    NodoBinario<T>* obtenerHijoIzq();
    
    // Obtiene el hijo derecho
    NodoBinario<T>* obtenerHijoDer();
    
    // Fija el hijo izquierdo
    void fijarHijoIzq(NodoBinario<T> *izq);
    
    // Fija el hijo derecho
    void fijarHijoDer(NodoBinario<T> *der);
    
    // Calcula la altura del nodo
    int altura();
    
    // Calcula el tamaño del subárbol con raíz en este nodo
    int tamano();
    
    // Inserta un valor en el subárbol con raíz en este nodo
    void insertar(T& val);
    
    // Busca un nodo con el valor dado en el subárbol
    NodoBinario<T>* buscar(T& val);
    
    // Recorridos del árbol
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    
    // Obtiene el nodo con el valor más bajo en el subárbol
    NodoBinario<T>* extremo_izq();
    
    // Obtiene el nodo con el valor más alto en el subárbol
    NodoBinario<T>* extremo_der();
};

#include "NodoBinario.hxx"
#endif
