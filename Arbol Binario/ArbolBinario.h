#ifndef __ARBOLBINARIO__H__
#define __ARBOLBINARIO__H__

#include "NodoBinario.h"

using namespace std;

template<class T>
class ArbolBinario {
protected:
    NodoBinario<T> *raiz;
public:
    // Constructor por defecto
    ArbolBinario();
    
    // Verifica si el árbol está vacío
    bool esVacio();
    
    // Devuelve el dato almacenado en la raíz
    T& datoRaiz();
    
    // Calcula la altura del árbol
    int altura();
    
    // Calcula el tamaño del árbol
    int tamano();
    
    // Inserta un nuevo elemento en el árbol
    void insertar(T& val);
    
    // Elimina un elemento del árbol
    bool eliminar(T& val);
    
    // Busca un elemento en el árbol
    NodoBinario<T>* buscar(T& val);
    
    // Recorridos del árbol
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "ArbolBinario.hxx"
#endif

