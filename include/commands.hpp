#include "pieces.hpp"

// {row, column} (value from 0, 0 in array)
std::vector<int> positionToRankFile(
  std::string position //In form of eg. "e4", "f3", etc.
) {
  std::vector<int> coordinates = {8 - int(position[1] - '0'), int(position[0] - 'a')};
  return coordinates;
}

bool movePiece(
  std::array<std::array<int, 8>, 8> &board,
  int player,
  std::string startingPosition,  //In form of eg. "e4", "f3", etc.
  std::string endingPosition  //In form of eg. "e4", "f3", etc.
) {

  if(startingPosition.length() != 2 || endingPosition.length() != 2)
    return false;

  // Find out piece
  std::vector<int> location = positionToRankFile(startingPosition);
  int elementValue = board[location[0]][location[1]];


  // Check color
  if(player != colorValue(elementValue))
    return false;

  // Check Legal Moves
  std::vector<std::vector<int>> moves =
    legalMovesFunctions[pieceIndex(elementValue)](board, int(startingPosition[1] - '0'), startingPosition[0]);

  // Check if move is legal
  std::vector<int> destination = positionToRankFile(endingPosition);
  bool legal = false;
  for(int i = 0; i<moves.size(); i++) {
    if(
      moves[i][0] == destination[0] &&
      moves[i][1] == destination[1]
    ) {
      legal = true;
      break;
    }
  }

  if(!legal)
    return false;

  //Moving Piece
  board[destination[0]][destination[1]] = board[location[0]][location[1]];
  board[location[0]][location[1]] = 0;

  return true;
}

// 0 -> Error in promotion. 1 -> Success
bool pawnPromotion(
  std::array<std::array<int, 8>, 8> &board,
  std::string newPiece,
  int rank,
  char file
) {
  int elementValue = board[8 - rank][int(file - 'a')];

  int color = colorValue(elementValue);

  if(
    (color == NO_COLOR) ||
    (color == WHITE && rank != 8) ||
    (color == BLACK && rank != 1)
  ) return false;

  board[8 - rank][int(file - 'a')] =
  addPiece(
    board,
    colorTypes[color],
    newPiece,
    rank,
    file
  );

  return true;
}