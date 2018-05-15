#ifndef _AVL__H_
#define _AVL__H_
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include "nodoAVL.hpp"
#include <queue>
using namespace std;

template <class T>
class AVL{
	private:
		nodoAVL<T> *raiz;

	public:
		int n_nodos;
		int comp_b; // comparar número de busquedas

	public:
		AVL(){
			raiz = NULL;
			comp_b = 0;
			n_nodos = 0;
		}
	
		~AVL(){}

		nodoAVL<T>* Buscar( T clave_dada ){
			return BuscarRama(raiz, clave_dada); 
		}
		
		nodoAVL<T>* BuscarRama( nodoAVL<T>* nodo,T clave_dada) {
			comp_b++;
			if (nodo == NULL)
				return NULL ;
			if (clave_dada == nodo->clave)
				return nodo ;
			if (clave_dada < nodo->clave )
				return BuscarRama(nodo->izdo, clave_dada);
			return BuscarRama(nodo->dcho, clave_dada);
		}

		void Insertar( T clave_dada) {
			nodoAVL<T>* nuevo = new nodoAVL<T>( clave_dada,clave_dada, 0 );
			bool crece = false;
			insertar_bal( raiz, nuevo, crece);
			
		}

		void insertar_bal( nodoAVL<T>* &nodo,nodoAVL<T>* nuevo, bool& crece) {
			if (nodo == NULL) {
				nodo = nuevo;
				crece = true;
			} else if (nuevo -> clave < nodo -> clave) {
				insertar_bal(nodo -> izdo,nuevo,crece);
				if (crece) 
					insertar_re_bal_izq(nodo,crece);
			  } else {
					insertar_bal(nodo->dcho,nuevo,crece);
					if (crece) 
						insertar_re_bal_dcha(nodo,crece);
			 	}
		}

		void insertar_re_bal_izq(nodoAVL<T>* &nodo,bool& crece) {	
			switch (nodo -> bal) {
				case -1: nodo -> bal = 0;
					crece = false;
					break;
				case 0: 
					nodo -> bal = 1 ;
					break;
				case 1: 
					nodoAVL<T>* nodo1 = nodo -> izdo;
					if (nodo1 -> bal == 1)
						rotacion_II(nodo);
					else rotacion_ID(nodo);
						crece = false;
			}
		}

		void insertar_re_bal_dcha (nodoAVL<T>* &nodo,bool& crece) {
			switch (nodo -> bal) {
				case 1: 
					nodo -> bal = 0;
					crece = false;
					break;
				case 0: 
					nodo -> bal = -1;
					break;
				case -1: 
					nodoAVL<T>* nodo1 = nodo -> dcho;
					if (nodo1 -> bal == -1)
						rotacion_DD(nodo);
					else 
						rotacion_DI(nodo);
					crece = false;
				}
		}

		void eliminar( int clave_data) {
			bool decrece = false;
			elimina_rama( raiz, clave_data, decrece);
		}
		
		void elimina_rama( nodoAVL<T>* &nodo,T clave_dada, bool& decrece) {
			if (nodo == NULL) 
				return;
			if (clave_dada < nodo -> clave) {
				elimina_rama(nodo -> izdo,clave_dada,decrece);
				if (decrece)
					eliminar_re_balancea_izda(nodo,decrece);
			} else if (clave_dada > nodo -> clave) {
			  	elimina_rama(nodo -> dcho,clave_dada,decrece);
				if (decrece)
					eliminar_re_balancea_dcha(nodo,decrece);
			  } else { 
					nodoAVL<T>* Eliminado = nodo;
					if (nodo->izdo == NULL) {
						nodo = nodo -> dcho;
						decrece = true;
					}
					else if (nodo -> dcho == NULL) {
						nodo = nodo -> izdo;
						decrece = true;
					}
					else {
						sustituye(Eliminado,nodo -> izdo,decrece);
					if (decrece)
						eliminar_re_balancea_izda(nodo,decrece);
					}
					delete Eliminado;
		     	}
		}

		void sustituye(nodoAVL<T>* &eliminado,nodoAVL<T>* &sust, bool &decrece) {
			if (sust->dcho != NULL) {
				sustituye(eliminado, sust -> dcho, decrece);
			if (decrece)
				eliminar_re_balancea_dcha(sust, decrece);
			} else {
				eliminado -> dato = sust -> dato;
				eliminado -> clave = sust -> clave;
				eliminado = sust;
				sust = sust -> izdo;
				decrece = true;
			 }
		}

		void eliminar_re_balancea_izda ( nodoAVL<T>* &nodo, bool& decrece) {
			nodoAVL<T>* nodo1;
			switch (nodo -> bal) {
				case -1: 
					nodo1 = nodo -> dcho;
					if (nodo1 -> bal > 0)
						rotacion_DI(nodo);
					else {
						if (nodo1 -> bal == 0)
							decrece = false;
							rotacion_DD(nodo);
					}
					break;
				case 0:
				    nodo -> bal = -1;
					decrece = false;
					break;
					
				case 1: 
					nodo -> bal = 0;
			}
		}

