#include <iostream>
using namespace std;

struct strTiempo{
	int hora;
	int minuto;
	int segundo;
};

struct strFecha{
	int anio;
	int mes;
	int dia;
};

void funcion(int n){
	cout << "Funcion INTEGER" << endl;
}
	
void funcion(int n, int m){
	cout << "Funcion 2 PARAMETROS" << endl;
}
		
void funcion(double n){
	cout << "Funcion DOUBLE" << endl;
}


void funcion(char c){
	cout << "Funcion Char" << endl;
}


void funcion(){
	cout << "Hola Cristian Edmundo" << endl;
}

void funcion(strTiempo tt){
	cout << "La hora es " << tt.hora << " : " << tt.minuto << " : " << tt.segundo << endl;
}

void funcion(strFecha tt){
	cout << "La fecha es " << tt.anio << " / " << tt.mes << " / " << tt.dia << endl;
}


int main(int argc, char *argv[]) {
	funcion();
	funcion(15);
	funcion(11.5);
	funcion('h');
	funcion(11, 5);
	strFecha f;
	t.hora = 10; t.minuto = 35; t.segundo = 0;
	f.anio = 2024; f.mes = 2; f.dia = 19;
	funcion(t);
	funcion(f);
return 0;
}

