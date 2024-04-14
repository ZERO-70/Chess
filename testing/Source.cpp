#include<iostream>
#include"Header.h"
#include<Windows.h>
#include<fstream>
#include <filesystem>
using namespace std;
enum COLOR {
	BLACK,
	WHITE,
};
struct pieces {
	COLOR color;
	char sym;
	string playername;
};

bool candocastling(pieces* board[][8], int sr, int sc, int dr, int dc, int turn, bool candopawnmove, int pdr, int pdc);

void pawn(int r, int c, int color) {
	c = c + 3;
	r = r + 2;
	SetClr(color);
	gotoRowCol(r, c + 2);
	cout << char(-37);
	gotoRowCol(r + 1, c + 1);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 2, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 3, c + 1);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 4, c + 2);
	cout << char(-37);
	gotoRowCol(r + 5, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
	SetClr(7);
}
void knight(int r, int c, int color) {
	c = c + 3;
	r = r + 2;
	SetClr(color);
	gotoRowCol(r, c + 2);
	cout << char(-37);
	gotoRowCol(r + 1, c);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 2, c);
	cout << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 3, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 4, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 5, c - 1);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
void queen(int r, int c, int color) {
	c = c + 3;
	r = r + 2;
	SetClr(color);
	gotoRowCol(r, c);
	cout << char(-37);
	gotoRowCol(r, c + 3);
	cout << char(-37);
	gotoRowCol(r + 1, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 2, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 3, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 4, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 5, c - 1);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
void king(int r, int c, int color) {
	c = c + 3;
	r = r + 2;
	SetClr(color);
	gotoRowCol(r, c - 1);
	cout << char(-37);
	gotoRowCol(r, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r, c + 4);
	cout << char(-37);
	gotoRowCol(r + 1, c - 1);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 2, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 3, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 4, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 5, c - 1);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
void bishop(int r, int c, int color) {
	c = c + 3;
	r = r + 2;
	SetClr(color);
	gotoRowCol(r, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 1, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 2, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 3, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 4, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 5, c - 1);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
void rook(int r, int c, int color) {
	c = c + 3;
	r = r + 2;
	SetClr(color);
	gotoRowCol(r, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 1, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 2, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 3, c + 1);
	cout << char(-37) << char(-37);
	gotoRowCol(r + 4, c);
	cout << char(-37) << char(-37) << char(-37) << char(-37);
	gotoRowCol(r + 5, c - 1);
	cout << char(-37) << char(-37) << char(-37) << char(-37) << char(-37) << char(-37);
}
void Board() {
	SetClr(7);
	char symbol = char(-37);
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if ((i + j) % 2)
				SetClr(8);
			for (int k = 0; k < 10; k++) {
				gotoRowCol(i * 10, j * 10 + k);
				cout << symbol;
				for (int p = 0;p < 10;p++) {
					gotoRowCol(i * 10 + p, j * 10 + k);
					cout << symbol;
				}
			}
			SetClr(7);
		}
	}
	for (int i = 9; i <= 90;i++) {
		gotoRowCol(9, i);
		cout << "*";
		gotoRowCol(i, 9);
		cout << "*";
		gotoRowCol(90, i);
		cout << "*";
		gotoRowCol(i, 90);
		cout << "*";
	}
}
void checksymbol(char Sym, int r, int c) {
	r++;
	c++;
	r *= 10;
	c *= 10;
	switch (Sym) {
	case 'P':
		pawn(r, c, 6);
		break;
	case 'p':
		pawn(r, c, 4);
		break;
	case 'N':
		knight(r, c, 6);
		break;
	case 'n':
		knight(r, c, 4);
		break;
	case 'Q':
		queen(r, c, 6);
		break;
	case 'q':
		queen(r, c, 4);
		break;
	case 'K':
		king(r, c, 6);
		break;
	case 'k':
		king(r, c, 4);
		break;
	case 'B':
		bishop(r, c, 6);
		break;
	case 'b':
		bishop(r, c, 4);
		break;
	case 'R':
		rook(r, c, 6);
		break;
	case 'r':
		rook(r, c, 4);
		break;
	}

}
void suboard(int sr, int sc, int dr, int dc, pieces* board[][8]) {
	sr++;sc++;dr++;dc++;
	if ((sr + sc) % 2) {
		SetClr(8);
	}
	for (int k = 0; k < 10; k++) {
		gotoRowCol(sr * 10, sc * 10 + k);
		cout << char(-37);
		for (int p = 0;p < 10;p++) {
			gotoRowCol(sr * 10 + p, sc * 10 + k);
			cout << char(-37);
		}
	}
	SetClr(7);
	if ((dr + dc) % 2) {
		SetClr(8);
	}
	for (int k = 0; k < 10; k++) {
		gotoRowCol(dr * 10, dc * 10 + k);
		cout << char(-37);
		for (int p = 0;p < 10;p++) {
			gotoRowCol(dr * 10 + p, dc * 10 + k);
			cout << char(-37);
		}
	}
	SetClr(7);
	sr--;sc--;dr--;dc--;
	if (board[dr][dc] != nullptr) {
		checksymbol(board[dr][dc]->sym, dr, dc);
	}
	if (board[sr][sc] != nullptr) {
		checksymbol(board[sr][sc]->sym, sr, sc);
	}
}
void repsuboard(int r, int c, pieces* board[][8], char temp) {
	r++;c++;
	if ((r + c) % 2) {
		SetClr(8);
	}
	for (int k = 0; k < 10; k++) {
		gotoRowCol(r * 10, c * 10 + k);
		cout << char(-37);
		for (int p = 0;p < 10;p++) {
			gotoRowCol(r * 10 + p, c * 10 + k);
			cout << char(-37);
		}
	}
	SetClr(7);
	r--;c--;
	if (temp != '-') {
		checksymbol(temp, r, c);
		if (temp < 'z' && temp > 'a') {
			board[r][c]->color = BLACK;
			board[r][c]->playername = "zair";
			board[r][c]->sym = temp;
		}
		if (temp < 'Z' && temp >'A') {
			board[r][c]->color = WHITE;
			board[r][c]->playername = "riaz";
			board[r][c]->sym = temp;
		}
	}
	else {
		board[r][c] = nullptr;
	}
	SetClr(7);
}
void pawnsuboard(bool candopawnmove, int pdr, int pdc, int dr, int dc, int sc) {
	if (candopawnmove && pdc == dc && abs(pdr - dr) == 1 && sc != dc) {
		pdr++, pdc++;
		if ((pdr + pdc) % 2) {
			SetClr(8);
		}
		for (int k = 0; k < 10; k++) {
			gotoRowCol(pdr * 10, pdc * 10 + k);
			cout << char(-37);
			for (int p = 0;p < 10;p++) {
				gotoRowCol(pdr * 10 + p, pdc * 10 + k);
				cout << char(-37);
			}
		}
		SetClr(7);
	}
}
void indicator(int r, int c, pieces* board[][8]) {
	r++;c++;
	SetClr(12);
	for (int k = 0; k < 10; k++) {
		gotoRowCol(r * 10, c * 10 + k);
		cout << char(-37);
		for (int p = 0;p < 10;p++) {
			gotoRowCol(r * 10 + p, c * 10 + k);
			cout << char(-37);
		}
	}
	SetClr(7);
	r--;c--;
	if (board[r][c] != nullptr) {
		checksymbol(board[r][c]->sym, r, c);
	}
}
void revertindicator(int r, int c, pieces* board[][8]) {
	r++;c++;
	SetClr(7);
	if ((r + c) % 2) {
		SetClr(8);
	}
	for (int k = 0; k < 10; k++) {
		gotoRowCol(r * 10, c * 10 + k);
		cout << char(-37);
		for (int p = 0;p < 10;p++) {
			gotoRowCol(r * 10 + p, c * 10 + k);
			cout << char(-37);
		}
	}
	SetClr(7);
	r--;c--;
	if (board[r][c] != nullptr) {
		checksymbol(board[r][c]->sym, r, c);
	}
}
void highlight(int r, int c, int turn) {
	r++;r *= 10;
	c++;c *= 10;
	if (turn == 0)
		SetClr(5);
	if (turn == 1)
		SetClr(2);
	for (int i = 1; i < 9;i++) {
		gotoRowCol(r + i, c + 1);
		cout << char(-37);
		gotoRowCol(r + i, c + 8);
		cout << char(-37);
		gotoRowCol(r + 1, c + i);
		cout << char(-37);
		gotoRowCol(r + 8, c + i);
		cout << char(-37);
	}
	SetClr(7);
}
void dehighlight(int r, int c, int turn) {
	r++;r *= 10;
	c++;c *= 10;
	if ((r / 10 + c / 10) % 2)
		SetClr(8);
	else
		SetClr(7);
	for (int i = 1; i < 9;i++) {
		gotoRowCol(r + i, c + 1);
		cout << char(-37);
		gotoRowCol(r + i, c + 8);
		cout << char(-37);
		gotoRowCol(r + 1, c + i);
		cout << char(-37);
		gotoRowCol(r + 8, c + i);
		cout << char(-37);
	}
	SetClr(7);
}
void init(pieces* board[][8], string player1, string player2) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = new pieces;
			if (i > 1 && i < 6) {
				board[i][j] = nullptr;
			}
			if (i == 1) {
				board[i][j]->color = BLACK;
				board[i][j]->sym = 'p';
				board[i][j]->playername = player1;
			}
			if (i == 6) {
				board[i][j]->color = WHITE;
				board[i][j]->sym = 'P';
				board[i][j]->playername = player2;
			}
			if (i == 0 && (j == 0 || j == 7)) {
				board[i][j]->color = BLACK;
				board[i][j]->sym = 'r';
				board[i][j]->playername = player1;
			}
			if (i == 7 && (j == 0 || j == 7)) {
				board[i][j]->color = WHITE;
				board[i][j]->sym = 'R';
				board[i][j]->playername = player2;
			}
			if (i == 0 && (j == 1 || j == 6)) {
				board[i][j]->color = BLACK;
				board[i][j]->sym = 'n';
				board[i][j]->playername = player1;
			}
			if (i == 7 && (j == 1 || j == 6)) {
				board[i][j]->color = WHITE;
				board[i][j]->sym = 'N';
				board[i][j]->playername = player2;
			}
			if (i == 0 && (j == 2 || j == 5)) {
				board[i][j]->color = BLACK;
				board[i][j]->sym = 'b';
				board[i][j]->playername = player1;
			}
			if (i == 7 && (j == 2 || j == 5)) {
				board[i][j]->color = WHITE;
				board[i][j]->sym = 'B';
				board[i][j]->playername = player2;
			}
			if (i == 0 && j == 3) {
				board[i][j]->color = BLACK;
				board[i][j]->sym = 'q';
				board[i][j]->playername = player1;
			}
			if (i == 7 && j == 3) {
				board[i][j]->color = WHITE;
				board[i][j]->sym = 'Q';
				board[i][j]->playername = player2;
			}
			if (i == 0 && j == 4) {
				board[i][j]->color = BLACK;
				board[i][j]->sym = 'k';
				board[i][j]->playername = player1;
			}
			if (i == 7 && j == 4) {
				board[i][j]->color = WHITE;
				board[i][j]->sym = 'K';
				board[i][j]->playername = player2;
			}
		}
	}
}
void displayboard(pieces* board[][8]) {
	Board();
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == nullptr) {
			}
			else {
				checksymbol(board[i][j]->sym, i, j);
			}
		}
		cout << endl;
	}
	SetClr(7);
}
void trunmessege(int turn, string player1, string player2) {
	SetClr(7);
	if (turn == 0) {
		gotoRowCol(100, 10);
		cout << "Its turn for player " << player1 << " (RED)     ";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				gotoRowCol(102 + i, 10 + j);
				SetClr(4);
				cout << char(-37);
			}
		}
		SetClr(7);
	}
	if (turn == 1) {
		gotoRowCol(100, 10);
		cout << "its turn for player " << player2 << " (YELLOW)  ";
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				gotoRowCol(102 + i, 10 + j);
				SetClr(6);
				cout << char(-37);
			}
		}
		SetClr(7);
	}
}
bool isvalidsource(int r, int c, int turn, pieces* board[][8]) {
	if (r < 0 || c < 0 || r > 7 || c > 7)
		return false;
	if (board[r][c] == nullptr)
		return false;
	if (turn != board[r][c]->color)
		return false;
	return true;
}
bool isvaliddestination(int r, int c, int turn, pieces* board[][8]) {
	if (r < 0 || c < 0 || r > 7 || c > 7)
		return false;
	if (board[r][c] == nullptr)
		return true;
	if (turn == board[r][c]->color)
		return false;
	return true;
}
void recieve(int& r, int& c) {
	getRowColbyLeftClick(r, c);
	c /= 10;
	r /= 10;
	r--;c--;
}
void turnchange(int& turn) {
	turn++;
	turn %= 2;
}
void updateboard(pieces* board[][8], int sr, int sc, int dr, int dc, int pdr, int pdc, bool candopawnmove) {
	if (candopawnmove && pdc == dc && abs(pdr - dr) == 1 && sc != dc) {
		board[pdr][pdc] = nullptr;
	}
	board[dr][dc] = board[sr][sc];
	board[sr][sc] = nullptr;
}
bool isverticalmove(int sr, int sc, int dr, int dc) {
	return sc == dc;
}
bool isverticalclear(int sr, int sc, int dr, int dc, pieces* board[][8]) {
	int correction = 1;
	if (sr > dr)
		correction = -1;
	if (board[sr][sc]->sym == 'p' || board[sr][sc]->sym == 'P') {
		for (int i = 1; i <= abs(dr - sr); i++) {
			if (board[sr + (i * correction)][sc] != nullptr)
				return false;
		}
	}
	else {
		for (int i = 1; i < abs(dr - sr); i++) {
			if (board[sr + (i * correction)][sc] != nullptr)
				return false;
		}
	}
	return true;
}
bool ishorizentalmove(int sr, int sc, int dr, int dc) {
	return dr == sr;
}
bool ishorizentalclear(int sr, int sc, int dr, int dc, pieces* board[][8]) {
	int correction = 1;
	if (sc > dc)
		correction = -1;

	for (int i = 1; i < abs(dc - sc); i++) {
		if (board[sr][sc + (i * correction)] != nullptr)
			return false;
	}
	return true;
}
bool isdiagonalmove(int sr, int sc, int dr, int dc) {
	int difr = abs(dr - sr);
	int difc = abs(dc - sc);
	return difr == difc;
}
bool isdiagonalclear(int sr, int sc, int dr, int dc, pieces* board[][8]) {
	int corr = 1;
	int corc = 1;
	if (sc > dc) {
		corc = -1;
	}
	if (sr > dr) {
		corr = -1;
	}
	for (int i = 1; i < abs(dc - sc); i++) {
		if (board[sr + (i * corr)][sc + (i * corc)] != nullptr)
			return false;
	}
	return true;
}
bool isknightmove(int sr, int sc, int dr, int dc) {
	int difr = abs(dr - sr);
	int difc = abs(dc - sc);
	return (difr == 2 && difc == 1) || (difr == 1 && difc == 2);
}
bool ispawnmove(int sr, int sc, int dr, int dc, pieces* board[][8], bool candopawnmove, int pdr, int pdc) {
	if ((board[sr][sc]->color == WHITE) && sr == 6 && (abs(sr - dr) == 1 || abs(sr - dr) == 2) && isverticalmove(sr, sc, dr, dc) && isverticalclear(sr, sc, dr, dc, board))
		return true;
	if ((board[sr][sc]->color == BLACK) && sr == 1 && (abs(sr - dr) == 1 || abs(sr - dr) == 2) && isverticalmove(sr, sc, dr, dc) && isverticalclear(sr, sc, dr, dc, board))
		return true;
	if ((board[sr][sc]->color == WHITE) && sr != 6 && (abs(sr - dr) == 1) && isverticalmove(sr, sc, dr, dc) && isverticalclear(sr, sc, dr, dc, board))
		return true;
	if ((board[sr][sc]->color == BLACK) && sr != 1 && (abs(sr - dr) == 1) && isverticalmove(sr, sc, dr, dc) && isverticalclear(sr, sc, dr, dc, board))
		return true;
	if (abs(sr - dr) == 1 && abs(sc - dc) == 1 && board[dr][dc] != nullptr)
		return true;
	if (candopawnmove) {
		if (board[sr][dc] != nullptr && abs(sr - dr) == 1 && abs(sc - dc) == 1 && sr == pdr && dc == pdc) {
			return true;
		}
	}
	return false;
}
bool isvalidmove(int sr, int sc, int dr, int dc, pieces* board[][8], bool candopawnmove, int pdr, int pdc) {
	switch (board[sr][sc]->sym) {
	case 'R':
	case 'r':
		return (isverticalmove(sr, sc, dr, dc) && isverticalclear(sr, sc, dr, dc, board)) || (ishorizentalmove(sr, sc, dr, dc) && ishorizentalclear(sr, sc, dr, dc, board));

	case 'B':
	case 'b':
		return (isdiagonalmove(sr, sc, dr, dc) && isdiagonalclear(sr, sc, dr, dc, board));
	case 'Q':
	case 'q':
		return (isdiagonalmove(sr, sc, dr, dc) && isdiagonalclear(sr, sc, dr, dc, board) || isverticalmove(sr, sc, dr, dc) && isverticalclear(sr, sc, dr, dc, board)) || (ishorizentalmove(sr, sc, dr, dc) && ishorizentalclear(sr, sc, dr, dc, board));
	case 'N':
	case 'n':
		return isknightmove(sr, sc, dr, dc);
	case 'K':
	case 'k':
		return ((isdiagonalmove(sr, sc, dr, dc) && isdiagonalclear(sr, sc, dr, dc, board)) || (isverticalmove(sr, sc, dr, dc) && isverticalclear(sr, sc, dr, dc, board)) || (ishorizentalmove(sr, sc, dr, dc) && ishorizentalclear(sr, sc, dr, dc, board))) && ((abs(dr - sr) == 1 && abs(dc - sc) == 0) || (abs(dr - sr) == 0 && abs(dc - sc) == 1) || (abs(dr - sr) == 1 && abs(dc - sc) == 1));
	case 'P':
		return ispawnmove(sr, sc, dr, dc, board, candopawnmove, pdr, pdc) && sr > dr;
	case 'p':
		return ispawnmove(sr, sc, dr, dc, board, candopawnmove, pdr, pdc) && sr < dr;
	}
}
void map(bool RB[][8], pieces* board[][8], int sr, int sc, int turn, bool candopawnmove, int pdr, int pdc) {
	int p = 0, k = 0;
	for (int i = 0; i < 8;i++) {
		for (int j = 0; j < 8; j++) {
			if (isvaliddestination(i, j, turn, board) || candocastling(board, sr, sc, i, j, turn, candopawnmove, pdr, pdc)) {
				RB[i][j] = (isvalidmove(sr, sc, i, j, board, candopawnmove, pdr, pdc) || candocastling(board, sr, sc, i, j, turn, candopawnmove, pdr, pdc));
			}
			k++;
		}
		p++;
	}
}
void revertmap(bool RB[][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			RB[i][j] = false;
		}
	}
}
bool isking(int r, int c, pieces* board[][8]) {
	if (board[r][c] == nullptr)
		return false;
	return (board[r][c]->sym == 'k' || board[r][c]->sym == 'K');
}
void removemap(bool RB[][8], int turn, pieces* board[][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (RB[i][j] && !isking(i, j, board)) {
				dehighlight(i, j, turn);
			}
		}
	}
}
bool isspecificking(int r, int c, pieces* board[][8], int turn) {
	if (board[r][c] == nullptr)
		return false;
	return ((board[r][c]->sym == 'k' || board[r][c]->sym == 'K') && board[r][c]->color == turn);
}
bool check(pieces* board[][8], int turn, int kr, int kc, bool candopawnmove, int pdr, int pdc) {

	turn = (!turn);
	bool check = false;
	bool checkmap[8][8];
	revertmap(checkmap);
	for (int i = 0; i < 8;i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != nullptr && board[i][j]->color == turn) {
				map(checkmap, board, i, j, turn, candopawnmove, pdr, pdc);
				if (checkmap[kr][kc]) {
					check = true;
					return true;
				}
			}
		}
	}
	return check;
}
void checkindicator(pieces* board[][8], int turn, bool candopawnmove, int pdr, int pdc) {
	int kr, kc;
	for (int i = 0; i < 8; i++) {
		for (int j = 0;j < 8; j++) {
			if (isspecificking(i, j, board, turn)) {
				kr = i;
				kc = j;
			}
		}
	}
	if (check(board, turn, kr, kc, candopawnmove, pdr, pdc)) {
		indicator(kr, kc, board);
	}
	else {
		revertindicator(kr, kc, board);
	}
}
bool selfcheck(pieces* board[][8], int turn, int sr, int sc, int dr, int dc, bool candopawnmove, int pdr, int pdc) {
	pieces* replica[8][8];
	int kr, kc;
	/*for (int i = 0; i < 8; i++) {
		for (int j = 0;j < 8; j++) {
			if (isspecificking(i, j, board, turn)) {
				kr = i;
				kc = j;
			}
		}
	}*/
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			replica[i][j] = board[i][j];
		}
	}
	updateboard(replica, sr, sc, dr, dc, pdr, pdc, candopawnmove);
	for (int i = 0; i < 8; i++) {
		for (int j = 0;j < 8; j++) {
			if (isspecificking(i, j, replica, turn)) {
				kr = i;
				kc = j;
			}
		}
	}
	if (check(replica, turn, kr, kc, candopawnmove, pdr, pdc))
		return true;
	return false;

}
void displaymap(bool RB[][8], int turn, pieces* board[][8], int sr, int sc, bool candopawnmove, int pdr, int pdc) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (RB[i][j]) {
				if (!selfcheck(board, turn, sr, sc, i, j, candopawnmove, pdr, pdc)) {
					if (board[i][j] == nullptr) {
						highlight(i, j, turn);
					}
					else {
						if (board[i][j]->sym == 'k' || board[i][j]->sym == 'K') {
							continue;
						}
						else {
							highlight(i, j, turn);
						}
					}
				}

			}
		}
	}
}
bool checkmate(pieces* board[][8], int turn, bool candopawnmove, int pdr, int pdc) {
	bool replica[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			revertmap(replica);
			if (board[i][j] != nullptr && board[i][j]->color == turn) {
				map(replica, board, i, j, turn, candopawnmove, pdr, pdc);
				for (int p = 0; p < 8;p++) {
					for (int k = 0; k < 8; k++) {
						if (replica[p][k]) {
							if (!selfcheck(board, turn, i, j, p, k, candopawnmove, pdr, pdc)) {
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
bool stalemate(pieces* board[][8], int turn, bool candopawnmove, int pdr, int pdc) {
	bool replica[8][8];
	bool notmove = true;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			revertmap(replica);
			if (board[i][j] != nullptr && board[i][j]->color == turn) {
				map(replica, board, i, j, turn, candopawnmove, pdr, pdc);
				for (int p = 0; p < 8;p++) {
					for (int k = 0; k < 8; k++) {
						if (replica[p][k] && !selfcheck(board, turn, i, j, p, k, candopawnmove, pdr, pdc)) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}
bool ismykingincheck(pieces* board[][8], int turn, bool candopawnmove, int pdr, int pdc) {
	int kr, kc;
	for (int i = 0; i < 8; i++) {
		for (int j = 0;j < 8; j++) {
			if (isspecificking(i, j, board, turn)) {
				kr = i;
				kc = j;
			}
		}
	}
	if (check(board, turn, kr, kc, candopawnmove, pdr, pdc)) {
		return true;
	}
	return false;

}
bool candocastling(pieces* board[][8], int sr, int sc, int dr, int dc, int turn, bool candopawnmove, int pdr, int pdc) {
	if (board[sr][sc] == nullptr || board[dr][dc] == nullptr)
		return false;
	if (board[sr][sc]->sym != 'k') {
		if (board[sr][sc]->sym != 'K') {
			return false;
		}
	}
	if (board[dr][dc]->sym != 'r') {
		if (board[dr][dc]->sym != 'R') {
			return false;
		}
	}
	if (sr != 0) {
		if (sr != 7) {
			return false;
		}
	}
	if (sc != 4) {
		return false;
	}
	if (dr != sr) {
		return false;
	}
	if (board[sr][sc]->color != board[dr][dc]->color) {
		return false;
	}
	if (dc != 0) {
		if (dc != 7)
			return false;
	}
	if (sc < dc) {
		for (int i = sc + 1; i < dc;i++) {
			if (board[sr][i] != nullptr) {
				return false;
			}
			if (selfcheck(board, turn, sr, sc, dr, i, candopawnmove, pdc, pdr)) {
				return false;
			}
		}
	}
	if (sc > dc) {
		for (int i = sc - 1; i > dc;i--) {
			if (board[sr][i] != nullptr) {
				return false;
			}
			if (selfcheck(board, turn, sr, sc, dr, i, candopawnmove, pdr, pdc)) {
				return false;
			}
		}
	}

	return true;

}
void docastling(pieces* board[][8], int sr, int sc, int dr, int dc) {
	if (sc < dc) {
		board[sr][6] = board[sr][sc];
		board[sr][5] = board[dr][dc];
		board[sr][sc] = nullptr;
		board[dr][dc] = nullptr;
		SetClr(7);
		suboard(sr, sc, sr, 6, board);
		SetClr(7);
		suboard(dr, dc, sr, 5, board);
	}
	else {
		board[sr][1] = board[sr][sc];
		board[sr][2] = board[dr][dc];
		board[sr][sc] = nullptr;
		board[dr][dc] = nullptr;
		SetClr(7);
		suboard(sr, sc, sr, 1, board);
		SetClr(7);
		suboard(dr, dc, sr, 2, board);
	}

}
bool candopawnspecialmove(int sr, int sc, int dr, int dc, pieces* board[][8]) {
	if (sr == 1 || sr == 6) {
		if (abs(sr - dr) == 2 && sc - dc == 0) {
			if (board[sr][sc]->sym == 'p' || board[sr][sc]->sym == 'P') {
				return true;
			}
		}
	}
	return false;
}
void copy(pieces* board[][8], pieces* replica[][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			replica[i][j] = board[i][j];
		}
	}
}
void pawnpromotion(int r, int c, pieces* board[][8], int color) {
	queen(40, 100, color);
	rook(40, 110, color);
	bishop(40, 120, color);
	knight(40, 130, color);
	gotoRowCol(55, 110);
	cout << "[]PAWN_PROMOTION[]";
	int row, col;
	do {
		getRowColbyLeftClick(row, col);
		if (col < 110 && col >100 && row < 50 && row >40) {
			if (color == 6) {
				board[r][c]->sym = 'Q';
			}
			if (color == 4) {
				board[r][c]->sym = 'q';
			}
		}
		if (col < 120 && col >110 && row < 50 && row >40) {
			if (color == 6) {
				board[r][c]->sym = 'R';
			}
			if (color == 4) {
				board[r][c]->sym = 'r';
			}
		}
		if (col < 130 && col >120 && row < 50 && row >40) {
			if (color == 6) {
				board[r][c]->sym = 'B';
			}
			if (color == 4) {
				board[r][c]->sym = 'b';
			}
		}
		if (col < 140 && col >130 && row < 50 && row >40) {
			if (color == 6) {
				board[r][c]->sym = 'N';
			}
			if (color == 4) {
				board[r][c]->sym = 'n';
			}
		}
	} while (col < 100 || col > 150 || row < 40 || row > 50);
	for (int i = 40; i < 50; i++) {
		for (int j = 100; j < 140;j++) {
			gotoRowCol(i, j);
			cout << ' ';
		}
	}
	gotoRowCol(55, 110);
	cout << "                  ";
}
void pawnpromotionspawn(pieces* board[][8], int r, int c) {
	r++;c++;
	SetClr(7);
	if ((r + c) % 2) {
		SetClr(8);
	}
	for (int k = 0; k < 10; k++) {
		gotoRowCol(r * 10, c * 10 + k);
		cout << char(-37);
		for (int p = 0;p < 10;p++) {
			gotoRowCol(r * 10 + p, c * 10 + k);
			cout << char(-37);
		}
	}
	SetClr(7);
	r--;c--;
	if (board[r][c] != nullptr) {
		checksymbol(board[r][c]->sym, r, c);
	}
	SetClr(7);
}
void checkpawnpromotion(pieces* board[][8]) {
	for (int i = 0; i < 8; i++) {
		if (board[0][i] != nullptr) {
			if (board[0][i]->color == 1 && board[0][i]->sym == 'P') {
				pawnpromotion(0, i, board, 6);
				pawnpromotionspawn(board, 0, i);
			}
		}
		if (board[7][i] != nullptr) {
			if (board[7][i]->color == 0 && board[7][i]->sym == 'p') {
				pawnpromotion(7, i, board, 4);
				pawnpromotionspawn(board, 7, i);
			}
		}
	}
}
void filesave(int& counter, int revertcount, ofstream& file, pieces* board[][8]) {
	file.seekp(17 * (counter - revertcount) * 8);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (j == 7) {
				if (board[i][j] != nullptr) {
					if (file << board[i][j]->sym) {
						int a = 10;
					}
				}
				else {
					file << '-';
				}
			}
			else {
				if (board[i][j] != nullptr) {
					file << board[i][j]->sym << ' ';
				}
				else {
					file << '-' << ' ';
				}
			}
		}
		file << endl;
	}
	counter++;
}
void loadfile(int counter, int revertcount, ifstream& file, pieces* board[][8], bool& fileloaded) {
	char ignore;
	for (int k = 0; k < (counter - revertcount) - 1;k++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8;j++) {
				if (file.is_open()) {
					file >> ignore;
				}
			}
		}
	}
	char temp;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			file >> temp;
			if (temp == '-') {
				board[i][j] = nullptr;
				fileloaded = true;
			}
			else if ((temp < 'Z' && temp >'A') || (temp < 'z' && temp > 'a')) {
				board[i][j] = new pieces;
				fileloaded = true;
				board[i][j]->sym = temp;
				if (temp >= 'a' && temp <= 'z') {
					board[i][j]->color = BLACK;
					board[i][j]->playername = "zair";
				}
				if (temp >= 'A' && temp <= 'Z') {
					board[i][j]->color = WHITE;
					board[i][j]->playername = "riaz";
				}
			}

		}
	}
}
void undo_redo_receive(int counter, int& revertcount, pieces* board[][8], ifstream& file, int& turn, string player1, string player2) {
	gotoRowCol(100, 60);
	cout << "press < key";
	gotoRowCol(100, 87);
	cout << "press > key";
	char C;
	bool fileloaded = false;
	cin >> C;
	if (C == ',') {
		if (revertcount < counter - 1) {
			do {
				revertcount++;
				loadfile(counter, revertcount, file, board, fileloaded);
				if (fileloaded) {
					displayboard(board);
					turnchange(turn);
					trunmessege(turn, "zair", "riaz");
				}
			} while (!fileloaded);
		}
	}
	if (C == '.') {
		if (revertcount > 0) {
			do {
				if (!file.eof()) {
					revertcount--;
					loadfile(counter, revertcount, file, board, fileloaded);
					if (fileloaded) {
						displayboard(board);
						turnchange(turn);
						trunmessege(turn, "zair", "riaz");
					}
					else {
						revertcount++;
					}
				}
			} while (!fileloaded && !file.eof());
		}
	}
	gotoRowCol(100, 60);
	cout << "             ";
	gotoRowCol(100, 87);
	cout << "           ";
}
void button(int r, int c) {
	SetClr(2);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gotoRowCol(r + i, c + j);
			cout << char(-37);
		}
	}
	gotoRowCol(100, 100);
	cout << "UNDO-REDO";
	SetClr(7);

}
void exitsavebutton() {
	gotoRowCol(70, 100);
	SetClr(1);
	cout << "SAVE AND EXIT";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5;j++) {
			gotoRowCol(72 + i, 100 + j);
			cout << char(-37);
		}
	}
	SetClr(7);
}
void exitsave(int counter, int revertcount, int turn, bool candopawnmove, int pdr, int pdc) {
	ofstream file("exitsave.txt");
	file << counter << ' ' << revertcount << ' ' << turn << ' ' << candopawnmove << ' ' << pdr << ' ' << pdc;
	exit(1);
}
void gameloadbutton() {
	SetClr(7);
	gotoRowCol(50, 80);
	cout << "DO YOU WANT TO LOAD PREVIOUS ON GOING GAME ?";
	SetClr(2);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gotoRowCol(52 + i, 80 + j);
			cout << char(-37);
		}
	}
	gotoRowCol(59, 80);
	cout << "YES";
	SetClr(4);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gotoRowCol(52 + i, 90 + j);
			cout << char(-37);
		}
	}
	gotoRowCol(59, 90);
	cout << "NO";
	SetClr(7);


}
void loadgame(int& counter, int& revertcount, int& turn, pieces* board[][8], bool& candopawnmove, ifstream& file1, int& pdr, int& pdc) {
	ifstream file("exitsave.txt");
	file >> counter >> revertcount >> turn >> candopawnmove >> pdr >> pdc;
	bool temp;
	loadfile(counter, revertcount, file1, board, temp);
}
void copyfiles(ofstream& file, ifstream& file1) {
	char ch;

	if (file.is_open() && file1.is_open()) {
		while (file1.get(ch)) {

			file.put(ch);

			file.flush();
		}
	}
}
void replay(ifstream& file, int counter, pieces* board[][8], int revertcount) {
	char temp;
	for (int i = 0; i < 8; i++) {
		for (int j = 0;j < 8;j++) {
			file >> temp;
			if (temp == '-') {
				board[i][j] = nullptr;
			}
			if (temp > 'a' && temp < 'z') {
				board[i][j] = new pieces;
				board[i][j]->color = BLACK;
				board[i][j]->playername = "zair";
				board[i][j]->sym = temp;
			}
			if (temp > 'A' && temp < 'Z') {
				board[i][j] = new pieces;
				board[i][j]->color = WHITE;
				board[i][j]->playername = "riaz";
				board[i][j]->sym = temp;
			}
		}
	}
	displayboard(board);
	for (int c = 0; c < (counter - revertcount) - 1;c++) {
		Sleep(1000);
		for (int i = 0; i < 8; i++) {
			for (int j = 0;j < 8;j++) {
				file >> temp;
				if (board[i][j] == nullptr && temp == '-') {
					continue;
				}
				if (board[i][j] == nullptr && temp != '-') {
					board[i][j] = new pieces;
				}
				if (board[i][j]->sym != temp) {
					repsuboard(i, j, board, temp);
				}
			}
		}
	}
}
void replaybutton(int counter, pieces* board[][8], int revertcount) {
	Sleep(3000);
	system("cls");
	SetClr(7);
	gotoRowCol(50, 80);
	cout << "DO YOU WANT TO REPLAY YOUR MOVES ?";
	SetClr(2);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gotoRowCol(52 + i, 80 + j);
			cout << char(-37);
		}
	}
	gotoRowCol(59, 80);
	cout << "YES";
	SetClr(4);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gotoRowCol(52 + i, 90 + j);
			cout << char(-37);
		}
	}
	gotoRowCol(59, 90);
	cout << "NO";
	int r, c;
	getRowColbyLeftClick(r, c);
	if (r >= 52 && r < 57 && c >= 80 && c < 85) {
		system("cls");
		ifstream file("save.txt");
		replay(file, counter, board, revertcount);
	}
	SetClr(7);
	ofstream File("save.txt", ios::trunc);
	ofstream f_ile("saveread.txt", ios::trunc);


}
void resignbutton() {
	SetClr(11);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			gotoRowCol(10 + i, 100 + j);
			cout << char(-37);
		}
	}
	gotoRowCol(8, 100);
	cout << "RESIGN";
	SetClr(7);
}
void chess(int r, int c) {
	for (int i = 0; i < 10; i++) {
		gotoRowCol(r, c + i);
		cout << char(-37);
		gotoRowCol(r + 10, c + i);
		cout << char(-37);
		gotoRowCol(r + i, c);
		cout << char(-37);

		gotoRowCol(r + i, c + 11);
		cout << char(-37);
		gotoRowCol(r + i, c + 22);
		cout << char(-37);
		gotoRowCol(r + 5, c + 11 + i);
		cout << char(-37);

		gotoRowCol(r + i, c + 24);
		cout << char(-37);
		gotoRowCol(r, c + 24 + i);
		cout << char(-37);
		gotoRowCol(r + 5, c + 24 + i);
		cout << char(-37);
		gotoRowCol(r + 10, c + 24 + i);
		cout << char(-37);

		gotoRowCol(r, c + 37 + i);
		cout << char(-37);
		gotoRowCol(r + i / 2, c + 37);
		cout << char(-37);
		gotoRowCol(r + 5, c + 37 + i);
		cout << char(-37);
		gotoRowCol(r + 5 + i / 2, c + 47);
		cout << char(-37);
		gotoRowCol(r + 10, c + 37 + i);
		cout << char(-37);

		gotoRowCol(r, c + 50 + i);
		cout << char(-37);
		gotoRowCol(r + i / 2, c + 50);
		cout << char(-37);
		gotoRowCol(r + 5, c + 50 + i);
		cout << char(-37);
		gotoRowCol(r + 5 + i / 2, c + 60);
		cout << char(-37);
		gotoRowCol(r + 10, c + 50 + i);
		cout << char(-37);
	}
}
void animation() {
	int n = 1;
	for (int i = 1; i < 10;i++) {
		n = !n;
		Sleep(100);
		system("cls");
		chess(30, 60);
		pawn(50 + n, 70, i);
		rook(50 - n, 77, i);
		bishop(50 + n, 84, i);
		knight(50 - n, 91, i);
		queen(50 + n, 98, i);
		king(50 - n, 105, i);

	}
}
void main() {
	_getch();
	animation();
	system("cls");
	pieces* board[8][8];
	int sr, sc, dr, dc, pdr = -1, pdc = -1;
	int counter = 0;
	int revertcount = 0;
	string filename = "save.txt";
	ifstream before(filename);
	ofstream read("saveread.txt");
	copyfiles(read, before);


	ofstream file(filename);

	ifstream rfile("saveread.txt");
	copyfiles(file, rfile);

	/*file.open("save.txt");*/
	ifstream file1(filename);
	int turn;
	turn = 1;
	bool RB[8][8];
	revertmap(RB);
	bool displaycheck = false;
	bool candopawnmove = false;
	gameloadbutton();
	int ro, co;
	getRowColbyLeftClick(ro, co);
	bool load = false;
	system("cls");
	if (ro >= 52 && ro < 57 && co >= 80 && co < 85) {
		if (file1.peek() == EOF) {
			gotoRowCol(50, 78);
			cout << "THERE EXIST NO GAME TO LOAD.";
			main();
		}
		loadgame(counter, revertcount, turn, board, candopawnmove, file1, pdr, pdc);
		displayboard(board);
		load = true;
	}
	else {
		ofstream File(filename, ios::trunc);
		ofstream File_("saveread.txt", ios::trunc);
		init(board, "zair", "riaz");
		displayboard(board);
		filesave(counter, revertcount, file, board);
	}
	while (1) {
		trunmessege(turn, "zair", "riaz");
		do {
			do {
				do {
					if (displaycheck)
						removemap(RB, turn, board);
					button(102, 100);
					exitsavebutton();
					resignbutton();
					recieve(sr, sc);
					if (sr == 6 && sc == 9) {
						exitsave(counter, revertcount, turn, candopawnmove, pdr, pdc);
					}
					if (sr == 9 && sc == 9) {
						ifstream file1("save.txt");
						undo_redo_receive(counter, revertcount, board, file1, turn, "zair", "riaz");
					}
					if (sr == 0 && sc == 9) {
						if (turn == 1) {
							gotoRowCol(40, 100);
							cout << "RED HAS WON THE MATCH";
						}
						if (turn == 0) {
							gotoRowCol(40, 100);
							cout << "Yellow HAS WON THE MATCH";
						}
						exit(1);
					}
					displaycheck = true;
				} while (!isvalidsource(sr, sc, turn, board));
				map(RB, board, sr, sc, turn, candopawnmove, pdr, pdc);
				displaymap(RB, turn, board, sr, sc, candopawnmove, pdr, pdc);
				recieve(dr, dc);
				trunmessege(turn, "zair", "riaz");
			} while (!isvaliddestination(dr, dc, turn, board) && !candocastling(board, sr, sc, dr, dc, turn, candopawnmove, pdr, pdc));
		} while (!RB[dr][dc]);
		if (isking(dr, dc, board) || selfcheck(board, turn, sr, sc, dr, dc, candopawnmove, pdr, pdc)) {
			continue;
		}
		removemap(RB, turn, board);
		pieces* prevboard[8][8];
		copy(board, prevboard);
		if (candocastling(board, sr, sc, dr, dc, turn, candopawnmove, pdr, pdc)) {
			docastling(board, sr, sc, dr, dc);
		}
		else {
			updateboard(board, sr, sc, dr, dc, pdr, pdc, candopawnmove);
			pawnsuboard(candopawnmove, pdr, pdc, dr, dc, sc);
			suboard(sr, sc, dr, dc, board);
		}
		if (!load) {
			candopawnmove = candopawnspecialmove(sr, sc, dr, dc, prevboard);
		}
		if (candopawnmove) {
			pdr = dr;
			pdc = dc;
		}
		load = false;
		displaycheck = false;
		checkindicator(board, turn, candopawnmove, pdr, pdc);
		checkpawnpromotion(board);
		if (stalemate(board, !turn, candopawnmove, pdr, pdc) && !ismykingincheck(board, !turn, candopawnmove, pdr, pdc)) {
			SetClr(3);
			gotoRowCol(40, 100);
			cout << "MATCH HAS BEEN DRAW";
			filesave(counter, revertcount, file, board);
			replaybutton(counter, board, revertcount);
			_getche();
			system("cls");
			exit(1);
		}
		turnchange(turn);
		revertmap(RB);
		checkindicator(board, turn, candopawnmove, pdr, pdc);
		if (checkmate(board, turn, candopawnmove, pdr, pdc)) {
			gotoRowCol(40, 100);
			if (turn) {
				SetClr(4);
				cout << "PLAYER RED WON";
			}
			else {
				SetClr(6);
				cout << "PLAYER YELLOW WON";
			}
			filesave(counter, revertcount, file, board);
			replaybutton(counter, board, revertcount);
			_getche();
			system("cls");
			exit(1);
		}
		else {
			if (stalemate(board, turn, candopawnmove, pdr, pdc)) {
				gotoRowCol(40, 100);
				cout << "MATCH HAS BEEN DRAW";
				filesave(counter, revertcount, file, board);
				replaybutton(counter, board, revertcount);
				_getche();
				system("cls");
				exit(1);
			}
		}
		filesave(counter, revertcount, file, board);
	}



	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete board[i][j];
		}
	}
}
