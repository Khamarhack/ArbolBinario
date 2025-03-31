// NodoBinario.h
#ifndef __NODOBINARIO__H__
#define __NODOBINARIO__H__

using namespace std;

template<class T>
class NodoBinario {
protected:
    T dato;
    NodoBinario<T> *hijoIzq;
    NodoBinario<T> *hijoDer;

public:
    // Constructor por defecto
    NodoBinario();
    
    // Obtiene el dato almacenado en el nodo
    T& obtenerDato();
    
    // Asigna un valor al nodo
    void fijarDato(T& val);
    
    // Obtiene el hijo izquierdo
    NodoBinario<T>* obtenerHijoIzq();
    
    // Obtiene el hijo derecho
    NodoBinario<T>* obtenerHijoDer();
    
    // Establece el hijo izquierdo
    void fijarHijoIzq(NodoBinario<T> *izq);
    
    // Establece el hijo derecho
    void fijarHijoDer(NodoBinario<T> *der);
    
    // Calcula la altura del subárbol
    int altura();
    
    // Calcula el tamaño del subárbol
    int tamano();
    
    // Inserta un nuevo valor en el subárbol
    void insertar(T& val);
    
    // Busca un nodo con un valor específico
    NodoBinario<T>* buscar(T& val);
    
    // Recorridos del subárbol
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
    
    // Encuentra el nodo con el valor más bajo en el subárbol
    NodoBinario<T>* extremo_izq();
    
    // Encuentra el nodo con el valor más alto en el subárbol
    NodoBinario<T>* extremo_der();
};

#include "NodoBinario.hxx"
#endif
