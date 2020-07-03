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
			bool lista_llena();
			void insertar(int codigo, T info);
			void borrar(int clave);
			bool buscar (int clave, T *infoRet);
			bool pertenence(int clave);
			bool cambiar(int clave, T infoNueva);	
			void recorrer();
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
	nuevo->clave = codigo;
	nuevo->Dato = info;
	
	if(cab == NULL){
		cab = nuevo;
		nuevo->sig = NULL;
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
				nuevo->sig = NULL;
			}
			else{
				nuevo->sig = siguiente;
				atras->sig = nuevo;
			}
		}
	}
	tam++;	
}

template <class T>
void lista<T>::borrar(int clave)
{	nodo <T> *temp;
	temp = cab;
	if(cab == NULL){
		cout << "No hay nada para borrar" << endl;
	}
	else{
		if(clave == cab->clave){
			cab = temp->sig;
			delete temp;
		}
		else{
			nodo <T> *anterior;
			
			while(clave != temp->clave && temp->sig != NULL){
				anterior = temp;
				temp = temp->sig;
			}
			
			anterior->sig = temp->sig; 
			delete temp;
		}
	}
	tam--;
}
template <class T>
bool lista<T>::buscar(int clave, T *infoRet)
{   nodo <T> *aux=cab;
    if (clave>=aux->clave)
	   { 
	   	while(aux->clave!=clave && aux->clave<clave)	//Es bucle termina cuando encuentra la cable o llega a una clave mayor
	   	{
	   		aux = aux->sig;
		}
		if(aux->clave==clave){	//Se obtiene el valor si la clave se encuentra dentro de la lista
    		*infoRet = aux->Dato;	
    		return true;
    		}
		}
	return false;
}
template <class T>
bool lista<T>::pertenence(int clave){
	nodo <T> *aux=cab;
	if (clave>=aux->clave)
	   { 
	   	while(aux->clave!=clave && aux->clave<clave)	//Es bucle termina cuando encuentra la cable o llega a una clave mayor
	   	{
	   		aux = aux->sig;
		}
		if(aux->clave==clave){	// si la clave se encuentra dentro de la lista	
    		return true;
    		}
		}
	return false;
}


template <class T>
void lista <T>::recorrer(){
	nodo <T> *sig = cab;
	while(sig != NULL){
		cout << sig->Dato << endl;
		sig = sig->sig;
	}
}

template <class T>
bool lista<T>::cambiar(int clave, T infoNueva)
{ nodo <T> *aux=cab;
  if (clave>=aux->clave)
	   { 
	   	while(aux->clave!=clave && aux->clave<clave)	//Es bucle termina cuando encuentra la cable o llega a una clave mayor
	   	{
	   		aux = aux->sig;
		}
		if(aux->clave==clave){
			aux->Dato = infoNueva;
			return true;
		}
		}
  return false;	
}	

#endif
