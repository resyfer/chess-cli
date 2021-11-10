#include "definitions.hpp"

/**
 * Last 3 bits of pieceValue shows
 * piece according to pieceTypes's index
 * 
 * 4th bit from last shows color according to the #define
 */
std::array<std::string, 7> pieceTypes = {
  "",
  "Pawn",
  "Rook",
  "Knight",
  "Bishop",
  "Queen",
  "King"
};
std::array<std::string, 3> colorTypes = {
  "White",
  "Black",
  ""
};

// Only for Printing Board Purpose
std::array<std::string, 7> pieceDisplay = {
  "|      ",
  "| Pawn ",
  "| Rook ",
  "|Knight",
  "|Bishop",
  "| Queen",
  "| King "
};
std::array<std::string, 2> colorDisplay = {
  "| White",
  "| Black"
};

/* Identification of Piece */
int colorValue (int pieceValue) {
  if(pieceValue)
    return (pieceValue & 8) ? BLACK : WHITE;
  else
    return NO_COLOR;
}

int pieceIndex(int pieceValue) {
  return (pieceValue % 8);
}

/* Legal Moves */

//Placeholder function for index 0 to match the index with piece values
std::vector<std::vector<int>> noColorMoves(
  std::array<std::array<int, 8>, 8> &board,
  int rank,
  char file
) {
  std::vector<std::vector<int>> moves = {};
  return moves;
}

std::vector<std::vector<int>> pawnMoves(
  std::array<std::array<int, 8>, 8> &board,
  int rank,
  char file
) {
  std::vector<std::vector<int>> moves;

  int elementValue = board[8 - rank][int(file - 'a')];

  //Black moves below, so +ve multiplier. White, above, -ve multiplier
  int multiplierSign = (colorValue(elementValue) == BLACK) ? +1 : -1;

  // up moves for white, down moves for black
  if(
    board[8 - rank + (multiplierSign * 1)][int(file - 'a')] == 0
  ) {
    //1-up or 1-down
    moves.push_back({8 - rank + (multiplierSign * 1), int(file - 'a')});

    //2-up or 2-down only if 1-up or 1-down available
    if(
      ((multiplierSign == 1 && rank == 7) || (multiplierSign == -1 && rank == 2)) &&
      board[8 - rank + (multiplierSign * 2)][int(file - 'a')] == 0
    ) {
      moves.push_back({8 - rank + (multiplierSign * 2), int(file - 'a')});
    }
  }

  // 1-up-&-1-right or 1-down-&-1-right
  if(
    8 - rank + (multiplierSign * 1) >= 0 && 8 - rank + (multiplierSign * 1) < 8 &&
    int(file - 'a') + 1 < 8 &&
    colorValue(board[8 - rank + (multiplierSign * 1)][int(file - 'a') + 1]) != NO_COLOR &&
    colorValue(board[8 - rank + (multiplierSign * 1)][int(file - 'a') + 1]) != colorValue(elementValue)
  ) {
    moves.push_back({8 - rank + (multiplierSign * 1), int(file - 'a') + 1});
  }

  // 1-up-&-1-left or 1-down-&-1-left
  if(
    8 - rank + (multiplierSign * 1) >= 0 && 8 - rank + (multiplierSign * 1) < 8 &&
    int(file - 'a') - 1 >= 0 &&
    colorValue(board[8 - rank + (multiplierSign * 1)][int(file - 'a') - 1]) != NO_COLOR &&
    colorValue(board[8 - rank + (multiplierSign * 1)][int(file - 'a') - 1]) != colorValue(elementValue)
  ) {
    moves.push_back({8 - rank + (multiplierSign * 1), int(file - 'a') - 1});
  }

  //TODO: En passant

  return moves;
}

