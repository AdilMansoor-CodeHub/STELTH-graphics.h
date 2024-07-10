#include <iostream>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
#include <fstream>
using namespace std;

int score = 0;
int page = 0;
int playerX = 300, playerY = 240;
int seconds = 20;
int timer = seconds * 1000;
int choice = 0;  
int x = 100, y = 100;

int enemyX = 290, enemyY = 320;
int enemy2X = 320, enemy2Y = 240;
int enemy3X = 320, enemy3Y = 300;
int enemy4X = 320, enemy4Y = 320;
int enemy5X = 290, enemy5Y = 290;

void menu() {
    setcolor(YELLOW);
    rectangle(50, 150, 150, 250);
    floodfill(100, 200, YELLOW);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	char enter[20];
	sprintf_s(enter, "PRESS ENTER TO PLAY");
	outtextxy(150, 150, enter);
	char esc[20];
	sprintf_s(esc, "PRESS ESC TO EXIT");
	outtextxy(150, 235, esc);
}
void map() {
	setlinestyle(SOLID_LINE, 0, 3);
	setcolor(GREEN);
	if (playerX >= 264 && playerX <= 274 && playerY >= 100 && playerY <= 200) {
		playerX = 264;
	}
	else if (playerX <= 290 && playerX >= 280 && playerY >= 100 && playerY <= 200) {
		playerX = 290;
	}
	if (playerY >= 265 && playerY <= 275 && playerX >= 220 && playerX <= 280) {
		playerY = 265;
	}
	line(280, 100, 280, 200);

	line(100, 100, 500, 100);

	line(280, 200, 220, 200);

	line(280, 150, 220, 150);

	line(220, 150, 220, 180);

	line(100, 160, 150, 160);

	line(130, 100, 130, 140);

	// left wall
	line(100, 100, 100, 400);

	// right wall
	line(500, 100, 500, 400);
	// bottom wall
	line(100, 400, 500, 400);

	//inside lines
	line(100, 250, 200, 250);
	line(100, 260, 200, 260);

	line(400, 250, 500, 250);
	line(100, 370, 130, 370);
	line(130, 370, 130, 300);

	line(450, 200, 500, 200);
	line(450, 150, 500, 150);

	line(330, 150, 420, 150);
	line(200, 360, 250, 360);

	// two lines middle (perp)
	line(375, 350, 375, 400);
	line(375, 150, 375, 300);
	if (playerY >= 150 && playerY <= 300 && playerX >= 365 && playerX <= 370) {
		playerX = 360;
	}
	if (playerY >= 150 && playerY <= 300 && playerX >= 370 && playerX <= 385) {
		playerX = 385;
	}
	if (enemyY >= 150 && enemyY <= 300 && enemyX >= 365 && enemyX <= 370) {
		enemyX = 360;
	}
	if (enemyY >= 150 && enemyY <= 300 && enemyX >= 370 && enemyX <= 385) {
		enemyX = 385;
	}
	if (enemy2Y >= 150 && enemy2Y <= 300 && enemy2X >= 365 && enemy2X <= 370) {
		enemy2X = 360;
	}
	if (enemy2Y >= 150 && enemy2Y <= 300 && enemy2X >= 370 && enemy2X <= 385) {
		enemy2X = 385;
	}
	if (enemy3Y >= 150 && enemy3Y <= 300 && enemy3X >= 365 && enemy3X <= 370) {
		enemy3X = 360;
	}
	if (enemy3Y >= 150 && enemy3Y <= 300 && enemy3X >= 370 && enemy3X <= 385) {
		enemy3X = 385;
	}


	if (enemy4Y >= 150 && enemy4Y <= 300 && enemy4X >= 365 && enemy4X <= 370) {
		enemy4X = 360;
	}
	if (enemy4Y >= 150 && enemy4Y <= 300 && enemy4X >= 370 && enemy4X <= 385) {
		enemy4X = 385;
	}
	if (enemy5Y >= 150 && enemy5Y <= 300 && enemy5X >= 365 && enemy5X <= 370) {
		enemy5X = 360;
	}
	if (enemy5Y >= 150 && enemy5Y <= 300 && enemy5X >= 370 && enemy5X <= 385) {
		enemy5X = 385;
	}

	line(150, 200, 150, 250);
	// horizontal line(bottom)
	line(430, 350, 470, 350);

	// three perpendicular lines (bottom)
	line(430, 300, 430, 350);
	line(470, 300, 470, 350);
	line(300, 300, 300, 350);

	// obstacle lines
	line(300, 300, 430, 300);
	line(280, 325, 300, 325);
	line(130, 325, 150, 325);


	line(470, 325, 490, 325);
	line(400, 325, 430, 325);

	//box
	line(200, 300, 450, 300);
	if (playerY >= 290 && playerY <= 300 && playerX >= 200 && playerX <= 450) {
		playerY = 290;
	}
	if (playerY >= 305 && playerY <= 320 && playerX >= 200 && playerX <= 450) {
		playerY = 320;
	}
	if (enemyY >= 290 && enemyY <= 300 && enemyX >= 200 && enemyX <= 450) {
		enemyY = 290;
	}
	if (enemyY >= 305 && enemyY <= 320 && enemyX >= 200 && enemyX <= 450) {
		enemyY = 320;
	}

	if (enemy2Y >= 290 && enemy2Y <= 300 && enemy2X >= 200 && enemy2X <= 450) {
		enemy2Y = 290;
	}
	if (enemy2Y >= 305 && enemy2Y <= 320 && enemy2X >= 200 && enemy2X <= 450) {
		enemy2Y = 320;
	}

	if (enemy3Y >= 290 && enemy3Y <= 300 && enemy3X >= 200 && enemy3X <= 450) {
		enemy3Y = 290;
	}
	if (enemy3Y >= 305 && enemy3Y <= 320 && enemy3X >= 200 && enemy3X <= 450) {
		enemy3Y = 320;
	}

	if (enemy4Y >= 290 && enemy4Y <= 300 && enemy4X >= 200 && enemy4X <= 450) {
		enemy4Y = 290;
	}
	if (enemy4Y >= 305 && enemy4Y <= 320 && enemy4X >= 200 && enemy4X <= 450) {
		enemy4Y = 320;
	}

	if (enemy5Y >= 290 && enemy5Y <= 300 && enemy5X >= 200 && enemy5X <= 450) {
		enemy5Y = 290;
	}
	if (enemy5Y >= 305 && enemy5Y <= 320 && enemy5X >= 200 && enemy5X <= 450) {
		enemy5Y = 320;
	}
	line(200, 300, 200, 330);
	line(200, 330, 230, 330);
	line(230, 330, 230, 310);

	//box
	line(260, 300, 260, 250);
	line(260, 250, 300, 250);

	line(300, 250, 300, 285);

	line(250, 300, 250, 380);
	line(350, 330, 350, 380);

	line(350, 340, 370, 340);

}
void time() {
	char timerText[20];
	sprintf_s(timerText, "Timer: %d seconds", timer / 1000);
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(170, 70, timerText);
	timer -= 100;
}
void drawPlayer() {
	setcolor(GREEN);
	circle(playerX, playerY, 10);
	floodfill(playerX, playerY, GREEN);

	if (playerY >= 390) {
		playerY = 390;
	}
	else if (playerY <= 110) {
		playerY = 110;
	}
	else if (playerX <= 110) {
		playerX = 110;
	}
	else if (playerX >= 490) {
		playerX = 490;
	}
}
void enemy() {
	setcolor(RED);
	circle(enemyX, enemyY, 5);
	floodfill(enemyX, enemyY, RED);

	if (enemyY >= 390) {
		enemyY = 390;
	}
	else if (enemyY <= 110) {
		enemyY = 110;
	}
	else if (enemyX <= 110) {
		enemyX = 110;
	}
	else if (enemyX >= 490) {
		enemyX = 490;
	}
	int randomDirection = rand() % 4;
	switch (randomDirection) {
	case 0:  // Up
		enemyY -= 5;
		enemyY -= 5;
		enemyY -= 5;
		break;
	case 1:  // Down
		enemyY += 5;
		enemyY += 5;
		enemyY += 5;
		break;
	case 2:  // Left
		enemyX -= 5;
		enemyX -= 5;
		enemyX -= 5;
		break;
	case 3:  // Right
		enemyX += 5;
		enemyX += 5;
		enemyX += 5;
		break;
	}
}
void enemy2() {
	setcolor(RED);
	circle(enemy2X, enemy2Y, 5);
	floodfill(enemy2X, enemy2Y, RED);

	if (enemy2Y >= 390) {
		enemy2Y = 390;
	}
	else if (enemy2Y <= 110) {
		enemy2Y = 110;
	}
	else if (enemy2X <= 110) {
		enemy2X = 110;
	}
	else if (enemy2X >= 490) {
		enemy2X = 490;
	}

	int randomDirection = rand() % 4;
	switch (randomDirection) {
	case 0:  // Up
		enemy2Y -= 5;
		delay(10);
		enemy2Y -= 5;
		delay(10);
		enemy2Y -= 5;
		break;
	case 1:  // Down
		enemy2Y += 5;
		delay(10);
		enemy2Y += 5;
		delay(10);
		enemy2Y += 5;
		break;
	case 2:  // Left
		enemy2X -= 5;
		delay(10);
		enemy2X -= 5;
		delay(10);
		enemy2X -= 5;
		delay(10);
		break;
	case 3:  // Right
		enemy2X += 5;
		delay(10);
		enemy2X += 5;
		delay(10);
		enemy2X += 5;
		delay(10);
		break;
	}
}
void enemy3() {
	setcolor(RED);
	circle(enemy3X, enemy3Y, 5);
	floodfill(enemy3X, enemy3Y, RED);

	if (enemy3Y >= 390) {
		enemy3Y = 390;
	}
	else if (enemy3Y <= 110) {
		enemy3Y = 110;
	}
	else if (enemy3X <= 110) {
		enemy3X = 110;
	}
	else if (enemy3X >= 490) {
		enemy3X = 490;
	}

	int randomDirection = rand() % 4;
	switch (randomDirection) {
	case 0:  // Up
		enemy3Y -= 5;
		delay(10);
		enemy3Y -= 5;
		delay(10);
		enemy3Y -= 5;
		break;
	case 1:  // Down
		enemy3Y += 5;
		delay(10);
		enemy3Y += 5;
		delay(10);
		enemy3Y += 5;
		break;
	case 2:  // Left
		enemy3X -= 5;
		delay(10);
		enemy3X -= 5;
		delay(10);
		enemy3X -= 5;
		delay(10);
		break;
	case 3:  // Right
		enemy3X += 5;
		delay(10);
		enemy3X += 5;
		delay(10);
		enemy3X += 5;
		delay(10);
		break;
	}
};
void enemy4() {
	setcolor(RED);
	circle(enemy4X, enemy4Y, 5);
	floodfill(enemy4X, enemy4Y, RED);
	if (enemy4Y >= 390) {
		enemy4Y = 390;
	}
	else if (enemy4Y <= 110) {
		enemy4Y = 110;
	}
	else if (enemy4X <= 110) {
		enemy4X = 110;
	}
	else if (enemy4X >= 490) {
		enemy4X = 490;
	}

	int randomDirection = rand() % 4;
	switch (randomDirection) {
	case 0:  // Up
		enemy4Y -= 5;
		delay(10);
		enemy4Y -= 5;
		delay(10);
		enemy4Y -= 5;
		break;
	case 1:  // Down
		enemy4Y += 5;
		delay(10);
		enemy4Y += 5;
		delay(10);
		enemy4Y += 5;
		break;
	case 2:  // Left
		enemy4X -= 5;
		delay(10);
		enemy4X -= 5;
		delay(10);
		enemy4X -= 5;
		delay(10);
		break;
	case 3:  // Right
		enemy4X += 5;
		delay(10);
		enemy4X += 5;
		delay(10);
		enemy4X += 5;
		delay(10);
		break;
	}
}
void enemy5() {
	setcolor(RED);
	circle(enemy5X, enemy5Y, 5);
	floodfill(enemy5X, enemy5Y, RED);

	if (enemy5Y >= 390) {
		enemy5Y = 390;
	}
	else if (enemy5Y <= 110) {
		enemy5Y = 110;
	}
	else if (enemy5X <= 110) {
		enemy5X = 110;
	}
	else if (enemy5X >= 490) {
		enemy5X = 490;
	}

	int randomDirection = rand() % 4;
	switch (randomDirection) {
	case 0:  // Up
		enemy5Y -= 5;
		delay(10);
		enemy5Y -= 5;
		delay(10);
		enemy5Y -= 5;
		break;
	case 1:  // Down
		enemy5Y += 5;
		delay(10);
		enemy5Y += 5;
		delay(10);
		enemy5Y += 5;
		break;
	case 2:  // Left
		enemy5X -= 5;
		delay(10);
		enemy5X -= 5;
		delay(10);
		enemy5X -= 5;
		delay(10);
		break;
	case 3:  // Right
		enemy5X += 5;
		delay(10);
		enemy5X += 5;
		delay(10);
		enemy5X += 5;
		delay(10);
		break;
	}
}

