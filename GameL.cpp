#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

//procedimiento para llamarlo en el jueguito con la musica de tetris
void musicatetris(){
	
    Beep(659, 300);
    Sleep(50);
    Beep(494, 300);
    Sleep(50);
    Beep(523, 300);
    Sleep(50);
    Beep(587, 300);
    Sleep(50);
    Beep(494, 300);
    Sleep(50);
    Beep(523, 300); 
    Sleep(50);
    Beep(587, 300);  
    Sleep(50);
    Beep(659, 300); 
    Sleep(50);
    Beep(587, 300);  
    Sleep(50);
    Beep(523, 300); 
    Sleep(50);
    Beep(494, 300); 
    Sleep(50);
    Beep(440, 300); 
    Sleep(50);
    Beep(440, 300);
    Sleep(50);
    Beep(494, 300); 
    Sleep(50);
    Beep(523, 300);
    Sleep(50);
    Beep(440, 300);
    Sleep(50);
    Beep(392, 300);
    Sleep(50);
    Beep(440, 300); 
    Sleep(50);
    Beep(494, 300); 
    Sleep(50);
    Beep(440, 300); 
    Sleep(50);
    Beep(392, 300); 
    Sleep(50);
    Beep(349, 300); 
    Sleep(50);
    Beep(392, 300); 
    Sleep(50);
    Beep(440, 300);  
    Sleep(50);
    Beep(349, 300);  
    Sleep(50);
    Beep(392, 300);  
    Sleep(50);
    Beep(440, 300); 
    Sleep(50);
    Beep(494, 300); 
    Sleep(50);
    Beep(523, 300); 
    Sleep(50);
    Beep(440, 300); 
    Sleep(50);
}

//generacion del mapa del juego de laberinto

void generar_m(char m[][20], int F, int C) {
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            if (rand() % 4 == 0) {
                m[i][j] = '#'; //los # señalan las paredes del laberinto
            } else {
                m[i][j] = '.'; //los puntos señalan el camino no visitado
            }
        }
    }

    
    m[0][0] = 'V';  //iniciar posicion del jugador representado con V
    m[F - 1][C - 1] = '.';
}


//generacion de puntos para poner el camino del jugador
void imprimir_m(char m[][20], int F, int C, int puntos) {
    system("cls");
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
}

int vacio(char m[][20], int F, int C) {
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] == '.') {
                return 0;
            }
        }
    }
    return 1;
}

void juego(char m[][20], int F, int C) {
    int i = 0, j = 0, k = 0;
    char c;

    while (1) {
        imprimir_m(m, F, C, k);

        
		
        if ((c = getch()) != EOF) {
            m[i][j] = '*';
            switch (c) {
            	
                case 'a': if (j > 0 && m[i][j - 1] != '#') j--; break; // letra a para ir a la zquierda
                case 'd': if (j < C - 1 && m[i][j + 1] != '#') j++; break; // letra d para ir a la erecha
                case 'w': if (i > 0 && m[i - 1][j] != '#') i--; break; // letra w para ir arriba
                case 's': if (i < F - 1 && m[i + 1][j] != '#') i++; break; // letra s para ir abajo
                case 27: exit(0); 
            }
            if (m[i][j] == '*') k++;
            m[i][j] = 'V';
        }
    }
}

int main() {
	
	//presentacion de nuestro juego laberinto
    system("color 05");
    printf("BIENVENIDO AL JUEGO DE LABERITNO!\n");
    printf("\nPropuesta de juego por: Emiliano Sanchez Gonzalez");
    printf("\nPresione 'w' para subir, 's' para bajar, 'a' para ir a la derecha, o 'd' para ir a la izquierda\n");
    printf("\n\nUna vez en la salida presione ESC para terminar el juego :)");
    getch();
    musicatetris(); //aqui llamamos el procedimiento para reproducir la musica

    char m[20][20];
    srand(time(NULL));

    generar_m(m, 20, 20);
    juego(m, 20, 20);

    return 0;
}

