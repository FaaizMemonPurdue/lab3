#include "BishopPiece.hh"
#include "ChessBoard.hh"

namespace Student
{

BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
  type = Bishop;
}

bool BishopPiece::canMoveToLocation(int toRow, int toColumn) {
  int x = getRow(), y = getColumn(), rowDir = x < toRow ? 1 : - 1, colDir = y < toColumn ? 1 : - 1;
  if (toRow != x && toColumn != y && toRow >= 0 && toRow < board.getNumRows() && toColumn >= 0 && toColumn < board.getNumCols()) for (x += rowDir, y += colDir; x != toRow && y != toColumn; x += rowDir, y += colDir) if (board.getPiece(x, y)) return false;
  return x == toRow && y == toColumn && (!board.getPiece(x, y) || board.getPiece(x, y)->getColor() != getColor());
}

const char *BishopPiece::toString() {
  return getColor() ? "\u2657" : "\u265D";
}

} // namespace Student
