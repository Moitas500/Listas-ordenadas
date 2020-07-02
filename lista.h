#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

template <class T>
struct nodo {T Dato;
             nodo<T> * sig;
			 int clave;};


template <class T>
class lista{nodo <T> *cab;
			int tam;
			
	public: lista(){cab=NULL; tam=0;}
			bool lista_vacia();
			void insertar(int codigo, T info);
			bool borrar(int pos);
			bool buscar (int pos, T *infoRet);
			bool cambiar(int pos, T infoNueva);	
			int get_tam(){
				return tam;
			}
			
			
			
};

template <class T>
bool lista<T>::lista_vacia()
{if(cab==NULL)
    return true;
 else
 	return false;
}

template <class T>
void lista <T>::insertar(int codigo, T info)
{
	nodo <T> *nuevo = new nodo <T>;
	nuevo->Dato = info;
	
	if(cab == NULL){
		cab = nuevo;
	}
	else{
		if(codigo<cab->clave){
			nuevo->sig = cab;
			cab = nuevo;
		}
		else{
			nodo <T> *siguiente = cab;
			nodo <T> *atras = cab;
			
			while(codigo >= siguiente->clave && siguiente->sig !=  NULL){
				atras = siguiente;
				siguiente = siguiente->sig;
			}
			
			if(codigo >= siguiente->clave){
				siguiente->sig = nuevo;
			}
			else{
				nuevo->sig = siguiente;
				atras->sig = nuevo;
			}
		}
	}	
}

template <class T>
bool lista<T>::borrar(int pos)
{ if(tam >= pos)
     { nodo <T> *temp;
       temp = cab;
       if(pos == 1)
         {cab = temp->sig;
          delete temp;
         }
       else
         {for(int i=1;i<pos-1;i++)
             {temp = temp->sig;}          
          nodo <T> *aux;
          aux = temp->sig;
          temp->sig = aux->sig;
          delete aux;
         }
        tam--;
        return true;          
     }
 else
     return false;
}

template <class T>
bool lista<T>::buscar(int pos, T *infoRet)
{   nodo <T> *aux=cab;
    int p = 1;
    if (pos<=tam)
	   { while(p<pos && aux != NULL)
    		{aux = aux->sig;
           	 p++;
    		}
    	*infoRet = aux->Dato;	
    	return true;
		}
	return false;
}

template <class T>
bool lista<T>::cambiar(int pos, T infoNueva)
{ nodo <T> *aux=cab;
  int p = 1;
  if (pos<=tam)
   { while(p<pos && aux != NULL)
   		{aux = aux->sig;
         p++;
    	}
     aux->Dato = infoNueva; 
     return true;
	}
  return false;	
}	

#endif
