#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW 3
#define COL 3

/*					TODO

- Bug na função checkWin(), vitoria atribuida ao valor default do caracter.
- Mudar os turnos e o character inserido no jogo.
- Verificar a ocupação ou não de uma posição

*/


//Functions
void updateBoard();
void drawBoard();
void clear();
int checkWin();

//Variables
char board[ROW][COL];

int main() {
	
	int xread, yread, run = 1;
	
	clear();
	drawBoard();
	
	do {
		printf("\nIntroduce values for X & Y (0 to 2): ");
		scanf("%d%d", &xread, &yread);
		
		board[xread][yread] = 'X';
		
		if(checkWin() != 0) {
			clear();
			updateBoard();
			
			printf("\nWin condition checked\n");
			run = 0;
		}		
		if (run != 0) {
			clear();
			updateBoard();
		}
		
	}while(run != 0);
	
	return 0;
}
void drawBoard() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			board[i][j] = '-';
			printf("|%c|", board[i][j]);
		}
		printf("\n");
	}
}
void updateBoard() {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			printf("|%c|", board[i][j]);
		}
		printf("\n");
	}
}
void clear() {
	char cmd[50];
	
	strcpy(cmd, "clear");
	system("clear");
}
int checkWin() {
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
		return 1;
	}
	if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2])) {
		return 1;
	}
	if ((board[0][0] == board[1][0]) && (board[1][0]) == board[2][0]) {
		return 1;
	}
	else {
		return 0;
	}	
}
