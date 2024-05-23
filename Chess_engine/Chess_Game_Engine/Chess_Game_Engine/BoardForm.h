#pragma once
#include <vector>
#include "InitializeChessBoard.h"



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
		BoardForm(void)
		{
			InitializeComponent();
			ChessBoard chessboard;
			auto board = chessboard.getBoard();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BoardForm()
		{
			if (components)
			{
				delete components;
			}
		}
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
	private: System::Windows::Forms::Timer^ menu_timer_white;
	private: System::Windows::Forms::Button^ close_timepanel;
	private: System::Windows::Forms::Label^ label_whitetime;
	private: System::Windows::Forms::Label^ label_blacktime;
	private: System::Windows::Forms::PictureBox^ pb_C;


	private: System::Windows::Forms::PictureBox^ pb_B2;
	private: System::Windows::Forms::PictureBox^ pb_D2;
	private: System::Windows::Forms::PictureBox^ pb_H1;




	private: System::Windows::Forms::PictureBox^ pb_F2;
	private: System::Windows::Forms::PictureBox^ pb_H2;






	private: System::Windows::Forms::PictureBox^ pb_G1;

	private: System::Windows::Forms::PictureBox^ pb_F1;





	private: System::Windows::Forms::PictureBox^ pb_E1;




	private: System::Windows::Forms::PictureBox^ pb_D1;

	private: System::Windows::Forms::PictureBox^ pb_B1;
	private: System::Windows::Forms::PictureBox^ pb_G2;






private: System::Windows::Forms::PictureBox^ pb_E2;



private: System::Windows::Forms::PictureBox^ pb_C2;


private: System::Windows::Forms::PictureBox^ pb_A1;

private: System::Windows::Forms::PictureBox^ pb_A7;
private: System::Windows::Forms::PictureBox^ pb_H8;











private: System::Windows::Forms::PictureBox^ pb_G8;



private: System::Windows::Forms::PictureBox^ pb_F8;


private: System::Windows::Forms::PictureBox^ pb_E8;


private: System::Windows::Forms::PictureBox^ pb_D8;


private: System::Windows::Forms::PictureBox^ pb_C8;


private: System::Windows::Forms::PictureBox^ pb_B8;


private: System::Windows::Forms::PictureBox^ pb_A8;
private: System::Windows::Forms::PictureBox^ pb_B7;
private: System::Windows::Forms::PictureBox^ pb_H7;





private: System::Windows::Forms::PictureBox^ pb_F7;



private: System::Windows::Forms::PictureBox^ pb_D7;
private: System::Windows::Forms::PictureBox^ pb_G7;



private: System::Windows::Forms::PictureBox^ pb_E7;




private: System::Windows::Forms::PictureBox^ pb_C7;


private: System::Windows::Forms::PictureBox^ pb_A2;


private: System::Windows::Forms::PictureBox^ picturebox_board;
private: System::Windows::Forms::PictureBox^ pb_B3;
private: System::Windows::Forms::PictureBox^ pb_B5;
private: System::Windows::Forms::PictureBox^ pb_C6;
private: System::Windows::Forms::PictureBox^ pb_H3;




private: System::Windows::Forms::PictureBox^ pb_G4;
private: System::Windows::Forms::PictureBox^ pb_G6;
private: System::Windows::Forms::PictureBox^ pb_H5;



private: System::Windows::Forms::PictureBox^ pb_F5;

private: System::Windows::Forms::PictureBox^ pb_E6;

private: System::Windows::Forms::PictureBox^ pb_D5;

private: System::Windows::Forms::PictureBox^ pb_a6;
private: System::Windows::Forms::PictureBox^ pb_A4;
private: System::Windows::Forms::PictureBox^ pb_C4;
private: System::Windows::Forms::PictureBox^ pb_E4;
private: System::Windows::Forms::PictureBox^ pb_F3;




private: System::Windows::Forms::PictureBox^ pb_C3;
private: System::Windows::Forms::PictureBox^ pb_G5;


private: System::Windows::Forms::PictureBox^ pb_F6;

private: System::Windows::Forms::PictureBox^ pb_D6;
private: System::Windows::Forms::PictureBox^ pb_E5;


private: System::Windows::Forms::PictureBox^ pb_C5;

private: System::Windows::Forms::PictureBox^ pb_B6;

private: System::Windows::Forms::PictureBox^ pb_A5;
private: System::Windows::Forms::PictureBox^ pb_A3;
private: System::Windows::Forms::PictureBox^ pb_B4;
private: System::Windows::Forms::PictureBox^ pb_D4;
private: System::Windows::Forms::PictureBox^ pb_F4;
private: System::Windows::Forms::PictureBox^ pb_H6;
private: System::Windows::Forms::PictureBox^ pb_H4;







private: System::Windows::Forms::PictureBox^ pb_G3;

private: System::Windows::Forms::PictureBox^ pb_E3;

private: System::Windows::Forms::PictureBox^ pb_D3;









































































































































































































































	private: System::ComponentModel::IContainer^ components;






















	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BoardForm::typeid));
			this->board_panel = (gcnew System::Windows::Forms::Panel());
			this->pb_A2 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_H8 = (gcnew System::Windows::Forms::PictureBox());
			this->timeset_panel = (gcnew System::Windows::Forms::Panel());
			this->increment_panel = (gcnew System::Windows::Forms::Panel());
			this->trackbar_secincrement = (gcnew System::Windows::Forms::TrackBar());
			this->label_incpersec = (gcnew System::Windows::Forms::Label());
			this->increment_label = (gcnew System::Windows::Forms::Label());
			this->timeroptions_panel = (gcnew System::Windows::Forms::Panel());
			this->save_time_button = (gcnew System::Windows::Forms::Button());
			this->close_timepanel = (gcnew System::Windows::Forms::Button());
			this->time_controllabel = (gcnew System::Windows::Forms::Label());
			this->time_options_box = (gcnew System::Windows::Forms::ComboBox());
			this->label_minperside = (gcnew System::Windows::Forms::Label());
			this->trackbar_minperside = (gcnew System::Windows::Forms::TrackBar());
			this->minperside_label = (gcnew System::Windows::Forms::Label());
			this->pb_G8 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_F8 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_E8 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_D8 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_C8 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_B8 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_A8 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_B7 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_H7 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_F7 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_D7 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_G7 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_E7 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_C7 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_A7 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_A1 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_C = (gcnew System::Windows::Forms::PictureBox());
			this->pb_B2 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_D2 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_H1 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_F2 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_H2 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_G1 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_F1 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_E1 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_D1 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_B1 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_G2 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_E2 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_C2 = (gcnew System::Windows::Forms::PictureBox());
			this->time_white = (gcnew System::Windows::Forms::Label());
			this->label_whitetime = (gcnew System::Windows::Forms::Label());
			this->label_blacktime = (gcnew System::Windows::Forms::Label());
			this->time_black = (gcnew System::Windows::Forms::Label());
			this->picturebox_board = (gcnew System::Windows::Forms::PictureBox());
			this->chess_menu = (gcnew System::Windows::Forms::MenuStrip());
			this->flipBoardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipBoardToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setTimeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restartToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_timer_black = (gcnew System::Windows::Forms::Timer(this->components));
			this->menu_timer_white = (gcnew System::Windows::Forms::Timer(this->components));
			this->pb_B3 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_D3 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_E3 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_G3 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_H4 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_H6 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_F4 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_D4 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_B4 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_A3 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_A5 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_B6 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_C5 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_E5 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_D6 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_F6 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_G5 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_C3 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_F3 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_E4 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_C4 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_A4 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_a6 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_D5 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_E6 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_F5 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_H5 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_G6 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_G4 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_H3 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_C6 = (gcnew System::Windows::Forms::PictureBox());
			this->pb_B5 = (gcnew System::Windows::Forms::PictureBox());
			this->board_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H8))->BeginInit();
			this->timeset_panel->SuspendLayout();
			this->increment_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_secincrement))->BeginInit();
			this->timeroptions_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_minperside))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->BeginInit();
			this->chess_menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_a6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B5))->BeginInit();
			this->SuspendLayout();
			// 
			// board_panel
			// 
			this->board_panel->Controls->Add(this->pb_B5);
			this->board_panel->Controls->Add(this->pb_C6);
			this->board_panel->Controls->Add(this->timeset_panel);
			this->board_panel->Controls->Add(this->pb_H3);
			this->board_panel->Controls->Add(this->pb_G4);
			this->board_panel->Controls->Add(this->pb_G6);
			this->board_panel->Controls->Add(this->pb_H5);
			this->board_panel->Controls->Add(this->pb_F5);
			this->board_panel->Controls->Add(this->pb_E6);
			this->board_panel->Controls->Add(this->pb_D5);
			this->board_panel->Controls->Add(this->pb_a6);
			this->board_panel->Controls->Add(this->pb_A4);
			this->board_panel->Controls->Add(this->pb_C4);
			this->board_panel->Controls->Add(this->pb_E4);
			this->board_panel->Controls->Add(this->pb_F3);
			this->board_panel->Controls->Add(this->pb_C3);
			this->board_panel->Controls->Add(this->pb_G5);
			this->board_panel->Controls->Add(this->pb_F6);
			this->board_panel->Controls->Add(this->pb_D6);
			this->board_panel->Controls->Add(this->pb_E5);
			this->board_panel->Controls->Add(this->pb_C5);
			this->board_panel->Controls->Add(this->pb_B6);
			this->board_panel->Controls->Add(this->pb_A5);
			this->board_panel->Controls->Add(this->pb_A3);
			this->board_panel->Controls->Add(this->pb_B4);
			this->board_panel->Controls->Add(this->pb_D4);
			this->board_panel->Controls->Add(this->pb_F4);
			this->board_panel->Controls->Add(this->pb_H6);
			this->board_panel->Controls->Add(this->pb_H4);
			this->board_panel->Controls->Add(this->pb_G3);
			this->board_panel->Controls->Add(this->pb_E3);
			this->board_panel->Controls->Add(this->pb_D3);
			this->board_panel->Controls->Add(this->pb_B3);
			this->board_panel->Controls->Add(this->pb_A2);
			this->board_panel->Controls->Add(this->pb_H8);
			this->board_panel->Controls->Add(this->pb_G8);
			this->board_panel->Controls->Add(this->pb_F8);
			this->board_panel->Controls->Add(this->pb_E8);
			this->board_panel->Controls->Add(this->pb_D8);
			this->board_panel->Controls->Add(this->pb_C8);
			this->board_panel->Controls->Add(this->pb_B8);
			this->board_panel->Controls->Add(this->pb_A8);
			this->board_panel->Controls->Add(this->pb_B7);
			this->board_panel->Controls->Add(this->pb_H7);
			this->board_panel->Controls->Add(this->pb_F7);
			this->board_panel->Controls->Add(this->pb_D7);
			this->board_panel->Controls->Add(this->pb_G7);
			this->board_panel->Controls->Add(this->pb_E7);
			this->board_panel->Controls->Add(this->pb_C7);
			this->board_panel->Controls->Add(this->pb_A7);
			this->board_panel->Controls->Add(this->pb_A1);
			this->board_panel->Controls->Add(this->pb_C);
			this->board_panel->Controls->Add(this->pb_B2);
			this->board_panel->Controls->Add(this->pb_D2);
			this->board_panel->Controls->Add(this->pb_H1);
			this->board_panel->Controls->Add(this->pb_F2);
			this->board_panel->Controls->Add(this->pb_H2);
			this->board_panel->Controls->Add(this->pb_G1);
			this->board_panel->Controls->Add(this->pb_F1);
			this->board_panel->Controls->Add(this->pb_E1);
			this->board_panel->Controls->Add(this->pb_D1);
			this->board_panel->Controls->Add(this->pb_B1);
			this->board_panel->Controls->Add(this->pb_G2);
			this->board_panel->Controls->Add(this->pb_E2);
			this->board_panel->Controls->Add(this->pb_C2);
			this->board_panel->Controls->Add(this->time_white);
			this->board_panel->Controls->Add(this->label_whitetime);
			this->board_panel->Controls->Add(this->label_blacktime);
			this->board_panel->Controls->Add(this->time_black);
			this->board_panel->Controls->Add(this->picturebox_board);
			this->board_panel->Location = System::Drawing::Point(50, 57);
			this->board_panel->Name = L"board_panel";
			this->board_panel->Size = System::Drawing::Size(700, 469);
			this->board_panel->TabIndex = 0;
			// 
			// pb_A2
			// 
			this->pb_A2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_A2.Image")));
			this->pb_A2->Location = System::Drawing::Point(127, 352);
			this->pb_A2->Name = L"pb_A2";
			this->pb_A2->Size = System::Drawing::Size(48, 48);
			this->pb_A2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_A2->TabIndex = 40;
			this->pb_A2->TabStop = false;
			// 
			// pb_H8
			// 
			this->pb_H8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_H8.Image")));
			this->pb_H8->Location = System::Drawing::Point(521, 12);
			this->pb_H8->Name = L"pb_H8";
			this->pb_H8->Size = System::Drawing::Size(45, 48);
			this->pb_H8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_H8->TabIndex = 39;
			this->pb_H8->TabStop = false;
			// 
			// timeset_panel
			// 
			this->timeset_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->timeset_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->timeset_panel->Controls->Add(this->increment_panel);
			this->timeset_panel->Controls->Add(this->timeroptions_panel);
			this->timeset_panel->Controls->Add(this->label_minperside);
			this->timeset_panel->Controls->Add(this->trackbar_minperside);
			this->timeset_panel->Controls->Add(this->minperside_label);
			this->timeset_panel->Location = System::Drawing::Point(677, 112);
			this->timeset_panel->Name = L"timeset_panel";
			this->timeset_panel->Size = System::Drawing::Size(330, 232);
			this->timeset_panel->TabIndex = 6;
			this->timeset_panel->Visible = false;
			// 
			// increment_panel
			// 
			this->increment_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(125)));
			this->increment_panel->Controls->Add(this->trackbar_secincrement);
			this->increment_panel->Controls->Add(this->label_incpersec);
			this->increment_panel->Controls->Add(this->increment_label);
			this->increment_panel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->increment_panel->Location = System::Drawing::Point(0, 144);
			this->increment_panel->Name = L"increment_panel";
			this->increment_panel->Size = System::Drawing::Size(328, 86);
			this->increment_panel->TabIndex = 10;
			// 
			// trackbar_secincrement
			// 
			this->trackbar_secincrement->Location = System::Drawing::Point(41, 29);
			this->trackbar_secincrement->Name = L"trackbar_secincrement";
			this->trackbar_secincrement->Size = System::Drawing::Size(243, 56);
			this->trackbar_secincrement->TabIndex = 12;
			this->trackbar_secincrement->Scroll += gcnew System::EventHandler(this, &BoardForm::trackbar_secincrement_Scroll);
			// 
			// label_incpersec
			// 
			this->label_incpersec->AutoSize = true;
			this->label_incpersec->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_incpersec->Location = System::Drawing::Point(220, 8);
			this->label_incpersec->Name = L"label_incpersec";
			this->label_incpersec->Size = System::Drawing::Size(20, 23);
			this->label_incpersec->TabIndex = 13;
			this->label_incpersec->Text = L"0";
			// 
			// increment_label
			// 
			this->increment_label->AutoSize = true;
			this->increment_label->BackColor = System::Drawing::Color::Transparent;
			this->increment_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->increment_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->increment_label->Location = System::Drawing::Point(107, 9);
			this->increment_label->Name = L"increment_label";
			this->increment_label->Size = System::Drawing::Size(115, 17);
			this->increment_label->TabIndex = 11;
			this->increment_label->Text = L"Increment per sec:";
			// 
			// timeroptions_panel
			// 
			this->timeroptions_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(125)));
			this->timeroptions_panel->Controls->Add(this->save_time_button);
			this->timeroptions_panel->Controls->Add(this->close_timepanel);
			this->timeroptions_panel->Controls->Add(this->time_controllabel);
			this->timeroptions_panel->Controls->Add(this->time_options_box);
			this->timeroptions_panel->Dock = System::Windows::Forms::DockStyle::Top;
			this->timeroptions_panel->Location = System::Drawing::Point(0, 0);
			this->timeroptions_panel->Name = L"timeroptions_panel";
			this->timeroptions_panel->Size = System::Drawing::Size(328, 56);
			this->timeroptions_panel->TabIndex = 9;
			// 
			// save_time_button
			// 
			this->save_time_button->BackColor = System::Drawing::Color::Black;
			this->save_time_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->save_time_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->save_time_button->ForeColor = System::Drawing::Color::White;
			this->save_time_button->Location = System::Drawing::Point(3, 14);
			this->save_time_button->Name = L"save_time_button";
			this->save_time_button->Size = System::Drawing::Size(49, 25);
			this->save_time_button->TabIndex = 11;
			this->save_time_button->Text = L"Set";
			this->save_time_button->UseVisualStyleBackColor = false;
			this->save_time_button->Click += gcnew System::EventHandler(this, &BoardForm::button1_Click);
			// 
			// close_timepanel
			// 
			this->close_timepanel->BackColor = System::Drawing::Color::Black;
			this->close_timepanel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->close_timepanel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 6.8F, System::Drawing::FontStyle::Bold));
			this->close_timepanel->ForeColor = System::Drawing::Color::White;
			this->close_timepanel->Location = System::Drawing::Point(307, -1);
			this->close_timepanel->Name = L"close_timepanel";
			this->close_timepanel->Size = System::Drawing::Size(22, 23);
			this->close_timepanel->TabIndex = 12;
			this->close_timepanel->Text = L"X";
			this->close_timepanel->UseVisualStyleBackColor = false;
			this->close_timepanel->Click += gcnew System::EventHandler(this, &BoardForm::close_timepanel_Click);
			// 
			// time_controllabel
			// 
			this->time_controllabel->AutoSize = true;
			this->time_controllabel->BackColor = System::Drawing::Color::Transparent;
			this->time_controllabel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->time_controllabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->time_controllabel->Location = System::Drawing::Point(58, 16);
			this->time_controllabel->Name = L"time_controllabel";
			this->time_controllabel->Size = System::Drawing::Size(111, 25);
			this->time_controllabel->TabIndex = 7;
			this->time_controllabel->Text = L"Time control";
			// 
			// time_options_box
			// 
			this->time_options_box->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->time_options_box->ForeColor = System::Drawing::SystemColors::WindowText;
			this->time_options_box->FormattingEnabled = true;
			this->time_options_box->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Real time", L"Unlimited" });
			this->time_options_box->Location = System::Drawing::Point(153, 13);
			this->time_options_box->Name = L"time_options_box";
			this->time_options_box->Size = System::Drawing::Size(131, 28);
			this->time_options_box->TabIndex = 8;
			this->time_options_box->Text = L"Real time";
			// 
			// label_minperside
			// 
			this->label_minperside->AutoSize = true;
			this->label_minperside->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_minperside->Location = System::Drawing::Point(220, 58);
			this->label_minperside->Name = L"label_minperside";
			this->label_minperside->Size = System::Drawing::Size(20, 23);
			this->label_minperside->TabIndex = 12;
			this->label_minperside->Text = L"1";
			// 
			// trackbar_minperside
			// 
			this->trackbar_minperside->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->trackbar_minperside->Location = System::Drawing::Point(41, 82);
			this->trackbar_minperside->Name = L"trackbar_minperside";
			this->trackbar_minperside->Size = System::Drawing::Size(243, 56);
			this->trackbar_minperside->TabIndex = 11;
			this->trackbar_minperside->Scroll += gcnew System::EventHandler(this, &BoardForm::trackbar_minperside_Scroll);
			// 
			// minperside_label
			// 
			this->minperside_label->AutoSize = true;
			this->minperside_label->BackColor = System::Drawing::Color::Transparent;
			this->minperside_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minperside_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->minperside_label->Location = System::Drawing::Point(107, 59);
			this->minperside_label->Name = L"minperside_label";
			this->minperside_label->Size = System::Drawing::Size(109, 17);
			this->minperside_label->TabIndex = 9;
			this->minperside_label->Text = L"Minutes per side:";
			// 
			// pb_G8
			// 
			this->pb_G8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_G8.Image")));
			this->pb_G8->Location = System::Drawing::Point(466, 12);
			this->pb_G8->Name = L"pb_G8";
			this->pb_G8->Size = System::Drawing::Size(48, 48);
			this->pb_G8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_G8->TabIndex = 38;
			this->pb_G8->TabStop = false;
			// 
			// pb_F8
			// 
			this->pb_F8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_F8.Image")));
			this->pb_F8->Location = System::Drawing::Point(410, 12);
			this->pb_F8->Name = L"pb_F8";
			this->pb_F8->Size = System::Drawing::Size(48, 48);
			this->pb_F8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_F8->TabIndex = 37;
			this->pb_F8->TabStop = false;
			// 
			// pb_E8
			// 
			this->pb_E8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_E8.Image")));
			this->pb_E8->Location = System::Drawing::Point(356, 12);
			this->pb_E8->Name = L"pb_E8";
			this->pb_E8->Size = System::Drawing::Size(48, 48);
			this->pb_E8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_E8->TabIndex = 36;
			this->pb_E8->TabStop = false;
			// 
			// pb_D8
			// 
			this->pb_D8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_D8.Image")));
			this->pb_D8->Location = System::Drawing::Point(297, 12);
			this->pb_D8->Name = L"pb_D8";
			this->pb_D8->Size = System::Drawing::Size(48, 48);
			this->pb_D8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_D8->TabIndex = 35;
			this->pb_D8->TabStop = false;
			// 
			// pb_C8
			// 
			this->pb_C8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_C8.Image")));
			this->pb_C8->Location = System::Drawing::Point(242, 12);
			this->pb_C8->Name = L"pb_C8";
			this->pb_C8->Size = System::Drawing::Size(48, 48);
			this->pb_C8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_C8->TabIndex = 34;
			this->pb_C8->TabStop = false;
			// 
			// pb_B8
			// 
			this->pb_B8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_B8.Image")));
			this->pb_B8->Location = System::Drawing::Point(183, 12);
			this->pb_B8->Name = L"pb_B8";
			this->pb_B8->Size = System::Drawing::Size(48, 48);
			this->pb_B8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_B8->TabIndex = 33;
			this->pb_B8->TabStop = false;
			// 
			// pb_A8
			// 
			this->pb_A8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_A8.Image")));
			this->pb_A8->Location = System::Drawing::Point(123, 12);
			this->pb_A8->Name = L"pb_A8";
			this->pb_A8->Size = System::Drawing::Size(48, 48);
			this->pb_A8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_A8->TabIndex = 32;
			this->pb_A8->TabStop = false;
			// 
			// pb_B7
			// 
			this->pb_B7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_B7.Image")));
			this->pb_B7->Location = System::Drawing::Point(183, 67);
			this->pb_B7->Name = L"pb_B7";
			this->pb_B7->Size = System::Drawing::Size(48, 48);
			this->pb_B7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_B7->TabIndex = 31;
			this->pb_B7->TabStop = false;
			// 
			// pb_H7
			// 
			this->pb_H7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_H7.Image")));
			this->pb_H7->Location = System::Drawing::Point(521, 67);
			this->pb_H7->Name = L"pb_H7";
			this->pb_H7->Size = System::Drawing::Size(45, 48);
			this->pb_H7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_H7->TabIndex = 30;
			this->pb_H7->TabStop = false;
			// 
			// pb_F7
			// 
			this->pb_F7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_F7.Image")));
			this->pb_F7->Location = System::Drawing::Point(410, 67);
			this->pb_F7->Name = L"pb_F7";
			this->pb_F7->Size = System::Drawing::Size(48, 48);
			this->pb_F7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_F7->TabIndex = 29;
			this->pb_F7->TabStop = false;
			// 
			// pb_D7
			// 
			this->pb_D7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_D7.Image")));
			this->pb_D7->Location = System::Drawing::Point(297, 67);
			this->pb_D7->Name = L"pb_D7";
			this->pb_D7->Size = System::Drawing::Size(48, 48);
			this->pb_D7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_D7->TabIndex = 28;
			this->pb_D7->TabStop = false;
			// 
			// pb_G7
			// 
			this->pb_G7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_G7.Image")));
			this->pb_G7->Location = System::Drawing::Point(470, 67);
			this->pb_G7->Name = L"pb_G7";
			this->pb_G7->Size = System::Drawing::Size(48, 48);
			this->pb_G7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_G7->TabIndex = 27;
			this->pb_G7->TabStop = false;
			// 
			// pb_E7
			// 
			this->pb_E7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_E7.Image")));
			this->pb_E7->Location = System::Drawing::Point(356, 67);
			this->pb_E7->Name = L"pb_E7";
			this->pb_E7->Size = System::Drawing::Size(48, 48);
			this->pb_E7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_E7->TabIndex = 26;
			this->pb_E7->TabStop = false;
			// 
			// pb_C7
			// 
			this->pb_C7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_C7.Image")));
			this->pb_C7->Location = System::Drawing::Point(238, 67);
			this->pb_C7->Name = L"pb_C7";
			this->pb_C7->Size = System::Drawing::Size(48, 48);
			this->pb_C7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_C7->TabIndex = 25;
			this->pb_C7->TabStop = false;
			// 
			// pb_A7
			// 
			this->pb_A7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_A7.Image")));
			this->pb_A7->Location = System::Drawing::Point(123, 67);
			this->pb_A7->Name = L"pb_A7";
			this->pb_A7->Size = System::Drawing::Size(48, 48);
			this->pb_A7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_A7->TabIndex = 24;
			this->pb_A7->TabStop = false;
			// 
			// pb_A1
			// 
			this->pb_A1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_A1.Image")));
			this->pb_A1->Location = System::Drawing::Point(127, 411);
			this->pb_A1->Name = L"pb_A1";
			this->pb_A1->Size = System::Drawing::Size(48, 48);
			this->pb_A1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_A1->TabIndex = 22;
			this->pb_A1->TabStop = false;
			// 
			// pb_C
			// 
			this->pb_C->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_C.Image")));
			this->pb_C->Location = System::Drawing::Point(238, 411);
			this->pb_C->Name = L"pb_C";
			this->pb_C->Size = System::Drawing::Size(48, 48);
			this->pb_C->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_C->TabIndex = 21;
			this->pb_C->TabStop = false;
			// 
			// pb_B2
			// 
			this->pb_B2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_B2.Image")));
			this->pb_B2->Location = System::Drawing::Point(183, 352);
			this->pb_B2->Name = L"pb_B2";
			this->pb_B2->Size = System::Drawing::Size(48, 48);
			this->pb_B2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_B2->TabIndex = 20;
			this->pb_B2->TabStop = false;
			// 
			// pb_D2
			// 
			this->pb_D2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_D2.Image")));
			this->pb_D2->Location = System::Drawing::Point(297, 352);
			this->pb_D2->Name = L"pb_D2";
			this->pb_D2->Size = System::Drawing::Size(48, 48);
			this->pb_D2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_D2->TabIndex = 19;
			this->pb_D2->TabStop = false;
			// 
			// pb_H1
			// 
			this->pb_H1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_H1.Image")));
			this->pb_H1->Location = System::Drawing::Point(521, 411);
			this->pb_H1->Name = L"pb_H1";
			this->pb_H1->Size = System::Drawing::Size(45, 48);
			this->pb_H1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_H1->TabIndex = 18;
			this->pb_H1->TabStop = false;
			// 
			// pb_F2
			// 
			this->pb_F2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_F2.Image")));
			this->pb_F2->Location = System::Drawing::Point(410, 352);
			this->pb_F2->Name = L"pb_F2";
			this->pb_F2->Size = System::Drawing::Size(48, 48);
			this->pb_F2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_F2->TabIndex = 17;
			this->pb_F2->TabStop = false;
			// 
			// pb_H2
			// 
			this->pb_H2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_H2.Image")));
			this->pb_H2->Location = System::Drawing::Point(521, 352);
			this->pb_H2->Name = L"pb_H2";
			this->pb_H2->Size = System::Drawing::Size(45, 48);
			this->pb_H2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_H2->TabIndex = 16;
			this->pb_H2->TabStop = false;
			// 
			// pb_G1
			// 
			this->pb_G1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_G1.Image")));
			this->pb_G1->Location = System::Drawing::Point(466, 411);
			this->pb_G1->Name = L"pb_G1";
			this->pb_G1->Size = System::Drawing::Size(48, 48);
			this->pb_G1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_G1->TabIndex = 15;
			this->pb_G1->TabStop = false;
			// 
			// pb_F1
			// 
			this->pb_F1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_F1.Image")));
			this->pb_F1->Location = System::Drawing::Point(410, 411);
			this->pb_F1->Name = L"pb_F1";
			this->pb_F1->Size = System::Drawing::Size(48, 48);
			this->pb_F1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_F1->TabIndex = 14;
			this->pb_F1->TabStop = false;
			// 
			// pb_E1
			// 
			this->pb_E1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_E1.Image")));
			this->pb_E1->Location = System::Drawing::Point(354, 411);
			this->pb_E1->Name = L"pb_E1";
			this->pb_E1->Size = System::Drawing::Size(48, 48);
			this->pb_E1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_E1->TabIndex = 13;
			this->pb_E1->TabStop = false;
			// 
			// pb_D1
			// 
			this->pb_D1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_D1.Image")));
			this->pb_D1->Location = System::Drawing::Point(297, 411);
			this->pb_D1->Name = L"pb_D1";
			this->pb_D1->Size = System::Drawing::Size(48, 48);
			this->pb_D1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_D1->TabIndex = 12;
			this->pb_D1->TabStop = false;
			// 
			// pb_B1
			// 
			this->pb_B1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_B1.Image")));
			this->pb_B1->Location = System::Drawing::Point(183, 411);
			this->pb_B1->Name = L"pb_B1";
			this->pb_B1->Size = System::Drawing::Size(48, 48);
			this->pb_B1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_B1->TabIndex = 11;
			this->pb_B1->TabStop = false;
			// 
			// pb_G2
			// 
			this->pb_G2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_G2.Image")));
			this->pb_G2->Location = System::Drawing::Point(470, 352);
			this->pb_G2->Name = L"pb_G2";
			this->pb_G2->Size = System::Drawing::Size(48, 48);
			this->pb_G2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_G2->TabIndex = 10;
			this->pb_G2->TabStop = false;
			// 
			// pb_E2
			// 
			this->pb_E2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_E2.Image")));
			this->pb_E2->Location = System::Drawing::Point(354, 352);
			this->pb_E2->Name = L"pb_E2";
			this->pb_E2->Size = System::Drawing::Size(48, 48);
			this->pb_E2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_E2->TabIndex = 9;
			this->pb_E2->TabStop = false;
			// 
			// pb_C2
			// 
			this->pb_C2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_C2.Image")));
			this->pb_C2->Location = System::Drawing::Point(238, 352);
			this->pb_C2->Name = L"pb_C2";
			this->pb_C2->Size = System::Drawing::Size(48, 48);
			this->pb_C2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pb_C2->TabIndex = 8;
			this->pb_C2->TabStop = false;
			// 
			// time_white
			// 
			this->time_white->AutoSize = true;
			this->time_white->BackColor = System::Drawing::Color::Gray;
			this->time_white->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->time_white->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->time_white->Location = System::Drawing::Point(601, 296);
			this->time_white->Name = L"time_white";
			this->time_white->Size = System::Drawing::Size(0, 50);
			this->time_white->TabIndex = 4;
			this->time_white->Visible = false;
			// 
			// label_whitetime
			// 
			this->label_whitetime->AutoSize = true;
			this->label_whitetime->BackColor = System::Drawing::Color::Gray;
			this->label_whitetime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_whitetime->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_whitetime->Location = System::Drawing::Point(602, 250);
			this->label_whitetime->Name = L"label_whitetime";
			this->label_whitetime->Size = System::Drawing::Size(94, 43);
			this->label_whitetime->TabIndex = 3;
			this->label_whitetime->Text = L" White";
			this->label_whitetime->Visible = false;
			// 
			// label_blacktime
			// 
			this->label_blacktime->AutoSize = true;
			this->label_blacktime->BackColor = System::Drawing::Color::Gray;
			this->label_blacktime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_blacktime->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_blacktime->Location = System::Drawing::Point(602, 12);
			this->label_blacktime->Name = L"label_blacktime";
			this->label_blacktime->Size = System::Drawing::Size(80, 43);
			this->label_blacktime->TabIndex = 2;
			this->label_blacktime->Text = L"Black";
			this->label_blacktime->Visible = false;
			// 
			// time_black
			// 
			this->time_black->AutoSize = true;
			this->time_black->BackColor = System::Drawing::Color::Gray;
			this->time_black->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->time_black->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->time_black->Location = System::Drawing::Point(601, 43);
			this->time_black->Name = L"time_black";
			this->time_black->Size = System::Drawing::Size(0, 50);
			this->time_black->TabIndex = 5;
			this->time_black->Visible = false;
			// 
			// picturebox_board
			// 
			this->picturebox_board->BackColor = System::Drawing::Color::Gray;
			this->picturebox_board->Dock = System::Windows::Forms::DockStyle::Fill;
			this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg";
			this->picturebox_board->Location = System::Drawing::Point(0, 0);
			this->picturebox_board->Name = L"picturebox_board";
			this->picturebox_board->Size = System::Drawing::Size(700, 469);
			this->picturebox_board->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picturebox_board->TabIndex = 6;
			this->picturebox_board->TabStop = false;
			this->picturebox_board->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::picturebox_board_MouseDown_1);
			this->picturebox_board->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::picturebox_board_MouseMove_1);
			this->picturebox_board->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::picturebox_board_MouseUp_1);
			// 
			// chess_menu
			// 
			this->chess_menu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->chess_menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->chess_menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->flipBoardToolStripMenuItem });
			this->chess_menu->Location = System::Drawing::Point(0, 0);
			this->chess_menu->Name = L"chess_menu";
			this->chess_menu->Size = System::Drawing::Size(799, 41);
			this->chess_menu->TabIndex = 2;
			this->chess_menu->Text = L"Menu";
			// 
			// flipBoardToolStripMenuItem
			// 
			this->flipBoardToolStripMenuItem->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->flipBoardToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->flipBoardToolStripMenuItem1,
					this->setTimeToolStripMenuItem, this->restartToolStripMenuItem1, this->exitToolStripMenuItem
			});
			this->flipBoardToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->flipBoardToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->flipBoardToolStripMenuItem->Name = L"flipBoardToolStripMenuItem";
			this->flipBoardToolStripMenuItem->Size = System::Drawing::Size(103, 37);
			this->flipBoardToolStripMenuItem->Text = L"Options";
			// 
			// flipBoardToolStripMenuItem1
			// 
			this->flipBoardToolStripMenuItem1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->flipBoardToolStripMenuItem1->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->flipBoardToolStripMenuItem1->ForeColor = System::Drawing::Color::White;
			this->flipBoardToolStripMenuItem1->Name = L"flipBoardToolStripMenuItem1";
			this->flipBoardToolStripMenuItem1->Size = System::Drawing::Size(183, 34);
			this->flipBoardToolStripMenuItem1->Text = L"Flip Board";
			this->flipBoardToolStripMenuItem1->Click += gcnew System::EventHandler(this, &BoardForm::flipBoardToolStripMenuItem1_Click);
			// 
			// setTimeToolStripMenuItem
			// 
			this->setTimeToolStripMenuItem->BackColor = System::Drawing::Color::Black;
			this->setTimeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->setTimeToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->setTimeToolStripMenuItem->Name = L"setTimeToolStripMenuItem";
			this->setTimeToolStripMenuItem->Size = System::Drawing::Size(183, 34);
			this->setTimeToolStripMenuItem->Text = L"Set time";
			this->setTimeToolStripMenuItem->Click += gcnew System::EventHandler(this, &BoardForm::setTimeToolStripMenuItem_Click);
			// 
			// restartToolStripMenuItem1
			// 
			this->restartToolStripMenuItem1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->restartToolStripMenuItem1->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->restartToolStripMenuItem1->ForeColor = System::Drawing::Color::White;
			this->restartToolStripMenuItem1->Name = L"restartToolStripMenuItem1";
			this->restartToolStripMenuItem1->Size = System::Drawing::Size(183, 34);
			this->restartToolStripMenuItem1->Text = L"Restart";
			this->restartToolStripMenuItem1->Click += gcnew System::EventHandler(this, &BoardForm::restartToolStripMenuItem1_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->BackColor = System::Drawing::Color::Black;
			this->exitToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Sitka Banner", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->exitToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(183, 34);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &BoardForm::exitToolStripMenuItem_Click);
			// 
			// menu_timer_black
			// 
			this->menu_timer_black->Interval = 1000;
			this->menu_timer_black->Tick += gcnew System::EventHandler(this, &BoardForm::menu_timer_Tick);
			// 
			// menu_timer_white
			// 
			this->menu_timer_white->Interval = 1000;
			this->menu_timer_white->Tick += gcnew System::EventHandler(this, &BoardForm::menu_timer_white_Tick);
			// 
			// pb_B3
			// 
			this->pb_B3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_B3.Image")));
			this->pb_B3->Location = System::Drawing::Point(183, 296);
			this->pb_B3->Name = L"pb_B3";
			this->pb_B3->Size = System::Drawing::Size(48, 48);
			this->pb_B3->TabIndex = 41;
			this->pb_B3->TabStop = false;
			// 
			// pb_D3
			// 
			this->pb_D3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_D3.Image")));
			this->pb_D3->Location = System::Drawing::Point(297, 296);
			this->pb_D3->Name = L"pb_D3";
			this->pb_D3->Size = System::Drawing::Size(48, 48);
			this->pb_D3->TabIndex = 42;
			this->pb_D3->TabStop = false;
			// 
			// pb_E3
			// 
			this->pb_E3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_E3.Image")));
			this->pb_E3->Location = System::Drawing::Point(354, 296);
			this->pb_E3->Name = L"pb_E3";
			this->pb_E3->Size = System::Drawing::Size(48, 48);
			this->pb_E3->TabIndex = 43;
			this->pb_E3->TabStop = false;
			// 
			// pb_G3
			// 
			this->pb_G3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_G3.Image")));
			this->pb_G3->Location = System::Drawing::Point(470, 296);
			this->pb_G3->Name = L"pb_G3";
			this->pb_G3->Size = System::Drawing::Size(48, 48);
			this->pb_G3->TabIndex = 44;
			this->pb_G3->TabStop = false;
			// 
			// pb_H4
			// 
			this->pb_H4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_H4.Image")));
			this->pb_H4->Location = System::Drawing::Point(521, 237);
			this->pb_H4->Name = L"pb_H4";
			this->pb_H4->Size = System::Drawing::Size(45, 48);
			this->pb_H4->TabIndex = 45;
			this->pb_H4->TabStop = false;
			// 
			// pb_H6
			// 
			this->pb_H6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_H6.Image")));
			this->pb_H6->Location = System::Drawing::Point(521, 124);
			this->pb_H6->Name = L"pb_H6";
			this->pb_H6->Size = System::Drawing::Size(45, 48);
			this->pb_H6->TabIndex = 46;
			this->pb_H6->TabStop = false;
			// 
			// pb_F4
			// 
			this->pb_F4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_F4.Image")));
			this->pb_F4->Location = System::Drawing::Point(411, 237);
			this->pb_F4->Name = L"pb_F4";
			this->pb_F4->Size = System::Drawing::Size(48, 48);
			this->pb_F4->TabIndex = 47;
			this->pb_F4->TabStop = false;
			// 
			// pb_D4
			// 
			this->pb_D4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_D4.Image")));
			this->pb_D4->Location = System::Drawing::Point(297, 237);
			this->pb_D4->Name = L"pb_D4";
			this->pb_D4->Size = System::Drawing::Size(48, 48);
			this->pb_D4->TabIndex = 48;
			this->pb_D4->TabStop = false;
			// 
			// pb_B4
			// 
			this->pb_B4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_B4.Image")));
			this->pb_B4->Location = System::Drawing::Point(183, 237);
			this->pb_B4->Name = L"pb_B4";
			this->pb_B4->Size = System::Drawing::Size(48, 48);
			this->pb_B4->TabIndex = 49;
			this->pb_B4->TabStop = false;
			// 
			// pb_A3
			// 
			this->pb_A3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_A3.Image")));
			this->pb_A3->Location = System::Drawing::Point(124, 296);
			this->pb_A3->Name = L"pb_A3";
			this->pb_A3->Size = System::Drawing::Size(48, 48);
			this->pb_A3->TabIndex = 50;
			this->pb_A3->TabStop = false;
			// 
			// pb_A5
			// 
			this->pb_A5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_A5.Image")));
			this->pb_A5->Location = System::Drawing::Point(124, 183);
			this->pb_A5->Name = L"pb_A5";
			this->pb_A5->Size = System::Drawing::Size(48, 48);
			this->pb_A5->TabIndex = 51;
			this->pb_A5->TabStop = false;
			// 
			// pb_B6
			// 
			this->pb_B6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_B6.Image")));
			this->pb_B6->Location = System::Drawing::Point(183, 124);
			this->pb_B6->Name = L"pb_B6";
			this->pb_B6->Size = System::Drawing::Size(48, 48);
			this->pb_B6->TabIndex = 52;
			this->pb_B6->TabStop = false;
			// 
			// pb_C5
			// 
			this->pb_C5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_C5.Image")));
			this->pb_C5->Location = System::Drawing::Point(243, 183);
			this->pb_C5->Name = L"pb_C5";
			this->pb_C5->Size = System::Drawing::Size(48, 48);
			this->pb_C5->TabIndex = 53;
			this->pb_C5->TabStop = false;
			// 
			// pb_E5
			// 
			this->pb_E5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_E5.Image")));
			this->pb_E5->Location = System::Drawing::Point(353, 183);
			this->pb_E5->Name = L"pb_E5";
			this->pb_E5->Size = System::Drawing::Size(48, 48);
			this->pb_E5->TabIndex = 54;
			this->pb_E5->TabStop = false;
			// 
			// pb_D6
			// 
			this->pb_D6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_D6.Image")));
			this->pb_D6->Location = System::Drawing::Point(297, 124);
			this->pb_D6->Name = L"pb_D6";
			this->pb_D6->Size = System::Drawing::Size(48, 48);
			this->pb_D6->TabIndex = 55;
			this->pb_D6->TabStop = false;
			// 
			// pb_F6
			// 
			this->pb_F6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_F6.Image")));
			this->pb_F6->Location = System::Drawing::Point(411, 124);
			this->pb_F6->Name = L"pb_F6";
			this->pb_F6->Size = System::Drawing::Size(48, 48);
			this->pb_F6->TabIndex = 56;
			this->pb_F6->TabStop = false;
			// 
			// pb_G5
			// 
			this->pb_G5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_G5.Image")));
			this->pb_G5->Location = System::Drawing::Point(467, 183);
			this->pb_G5->Name = L"pb_G5";
			this->pb_G5->Size = System::Drawing::Size(48, 48);
			this->pb_G5->TabIndex = 57;
			this->pb_G5->TabStop = false;
			// 
			// pb_C3
			// 
			this->pb_C3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_C3.Image")));
			this->pb_C3->Location = System::Drawing::Point(242, 296);
			this->pb_C3->Name = L"pb_C3";
			this->pb_C3->Size = System::Drawing::Size(48, 48);
			this->pb_C3->TabIndex = 58;
			this->pb_C3->TabStop = false;
			// 
			// pb_F3
			// 
			this->pb_F3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_F3.Image")));
			this->pb_F3->Location = System::Drawing::Point(408, 296);
			this->pb_F3->Name = L"pb_F3";
			this->pb_F3->Size = System::Drawing::Size(48, 48);
			this->pb_F3->TabIndex = 59;
			this->pb_F3->TabStop = false;
			// 
			// pb_E4
			// 
			this->pb_E4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_E4.Image")));
			this->pb_E4->Location = System::Drawing::Point(354, 237);
			this->pb_E4->Name = L"pb_E4";
			this->pb_E4->Size = System::Drawing::Size(48, 48);
			this->pb_E4->TabIndex = 60;
			this->pb_E4->TabStop = false;
			// 
			// pb_C4
			// 
			this->pb_C4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_C4.Image")));
			this->pb_C4->Location = System::Drawing::Point(239, 237);
			this->pb_C4->Name = L"pb_C4";
			this->pb_C4->Size = System::Drawing::Size(48, 48);
			this->pb_C4->TabIndex = 61;
			this->pb_C4->TabStop = false;
			// 
			// pb_A4
			// 
			this->pb_A4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_A4.Image")));
			this->pb_A4->Location = System::Drawing::Point(124, 237);
			this->pb_A4->Name = L"pb_A4";
			this->pb_A4->Size = System::Drawing::Size(48, 48);
			this->pb_A4->TabIndex = 62;
			this->pb_A4->TabStop = false;
			// 
			// pb_a6
			// 
			this->pb_a6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_a6.Image")));
			this->pb_a6->Location = System::Drawing::Point(124, 124);
			this->pb_a6->Name = L"pb_a6";
			this->pb_a6->Size = System::Drawing::Size(48, 48);
			this->pb_a6->TabIndex = 63;
			this->pb_a6->TabStop = false;
			// 
			// pb_D5
			// 
			this->pb_D5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_D5.Image")));
			this->pb_D5->Location = System::Drawing::Point(297, 183);
			this->pb_D5->Name = L"pb_D5";
			this->pb_D5->Size = System::Drawing::Size(48, 48);
			this->pb_D5->TabIndex = 64;
			this->pb_D5->TabStop = false;
			// 
			// pb_E6
			// 
			this->pb_E6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_E6.Image")));
			this->pb_E6->Location = System::Drawing::Point(353, 124);
			this->pb_E6->Name = L"pb_E6";
			this->pb_E6->Size = System::Drawing::Size(48, 48);
			this->pb_E6->TabIndex = 65;
			this->pb_E6->TabStop = false;
			// 
			// pb_F5
			// 
			this->pb_F5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_F5.Image")));
			this->pb_F5->Location = System::Drawing::Point(408, 183);
			this->pb_F5->Name = L"pb_F5";
			this->pb_F5->Size = System::Drawing::Size(48, 48);
			this->pb_F5->TabIndex = 66;
			this->pb_F5->TabStop = false;
			// 
			// pb_H5
			// 
			this->pb_H5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_H5.Image")));
			this->pb_H5->Location = System::Drawing::Point(521, 183);
			this->pb_H5->Name = L"pb_H5";
			this->pb_H5->Size = System::Drawing::Size(45, 48);
			this->pb_H5->TabIndex = 67;
			this->pb_H5->TabStop = false;
			// 
			// pb_G6
			// 
			this->pb_G6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_G6.Image")));
			this->pb_G6->Location = System::Drawing::Point(467, 124);
			this->pb_G6->Name = L"pb_G6";
			this->pb_G6->Size = System::Drawing::Size(48, 48);
			this->pb_G6->TabIndex = 68;
			this->pb_G6->TabStop = false;
			// 
			// pb_G4
			// 
			this->pb_G4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_G4.Image")));
			this->pb_G4->Location = System::Drawing::Point(470, 237);
			this->pb_G4->Name = L"pb_G4";
			this->pb_G4->Size = System::Drawing::Size(48, 48);
			this->pb_G4->TabIndex = 69;
			this->pb_G4->TabStop = false;
			// 
			// pb_H3
			// 
			this->pb_H3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_H3.Image")));
			this->pb_H3->Location = System::Drawing::Point(521, 296);
			this->pb_H3->Name = L"pb_H3";
			this->pb_H3->Size = System::Drawing::Size(45, 48);
			this->pb_H3->TabIndex = 70;
			this->pb_H3->TabStop = false;
			// 
			// pb_C6
			// 
			this->pb_C6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_C6.Image")));
			this->pb_C6->Location = System::Drawing::Point(239, 124);
			this->pb_C6->Name = L"pb_C6";
			this->pb_C6->Size = System::Drawing::Size(48, 48);
			this->pb_C6->TabIndex = 71;
			this->pb_C6->TabStop = false;
			// 
			// pb_B5
			// 
			this->pb_B5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_B5.Image")));
			this->pb_B5->Location = System::Drawing::Point(183, 183);
			this->pb_B5->Name = L"pb_B5";
			this->pb_B5->Size = System::Drawing::Size(48, 48);
			this->pb_B5->TabIndex = 72;
			this->pb_B5->TabStop = false;
			// 
			// BoardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->ClientSize = System::Drawing::Size(799, 538);
			this->Controls->Add(this->board_panel);
			this->Controls->Add(this->chess_menu);
			this->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ForeColor = System::Drawing::Color::White;
			this->MainMenuStrip = this->chess_menu;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(817, 585);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(817, 585);
			this->Name = L"BoardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BoardForm";
			this->board_panel->ResumeLayout(false);
			this->board_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H8))->EndInit();
			this->timeset_panel->ResumeLayout(false);
			this->timeset_panel->PerformLayout();
			this->increment_panel->ResumeLayout(false);
			this->increment_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_secincrement))->EndInit();
			this->timeroptions_panel->ResumeLayout(false);
			this->timeroptions_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_minperside))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->EndInit();
			this->chess_menu->ResumeLayout(false);
			this->chess_menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_A4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_a6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_D5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_E6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_F5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_G4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_H3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_C6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_B5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//chess board init
	
		//flip board
	   Point start_black = Point(602, 12);
	   Point start_white = Point(602, 250);

