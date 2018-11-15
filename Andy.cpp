//============================================================================
// Name        : Andy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int Bubblesort(int* arr, int* parr);
int Busqueda(int arr[], int n, int* parr);
void print(int arr[], int* parr);


int main() {
	int arr[11] = {10, 7, 8, 9, 0, 1000, 30, 20, 45, 70, 1};
	int n;
	cout<<"Ingrese el número que desea encontrar: ";
	cin>>n;
	int size = sizeof(arr)/sizeof(int);
	int* parr = &arr[size];
	cout<<"Arreglo ordenado: ";
	print(arr, parr);
	cout<<endl;
	if(Busqueda(arr, n, parr) != -1){
		cout<<"Si se encontro el número "<<n<<" en el indice: "<<Busqueda(arr, n, parr)<<endl;
	}
	else{
		cout<<"El numero "<<n<<" no esta en el arreglo."<<endl;
	}
	return 0;
}

int Bubblesort(int* arr, int* parr){
	int temp;
	int contador;
	for(contador = 1; &arr[contador] != parr; contador++);
	for(int j = contador-1; j>0; j--){
		for(int i = 0; i<j; i++){
			if(arr[i]>arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	return contador;
}

int Busqueda(int* arr, int n, int* parr){
	int size = Bubblesort(arr, parr);
	int max = size-1;
	int min = 0;
	int centro;
	while(min <= max){
		centro = ((max+min)/2);
		if(arr[centro] == n){
			return centro;
		}
		else if(arr[centro] < n){
			min = centro+1;
		}
		else{
			max = centro-1;
		}
	}
	return -1;
}

void print(int* arr, int* parr){
	int size = Bubblesort(arr, parr);
	for(int i = 0; i<size; i++){
		cout<<arr[i]<<" ";
	}
}
