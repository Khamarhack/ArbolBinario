/*******************************************
Fecha: 26 marzo 2025
Autor: Santiago Camargo
Tema: Taller Arboles
Estructuras de datos
******************************************/
#include<iostream>
#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

main(int argc, char* argv[])
{
    ArbolBinario<int> arbolito;
	for(int i=0; i<7; i++)
	{
		int dato;
		cin>>dato;
		arbolito.insertar(dato);
	}
	
	arbolito.nivelOrden();
}
