#ifndef BIBLIOTECA_H 

#define BIBLIOTECA_H 

 

#include <vector>  

#include "Libro.h" 

 

class Biblioteca { 

private: 

    std::vector<Libro> libros; 


public: 

    Biblioteca(); // Constructor 

    ~Biblioteca(); // Destructor 

    void agregarLibro(Libro libro); 

};
