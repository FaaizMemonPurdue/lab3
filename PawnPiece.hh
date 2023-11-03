#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__
#include "ChessPiece.hh"

namespace Student
{

class PawnPiece : public ChessPiece {
 public:
  PawnPiece(ChessBoard &board, Color color, int row, int column);
  virtual bool canMoveToLocation(int toRow, int toColumn);
  virtual const char *toString();
};

} // namespace Student

#endif
