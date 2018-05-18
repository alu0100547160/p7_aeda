#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include "AVL.hpp"
#include "Dni.hpp"
#include "utilidades.hpp"
#include "Logger.hpp"


#define MAGIC_LOG Log(__FUNCTION__) 


int main(void){

	//Variables
	int opc;
 	int dem;
 	AVL<int> arbol;
	AVL<int> arbol2;

  do{
 	MAGIC_LOG << "   1. Modo Demostracion\n";
        MAGIC_LOG << "   2. Modo Estadistica\n"; 
        MAGIC_LOG << "   3. Salir\n";
        MAGIC_LOG << " Opción:\n";
	std::cin >> opc;

	if(opc == 1){
	  do{
		
		dem  =	demostracion( arbol2,dem);
	
	  }while(dem != 0);
	}

	if(opc == 2) estadistica(arbol);

  }while (opc != 3);

	return 0;
}