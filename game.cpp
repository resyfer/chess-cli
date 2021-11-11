#include "include/board.hpp"

int main() {

  std::cout<<"Welcome to Chess CLI"<<std::endl;
  std::cout<<"A Chess game in your CLI"<<std::endl;

  /**
   * Selecting Game mode from options:
   * 1. Visual
   * 2. Blindfold
   * 
   * Selecting player mode from options:
   * 1. Player vs Player
   */
  int gameMode = 3;
  int playerMode = 2;
  while(gameMode < 1 || gameMode > 2) {
    CLEAR;
    std::cout<<"1. Visual"<<std::endl;
    std::cout<<"2. Blindfold"<<std::endl;
    std::cout<<"Please select a game mode > ";
    std::cin>>gameMode;
  }
  CLEAR;
  while(playerMode < 1 || playerMode > 1) {
    CLEAR;
    std::cout<<"1. Player vs Player"<<std::endl;
    // std::cout<<"2. Player vs Bot"<<std::endl;
    std::cout<<"Please select a player mode > ";
    std::cin>>playerMode;
  }
  CLEAR;

  
  /* Initializing Board */
  std::array<std::array<int, 8>, 8> board = {0};
  initializeBoard(board);

  int player = 0;
  while(true) {
    CLEAR;
    
    if(gameMode != 2)
      printBoard(board);

    //Check Warning
    if(kingCheck[0] == 1) {
      std::cout<<"White King in Check!!!"<<std::endl;
    }
    if (kingCheck[1] == 1) {
      std::cout<<"Black King in Check!!!"<<std::endl;
    }

    // Getting move commands
    bool wrongCommand = false;
      std::string location, destination;

      std::cout<<"[Player "<<(player + 1)<<"]"<<std::endl;
      std::cout<<"Commands to be given like e4, d2, etc."<<std::endl<<std::endl;

    do {
      std::cout<<"Chess piece location > ";
      std::cin>>location;

      std::cout<<"Chess piece destination > ";
      std::cin>>destination;

      wrongCommand = !movePiece(board, player, location, destination);

      if(wrongCommand)
        std::cout<<"Incorrect command"<<std::endl<<std::endl;
    } while(wrongCommand && gameWin == 3);

    player = !player;

    // Game End Condition
    win(board);
    CLEAR;

    if(gameWin != 3) {
      printBoard(board);

      if(gameWin == 0)
        std::cout<<"White Wins!!!"<<std::endl;
      else if(gameWin == 1)
        std::cout<<"Black Wins!!!"<<std::endl;
      else if(gameWin == 2)
        std::cout<<"It's a Draw!!!"<<std::endl;

      break;
    }
  }
  return 0;
}