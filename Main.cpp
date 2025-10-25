#include <conio.h>xd
#include <windows.h>
#include <iostream>
#include <stdio.h>

int gotoxy(int x, int y);

int main() {
	
	system("color 06");
	gotoxy(35,10);
    printf("Les presentamos No.Creator, la plataforma mas divertida!: ");
    getch();
    system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\LogoNC.jpeg");
    getch(); 
    gotoxy(35,11);
    printf("Autores de No.Creator:");
    gotoxy(35,12);
	printf("Jose Agustin Nava Segura");
	gotoxy(35,13);
	printf("Edgar Andre Espinosa Barrales");
	gotoxy(35,14);
	printf("Emiliano Sanchez Gonzalez");
	gotoxy(35,15);
	printf("Norma Ines Llergo Sanchez");
	getch(); system("cls");    int opcion;
    do{
    	gotoxy(35,11);
    	printf("Presione 1 para comenzar con el juego clasico 'Ahorcado'");
    	gotoxy(35,12);
		printf("Presione 2 para comenzar con el juego clasico 'Pac-man");
    	gotoxy(35,13);
		printf("Presione 3 para comenzar con el juego clasico 'Laberinto'");
		gotoxy(35,14);
		printf("Presione 4 para comenzar con el juego clasico 'Snake'");
    	gotoxy(35,15);
		printf("Presione 5 para salir de la plataforma");
    	scanf("%d",&opcion);
    	system("cls");
    	switch(opcion){
    		case 1:{

    			printf("\nLogo de juego Ahorcado: ");
    			getch(); 
    			system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\LogoAhorca.jpg");
    			getch();
    			system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\JuegoA.exe");
    			getch();
    			system("cls");
				break;
			}
			case 2:{
				printf("\nLogo de juego PAC-MAN: ");
				getch();
    			system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\LogoPacman.jpeg");
    			getch();
    			system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\JuegoP.exe");
    			getch();
				break;
			}
			case 3:{
				printf("\nLogo de juego Laberinto: ");
				getch();
    			system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\LogoLaberinto.jpeg");
    			getch();
    			system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\JuegoL.exe");
    			getch();
				break;
			}
			case 4:{
				printf("\nLogo de juego Snake: ");
				getch();
    			system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\LogoSnake.jpeg");
    			getch();	
    			system("C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\JuegoS.exe");
    			getch();
				break;
			}	
		}
		getch();
		system("cls");
	}while(opcion!=5);
	
    return 0;
}

int gotoxy(int x, int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}
