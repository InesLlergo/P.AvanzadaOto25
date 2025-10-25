#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

void musicapacman(){
	// Parte inicial de la música de Pac-Man
    Beep(1319, 200);  // C6
    Sleep(100);
    Beep(987, 200);   // B5
    Sleep(100);
    Beep(1319, 200);  // C6
    Sleep(100);
    Beep(987, 200);   // B5
    Sleep(100);
    Beep(1319, 200);  // C6
    Sleep(100);
    Beep(987, 200);   // B5
    Sleep(100);

    // Cambiar a un patrón más largo
    Beep(1319, 400);  // C6
    Sleep(200);
    Beep(987, 400);   // B5
    Sleep(200);
    Beep(1319, 400);  // C6
    Sleep(200);
    Beep(987, 400);   // B5
    Sleep(200);

    // Parte media
    Beep(987, 200);   // B5
    Sleep(100);
    Beep(740, 200);   // F#5
    Sleep(100);
    Beep(622, 200);   // D#5
    Sleep(100);
    Beep(740, 200);   // F#5
    Sleep(100);
    Beep(622, 200);   // D#5
    Sleep(100);

    // Repetir el inicio
    Beep(1319, 200);  // C6
    Sleep(100);
    Beep(987, 200);   // B5
    Sleep(100);
    Beep(1319, 200);  // C6
    Sleep(100);
    Beep(987, 200);   // B5
    Sleep(100);
    Beep(1319, 200);  // C6
    Sleep(100);
    Beep(987, 200);   // B5
    Sleep(100);
}

//genera camino disponible dentro del mapa

void generar_m(char m[][20], int F, int C) {

    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            m[i][j] = '*';
        }
    }
}

//por cada punto en el que avanza se agregan puntos para el jugador

void imprimir_m(char m[][20], int F, int C, int puntos) {

    system("cls"); 

    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
    printf("\n< %i puntos obtenidos >\n", puntos * 15);
    
}

//ciclo para dejar el camino original sin afectaciones cada que avance el jugador en el camino

int vacio(char m[][20], int F, int C) {

    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            if (m[i][j] == '*') {
                return 0;
            }
        }
    }
    return 1;
}

//monstruos fantasma representados por M y N  

void bichos(char m[][20], int F, int C) {
    int i = 0, j = 0, x1 = C - 1, x2 = C - 1, y1 = 0, y2 = F - 1, k = 0;
    char c;
    int r;

    m[i][j] = 'V';
    m[y1][x1] = 'M';  
    m[y2][x2] = 'N';  

    while (1) {
        imprimir_m(m, F, C, k);

        
        m[y1][x1] = '*';
        m[y2][x2] = '*';

        if (vacio(m, F, C)) {
            printf("\nHaz Ganado!\n");
            exit(0);
        }


		//botones para moverse con w arriba, s abajo, a izquierda, d derecha
        if ((c = getchar()) != EOF) {
            m[i][j] = '*';
            switch (c) {
                case 'a': if (j > 0) j--; break;          
                case 'd': if (j < C - 1) j++; break;      
                case 'w': if (i > 0) i--; break;          
                case 's': if (i < F - 1) i++; break;      
                case 27: exit(0);                         
            }
            if (m[i][j] == '*') k++;
            m[i][j] = 'V'; 
        }
        
        
        //si llega a chocar con un mosntruo, el jugador pierde 
        if ((x1 == j && y1 == i) || (x2 == j && y2 == i)) {
            m[i][j] = 'X';
            imprimir_m(m, F, C, k);
            printf("**Perdiste!!**\n");
            exit(0);
        }

        if (rand() % 2) { if (x1 < C - 1) x1++; } else { if (x1 > 0) x1--; }
        if (rand() % 2) { if (y1 < F - 1) y1++; } else { if (y1 > 0) y1--; }
        m[y1][x1] = 'M';

        if (rand() % 2) { if (x2 < C - 1) x2++; } else { if (x2 > 0) x2--; }
        if (rand() % 2) { if (y2 < F - 1) y2++; } else { if (y2 > 0) y2--; }
        m[y2][x2] = 'N';
    }
}

int main() {
	system("color 01");
	printf("BIENVENIDOS AL JUEGO CLASICO PAC-MAN!\n");
	printf("\nPresiona 'w' para subir, 's' para bajar, 'a' para ir a la izquierda, 'd' para ir a la derecha");
    getch();
    musicapacman();
	char m[20][20];

    srand(time(NULL));

    generar_m(m, 10, 20); 
    bichos(m, 10, 20);
    musicapacman();

    return 0;
}
