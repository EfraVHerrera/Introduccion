#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
	float num1, num2, num3; //Declaramos Variables de tipo float
	
	cout << "Ingresa el primer n�mero: "; //Se utiliza cout para mostrar el mensaje "Ingresa el primer n�mero: "
	cin >> num1; //El cin para leer el valor ingresado por el usuario 
	cout << "Ingresa el segundo n�mero: ";
	cin >> num2;
	cout << "Ingresa el tercer n�mero: ";
	cin >> num3;
	
	float mayor = num1; 
	if (num2 > mayor) { //Se usa el if para comparar num2 con mayor. Si num2 es mayor que mayor, actualizamos el valor de mayor con num2.
		mayor = num2;
	}
	if (num3 > mayor) { //Se repite el paso anterior
		mayor = num3;
	}
	
	cout << "El n�mero mayor es: " << mayor << endl; //Utilizamos cout para imprimir el mensaje "El n�mero mayor es: " seguido del valor de mayor.
	
	return 0;
}

