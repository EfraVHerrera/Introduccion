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
	string idioma;
	int edicion;
	int numPaginas;
};

struct USUARIO {
	int userID;
	string name;
	string lastname;
	string email;
	string fechaRegistro;
};

struct BIBLIOTECARIO {
	int employeeID;
	string name;
	string lastname;
	string email;
	string cargo;
};

const int NUM_LIBROS = 3;
const int NUM_USUARIOS = 3;
const int NUM_BIBLIOTECARIOS = 3;

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

string generateFechaRegistro(string listaFechasRegistro[], int size) {
	return listaFechasRegistro[rand() % size]; // Se elige una fecha de registro aleatoria del array
}

// Funciones para generar las estructuras y sus datos
void generarLibros(LIBRO libros[], string listaLibros[], string listaNombres[], string listaApellidos[], string listaIdiomas[]) {
	for (int i = 0; i < NUM_LIBROS; ++i) {
		libros[i].title = getRandomElement(listaLibros, NUM_LIBROS);
		libros[i].author = getRandomElement(listaNombres, 5) + " " + getRandomElement(listaApellidos, 5);
		libros[i].ISBN = to_string(i + 1) + ",2,3,4,5"; // ISBN falso
		libros[i].publicationYear = getRandomYear();
		libros[i].idioma = getRandomElement(listaIdiomas, 8); // Se elige un idioma aleatorio
		libros[i].edicion = rand() % 10 + 1; // Número de edición aleatorio entre 1 y 10
		libros[i].numPaginas = rand() % 500 + 100; // Número de páginas aleatorio entre 100 y 599
	}
}

void generarUsuarios(USUARIO usuarios[], string listaNombres[], string listaApellidos[], string listaFechasRegistro[], int size) {
	for (int i = 0; i < NUM_USUARIOS; ++i) {
		usuarios[i].userID = i + 1;
		usuarios[i].name = getRandomElement(listaNombres, 5);
		usuarios[i].lastname = getRandomElement(listaApellidos, 5);
		usuarios[i].email = generateEmail(usuarios[i].name, usuarios[i].lastname);
		usuarios[i].fechaRegistro = generateFechaRegistro(listaFechasRegistro, size); //HOY
	}
}

void generarBibliotecarios(BIBLIOTECARIO bibliotecarios[], string listaNombres[], string listaApellidos[], string listaCargos[], int size) {
	for (int i = 0; i < NUM_BIBLIOTECARIOS; ++i) {
		bibliotecarios[i].employeeID = i + 1;
		bibliotecarios[i].name = getRandomElement(listaNombres, 5);
		bibliotecarios[i].lastname = getRandomElement(listaApellidos, 5);
		bibliotecarios[i].email = generateEmail(bibliotecarios[i].name, bibliotecarios[i].lastname);
		bibliotecarios[i].cargo = getRandomElement(listaCargos, size); //HOY
	}
}

// Función para imprimir las estructuras
void imprimirLibros(LIBRO libros[]) {
	cout << "Libros:" << endl;
	for (int i = 0; i < NUM_LIBROS; ++i) {
		cout << "Título: " << libros[i].title << ", Autor: " << libros[i].author << ", ISBN: " << libros[i].ISBN << ", Año de Publicación: " << libros[i].publicationYear << ", Idioma: " << libros[i].idioma << ", Edición: " << libros[i].edicion << ", Número de Páginas: " << libros[i].numPaginas << endl;
	}
}

void imprimirUsuarios(USUARIO usuarios[]) {
	cout << "\nUsuarios:" << endl;
	for (int i = 0; i < NUM_USUARIOS; ++i) {
		cout << "ID: " << usuarios[i].userID << ", Nombre: " << usuarios[i].name << ", Apellido: " << usuarios[i].lastname << ", Email: " << usuarios[i].email << ", Fecha de Registro: " << usuarios[i].fechaRegistro << endl;
	}
}

void imprimirBibliotecarios(BIBLIOTECARIO bibliotecarios[]) {
	cout << "\nBibliotecarios:" << endl;
	for (int i = 0; i < NUM_BIBLIOTECARIOS; ++i) {
		cout << "ID: " << bibliotecarios[i].employeeID << ", Nombre: " << bibliotecarios[i].name << ", Apellido: " << bibliotecarios[i].lastname << ", Email: " << bibliotecarios[i].email << ", Cargo: " << bibliotecarios[i].cargo << endl;
	}
}

int main() {
	// Semilla para números aleatorios
	srand(time(0));
	
	// Arrays fijos de datos
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux", "Aprende C++", "Aprende Ubunto", "Clean Code", "The Art of Computer Programming", "Programming Pearls", "Introduction to Algorithms"};
	string listaNombres[] = {"Juan", "María", "Pedro", "Ana", "Luis", "Efrain", "Jose", "Carlos", "Cristian"};
	string listaApellidos[] = {"García", "Martínez", "López", "González", "Rodríguez", "Edmundo", "Flores", "Ponce", "Herrera"};
	string listaIdiomas[] = {"Español", "Inglés", "Francés", "Alemán", "Italiano", "Portugués", "Japonés", "Chino"};
	string listaFechasRegistro[] = {"01/01/2020", "15/03/2021", "30/06/2022", "26/06/2019"};
	string listaCargos[] = {"Bibliotecario jefe", "Bibliotecario Asistente", "Bibliotecario Junior", "Bibliotecario de tecnología de la información", "Bibliotecario de archivos y preservación:"};
	
	// Generar estructuras
	LIBRO libros[NUM_LIBROS];
	USUARIO usuarios[NUM_USUARIOS];
	BIBLIOTECARIO bibliotecarios[NUM_BIBLIOTECARIOS];
	
	// Generar datos aleatorios utilizando punteros
	generarLibros(libros, listaLibros, listaNombres, listaApellidos, listaIdiomas);
	generarUsuarios(usuarios, listaNombres, listaApellidos, listaFechasRegistro, sizeof(listaFechasRegistro)/sizeof(listaFechasRegistro[0]));
	generarBibliotecarios(bibliotecarios, listaNombres, listaApellidos, listaCargos, sizeof(listaCargos)/sizeof(listaCargos[0]));
	
	
	// Imprimir datos utilizando punteros
	imprimirLibros(libros);
	imprimirUsuarios(usuarios);
	imprimirBibliotecarios(bibliotecarios);
	
	return 0;
}
