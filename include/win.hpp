#include "pieces.hpp"

std::vector<int> kingCheck = {0, 0};
//Index: 0 -> White, 1 -> Black
//Values: 0 -> No Check, 1 -> Check

int gameWin = 3; //0 -> White win, 1 -> Black win, 2 -> Draw, 3 -> No Win

void win(
  std::array<std::array<int, 8>, 8> &board
) {

  //Basic Win Condition
  std::vector<bool> kingFound = {false, false};
  std::vector<std::vector<int>> kingLocation = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
  
  //Index: 0 -> White, 1 -> Black
  for(int i = 0; i< 8; i++) {
    for(int j = 0; j<8; j++) {

      if(pieceIndex(board[i][j]) == 6) {
        int color = colorValue(board[i][j]);
        
        kingFound[color] = true;

        kingLocation[color][0] = i;
        kingLocation[color][1] = j;
      }
    }
  }

  if(!kingFound[0]) {
    gameWin = 1;
    return;
  } else if (!kingFound[1]) {
    gameWin = 0;
    return;
  }



  // Check and Game Draw Condition
  std::vector<std::vector<std::vector<bool>>> kingChoices = {
    {
      {1, 1, 1},
      {1, 1, 1},
      {1, 1, 1},
    },
    {
      {1, 1, 1},
      {1, 1, 1},
      {1, 1, 1},
    }
  }; //Index: 0 -> White, 1 -> Black
  // Matrixes represent areas around each king, with king at centre


  for(int k = 0; k<2; k++) { //Both colors' iterations separate
    for(int i = 0; i<8; i++) {
      for(int j = 0; j<8; j++) {
        
        if(colorValue(board[i][j]) != k)
          continue;


        std::vector<std::vector<int>> moves = 
          legalMovesFunctions[pieceIndex(board[i][j])](board, 8-i, char(j + 'a'));
        
        std::vector<int> kingCoordinates = kingLocation[(!k)];
        //Finding Coordinates of other color's king


        for(int p = 0; p<moves.size(); p++) {

          if(
            kingCoordinates[0] - 1 <= moves[p][0] && moves[p][0] <= kingCoordinates[0] + 1 &&
            kingCoordinates[1] - 1 <= moves[p][1] && moves[p][1] <= kingCoordinates[1] + 1
            //Checking for moves inside king's area
          ) {
            kingChoices[(!k)][1 - (kingCoordinates[0] - moves[p][0])][1 - (kingCoordinates[1] - moves[p][1])] =
              0;
          }

        }

      }
    }
  }
  


  for(int k = 0; k<kingChoices.size(); k++) {

    int kingChoiceCount = 0; //Counting number of choices
    for(int i = 0; i<kingChoices[k].size(); i++) {
      for(int j = 0; j<kingChoices[k][i].size(); j++) {
        kingChoiceCount+=kingChoices[k][i][j];
      }
    }


    if (
      kingChoices[k][1][1] == 0
    ) {
      kingCheck[k] = 1; // Check
      gameWin = 3; // No Win
    } else if(
      kingChoiceCount == 1 &&
      kingChoices[k][1][1] == 1
    ) {
      kingCheck[k] = 0; // No Check
      gameWin = 2; // Draw
    } else {
      kingCheck[k] = 0; // No Check
      gameWin = 3; // No Win
    }

  }

}