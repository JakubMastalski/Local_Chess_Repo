#pragma once
#include "ChessEnums.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;



ref class ChessPiece : public System::Windows::Forms::PictureBox
{
public:
    ChessPiece();

    Piece check_piece();
    PieceColor check_color();
    void set_piece(Piece newPiece);
    void set_color(PieceColor newColor);

    bool onMoveIMG;

    int row;
    int column;
private:
    Piece piece;
    PieceColor color;
    bool passantable;
};