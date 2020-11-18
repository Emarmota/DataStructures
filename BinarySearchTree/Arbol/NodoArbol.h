#pragma once
#include <iostream>
using namespace std;

class NodoArbol
{
public: //Metodos públicos
	NodoArbol(); //Constructor por omisión
	NodoArbol(string);


	string getDato(); //Accesor
	void setDato(string); //Modificador 
	NodoArbol* getDerecha(); //Accesor
	void setDerecha(NodoArbol*); //Modificador

	NodoArbol* getIzquierda(); //Accesor
	void setIzquierda(NodoArbol*); //Modificador


	virtual ~NodoArbol();

private: //Atributos privados
	string dato; //Es la parte de la informacion
	NodoArbol* derecha;
	NodoArbol* izquierda;

};

