#include "pieces.hpp"


int gameWin = 3; //0 -> White win, 1 -> Black win, 2 -> Draw, 3 -> No Win

void win(
  std::array<std::array<int, 8>, 8> &board
) {

  //Win Condition
  std::vector<bool> kingFound = {false, false};
  //Index: 0 -> White, 1 -> Black
  for(int i = 0; i< 8; i++) {
    for(int j = 0; j<8; j++) {

      if(pieceIndex(board[i][j]) == 6)
        kingFound[colorValue(board[i][j])] = true;

    }
  }

  if(!kingFound[0])
    gameWin = 1;
  else if (!kingFound[1])
    gameWin = 0;

}