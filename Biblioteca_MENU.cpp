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
    int opcion;
    vector<Libro*> libros;

    do {
        cout << "Menu de Opciones" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Ver detalles de libros" << endl;
        cout << "3. Buscar libro por autor" << endl;
        cout << "4. Buscar libro por año de publicacion" << endl;
        cout << "5. Modificar detalles de libro" << endl;
        cout << "6. Eliminar libro" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string titulo, autor;
                int anioPublicacion;
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese el nombre del autor: ";
                getline(cin, autor);
                cout << "Ingrese el año de publicacion: ";
                cin >> anioPublicacion;
                Libro* nuevoLibro = new Libro(titulo, autor, anioPublicacion); // Constructor: Creación de un nuevo objeto Libro
                libros.push_back(nuevoLibro); // Autorreferencia: Agregar el libro recién creado al vector de libros
                break;
            }
            case 2: {
                cout << "Detalles de los libros:" << endl;
                for (auto& libro : libros) {
                    libro->mostrarDetalles(); // Miembro de Clase: Llamada a la función mostrarDetalles() de cada objeto Libro
                    cout << endl;
                }
                break;
            }
            case 3: {
                string autor;
                cout << "Ingrese el nombre del autor a buscar: ";
                cin.ignore();
                getline(cin, autor);
                cout << "Libros del autor " << autor << ":" << endl;
                for (auto& libro : libros) {
                    if (libro->getAutor() == autor) { // Miembro de Clase: Acceso al autor del libro para comparar
                        libro->mostrarDetalles(); // Miembro de Clase: Llamada a la función mostrarDetalles() de cada objeto Libro
                        cout << endl;
                    }
                }
                break;
            }
            case 4: {
                int anio;
                cout << "Ingrese el año de publicacion a buscar: ";
                cin >> anio;
                cout << "Libros publicados en " << anio << ":" << endl;
                for (auto& libro : libros) {
                    if (libro->getAnioPublicacion() == anio) { // Miembro de Clase: Acceso al año de publicación del libro para comparar
                        libro->mostrarDetalles(); // Miembro de Clase: Llamada a la función mostrarDetalles() de cada objeto Libro
                        cout << endl;
                    }
                }
                break;
            }
            case 5: {
                int indice;
                cout << "Ingrese el indice del libro que desea modificar: ";
                cin >> indice;
                if (indice >= 1 && indice <= libros.size()) {
                    string titulo, autor;
                    int anioPublicacion;
                    cout << "Ingrese el nuevo titulo del libro: ";
                    cin.ignore();
                    getline(cin, titulo);
                    cout << "Ingrese el nuevo nombre del autor: ";
                    getline(cin, autor);
                    cout << "Ingrese el nuevo año de publicacion: ";
                    cin >> anioPublicacion;
                    libros[indice - 1]->setTitulo(titulo); // Miembro de Clase: Llamada a la función setTitulo() de un objeto Libro
                    libros[indice - 1]->setAutor(autor); // Miembro de Clase: Llamada a la función setAutor() de un objeto Libro
                    libros[indice - 1]->setAnioPublicacion(anioPublicacion); // Miembro de Clase: Llamada a la función setAnioPublicacion() de un objeto Libro
                    cout << "Detalles del libro modificado:" << endl;
                    libros[indice - 1]->mostrarDetalles(); // Miembro de Clase: Llamada a la función mostrarDetalles() de un objeto Libro
                } else {
                    cout << "Indice invalido." << endl;
                }
                break;
            }
            case 6: {
                if (libros.empty()) {
                    cout << "No hay libros para eliminar." << endl;
                } else {
                    int indice;
                    cout << "Ingrese el indice del libro que desea eliminar: ";
                    cin >> indice;
                    if (indice >= 1 && indice <= libros.size()) {
                        delete libros[indice - 1]; // Destructor: Liberar memoria del libro eliminado
                        libros.erase(libros.begin() + indice - 1); // Eliminar el libro del vector
                        cout << "Libro eliminado exitosamente." << endl;
                    } else {
                        cout << "Indice invalido." << endl;
                    }
                }
                break;
            }
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != 7);

    // Liberar memoria de los libros creados dinámicamente
    for (auto& libro : libros) {
        delete libro; // Destructor: Liberar memoria de cada objeto Libro creado dinámicamente
    }

    return 0;
}
