#include <vector> 
#include <assert.h>
#include <cstdio>
#include <cstdlib>

#define MY_LOG Log(__FUNCTION__) 

bool en_banco(std::vector<DNI> banco, DNI eldni) {
    for (int i = 0; i < banco.size(); i++) {
        if (banco[i] == eldni)
            return true;
    }
    return false;
}


int  demostracion( AVL<int>& arbol2,int dem){

        int in;
        int valor;
        MY_LOG << "   [0] Salir\n";
        MY_LOG << "   [1] Insertar clave\n"; 
        MY_LOG << "   [2] Eliminar clave\n";
        MY_LOG << "Opción:\n ";
		std::cin >> dem;
		switch(dem){
			case 0:
				dem = 0;
				break;

			case 1:
				MY_LOG << "\n";
				MY_LOG << " Insertar: ";
				std::cin >> in;
				/* Nota si se quiere probar con enteros pequeños quitar condiciones */
				//assert(( in < MIN) || (in > MAX));
				arbol2.Insertar(in);

				break;
				
			case 2:
				arbol2.mostrar();
				MY_LOG << "\n\n Introduzca valor a eliminar: ";
				std::cin >> valor;
				arbol2.eliminar(valor);
				break;
				
			default:
				MY_LOG << "\nValor no encontrado ";
				break;

		}
		arbol2.mostrar();
	return dem;
   
}

int estadistica (AVL<int>& arbol){
		int n_pruebas;
		int* ref;
		int* banco;
		int n_nodos;
		DNI numeros;
		
		MY_LOG <<  "\nIntroduzca el número de nodos a insertar: ";
		std::cin >> n_nodos;
		MY_LOG <<  "Introduzca el número de pruebas: ";
		std::cin >> n_pruebas;

		//Variables comparaciones
	
		//int compi[n_pruebas];
		int mini;
		int medi;
		int maxi; //variables insertar
		//int compb[n_pruebas];
		int minb;
		int medb;
		int maxb; //variables búsqueda
		mini = 99999999;
		maxi = 0;
		medi = 0;
		medb = 0;
		minb = 99999999;
		maxb = 0;
	
		//Comienzo de comparaciones
		ref = numeros.generar(n_nodos,banco);
		for(int i = 0; i < n_nodos; i++){                
			arbol.Insertar(ref[i]);
		}

		for(int i = 0; i < n_pruebas; i++){                
			arbol.Buscar(ref[i]);
			if(arbol.comp_b > maxb)
				maxb = arbol.comp_b ; 
			if(arbol.comp_b < minb)
				minb = arbol.comp_b ; 
			medb += arbol.comp_b ; 
			arbol.reset();
		}

		numeros.reset(n_nodos,ref);
		ref = numeros.generar(n_nodos,banco);
	
			for(int i = 0; i < n_pruebas; i++){
				arbol.Buscar(ref[i]);
				if(arbol.comp_b > maxi) 
                                    maxi = arbol.comp_b ; 
				if(arbol.comp_b <  mini) 
                                    mini = arbol.comp_b ; 
                                medi += arbol.comp_b ; 
                                arbol.reset();
			}	

	// Resultado de las comparaciones 
		MY_LOG <<  "              N    P    Mínimo   Medio   Máximo\n" ;
                MY_LOG <<  "              " <<n_nodos << "    " <<  n_pruebas  << "      "<< minb << "      "<< medb/n_pruebas<< "       "<< maxb;
		MY_LOG << "\nInsercción:   ";
                MY_LOG <<   n_nodos << "    " <<  n_pruebas  << "      "<< mini << "      "<< medi/n_pruebas<< "       "<< maxi;
		MY_LOG <<  "\n";
              
}





