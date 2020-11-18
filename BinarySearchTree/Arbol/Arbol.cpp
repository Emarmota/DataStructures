
#include <iostream>
#include "NodoArbol.h"
#include "Abb.h"
#include <fstream> //Lee datos de un .txt
#include <string>
#include <algorithm>


int main()
{
    int cont = 0;
    int hojas = 0;
    int internos = 0;
    Abb arbolito;
    string resp="hola muchos gusto";

    fstream newfile; //Creo un objeto de la clase fstream para leer .txt

    newfile.open("dictionary.txt", ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) {   //checking whether the file is open
        string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            arbolito.Inserta(tp);
            std::cout << tp << "\n"; //print the data of the string
        }
        newfile.close(); //close the file object.
    }



    do {
        std::cout << " \n\n Ingrese la palabra para buscarla. \n Ingrese D + palabra para borrarla.\n ingrese I + palabra para Insertarla.\n C para regresar todas las palabras." <<endl;
        getline(cin, resp);
        std::string data = resp;
        // convert string to back to lower case
        std::for_each(data.begin(), data.end(), [](char& c) {
            c = ::tolower(c);
            });
       
        if (data[0] == 'd') {
            std::string s = data;
            std::string delimiter = " ";

            size_t pos = 0;
            std::string token;
            while ((pos = s.find(delimiter)) != (std::string::npos)) {
                token = s.substr(0, pos);
                s.erase(0, pos + delimiter.length());
            }
            arbolito.borrar(s);
            std::cout << endl;
            system("pause");
        }

        else if (data[0] == 'i') {
            std::string s = data;
            std::string delimiter = " ";

            size_t pos = 0;
            std::string token;
            while ((pos = s.find(delimiter)) != (std::string::npos)) {
                token = s.substr(0, pos);
                s.erase(0, pos + delimiter.length());
            }
            if (s.size() > 3)
            {
                arbolito.Inserta(s);
            }
            else {
                std::cout << "Ingrese una palabra mayor de 3 caracteres..." << endl;
            }
           
            std::cout << endl;
            system("pause");
        }

        else if (data[0] == 'c')
        {
         
            std::cout << "\nTotal de palabras: ";
            std::cout << arbolito.contarNodos(arbolito.getRoot(), cont) << endl;
            arbolito.preorden(arbolito.getRoot());
            std::cout << endl;
            system("pause");
        }
        else {
            arbolito.buscar(data);
        }
    } while (resp != "0");


    //std::cout << "Total de nodos: ";
    //std::cout << arbolito.contarNodos(arbolito.getRoot(), cont) << endl;

    //arbolito.contarNodosIH(arbolito.getRoot(), internos, hojas);
    //std::cout << "Hay: " << hojas << " hojas y " << internos << " Nodos internos." <<endl;


}
