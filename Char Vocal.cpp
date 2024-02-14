#include <iostream>
using namespace std;

int Vocales(char *pc) {
	int contador = 0;
	
	while (*pc != '\0') {
		
		if (*pc == 'a' || *pc == 'e' || *pc == 'i' || *pc == 'o' || *pc == 'u' ||
			*pc == 'A' || *pc == 'E' || *pc == 'I' || *pc == 'O' || *pc == 'U') {
			contador++;
		}
		pc++;
	}
	
	return contador;
}

int main(int argc, char *argv[]){
	char cadena[] = "HOLA MUNDO";
	char *pc = cadena;
	
	// Contar vocales de la funcion
	int numVocales = Vocales(pc);
	
	cout << "El número de vocales: " << numVocales << endl;
	
	return 0;
}
	