private: System::Void flipBoardToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->picturebox_board->ImageLocation == L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg")
	{
		this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\flipedboard1.jpg";
		picturebox_board->Refresh();
		label_blacktime->Location = start_white;
		label_whitetime->Location = start_black;
	}
	else
	{
		this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg";
		picturebox_board->Refresh();
		label_blacktime->Location = start_black;
		label_whitetime->Location = start_white;
	}

}
	   //open panel with time
private: System::Void setTimeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	timeset_panel->Visible = true;
	timeset_panel->Enabled = true;
}
	 //set button set time 
	   int seconds, seconds_white;
	   int increment;
	   //on move true == white on move
	   bool on_move = true;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	timeset_panel->Visible = false;
	//set time for black pieces
	if (time_options_box->Text == "Real time")
	{
		//test time
		//black
		menu_timer_black->Enabled = true;
		time_black->Visible = true;
		//white
		menu_timer_white->Enabled = true;
		time_white->Visible = true;
		//switch black
		switch (trackbar_minperside->Value)
		{
		case 0:
			seconds = 60;
			break;
		case 1:
			seconds = 120;
			break;
		case 2:
			seconds = 180;
			break;
		case 3:
			seconds = 300;
			break;
		case 4:
			seconds = 600;
			break;
		case 5:
			seconds = 900;
			break;
		case 6:
			seconds = 1200;
			break;
		case 7:
			seconds = 1800;
			break;
		case 8:
			seconds = 3600;
			break;
		case 9:
			seconds = 7200;
			break;
		case 10:
			seconds = 10800;
			break;
		}
		//switch white
		seconds_white = seconds;
		//add increment
		increment = trackbar_secincrement->Value;
	}
	else
	{
		//black
		menu_timer_black->Enabled = false;
		label_blacktime->Visible = false;
		time_black->Visible = false;
		//white
		menu_timer_white->Enabled = false;
		label_whitetime->Visible = false;
		time_white->Visible = false;
	}

}
	   //set time
