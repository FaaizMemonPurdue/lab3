#include "KingPiece.hh"
#include "ChessBoard.hh"

namespace Student
{

KingPiece::KingPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
  type = King;
}

bool KingPiece::canMoveToLocation(int toRow, int toColumn) {
  int row = getRow(), col = getColumn();
  return (col != toColumn || row != toRow) && toRow >= std::max(0, row - 1) && toRow < std::min(board.getNumRows(), row + 2) && toColumn >= std::max(0, col - 1) && toColumn < std::min(board.getNumCols(), col + 2) && (!board.getPiece(toRow, toColumn) || board.getPiece(toRow, toColumn)->getColor() != color);
}

const char *Student::KingPiece::toString() {
  return getColor() ? "\u2654" : "\u265A";
}

} // namespace Student
