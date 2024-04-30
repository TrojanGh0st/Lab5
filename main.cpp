#include <iostream> 

#include "Libro.h" 

#include "Biblioteca.h" 

 

using namespace std;  

 

int main() { 

    Libro libro1; 

    Libro libro2; 

 

    cout << "Información de libro1 antes de asignar valores:" << endl; 

    libro1.mostrarInformacion(); 

    cout << endl; 

 

    cout << "Información de libro2 antes de asignar valores:" << endl; 

    libro2.mostrarInformacion(); 

    cout << endl; 

 

     libro1 = Libro("El señor de los anillos", "J.R.R. Tolkien", 1954); 

 

    libro2 = Libro("Cien años de soledad", "Gabriel García Márquez", 1967); 

 

    cout << "Información de libro1 después de asignar valores:" << endl; 

    libro1.mostrarInformacion(); 

    cout << endl; 

 

    cout << "Información de libro2 después de asignar valores:" << endl; 

    libro2.mostrarInformacion(); 

    cout << endl; 

 

    return 0; 

} 
