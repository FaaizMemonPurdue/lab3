#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>
#include <vector>
#include <list>
#include <fstream>

void isValidScan(Student::ChessBoard sBoard) {
  for (int i = 0; i < sBoard.getNumRows(); i++) for (int j = 0; j < sBoard.getNumCols(); j++) {
    if (sBoard.getPiece(i, j)) {
      for (int k = 0; k < sBoard.getNumRows(); k++) for (int l = 0; l < sBoard.getNumCols(); l++) {
        if (sBoard.isValidMove(i, j, k, l))
          std::cout << "Valid move from (" << i << ", " << j << ") to (" << k << ", " << l << ")" << std::endl;
        else
          std::cout << "InValid move from (" << i << ", " << j << ") to (" << k << ", " << l << ")" << std::endl;
      }
    }
  }
}

void underThreatScan(Student::ChessBoard sBoard) {
    for (int i = 0; i < sBoard.getNumRows(); i++) {
        for (int j = 0; j < sBoard.getNumCols(); j++) {
            Student::ChessPiece * piece = sBoard.getPiece(i, j);
            if (piece != nullptr) {
                if (sBoard.isPieceUnderThreat(i, j)) {
                    std::cout << "Piece at (" << i << ", " << j << ") is under threat" << std::endl;
                }
            }
        }
    }
}

int main() {
  Student::ChessBoard sBoard(4, 4);
  sBoard.createChessPiece(White, Rook, 3, 2);
  sBoard.createChessPiece(Black, Bishop, 1, 3);
  sBoard.createChessPiece(Black, Rook, 1, 1);
  sBoard.createChessPiece(White, Rook, 2, 3);
  sBoard.createChessPiece(Black, King, 0, 0);
  sBoard.createChessPiece(White, King, 3, 0);
  std::cout << sBoard.displayBoard().str();

  std::ifstream inputFile("input.txt");
  if (!inputFile.is_open()) {
      std::cerr << "Failed to open the input file." << std::endl;
      return EXIT_FAILURE;
  }
  std::string line;
  while (std::getline(inputFile, line)) {
    if (line.length() != 4) {
        std::cerr << "Each line must contain exactly 4 characters." << std::endl;
        return EXIT_FAILURE;
    }
    int d[4];
    for (int i = 0; i < 4; i++) d[i] = line[i] - '0';
    std::cout << "Read: ";
    for (int i = 0; i < 4; i++) std::cout << d[i] << " ";
    std::cout << std::end << std::end;
    isValidScan(sBoard);
    sBoard.movePiece(d[0], d[1], d[2], d[3]);
    std::cout << std::endl << sBoard.displayBoard().str();
  }
  return EXIT_SUCCESS;
}
