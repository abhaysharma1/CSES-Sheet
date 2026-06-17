#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int ans = 0;

bool isValid(vector<vector<char>>& board, int row, int col) {
    for (int i = row; i >= 0; i--) {
        if (board[i][col] == '$') return false;
    }
    // diagonal
    int rw = row, cl = col;
    while (rw >= 0 && cl < 8) {
        if (board[rw][cl] == '$') return false;
        rw--;
        cl++;
    }

    rw = row;
    cl = col;
    //anti-diagonal
    while (rw >= 0 && cl >= 0) {
        if (board[rw][cl] == '$') return false;
        rw--;
        cl--;
    }

    return true;
}

void rec(vector<vector<char>>& board, int placed, int row) {
    if (row == 8) {
        if (placed == 8) {
            ans++;
        }
        return;
    }

    for (int cl = 0; cl < 8; cl++) {
        if (board[row][cl] != '*' && isValid(board, row, cl)) {
            board[row][cl] = '$';
            rec(board, placed + 1, row + 1);
            board[row][cl] = '.';
        }
    }
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    rec(board, 0, 0);

    cout << ans;

    return 0;
}
