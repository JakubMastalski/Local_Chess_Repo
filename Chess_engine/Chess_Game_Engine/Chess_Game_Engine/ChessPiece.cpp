#include "ChessPiece.h"

#include "ChessPiece.h"

ChessPiece::ChessPiece()
{
    BackColor = System::Drawing::Color::Transparent;
    Size = System::Drawing::Size(52, 50);
    SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
    TabIndex = 6;
    TabStop = false;
    piece = Piece::EMPTY;
    color = PieceColor::NONE;
    passantable = false;
    onMoveIMG = false;
    row = -1;
    column = -1;
}

Piece ChessPiece::check_piece()
{
    if (this == nullptr)
    {
        MessageBox::Show("Error: Picture box does not contain a valid piece");
        return Piece::EMPTY;
    }
    else
    {
        return this->piece;
    }
}

PieceColor ChessPiece::check_color()
{
    if (this == nullptr)
    {
        MessageBox::Show("Error: Picture box does not contain a valid piece");
        return PieceColor::NONE;
    }
    else
    {
        return this->color;
    }
}

void ChessPiece::set_piece(Piece newPiece)
{
    if (this == nullptr)
    {
        MessageBox::Show("Error: Picture box does not contain a valid piece");
        return;
    }
    else
    {
        this->piece = newPiece;
    }
}

void ChessPiece::set_color(PieceColor newColor)
{
    if (this == nullptr)
    {
        MessageBox::Show("Error: Picture box does not contain a valid piece");
        return;
    }
    else
    {
        this->color = newColor;
    }
}