#pragma once
#include <vector>
#include "custom_picturebox.h"
#include <cmath> 
#include <algorithm> 
#include <math.h>


namespace ChessGameEngine {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BoardForm
	/// </summary>
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

		custom_picturebox^ onHit_target = nullptr;
		custom_picturebox^ hiddenPictureBox = nullptr;
		custom_picturebox^ selectedPictureBox = nullptr;
		custom_picturebox^ targetPictureBox = nullptr;
		custom_picturebox^ white_king = nullptr;
		custom_picturebox^ black_king = nullptr;
		custom_picturebox^ last_moved_piece = nullptr;
		custom_picturebox^ onMove_target = nullptr;
		custom_picturebox^ target_pb = nullptr;
		custom_picturebox^ clicked_pb = nullptr;
		custom_picturebox^ enPassant_pb = nullptr;
		custom_picturebox^ new_selected = nullptr;
		custom_picturebox^ enPassantTarget_pb = nullptr;
		custom_picturebox^ chosen_piece = nullptr;
		custom_picturebox^ onMove_target_twoSteps = nullptr;
		custom_picturebox^ passantable = nullptr;
		custom_picturebox^ flipped_black_kingbox = nullptr;
		custom_picturebox^ flipped_white_kingbox = nullptr;
		custom_picturebox^ pictureBoxInstance = gcnew custom_picturebox();

		Control^ controlUnderCursor;

		Piece current_piece;
		Piece target_piece;
		Piece pieceType_selected;
		Piece pieceType_target;
		PieceColor current_color;
		PieceColor color_before;
		PieceColor pieceColor_selected;
		PieceColor pieceColor_target;

		array<array<custom_picturebox^>^>^ pictureBoxes;

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
private: bool change_pb(custom_picturebox^ selected_pb, custom_picturebox^ target_pb);
private: bool check_Pawnmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
private: bool check_sent(custom_picturebox^ selected_pb);
private: bool check_Knightmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
private: bool check_Bishopmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
private: bool check_Rookmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
private: bool check_Queenmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
private: bool check_Kingmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
private: bool king_checked(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ selected_piece);
private: bool check_Pawn_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
private: bool check_Knight_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
private: bool check_Bishop_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
private: bool check_Rook_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
private: bool check_Queen_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
private: bool is_king_under_attack(custom_picturebox^ piece, int kingRow, int kingCol);
private: bool king_still_checked(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ selected, custom_picturebox^ target, custom_picturebox^ last_moved);
private: bool is_king_still_in_check_after_move(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ selected, custom_picturebox^ target);
private: bool is_checkmate(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ kingBox);
private: bool pawn_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox);
private: bool knight_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox);
private: bool bishop_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox);
private: bool rook_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox);
private: bool queen_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox);
private: bool is_square_under_attack(int row, int col, PieceColor kingColor);

	   // Void functions
private: void player_turn(bool onMove, array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected);
private: void castle(custom_picturebox^ king, custom_picturebox^ king_dest, custom_picturebox^ rook, custom_picturebox^ rook_dest);
private: void reset_pb(array<array<custom_picturebox^>^>^ pictureBoxes);
private: void highlight_possible_moves_PAWM(custom_picturebox^ selected_pb);
private: void highlight_possible_moves_KNIGHT(custom_picturebox^ selected_pb);
private: void highlight_possible_moves_BISHOP(custom_picturebox^ selected_pb);
private: void highlight_possible_moves_ROOK(custom_picturebox^ selected_pb);
private: void highlight_possible_moves_QUEEN(custom_picturebox^ selected_pb);
private: void highlight_possible_moves_KING(custom_picturebox^ selected_pb);
private: void reset_highlight_moves();
private: void HandlePieceSelection(custom_picturebox^ selectedPictureBox);
private: void HandlePieceUp(custom_picturebox^ selectedPictureBox, custom_picturebox^ targetPictureBox);
private: void player_turnClick(); 

};
}
