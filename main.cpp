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
	int clave, inf;
	
	lista<int> a;
	
	a.insertar(10,2);

	return 0;
}