int main() {
    ofstream outputFile;
    outputFile.open("data.txt");
    initwindow(600, 600);

    while (1) {
        setactivepage(page);
        setvisualpage(1 - page);
        cleardevice();
		char stealth[10];
		sprintf_s(stealth, "STEALTH");
		outtextxy(220, 40, stealth);
        if (choice == 0) {
            menu();
            if (GetAsyncKeyState(VK_RETURN)) {
                choice = 1;
                delay(500);  
            }
			if (GetAsyncKeyState(VK_ESCAPE)) {
				closegraph();
				break;
			}
        }
        else if (choice == 1) {
            time();
            map();
            if (abs(playerX - enemyX) < 20 && abs(playerY - enemyY) < 20) {
                enemyX = -1;
                score = score + 2;
            }
            if (abs(playerX - enemy2X) < 20 && abs(playerY - enemy2Y) < 20) {
                enemy2X = -1;
                score = score + 2;
            }
            if (abs(playerX - enemy3X) < 20 && abs(playerY - enemy3Y) < 20) {
                enemy3X = -1;
                score = score + 2;
            }
            if (abs(playerX - enemy4X) < 20 && abs(playerY - enemy4Y) < 20) {
                enemy4X = -1;
                score = score + 2;
            }
            if (abs(playerX - enemy5X) < 20 && abs(playerY - enemy5Y) < 20) {
                enemy5X = -1;
                score = score + 2;
            }

            if (enemyX != -1) {
                enemy();
            }
            if (enemy2X != -1) {
                enemy2();
            }
            if (enemy3X != -1) {
                enemy3();
            }
            if (enemy4X != -1) {
                enemy4();
            }
			if (enemy5X != -1) {
				enemy5();
			}

            if (enemyX == -1) {
                delay(15);
            }
            if (enemy2X == -1) {
                delay(15);
            }
            if (enemy3X == -1) {
                delay(15);
            }
            if (enemy4X == -1) {
                delay(15);
            }
            if (enemy5X == -1) {
                delay(15);
            }
            drawPlayer();
            if (GetAsyncKeyState(VK_UP)) {
                playerY = playerY - 10;
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                playerY = playerY + 10;
            }
            if (GetAsyncKeyState(VK_RIGHT)) {
                playerX = playerX + 10;
            }
			if (GetAsyncKeyState(VK_LEFT)) {
				playerX = playerX - 10;
			}

            if (playerY >= 400) {
                playerY = 399;
            }
            if (timer == 0) {
                break;
            }
			if (score == 10) {
				char win[20];
				sprintf_s(win, "YOU WIN");
				outtextxy(240, 10, win);
			}
        }
        page = 1 - page;
        setcolor(RED);
        outputFile << "score: " << score << endl;
    }
    outputFile.close();
    char timerText[20];
    sprintf_s(timerText, "Timer: 0 seconds");
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(150, 50, timerText);
    getch();
    closegraph();
    return 0;






	// 600 lines yeaaaaaaaahhhh
}
