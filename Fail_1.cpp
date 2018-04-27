#include <stdio.h>
#include <conio.h>
#include <fstream> //Paso 1

using namespace std; //Paso 2

main()
{
	ifstream arch; //Paso 3
	arch.open("productos.txt",ios::in); //Paso 4
	
	if(arch.fail()) printf("Archivo no existe");
	else printf("Archivo si existe");
	getche();
}
