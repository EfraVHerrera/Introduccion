#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Tiempo {
	int hora;
	int minuto;
	int segundo;
};

//FUNCION PARA GENERAR NUMERO ALEATORIO
int numeroAleatorio(int min, int max) {
	return rand() % (max - min + 1) + min;
}

// FUNCION PARA GENERAR HORA ALEATORIA 0-23
int horaRam() {
	return numeroAleatorio(01, 23);
}
//FUNCION PARA GENERAR MINUTOS ALEATORIOS 0-59
int mnRam() {
	return numeroAleatorio(0, 59);
}
//FUNCION PARA GENERAR SEGUNDOS ALEATORIOS 0-59
int msRam() {
	return numeroAleatorio(0, 59);
}


//FUNCION PARA AGREGAR TMA
void agregar(Tiempo vt[], int tamano) {
	for (int i = 0; i < tamano; ++i) {
		vt[i].hora = horaRam();
		vt[i].minuto = mnRam();
		vt[i].segundo = msRam();
	}
}

//FUNCION PARA IMPRIMIR
void imprimir(Tiempo vt[], int tamano) {
	for (int i = 0; i < tamano; ++i) {
		cout << "Hora " << i + 1 << " : " << vt[i].hora << " : " << vt[i].minuto << " : " << vt[i].segundo << endl;
	}
}

int main() {
	const int TMA = 5; //TAMAÑO DE ARRAY
	Tiempo vt[TMA]; // Array de Tiempo
	

	srand(time(nullptr));
	

	agregar(vt, TMA);
	

	imprimir(vt, TMA);
	
	return 0;
}
