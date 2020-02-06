// Aleatorio por odenamiento.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include<iostream>
#include <time.h>
#include<algorithm>
using namespace std;

//Función para ordenar
int ordenar(int n, int aleatorio[])
{
	int j, p, aux;
	for (j = 1; j < n; j++)
	{
		for (p = 0; p < n - 1; p++)
		{
			if (aleatorio[p]>aleatorio[p + 1])
			{
				aux = aleatorio[p + 1];
				aleatorio[p + 1] = aleatorio[p];
				aleatorio[p] = aux;
			}
		}
	}
	return (n, aleatorio[n]);
}

//Funcion principal
int main()
{
	cout << "Programa de generacion de numeros aleatorios" << endl;
	//Declarando variables.
	int  n, num, desde, hasta, tempcantidad, repetir, aux, k, i;
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
		for (i = 0; i < n; i++)
		{
			//Generar el aleatorio en la posición actual del arreglo.
			num = desde + rand() % ((hasta+1) - desde);
			aleatorio[i] = num;
		}
		//Ordenar arreglo aleatorio.
		ordenar(n, aleatorio);
		//Buscando elementos repetidos.
		for (i = 0; i < n;i++)
		{
			/* Si el elemento actual y el elemento siguiente coinciden
			genera un nuevo elemento aleatorio para la siguiente posición
			luego ordena el arreglo*/
			while (aleatorio[i] == aleatorio[i + 1])
			{
				num = desde + rand() % ((hasta + 1) - desde);
				aleatorio[i + 1] = num;
				ordenar(n, aleatorio);
				i = 0;
			}
		}
		//Desordenar arreglo aleatorio.
		random_shuffle(&aleatorio[0], &aleatorio[n]);
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


