#pragma once
#include <vector>

namespace ChessGameEngine {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    class ChessBoard {
    private:
        // enum representing piece types
        enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

        // enum representing piece color or square color
        enum Color { NONE, WHITE, BLACK };

        // enum representing square color
        enum SquareColor { WHITE_SQUARE, BLACK_SQUARE };
        
        //square on the board
        struct ChessPiece {
            Piece piece;
            Color color;
            SquareColor square_color;

        };
    public:
        ChessBoard() {
            board.resize(8, std::vector<ChessPiece>(8));
            InitializeBoard();
        }

        // return const reference to the board
        const std::vector<std::vector<ChessPiece>>& getBoard() const {
            return board;
        }

   public:
        void InitializeBoard() {
            // initialize the chessboard
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    // et the color of the square to add good pb
                    SquareColor squareColor = (i + j) % 2 == 0 ? WHITE_SQUARE : BLACK_SQUARE;
                    // set the square on the board
                    board[i][j] = { EMPTY, NONE, squareColor };
                }
            }

            // initialize pawns
            for (int i = 0; i < 8; i++) {
                board[1][i] = { PAWN, WHITE, BLACK_SQUARE };
                board[6][i] = { PAWN, BLACK, WHITE_SQUARE };
            }

            // initialize the rest of the pieces
            InitializePieces();
        }
  
    public:  void InitializePieces() {
            // initialize white pieces
            board[0][0] = { ROOK, WHITE, BLACK_SQUARE };
            board[0][1] = { KNIGHT, WHITE, WHITE_SQUARE };
            board[0][2] = { BISHOP, WHITE, BLACK_SQUARE };
            board[0][3] = { QUEEN, WHITE, WHITE_SQUARE };
            board[0][4] = { KING, WHITE, BLACK_SQUARE };
            board[0][5] = { BISHOP, WHITE, WHITE_SQUARE };
            board[0][6] = { KNIGHT, WHITE, BLACK_SQUARE };
            board[0][7] = { ROOK, WHITE, WHITE_SQUARE };

            // initialize black pieces 
            board[7][0] = { ROOK, BLACK, WHITE_SQUARE };
            board[7][1] = { KNIGHT, BLACK, BLACK_SQUARE };
            board[7][2] = { BISHOP, BLACK, WHITE_SQUARE };
            board[7][3] = { QUEEN, BLACK, BLACK_SQUARE };
            board[7][4] = { KING, BLACK, WHITE_SQUARE };
            board[7][5] = { BISHOP, BLACK, BLACK_SQUARE };
            board[7][6] = { KNIGHT, BLACK, WHITE_SQUARE };
            board[7][7] = { ROOK, BLACK, BLACK_SQUARE };
        }
    private:
        std::vector<std::vector<ChessPiece>> board;
    };
};