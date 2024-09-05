#pragma once
#include <vector>
#include <cmath> 
#include <algorithm> 
#include <math.h>
#include "ChessPiece.h"
#include "ChessBoard.h"


namespace ChessGameEngine {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class BoardForm : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::Panel^ board_panel;
		System::Windows::Forms::Panel^ timeset_panel;
		System::Windows::Forms::Panel^ increment_panel;
		System::Windows::Forms::Panel^ promote_panel;
		System::Windows::Forms::Panel^ timeroptions_panel;
		System::Windows::Forms::Panel^ grid_panel;

		System::Windows::Forms::Label^ time_white;
		System::Windows::Forms::Label^ time_black;
		System::Windows::Forms::Label^ time_controllabel;
		System::Windows::Forms::Label^ minperside_label;
		System::Windows::Forms::Label^ increment_label;
		System::Windows::Forms::Label^ label_minperside;
		System::Windows::Forms::Label^ label_incpersec;
		System::Windows::Forms::Label^ label_whitetime;
		System::Windows::Forms::Label^ label_blacktime;

		System::Windows::Forms::ComboBox^ time_options_box;

		System::Windows::Forms::Button^ save_time_button;
		System::Windows::Forms::Button^ close_timepanel;

		System::Windows::Forms::TrackBar^ trackbar_minperside;
		System::Windows::Forms::TrackBar^ trackbar_secincrement;

		System::Windows::Forms::Timer^ menu_timer_black;
		System::Windows::Forms::Timer^ menu_timer_white;

		System::Windows::Forms::PictureBox^ picturebox_bg;
		System::Windows::Forms::PictureBox^ picturebox_board;
		System::Windows::Forms::PictureBox^ picturebox_queen;
		System::Windows::Forms::PictureBox^ picturebox_knight;
		System::Windows::Forms::PictureBox^ picturebox_rook;
		System::Windows::Forms::PictureBox^ picturebox_bishop;

		System::Windows::Forms::MenuStrip^ chess_menu;
		System::Windows::Forms::ToolStripMenuItem^ flipBoardToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ setTimeToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ restartToolStripMenuItem1;
		System::Windows::Forms::ToolStripMenuItem^ flipBoardToolStripMenuItem1;
		System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;

		System::ComponentModel::IContainer^ components;

	public:
		BoardForm(void);
	protected:
		~BoardForm();

	private:
		bool on_move;
		bool isWithinBounds;
		bool dragging;
		bool one_piece = true;
		bool castle_move;
		bool whiteonMove;
		bool piece_clicked;
		bool white_king_on_checked;
		bool black_king_on_checked;
		bool mouse_clicked = false;
		bool two_stepMove = false;
		bool white_king_moved;
		bool black_king_moved;
		bool black_queenside_rook_moved = false;
		bool black_kingside_rook_moved = false;
		bool white_queenside_rook_moved = false;
		bool white_kingside_rook_moved = false;
		bool game_started;
		bool timer_set;
		bool white_time_ended;
		bool black_time_ended;
		bool boardFlipped = false;
		bool sucess = false;
		bool show;

		int seconds;
		int seconds_white;
		int increment;
		int chosen_piece_val;
		int enPassantRow;
		int enPassantCol;

		Point start_black;
		Point start_white;
		Point scope;
		Point start_location;
		Point startLocation_selected;
		Point startLocation_target;

		ChessPiece^ onHit_target = nullptr;
		ChessPiece^ hiddenPictureBox = nullptr;
		ChessPiece^ target_pb = nullptr;
		ChessPiece^ clicked_pb = nullptr;
		ChessPiece^ enPassantTarget_pb = nullptr;
		ChessBoard^ pictureBoxInstance = gcnew ChessBoard();

		ChessPiece^ selectedPictureBox = nullptr;
		ChessPiece^ targetPictureBox = nullptr;
		ChessPiece^ white_king = nullptr;
		ChessPiece^ black_king = nullptr;
		ChessPiece^ last_moved_piece = nullptr;
		ChessPiece^ onMove_target = nullptr;
		ChessPiece^ enPassant_pb = nullptr;
		ChessPiece^ new_selected = nullptr;
		ChessPiece^ chosen_piece = nullptr;
		ChessPiece^ onMove_target_twoSteps = nullptr;
		ChessPiece^ passantable = nullptr;
		ChessPiece^ flipped_black_kingbox = nullptr;
		ChessPiece^ flipped_white_kingbox = nullptr;

