#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//DEFINICION DE ESTRUTURA
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

//FUNCION ALEATORIA
string getRandomElement(string arr[], int size) {
	return arr[rand() % size];
}

int getRandomYear() {
	return rand() % 50 + 1970; //AÑOS ALEATORIOS 1970 y 2019
}

string generateEmail(string name, string lastname) {
	return name + "." + lastname + "@upds.net.bo";
}

int main() {
	//SEMILLA PARA NUMERO ALEATORIOS
	srand(time(0));
	
	//ARRAYS FIJOS DE DATOS
	string listaLibros[] = {"Aprende C++", "Aprende PHP", "Aprende Linux"};
	int numLibros = sizeof(listaLibros) / sizeof(listaLibros[0]);
	
	string listaNombres[] = {"Efra", "Mario", "Ezequiel", "Tania", "Luis"};
	string listaApellidos[] = {"Herrera", "Marce", "Ortiz", "Vaca", "Menacho"};
	
	//GENERA ESTRUCTURAS Y ASIGNA DATOS ALEATORIOS
	LIBRO libros[3];
	for (int i = 0; i < 3; ++i) {
		libros[i].title = getRandomElement(listaLibros, numLibros);
		libros[i].author = getRandomElement(listaNombres, 5) + " " + getRandomElement(listaApellidos, 5);
		libros[i].ISBN = to_string(i + 1) + ",2,3,4,5"; // ISBN falso
		libros[i].publicationYear = getRandomYear();
	}
	
	USUARIO usuarios[3];
	for (int i = 0; i < 3; ++i) {
		usuarios[i].userID = i + 1;
		usuarios[i].name = getRandomElement(listaNombres, 5);
		usuarios[i].lastname = getRandomElement(listaApellidos, 5);
		usuarios[i].email = generateEmail(usuarios[i].name, usuarios[i].lastname);
	}
	
	BIBLIOTECARIO bibliotecarios[3];
	for (int i = 0; i < 3; ++i) {
		bibliotecarios[i].employeeID = i + 1;
		bibliotecarios[i].name = getRandomElement(listaNombres, 5);
		bibliotecarios[i].lastname = getRandomElement(listaApellidos, 5);
		bibliotecarios[i].email = generateEmail(bibliotecarios[i].name, bibliotecarios[i].lastname);
	}
	
	//UTILIZANDO PUNTEROS PARA PASAR LOS ARRAYS DE LAS ESTRUCCTURAS
	LIBRO *librosPtr = libros;
	USUARIO *usuariosPtr = usuarios;
	BIBLIOTECARIO *bibliotecariosPtr = bibliotecarios;
	
	//MUESTRA LOS DATOS GENERADOS
	cout << "Libros:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Título: " << librosPtr[i].title << ", Autor: " << librosPtr[i].author << ", ISBN: " << librosPtr[i].ISBN << ", Año de Publicación: " << librosPtr[i].publicationYear << endl;
	}
	
	cout << "\nUsuarios:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "ID: " << usuariosPtr[i].userID << ", Nombre: " << usuariosPtr[i].name << ", Apellido: " << usuariosPtr[i].lastname << ", Email: " << usuariosPtr[i].email << endl;
	}
	
	cout << "\nBibliotecarios:" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "ID: " << bibliotecariosPtr[i].employeeID << ", Nombre: " << bibliotecariosPtr[i].name << ", Apellido: " << bibliotecariosPtr[i].lastname << ", Email: " << bibliotecariosPtr[i].email << endl;
	}
	
	return 0;
}

