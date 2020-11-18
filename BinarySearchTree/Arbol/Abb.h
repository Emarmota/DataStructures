#pragma once

#include "NodoArbol.h"
#include <iostream>

using namespace std;

class Abb
{
	NodoArbol* root;

	public:
		Abb(); 
		~Abb();
		NodoArbol* getRoot();
		void setRoot(NodoArbol*);
		void Inserta(string);
		void preorden(NodoArbol*);
		void posorden(NodoArbol*);
		void inorden(NodoArbol*);
		void definir(string str);
		void borrar(string str);
		bool buscar(string str);
		int contarNodos(NodoArbol*, int cont);
		int contarInternos(NodoArbol*, int cont);
		int contarHojas(NodoArbol*, int cont);
		void contarNodosIH(NodoArbol*, int& internos, int& hojas);
		NodoArbol* BorrarSinHijos(NodoArbol*, NodoArbol*);
		NodoArbol* BorrarUnHijo(NodoArbol*, NodoArbol*);
		NodoArbol* BorrarDosHijos(NodoArbol*, NodoArbol*);

	private:
};

