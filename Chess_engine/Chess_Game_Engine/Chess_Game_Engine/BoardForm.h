#pragma once
#include <vector>
#include "custom_picturebox.h"
#include <cmath> 
#include <algorithm> 


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
	public:
		BoardForm(void);
	protected:
		~BoardForm();

	private: System::Windows::Forms::Panel^ board_panel;
	private: System::Windows::Forms::Label^ time_white;
	private: System::Windows::Forms::Label^ time_black;
	private: System::Windows::Forms::MenuStrip^ chess_menu;
	private: System::Windows::Forms::ToolStripMenuItem^ flipBoardToolStripMenuItem;
	private: System::Windows::Forms::Panel^ timeset_panel;
	private: System::Windows::Forms::Label^ time_controllabel;
	private: System::Windows::Forms::ComboBox^ time_options_box;
	private: System::Windows::Forms::ToolStripMenuItem^ setTimeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ restartToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ flipBoardToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Panel^ increment_panel;
	private: System::Windows::Forms::Panel^ timeroptions_panel;
	private: System::Windows::Forms::Label^ minperside_label;
	private: System::Windows::Forms::Label^ increment_label;
	private: System::Windows::Forms::Button^ save_time_button;
	private: System::Windows::Forms::TrackBar^ trackbar_minperside;
	private: System::Windows::Forms::TrackBar^ trackbar_secincrement;
	private: System::Windows::Forms::Label^ label_minperside;
	private: System::Windows::Forms::Label^ label_incpersec;
	private: System::Windows::Forms::Timer^ menu_timer_black;
	private: System::Windows::Forms::PictureBox^ picturebox_bg;
	private: System::Windows::Forms::Timer^ menu_timer_white;
	private: System::Windows::Forms::Button^ close_timepanel;
	private: System::Windows::Forms::Label^ label_whitetime;
	private: System::Windows::Forms::Label^ label_blacktime;
	private: System::Windows::Forms::PictureBox^ picturebox_board;
	private: System::Windows::Forms::Panel^ grid_panel;
    private: System::ComponentModel::IContainer^ components;
	private:
		Point start_black;
		Point start_white;

		int seconds, seconds_white;
		int increment;
		bool on_move;
		bool isWithinBounds;

		bool dragging;
		Point scope;

		String^ file_path;
		String^ start_filepath;
		custom_picturebox^ selectedPictureBox;
		Point start_location;
		int chosen_piece_val;
	private:
		Control^ controlUnderCursor;
		custom_picturebox^ targetPictureBox;
	private:
		custom_picturebox^ white_king;
		custom_picturebox^ black_king;
	private:
		array<array<custom_picturebox^>^>^ pictureBoxes;
	private:
		Piece current_piece;
		Piece target_piece;
	private:
		bool castle_move;
	private:
		bool whiteonMove;
		bool piece_clicked;
	private:
		bool white_king_on_checked;
		bool black_king_on_checked;
	private:
		custom_picturebox^ last_moved_piece;
	private:
		Piece pieceType_selected;
		PieceColor pieceColor_selected;
		String^ imgLocation_selected;
		Point startLocation_selected;

		Piece pieceType_target;
		PieceColor pieceColor_target;
		String^ imgLocation_target;
		Point startLocation_target;

		int enPassantRow;
		int enPassantCol;
	private:
		bool white_king_moved;
		bool black_king_moved;

#pragma region Windows Form Designer generated code
    void InitializeComponent(void);
#pragma endregion
		//flip board
	private: System::Void flipBoardToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
	   //open panel with time
private: System::Void setTimeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	   //set time value from trackbar
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	   //set time
	private: System::Void trackbar_minperside_Scroll(System::Object^ sender, System::EventArgs^ e);

	   //set increment
	private: System::Void trackbar_secincrement_Scroll(System::Object^ sender, System::EventArgs^ e);
	
	   //black timer tick
	private: System::Void menu_timer_Tick(System::Object^ sender, System::EventArgs^ e);
	
	   //white timer tick
	private: System::Void menu_timer_white_Tick(System::Object^ sender, System::EventArgs^ e);
   //restart app
	private: System::Void restartToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);

	   //close app
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void close_timepanel_Click(System::Object^ sender, System::EventArgs^ e);
		   //draging form
	private: System::Void grid_panel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void grid_panel_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void grid_panel_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void grid_panel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: void change_pb(custom_picturebox^ selected_pb, custom_picturebox^ target_pb);
	private: bool check_Pawnmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
	private:bool check_sent(custom_picturebox^ selected_pb);
	private: bool check_Knightmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
    private: bool check_Bishopmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
	private: bool check_Rookmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
	private: bool check_Queenmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
	private: bool check_Kingmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
	private: void player_turn(bool onMove, array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected);
	private:void castle(custom_picturebox^ king, custom_picturebox^ king_dest, custom_picturebox^ rook, custom_picturebox^ rook_dest);
	private:void reset_pb(array<array<custom_picturebox^>^>^ pictureBoxes);
	private:bool king_checked(array<array<custom_picturebox^>^>^ pb,custom_picturebox^ selected_piece);
	private:bool check_Pawn_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
	private:bool check_Knight_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
    private:bool check_Bishop_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
	private:bool check_Rook_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
    private:bool check_Queen_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol);
	private:bool is_king_under_attack(custom_picturebox^ piece, int kingRow, int kingCol);
	private:bool king_still_checked(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ selected, custom_picturebox^ target, custom_picturebox^ last_moved);
};
}
