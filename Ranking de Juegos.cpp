#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random> // Incluir la cabecera para std::mt19937
using namespace std;

const int TAMJ = 3;
const int NUM_PERSONAS = 3;
const int NUM_JUEGOS = 3;

struct vjuegos {
	string nombre;
	int ranking; // 1 al 10
	bool tipo; // OFFLINE Y ONLINE;
	string des; // DESCRIPCION
};

struct persona {
	string nombre;
	int id_persona;
	vjuegos juegos[TAMJ];
};

string generarNombrePersona();
string generarNombreJuego();
string generarDescripcionJuego();

void llenarPersona(persona &p, int cant, persona *pArray);
void llenarJuegos(vjuegos &j);
void imprimirPersona(persona p, int cant, persona *pArray);
void imprimirJuegos(vjuegos j, bool repetido[], int cant);
void rankingPorPersona(persona p);

int main() {
	srand(time(nullptr));
	
	persona personas[NUM_PERSONAS]; // CREAR ARREGLO DE PERSONA
	
	for (int i = 0; i < NUM_PERSONAS; i++) {
		llenarPersona(personas[i], i, personas); // LLENAR DATO DE CADA PERSONA
	}
	
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
				llenarPersona(personas[i], i, personas); // LLENAR DATO DE CADA PERSONA
			}
			break;
		case 2:
			for (int i = 0; i < NUM_PERSONAS; i++) {
				imprimirPersona(personas[i], i, personas); // IMPRIMIR DATOS DE CADA PERSONA
			}
			break;
		case 3:
			for (int i = 0; i < NUM_PERSONAS; i++) {
				rankingPorPersona(personas[i]); // MOSTRAR RANKING DE JUEGOS POR PERSONA
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
	shuffle(nombres, nombres + 10, mt19937(rand())); // Utilizar std::mt19937
	return nombres[indice++ % 10];
}

string generarNombreJuego() {
	string vjuegos[] = {"Valorant", "Call of Duty: Warzone 2.0", "CSGO", "Counter-Strike: Global Offensive", "League of Legends", "Lost Ark", "Apex Legends", "Final Fantasy XIV", "Fortnite", "Rocket League"};
	static int indice = 0;
	shuffle(vjuegos, vjuegos + 10, mt19937(rand())); // Utilizar std::mt19937
	return vjuegos[indice++ % 10];
}

string generarDescripcionJuego() {
	string descripciones[] = {
		"Un juego En primera persona.",
			"Un juego en equipo.",
			"Competitivo con una amplia comunidad.",
			"Estrategia en tiempo real.",
			"Variedad de personajes y habilidades.",
			"Rol de acción con un mundo abierto.",
			"Un battle royale.",
			"En línea con una historia envolvente.",
			"Un juego de construcción y supervivencia.",
			"Fútbol donde los jugadores controlan coches."
	};
	static int indice = 0;
	shuffle(descripciones, descripciones + 10, mt19937(rand())); // Utilizar std::mt19937
	return descripciones[indice++ % 10];
}

void llenarPersona(persona &p, int cant, persona *pArray) {
	string nombre;
	bool repetido;
	do {
		repetido = false;
		nombre = generarNombrePersona();
		for (int i = 0; i < cant; ++i) {
			if (nombre == pArray[i].nombre) {
				repetido = true;
				break;
			}
		}
	} while (repetido); // REPETIR HASTA QUE SE GENERA UN NOMBRE ÚNICO
	p.nombre = nombre;
	
	p.id_persona = rand() % 1000; // GENERAR UN ID ALEATORIO PARA LA PERSONA
	for (int i = 0; i < TAMJ; i++) {
		llenarJuegos(p.juegos[i]); // LLENAR DATOS DE LOS JUEGOS DE LA PERSONA
	}
}

void llenarJuegos(vjuegos &j) {
	j.nombre = generarNombreJuego();
	j.ranking = rand() % 10 + 1; // GENERAR UN RANKING ALEATORIO ENTRE 1 Y 10
	j.tipo = rand() % 2; // GENERAR UN TIPO ALEATORIO (0 PARA OFFLINE, 1 PARA ONLINE)
	j.des = generarDescripcionJuego(); // GENERAR UNA DESCRIPCIÓN PARA EL JUEGO
}

void imprimirPersona(persona p, int cant, persona *pArray) {
	bool repetido[NUM_JUEGOS] = {false};
	
	cout << "Nombre: " << p.nombre << endl;
	cout << "ID: " << p.id_persona << endl;
	cout << "Juegos:" << endl;
	for (int i = 0; i < TAMJ; i++) {
		imprimirJuegos(p.juegos[i], repetido, cant); // IMPRIMIR DATOS DE LOS JUEGOS DE LA PERSONA
	}
	cout << endl;
}

void imprimirJuegos(vjuegos j, bool repetido[], int cant) {
	cout << "  Nombre del juego: " << j.nombre << endl;
	cout << "  Ranking: " << j.ranking << "/10" << endl;
	cout << "  Tipo: " << (j.tipo ? "ONLINE" : "OFFLINE") << endl;
	cout << "  Descripción: " << j.des << endl; // IMPRIMIR LA DESCRIPCIÓN DEL JUEGO
	
	// Marcar el juego actual como repetido para evitar su impresión en futuras iteraciones
	for (int i = 0; i < cant; ++i) {
		if (!repetido[i]) {
			repetido[i] = true;
			break; // Salir del bucle una vez que se ha marcado el juego como repetido
		}
	}
}

void rankingPorPersona(persona p) {
	cout << "Nombre: " << p.nombre << endl;
	cout << "El Ranking es :" << endl;
	
	int maxRanking = 0;
	string juegoMejorRanking;
	
	for (int i = 0; i < TAMJ; i++) {
		if (p.juegos[i].ranking > maxRanking) {
			maxRanking = p.juegos[i].ranking;
			juegoMejorRanking = p.juegos[i].nombre;
		}
	}
	
	if (maxRanking > 0) {
		cout << "  " << juegoMejorRanking << ": " << maxRanking << "/10" << endl;
	} else {
		cout << "  Esta persona no tiene juegos registrados." << endl;
	}
	
	cout << endl;
}

