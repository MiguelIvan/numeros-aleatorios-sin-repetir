// Aleatorio por odenamiento comparado.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include<iostream>
#include <time.h>
#include <algorithm>
using namespace std;

int main()
{
	cout << "Programa de generacion de numeros aleatorios" << endl;
	//Declarando variables.
	int  n, num, desde, hasta, clave, tempcantidad, suma, repetir, inicio, fin, medio, aux;
	//Ciclos
	int i, j, k, c, p;
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
		//Insertar valores en el arreglo aleatorio.
		for (i = 0; i < n; i++)
		{
			//Generar el aleatorio en la posición actual del arreglo.
			num = desde + rand() % ((hasta + 1) - desde);
			aleatorio[i] = num;
		}
		//Ordenar el arrelgo aleatorio.
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
		//Buscando elementos repetidos.
		for (i = 0; i < n;i++)
		{
			/* Si el elemento actual y el elemento siguiente coinciden
			convierte el valor del elemento actual en cero */
			if (aleatorio[i] == aleatorio[i + 1])
			{
				aleatorio[i] = 0;
			}
		}
		//Buscar en temp valores que ya están en el arrelgo.
		for (i = 0;i < tempcantidad;i++)
		{
			clave = temp[i];
			c = 0;
			inicio = 0;
			fin = n - 1;
			//Busca la clave en el arreglo donde están los aleatorios.
			while (c<n)
			{
				//Si encuentra la clave en el arreglo aleatorio.
				if (clave == aleatorio[c])
				{
					//Ve a temp y cambia el valor en cero.
					while (inicio <= fin)
					{
						//Medio será igual a la mitad de la dimensión del arreglo.
						medio = (fin + inicio) / 2;
						//Si variable medio es similar a la clave de búsqueda convierte el valor en cero.               
						if (temp[medio] == clave)
						{
							temp[medio] = 0;
							fin = -1;
						}
						//De lo contrario verifica si la posición del valor medio actual es menor que la clave de búsqueda.
						else
							if (clave < temp[medio])
								fin = medio - 1;
							else
								inicio = medio + 1;
					}
				}
				c = c + 1;
			}
		}
		//Pasando valores desde temp hasta el arreglo aleatorio.
		for (i = 0;i < n;i++)
		{
			c = 0;
			while (c<tempcantidad)
			{
				//Si el valor de la posición actual en temp es diferente de cero...
				if (temp[c] != 0)
				{
					//Ve al arreglo aleatorio y busca algun valor en cero y asigna
					//el valor de temp[c] a dicho valor en el arrelgo aleatorio.
					for (j = 0;j < n;j++)
					{
						if (aleatorio[j] == 0)
						{
							aleatorio[j] = temp[c];
							temp[c] = 0;
							j = n;
						}
					}
				}
				c = c + 1;
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
		delete[]temp;
	}
	system("pause");
	return 0;
}



