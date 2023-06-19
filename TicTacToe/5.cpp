/*
日期:2022/12/30
學號:1080729
姓名:黃國安
*/
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

#define ROW 3 
#define COL 3

void draw(char num[ROW][COL]);
void initial_num(char num[ROW][COL]);
void player(char num[ROW][COL], int a, int b);
void computer(char num[ROW][COL]);
char isEnd(char num[ROW][COL]);

void main(void)
{
	int a, b;
	char num[ROW][COL];
	char replay = 'y';
	while (replay=='y') {
		initial_num(num);
		draw(num);
		while (isEnd(num)=='n') {
			cout << "玩家下棋位置:";
			cin >> a >> b;
			player(num, a, b);
			if (isEnd(num)=='o'){
				draw(num);
				cout << "You win!!\n";
				break;
			}
			if (isEnd(num) == '=') {
				draw(num);
				cout << "平局!!\n";
				break;
			}
			computer(num);
			if (isEnd(num) == 'x') {
				draw(num);
				cout << "You lose!!\n";
				break;
			}
			draw(num);
		}
		cout << "再玩一次? (y/n):";
		cin >> replay;
	}
	system("pause");
}

char isEnd(char num[ROW][COL]) {
	//判斷列
	for (int i = 0; i < 3; i++){
		if (num[i][0] == num[i][1] && num[i][1] == num[i][2]) {
			if (num[i][0]=='o') {
				return 'o';
			}
			if (num[i][0] == 'x') {
				return 'x';
			}
		}
	}
	//判斷行
	for (int i = 0; i < 3; i++) {
		if (num[0][i] == num[1][i] && num[1][i] == num[2][i]) {
			if (num[0][i] == 'o') {
				return 'o';
			}
			if (num[0][i] == 'x') {
				return 'x';
			}
		}
	}
	//判斷對角
	if ((num[0][0] == num[1][1] && num[1][1] == num[2][2]) || (num[0][2] == num[1][1] && num[1][1] == num[2][0])) {
		if (num[1][1] == 'o') {
			return 'o';
		}
		if (num[1][1] == 'x') {
			return 'x';
		}
	}
	//繼續
	bool is_full = true;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (num[i][j]==' ') {
				is_full = false;
				return 'n';
			}
		}
	}
	//滿了 平手
	if (is_full){
		return '=';
	}
}

void computer(char num[ROW][COL]) {
	//進攻
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (num[i][j]==' '){
				num[i][j] = 'x';
				if (isEnd(num)=='x'){
					return;
				}else {
					num[i][j] = ' ';
				}
			}
		}
	}
	//防守
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (num[i][j] == ' ') {
				num[i][j] = 'o';
				if (isEnd(num) == 'o') {
					num[i][j] = 'x';
					return;
				}
				else {
					num[i][j] = ' ';
				}
			}
		}
	}
	//隨機
	srand(time(NULL));
	int a = rand() % 3;
	int b = rand() % 3;
	while (num[a][b] != ' ') {
		a = rand() % 3;
		b = rand() % 3;
	}
	num[a][b] = 'x';
}

void player(char num[ROW][COL], int a, int b) {
	if(num[a-1][b-1] == ' ') {
		num[a-1][b-1] = 'o';
	}
	else {
		cout << "Error!!\n";
		cout << "玩家下棋位置:";
		cin >> a >> b;
		player(num, a, b);
	}
}

void draw(char num[ROW][COL]) {
	cout << "  1   2   3\n";
	for (int i = 0; i < 3; i++){
		cout << i + 1;
		for (int j = 0; j < 3; j++){
			cout << " " << num[i][j] << " ";
			if (j<2){
				cout << "|";
			}
		}
		if (i<2){
			cout << "\n ---|---|---\n";
		}
	}
	cout << endl;
}

void initial_num(char num[ROW][COL]) {
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			num[i][j] = ' ';
		}
	}
}