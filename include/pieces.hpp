#define WHITE 0
#define BLACK 1
#define NO_COLOR 2

int colorValue (int pieceValue) {
  if(pieceValue)  
    return (pieceValue & 8) ? BLACK : WHITE;
  else
    return NO_COLOR;
}

int pieceIndex(int pieceValue) {
  return (pieceValue % 8);
}