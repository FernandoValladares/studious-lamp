#if defined(_WIN32) || defined(WIN32) // Windows-way ~
   #define WIN32_LEAN_AND_MEAN // para no incluir cosas innecesarias en windows.h
   #include <Windows.h>
   #define gotoxy(x,y) {COORD a;a.X = x; a.Y = y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);}
#else // Linux-Way =)
   #include <ncurses.h>
   #define gotoxy(x,y) move(x,y)
#endif

#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <String.h>

using namespace std;

char clave[4], nom[21], fam[21], medida[11], mas, falso[3];
float exis, prec_uni;



void error(int error)
{
	gotoxy(25,23);
	if(error==1) printf("Error, la clave no puede empezar con un valor diferente de C ");
	if(error==2) printf("Error, no puedes introducir mas de 2 valores numericos");
	if(error==3) printf("Error, no puedes introducir mas caracteres");
	if(error==4) printf("Error, no puede haber un producto con 0 unidades de inventario");
	if(error==5) printf("Error, no puede haber un producto con precio de $0");
	getche();
}



void pide_datos()
{
	system ("cls");
	
	
	do {
		gotoxy(20,5); printf("                                                                   ");     //Borrar
		gotoxy(20,5); printf("Introduce la clave de tu producto               : "); gets(clave);
		if(clave[0]!='C') error(1);
		if(strlen(clave)>3) error(2);
	} while	((clave[0]!='C') && (strlen(clave)>3));
	
	do {
		gotoxy(20,6); printf("                                                                   ");     //Borrar
		gotoxy(20,6); printf("Introduce el nombre de tu producto              : "); gets(nom);
		if(strlen(nom)>20) error(3);
	} while	((strlen(nom)>20));
	
	do {
		gotoxy(20,7); printf("                                                                   ");     //Borrar
		gotoxy(20,7); printf("Introduce la familia de tu producto             : "); gets(fam);
		if(strlen(fam)>20) error(3);
	} while	((strlen(fam)>20));
	
	do {
		gotoxy(20,8); printf("                                                                   ");     //Borrar
		gotoxy(20,8); printf("Introduce la unidad de medida de tu producto    : "); gets(medida);
		if(strlen(medida)>20) error(3);
	} while	((strlen(medida)>20));
	
	do {
		gotoxy(20,9); printf("                                                                   ");     //Borrar
		gotoxy(20,9); printf("Introduce la existencia del producto            : "); scanf("%f",&exis); gets(falso);
		if ((exis)<=0) error(4);
	} while	((exis)<0);
	
	do {
		gotoxy(20,10); printf("                                                                   ");     //Borrar
		gotoxy(20,10); printf("Introduce el precio del producto                : "); scanf("%f",&prec_uni); gets(falso);
		if ((prec_uni)<=0) error(5);
	} while	((prec_uni)<0);
	
}


void graba()
{
		for(int i=0;i<strlen(nom);i++) if (nom[i]==' ') nom[i]='_';
		for(int i=0;i<strlen(fam);i++) if (fam[i]==' ') fam[i]='_';
		ofstream arch;
		arch.open("productos.txt",ios::app);
		arch <<clave <<" " <<nom <<" " <<fam <<" " <<exis <<" " <<medida <<" " <<prec_uni <<" ""\n";
		arch.close();
}

main()
{
	pide_datos();
	graba();
}
