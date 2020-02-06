// Aleatorio por selección optimizado.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include<iostream>
#include <time.h>
using namespace std;

int main()
{
	cout << "Programa de generacion de numeros aleatorios" << endl;
	//Declarando variables.
	int  n, num, desde, hasta, tempcantidad, suma, repetir, c;
	int i, j, k;
	cout << endl;
	//Semilla para que los aleatorios no se repitan.
	srand(time(NULL));
	//Pedir tamaño del arreglo.
	cout << "Ingrese dimension del arreglo: ";
	cin >> n;
	cout << endl;
	//Asignar rango de los valores aleatorios.
	cout << "Los valores aleatorios van desde: ";
	cin >> desde;
	cout << endl;
	cout << "Los valores aleatorios van hasta: ";
	cin >> hasta;
	cout << endl;
	//El valor desde no puede ser mayor o igual que hasta.
	if (desde >= hasta)
	{
		cout << "El valor desde no puede ser mayor o igual que hasta" << endl;
		system("pause");
		return 0;
	}
	//Calcular cantidad de posiciones en el rango desde-hasta.
	tempcantidad = 1 + (hasta - desde);
	//La cantidad de elemento entre el rango (desde-hasta) no puede ser menor a n (tamaño del arreglo aleatorio).
	if (tempcantidad < n)
	{
		cout << "El rango " << desde << " al " << hasta << " es de " << tempcantidad << " elementos y no puede ser menor al tamaño del arreglo" << endl;
		system("pause");
		return 0;
	}
	cout << "Cuantas veces desea generar los aleatorios? : ";
	cin >> repetir;
	//Generar aleatorios hasta que el usuario decida salir.
	cout << endl;
	for (k = 0;k < repetir;k++)
	{
		//Crear las variables para el arreglo dinámico.
		int* aleatorio = new int[n];
		int* temp = new int[tempcantidad];
		//Insertar valores ordenados (valores desde-hasta) en el arreglo temp.
		suma = desde;
		for (i = 0; i < tempcantidad;i++)
		{
			temp[i] = suma;
			suma = suma + 1;
		}
		//Insertar valores valores en el arreglo aleatorio.
		for (i = 0; i < n; i++)
		{
			c = 0;
			while (c == 0)
			{
				num = 0 + rand() % ((tempcantidad)-0);
				/*inserta numero aleatorio a la posición actual siempre y cuando 
				en el arreglo temp dicha posición no tenga valor cero.*/
				if (temp[num] != 0)
				{
					aleatorio[i] = temp[num];
					temp[num] = 0;
					c = 1;
				}
			}
			
		}

		//Mostrar arreglo aleatorio.
		for (i = 0; i < n;i++)
			cout << "Posicion [" << i << "] = " << aleatorio[i] << endl;
		cout << endl;
		//Liberar memoria del arreglo.
		delete[]aleatorio;
		delete[]temp;
	}
	system("pause");
	return 0;
}


