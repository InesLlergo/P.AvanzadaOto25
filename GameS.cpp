#include <stdio.h>
#include <conio.h> 
#include <stdlib.h> 
#include <time.h>  
#include <windows.h>
//aqui mostramos la musica de para elisa para el jueg0 snake
void musicaparaelisa(){
	Beep(659, 250);
    Sleep(150);
    Beep(622, 250); 
    Sleep(150);
    Beep(659, 250); 
    Sleep(150);
    Beep(622, 250);
    Sleep(150);
    Beep(659, 250); 
    Sleep(150);
    Beep(494, 250); 
    Sleep(150);
    Beep(587, 250); 
    Sleep(150);
    Beep(523, 250); 
    Sleep(150);
    Beep(440, 500);
    Sleep(300);

    Beep(262, 250); 
    Sleep(150);
    Beep(330, 250); 
    Sleep(150);
    Beep(440, 250); // A
    Sleep(150);
    Beep(494, 250); // B
    Sleep(150);
    Beep(330, 250); // E
    Sleep(150);
    Beep(415, 250); // G#
    Sleep(150);
    Beep(494, 250); // B
    Sleep(150);
    Beep(523, 250); // C
    Sleep(300);

    // Repetición de la primera parte
    Beep(659, 250); // E
    Sleep(150);
    Beep(622, 250); // D#
    Sleep(150);
    Beep(659, 250); // E
    Sleep(150);
    Beep(622, 250); // D#
    Sleep(150);
    Beep(659, 250); // E
    Sleep(150);
    Beep(494, 250); // B
    Sleep(150);
    Beep(587, 250); // D
    Sleep(150);
    Beep(523, 250); // C
    Sleep(150);
    Beep(440, 500); // A
}

//declaracion de las variables que se usaran en el programa para el juego

bool gameover;
const int width = 20;
const int height = 17;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; 
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; 
eDirection dir;

void Setup() {
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width; 
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
}

void Draw() {
    system("cls"); 
    for(int i = 0; i < width + 2; i++)
        printf("|");
    printf("\n");

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printf("|"); 

            if (i == y && j == x)
                printf("*"); 
            else if (i == fruitY && j == fruitX)
                printf("%"); 
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("*"); 
                        print = true;
                    }
                }
                if (!print)
                    printf(" ");
            }

            if (j == width - 1)
                printf("|");
        }
        printf("\n");
    }

    for (int i = 0; i < width + 2; i++)
        printf("|");
    printf("\n");
    printf("Score: %d\n", score);
}

void Input() {
    if (_kbhit()) { 
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}
//aqui es la parte para mover a la serpiente
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameover = true;
    }

    if (x==fruitX&&y==fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main() {
	system("color 0A");
	printf("Bienvenido al juego clasico Snake!\nPropuesta de juego por Norma Ines Llergo Sanchez\n");
	printf("\nPresione 'w' para subir, 's' para bajar, 'a' para ir a la izquierda, o 'd' para ir a la derehca y coleccionar el punto");
	getch();
	
	musicaparaelisa();
    srand(time(0)); 
    Setup();
    while (!gameover) {
        Draw();
        Input();
        Logic();
    }
    
}

