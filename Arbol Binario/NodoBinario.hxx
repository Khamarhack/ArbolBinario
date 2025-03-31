// NodoBinario.hxx
#include "NodoBinario.h"
#include <queue>

using namespace std;

// Constructor por defecto
template<class T>
NodoBinario<T>::NodoBinario() {
    this->hijoIzq = NULL;
    this->hijoDer = NULL;
}

// Devuelve el dato del nodo
template<class T>
T& NodoBinario<T>::obtenerDato() {
    return this->dato;
}

// Asigna un valor al nodo
template<class T>
void NodoBinario<T>::fijarDato(T& val) {
    this->dato = val;
}

// Devuelve el hijo izquierdo
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq() {
    return this->hijoIzq;
}

// Devuelve el hijo derecho
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

// Calcula el tamaño del subárbol
template<class T>
int NodoBinario<T>::tamano() {
    if (!this) return 0;
    int tamanoIzq = this->hijoIzq ? this->hijoIzq->tamano() : 0;
    int tamanoDer = this->hijoDer ? this->hijoDer->tamano() : 0;
    return 1 + tamanoIzq + tamanoDer;
}

// Inserta un valor en el subárbol
template<class T>
void NodoBinario<T>::insertar(T& val) {
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
NodoBinario<T>* NodoBinario<T>::buscar(T& val) {
    if (this->dato == val) return this;
    if (val < this->dato && this->hijoIzq) return this->hijoIzq->buscar(val);
    if (val > this->dato && this->hijoDer) return this->hijoDer->buscar(val);
    return NULL;
}

// Encuentra el nodo con el menor valor
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_izq() {
    return this->hijoIzq ? this->hijoIzq->extremo_izq() : this;
}

// Encuentra el nodo con el mayor valor
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_der() {
    return this->hijoDer ? this->hijoDer->extremo_der() : this;
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

// Recorrido postorden
template<class T>
void NodoBinario<T>::posOrden() {
    if (this->hijoIzq) this->hijoIzq->posOrden();
    if (this->hijoDer) this->hijoDer->posOrden();
    cout << this->dato << " ";
}

// Recorrido por niveles
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


