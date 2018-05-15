#include <vector> 

using namespace std;

bool en_banco(vector<DNI> banco, DNI eldni) {
    for (int i = 0; i < banco.size(); i++) {
        if (banco[i] == eldni)
            return true;
    }
    return false;
}


int  demostracion( AVL<int> & arbol2,int dem){

        int in;
        int valor;
        cout << "   [0] Salir" << endl;
		cout << "   [1] Insertar clave" << endl;
		cout << "   [2] Eliminar clave" << endl;
		cout << "Opción: ";
		cin >> dem;
		switch(dem){
			case 0:
				dem = 0;
				break;

			case 1:
				cout << endl;
				cout<<" Insertar: ";
				cin >> in;
				/* Nota si se quiere probar con enteros pequeños quitar condiciones */
				if(( in < MIN) || (in > MAX))
					cout << " El DNI no puede ser inferior a " << MIN << "ni mayor a " << MAX << endl;
				else
					arbol2.Insertar(in);

				break;
				
			case 2:
				arbol2.mostrar();
				cout <<"\n\n";
				cout << " Introduzca valor a eliminar: ";
				cin >> valor;
				arbol2.eliminar(valor);
				break;
				
			default:
				cout << "\nValor no encontrado " << endl;
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
		
		cout << "\nIntroduzca el número de nodos a insertar: ";
		cin >> n_nodos;
		cout << "Introduzca el número de pruebas: ";
		cin >> n_pruebas;

		//Variables comparaciones
	
		int compi[n_pruebas],mini,medi,maxi; //variables insertar
		int compb[n_pruebas],minb,medb,maxb; //variables búsqueda
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
		cout << "              N    P    Mínimo   Medio   Máximo\n" << endl;
		cout << "Búsqueda      " << n_nodos  << "    " <<  n_pruebas << "        " << minb << "      " <<   medb/n_pruebas  <<  "     " << maxb  << endl;
		cout << "\nInsercción    " << n_nodos  << "    " <<  n_pruebas << "        " << mini << "      " <<   medi/n_pruebas  <<  "     " << maxi  << endl;
		
              
}