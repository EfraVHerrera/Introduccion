#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int main() {
	float num1, num2, num3; //Declaramos Variables de tipo float
	
	cout << "Ingresa el primer número: "; //Se utiliza cout para mostrar el mensaje "Ingresa el primer número: "
	cin >> num1; //El cin para leer el valor ingresado por el usuario 
	cout << "Ingresa el segundo número: ";
	cin >> num2;
	cout << "Ingresa el tercer número: ";
	cin >> num3;
	
	float mayor = num1; 
	if (num2 > mayor) { //Se usa el if para comparar num2 con mayor. Si num2 es mayor que mayor, actualizamos el valor de mayor con num2.
		mayor = num2;
	}
	if (num3 > mayor) { //Se repite el paso anterior
		mayor = num3;
	}
	
	cout << "El número mayor es: " << mayor << endl; //Utilizamos cout para imprimir el mensaje "El número mayor es: " seguido del valor de mayor.
	
	return 0;
}

