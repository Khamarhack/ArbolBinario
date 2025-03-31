/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#ifndef __ARBOLBINARIO__H__
#define __ARBOLBINARIO__H__

#include "NodoBinario.h"

using namespace std;

template<class T>
class ArbolBinario {
protected:
    NodoBinario<T> *raiz; // Raíz del árbol

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
    
    // Inserta un valor en el árbol
    void insertar(T& val);
    
    // Elimina un valor del árbol
    bool eliminar(T& val);
    
    // Busca un nodo con el valor dado
    NodoBinario<T>* buscar(T& val);
    
    // Recorridos del árbol
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#endif
