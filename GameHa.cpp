#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

//procedimiento usado para musiquita del juego ahorcado
void musicazelda(){
	Beep(659, 300);  // E5
    Sleep(150);
    Beep(523, 300);  // C5
    Sleep(150);
    Beep(587, 300);  // D5
    Sleep(150);
    Beep(784, 300);  // G5
    Sleep(300);

    Beep(659, 300);  // E5
    Sleep(150);
    Beep(523, 300);  // C5
    Sleep(150);
    Beep(587, 300);  // D5
    Sleep(150);
    Beep(784, 300);  // G5
    Sleep(300);

    // Segunda parte
    Beep(880, 300);  // A5
    Sleep(150);
    Beep(784, 300);  // G5
    Sleep(150);
    Beep(659, 300);  // E5
    Sleep(150);
    Beep(698, 300);  // F5
    Sleep(150);
    Beep(659, 300);  // E5
    Sleep(300);

    Beep(523, 300);  // C5
    Sleep(150);
    Beep(587, 300);  // D5
    Sleep(150);
    Beep(659, 300);  // E5
    Sleep(150);
    Beep(523, 300);  // C5
    Sleep(300);

    // Parte final
    Beep(587, 300);  // D5
    Sleep(150);
    Beep(659, 300);  // E5
    Sleep(150);
    Beep(784, 300);  // G5
    Sleep(150);
    Beep(880, 300);  // A5
    Sleep(300);

    Beep(784, 300);  // G5
    Sleep(150);
    Beep(659, 300);  // E5
    Sleep(150);
    Beep(523, 300);  // C5
    Sleep(150);
    Beep(587, 300);  // D5
    Sleep(300);
}

int main(){
	system("color 40");
	printf("BIENVENIDO AL JUEGO CLASICO AHORCADO!\n\n\n");
	getch();
	musicazelda();
	printf("\nPista inicial: la palabra contiene la consonante 'm'");
	char pal[10]="imposible";
	char r[100], t[100];
	char caracter;
	int n, bien=0, j=0, gana=0; 
	int vidas=10;
	int repetido; n=strlen(pal);
	for(int i=0;i<n;i++){
		t[i]='_';
	}
	t[n]=0;
	do{
		repetido=0;
		printf("\nLetras atinadas: %s",t);
		printf("\nVidas restantes: %d",vidas);
		printf("\nIntroduzca una letra: ");
		caracter=getch(); printf("\n");
		
		for(int i=0; i<j; i++){
			if(r[i]==caracter){
				repetido=1;
				break;
			}
		}
		if(!repetido){
			r[j++]=caracter;
			bien=0;
			for(int i=0; i<n; i++){
				if(pal[i]==caracter){
					t[i]=caracter;
					bien=1;
				}
			}
			if(!bien){
				vidas--;
			}
		}else{
			printf("Esta letra ya fue introducida :c\n");
		}
		if(strcmp(pal,t)==0){
			gana=1;
			break;
		}
	}while(vidas>0);
	
	if(gana){
		printf("\n\nGanaste! La palabra era %s",pal);
	}else{
    	printf("\n\nHaz perdido :c");
    	system("start C:\\Users\\InesL\\OneDrive\\Documentos\\ArchivosProyectoFP\\morido.webp"); 
    	getch(); 
	}
	musicazelda();
	return 0;
}
