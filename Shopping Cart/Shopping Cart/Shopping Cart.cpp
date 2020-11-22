// Shopping Cart.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "product.h"
#include "Products.h"


int main()
{
	//Product product1("Muffin",100);
	Products products("products.dat");
	
	//cout << product1.name << endl;
	//cout << product1.price << endl;

	//Product product2("Chocolate", -1); //Si asigno un num negativo a precio le pongo 0 y lanzo msj en pantalla
	//cout << product2.name << endl;
	//cout << product2.price << endl;

	/*
	//Operador ==
	if (product1 != "Muffin")
		cout << "Sí son diferentes\n";
	else
		cout << "Son iguales\n";
	//Operador !=
	if (product1 != "Muffin")
		cout << "Sí son diferentes\n";
	else
		cout << "Son iguales\n";

	cout << "Los datos del producto1 son: " << product1<<endl;
	*/
	
	//products.printProducts();
	cout << "El sexto producto es: " << products[0] << endl;
	cout << "El tamaño del arreglo es: " << products.products_size();
}
