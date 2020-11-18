
#include <iostream>
#include<sstream>
#include "NodoArbol.h"
#include "Abb.h"
#include <fstream> //Lee datos de un .txt
#include <string>
#include <algorithm>
//#include <bits/stdc++.h> 
#include <vector>
#include <string.h>

//Concordance function
bool countOccurences(string palabra, string word)
{
    stringstream s(palabra);

    // To temporarily store each individual word 
    string temp;

    while (s >> temp) {

        // Comparing the current word 
        // with the word to be searched 
        if (temp.compare(word) == 0) {
            return true;
        }
    }
    return false;
}
int main()
{
    int cont = 0;
    int hojas = 0;
    int internos = 0;
    Abb arbolito;
    string resp = "hola muchos gusto";
    vector<string> renglones;
    vector <int> numLineas;
    string filename = "dofi.dat";
    fstream newfile; //Creo un objeto de la clase fstream para leer .txt
    fstream file;
    newfile.open(filename, ios::in); //open a file to perform read operation using file object
    string oneWord;
    
    // opening file 
    file.open(filename.c_str());
    int contLineas = 0;
    // extracting words from the file 
    while (file >> oneWord)
    {
        if (oneWord.size() >= 3) {
            std::for_each(oneWord.begin(), oneWord.end(), [](char& c) {
                c = ::tolower(c);
                });
            oneWord.erase(std::remove_if(oneWord.begin(),
                oneWord.end(),
                [](char c)
                { return c == ',' || c == '.' || c == ':' || c == ';' || c == '!'; })); //Excluyo cualquier signo diferente al abecedario
            oneWord.end();
            arbolito.Inserta(oneWord);
        }
    }

    if (newfile.is_open()) {   //checking whether the file is open
        string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            //arbolito.Inserta(tp);
            std::cout << tp << "\n"; //print the data of the string
            std::for_each(tp.begin(), tp.end(), [](char& c) {
                c = ::tolower(c);
                });
            tp.erase(std::remove_if(tp.begin(),
                tp.end(),
                [](char c)
                { return c == ',' || c == '.' || c == ':' || c == ';' || c == '!'; })); //Excluyo cualquier signo diferente al abecedario
            tp.end();
            renglones.push_back(tp); //Guardo linea por linea
        }
      
        newfile.close(); //close the file object.
    }
    cout << "renglones\n";
    for (int i = 0; i < renglones.size(); i++)
    {
        cout << renglones[i] << " ";
    }
    do {
        std::cout << " \n\n Ingrese la palabra para buscarla. \n Ingrese D + palabra para borrarla.\n ingrese I + palabra para Insertarla.\n C para regresar todas las palabras." << endl;
        getline(cin, resp);
        std::string data = resp;
        // convert string to back to lower case
        std::for_each(data.begin(), data.end(), [](char& c) {
            c = ::tolower(c);
            });

        if (data[0] == 'd' && data[1] == ' ') {
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

        else if (data[0] == 'i' && data.size() == 1) {
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

        else if (data[0] == 'c' && data.size()==1)
        {

            std::cout << "\nTotal de palabras: ";
            std::cout << arbolito.contarNodos(arbolito.getRoot(), cont) << endl;
            arbolito.preorden(arbolito.getRoot());
            std::cout << endl;
            system("pause");
        }
        else {
            if (arbolito.buscar(data)) {
                numLineas.clear();
                int numLinea = 0;
                for (int i = 0; i < renglones.size(); i++)
                {
                    numLinea++;
                    if (countOccurences(renglones[i], data)) {
                        numLineas.push_back(numLinea);
                    }
                }
                for (int i = 0; i < numLineas.size(); i++)
                {
                    cout << numLineas[i] <<" ";
                }
            }
        }
    } while (resp != "0");


}
