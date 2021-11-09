#include "pieces.hpp"

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
  ) return 0;

  board[8 - rank][int(file - 'a')] =
  addPiece(
    board,
    colorTypes[color],
    newPiece,
    rank,
    file
  );

  return 1;
}