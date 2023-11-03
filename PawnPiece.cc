#include "PawnPiece.hh"
#include "ChessBoard.hh"

namespace Student
{

PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column) : ChessPiece(board, color, row, column) {
  type = Pawn;
}

bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
  int dir, start, end, row = getRow(), col = getColumn();
  if (getColor()) dir = - 1, start = board.getNumRows() - 2, end = 0;
  else dir = 1, start = 1, end = board.getNumRows() - 1;
  return toRow >= 0 && toRow < board.getNumRows() && row != end && toColumn >= std::max(0, col - 1) && toColumn < std::min(board.getNumCols(), col + 2) && (board.getPiece(toRow, toColumn) ? toColumn != col && toRow == row + dir && getColor() != board.getPiece(toRow, toColumn)->getColor() : toColumn == col && (toRow == row + dir || row == start && toRow == row + 2 * dir && !board.getPiece(row + dir, toColumn)));
}

const char *PawnPiece::toString() {
  return getColor() ? "\u2659" : "\u265F";
}

} // namespace Student
