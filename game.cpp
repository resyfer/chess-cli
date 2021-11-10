#include "include/board.hpp"

int main() {

  std::cout<<"Welcome to Chess CLI"<<std::endl;
  std::cout<<"A Chess game in your CLI"<<std::endl;

  /**
   * @brief Selecting Game mode from options:
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

  bool gameOver = false; //temporary
  int player = 0; //temporary
  while(!gameOver) {
    CLEAR;
    
    if(gameMode != 2)
      printBoard(board);


    // Getting move commands
    bool wrongCommand = false;
      std::string location, destination;

      std::cout<<"[Player "<<((player == WHITE) ? "1" : "2")<<"]"<<std::endl;
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

    CLEAR;
    if(gameWin != 3) {
      printBoard(board);
      std::cout<<((gameWin == 0) ? "White" : "Black")<<" Wins!!"<<std::endl;
      break;
    }
  }
  return 0;
}