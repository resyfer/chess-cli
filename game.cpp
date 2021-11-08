#include <iostream>
#include <stdlib.h>
#include <array>
#include <vector>

#include "include/board.hpp"

//Defining CLEAR command for various OSes
#ifdef _WIN32
#define CLEAR system("cls")
#else
#define CLEAR system("clear")
#endif

int main() {

  std::cout<<"Welcome to Chess CLI"<<std::endl;
  std::cout<<"A Chess game in your CLI"<<std::endl;

  /**
   * @brief Selecting Game mode from options:
   * 1. Player vs Player
   */
  int gameMode = 2;
  while(gameMode < 1 || gameMode > 1) {
    CLEAR;
    std::cout<<"1. Player vs Player"<<std::endl;
    // std::cout<<"2. Player vs Bot"<<std::endl;
    std::cout<<"Please select a game mode > ";
    std::cin>>gameMode;
  }
  CLEAR;

  
  /* Initializing Board */
  std::array<std::array<int, 8>, 8> board = {0};
  initializeBoard(board);

  printBoard(board);

  std::vector<std::vector<int>> moves = legalMovesFunctions[3](board, 1, 'b');
  for(int i = 0; i<moves.size(); i++) {
    std::cout<<(8 - moves[i][0])<<" "<<char(moves[i][1] + 'a')<<std::endl;
  }

  return 0;
}