/*
Julieth Tatiana Riaño Mora - 20181020107
Juan David Rosero Torres - 20181020071
Cristian Camilo Martinez Rey 20181020021
*/
#ifndef LISTA_H
#define LISTA_H
#include <iostream>

using namespace std;

template <class T>
struct nodo {T Dato;
             nodo<T> * sig;
			 int clave;};


template <class T>
class lista{
	nodo <T> *inicio, *final;		
	public: lista(){
		inicio = new nodo <T>;
		final = new nodo <T>;
		inicio->clave= -1;
		final->clave=50505050505050;
		inicio->sig=final;
	}
	bool lista_vacia();
	bool lista_llena();
	void insertar(int clave, T info);
	void borrar(int clave);
	bool buscar (int clave, T *infoRet);
	bool pertenence(int clave);
	bool asignarInfo(int clave, T infoNueva);	
	void recorrer();			
};

template <class T>
bool lista<T>::lista_vacia()
{if(inicio.sig=final){
	return true;
	}
	else 
		return false;
}

template <class T>
void lista <T>::insertar(int clave, T info)
{
	nodo <T> *aux,*nuevo = new nodo <T>;
	nuevo->clave = clave;
	nuevo->Dato = info;
	aux=inicio;
	while(clave>aux->sig->clave){
		aux=aux->sig;
	}
	nuevo->sig=aux->sig;
	aux->sig= nuevo;
}

template <class T>
void lista<T>::borrar(int clave)
{	nodo <T> *temp,*anterior;
	temp = inicio;
	if(inicio->sig == final){
		cout << "No hay nada para borrar" << endl;
	}
	else{
		while((clave != temp->clave && temp->sig != final) || temp->clave>clave ){
			anterior=temp;
			temp=temp->sig;
		}
		if(temp->clave==clave){
			//Toca borrar la clave
			anterior->sig=temp->sig;
			delete temp;
		}
		else {
			cout<<"No se encontró la clave"<<endl;
		}
		
	}
}
template <class T>
bool lista<T>::buscar(int clave, T *infoRet)
{   nodo <T> *aux=inicio->sig;
	while(aux->clave!=clave && aux->clave<clave)	//Es bucle termina cuando encuentra la cable o llega a una clave mayor
	{
		aux = aux->sig;
	}
	if(aux->clave==clave){	//Se obtiene el valor si la clave se encuentra dentro de la lista
    	*infoRet = aux->Dato;	
    	return true;
    }
    cout<<"No se encontro la clave buscada"<<endl;
	return false;
}
template <class T>
bool lista<T>::pertenence(int clave){
	nodo <T> *aux=inicio->sig;
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
	nodo <T> *sig = inicio->sig;
	while(sig != final){
		cout << sig->Dato << endl;
		sig = sig->sig;
	}
}

template <class T>
bool lista<T>::asignarInfo(int clave, T infoNueva)
{ nodo <T> *aux=inicio->sig;
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
  cout<<"La clave buscada no existe"<<endl;
  return false;	
}	

#endif
