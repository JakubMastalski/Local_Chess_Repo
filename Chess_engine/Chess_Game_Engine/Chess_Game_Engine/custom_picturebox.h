
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

class Pawn
{
    int points;
};
// enum representing piece types
enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };

// enum representing piece color or square color
enum PieceColor { NONE, WHITE, BLACK };



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
private:
    Piece piece;
    PieceColor color;
public:
    array<array<custom_picturebox^>^>^ GetPictureBoxes()
    {
        return pictureBoxes;
    }
public:
    void InitializeBoard()
    {
        // Custom PictureBox list
        int squareSize = 460 / 8 ;
        //varible to assign picture boxed number
        int pbCounter = 1;

        this->pictureBoxes = gcnew array<array<custom_picturebox^>^>(8);

        for (int row = 0; row < 8; row++)
        {
            pictureBoxes[row] = gcnew array<custom_picturebox^>(8);
            for (int col = 0; col < 8; col++)
            {
                custom_picturebox^ pictureBox = gcnew custom_picturebox();

                pictureBox->Location = System::Drawing::Point((col * squareSize)+6, (row * squareSize)+7);
        
                // Initialize the piece on the square
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
                else if(row > 1 && row < 6)
                {
                   
                    pictureBox->ImageLocation = (row + col) % 2 == 0 ?
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_sqr.jpg" :
                        "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_sqr.jpg";
                }
              
                pictureBox->Tag = gcnew Tuple<int, int>((int)piece, (int)color);
                pictureBox->pb_value = pbCounter++;
                pictureBoxes[row][col] = pictureBox;
                board_initialized = true;
                
            }
        }
       

    } 

    public:
        void FlipBoard()
        {
            // Custom PictureBox list
            int squareSize = 460 / 8;
            //varible to assign picture boxed number
            int pbCounter = 1;

            this->pictureBoxes = gcnew array<array<custom_picturebox^>^>(8);

            for (int row = 0; row < 8; row++)
            {
                pictureBoxes[row] = gcnew array<custom_picturebox^>(8);
                for (int col = 0; col < 8; col++)
                {
                    custom_picturebox^ pictureBox = gcnew custom_picturebox();

                    pictureBox->Location = System::Drawing::Point((col * squareSize) + 6, (row * squareSize) + 7);

                    if (row == 1 || row == 6)
                    {
                        piece = Piece::PAWN;

                        color = (row == 1) ? PieceColor::WHITE : PieceColor::BLACK;
                        pictureBox->ImageLocation = (color == PieceColor::BLACK) ?
                            "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_pawn.png" :
                            "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_pawn.png";

                    }

                    if (row == 0 || row == 7)
                    {
                        color = (row == 0) ? PieceColor::WHITE : PieceColor::BLACK;
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
                    else if (row > 1 && row < 6)
                    {
                        pictureBox->ImageLocation = (row + col) % 2 == 0 ?
                            "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_sqr.jpg" :
                            "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_sqr.jpg";
                        Visible = false;
                        Enabled = false;
                    }

                    pictureBox->Tag = gcnew Tuple<int, int>((int)piece, (int)color);
                    pictureBox->pb_value = pbCounter++;
                    pictureBoxes[row][col] = pictureBox;
                    board_initialized = true;

                }
            }
        }
       
       // Geter Piece piece
       // Geter PieceColor color
        public:
        Piece check_piece(custom_picturebox^ pb_piece)
        {
            return pb_piece->piece;
        }
        public:
        PieceColor check_color(custom_picturebox^ pb_piececolor)
        {
            return pb_piececolor->color;
        }

private:
    int pb_value;
    bool board_initialized;
private:
    array<array<custom_picturebox^>^>^ pictureBoxes;
};