std::vector<std::vector<int>> rookMoves(
  std::array<std::array<int, 8>, 8> &board,
  int rank,
  char file
) {
  std::vector<std::vector<int>> moves;

  int elementValue = board[8 - rank][int(file - 'a')];

  //down
  for(int i = 8 - rank + 1; i<8; i++) {
    if(board[i][int(file - 'a')] == 0)
      moves.push_back({i, int(file - 'a')});
    else if (colorValue(board[i][int(file - 'a')]) == colorValue(elementValue))
      break;
    else {
      moves.push_back({i, int(file - 'a')});
      break;
    }
  }

  //up
  for(int i = 8 - rank - 1; i>=0; i--) {
    if(board[i][int(file - 'a')] == 0)
      moves.push_back({i, int(file - 'a')});
    else if (colorValue(board[i][int(file - 'a')]) == colorValue(elementValue))
      break;
    else {
      moves.push_back({i, int(file - 'a')});
      break;
    }
  }
  
  //right
  for(int i = int(file - 'a') + 1; i<8; i++) {
    if(board[8 - rank][i] == 0)
      moves.push_back({(8 - rank), i});
    else if (colorValue(board[8 - rank][i]) == colorValue(elementValue))
      break;
    else {
      moves.push_back({(8 - rank), i});
      break;
    }
  }

  //left
  for(int i = int(file - 'a') - 1; i>=0; i--) {
    if(board[8 - rank][i] == 0)
      moves.push_back({(8 - rank), i});
    else if (colorValue(board[8 - rank][i]) == colorValue(elementValue))
      break;
    else {
      moves.push_back({(8 - rank), i});
      break;
    }
  }
  return moves;
}

std::vector<std::vector<int>> knightMoves(
  std::array<std::array<int, 8>, 8> &board,
  int rank,
  char file
) {
  std::vector<std::vector<int>> moves;

  int elementValue = board[8 - rank][int(file - 'a')];
  
  /**
   * Knight moves as indexes:
   * 
   *    0--|--1
   *  2----|----3
   *       N
   *  4----|----5
   *    6--|--7
   */

  std::vector<std::vector<int>> positions = {
    {-2, -1},   //0
    {-2, +1},   //1
    {-1, -2},   //2
    {-1, +2},   //3
    {+1, -2},   //4
    {+1, +2},   //5
    {+2, -1},   //6
    {+2, +1}    //7
  };

  for(int i = 0; i<positions.size(); i++) {

    if( //Check Limits to keep positions inside board
      (8 - rank + positions[i][0] >= 0) && (8 - rank + positions[i][0] < 8) &&
      (int(file - 'a') + positions[i][1] >= 0) && (int(file - 'a') + positions[i][1] < 8)
    ) {

      if( //Move Legal if empty space or opponent piece
        board[8 - rank + positions[i][0]][int(file - 'a') + positions[i][1]] == 0 ||
        colorValue(board[8 - rank + positions[i][0]][int(file - 'a') + positions[i][1]]) != colorValue(elementValue)
      ) {
        moves.push_back({8 - rank + positions[i][0], int(file - 'a') + positions[i][1]});
      }
    }

  }
  return moves;
}

std::vector<std::vector<int>> bishopMoves(
  std::array<std::array<int, 8>, 8> &board,
  int rank,
  char file
) {
  std::vector<std::vector<int>> moves;

  int elementValue = board[8 - rank][int(file - 'a')];

  //down-right
  for(int i = 1; 8 - rank + i < 8 && int(file - 'a') + i < 8; i++) {
    if(board[8 - rank + i][int(file - 'a') + i] == 0)
      moves.push_back({8 - rank + i, int(file - 'a') + i});
    else if (colorValue(board[8 - rank + i][int(file - 'a') + i]) == colorValue(elementValue))
      break;
    else {
      moves.push_back({8 - rank + i, int(file - 'a') + i});
      break;
    }
  }

  //down-left
  for(int i = 1; 8 - rank + i < 8 && int(file - 'a') - i >=0; i++) {
    if(board[8 - rank + i][int(file - 'a') - i] == 0)
      moves.push_back({8 - rank + i, int(file - 'a') - i});
    else if (colorValue(board[8 - rank + i][int(file - 'a') - i]) == colorValue(elementValue))
      break;
    else {
      moves.push_back({8 - rank + i, int(file - 'a') - i});
      break;
    }
  }

  //up-right
  for(int i = 1; 8 - rank - i >= 0 && int(file - 'a') + i < 8; i++) {
    if(board[8 - rank - i][int(file - 'a') + i] == 0)
      moves.push_back({8 - rank - i, int(file - 'a') + i});
    else if (colorValue(board[8 - rank - i][int(file - 'a') + i]) == colorValue(elementValue))
      break;
    else {
      moves.push_back({8 - rank - i, int(file - 'a') + i});
      break;
    }
  }

  //up-left
  for(int i = 1; 8 - rank - i >= 0 && int(file - 'a') - i >=0; i++) {
    if(board[8 - rank - i][int(file - 'a') - i] == 0)
      moves.push_back({8 - rank - i, int(file - 'a') - i});
    else if (colorValue(board[8 - rank - i][int(file - 'a') - i]) == colorValue(elementValue))
      break;
    else {
      moves.push_back({8 - rank - i, int(file - 'a') - i});
      break;
    }
  }

  return moves;
}

