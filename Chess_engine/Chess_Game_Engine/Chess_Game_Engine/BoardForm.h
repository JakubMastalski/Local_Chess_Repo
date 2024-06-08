﻿#pragma once
#include <vector>
#include "custom_picturebox.h"



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
		array<array<custom_picturebox^>^>^ pictureBoxes;

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
	private: void change_pb(custom_picturebox^ selected_pb, custom_picturebox^ target_pb);
	private: bool check_Pawnmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb);
	private:bool check_sent(custom_picturebox^ selected_pb);

	//private: bool check_Knightmove(custom_picturebox^ pb);
	//private: bool check_Bishopmove(custom_picturebox^ pb);
	//private: bool check_Rookmove(custom_picturebox^ pb);
	//private: bool check_Queenmove(custom_picturebox^ pb);
	//private: bool check_Kingmove(custom_picturebox^ pb);
};
}
