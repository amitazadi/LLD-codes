// Tictactoe data members:-
//   size
//   board
//   currentPlayer

// Tictactoe member functions:-
//   getCurrentPlayer();
//   makeMove();
//   checkWin();
//   switchPlayer();
//   boardFull();
//   printBoard();


#include<bits/stdc++.h>
using namespace std;

class TicTacToe {
  private: 
  int size;
  vector<vector<char>>board;
  char currentPlayer;

  public: TicTacToe(int n) {
    size = n;
    board = vector<vector<char>>(n, vector<char>(n, '_'));
    currentPlayer = 'X';
  }

  void printBoard() const {
    for (const auto & row: board) {
      for (char cell: row) {
        cout << cell << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  bool makeMove(int row, int col) {
    if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != '_') {
      cout << "Invalid move! Try again." << endl;
      return false;
    }

    board[row][col] = currentPlayer;
    return true;
  }

  bool checkWin(int row, int col) {
    // Checking rows
    int rowCnt = 0, colCnt = 0, digCnt1 = 0, digCnt2 = 0;
    for (int i = 0; i < size; i++) {
      if (board[row][i] == currentPlayer)
        rowCnt++;

      if (board[i][col] == currentPlayer)
        colCnt++;

      if (board[i][i] == currentPlayer)
        digCnt1++;

      if (board[i][size - i] == currentPlayer)
        digCnt2++;

      if (rowCnt == size || colCnt == size || digCnt1 == size || digCnt2 == size)
        break;
    }

    if (rowCnt == size || colCnt == size || digCnt1 == size || digCnt2 == size)
      return true;

    return false;
  }

  bool boardFull() const {
    for (const auto & row: board) {
      for (char cell: row) {
        if (cell == '_') {
          return false; // Board is not full
        }
      }
    }
    return true; // Board is full
  }

  void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
  }

  char getCurrentPlayer() const {
    return currentPlayer;
  }
};

int main() {

  int n;
  cout << "Enter size of a board" << endl;
  cin >> n;

  TicTacToe game(n);
  while (true) {
    game.printBoard();

    int row, col;
    cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
    cin >> row >> col;

    if (game.makeMove(row, col)) {
      if (game.checkWin(row, col)) {
        game.printBoard();
        cout << "Player " << game.getCurrentPlayer() << " wins!" << endl;
        break;
      }

      if (game.boardFull()) {
        game.printBoard();
        cout << "It's a draw!" << endl;
        break;
      }

      game.switchPlayer();
    }
  }

  return 0;
}
