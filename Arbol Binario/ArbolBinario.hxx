/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

// Constructor por defecto, inicializa la raíz como NULL
template<class T>
ArbolBinario<T>::ArbolBinario() {
    this->raiz = NULL;
}

// Verifica si el árbol está vacío
template<class T>
bool ArbolBinario<T>::esVacio() {
    return this->raiz == NULL;
}

// Devuelve el dato almacenado en la raíz
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

// Inserta un valor en el árbol
template<class T>
void ArbolBinario<T>::insertar(T& val) {
    if (this->raiz != NULL) {
        this->raiz->insertar(val);
    } else {
        NodoBinario<T>* nuevo = new NodoBinario<T>();
        nuevo->fijarDato(val);
        this->raiz = nuevo;
    }
}

// Elimina un valor del árbol
template<class T>
bool ArbolBinario<T>::eliminar(T& val) {
    NodoBinario<T>* borrar = this->buscar(val);
    if (borrar == NULL) {
        return false;
    }
    
    if (borrar->obtenerHijoIzq() != NULL) {
        NodoBinario<T>* nuevo = borrar->obtenerHijoIzq()->extremo_der();
        borrar->fijarDato(nuevo->obtenerDato());
        delete nuevo;
    } else if (borrar->obtenerHijoDer() != NULL) {
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

// Recorrido preorden
template<class T>
void ArbolBinario<T>::preOrden() {
    if (this->raiz) this->raiz->preOrden();
}

// Recorrido inorden
template<class T>
void ArbolBinario<T>::inOrden() {
    if (this->raiz) this->raiz->inOrden();
}

// Recorrido posorden
template<class T>
void ArbolBinario<T>::posOrden() {
    if (this->raiz) this->raiz->posOrden();
}

// Recorrido por niveles
template<class T>
void ArbolBinario<T>::nivelOrden() {
    if (this->raiz) this->raiz->nivelOrden();
}