private: System::Void trackbar_minperside_Scroll(System::Object^ sender, System::EventArgs^ e) {
	switch (trackbar_minperside->Value)
	{
	case 0:
		label_minperside->Text = "1";
		break;
	case 1:
		label_minperside->Text = "2";
		break;
	case 2:
		label_minperside->Text = "3";
		break;
	case 3:
		label_minperside->Text = "5";
		break;
	case 4:
		label_minperside->Text = "10";
		break;
	case 5:
		label_minperside->Text = "15";
		break;
	case 6:
		label_minperside->Text = "20";
		break;
	case 7:
		label_minperside->Text = "30";
		break;
	case 8:
		label_minperside->Text = "60";
		break;
	case 9:
		label_minperside->Text = "120";
		break;
	case 10:
		label_minperside->Text = "180";
		break;
	default:
		label_minperside->Text = "Incoret value";
		break;
	}
}
	   //set increment
private: System::Void trackbar_secincrement_Scroll(System::Object^ sender, System::EventArgs^ e) {
	switch (trackbar_secincrement->Value)
	{
	case 0:
		label_incpersec->Text = "0";
		break;
	case 1:
		label_incpersec->Text = "1";
		break;
	case 2:
		label_incpersec->Text = "2";
		break;
	case 3:
		label_incpersec->Text = "3";
		break;
	case 4:
		label_incpersec->Text = "4";
		break;
	case 5:
		label_incpersec->Text = "5";
		break;
	case 6:
		label_incpersec->Text = "6";
		break;
	case 7:
		label_incpersec->Text = "7";
		break;
	case 8:
		label_incpersec->Text = "8";
		break;
	case 9:
		label_incpersec->Text = "9";
		break;
	case 10:
		label_incpersec->Text = "10";
		break;
	default:
		label_incpersec->Text = "Incoret value";
		break;
	}
}

	   //black timer tick
