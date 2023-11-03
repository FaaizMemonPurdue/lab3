#ifndef __KINGPIECE_H__
#define __KINGPIECE_H__

#include "ChessPiece.hh"

namespace Student
{

class KingPiece : public ChessPiece {
  public:
  KingPiece(ChessBoard &board, Color color, int row, int column);
  virtual bool canMoveToLocation(int toRow, int toColumn);
  virtual const char *toString();
};

} // namespace Student

#endif
