#ifndef LIBRO_H 

#define LIBRO_H 

 

#include <string> 

#include <iostream> 

 

using namespace std;  

 

class Libro { 

private: 

    string titulo; 

    string autor; 

    int anioPublicacion; 

 

public: 

    Libro() : titulo("Sin título"), autor("Desconocido"), anioPublicacion(0) { 

        cout << "Se ha creado un nuevo libro." << endl; 

    } 

 

    Libro(string _titulo, string _autor, int _anioPublicacion)  

        : titulo(_titulo), autor(_autor), anioPublicacion(_anioPublicacion) { 

        cout << "Se ha creado un nuevo libro: " << titulo << endl; 

    } 

 

    ~Libro() { 

        cout << "El libro '" << titulo << "' ha sido destruido." << endl; 

    } 

 

    void mostrarInformacion() { 

        cout << "Título: " << titulo << endl; 

        cout << "Autor: " << autor << endl; 

        cout << "Año de publicación: " << anioPublicacion << endl; 

    } 

}; 

 

#endif 
