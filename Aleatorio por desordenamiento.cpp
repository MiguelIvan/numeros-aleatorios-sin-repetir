// Aleatorio por desordenamiento.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include<iostream>
#include <time.h>
#include<algorithm>
using namespace std;

int main()
{
	cout << "Programa de generacion de numeros aleatorios" << endl;
	//Declarando variables.
	int  n, i, j, desde, hasta, tempcantidad, suma, repetir;
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
	cout << "Ingrese cantidad de aleatorios que desea producir: ";
	cin >> repetir;
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
	//Crear las variables para el arreglo dinámico.
	int* aleatorio = new int[n];
	int* temp = new int[tempcantidad];
	//La cantidad de elemento entre el rango (desde-hasta) no puede ser menor a n (tamaño del arreglo aleatorio).
	if (tempcantidad < n)
	{
		cout << "El rango " << desde << " al " << hasta << " es de " << tempcantidad << " elementos y no puede ser menor al tamaño del arreglo" << endl;
		system("pause");
		return 0;
	}
	//Insertar valores ordenados (valores desde-hasta) en el arreglo temp.
	suma = desde;
	for (i = 0; i < tempcantidad;i++)
	{
		temp[i] = suma;
		suma = suma + 1;
	}
	//Generar aleatorios.
	for (j = 0;j < repetir;j++)
	{
		//Desordenar arreglo temp.
		random_shuffle(&temp[0], &temp[tempcantidad]);
		//Insertar valores temp en arreglo aleatorio.
		for (i = 0; i < n;i++)
		{
			aleatorio[i] = temp[i];
		}
		//Mostrar arreglo aleatorio.
		for (i = 0; i < n;i++)
			cout << "Aleatorio [" << i << "] : " << aleatorio[i] << endl;
		cout << endl;
	}
	//Liberar memoria del arreglo.
	delete[]aleatorio;
	delete[]temp;
	system("pause");
	return 0;
}

