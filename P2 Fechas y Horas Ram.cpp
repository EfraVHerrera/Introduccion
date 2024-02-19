#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


struct strTiempo {
	int hora;
	int minuto;
	int segundo;
};

struct strFecha {
	int anio;
	int mes;
	int dia;
};

//FUNCION PARA GENERAR NUMERO ALEATORIOS
int randomica(int max) {
	return rand() % max;
}

//FUNCION PARA LLENAR LOS ARRAYS DE TIEMPO CON VALORES ALEATORIOS
void llenado(strTiempo t[], int cant) {
	for (int i = 0; i < cant; ++i) {
		t[i].hora = randomica(24);
		t[i].minuto = randomica(60); 
		t[i].segundo = randomica(60);
	}
}

//FUNCION PARA LLENAR LOS ARRAY DE FECHA Y TIEMPO CON DATOS ALEATORIOS
void llenado(strFecha f[], int cant) {
	for (int i = 0; i < cant; ++i) {
		f[i].anio = 2000 + randomica(24);
		f[i].mes = randomica(12) + 1;    
		f[i].dia = randomica(31) + 1;    
	}
}

//FUNCION PARA IMPRIMIR EL TIEMPO
void imprimir(strTiempo t[], int cant) {
	for (int i = 0; i < cant; ++i) {
		cout << "Hora: " << t[i].hora << ", Minuto: " << t[i].minuto << ", Segundo: " << t[i].segundo << endl;
	}
}

//FUNCION PARA IMPRIMIR LA FECHA
void imprimir(strFecha f[], int cant) {
	for (int i = 0; i < cant; ++i) {
		cout << "Dia: " << f[i].dia << ", Mes: " << f[i].mes << ", Año: " << f[i].anio << endl;
	}
}

int main(int argc, char *argv[]) {
	const int TAM = 5;
	strTiempo t[TAM];
	strFecha f[TAM];
	
	srand(time(nullptr));
	
	//LLENA LOS ARRAY ALEATORIAMENTE DE FECHA Y TIEMPO
	llenado(t, TAM);
	llenado(f, TAM);
	
	//IMPRIME EL TIEMPO
	cout << "Datos de Tiempo:" << endl;
	imprimir(t, TAM);
	
	//IMPRIME FECHA
	cout << "\nDatos de Fecha:" << endl;
	imprimir(f, TAM);
	
	return 0;
}
