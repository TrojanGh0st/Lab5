#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anioPublicacion;

public:
    // Constructor de 03 parámetros
    Libro(string titulo, string autor, int anioPublicacion) {
        this->titulo = titulo; // Constructor: Inicializa el título del libro
        this->autor = autor; // Constructor: Inicializa el autor del libro
        this->anioPublicacion = anioPublicacion; // Constructor: Inicializa el año de publicación del libro
    }

    // Destructor
    ~Libro() {} // Destructor: No realiza ninguna operación en este caso

    // Getters y Setters
    string getTitulo() const { return titulo; } // Miembro de Clase: Función para obtener el título del libro
    void setTitulo(string titulo) { this->titulo = titulo; } // Miembro de Clase: Función para establecer el título del libro

    string getAutor() const { return autor; } // Miembro de Clase: Función para obtener el autor del libro
    void setAutor(string autor) { this->autor = autor; } // Miembro de Clase: Función para establecer el autor del libro

    int getAnioPublicacion() const { return anioPublicacion; } // Miembro de Clase: Función para obtener el año de publicación del libro
    void setAnioPublicacion(int anioPublicacion) { this->anioPublicacion = anioPublicacion; } // Miembro de Clase: Función para establecer el año de publicación del libro

    void mostrarDetalles() const {
        cout << "Titulo: " << titulo << endl; // Miembro de Clase: Acceso al título del libro
        cout << "Autor: " << autor << endl; // Miembro de Clase: Acceso al autor del libro
        cout << "Año de publicacion: " << anioPublicacion << endl; // Miembro de Clase: Acceso al año de publicación del libro
    }
};

int main() {
    vector<Libro*> libros;

    // Agregar libros manualmente
    Libro* libro1 = new Libro("Don Quijote de la Mancha", "Miguel de Cervantes", 1605);
    Libro* libro2 = new Libro("Cien años de soledad", "Gabriel García Márquez", 1967);
    Libro* libro3 = new Libro("El principito", "Antoine de Saint-Exupéry", 1943);

    libros.push_back(libro1);
    libros.push_back(libro2);
    libros.push_back(libro3);

    // Mostrar detalles de los libros
    cout << "Detalles de los libros:" << endl;
    for (auto& libro : libros) {
        libro->mostrarDetalles(); // Miembro de Clase: Llamada a la función mostrarDetalles() de cada objeto Libro
        cout << endl;
    }

    // Buscar libros por autor
    string autorBusqueda = "Gabriel García Márquez";
    cout << "Libros del autor " << autorBusqueda << ":" << endl;
    for (auto& libro : libros) {
        if (libro->getAutor() == autorBusqueda) { // Miembro de Clase: Acceso al autor del libro para comparar
            libro->mostrarDetalles(); // Miembro de Clase: Llamada a la función mostrarDetalles() de cada objeto Libro
            cout << endl;
        }
    }

    // Buscar libros por año de publicación
    int anioBusqueda = 1943;
    cout << "Libros publicados en " << anioBusqueda << ":" << endl;
    for (auto& libro : libros) {
        if (libro->getAnioPublicacion() == anioBusqueda) { // Miembro de Clase: Acceso al año de publicación del libro para comparar
            libro->mostrarDetalles(); // Miembro de Clase: Llamada a la función mostrarDetalles() de cada objeto Libro
            cout << endl;
        }
    }

    // Modificar detalles de libro
    cout << "Modificando detalles del libro 1:" << endl;
    libros[0]->setTitulo("Nuevo Título");
    libros[0]->setAutor("Nuevo Autor");
    libros[0]->setAnioPublicacion(2000);
    libros[0]->mostrarDetalles(); // Miembro de Clase: Llamada a la función mostrarDetalles() de un objeto Libro

    // Eliminar libro
    cout << "Eliminando libro 2:" << endl;
    delete libros[1]; // Destructor: Liberar memoria del libro eliminado
    libros.erase(libros.begin() + 1); // Eliminar el libro del vector

    // Liberar memoria de los libros creados dinámicamente
    for (auto& libro : libros) {
        delete libro; // Destructor: Liberar memoria de cada objeto Libro creado dinámicamente
    }

    return 0;
}
