#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
    board_initialized = false;
    pictureBoxes = nullptr;
}

array<array<ChessPiece^>^>^ ChessBoard::GetPictureBoxes()
{
    return pictureBoxes;
}

void ChessBoard::InitializeBoard()
{
    int squareSize = 460 / 8;

    this->pictureBoxes = gcnew array<array<ChessPiece^>^>(8);

    for (int row = 0; row < 8; row++)
    {
        pictureBoxes[row] = gcnew array<ChessPiece^>(8);
        for (int col = 0; col < 8; col++)
        {
            ChessPiece^ pictureBox = gcnew ChessPiece();

            pictureBox->Location = System::Drawing::Point((col * squareSize) + 6, (row * squareSize) + 7);

            pictureBox->row = row;
            pictureBox->column = col;

            Piece piece = Piece::EMPTY;
            PieceColor color = PieceColor::NONE;

            if (row == 1 || row == 6)
            {
                piece = Piece::PAWN;
                color = (row == 1) ? PieceColor::BLACK : PieceColor::WHITE;
                pictureBox->ImageLocation = (color == PieceColor::BLACK) ?
                    "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_pawn.png" :
                    "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_pawn.png";
            }

            if (row == 0 || row == 7)
            {
                color = (row == 0) ? PieceColor::BLACK : PieceColor::WHITE;
                switch (col)
                {
                case 0:
                case 7:
                    piece = Piece::ROOK;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_rook.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_rook.png";
                    break;
                case 1:
                case 6:
                    piece = Piece::KNIGHT;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_knight.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_knight.png";
                    break;
                case 2:
                case 5:
                    piece = Piece::BISHOP;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_bishop.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_bishop.png";
                    break;
                case 3:
                    piece = Piece::QUEEN;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_queen.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_queen.png";
                    break;
                case 4:
                    piece = Piece::KING;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";
                    break;
                }
            }

            pictureBox->Tag = gcnew Tuple<int, int>((int)piece, (int)color);
            pictureBoxes[row][col] = pictureBox;
            board_initialized = true;
        }
    }
}

void ChessBoard::FlipBoard()
{
    int squareSize = 460 / 8;

    this->pictureBoxes = gcnew array<array<ChessPiece^>^>(8);

    for (int row = 0; row < 8; row++)
    {
        pictureBoxes[row] = gcnew array<ChessPiece^>(8);
        for (int col = 0; col < 8; col++)
        {
            ChessPiece^ pictureBox = gcnew ChessPiece();

            int newX = (7 - col) * squareSize + 6;
            int newY = (7 - row) * squareSize + 7;
            pictureBox->Location = System::Drawing::Point(newX, newY);

            Piece piece = Piece::EMPTY;
            PieceColor color = PieceColor::NONE;

            if (row == 1 || row == 6)
            {
                piece = Piece::PAWN;
                color = (row == 6) ? PieceColor::WHITE : PieceColor::BLACK;
                pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                    "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_pawn.png" :
                    "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_pawn.png";
            }

            if (row == 0 || row == 7)
            {
                color = (row == 7) ? PieceColor::WHITE : PieceColor::BLACK;
                switch (col)
                {
                case 0:
                case 7:
                    piece = Piece::ROOK;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_rook.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_rook.png";
                    break;
                case 1:
                case 6:
                    piece = Piece::KNIGHT;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_knight.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_knight.png";
                    break;
                case 2:
                case 5:
                    piece = Piece::BISHOP;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_bishop.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_bishop.png";
                    break;
                case 3:
                    piece = Piece::QUEEN;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_queen.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_queen.png";
                    break;
                case 4:
                    piece = Piece::KING;
                    pictureBox->ImageLocation = (color == PieceColor::WHITE) ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.png" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";
                    break;
                }
            }

            pictureBox->Tag = gcnew Tuple<int, int>((int)piece, (int)color);
            pictureBoxes[row][col] = pictureBox;
        }
    }

    board_initialized = true;
}