#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int TAMJ = 3;
const int NUM_PERSONAS = 3;
const int NUM_JUEGOS = 3;

struct vjuegos {
	string nombre;
	int ranking; // 1 al 10
	bool tipo; // OFFLINE Y ONLINE;
	string des; // Descripción del juego
};

struct persona {
	string nombre;
	int id_persona;
	vjuegos juegos[TAMJ];
	unordered_set<string> juegosImpresos; // Conjunto para rastrear juegos impresos por esta persona
};

// Funciones para generar nombres aleatorios
string generarNombrePersona();
string generarNombreJuego();
string generarDescripcionJuego(); // Nueva función para generar descripciones de juegos

void llenarPersona(persona &p);
void llenarJuegos(vjuegos &j);
void imprimirPersona(persona p, unordered_set<string> &nombresImpresos);
void imprimirJuegos(vjuegos j, unordered_set<string> &juegosImpresos);
void rankingPorPersona(persona p);

int main() {
	srand(time(nullptr));
	
	persona personas[NUM_PERSONAS]; // Crear un arreglo de personas
	
	for (int i = 0; i < NUM_PERSONAS; i++) {
		llenarPersona(personas[i]); // Llenar datos de cada persona
	}
	
	unordered_set<string> nombresImpresos;
	
	int opcion;
	do {
		cout << "------ MENU ------" << endl;
		cout << "1) LLENADO DE PERSONA" << endl;
		cout << "2) IMPRESION DE PERSONAS" << endl;
		cout << "3) RANKING DE JUEGO POR PERSONA" << endl;
		cout << "0) SALIR" << endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			for (int i = 0; i < NUM_PERSONAS; i++) {
				llenarPersona(personas[i]);
			}
			break;
		case 2:
			for (int i = 0; i < NUM_PERSONAS; i++) {
				imprimirPersona(personas[i], nombresImpresos);
			}
			break;
		case 3:
			for (int i = 0; i < NUM_PERSONAS; i++) {
				rankingPorPersona(personas[i]);
			}
			break;
		case 0:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
			break;
		}
	} while (opcion != 0);
	
	return 0;
}

string generarNombrePersona() {
	string nombres[] = {"Juan Perez", "Maria Flor", "Noah Ramirez", "Cristian Edmundo", "Efra Herrera", "Thiago", "Santy", "Gerson", "Jose Carlos", "Justin Davis"};
	static int indice = 0;
	random_shuffle(nombres, nombres + 10);
	return nombres[indice++ % 10];
}

string generarNombreJuego() {
	string vjuegos[] = {"Valorant", "Call of Duty: Warzone 2.0", "CSGO", "Counter-Strike: Global Offensive", "League of Legends", "Lost Ark", "Apex Legends", "Final Fantasy XIV", "Fortnite", "Rocket League"};
	static int indice = 0;
	random_shuffle(vjuegos, vjuegos + 10);
	return vjuegos[indice++ % 10];
}

string generarDescripcionJuego() {
	string descripciones[] = {
			"Un juego de disparos táctico en primera persona.",
			"Un juego de disparos en equipo con modos de juego variados.",
			"Un juego de disparos competitivo con una amplia comunidad.",
			"Un juego de estrategia en tiempo real con elementos de MOBA.",
			"Un MMORPG épico con una enorme variedad de personajes y habilidades.",
			"Un juego de rol de acción con un mundo abierto y libertad de exploración.",
			"Un battle royale con personajes únicos y habilidades especiales.",
			"Un juego de rol en línea con una historia envolvente y una gran cantidad de contenido.",
			"Un juego de construcción y supervivencia en un mundo post-apocalíptico.",
			"Un juego de fútbol donde los jugadores controlan coches con el objetivo de marcar goles."
	};
	static int indice = 0;
	random_shuffle(descripciones, descripciones + 10);
	return descripciones[indice++ % 10];
}

void llenarPersona(persona &p) {
	p.nombre = generarNombrePersona();
	p.id_persona = rand() % 1000; // Generar un ID aleatorio para la persona
	for (int i = 0; i < TAMJ; i++) {
		llenarJuegos(p.juegos[i]); // Llenar datos de los juegos de la persona
	}
}

void llenarJuegos(vjuegos &j) {
	j.nombre = generarNombreJuego();
	j.ranking = rand() % 10 + 1; // Generar un ranking aleatorio entre 1 y 10
	j.tipo = rand() % 2; // Generar un tipo aleatorio (0 para OFFLINE, 1 para ONLINE)
	j.des = generarDescripcionJuego(); // Generar una descripción para el juego
}

void imprimirPersona(persona p, unordered_set<string> &nombresImpresos) {
	if (nombresImpresos.find(p.nombre) != nombresImpresos.end()) {
		return; // Si el nombre ya se ha impreso, salimos de la función
	}
	
	cout << "Nombre: " << p.nombre << endl;
	cout << "ID: " << p.id_persona << endl;
	cout << "Juegos:" << endl;
	for (int i = 0; i < TAMJ; i++) {
		imprimirJuegos(p.juegos[i], p.juegosImpresos); // Imprimir datos de los juegos de la persona
	}
	cout << endl;
	
	nombresImpresos.insert(p.nombre); // Agregar el nombre a los nombres impresos
}

void imprimirJuegos(vjuegos j, unordered_set<string> &juegosImpresos) {
	if (juegosImpresos.find(j.nombre) != juegosImpresos.end()) {
		return;
	}
	
	cout << "  Nombre del juego: " << j.nombre << endl;
	cout << "  Ranking: " << j.ranking << "/10" << endl;
	cout << "  Tipo: " << (j.tipo ? "ONLINE" : "OFFLINE") << endl;
	cout << "  Descripción: " << j.des << endl; // Imprimir la descripción del juego
	
	juegosImpresos.insert(j.nombre); // Agregar el juego a los juegos impresos
}

void rankingPorPersona(persona p) {
	cout << "Nombre: " << p.nombre << endl;
	cout << "Ranking de juegos:" << endl;
	for (int i = 0; i < TAMJ; i++) {
		cout << "  " << p.juegos[i].nombre << ": " << p.juegos[i].ranking << "/10" << endl;
	}
	cout << endl;
}
