#include "commands.hpp"

/* History of the played moves in the match */
std::vector<std::string> playedMoves;

void initializeBoard(std::array<std::array<int, 8>, 8> &board) {
  //Black
  addPiece(board, "Black", "Rook", 8, 'a');
  addPiece(board, "Black", "Knight", 8, 'b');
  addPiece(board, "Black", "Bishop", 8, 'c');
  addPiece(board, "Black", "Queen", 8, 'd');
  addPiece(board, "Black", "King", 8, 'e');
  addPiece(board, "Black", "Bishop", 8, 'f');
  addPiece(board, "Black", "Knight", 8, 'g');
  addPiece(board, "Black", "Rook", 8, 'h');
  addPiece(board, "Black", "Pawn", 7, 'a');
  addPiece(board, "Black", "Pawn", 7, 'b');
  addPiece(board, "Black", "Pawn", 7, 'c');
  addPiece(board, "Black", "Pawn", 7, 'd');
  addPiece(board, "Black", "Pawn", 7, 'e');
  addPiece(board, "Black", "Pawn", 7, 'f');
  addPiece(board, "Black", "Pawn", 7, 'g');
  addPiece(board, "Black", "Pawn", 7, 'h');

  //White
  addPiece(board, "White", "Rook", 1, 'a');
  addPiece(board, "White", "Knight", 1, 'b');
  addPiece(board, "White", "Bishop", 1, 'c');
  addPiece(board, "White", "Queen", 1, 'd');
  addPiece(board, "White", "King", 1, 'e');
  addPiece(board, "White", "Bishop", 1, 'f');
  addPiece(board, "White", "Knight", 1, 'g');
  addPiece(board, "White", "Rook", 1, 'h');
  addPiece(board, "White", "Pawn", 2, 'a');
  addPiece(board, "White", "Pawn", 2, 'b');
  addPiece(board, "White", "Pawn", 2, 'c');
  addPiece(board, "White", "Pawn", 2, 'd');
  addPiece(board, "White", "Pawn", 2, 'e');
  addPiece(board, "White", "Pawn", 2, 'f');
  addPiece(board, "White", "Pawn", 2, 'g');
  addPiece(board, "White", "Pawn", 2, 'h');
}

void printBoard(std::array<std::array<int, 8>, 8> board) {

  for(int i = 0; i<8; i++) {
    
    std::cout<<"   ";
    for(int j = 0; j<8; j++) {
      std::cout<<"+------";
    }
    std::cout<<"+"<<std::endl;
      
    for(int k = 1; k<=2; k++) {
      if(k == 1)
        std::cout<<" "<<(8 - i)<<" ";
      else
        std::cout<<"   ";


      for(int j = 0; j<8; j++) {
        if(board[i][j] == 0) {
          std::cout<<"|      ";
        } else {
          if(k == 1)
            std::cout<<colorDisplay[colorValue(board[i][j])];
          else
            std::cout<<pieceDisplay[pieceIndex(board[i][j])];
        }
      }
      std::cout<<"|";
      std::cout<<std::endl;
    }
  } 

  std::cout<<"   ";
  for(int i = 0; i<8; i++) {
    std::cout<<"+------";
  } 
  std::cout<<"+"<<std::endl;


  std::cout<<"   ";
  for(int i = 0; i<8; i++) {
    std::cout<<"   "<<char('a' + i)<<"   ";
  }
  std::cout<<std::endl;
}