		Control^ controlUnderCursor;

		Piece current_piece;
		Piece target_piece;
		Piece pieceType_selected;
		Piece pieceType_target;
		PieceColor current_color;
		PieceColor color_before;
		PieceColor pieceColor_selected;
		PieceColor pieceColor_target;

		array<array<ChessPiece^>^>^ pictureBoxes;

		String^ file_path;
		String^ start_filepath;
		String^ imgLocation_selected;
		String^ imgLocation_target;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void);
#pragma endregion

		// System::Void event handlers
private: System::Void flipBoardToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void setTimeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void trackbar_minperside_Scroll(System::Object^ sender, System::EventArgs^ e);
private: System::Void trackbar_secincrement_Scroll(System::Object^ sender, System::EventArgs^ e);
private: System::Void menu_timer_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void menu_timer_white_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void restartToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void close_timepanel_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void grid_panel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void grid_panel_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void grid_panel_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void grid_panel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void picturebox_bishop_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void picturebox_knight_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void picturebox_rook_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
private: System::Void picturebox_queen_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);

	   // Boolean functions
private: bool change_pb(ChessPiece^ selected_pb, ChessPiece^ target_pb);
private: bool check_Pawnmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb);
private: bool check_sent(ChessPiece^ selected_pb);
private: bool check_Knightmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb);
private: bool check_Bishopmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb);
private: bool check_Rookmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb);
private: bool check_Queenmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb);
private: bool check_Kingmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb);
private: bool king_checked(array<array<ChessPiece^>^>^ pb, ChessPiece^ selected_piece);
private: bool check_Pawn_Attack(ChessPiece^ pawnBox, int kingRow, int kingCol);
private: bool check_Knight_Attack(ChessPiece^ pawnBox, int kingRow, int kingCol);
private: bool check_Bishop_Attack(ChessPiece^ pawnBox, int kingRow, int kingCol);
private: bool check_Rook_Attack(ChessPiece^ pawnBox, int kingRow, int kingCol);
private: bool check_Queen_Attack(ChessPiece^ pawnBox, int kingRow, int kingCol);
private: bool is_king_under_attack(ChessPiece^ piece, int kingRow, int kingCol);
private: bool king_still_checked(array<array<ChessPiece^>^>^ pb, ChessPiece^ selected, ChessPiece^ target, ChessPiece^ last_moved);
private: bool is_king_still_in_check_after_move(array<array<ChessPiece^>^>^ pb, ChessPiece^ selected, ChessPiece^ target);
private: bool is_checkmate(array<array<ChessPiece^>^>^ pb, ChessPiece^ kingBox);
private: bool pawn_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox);
private: bool knight_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox);
private: bool bishop_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox);
private: bool rook_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox);
private: bool queen_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox);
private: bool is_square_under_attack(int row, int col, PieceColor kingColor);

	   // Void functions
private: void player_turn(bool onMove, array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected);
private: void castle(ChessPiece^ king, ChessPiece^ king_dest, ChessPiece^ rook, ChessPiece^ rook_dest);
private: void reset_pb(array<array<ChessPiece^>^>^ pictureBoxes);
private: void highlight_possible_moves_PAWM(ChessPiece^ selected_pb);
private: void highlight_possible_moves_KNIGHT(ChessPiece^ selected_pb);
private: void highlight_possible_moves_BISHOP(ChessPiece^ selected_pb);
private: void highlight_possible_moves_ROOK(ChessPiece^ selected_pb);
private: void highlight_possible_moves_QUEEN(ChessPiece^ selected_pb);
private: void highlight_possible_moves_KING(ChessPiece^ selected_pb);
private: void reset_highlight_moves();
private: void HandlePieceSelection(ChessPiece^ selectedPictureBox);
private: void HandlePieceUp(ChessPiece^ selectedPictureBox, ChessPiece^ targetPictureBox);
private: void player_turnClick();
};
}
