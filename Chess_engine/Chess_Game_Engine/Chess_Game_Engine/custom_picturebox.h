#include "string"



using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

//file path
/*

std::string white_pawn = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_pawn.jpg";
std::string black_pawn = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_pawn.jpg";
std::string white_bishop = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_bishop.jpg";
std::string black_bishop = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_bishop.jpg";
std::string white_knight = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_knight.jpg";
std::string black_knight = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_knight.jpg";
std::string white_rook = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_rook.jpg";
std::string black_rook = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_rook.jpg";
std::string white_queen = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_queen.jpg";
std::string black_queen = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_queen.jpg";
std::string white_king = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.jpg";
std::string black_king = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.jpg";
std::string white_kingchecked = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_kingchecked.jpg";
std::string black_kingchecked = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_kingchecked.jpg";
std::string white_sqr = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_sqr.jpg";
std::string black_sqr = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_sqr.jpg";
std::string on_move = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\on_move.jpg";
*/



// enum representing piece types
enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

// enum representing piece color or square color
enum PieceColor { NONE, WHITE, BLACK };

// enum representing square color
enum SquareColor { WHITE_SQUARE, BLACK_SQUARE };


ref class custom_picturebox :
    public System::Windows::Forms::PictureBox
{
public:
    custom_picturebox()
    {
        BackColor = System::Drawing::Color::Transparent;
        Size = System::Drawing::Size(48, 48);
        SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        TabIndex = 6;
        TabStop = false;
    };
private:
    //square on the board

    Piece piece;
    PieceColor color;
    SquareColor square_color;
public:
    array<array<custom_picturebox^>^>^ GetPictureBoxes()
    {
        return pictureBoxes;
    }
public:

    void InitializeBoard()
    {
        //custom pb list
        this->pictureBoxes = gcnew array<array<custom_picturebox^>^>(8);
        for (int row = 0; row < 8; row++)
        {
            pictureBoxes[row] = gcnew array<custom_picturebox^>(8);
            for (int col = 0; col < 8; col++)
            {
                custom_picturebox^ pictureBox = gcnew custom_picturebox();

                // Et the color of the square to add good pb
                SquareColor squareColor = (row + col) % 2 == 0 ? WHITE_SQUARE : BLACK_SQUARE;

                // Set the square on the board
                Piece piece;
                PieceColor color;
                if (row == 1 || row == 6)
                {
                    piece = PAWN;
                    color = (row == 1) ? WHITE : BLACK;
            

                }
                else
                {
                    piece = EMPTY;
                    color = NONE;
                }
                pictureBox->Tag = gcnew Tuple<int, int, int>((int)piece, (int)color, (int)squareColor);

                pictureBoxes[row][col] = pictureBox;
                // initialize white pieces
             
                // initialize the rest of the pieces
                this->Controls->Add(pictureBox);
            }
        }
    }
private:
    int pb_value;
private:
    array<array<custom_picturebox^>^>^ pictureBoxes;
};