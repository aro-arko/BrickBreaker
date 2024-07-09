#include "graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void brickColor();
void ChangeBrick(int, int);
void strikePad(int);
void removeStrikePad(int);
void ballPosition(int, int);
int level = 1;


int a[80] = {0};
int bricks[8][10] = { 0 };

int main(){

	int random, ranDir;
	int gd = DETECT, gm;
	int posX = 650;
	int ballX = 650, ballY = 635;
	int count = 0;
	int Xcoll = 0, Ycollup = 0, Ycolldown = 0;
	int brickX, brickY;



	initgraph(&gd, &gm, "C:\\TC\\BGI"); // Initilize graph
	initwindow(1366, 710);

	settextstyle(0, HORIZ_DIR, 1);
	int x = 10, b = 200;
	setcolor(WHITE);
	outtextxy(200, b += x, " ______  # ______  # _____ #  ______ # _    _ #  # ______  # ______  # _______ #        # _    _ # _______ # ______  #");
	outtextxy(200, b += x, "(____  \\ #(_____ \\ #(_____)# / _____)#| |  / )#  #(____  \\ #(_____ \\ #(_______)#   /\\   #| |  / )#(_______)#(_____ \\\ #");
	outtextxy(200, b += x, " ____)  )# _____) )#   _   #| /      #| | / / #  # ____)  )# _____) )# _____   #  /  \\  #| | / / # _____   # _____) )#");
	outtextxy(200, b += x, "|  __  ( #(_____ ( #  | |  #| |      #| |< <  #  #|  __  ( #(_____ ( #|  ___)  # / /\\ \\ #| |< <  #|  ___)  #(_____ ( #");
	outtextxy(200, b += x, "| |__)  )#      | |# _| |_ #| \\_____ #| | \\ \\ #  #| |__)  )#      | |#| |_____ #| |__| |#| | \\ \\ #| |_____ #      | |#");
	outtextxy(200, b += x, "|______/ #      |_|#(_____)# \\______)#|_|  \\_)#  #|______/ #      |_|#|_______)#|______|#|_|  \\_)#|_______)#      |_|#");

	settextstyle(0, HORIZ_DIR, 2);
	outtextxy(500, b += 4 * x, "INSTRUCTIONS");
	outtextxy(500, b += 2 * x, "------------");
	outtextxy(200, b += 2 * x, "1. Click the Left Mouse button to start the game.");
	outtextxy(200, b += 2 * x, "2. Hit the ball with strike Pad to keep it in the sceen.");
	outtextxy(200, b += 2 * x, "3. Hit the bricks following times to destroy them.");

	setfillstyle(SOLID_FILL, BLACK); //fill styles with fill style color
	rectangle(200, b += 4 * x, 300, b + 2 * x);
	floodfill(250, b + 3, WHITE);

	setfillstyle(SOLID_FILL, GREEN); //fill styles with fill style color
	rectangle(400, b, 500, b + 2 * x);
	floodfill(450, b + 3, WHITE);

	setfillstyle(SOLID_FILL, RED); //fill styles with fill style color
	rectangle(600, b, 700, b + 2 * x);
	floodfill(650, b + 3, WHITE);

	setfillstyle(SOLID_FILL, BLUE); //fill styles with fill style color
	rectangle(800, b, 900, b + 2 * x);
	floodfill(850, b + 3, WHITE);

	outtextxy(200, b += 3 * x, "4 TIMES");
	outtextxy(400, b, "3 TIMES");
	outtextxy(600, b, "2 TIMES");
	outtextxy(800, b, "1 TIME");

	outtextxy(200, b += 4 * x, "4. Destroy all the bricks to complete a level. There are 3 levels");

	getch();
	cleardevice();

	while (level < 4){

		posX = 650;
		ballX = 650, ballY = 635;
		count = 0;
		cleardevice();

		if (level == 1){
			a[1] = 1, a[2] = 1, a[3] = 1, a[4] = 1, a[5] = 1;
			a[6] = 1, a[7] = 1, a[8] = 1, a[9] = 1, a[10] = 1;
			a[11] = 1, a[12] = 1;
		}


		else
		if (level == 2){
			a[1] = 1, a[2] = 1, a[3] = 1, a[4] = 1, a[5] = 1, a[6] = 1, a[7] = 1, a[8] = 1, a[9] = 1, a[10] = 1;
			a[11] = 1, a[12] = 1, a[13] = 2, a[14] = 1, a[15] = 1, a[16] = 1, a[17] = 2, a[18] = 2, a[19] = 1, a[20] = 1;
			a[21] = 1, a[22] = 1, a[23] = 3, a[24] = 3, a[25] = 2, a[26] = 1, a[27] = 1, a[28] = 1, a[29] = 1, a[30] = 2;
			a[31] = 1, a[32] = 1, a[33] = 3, a[34] = 1, a[35] = 1, a[36] = 1, a[37] = 1, a[38] = 1, a[39] = 1, a[40] = 1;

		}
		else
		if (level == 3){
			a[1] = 1, a[2] = 2, a[3] = 2, a[4] = 2, a[5] = 2, a[6] = 2, a[7] = 2, a[8] = 2, a[9] = 2, a[10] = 1;
			a[11] = 1, a[12] = 2, a[13] = 1, a[14] = 1, a[15] = 1, a[16] = 1, a[17] = 1, a[18] = 1, a[19] = 2, a[20] = 1;
			a[21] = 1, a[22] = 1, a[23] = 1, a[24] = 1, a[25] = 2, a[26] = 1, a[27] = 1, a[28] = 1, a[29] = 1, a[30] = 1;
			a[31] = 1, a[32] = 1, a[33] = 1, a[34] = 1, a[35] = 2, a[36] = 1, a[37] = 1, a[38] = 1, a[39] = 1, a[40] = 1;
			a[41] = 1, a[42] = 2, a[43] = 1, a[44] = 4, a[45] = 4, a[46] = 1, a[47] = 1, a[48] = 1, a[49] = 1, a[50] = 1;
	
		}
		else
		if (level == 4){
			a[1] = 2, a[2] = 2, a[3] = 1, a[4] = 2, a[5] = 2, a[6] = 2, a[7] = 2, a[8] = 1, a[9] = 2, a[10] = 1;
			a[11] = 3, a[12] = 2, a[13] = 1, a[14] = 1, a[15] = 1, a[16] = 1, a[17] = 1, a[18] = 1, a[19] = 2, a[20] = 1;
			a[21] = 4, a[22] = 1, a[23] = 1, a[24] = 3, a[25] = 2, a[26] = 1, a[27] = 1, a[28] = 3, a[29] = 3, a[30] = 1;
			a[31] = 2, a[32] = 2, a[33] = 2, a[34] = 2, a[35] = 1, a[36] = 2, a[37] = 1, a[38] = 1, a[39] = 2, a[40] = 1;
			a[41] = 1, a[42] = 1, a[43] = 1, a[44] = 1, a[45] = 2, a[46] = 1, a[47] = 1, a[48] = 3, a[49] = 3, a[50] = 1;
	
		}
		else
		if (level == 5){
			a[1] = 1, a[2] = 2, a[3] = 2, a[4] = 2, a[5] = 2, a[6] = 2, a[7] = 2, a[8] = 2, a[9] = 2, a[10] = 1;
			a[11] = 1, a[12] = 2, a[13] = 1, a[14] = 1, a[15] = 1, a[16] = 1, a[17] = 1, a[18] = 1, a[19] = 2, a[20] = 1;
			a[21] = 1, a[22] = 3, a[23] = 4, a[24] = 4, a[25] = 4, a[26] = 4, a[27] = 4, a[28] = 3, a[29] = 3, a[30] = 1;
			a[31] = 1, a[32] = 2, a[33] = 4, a[34] = 4, a[35] = 4, a[36] = 4, a[37] = 4, a[38] = 1, a[39] = 2, a[40] = 1;
			a[41] = 1, a[42] = 3, a[43] = 4, a[44] = 4, a[45] = 4, a[46] = 4, a[47] = 4, a[48] = 3, a[49] = 3, a[50] = 1;
	
		}
		else
		if (level == 6){
			a[1] = 1, a[2] = 2, a[3] = 2, a[4] = 2, a[5] = 2, a[6] = 2, a[7] = 2, a[8] = 2, a[9] = 2, a[10] = 1;
			a[11] = 1, a[12] = 2, a[13] = 1, a[14] = 1, a[15] = 1, a[16] = 1, a[17] = 1, a[18] = 1, a[19] = 2, a[20] = 1;
			a[21] = 2, a[22] = 3, a[23] = 3, a[24] = 4, a[25] = 4, a[26] = 4, a[27] = 4, a[28] = 3, a[29] = 3, a[30] = 1;
			a[31] = 2, a[32] = 1, a[33] = 4, a[34] = 4, a[35] = 4, a[36] = 3, a[37] = 3, a[38] = 1, a[39] = 2, a[40] = 1;
			a[41] = 4, a[42] = 3, a[43] = 3, a[44] = 3, a[45] = 3, a[46] = 4, a[47] = 4, a[48] = 3, a[49] = 3, a[50] = 1;
	
		}
		else
		if (level == 7){
			a[1] = 1, a[2] = 2, a[3] = 2, a[4] = 2, a[5] = 2, a[6] = 2, a[7] = 2, a[8] = 2, a[9] = 2, a[10] = 1;
			a[11] = 1, a[12] = 2, a[13] = 1, a[14] = 1, a[15] = 1, a[16] = 1, a[17] = 1, a[18] = 1, a[19] = 2, a[20] = 3;
			a[21] = 1, a[22] = 3, a[23] = 2, a[24] = 2, a[25] = 4, a[26] = 4, a[27] = 4, a[28] = 3, a[29] = 3, a[30] = 3;
			a[31] = 1, a[32] = 2, a[33] = 3, a[34] = 2, a[35] = 4, a[36] = 4, a[37] = 4, a[38] = 1, a[39] = 2, a[40] = 3;
			a[41] = 1, a[42] = 3, a[43] = 3, a[44] = 2, a[45] = 4, a[46] = 4, a[47] = 4, a[48] = 3, a[49] = 3, a[50] = 3;
	
		}
		else
		if (level == 8){
			a[1] = 2, a[2] = 2, a[3] = 2, a[4] = 2, a[5] = 2, a[6] = 2, a[7] = 2, a[8] = 2, a[9] = 2, a[10] = 1;
			a[11] = 2, a[12] = 2, a[13] = 2, a[14] = 1, a[15] = 1, a[16] = 2, a[17] = 2, a[18] = 1, a[19] = 2, a[20] = 1;
			a[21] = 2, a[22] = 3, a[23] = 4, a[24] = 4, a[25] = 4, a[26] = 4, a[27] = 4, a[28] = 3, a[29] = 3, a[30] = 4;
			a[31] = 2, a[32] = 2, a[33] = 4, a[34] = 4, a[35] = 4, a[36] = 4, a[37] = 2, a[38] = 1, a[39] = 2, a[40] = 1;
			a[41] = 2, a[42] = 3, a[43] = 4, a[44] = 4, a[45] = 4, a[46] = 4, a[47] = 4, a[48] = 3, a[49] = 3, a[50] = 4;
	
		}

		int x = 1;
		for (int i = 0; i < 8; i++){
			for (int z = 0; z < 10; z++){
				bricks[i][z] = a[x];
				x++;
			}
		}

		brickColor();
		strikePad(posX);
		ballPosition(ballX, ballY);

		srand(time(NULL));
		random = 1;
		ranDir = rand() % 2;

		Xcoll = 0, Ycollup = 0, Ycolldown = 0;

		while (ballY < 710){
			count = 0;
			for (int row = 0; row < 8; row++){
				for (int col = 0; col < 10; col++){
					brickY = 50 + (row * 30);
					if (row % 2 == 0){
						brickX = 100 + (col * 110);
					}
					else if (row % 2 == 1){
						brickX = 160 + (col * 110);
					}

					if (((ballY + 13) == brickY) && (ballX) >= brickX && (ballX) <= brickX + 110){
						if (bricks[row][col] != 0){
							bricks[row][col]--;
							cleardevice();
							strikePad(posX);
							brickColor();
							Ycolldown = 1;
							Ycollup = 0;
							break;
						}
					}

					else if (((ballY - 15) == brickY + 30) && (ballX) >= brickX && (ballX) <= brickX + 110){
						if (bricks[row][col] != 0){
							bricks[row][col]--;
							cleardevice();
							strikePad(posX);
							brickColor();
							Ycollup = 1;
							Ycolldown = 0;
							break;
						}
					}

					else if (((ballX - 13) == brickX + 110) && (ballY) >= brickY && (ballY) <= brickY + 30){
						if (bricks[row][col] != 0){
							bricks[row][col]--;
							cleardevice();
							strikePad(posX);
							brickColor();
							Xcoll = 1;
							ranDir = 1;
							break;
						}
					}
					else if (((ballX + 13) == brickX) && (ballY) >= brickY && (ballY) <= brickY + 30){
						if (bricks[row][col] != 0){
							bricks[row][col]--;
							cleardevice();
							strikePad(posX);
							brickColor();
							Xcoll = 1;
							ranDir = 0;
							break;
						}
					}
					if (bricks[row][col] == 0){
						count++;
					}

				}

			}
			if (count >= 80){
				settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
				if (level == 1){
					outtextxy(500, 500, "LEVEL 1 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 2){
					outtextxy(500, 500, "LEVEL 2 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 3){
					outtextxy(500, 500, "LEVEL 3 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 4){
					outtextxy(500, 500, "LEVEL 4 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 5){
					outtextxy(500, 500, "LEVEL 5 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 6){
					outtextxy(500, 500, "LEVEL 6 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 7){
					outtextxy(500, 500, "LEVEL 7 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				if (level == 8){
					outtextxy(500, 500, "LEVEL 8 COMPLETE");
					outtextxy(250, 550, "PRESS ENTER TO PROCEED TO THE NEXT LEVEL");
				}
				level++;
				getch();
				break;
			}

			bool click = ismouseclick(WM_LBUTTONDOWN);
			if (click == 1){
				if (ballY <= 12 || Ycollup == 1){
					ballY += 1;
					Ycollup = 1;
					Ycolldown = 0;
					if (ballY >= 634 && ballX > posX - 80 && ballX < posX + 80){
						if (ballX <= posX - 80){
							random = 3;
							ranDir = 1;
						}
						else if (ballX <= posX - 40){
							random = 2;
							ranDir = 1;
						}
						else if (ballX <= posX + 40){
							random = 2;
							ranDir = 0;
						}
						else if (ballX <= posX + 80){
							random = 3;
							ranDir = 0;
						}

						Ycolldown = 1;
						Ycollup = 0;
					}
				}
				if (ballY > 12 && (Ycollup == 0 || Ycolldown == 1)){
					ballY -= 1;
				}


				if (Xcoll == 0){
					if (ranDir == 0){
						if (ballX < 1354){
							ballPosition(ballX += random, ballY);
						}
						if (ballX >= 1354){
							ballPosition(ballX -= random, ballY);
							Xcoll = 1;
						}
					}
					else if (ranDir == 1){
						if (ballX > 12){
							ballPosition(ballX -= random, ballY);
						}
						if (ballX <= 12){
							ballPosition(ballX += random, ballY);
							Xcoll = 1;
						}
					}
				}
				else if (Xcoll == 1){
					if (ranDir == 0){
						if (ballX > 12){
							ballPosition(ballX -= random, ballY);
						}
						if (ballX <= 12){
							ballPosition(ballX += random, ballY);
							Xcoll = 0;
						}
					}
					else if (ranDir == 1){
						if (ballX < 1354){
							ballPosition(ballX += random, ballY);
						}
						if (ballX >= 1354){
							ballPosition(ballX -= random, ballY);
							Xcoll = 0;
						}
					}
				}

			}

			int move = 0;
			if (kbhit()){
				move = getch();
			}
			if (move == KEY_RIGHT){
				if (posX <= 1250){
					removeStrikePad(posX);
					strikePad(posX += 70);
				}
			}
			else if (move == KEY_LEFT){
				if (posX >= 120){
					removeStrikePad(posX);
					strikePad(posX -= 70);
				}
			}
		}
		if (count < 80){
			settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
			outtextxy(500, 500, "GAME OVER");
			break;
			exit(0);
		}
	}
	getch();
	closegraph();
}

void brickColor(){

	int top = 50;
	int right = 100;
	for (int row = 0; row < 8; row++){
		for (int col = 0; col < 10; col++){

			if (bricks[row][col] == 1){
				setfillstyle(SOLID_FILL, BLUE); //fill styles with fill style color
				rectangle(right, top, right + 110, top + 30);
				floodfill(right + 100, top + 15, WHITE);
			}
			else if (bricks[row][col] == 2){
				setfillstyle(SOLID_FILL, RED); //fill styles with fill style color
				rectangle(right, top, right + 110, top + 30);
				floodfill(right + 100, top + 15, WHITE);
			}
			else if (bricks[row][col] == 3){
				setfillstyle(SOLID_FILL, GREEN); //fill styles with fill style color
				rectangle(right, top, right + 110, top + 30);
				floodfill(right + 100, top + 15, WHITE);
			}
			else if (bricks[row][col] == 4){
				setfillstyle(SOLID_FILL, BROWN); //fill styles with fill style color
				rectangle(right, top, right + 110, top + 30);
				floodfill(right + 100, top + 15, WHITE);
			}
			right += 110;
		}
		top += 30;
		if (row % 2 == 0){
			right = 160;
		}
		else if (row % 2 == 1){
			right = 100;
		}

	}

}

void ChangeBrick(int row, int col){

	int left = 50 + (col * 110);
	int right = left + 110;
	int top = 50 + (row * 30);
	int bottom = top + 30;
	int color;


	if (bricks[row][col] == 0){
		setfillstyle(SOLID_FILL, BLACK); //fill styles with fill style color
		rectangle(right, top, left, bottom);
		floodfill(right + 100, top + 15, WHITE);
	}
	else if (bricks[row][col] == 1){
		setfillstyle(SOLID_FILL, BLUE); //fill styles with fill style color
		rectangle(right, top, left, bottom);
		floodfill(right + 100, top + 15, WHITE);
	}
	else if (bricks[row][col] == 2){
		setfillstyle(SOLID_FILL, RED); //fill styles with fill style color
		rectangle(right, top, left, bottom);
		floodfill(right + 100, top + 15, WHITE);
	}

}

void strikePad(int posX){
	setfillstyle(SOLID_FILL, 4); //fill styles with fill style color
	rectangle(posX - 70, 650, posX + 70, 680);
	floodfill(posX, 665, WHITE);

	setfillstyle(SOLID_FILL, 15); //fill styles with fill style color
	sector(posX - 70, 665, 90, 270, 15, 15);
	floodfill(posX - 75, 665, WHITE);
	setfillstyle(SOLID_FILL, 15); //fill styles with fill style color
	sector(posX + 70, 665, 270, 90, 15, 15);
	floodfill(posX + 75, 665, WHITE);

}

void removeStrikePad(int posX){
	setfillstyle(SOLID_FILL, BLACK); //fill styles with fill style color
	rectangle(posX - 70, 650, posX + 70, 680);
	floodfill(posX, 650, BLACK);
}

void ballPosition(int x, int y){

	setfillstyle(SOLID_FILL, BLACK); //fill styles with fill style color
	circle(x, y, 12);
	floodfill(x, y, BLACK);
	setfillstyle(SOLID_FILL, WHITE); //fill styles with fill style color
	circle(x, y, 12);
	floodfill(x, y, WHITE);
	Sleep(1);
}