#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {

    for (int i = 0; i < row; ++i)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1)
            return false;


    for (int i = row, j = col; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueensUtil(int row, vector<vector<int>> &board, int n) {
    if (row == n)
        return true;

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 1;

            if (solveNQueensUtil(row + 1, board, n))
                return true;

            board[row][col] = 0;
        }
    }
    return false;
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<string>> solutions;

    if (solveNQueensUtil(0, board, n)) {
        for (int i = 0; i < n; ++i) {
            vector<string> solution;
            for (int j = 0; j < n; ++j) {
                string str = (board[i][j] == 1) ? "Q" : ".";
                solution.push_back(str);
            }
            solutions.push_back(solution);
        }
    }

    return solutions;
}

int main() {
    int n = 4;
    vector<vector<string>> solutions = solveNQueens(n);

    for (int i = 0; i < solutions.size(); ++i) {
        for (int j = 0; j < solutions[i].size(); ++j)
            cout << solutions[i][j] << " ";
        cout << endl;
    }

    return 0;
}
