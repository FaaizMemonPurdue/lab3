#include "BishopPiece.hh"
#include "ChessBoard.hh"
#include "KingPiece.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"

namespace Student {

ChessBoard::ChessBoard(int numRow, int numCol) : numRows(numRow), numCols(numCol), board(std::vector<std::vector<ChessPiece*>>(numRow, std::vector<ChessPiece*>(numCol, nullptr))) {
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {
  if (startRow < 0 || startRow >= numRows || startColumn < 0 || startColumn >= numCols) return;
  ChessPiece *&cp = board.at(startRow).at(startColumn);
  if (cp) delete cp;
  switch (ty) {
    case Bishop: cp = new BishopPiece(*this, col, startRow, startColumn); break;
    case King: cp = new KingPiece(*this, col, startRow, startColumn); break;
    case Pawn: cp = new PawnPiece(*this, col, startRow, startColumn); break;
    case Rook: cp = new RookPiece(*this, col, startRow, startColumn);
  }
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
  if (!isValidMove(fromRow, fromColumn, toRow, toColumn) || turn != board.at(fromRow).at(fromColumn)->getColor()) return false;
  ChessPiece *temp = board.at(toRow).at(toColumn);
  board.at(toRow).at(toColumn) = board.at(fromRow).at(fromColumn);
  board.at(toRow).at(toColumn)->setPosition(toRow, toColumn);
  board.at(fromRow).at(fromColumn) = nullptr;
  if (board.at(toRow).at(toColumn)->getType() == King && isPieceUnderThreat(toRow, toColumn)) {
    board.at(fromRow).at(fromColumn) = board.at(toRow).at(toColumn);
    board.at(fromRow).at(fromColumn)->setPosition(fromRow, fromColumn);
    board.at(toRow).at(toColumn) = temp;
    return false;
  }
  if (temp) delete temp;
  turn = turn ? Black : White;
  return true;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
  return fromRow >= 0 && fromRow < numRows && fromColumn >= 0 && fromColumn < numCols && board.at(fromRow).at(fromColumn) && board.at(fromRow).at(fromColumn)->canMoveToLocation(toRow, toColumn);
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
  if (board.at(row).at(column)) for (int x = 0; x < numRows; x++) for (int y = 0; y < numCols; y++) if (isValidMove(x, y, row, column)) return true;
  return false;
}

std::ostringstream ChessBoard::displayBoard() {
  std::ostringstream outputString;
  outputString << "  ";
  for (int i = 0; i < numCols; i++) outputString << i;
  outputString << std::endl << "  ";
  for (int i = 0; i < numCols; i++) outputString << "-";
  outputString << std::endl;
  for (int row = 0; row < numRows; row++) {
    outputString << row << "|";
    for (int column = 0; column < numCols; column++) outputString << (board.at(row).at(column) == nullptr ? " " : board.at(row).at(column)->toString());
    outputString << "|" << std::endl;
  }
  outputString << "  ";
  for (int i = 0; i < numCols; i++) outputString << "-";
  outputString << std::endl << std::endl;
  return outputString;
}

ChessBoard::~ChessBoard(){
  for (int x = 0; x < numRows; ++x) for (int y = 0; y < numCols; ++y) if (board.at(x).at(y)) delete board.at(x).at(y);
}

} // namespace Student
