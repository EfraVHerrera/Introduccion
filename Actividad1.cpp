#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definición de las estructuras
struct LIBRO {
	string title;
	string author;
	string ISBN;
	int publicationYear;
};

struct USUARIO {
	int userID;
	string name;
	string lastname;
	string email;
};

struct BIBLIOTECARIO {
	int employeeID;
	string name;
	string lastname;
	string email;
};

const int NUM_LIBROS = 7;
const int NUM_USUARIOS = 7;
const int NUM_BIBLIOTECARIOS = 7;

// Funciones para generar datos aleatorios
string getRandomElement(string arr[], int size) {
	return arr[rand() % size];
}

int getRandomYear() {
	return rand() % 50 + 1970; // Años aleatorios entre 1970 y 2019
}

string generateEmail(string name, string lastname) {
	return name + "." + lastname + "@upds.net.bo";
}

// Funciones para generar las estructuras y sus datos
void generarLibros(LIBRO libros[], string listaLibros[], string listaNombres[], string listaApellidos[]) {
	for (int i = 0; i < NUM_LIBROS; ++i) {
		libros[i].title = getRandomElement(listaLibros, NUM_LIBROS);
		libros[i].author = getRandomElement(listaNombres, 5) + " " + getRandomElement(listaApellidos, 5);
		libros[i].ISBN = to_string(i + 1) + ",2,3,4,5"; // ISBN falso
		libros[i].publicationYear = getRandomYear();
	}
}

void generarUsuarios(USUARIO usuarios[], string listaNombres[], string listaApellidos[]) {
	for (int i = 0; i < NUM_USUARIOS; ++i) {
		usuarios[i].userID = i + 1;
		usuarios[i].name = getRandomElement(listaNombres, 5);
		usuarios[i].lastname = getRandomElement(listaApellidos, 5);
		usuarios[i].email = generateEmail(usuarios[i].name, usuarios[i].lastname);
	}
}

void generarBibliotecarios(BIBLIOTECARIO bibliotecarios[], string listaNombres[], string listaApellidos[]) {
	for (int i = 0; i < NUM_BIBLIOTECARIOS; ++i) {
		bibliotecarios[i].employeeID = i + 1;
		bibliotecarios[i].name = getRandomElement(listaNombres, 5);
		bibliotecarios[i].lastname = getRandomElement(listaApellidos, 5);
		bibliotecarios[i].email = generateEmail(bibliotecarios[i].name, bibliotecarios[i].lastname);
	}
}

// Función para imprimir las estructuras
void imprimirLibros(LIBRO libros[]) {
	cout << "Libros:" << endl;
	for (int i = 0; i < NUM_LIBROS; ++i) {
		cout << "Título: " << libros[i].title << ", Autor: " << libros[i].author << ", ISBN: " << libros[i].ISBN << ", Año de Publicación: " << libros[i].publicationYear << endl;
	}
}

void imprimirUsuarios(USUARIO usuarios[]) {
	cout << "\nUsuarios:" << endl;
	for (int i = 0; i < NUM_USUARIOS; ++i) {
		cout << "ID: " << usuarios[i].userID << ", Nombre: " << usuarios[i].name << ", Apellido: " << usuarios[i].lastname << ", Email: " << usuarios[i].email << endl;
	}
}

void imprimirBibliotecarios(BIBLIOTECARIO bibliotecarios[]) {
	cout << "\nBibliotecarios:" << endl;
	for (int i = 0; i < NUM_BIBLIOTECARIOS; ++i) {
		cout << "ID: " << bibliotecarios[i].employeeID << ", Nombre: " << bibliotecarios[i].name << ", Apellido: " << bibliotecarios[i].lastname << ", Email: " << bibliotecarios[i].email << endl;
	}
}

int main() {
	// Semilla para números aleatorios
	srand(time(0));
	
	// Arrays fijos de datos
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux", "Aprende C++", "Aprende Ubunto", "Clean Code", "The Art of Computer Programming", "Programming Pearls", "Introduction to Algorithms"};
	string listaNombres[] = {"Juan", "María", "Pedro", "Ana", "Luis", "Efrain", "Jose", "Carlos", "Cristian"};
	string listaApellidos[] = {"García", "Martínez", "López", "González", "Rodríguez", "Edmundo", "Flores", "Ponce", "Herrera"};
	
	// Generar estructuras
	LIBRO libros[NUM_LIBROS];
	USUARIO usuarios[NUM_USUARIOS];
	BIBLIOTECARIO bibliotecarios[NUM_BIBLIOTECARIOS];
	
	// Generar datos aleatorios utilizando punteros
	generarLibros(libros, listaLibros, listaNombres, listaApellidos);
	generarUsuarios(usuarios, listaNombres, listaApellidos);
	generarBibliotecarios(bibliotecarios, listaNombres, listaApellidos);
	
	// Imprimir datos utilizando punteros
	imprimirLibros(libros);
	imprimirUsuarios(usuarios);
	imprimirBibliotecarios(bibliotecarios);
	
	return 0;
}
