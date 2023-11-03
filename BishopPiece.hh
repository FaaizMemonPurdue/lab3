#ifndef __BISHOPPIECE_H__
#define __BISHOPPIECE_H__
#include "ChessPiece.hh"

namespace Student
{

class BishopPiece : public ChessPiece {
 public:
  BishopPiece(ChessBoard &board, Color color, int row, int column);
  virtual bool canMoveToLocation(int toRow, int toColumn);
  virtual const char *toString();
};

} // namespace Student

#endif
