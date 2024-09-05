#pragma once
#include "ChessPiece.h"

ref class ChessBoard : public System::Windows::Forms::PictureBox
{
public:
    ChessBoard();

    array<array<ChessPiece^>^>^ GetPictureBoxes();
    void InitializeBoard();
    void FlipBoard();

private:
    bool board_initialized;
    array<array<ChessPiece^>^>^ pictureBoxes;
};

