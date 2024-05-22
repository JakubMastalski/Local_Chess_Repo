#pragma once

#include <vector>


//enum represent piece
enum Piece {EMPTY , PAWN , KNIGHT , BISHOP , ROOK ,QUEEN, KING};
//enum represent piece or field color
enum Color {NONE,WHITE,BLACK};

//squere on board
struct  ChessPiece
{
	Piece piece;
	Color color;
};

class ChessBoard
{
public:
	ChessBoard()
	{
		board.resize(8, std::vector<ChessPiece>(8));
		InitializeBoard();
	}


public:
// initialize empty squares
	void InitializeBoard()
	{
		for (int i = 2; i < 6; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				board[i][j] = { EMPTY, NONE };
			}
		}

		//init pawns black, and white
		for (int i = 0; i < 8; i++)
		{
			board[1][i] = { PAWN, WHITE };
			board[6][i] = { PAWN, BLACK };
		}
		//initialize rest of pieces
		InitializePieces();
}
	//ches board const ref
	const std::vector<std::vector<ChessPiece>>& getBoard() const {
		return board;
	}
//chess piece vector
private:
	std::vector<std::vector<ChessPiece>> board;
private:
	void InitializePieces()
	{
		//white pieces
		board[0][0] = { ROOK, WHITE };
		board[0][1] = { KNIGHT, WHITE };
		board[0][2] = { BISHOP, WHITE };
		board[0][3] = { QUEEN, WHITE };
		board[0][4] = { KING, WHITE };
		board[0][5] = { BISHOP, WHITE };
		board[0][6] = { KNIGHT, WHITE };
		board[0][7] = { ROOK, WHITE };
		//black pieces 
		board[7][0] = { ROOK, BLACK };
		board[7][1] = { KNIGHT, BLACK };
		board[7][2] = { BISHOP, BLACK };
		board[7][3] = { QUEEN, BLACK };
		board[7][4] = { KING, BLACK };
		board[7][5] = { BISHOP, BLACK };
		board[7][6] = { KNIGHT, BLACK };
		board[7][7] = { ROOK, BLACK };
	}













};






