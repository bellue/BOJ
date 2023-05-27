#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> emptyCells;

bool rowUsed[9][10];
bool colUsed[9][10];
bool squareUsed[9][10];

void solve(int cnt) {
    if (cnt == emptyCells.size()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++)
                cout << board[r][c] << ' ';
            cout << endl;
        }
        exit(0);
    }

    int r = emptyCells[cnt].first;
    int c = emptyCells[cnt].second;

    for (int num = 1; num <= 9; num++) {
        if (!rowUsed[r][num] && !colUsed[c][num] && !squareUsed[(r / 3) * 3 + (c / 3)][num]) {
            rowUsed[r][num] = true;
            colUsed[c][num] = true;
            squareUsed[(r / 3) * 3 + (c / 3)][num] = true;
            board[r][c] = num;

            solve(cnt + 1);

            rowUsed[r][num] = false;
            colUsed[c][num] = false;
            squareUsed[(r / 3) * 3 + (c / 3)][num] = false;
            board[r][c] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];

            if (board[r][c] == 0)
                emptyCells.push_back(make_pair(r, c));
            else {
                rowUsed[r][board[r][c]] = true;
                colUsed[c][board[r][c]] = true;
                squareUsed[(r / 3) * 3 + (c / 3)][board[r][c]] = true;
            }
        }
    }

    solve(0);
}
