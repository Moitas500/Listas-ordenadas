#include <iostream>
#include <cstdlib>
#include "lista.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct persona{
	string nombre;
	int codigo;
};

int main(int argc, char** argv) {
	int clave, inf=-1;
	
	lista<int> a;
	
	a.insertar(10,2);
	a.insertar(5,3);
	a.insertar(6,4);
	a.insertar(12,5);
	a.recorrer();
	a.buscar(6,& inf);
	cout<<"caracter buscado "<<inf<<endl;
	inf=-1;
	//Si el caracter buscado no se encuentra aparecera -1
	cout<<"Si esta "<<a.pertenence(6)<<endl;	//0 si no esta, 1 si si esta
	a.borrar(6);
	cout<<"Se ha borrado"<<endl;
	a.recorrer();
	cout<<"Si esta "<<a.pertenence(6)<<endl;	//0 si no esta, 1 si si esta
	a.buscar(6,& inf);
	cout<<"caracter  buscado "<<inf<<endl;

	return 0;
}
