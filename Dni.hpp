#pragma once 
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h> 



const int  MIN = 00000000;
const int  MAX = 99999999;

class DNI{
    
    int dni;
    int letra;
   
public:

    explicit DNI(const int dn):
    dni(dn)
    {
        assert ((dn < MIN )|| (dn > MAX));
        letra =  rand() % 9;
         
    }
     
    DNI(){
         
       srand(time(NULL));
       int dn = MIN + rand() % (MAX - MIN);
       dni = dn;
       letra = rand() % 6;
    
         
    }
    
    ~DNI(){
    }
      
    
    int  get_dni() const{
        
       int result = dni ;//+ letra;
        return result;
    }
    
    
    void set_dni(int dn){
        dni = dn;
      //  letra = l;
    }
    
    int* generar(int TAMANOBANCO,int* banco){
			banco = new int[TAMANOBANCO];
			for(int i=0;i<TAMANOBANCO;i++){
			      banco[i] = MIN + (rand() % ( MAX - MIN));
			    
			}
			return banco;
	}
    
    
    void reset(int TAMANOBANCO, int* ref){
			for(int i=0;i<TAMANOBANCO;i++){
			      ref[i] = 0;
			    
			}
	}
		
    char getRandomChar()
    {
        static char c = 'H' + rand()% 5;
        return c;    
    }
    bool operator==(const DNI& b){
        
        return (get_dni() == b.get_dni());
    }
    
    
    bool operator<(const DNI& b){
        return (get_dni() < b.get_dni() );
    }
    
    
    bool operator>(const DNI& b){
        return (get_dni() > b.get_dni() );
       
    }
    bool operator<=(const DNI& b){
        return (get_dni() <= b.get_dni());
        
    }
    bool operator>=(const DNI& b){
        return (get_dni() >= b.get_dni());
    }
    
    std::ostream& write(std::ostream& os){

			
		        os << dni;
		
    }
};
