// NodoBinario.hxx
// NodoBinario.hxx
#include "NodoBinario.h"
#include <queue>
#include <iostream>

using namespace std;

// Constructor por defecto, inicializa los hijos como NULL
template<class T>
NodoBinario<T>::NodoBinario() {
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

// Retorna el dato almacenado en el nodo
template<class T>
T& NodoBinario<T>::obtenerDato() {
    return this->dato;
}

// Asigna un valor al nodo
template<class T>
void NodoBinario<T>::fijarDato(T val) {
    this->dato = val;
}

// Retorna el hijo izquierdo
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq() {
    return this->hijoIzq;
}

// Retorna el hijo derecho
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer() {
    return this->hijoDer;
}

// Asigna el hijo izquierdo
template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq) {
    this->hijoIzq = izq;
}

// Asigna el hijo derecho
template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der) {
    this->hijoDer = der;
}

// Calcula la altura del nodo
template<class T>
int NodoBinario<T>::altura() {
    if (!this) return 0;
    int alturaIzq = this->hijoIzq ? this->hijoIzq->altura() : 0;
    int alturaDer = this->hijoDer ? this->hijoDer->altura() : 0;
    return 1 + max(alturaIzq, alturaDer);
}

// Calcula el tamaño del subárbol con raíz en este nodo
template<class T>
int NodoBinario<T>::tamano() {
    if (!this) return 0;
    int tamIzq = this->hijoIzq ? this->hijoIzq->tamano() : 0;
    int tamDer = this->hijoDer ? this->hijoDer->tamano() : 0;
    return 1 + tamIzq + tamDer;
}

// Inserta un valor en el subárbol de forma recursiva
template<class T>
void NodoBinario<T>::insertar(T val) {
    if (val > this->dato) {
        if (!this->hijoDer) {
            this->hijoDer = new NodoBinario<T>();
            this->hijoDer->fijarDato(val);
        } else {
            this->hijoDer->insertar(val);
        }
    } else if (val < this->dato) {
        if (!this->hijoIzq) {
            this->hijoIzq = new NodoBinario<T>();
            this->hijoIzq->fijarDato(val);
        } else {
            this->hijoIzq->insertar(val);
        }
    }
}

// Busca un nodo con el valor dado
template<class T>
NodoBinario<T>* NodoBinario<T>::buscar(T val) {
    if (!this || this->dato == val) return this;
    if (val < this->dato) return this->hijoIzq ? this->hijoIzq->buscar(val) : NULL;
    return this->hijoDer ? this->hijoDer->buscar(val) : NULL;
}

// Retorna el nodo con el valor más alto en el subárbol
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_der() {
    return this->hijoDer ? this->hijoDer->extremo_der() : this;
}

// Retorna el nodo con el valor más bajo en el subárbol
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_izq() {
    return this->hijoIzq ? this->hijoIzq->extremo_izq() : this;
}

// Recorrido preorden
template<class T>
void NodoBinario<T>::preOrden() {
    cout << this->dato << " ";
    if (this->hijoIzq) this->hijoIzq->preOrden();
    if (this->hijoDer) this->hijoDer->preOrden();
}

// Recorrido inorden
template<class T>
void NodoBinario<T>::inOrden() {
    if (this->hijoIzq) this->hijoIzq->inOrden();
    cout << this->dato << " ";
    if (this->hijoDer) this->hijoDer->inOrden();
}

// Recorrido posorden
template<class T>
void NodoBinario<T>::posOrden() {
    if (this->hijoIzq) this->hijoIzq->posOrden();
    if (this->hijoDer) this->hijoDer->posOrden();
    cout << this->dato << " ";
}

// Recorrido por niveles utilizando una cola
template<class T>
void NodoBinario<T>::nivelOrden() {
    queue<NodoBinario<T>*> cola;
    cola.push(this);
    while (!cola.empty()) {
        NodoBinario<T>* actual = cola.front();
        cola.pop();
        cout << actual->dato << " ";
        if (actual->hijoIzq) cola.push(actual->hijoIzq);
        if (actual->hijoDer) cola.push(actual->hijoDer);
    }
}

