#include "RookPiece.hh"
#include "ChessBoard.hh"

namespace Student
{
    
RookPiece::RookPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
  type = Rook;
}

bool RookPiece::canMoveToLocation(int toRow, int toColumn) {
  int x = getRow(), y = getColumn(), xD = toRow - x, yD = toColumn - y, dir;
  if (xD && !yD) {
    dir = xD > 0 ? 1 : - 1;
    for (x += dir; x != toRow; x += dir) if (board.getPiece(x, y)) return false;
  }
  else if (yD && !xD) {
    dir = yD > 0 ? 1 : - 1;
    for (y += dir; y != toColumn; y += dir) if (board.getPiece(x, y)) return false;
  }
  else return false;
  return !board.getPiece(x, y) || board.getPiece(x, y)->getColor() != getColor();
}

const char *RookPiece::toString() {
  return getColor() ? "\u2656" : "\u265C";
}

} // namespace Student
