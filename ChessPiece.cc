#include "ChessPiece.hh"

namespace Student
{

ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column) : row(row), column(column), board(board), color(color) {
}

Color ChessPiece::getColor() {
  return color;
}

Type ChessPiece::getType() {
  return type;
}

int ChessPiece::getRow() {
  return row;
}

int ChessPiece::getColumn() {
  return column;
}

void ChessPiece::setPosition(int row, int column) {
  this -> row = row;
  this -> column = column;
}

} // namespace Student
