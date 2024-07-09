#include <bits/stdc++.h>
#define m 4
using namespace std;

void printSolution(int board[m][m])
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<". ";
		printf("\n");
	}
}

bool isSafe(int board[m][m], int row, int col)
{
	int i, j;

	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < m; i++, j--)
		if (board[i][j])
			return false;

	return true;
}
bool solve(int board[m][m], int col)
{

	if (col >= m)
		return true;
	for (int i = 0; i < m; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			if (solve(board, col + 1))
				return true;
			board[i][col] = 0; 
		}
	}
	return false;
}
int main()
{
		int board[m][m]={{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 },
						{ 0, 0, 0, 0 } };

	if (solve(board, 0) == false) {
		cout << "Solution does not exist";
		return false;
	}
	printSolution(board);
	return 0;
}

