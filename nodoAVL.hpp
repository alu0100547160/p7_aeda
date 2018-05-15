#ifndef _NODOAVL__H_
#define _NODOAVL__H_
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

template <class T>
class nodoAVL{

	public:
		// Miembros:
		   T dato;
		   T clave;
		   int bal;
		   nodoAVL *izdo;
		   nodoAVL *dcho;
		   
		   nodoAVL(T dat, T cl, nodoAVL *iz = NULL, nodoAVL *de = NULL){
		   	dato = dat;
		   	clave = cl;
		   	bal = 0;
		   	izdo = iz;
		   	dcho = de;
		   }
		   
		   T get_clave(){
		   	return clave;
		   }
		  
};
#endif