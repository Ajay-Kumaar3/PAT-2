#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
vector<vector<string>> solutions;

bool place(int row, int col, vector<string> &board)
{
  for (int i = 0; i < row; i++)
  {
    // Same columnb
    if (board[i][col] == 'Q')
      return false;

    // Diagonal
    int diff = row - i;

    if (col - diff >= 0 && board[i][col - diff] == 'Q')
      return false;

    if (col + diff < N && board[i][col + diff] == 'Q')
      return false;
  }

  return true;
}

void nQueens(int row, vector<string> &board)
{
  if (row == N)
  {
    solutions.push_back(board);
    return;
  }

  for (int col = 0; col < N; col++)
  {
    if (place(row, col, board))
    {
      board[row][col] = 'Q';

      nQueens(row + 1, board);

      board[row][col] = '.';
    }
  }
}

int main()
{
  N = 4;

  vector<string> board(N, string(N, '.'));

  nQueens(0, board);

  cout << "=== Solar Grid Drone Deployment ===" << endl;
  cout << "Grid Size : " << N << "x" << N << endl;
  cout << "Found " << solutions.size()
       << " valid collision-free configurations:" << endl
       << endl;

  for (int i = 0; i < solutions.size(); i++)
  {
    cout << "Configuration " << i + 1 << ":" << endl;

    for (string row : solutions[i])
    {
      for (char cell : row)
        cout << cell << " ";

      cout << endl;
    }

    cout << endl;
  }

  return 0;
}

// Algorithm
// Start from the first row.
// Try placing a queen in every column.
// Check whether the position is safe.
// If safe, place the queen.
// Recursively solve the next row.
// If no solution is possible, remove the queen and backtrack.
// Continue until all queens are placed.

// NQueens(row)

//     if row == N
//         print solution
//         return

//     for col = 0 to N-1

//         if position(row, col) is safe

//             place queen at (row, col)

//             NQueens(row + 1)

//             remove queen

// Worst case ≈ O(N!)