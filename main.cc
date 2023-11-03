#include <iostream>
#include <string>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using namespace Student;

int main()
{
    int nRow, nCol, pieceRow, pieceCol;
    char color, p;
    Type typ;
    string op;
    cin >> nRow;
    cin >> nRow >> nCol;

    ChessBoard sBoard(nRow, nCol);
    
    while (true) {
        cin >> color;
        if (color == '~') {
            break;
        }
        cin >> p;
        cin >> pieceRow >> pieceCol;
        switch (p) {
            case ('p'):
                typ = Type::Pawn; break;
            case ('b'):
                typ = Type::Bishop; break;
            case ('r'):
                typ = Type::Rook; break;
            case ('k'):
                typ = Type::King; break;
            default:
                cout << "wtf";
                exit(-1);
        }
        sBoard.createChessPiece((color == 'w') ? Color::White : Color::Black, typ, pieceRow, pieceCol);
    }
    cout << "Board scan complete\n";
    cout << sBoard.displayBoard().str() << endl;

    while (!cin.eof()) {
        cout << "#######################################\n";
        cin >> op;
        if (op == "isValidScan") {
            cout << "isValidScan" << endl;
            for (int io = 0; io < nRow; io++) {
                for (int jo = 0; jo < nCol; jo++) {
                    if (sBoard.getPiece(io, jo)) {
                        ChessPiece *piece = sBoard.getPiece(io, jo);
                        cout << piece->toString() << endl;
                        std::ostringstream outputString;
                        // top scale
                        outputString << "  ";
                        for (int i = 0; i < nCol; i++)
                        {
                            outputString << i;
                        }
                        outputString << std::endl
                                     << "  ";
                        // top border
                        for (int i = 0; i < nCol; i++)
                        {
                            outputString << "-";
                        }
                        outputString << std::endl;

                        for (int row = 0; row < nRow; row++)
                        {
                            outputString << row << "|";
                            for (int column = 0; column < nCol; column++)
                            {
                                outputString << ((sBoard.isValidMove(io, jo, row, column)) ? "⏺" : "˟");
                            }
                            outputString << "|" << std::endl;
                        }

                        // bottom border
                        outputString << "  ";
                        for (int i = 0; i < nCol; i++)
                        {
                            outputString << "-";
                        }
                        outputString << std::endl;
                        cout << outputString.str();
                    }
                }
            }
        } else if (op == "underThreatScan") {
            cout << "underThreatScan" << endl;
            std::ostringstream outputString;
            // top scale
            outputString << "  ";
            for (int i = 0; i < nCol; i++)
            {
                outputString << i;
            }
            outputString << std::endl
                         << "  ";
            // top border
            for (int i = 0; i < nCol; i++)
            {
                outputString << "-";
            }
            outputString << std::endl;

            for (int row = 0; row < nRow; row++)
            {
                outputString << row << "|";
                for (int column = 0; column < nCol; column++)
                {
                    outputString << ((sBoard.isPieceUnderThreat(row, column)) ? "⏺" : "˟");
                }
                outputString << "|" << std::endl;
            }

            // bottom border
            outputString << "  ";
            for (int i = 0; i < nCol; i++)
            {
                outputString << "-";
            }
            outputString << std::endl;
            cout << outputString.str();
        } else if (op == "movePiece") {
            cout << "movePiece ";
            int i, j, ni, nj;
            cin >> i >> j >> ni >> nj;
            cout << i << " " << j << " " << ni << " " << nj << endl;
            sBoard.movePiece(i, j, ni, nj);
            cout << sBoard.displayBoard().str() << endl;
        }
    }
    return EXIT_SUCCESS;
}


// #include <assert.h>
// #include "Chess.h"
// #include "ChessBoard.hh"
// #include "ChessPiece.hh"
// #include <iostream>
// #include <vector>
// #include <list>
// #include <fstream>

// void isValidScan(Student::ChessBoard sBoard) {
//   for (int i = 0; i < sBoard.getNumRows(); i++) for (int j = 0; j < sBoard.getNumCols(); j++) {
//     std::cout << "From (" << i << ", " << j << "):" << std::endl;
//     if (sBoard.getPiece(i, j)) for (int k = 0; k < sBoard.getNumRows(); k++) for (int l = 0; l < sBoard.getNumCols(); l++) {
//       std::cout << "to (" << k << ", " << l << ")" << std::endl;
//     }
//   }
// }

// void underThreatScan(Student::ChessBoard sBoard) {
//     for (int i = 0; i < sBoard.getNumRows(); i++) {
//         for (int j = 0; j < sBoard.getNumCols(); j++) {
//             Student::ChessPiece * piece = sBoard.getPiece(i, j);
//             if (piece != nullptr) {
//                 if (sBoard.isPieceUnderThreat(i, j)) {
//                     std::cout << "Piece at (" << i << ", " << j << ") is under threat" << std::endl;
//                 }
//             }
//         }
//     }
// }

// int main() {
//   Student::ChessBoard sBoard(4, 4);
//   sBoard.createChessPiece(White, Rook, 3, 2);
//   sBoard.createChessPiece(Black, Bishop, 1, 3);
//   sBoard.createChessPiece(Black, Rook, 1, 1);
//   sBoard.createChessPiece(White, Rook, 2, 3);
//   sBoard.createChessPiece(Black, King, 0, 0);
//   sBoard.createChessPiece(White, King, 3, 0);
//   std::cout << sBoard.displayBoard().str();

//   std::ifstream inputFile("input.txt");
//   if (!inputFile.is_open()) {
//       std::cerr << "Failed to open the input file." << std::endl;
//       return EXIT_FAILURE;
//   }
//   std::string line;
//   while (std::getline(inputFile, line)) {
//     if (line.length() != 4) {
//         std::cerr << "Each line must contain exactly 4 characters." << std::endl;
//         return EXIT_FAILURE;
//     }
//     int d[4];
//     for (int i = 0; i < 4; i++) d[i] = line[i] - '0';
//     std::cout << "Read: ";
//     for (int i = 0; i < 4; i++) std::cout << d[i] << " ";
//     std::cout << std::endl << std::endl;
//     isValidScan(sBoard);
//     sBoard.movePiece(d[0], d[1], d[2], d[3]);
//     std::cout << std::endl << sBoard.displayBoard().str();
//   }
//   return EXIT_SUCCESS;
// }
