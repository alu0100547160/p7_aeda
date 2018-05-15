#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include "AVL.hpp"
#include "Dni.hpp"
#include "utilidades.hpp"
using namespace std;


int main(void){

	//Variables
	int opc;
 	int dem;
 	AVL<int> arbol;
	AVL<int> arbol2;

  do{
 	cout << "   1. Modo Demostracion" << endl;
	cout << "   2. Modo Estadistica" << endl;
	cout << "   3. Salir " << endl;
	cout << "Opción: ";
	cin >> opc;

	if(opc == 1){
	  do{
		
		dem  =	demostracion( arbol2,dem);
	
	  }while(dem != 0);
	}

	if(opc == 2) estadistica(arbol);

  }while (opc != 3);

	return 0;
}