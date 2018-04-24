#if defined(_WIN32) || defined(WIN32) // Windows-way ~
   #define WIN32_LEAN_AND_MEAN // para no incluir cosas innecesarias en windows.h
   #include <Windows.h>
   #define gotoxy(x,y) {COORD a;a.X = x; a.Y = y;SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);}
#else // Linux-Way =)
   #include <ncurses.h>
   #define gotoxy(x,y) move(x,y)
#endif
# include <stdio.h>
# include <conio.h>
# include <Math.h>

void error(int er)
{
	gotoxy(35,17);
	if (er==1) printf("Error, opci%cn fuera del rango del 1 al 6");
	getche();
}

void alta()
{
	
}

void cc()
{
	
}

void cf()
{
	
}

void listado_p()
{
	
}

void list_ex()
{
	
}
void menu()
{
	char op;
	while (op!=char(54))
	{
		system("cls");
		gotoxy(35,5); printf("1) Altas de productos ");
		gotoxy(35,6); printf("2) Consultas de productos por clave ");
		gotoxy(35,7); printf("3) Consulta de productos por familia ");
		gotoxy(35,8); printf("4) Listado de productos");
		gotoxy(35,9); printf("5) Listado de productos por existencia ");
		gotoxy(35,10); printf("6) Salir del sistema");
		gotoxy(35,13); printf("Indica la opci%cn: ",162);
		gotoxy(53,13); op=getche();
		if(((op<'a')||(op>'g')) && (op!=char(54))) error(1);
		else
		{
			switch(op)
			{
				case '1': alta(); break;
				case '2': cc(); break;
				case '3': cf(); break;
				case '4': listado_p(); break;
				case '5': list_ex(); break;
			}
		}
	}
}
asdfghjklñ
main()
{
	menu();
}
