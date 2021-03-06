// Aleatorio simple mejorado.cpp: define el punto de entrada de la aplicaci�n de consola.
//
#include "stdafx.h"
#include<iostream>
#include <time.h>
using namespace std;

//Funcion principal
int main()
{
	cout << "Programa de generacion de numeros aleatorios" << endl;
	//Declarando variables.
	int  n, desde, hasta, tempcantidad, repetir, k, i, j, clave, num;
	cout << endl;
	//Semilla para que los aleatorios no se repitan.
	srand(time(NULL));
	//Pedir tama�o del arreglo.
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
	//La cantidad de elemento entre el rango (desde-hasta) no puede ser menor a n (tama�o del arreglo aleatorio).
	if (tempcantidad < n)
	{
		cout << "El rango " << desde << " al " << hasta << " es de " << tempcantidad << " elementos y no puede ser menor al tama�o del arreglo" << endl;
		system("pause");
		return 0;
	}
	cout << "Cuantas veces desea generar los aleatorios? : ";
	cin >> repetir;
	//Generar aleatorios hasta que el usuario decida salir.
	cout << endl;
	for (k = 0;k < repetir;k++)
	{
		//Crear las variables para el arreglo din�mico.
		int* aleatorio = new int[n];
		//Insertando valores al arrelgo aleatorio.
		for (i = 0; i < n;i++)
		{
			//Generar el aleatorio en la posici�n actual del arreglo.
			num = desde + rand() % ((hasta + 1) - desde);
			aleatorio[i] = num;
			clave = aleatorio[i];
			if (i >= 1)
			{
				//Generar ciclo hasta donde est� la posici�n actual.
				for (j = 0;j < i;j++)
				{
					/*En caso de que encuentre un elemento reperido, cambia dicho valor por
					un elemento aleatorio nuevo*/
					if (aleatorio[j] == clave)
					{
						num = desde + rand() % ((hasta + 1) - desde);
						aleatorio[i] = num;
						i = i-1;
					}
				}
			}
		}
		//Mostrar arreglo aleatorio.
		for (i = 0; i < n;i++)
			cout << aleatorio[i] <<" "<<;
		cout << endl;
		//Liberar memoria del arreglo.
		delete[]aleatorio;
	}
	system("pause");
	return 0;
}

