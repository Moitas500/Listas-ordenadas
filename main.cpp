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
	
	int pos  = 1, inf;
	char letra;
	persona p;
	
	lista<int> a;
	lista<float> b;
	lista<char> c;
	lista<persona> d;
	persona per;
	
	a.insertar_inicio(8);
	a.insertar_final(18);
	a.insertar(10,2);
	a.insertar(12,3);
	
	b.insertar_inicio(5.5);
	b.insertar_final(6.3);
	b.insertar(10.2,2);
	b.insertar(12.6,3);	
	
	c.insertar_inicio('a');
	c.insertar_final('z');
	c.insertar('c',2);
	c.insertar('d',3);
	
	per.codigo = 1000;
	per.nombre = "Juan";
	
	d.insertar_inicio(per);
	
	per.codigo = 1500;
	per.nombre = "Pedro";
	
	d.insertar_final(per);
	
	per.nombre = 2000;
	per.nombre = "maria";
	
	d.insertar(per,2);
	
	per.nombre = 2500;
	per.nombre = "Ana";
	
	d.insertar(per,3);
	
	a.cambiar(2,15);
	a.borrar(3);
	
	while(pos <= d.get_tam()){
		d.buscar(pos, &p);
		cout << p.codigo << " " << p.nombre << "" << endl;
		pos++;
	}
	
	return 0;
}