		void eliminar_re_balancea_dcha ( nodoAVL<T>* &nodo, bool& decrece) {
			nodoAVL<T>* nodo1;
			switch (nodo -> bal) {
			case 1: 
				nodo -> izdo;
				if (nodo1 -> bal < 0)
					rotacion_ID(nodo);
				else {
					if (nodo1 -> bal == 0)
					decrece = false;
					rotacion_II(nodo);
				}
				break ;
			
			case 0:
				 nodo -> bal = 1;
				decrece = false;
				break;
			case -1: 
				nodo ->bal = 0;
			}
		}

		void contarnodos(){ 
		   n_nodos = 0; 
		   cuenta(raiz); 
		}

		void cuenta(nodoAVL<T> *nodo){
		   n_nodos++;
		   if(nodo -> izdo != NULL)
			   cuenta(nodo -> izdo);
		   if(nodo -> dcho != NULL)
			   cuenta(nodo -> dcho);
		}


		void  rotacion_DD (nodoAVL<T>* &nodo) {
		nodoAVL<T>* nodo1 = nodo -> dcho;
		nodo -> dcho = nodo1 -> izdo;
		nodo1 -> izdo = nodo ;
		if (nodo1 -> bal == -1) {
			nodo -> bal = 0;
			nodo1 -> bal = 0;
		} else { // nodo1->bal == 0
			nodo -> bal = -1;
			nodo1 -> bal = 1;
		 }
		nodo = nodo1;
		}

		void  rotacion_II (nodoAVL<T>* &nodo) {
			nodoAVL<T>* nodo1 = nodo -> izdo;
			nodo -> izdo = nodo1 -> dcho;
			nodo1 -> dcho = nodo;
			if (nodo1 -> bal == 1) {
				nodo -> bal = 0;
				nodo1 -> bal = 0;
			} else { // nodo1->bal == 0
				nodo -> bal = 1;
				nodo1 -> bal = -1;
			  }
			nodo = nodo1;
		}

		void  rotacion_ID (nodoAVL<T>* &nodo) {
			nodoAVL<T>* nodo1 = nodo -> izdo;
			nodoAVL<T>* nodo2 = nodo1 -> dcho;
			nodo -> izdo = nodo2 -> dcho;
			nodo2 -> dcho = nodo;
			nodo1 -> dcho = nodo2 -> izdo;
			nodo2 -> izdo = nodo1;
			if (nodo2 -> bal == -1)
				nodo1 -> bal = 1;
			else nodo1 -> bal = 0;
				if (nodo2 -> bal == 1)
					nodo -> bal = -1;
				else nodo -> bal = 0;
					nodo2 -> bal = 0;
				nodo = nodo2;
		}

		void  rotacion_DI (nodoAVL<T>* &nodo) {
			nodoAVL<T>* nodo1 = nodo -> dcho;
			nodoAVL<T>* nodo2 = nodo1 -> izdo;
			nodo -> dcho = nodo2 -> izdo;
			nodo2 -> izdo = nodo;
			nodo1 -> izdo = nodo2 -> dcho;
			nodo2 -> dcho = nodo1;
			if (nodo2 -> bal == 1)
				nodo1 -> bal = -1;
			else 
				nodo1 -> bal = 0;
			if (nodo2 -> bal == -1)
				nodo -> bal = 1;
			else 
				nodo -> bal = 0;
			nodo2 -> bal = 0;
			nodo = nodo2;
		}

		void mostrar(){
	   		if(raiz != NULL){
	         bool nivel_= true; //Chivato para el nivel
			   queue<nodoAVL<T>*> cola;
			   cola.push(raiz);
			   int j = 0; //Nivel
			   int i = 1; //Iterador por nivel
			   int k = 0; //Iterador de nodos totales
			   int l; //Solo para espacios
			   contarnodos(); //Hacemos un dfs para ver cuantos nodos hay activos
			   while (k < n_nodos && !cola.empty()){ //Mientras no haya recorrido todos los nodos activos
	            if(nivel_){ 
	               cout << "Nivel " << j << ":"; //Printamos el nivel
	               nivel_= false;
	            }
				   if (cola.front() != NULL){ //Si no es null, pusheamos normal
	               	   cola.push(cola.front() -> izdo);
					   cola.push(cola.front() -> dcho);
				   } else{ 
					   cola.push(NULL);
					   cola.push(NULL);
				   }
				   if (cola.front() != NULL){
	               	  for(l=0;l<2;l++) 
	                  	cout << " ";
					   //printf ("%d",cola.front()->get_clave()); 
						cout << cola.front()->get_clave();
	           
	           	   } else{
				     	for(l = 0; l < 2; l++)
	                 		printf(" ");
					     printf("[.]"); 
				         k--; //Cada vez que imprimamos un nodo vacio, restamos 1 al contador para seguir con el limite de los nodos activos
	           	     }
				  
				  cola.pop();
				   if (i == pow(2,j)){ //Cuando imprimimos todos los nodos del nivel 2^j
					   j++; //Pasamos al siguiente nivel
					   printf("\n");
					   i = 0; //Y reseteamos el iterador
					   nivel_= true; //Activamos el bool que nos avisará del siguiente nivel
				   }
				   i++; //Incrementamos el iterador pro nivel
				   k++; //Incrementadmos el iterador de activos
			  }
			}
			printf("\n");
		}

		void reset(){
			comp_b = 0;
		}
		
		};
#endif