private: System::Void menu_timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		seconds--;
		int minutes = seconds / 60;
		int sec = seconds - minutes * 60;
		label_blacktime->Visible = true;
		time_black->Text = "0" + Convert::ToString(minutes) + ":" + Convert::ToString(sec);

		if (sec < 10)
			time_black->Text = "0" + Convert::ToString(minutes) + ":" + "0" + Convert::ToString(sec);

		if (minutes > 10)
			time_black->Text = Convert::ToString(minutes) + ":" + Convert::ToString(sec);

		if (seconds <= 0)
		{
			MessageBox::Show("White wins!", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Information);
			menu_timer_black->Stop();
			menu_timer_white->Stop();
		}
	
}
	   //white timer tick
private: System::Void menu_timer_white_Tick(System::Object^ sender, System::EventArgs^ e) {
	seconds_white--;
	int minutes_white = seconds_white / 60;
	int sec_white = seconds_white - minutes_white * 60;
	label_whitetime->Visible = true;
	time_white->Text = "0" + Convert::ToString(minutes_white) + ":" + Convert::ToString(sec_white);

	if (sec_white < 10)
		time_white->Text = "0" + Convert::ToString(minutes_white) + ":" + "0" + Convert::ToString(sec_white);

	if (minutes_white > 10)
		time_white->Text = Convert::ToString(minutes_white) + ":" + Convert::ToString(sec_white);

	if (seconds_white <= 0)
	{
		MessageBox::Show("Black wins!", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Information);
		menu_timer_white->Stop();
		menu_timer_black->Stop();
	}
}
	   //restart app
private: System::Void restartToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Restart();
}
	   //close app
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void close_timepanel_Click(System::Object^ sender, System::EventArgs^ e) {
	timeset_panel->Visible = false;
	timeset_panel->Enabled = false;
}
	  //drag form
	   bool dragging = false;
	   Point scope;
private: System::Void picturebox_board_MouseDown_1(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging = true;
	scope.X = e->X;
	scope.Y = e->Y;
}
private: System::Void picturebox_board_MouseMove_1(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (dragging)
	{
		Point current_scope = PointToScreen(Point(e->X, e->Y));
		Location = Point(current_scope.X - scope.X, current_scope.Y - scope.Y);
	}
}
private: System::Void picturebox_board_MouseUp_1(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging = false;
}
};
}
