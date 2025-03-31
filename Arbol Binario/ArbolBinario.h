#ifndef __ARBOLBINARIO__H__
#define __ARBOLBINARIO__H__

#include "NodoBinario.h"

using namespace std;

template<class T>
class ArbolBinario {
  protected:
    NodoBinario<T> *raiz; // Raíz del árbol
public:
    ArbolBinario(); // Constructor
    bool esVacio(); // Verifica si el árbol está vacío
    T& datoRaiz(); // Devuelve el dato de la raíz
    int altura(); // Calcula la altura del árbol
    int tamano(); // Calcula el número de nodos en el árbol
    void insertar(T& val); // Inserta un valor en el árbol
    bool eliminar(T& val); // Elimina un valor del árbol
    NodoBinario<T>* buscar(T& val); // Busca un nodo con el valor dado
    void preOrden(); // Recorre el árbol en preorden
    void inOrden(); // Recorre el árbol en inorden
    void posOrden(); // Recorre el árbol en posorden
    void nivelOrden(); // Recorre el árbol por niveles
};

#include "ArbolBinario.hxx"
#endif

