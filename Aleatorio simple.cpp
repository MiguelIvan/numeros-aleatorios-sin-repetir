// Aleatorio simple.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include<iostream>
#include <time.h>
using namespace std;

//Funcion para general aleatorio.
int Genera_aleatorio(int n, int desde, int hasta, int aleatorio[])
{
	int num = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		//Generar el aleatorio en la posición actual del arreglo.
		num = desde + rand() % ((hasta + 1) - desde);
		aleatorio[i] = num;
	}
	return(n, desde, hasta, aleatorio[n]);
}
//Funcion principal
int main()
{
	cout << "Programa de generacion de numeros aleatorios" << endl;
	//Declarando variables.
	int  n, desde, hasta, tempcantidad, repetir, k, i, j, clave;
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
		//Insertar valores en el arreglo aleatorio.
		Genera_aleatorio(n, desde, hasta, aleatorio);
		//Buscando elementos repetidos.
		for (i = 0; i < n;i++)
		{
			/* Cuando la posición actual sea mayor o igual a 1 busca si ese valor se 
			encuentra anteriormente, en caso de que asi sea genera otro arreglo aleatorio
			hasta que genere un arreglo sin repeticiones*/
			clave = aleatorio[i];
			if (i >= 1)
			{
				//Generar ciclo hasta donde esté la posición actual.
				for (j = 0;j < i;j++)
				{
					if (aleatorio[j] == clave)
					{
						Genera_aleatorio(n, desde, hasta, aleatorio);
						i = 0;
					}
				}
			}
		}
		//Mostrar arreglo aleatorio.
		for (i = 0; i < n;i++)
			cout << "Posicion [" << i << "] = " << aleatorio[i] << endl;
		cout << endl;
		//Liberar memoria del arreglo.
		delete[]aleatorio;
	}
	system("pause");
	return 0;
}



