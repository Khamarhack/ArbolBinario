// ArbolBinario.hxx
#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

// Constructor de ArbolBinario
// Inicializa el árbol con una raíz nula
template<class T>
ArbolBinario<T>::ArbolBinario() {
    this->raiz = NULL;
}

// Verifica si el árbol está vacío
template<class T>
bool ArbolBinario<T>::esVacio() {
    return this->raiz == NULL;
}

// Devuelve el dato de la raíz
template<class T>
T& ArbolBinario<T>::datoRaiz() {
    return this->raiz->obtenerDato();
}

// Calcula la altura del árbol
template<class T>
int ArbolBinario<T>::altura() {
    return this->raiz ? this->raiz->altura() : 0;
}

// Calcula el tamaño del árbol
template<class T>
int ArbolBinario<T>::tamano() {
    return this->raiz ? this->raiz->tamano() : 0;
}

// Inserta un nuevo valor en el árbol
template<class T>
void ArbolBinario<T>::insertar(T& val) {
    if (this->raiz) {
        this->raiz->insertar(val);
    } else {
        this->raiz = new NodoBinario<T>();
        this->raiz->fijarDato(val);
    }
}

// Elimina un nodo con el valor dado
template<class T>
bool ArbolBinario<T>::eliminar(T& val) {
    NodoBinario<T>* borrar = this->buscar(val);
    if (!borrar) return false;
    
    if (borrar->obtenerHijoIzq()) {
        NodoBinario<T>* nuevo = borrar->obtenerHijoIzq()->extremo_der();
        borrar->fijarDato(nuevo->obtenerDato());
        delete nuevo;
    } else if (borrar->obtenerHijoDer()) {
        NodoBinario<T>* nuevo = borrar->obtenerHijoDer()->extremo_izq();
        borrar->fijarDato(nuevo->obtenerDato());
        delete nuevo;
    }
    return true;
}

// Busca un nodo con el valor dado
template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val) {
    return this->raiz ? this->raiz->buscar(val) : NULL;
}

// Recorridos del árbol
template<class T>
void ArbolBinario<T>::preOrden() {
    if (this->raiz) this->raiz->preOrden();
}

template<class T>
void ArbolBinario<T>::inOrden() {
    if (this->raiz) this->raiz->inOrden();
}

template<class T>
void ArbolBinario<T>::posOrden() {
    if (this->raiz) this->raiz->posOrden();
}

template<class T>
void ArbolBinario<T>::nivelOrden() {
    if (this->raiz) this->raiz->nivelOrden();
}