std::vector<std::vector<int>> queenMoves(
  std::array<std::array<int, 8>, 8> &board,
  int rank,
  char file
) {
  std::vector<std::vector<int>> moves;

  // Queen's Moves = Rook's Moves + Bishop's Moves
  std::vector<std::vector<int>> straightMoves = rookMoves(board, rank, file);
  std::vector<std::vector<int>> diagonalMoves = bishopMoves(board, rank, file);

  moves.insert(moves.end(), straightMoves.begin(), straightMoves.end());
  moves.insert(moves.end(), diagonalMoves.begin(), diagonalMoves.end());
  return moves;
}

std::vector<std::vector<int>> kingMoves(
  std::array<std::array<int, 8>, 8> &board,
  int rank,
  char file
) {
  std::vector<std::vector<int>> moves;

  int elementValue = board[8 - rank][int(file - 'a')];

  //TODO: Castling

  /**
   * King moves as indexes:
   * 
   * 0 1 2
   * 3 K 4
   * 5 6 7
   * 
   */

  std::vector<std::vector<int>> positions = {
    {-1, -1},   //0
    {-1,  0},   //1
    {-1, +1},   //2
    { 0, -1},   //3
    { 0, +1},   //4
    {+1, -1},   //5
    {+1,  0},   //6
    {+1, +1},   //7
  };

  for(int i = 0; i<positions.size(); i++) {
    if(
      0 <= 8 - rank + positions[i][0] && 8 - rank + positions[i][0] < 8 &&
      0 <= int(file - 'a') + positions[i][1] && int(file - 'a') + positions[i][1] < 8
    ) {
      if(
        colorValue(board[8 - rank + positions[i][0]][int(file - 'a') + positions[i][1]]) !=
        colorValue(elementValue)
      ) {
        moves.push_back({8 - rank + positions[i][0], int(file - 'a') + positions[i][1]});
      }
    }
  }
  return moves;
}

// Array to call functions based on the chess piece's index
std::vector<std::vector<int>> (*legalMovesFunctions[7])(
  std::array<std::array<int, 8>, 8> &board,
  int rank,
  char file
) = {
  noColorMoves, //0
  pawnMoves,    //1
  rookMoves,    //2
  knightMoves,  //3
  bishopMoves,  //4
  queenMoves,   //5
  kingMoves     //6
};

// Adding a piece to the chess board
int addPiece(
  std::array<std::array<int, 8>, 8> &board,
  std::string color,
  std::string piece,
  int rank,
  char file
) {

  int pieceValue;

  for(int i = 0; i<pieceTypes.size(); i++) {
    if(pieceTypes[i] == piece)
      pieceValue = i;
  }

  for(int i = 0; i<colorDisplay.size(); i++) {
    if(colorTypes[i] == color)
      pieceValue += (i * 8);
  }

  board[8 - rank][int(file - 'a')] = pieceValue;

  return pieceValue;
}