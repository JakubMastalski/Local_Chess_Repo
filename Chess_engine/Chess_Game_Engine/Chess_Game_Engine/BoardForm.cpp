#include "BoardForm.h"
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

	BoardForm::BoardForm(void)
	{
		InitializeComponent();
		
		start_black = Point(602, 12);
		start_white = Point(602, 250);
		on_move = true;
		seconds=0, seconds_white = 1;
		increment=0;
		on_move=0;
		dragging = false;
		scope = Point(0, 0);
		chosen_piece_val = 1;
		whiteonMove = true;
		castle_move = false;
		piece_clicked = false;
		enPassantRow = -1;
		enPassantCol = -1;
		menu_timer_white->Enabled = false;
		menu_timer_black->Enabled = false;
		game_started = false;
		timer_set = false;
		white_time_ended = false;
		black_time_ended = false;
		show = false;
		boardFlipped = false;
		reset_highlight_moves();
	}

	BoardForm::~BoardForm()
	{
		if (components)
		{
			delete components;
		}
	}
	void BoardForm::InitializeComponent(void)
	{
		//init grid panel
		this->grid_panel = (gcnew System::Windows::Forms::Panel());
		//array of board classes objects
		pictureBoxInstance->InitializeBoard(); // init board in pb_instance
		this->pictureBoxes = pictureBoxInstance->GetPictureBoxes(); 
		//add picture boxed to form
		for (int row = 2; row < 6; ++row) {
			for (int col = 0; col < 8; ++col) {
				this->grid_panel->Controls->Add(pictureBoxes[row][col]);
				pictureBoxes[row][col]->ImageLocation = "";
				pictureBoxes[row][col]->Enabled = true;
				pictureBoxes[row][col]->set_color(pictureBoxes[row][col], NONE);
				pictureBoxes[row][col]->set_piece(pictureBoxes[row][col], EMPTY);
			}
		}

	
		for (int col = 0; col < 8; ++col) {
		
			this->grid_panel->Controls->Add(pictureBoxes[6][col]);
			if(!boardFlipped)pictureBoxes[6][col]->set_color(pictureBoxes[6][col], WHITE);
			else
			{
				pictureBoxes[6][col]->set_color(pictureBoxes[6][col], BLACK);
			}
			pictureBoxes[6][col]->set_piece(pictureBoxes[6][col], PAWN);

			this->grid_panel->Controls->Add(pictureBoxes[7][col]);
			switch (col) {
			case 0:
			case 7:
				pictureBoxes[7][col]->set_piece(pictureBoxes[7][col], ROOK);
				break;
			case 1:
			case 6:
				pictureBoxes[7][col]->set_piece(pictureBoxes[7][col], KNIGHT);
				break;
			case 2:
			case 5:
				pictureBoxes[7][col]->set_piece(pictureBoxes[7][col], BISHOP);
				break;
			case 3:
				pictureBoxes[7][col]->set_piece(pictureBoxes[7][col], QUEEN);
				break;
			case 4:
				pictureBoxes[7][col]->set_piece(pictureBoxes[7][col], KING);
				if(!boardFlipped)white_king = pictureBoxes[7][col];
				else
				{
					black_king = pictureBoxes[7][col];
				}
				break;
			}
			if(!boardFlipped)pictureBoxes[7][col]->set_color(pictureBoxes[7][col], WHITE);
			else
			{
				pictureBoxes[7][col]->set_color(pictureBoxes[7][col], BLACK);
			}
		}

		
		for (int col = 0; col < 8; ++col) {
		
			this->grid_panel->Controls->Add(pictureBoxes[0][col]);
			switch (col) {
			case 0:
			case 7:
				pictureBoxes[0][col]->set_piece(pictureBoxes[0][col], ROOK);
				break;
			case 1:
			case 6:
				pictureBoxes[0][col]->set_piece(pictureBoxes[0][col], KNIGHT);
				break;
			case 2:
			case 5:
				pictureBoxes[0][col]->set_piece(pictureBoxes[0][col], BISHOP);
				break;
			case 3:
				pictureBoxes[0][col]->set_piece(pictureBoxes[0][col], QUEEN);
				break;
			case 4:
				pictureBoxes[0][col]->set_piece(pictureBoxes[0][col], KING);
				if(!boardFlipped)black_king = pictureBoxes[0][col];
				else
				{
					white_king = pictureBoxes[0][col];
				}
				break;
			}
			if(!boardFlipped)pictureBoxes[0][col]->set_color(pictureBoxes[0][col], BLACK);
			else
			{
				pictureBoxes[0][col]->set_color(pictureBoxes[0][col], WHITE);
			}

			this->grid_panel->Controls->Add(pictureBoxes[1][col]);
			if(!boardFlipped)pictureBoxes[1][col]->set_color(pictureBoxes[1][col], BLACK);
			else
			{
				pictureBoxes[1][col]->set_color(pictureBoxes[1][col], WHITE);
			}
			pictureBoxes[1][col]->set_piece(pictureBoxes[1][col], PAWN);
		}

		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				pictureBoxes[i][j]->MouseDown += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseDown);
				pictureBoxes[i][j]->MouseMove += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseMove);
				pictureBoxes[i][j]->MouseUp += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseUp);
				pictureBoxes[i][j]->MouseClick += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseClick);
			}
		}
	
		this->components = (gcnew System::ComponentModel::Container());
		this->board_panel = (gcnew System::Windows::Forms::Panel());
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
		this->time_white = (gcnew System::Windows::Forms::Label());
		this->label_whitetime = (gcnew System::Windows::Forms::Label());
		this->label_blacktime = (gcnew System::Windows::Forms::Label());
		this->time_black = (gcnew System::Windows::Forms::Label());
		this->picturebox_bg = (gcnew System::Windows::Forms::PictureBox());
		this->chess_menu = (gcnew System::Windows::Forms::MenuStrip());

		this->promote_panel = (gcnew System::Windows::Forms::Panel());
		this->picturebox_bishop = gcnew System::Windows::Forms::PictureBox();
		this->picturebox_knight = gcnew System::Windows::Forms::PictureBox();
		this->picturebox_rook = gcnew System::Windows::Forms::PictureBox();
		this->picturebox_queen = gcnew System::Windows::Forms::PictureBox();

		this->flipBoardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->flipBoardToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->setTimeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->restartToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->menu_timer_black = (gcnew System::Windows::Forms::Timer(this->components));
		this->menu_timer_white = (gcnew System::Windows::Forms::Timer(this->components));
		this->picturebox_board = (gcnew System::Windows::Forms::PictureBox());
		this->board_panel->SuspendLayout();
		this->timeset_panel->SuspendLayout();
		this->increment_panel->SuspendLayout();
		this->promote_panel->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_secincrement))->BeginInit();
		this->timeroptions_panel->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_minperside))->BeginInit();
		this->chess_menu->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->BeginInit();
		this->SuspendLayout();
		// 
		// board_panel
		// 
		this->board_panel->Controls->Add(this->grid_panel);
		this->board_panel->Controls->Add(this->timeset_panel);
		this->board_panel->Controls->Add(this->time_white);
		this->board_panel->Controls->Add(this->label_whitetime);
		this->board_panel->Controls->Add(this->promote_panel);
		this->board_panel->Controls->Add(this->label_blacktime);
		this->board_panel->Controls->Add(this->time_black);
		this->board_panel->Controls->Add(this->picturebox_board);
		this->board_panel->Location = System::Drawing::Point(50, 57);
		this->board_panel->Name = L"board_panel";
		this->board_panel->Size = System::Drawing::Size(700, 469);
		this->board_panel->TabIndex = 0;
		//
		// promote_panel
		// 
		// Ustawienia dla picturebox_bishop
		picturebox_bishop = gcnew System::Windows::Forms::PictureBox();
		picturebox_bishop->Location = System::Drawing::Point(20, 20);
		picturebox_bishop->Size = System::Drawing::Size(50, 50);
		picturebox_bishop->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_bishop.png";
		picturebox_bishop->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		picturebox_bishop->TabIndex = 0;
		picturebox_bishop->Visible = true;
		picturebox_bishop->Cursor = System::Windows::Forms::Cursors::Hand;
		picturebox_bishop->Enabled = true;
		picturebox_bishop->TabStop = false;
		picturebox_bishop->MouseClick += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseClick);
		//picturebox_bishop->MouseEnter += gcnew EventHandler(this, &BoardForm::picturebox_MouseEnter);

		// Ustawienia dla picturebox_knight
		picturebox_knight = gcnew System::Windows::Forms::PictureBox();
		picturebox_knight->Location = System::Drawing::Point(80, 20);
		picturebox_knight->Size = System::Drawing::Size(50, 50);
		picturebox_knight->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_knight.png";
		picturebox_knight->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		picturebox_knight->TabIndex = 1;
		picturebox_knight->Cursor = System::Windows::Forms::Cursors::Hand;
		picturebox_knight->Visible = true; 
		picturebox_knight->Enabled = true;
		picturebox_knight->TabStop = false;
		picturebox_knight->MouseClick += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseClick);
		//picturebox_knight->MouseEnter += gcnew EventHandler(this, &BoardForm::picturebox_MouseEnter);


		// Ustawienia dla picturebox_rook
		picturebox_rook = gcnew System::Windows::Forms::PictureBox();
		picturebox_rook->Location = System::Drawing::Point(20, 80);
		picturebox_rook->Size = System::Drawing::Size(50, 50);
		picturebox_rook->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_rook.png";
		picturebox_rook->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		picturebox_rook->TabIndex = 2;
		picturebox_rook->Cursor = System::Windows::Forms::Cursors::Hand;
		picturebox_rook->Visible = true; 
		picturebox_rook->Enabled = true;
		picturebox_rook->TabStop = false;
		picturebox_rook->MouseClick += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseClick);
		//picturebox_rook->MouseEnter += gcnew EventHandler(this, &BoardForm::picturebox_MouseEnter);

		// Ustawienia dla picturebox_queen
		picturebox_queen = gcnew System::Windows::Forms::PictureBox();
		picturebox_queen->Location = System::Drawing::Point(80, 80);
		picturebox_queen->Size = System::Drawing::Size(50, 50);
		picturebox_queen->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_queen.png";
		picturebox_queen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		picturebox_queen->TabIndex = 3;
		picturebox_queen->Cursor = System::Windows::Forms::Cursors::Hand;
		picturebox_queen->Visible = true; 
		picturebox_queen->Enabled = true;
		picturebox_queen->TabStop = false;
		picturebox_queen->MouseClick += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseClick);

		// promote_panel
		promote_panel = gcnew System::Windows::Forms::Panel();
		promote_panel->BackColor = System::Drawing::Color::Black; 
		promote_panel->Location = System::Drawing::Point(13, 63);   
		promote_panel->Size = System::Drawing::Size(150,150);     
		promote_panel->BorderStyle = System::Windows::Forms::BorderStyle::None;  
		promote_panel->Margin = System::Windows::Forms::Padding(10); 
		promote_panel->Visible = false;  
		promote_panel->Enabled = true;
		promote_panel->Controls->Add(picturebox_bishop);
		promote_panel->Controls->Add(picturebox_knight);
		promote_panel->Controls->Add(picturebox_rook);
		promote_panel->Controls->Add(picturebox_queen);

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
		this->timeset_panel->Location = System::Drawing::Point(200, 100);
		this->timeset_panel->Name = L"timeset_panel";
		this->timeset_panel->Size = System::Drawing::Size(330, 232);
		this->timeset_panel->TabIndex = 6;
		this->timeset_panel->Visible = false;
		this->timeset_panel->BringToFront();
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
		// time_white
		// 
		this->time_white->AutoSize = true;
		this->time_white->BackColor = System::Drawing::Color::Transparent;
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
		this->label_whitetime->BackColor = System::Drawing::Color::Transparent;
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
		this->label_blacktime->BackColor = System::Drawing::Color::Transparent;
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
		this->time_black->BackColor = System::Drawing::Color::Transparent;
		this->time_black->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->time_black->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(238)));
		this->time_black->Location = System::Drawing::Point(601, 43);
		this->time_black->Name = L"time_black";
		this->time_black->Size = System::Drawing::Size(0, 50);
		this->time_black->TabIndex = 5;
		this->time_black->Visible = false;
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
		//PB TESTOWE CUSTOM
        //picture box bg
		this->picturebox_bg->Location = System::Drawing::Point(0, 0); // Ustawienie lokalizacji
		this->picturebox_bg->Size = System::Drawing::Size(460, 460); // Ustawienie rozmiaru
		this->picturebox_bg->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg";
		this->picturebox_bg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->picturebox_bg->Dock = System::Windows::Forms::DockStyle::Fill;
		this->picturebox_bg->SendToBack();
		this->picturebox_bg->TabIndex = 6;
		this->picturebox_bg->TabStop = false;
		// 
		// grid_panel
		// 
		//this->grid_panel->BackColor = System::Drawing::Color::Transparent;
		this->grid_panel->Location = System::Drawing::Point(121, 5);
		this->grid_panel->Name = L"grid_panel";
		this->grid_panel->Size = System::Drawing::Size(460, 460);
		this->grid_panel->Controls->Add(picturebox_bg);
		this->grid_panel->Controls->Add(promote_panel);
		this->grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg");
		if(boardFlipped)grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\flipedboard1");
		this->grid_panel->TabIndex = 47;
		this->grid_panel->Visible = true;
		//this->grid_panel->BringToFront();
		this->grid_panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::grid_panel_MouseDown);
		this->grid_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::grid_panel_MouseMove);
		this->grid_panel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::grid_panel_MouseUp);
		this->grid_panel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::grid_panel_MouseClick);
		// 
		// BoardForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::GrayText;
		this->ClientSize = System::Drawing::Size(799, 538);
		this->Controls->Add(this->board_panel);
		this->Controls->Add(this->chess_menu);
		this->Controls->Add(this->promote_panel);
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
		this->timeset_panel->ResumeLayout(false);
		this->timeset_panel->PerformLayout();
		this->increment_panel->ResumeLayout(false);
		this->increment_panel->PerformLayout();
		this->promote_panel->ResumeLayout(false);
		this->promote_panel->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_secincrement))->EndInit();
		this->timeroptions_panel->ResumeLayout(false);
		this->timeroptions_panel->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_minperside))->EndInit();
		this->chess_menu->ResumeLayout(false);
		this->chess_menu->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();
		this->SetStyle(System::Windows::Forms::ControlStyles::UserPaint, true);
		this->SetStyle(System::Windows::Forms::ControlStyles::AllPaintingInWmPaint, true);
		this->SetStyle(System::Windows::Forms::ControlStyles::DoubleBuffer, true);
		picturebox_rook->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::picturebox_rook_MouseClick);
		picturebox_knight->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::picturebox_knight_MouseClick);
		picturebox_queen->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::picturebox_queen_MouseClick);
		picturebox_bishop->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::picturebox_bishop_MouseClick);

	}
#pragma endregion
#pragma endregion
	//chess board init

		//flip board
	

void BoardForm::flipBoardToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {

	if (MessageBox::Show("Are you sure you want to flip the board? (If the board is flipped, the game will restart)",
		"Confirm Flip Board", MessageBoxButtons::OKCancel, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK) {


		this->grid_panel->Controls->Clear(); // Clear existing PictureBoxes from grid_panel
		grid_panel->BackgroundImage = nullptr;

		whiteonMove = true;

		white_king = nullptr;
		black_king = nullptr;

		white_king_on_checked = false;
		black_king_on_checked = false;

		black_king_moved = false;
		white_king_moved = false;

		boardFlipped = !boardFlipped; // Toggle board flipped status

		if (!boardFlipped)
		{
			Application::Restart();
		}

		if (boardFlipped) {
			pictureBoxInstance->FlipBoard();
			grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\flipedboard1.jpg");
		}
		else {
			pictureBoxInstance->InitializeBoard(); // Initialize the board normally
			grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg");
		}
		promote_panel->BackColor = System::Drawing::Color::Black;
		promote_panel->Location = System::Drawing::Point(20, 20);



		this->pictureBoxes = pictureBoxInstance->GetPictureBoxes(); // Update pictureBoxes array

			// Adjust indices when the board is flipped
			array<array<custom_picturebox^>^>^ flippedPictureBoxes = gcnew array<array<custom_picturebox^>^>(8);
			for (int i = 0; i < 8; i++) {
				flippedPictureBoxes[i] = gcnew array<custom_picturebox^>(8);
				for (int j = 0; j < 8; j++) {
					flippedPictureBoxes[i][j] = pictureBoxes[7 - i][7 - j];
				}
			}
			this->pictureBoxes = flippedPictureBoxes;

		// Setting pieces on the board
		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 8; j++) {
				this->grid_panel->Controls->Add(pictureBoxes[i][j]);
				pictureBoxes[i][j]->ImageLocation = "";
				pictureBoxes[i][j]->Enabled = true;
				pictureBoxes[i][j]->set_color(pictureBoxes[i][j], NONE);
				pictureBoxes[i][j]->set_piece(pictureBoxes[i][j], EMPTY);
			}
		}

		for (int i = 0; i < 8; i++) {
			pictureBoxes[1][i]->set_piece(pictureBoxes[1][i], PAWN);
			pictureBoxes[1][i]->set_color(pictureBoxes[1][i], WHITE);
			pictureBoxes[1][i]->BringToFront();
			grid_panel->Controls->Add(pictureBoxes[1][i]);
		}

		for (int i = 0; i < 8; i++) {
			pictureBoxes[6][i]->set_piece(pictureBoxes[6][i], PAWN);
			pictureBoxes[6][i]->set_color(pictureBoxes[6][i], BLACK);
		
			pictureBoxes[6][i]->BringToFront();
			grid_panel->Controls->Add(pictureBoxes[6][i]);
		}

		// Set rooks, knights, bishops, queen, and king for both black and white
		for (int i = 0; i < 8; i++) {
			switch (i) {
			case 0:
			case 7:
				pictureBoxes[7][i]->set_piece(pictureBoxes[7][i], ROOK);
				break;
			case 1:
			case 6:
				pictureBoxes[7][i]->set_piece(pictureBoxes[7][i], KNIGHT);
				break;
			case 2:
			case 5:
				pictureBoxes[7][i]->set_piece(pictureBoxes[7][i], BISHOP);
				break;
			case 4:
				pictureBoxes[7][i]->set_piece(pictureBoxes[7][i], QUEEN);
				break;
			case 3:
				
					flipped_black_kingbox = pictureBoxes[7][i];
					flipped_black_kingbox->row = 7;
					flipped_black_kingbox->column = 3;
					black_king = flipped_black_kingbox;
			
				pictureBoxes[7][i]->set_piece(pictureBoxes[7][i], KING);
				break;
			}
			pictureBoxes[7][i]->set_color(pictureBoxes[7][i], BLACK);
			pictureBoxes[7][1]->BringToFront();
			grid_panel->Controls->Add(pictureBoxes[7][i]);
		}

		for (int i = 0; i < 8; i++) {
			switch (i) {
			case 0:
			case 7:
				pictureBoxes[0][i]->set_piece(pictureBoxes[0][i], ROOK);
				break;
			case 1:
			case 6:
				pictureBoxes[0][i]->set_piece(pictureBoxes[0][i], KNIGHT);
				break;
			case 2:
			case 5:
				pictureBoxes[0][i]->set_piece(pictureBoxes[0][i], BISHOP);
				break;
			case 4:
				pictureBoxes[0][i]->set_piece(pictureBoxes[0][i], QUEEN);
				break;
			case 3:
				flipped_white_kingbox = pictureBoxes[0][i];
				flipped_white_kingbox->row = 0;
				flipped_white_kingbox->column = 3;
			
				pictureBoxes[0][i]->set_piece(pictureBoxes[0][i], KING);
				break;
			}
			pictureBoxes[0][i]->set_color(pictureBoxes[0][i], WHITE);
		
			pictureBoxes[0][i]->BringToFront();
			grid_panel->Controls->Add(pictureBoxes[0][i]);
		}

		this->grid_panel->Location = System::Drawing::Point(121, 5);
		this->grid_panel->Name = L"grid_panel";
		this->grid_panel->Size = System::Drawing::Size(460, 460);
		this->grid_panel->Controls->Add(picturebox_bg);
		this->grid_panel->Controls->Add(promote_panel);
		this->grid_panel->TabIndex = 47;
		this->grid_panel->Visible = true;


		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				// Update PictureBox properties based on pictureBoxes array
				pictureBoxes[i][j]->MouseDown += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseDown);
				pictureBoxes[i][j]->MouseMove += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseMove);
				pictureBoxes[i][j]->MouseUp += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseUp);
				pictureBoxes[i][j]->MouseClick += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseClick);
				grid_panel->Controls->Add(pictureBoxes[i][j]);
				pictureBoxes[i][j]->BringToFront();
			}
		}
		// Refresh the form
		this->Refresh();
	}
}
	   //open panel with time
void BoardForm::setTimeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	timeset_panel->Visible = true;
	timeset_panel->Enabled = true;
}
	   //set button set time 
	   int seconds, seconds_white;
	   int increment;
	   //on move true == white on move
	   bool on_move = true;

	   void BoardForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	timeset_panel->Visible = false;
	//set time for black pieces
	if (time_options_box->Text == "Real time")
	{
		//test time
		//black
		menu_timer_black->Enabled = true;
		label_blacktime->Visible = true;
		time_black->Visible = true;
		//white
		menu_timer_white->Enabled = true;
		//menu_timer_white->Enabled = false;
		label_whitetime->Visible = true;
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
		timer_set = true;
		show = false;
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

		timer_set = false;
	}

}
	   //set time
	   void BoardForm:: trackbar_minperside_Scroll(System::Object^ sender, System::EventArgs^ e) {
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
	   void BoardForm::trackbar_secincrement_Scroll(System::Object^ sender, System::EventArgs^ e) {
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
	   void BoardForm::menu_timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		   if (game_started && seconds > 0) {
			   seconds--;
			   int minutes = seconds / 60;
			   int sec = seconds - minutes * 60;
			   label_blacktime->Visible = true;
			   time_black->Text = (minutes < 10 ? "0" : "") + Convert::ToString(minutes) + ":" + (sec < 10 ? "0" : "") + Convert::ToString(sec);

			   if (seconds <= 0 && !show) {
				   MessageBox::Show("White wins!", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   menu_timer_black->Stop();
				   menu_timer_white->Stop();
				   label_blacktime->Visible = false;
				   label_whitetime->Visible = false;
				   game_started = false;
				   show = true;
			   }
		   }

}
	   //white timer tick
	   void BoardForm::menu_timer_white_Tick(System::Object^ sender, System::EventArgs^ e) {
		   if (game_started && seconds_white > 0) {
			   seconds_white--;
			   int minutes_white = seconds_white / 60;
			   int sec_white = seconds_white - minutes_white * 60;
			   label_whitetime->Visible = true;
			   time_white->Text = (minutes_white < 10 ? "0" : "") + Convert::ToString(minutes_white) + ":" + (sec_white < 10 ? "0" : "") + Convert::ToString(sec_white);

			   if (seconds_white <= 0 && !show) {
				   MessageBox::Show("Black wins!", "Game Over", MessageBoxButtons::OK, MessageBoxIcon::Information);
				   menu_timer_black->Stop();
				   menu_timer_white->Stop();
				   label_blacktime->Visible = false;
				   label_whitetime->Visible = false;
				   game_started = false;
				   show = true;
			   }
		   }
       }

	   void BoardForm::player_turn(bool onMove, array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected)
	   {
		   if (onMove)
		   {
			   for (int i = 0; i < 8; i++)
			   {
				   for (int j = 0; j < 8; j++)
				   {
					   if (pictureBoxes[i][j]->check_color(selected) == WHITE)
					   {
						   pictureBoxes[i][j]->Enabled = true;
						   reset_highlight_moves();
			
						   if (timer_set)
						   {
							   menu_timer_black->Start();
							   menu_timer_white->Stop();
						   }
					   }
				   }
			   }
		   }
		   else
		   {
			   for (int i = 0; i < 8; i++)
			   {
				   for (int j = 0; j < 8; j++)
				   {
					   if (pictureBoxes[i][j]->check_color(selected) == BLACK)
					   {
						  pictureBoxes[i][j]->Enabled = true;
						  reset_highlight_moves();

						   if (timer_set)
						   {
							   menu_timer_white->Start();
							   menu_timer_black->Stop();
						   }
					   }
				   }
			   }
		   }
	   }

	   void BoardForm::player_turnClick()
	   {
		   if (whiteonMove)
		   {
			   menu_timer_white->Start();
			   menu_timer_black->Stop();
		   }
		   else
		   {
			   menu_timer_black->Start();
			   menu_timer_white->Stop();
		   }

	   }


	   //restart app
	   void BoardForm::restartToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Restart();
}
	   //close app
	   void BoardForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
	   void BoardForm::close_timepanel_Click(System::Object^ sender, System::EventArgs^ e) {
	timeset_panel->Visible = false;
	timeset_panel->Enabled = false;
}
	   //draging pieces
	   void BoardForm::HandlePieceSelection(custom_picturebox^ selectedPictureBox)
	   {
		   if (selectedPictureBox->ImageLocation != "")
		   {
			   if (selectedPictureBox != nullptr && promote_panel->Visible == false)
			   {
				   piece_clicked = true;
				   selectedPictureBox->Capture = true;
				   selectedPictureBox->BringToFront();
				   new_selected = selectedPictureBox;
				   current_piece = selectedPictureBox->check_piece(selectedPictureBox);
				   current_color = selectedPictureBox->check_color(selectedPictureBox);
				   start_location = selectedPictureBox->Location;
				   file_path = selectedPictureBox->ImageLocation;
				   selectedPictureBox->Tag = "Dragging";
			   }
		   }
	   }

	   void BoardForm::HandlePieceUp(custom_picturebox^ selectedPictureBox, custom_picturebox^ targetPictureBox)
	   {
		   selectedPictureBox->Capture = false;
		   selectedPictureBox->Tag = "";

		   isWithinBounds = check_sent(selectedPictureBox);

		   if (selectedPictureBox->Location != start_location && isWithinBounds)
		   {
			   switch (current_piece)
			   {
			   case PAWN:
				   if (!check_Pawnmove(pictureBoxes, selectedPictureBox))
				   {
					   reset_highlight_moves();
					   selectedPictureBox->Location = start_location;
					   return;
				   }
				   break;
			   case KNIGHT:
				   if (!check_Knightmove(pictureBoxes, selectedPictureBox))
				   {
					   reset_highlight_moves();
					   selectedPictureBox->Location = start_location;
					   return;
				   }
				   break;
			   case BISHOP:
				   if (!check_Bishopmove(pictureBoxes, selectedPictureBox))
				   {
					   reset_highlight_moves();
					   selectedPictureBox->Location = start_location;
					   return;
				   }
				   break;
			   case ROOK:
				   if (!check_Rookmove(pictureBoxes, selectedPictureBox))
				   {
					   reset_highlight_moves();
					   selectedPictureBox->Location = start_location;
					   return;
				   }
				   break;
			   case QUEEN:
				   if (!check_Queenmove(pictureBoxes, selectedPictureBox))
				   {
					   reset_highlight_moves();
					   selectedPictureBox->Location = start_location;
					   return;
				   }
				   break;
			   case KING:
				   if (!check_Kingmove(pictureBoxes, selectedPictureBox))
				   {
					   reset_highlight_moves();
					   selectedPictureBox->Location = start_location;
					   return;
				   }
				   break;
			   default:
				   reset_highlight_moves();
				   selectedPictureBox->Location = start_location;
				   return;
			   }

			   selectedPictureBox->SendToBack();
		   }
		   else
		   {
			   selectedPictureBox->Location = start_location;
			   selectedPictureBox->ImageLocation = file_path;
			   return;
		   }

		   controlUnderCursor = selectedPictureBox->Parent->GetChildAtPoint(selectedPictureBox->Parent->PointToClient(Control::MousePosition));


		targetPictureBox = dynamic_cast<custom_picturebox^>(controlUnderCursor);
		  

		   if (targetPictureBox == nullptr || selectedPictureBox == nullptr)
		   {
			   switch (current_piece)
			   {
			   case PAWN:
				   new_selected->ImageLocation = (current_color == PieceColor::WHITE) ?
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_pawn.png" :
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_knight.png";
				   break;
			   case KNIGHT:
				   new_selected->ImageLocation = (current_color == PieceColor::WHITE) ?
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_knight.png" :
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_knight.png";
				   break;
			   case BISHOP:
				   new_selected->ImageLocation = (current_color == PieceColor::WHITE) ?
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_bishop.png" :
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_bishop.png";
				   break;
			   case ROOK:
				   new_selected->ImageLocation = (current_color == PieceColor::WHITE) ?
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_rook.png" :
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_rook.png";
				   break;
			   case QUEEN:
				   new_selected->ImageLocation = (current_color == PieceColor::WHITE) ?
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_queen.png" :
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_queen.png";
				   break;
			   case KING:
				   new_selected->ImageLocation = (current_color == PieceColor::WHITE) ?
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.png" :
					   "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";
				   break;
			   default:
				   MessageBox::Show("Error");
				   return;
			   }

			   new_selected->Location = startLocation_selected;
			   new_selected->BringToFront();
			   selectedPictureBox->Location = start_location;
			   selectedPictureBox->BringToFront();
			   return;
		   }

		   if (whiteonMove)
		   {
			   promote_panel->BackColor = System::Drawing::Color::Black;
			   picturebox_bishop->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_bishop.png";
			   picturebox_knight->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_knight.png";
			   picturebox_rook->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_rook.png";
			   picturebox_queen->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_queen.png";
		   }
		   else
		   {
			   promote_panel->BackColor = System::Drawing::Color::White;
			   picturebox_bishop->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_bishop.png";
			   picturebox_knight->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_knight.png";
			   picturebox_rook->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_rook.png";
			   picturebox_queen->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_queen.png";
		   }
		   promote_panel->BringToFront();

		   pieceType_selected = selectedPictureBox->check_piece(selectedPictureBox);
		   pieceColor_selected = selectedPictureBox->check_color(selectedPictureBox);
		   imgLocation_selected = selectedPictureBox->ImageLocation;
		   startLocation_selected = start_location;

		   pieceType_target = targetPictureBox->check_piece(targetPictureBox);
		   pieceColor_target = targetPictureBox->check_color(targetPictureBox);
		   imgLocation_target = targetPictureBox->ImageLocation;

		   if (!castle_move)
		   {
			   if (targetPictureBox != nullptr && targetPictureBox != selectedPictureBox && selectedPictureBox != nullptr)
			   {
				   if (!BoardForm::change_pb(selectedPictureBox, targetPictureBox))
				   {
					   selectedPictureBox->set_piece(selectedPictureBox, pieceType_selected);
					   selectedPictureBox->set_color(selectedPictureBox, pieceColor_selected);
					   selectedPictureBox->ImageLocation = imgLocation_selected;
					   selectedPictureBox->Location = start_location;

					   targetPictureBox->set_piece(targetPictureBox, pieceType_target);
					   targetPictureBox->set_color(targetPictureBox, pieceColor_target);
					   targetPictureBox->ImageLocation = imgLocation_target;
				   }
			   }
		   }

		   if (castle_move)
		   {
			   castle_move = false;
		   }

		   if (white_king_on_checked || black_king_on_checked)
		   {
			   if (!king_still_checked(pictureBoxes, selectedPictureBox, targetPictureBox, last_moved_piece))
			   {
				   white_king_on_checked = false;
				   black_king_on_checked = false;
			   }
			   else if (king_still_checked(pictureBoxes, selectedPictureBox, targetPictureBox, last_moved_piece))
			   {
				   white_king_on_checked = true;
				   black_king_on_checked = true;

				   selectedPictureBox->ImageLocation = imgLocation_selected;
				   selectedPictureBox->set_color(selectedPictureBox, pieceColor_selected);
				   selectedPictureBox->set_piece(selectedPictureBox, pieceType_selected);

				   targetPictureBox->ImageLocation = imgLocation_target;
				   targetPictureBox->set_color(targetPictureBox, pieceColor_target);
				   targetPictureBox->set_piece(targetPictureBox, pieceType_target);
				   whiteonMove = !whiteonMove;
			   }
		   }

		   int white_row = -1;
		   int white_column = -1;

		   int black_row = -1;
		   int black_column = -1;

		   if (king_checked(pictureBoxes, selectedPictureBox) || white_king_on_checked || black_king_on_checked)
		   {
			   if ((whiteonMove && black_king_on_checked) || (!whiteonMove && white_king_on_checked))
			   {
				   selectedPictureBox->ImageLocation = imgLocation_selected;
				   selectedPictureBox->set_color(selectedPictureBox, pieceColor_selected);
				   selectedPictureBox->set_piece(selectedPictureBox, pieceType_selected);

				   targetPictureBox->ImageLocation = imgLocation_target;
				   targetPictureBox->set_color(targetPictureBox, pieceColor_target);
				   targetPictureBox->set_piece(targetPictureBox, pieceType_target);

				   if(white_king_on_checked)white_king->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.png";

				   else if(black_king_on_checked)black_king->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";

				   whiteonMove = !whiteonMove;
				   return;
			   }
			   else
			   {
				   custom_picturebox^ whiteKingBox = nullptr;
				   custom_picturebox^ blackKingBox = nullptr;

				   for (int i = 0; i < 8; i++)
				   {
					   for (int j = 0; j < 8; j++)
					   {
						   if (pictureBoxes[i][j]->check_piece(pictureBoxes[i][j]) == KING)
						   {
							   if (pictureBoxes[i][j]->check_color(pictureBoxes[i][j]) == WHITE)
							   {
								   whiteKingBox = pictureBoxes[i][j];
							   }
							   else
							   {
								   blackKingBox = pictureBoxes[i][j];
							   }
						   }
					   }
				   }
				   if ((!whiteonMove && is_checkmate(pictureBoxes, blackKingBox)) || (whiteonMove && is_checkmate(pictureBoxes, whiteKingBox)))
				   {
					   MessageBox::Show("Checkmate!", "Game Over");
					   grid_panel->Enabled = false;

					   // Reset game or any other logic for end game
					   return;
				   }
			   }
		   }

		   game_started = true;
	   }

    void BoardForm::grid_panel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			selectedPictureBox = dynamic_cast<custom_picturebox^>(sender);
			HandlePieceSelection(selectedPictureBox);
		}
   }
	void BoardForm::grid_panel_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		if (e->Button == System::Windows::Forms::MouseButtons::Left && selectedPictureBox != nullptr && selectedPictureBox->Tag->ToString() == "Dragging") {
			PieceColor current_collor = selectedPictureBox->check_color(selectedPictureBox);
			if ((whiteonMove && current_collor == BLACK) || (!whiteonMove && current_collor == WHITE)) {
				selectedPictureBox->Enabled = false; 
				return;
			}
			reset_highlight_moves();
			player_turn(whiteonMove, pictureBoxes, selectedPictureBox);
			Point new_location = selectedPictureBox->Parent->PointToClient(Control::MousePosition);
			piece_clicked = false;
			new_location.Offset(-selectedPictureBox->Width / 2, -selectedPictureBox->Height / 2);
		    selectedPictureBox->BringToFront();
			selectedPictureBox->Location = new_location;
		}

	}


	void BoardForm::grid_panel_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left && selectedPictureBox != nullptr && selectedPictureBox->Tag->ToString() == "Dragging")
		{
			HandlePieceUp(selectedPictureBox,targetPictureBox);
		}
	}
	//swap pb
	bool BoardForm::change_pb(custom_picturebox^ selected_pb, custom_picturebox^ target_pb)
	{
		reset_highlight_moves();

		Piece chosen_piece_selected = selected_pb->check_piece(selected_pb);
		Piece chosen_piece_target = target_pb->check_piece(target_pb);

		PieceColor color_selected = selected_pb->check_color(selected_pb);
		PieceColor color_target = target_pb->check_color(target_pb);

		String^ img_location_selected = selected_pb->ImageLocation;
		String^ img_location_target = target_pb->ImageLocation;

		Point start_location_selected = selected_pb->Location;
		Point start_location_target = target_pb->Location;

		target_pb->ImageLocation = img_location_selected;
		target_pb->set_color(target_pb, color_selected);
		target_pb->set_piece(target_pb, chosen_piece_selected);
		target_pb->BackColor = System::Drawing::Color::Transparent;

		selected_pb->ImageLocation = "";
		selected_pb->set_color(selected_pb, NONE);
		selected_pb->set_piece(selected_pb, EMPTY);
		selected_pb->BackColor = System::Drawing::Color::Transparent;
		selected_pb->Location = start_location;
		selected_pb->BringToFront();
		target_pb->BringToFront();

		whiteonMove = !whiteonMove;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				pictureBoxes[i][j]->onMoveIMG = false;
				if (pictureBoxes[i][j]->check_color(pictureBoxes[i][j]) == GREEN)
				{
					pictureBoxes[i][j]->set_color(pictureBoxes[i][j], color_before);
					color_before = NONE;
				}
			}
		}
	
		if (target_pb->check_piece(target_pb) == chosen_piece_selected || selected_pb->check_piece(selected_pb) == NONE)
		{
			reset_highlight_moves();
			return true;
		}
		else
		{
			reset_highlight_moves();
			return false;
		}
		reset_highlight_moves();
		return true;
	}

	bool BoardForm::king_still_checked(array<array<custom_picturebox^>^>^ pb,custom_picturebox^ selected, custom_picturebox^ target,custom_picturebox^ last_moved)
	{
		// ZnajdŸ pola króla bia³ego i czarnego oraz ich pozycje
		custom_picturebox^ whiteKingBox = nullptr;
		custom_picturebox^ blackKingBox = nullptr;
		int whiteKingRow = -1, whiteKingCol = -1;
		int blackKingRow = -1, blackKingCol = -1;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				int actualRow = i;
				int actualCol = j;
				if (boardFlipped) {
					actualRow = 7 - i;
					actualCol = 7 - j;
				}

				if (pb[actualRow][actualCol]->check_piece(pb[actualRow][actualCol]) == KING) {
					if (pb[actualRow][actualCol]->check_color(pb[actualRow][actualCol]) == WHITE) {
						whiteKingBox = pb[actualRow][actualCol];
						whiteKingRow = actualRow;
						whiteKingCol = actualCol;
					}
					else {
						blackKingBox = pb[actualRow][actualCol];
						blackKingRow = actualRow;
						blackKingCol = actualCol;
					}
				}
			}
		}

		// SprawdŸ szachowanie bia³ego króla
		if (whiteKingBox != nullptr) {
			// Przejrzyj wszystkie pola, aby znaleŸæ figury przeciwnika
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					int actualRow = i;
					int actualCol = j;
					if (boardFlipped) {
						actualRow = 7 - i;
						actualCol = 7 - j;
					}

					// SprawdŸ czy figura nale¿y do przeciwnika
					if (pb[actualRow][actualCol]->check_color(pb[actualRow][actualCol]) == BLACK) {
						// Jeœli figura mo¿e zaatakowaæ króla, zwróæ true
						if (is_king_under_attack(pb[actualRow][actualCol], whiteKingRow, whiteKingCol)) {
							return true;
						}
					}
				}
			}
		}

		// SprawdŸ szachowanie czarnego króla
		if (blackKingBox != nullptr) {
			// Przejrzyj wszystkie pola, aby znaleŸæ figury przeciwnika
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					int actualRow = i;
					int actualCol = j;
					if (boardFlipped) {
						actualRow = 7 - i;
						actualCol = 7 - j;
					}

					// SprawdŸ czy figura nale¿y do przeciwnika
					if (pb[actualRow][actualCol]->check_color(pb[actualRow][actualCol]) == WHITE) {
						// Jeœli figura mo¿e zaatakowaæ króla, zwróæ true
						if (is_king_under_attack(pb[actualRow][actualCol], blackKingRow, blackKingCol)) {
							reset_highlight_moves();
							return true;
						}
					}
				}
			}
		}

		// Jeœli król nie jest szachowany, zwróæ false
		return false;
	}
	//check pawn
	bool BoardForm::check_Pawnmove(array<array<custom_picturebox^>^>^ pictureBoxes,custom_picturebox^ selected_pb)
	{
		Point startPos = start_location; // Initial position of the pawn
		Point targetPos = selected_pb->Location; // New position of the pawn

		// Calculate position differences
		int dx = abs(targetPos.X - startPos.X) / selected_pb->Width; // Column difference
		int dy = abs(targetPos.Y - startPos.Y) / selected_pb->Height; // Row difference

		// Determine the direction of movement
		int direction = (targetPos.Y - startPos.Y) / selected_pb->Height; // 1 forward, -1 backward

		// Determine row and column indices for initial and target positions
		int startRow = startPos.Y / selected_pb->Height;
		int startCol = startPos.X / selected_pb->Width;
		int targetRow = targetPos.Y / selected_pb->Height;
		int targetCol = targetPos.X / selected_pb->Width;

		// Constrain indices to the board range (0-7)
		startRow = Math::Min(startRow, 7);
		startCol = Math::Min(startCol, 7);
		targetRow = Math::Min(targetRow, 7);
		targetCol = Math::Min(targetCol, 7);

		custom_picturebox^ intermediate_pb = nullptr;
		custom_picturebox^ target_pb = nullptr;

		// Check if the pawn is moving backward for black pawns
		if (selected_pb->check_color(selected_pb) == BLACK && targetRow < startRow && !boardFlipped) {
			passantable = nullptr;
			return false;
		}

		// Check if the pawn is moving backward for white pawns
		if (selected_pb->check_color(selected_pb) == WHITE && targetRow > startRow && !boardFlipped) {
			passantable = nullptr;
			return false;
		}

		// Check for flipped board state
		if (boardFlipped)
		{
			if (selected_pb->check_color(selected_pb) == WHITE && targetRow < startRow)
			{
				passantable = nullptr;
				return false;
			}
			if (selected_pb->check_color(selected_pb) == BLACK && targetRow > startRow)
			{
				passantable = nullptr;
				return false;
			}
		}

		// Check if indices are within the board range
		if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8 ||
			targetRow < 0 || targetRow >= 8 || targetCol < 0 || targetCol >= 8) {
			return true;
		}

		// Move forward by one square and no obstacles
		if (dx == 0 && dy == 1) {
			target_pb = pictureBoxes[targetRow][targetCol];
			if (target_pb->check_piece(target_pb) == EMPTY) {
				if (targetRow == 7 || targetRow == 0)
				{
					promote_panel->Visible = true;
					promote_panel->Enabled = true;
					promote_panel->BringToFront();
				}
				passantable = nullptr;
				return true;
			}
		}
		// Initial move by two squares forward
		else if (dx == 0 && dy == 2 && (startRow == 1 || startRow == 6)) {
			intermediate_pb = pictureBoxes[startRow + direction][startCol];
			target_pb = pictureBoxes[targetRow][targetCol];
			if (intermediate_pb->check_piece(intermediate_pb) == EMPTY && target_pb->check_piece(target_pb) == EMPTY) {
				passantable = pictureBoxes[targetRow][targetCol];
				return true;
			}
		}
		// Capture diagonally
		else if (dx == 1 && dy == 1) {
			target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color(target_pb);
			Piece check_piece = target_pb->check_piece(target_pb);

			// Normal capture
			if (check_targetpb != EMPTY && selected_pb->check_color(selected_pb) != check_targetpb && check_piece != KING) {
				if (targetRow == 7 || targetRow == 0)
				{
					promote_panel->Visible = true;
					promote_panel->Enabled = true;
					promote_panel->BringToFront();
				}
				passantable = nullptr;
				return true;
			}

			// En passant capture
			else if (check_targetpb == EMPTY) {
				int enPassantRow = 0;
				if (boardFlipped) {
					enPassantRow = selected_pb->check_color(selected_pb) == WHITE ? targetRow - 1 : targetRow + 1;
				}
				else {
					enPassantRow = selected_pb->check_color(selected_pb) == WHITE ? targetRow + 1 : targetRow - 1;
				}

				custom_picturebox^ enPassant_pb = pictureBoxes[enPassantRow][targetCol];
				if (enPassant_pb->check_piece(enPassant_pb) == PAWN && enPassant_pb->check_color(enPassant_pb) != selected_pb->check_color(selected_pb) && passantable == enPassant_pb) {
					// Perform en passant capture
					enPassant_pb->ImageLocation = ""; // Remove captured pawn image (optional)
					enPassant_pb->set_color(enPassant_pb, NONE); // Set color to NONE (optional)
					enPassant_pb->set_piece(enPassant_pb, EMPTY); // Set piece type to EMPTY (optional)
					return true;
				}
			}
		}

		// Check if the king is safe after the move
		bool king_safe_place = king_still_checked(pictureBoxes, selected_pb, target_pb, last_moved_piece);
		if (!king_safe_place) {
			return false;
		}

		return false;
	}
	//check does pb in board border
	bool BoardForm::check_sent(custom_picturebox^ selected_pb)
	{
		int x = selected_pb->Location.X;
		int y = selected_pb->Location.Y;

		int pbWidth = selected_pb->Width;
		int pbHeight = selected_pb->Height;
		int panelWidth = 460;
		int panelHeight = 460;
		int cellSize = 50;

		// Check if pb is within the panel boundaries
		if (x >= 0 && x + pbWidth <= panelWidth && y >= 0 && y + pbHeight <= panelHeight) {
			// Check if pb is not on the edge of a cell
			bool notOnEdgeX = (x % cellSize) != 0 && ((x + pbWidth) % cellSize) != 0;
			bool notOnEdgeY = (y % cellSize) != 0 && ((y + pbHeight) % cellSize) != 0;

			if (notOnEdgeX && notOnEdgeY) {
				return true;
			}
		}

		return false;
	}
	//check knight
	bool BoardForm::check_Knightmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		Point startPos = start_location; // Original position of the piece
		Point targetPos = selected_pb->Location; // New position of the piece

		// Calculate the difference in positions
		int dx = abs(targetPos.X - startPos.X) / selected_pb->Width; // difference in columns
		int dy = abs(targetPos.Y - startPos.Y) / selected_pb->Height; // difference in rows

		// Determine the row and column indices of the start and target positions
		int startRow = startPos.Y / selected_pb->Height;
		int startCol = startPos.X / selected_pb->Width;
		int targetRow = targetPos.Y / selected_pb->Height;
		int targetCol = targetPos.X / selected_pb->Width;

		// Constrain indices to the board range (0-7)
		startRow = Math::Min(startRow, 7);
		startCol = Math::Min(startCol, 7);
		targetRow = Math::Min(targetRow, 7);
		targetCol = Math::Min(targetCol, 7);

		// Check if indices are within bounds
		if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8 ||
			targetRow < 0 || targetRow >= 8 || targetCol < 0 || targetCol >= 8) {
			return false;
		}

		// Adjust coordinates for a flipped board
		if (boardFlipped) {
			startRow = 7 - startRow;
			startCol = 7 - startCol;
			targetRow = 7 - targetRow;
			targetCol = 7 - targetCol;
		}

		// Check if the move is a valid knight move: L-shaped movement
		if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
			custom_picturebox^ target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color(target_pb);
			Piece target_piece = target_pb->check_piece(target_pb);

			// Check if the target position is empty or occupied by an opponent's piece
			if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color(selected_pb) && target_piece != KING)) {
				return true;
			}
			else {
				return false;
			}
		}

		// If the move is not valid, bring all pieces to the front
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pictureBoxes[i][j]->BringToFront();
			}
		}

		return false;
	}
	//check bishop
	bool BoardForm::check_Bishopmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		Point startPos = start_location;
		Point targetPos = selected_pb->Location;

		int dx = abs(targetPos.X - startPos.X) / selected_pb->Width;
		int dy = abs(targetPos.Y - startPos.Y) / selected_pb->Height;

		int startRow = startPos.Y / selected_pb->Height;
		int startCol = startPos.X / selected_pb->Width;
		int targetRow = targetPos.Y / selected_pb->Height;
		int targetCol = targetPos.X / selected_pb->Width;

		startRow = Math::Min(startRow, 7);
		startCol = Math::Min(startCol, 7);
		targetRow = Math::Min(targetRow, 7);
		targetCol = Math::Min(targetCol, 7);

		if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8 ||
			targetRow < 0 || targetRow >= 8 || targetCol < 0 || targetCol >= 8) {
			return false;
		}

		// Check for Bishop move
		if (dx == dy) {
			if (!dx || !dy)
			{
				return false;
			}
			
				int stepX = (targetCol - startCol) / dx;
				int stepY = (targetRow - startRow) / dy;


			for (int i = 1; i < dx; ++i) {
				int currentRow = startRow + i * stepY;
				int currentCol = startCol + i * stepX;
				custom_picturebox^ current_pb = pictureBoxes[currentRow][currentCol];

				if (current_pb->check_piece(current_pb) != EMPTY) {
					return false;
				}
			}

			custom_picturebox^ target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color(target_pb);
			Piece target_piece = target_pb->check_piece(target_pb);

			if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color(selected_pb) && target_piece != KING)) {
				return true;
			}
			else {
				return false;
			}
		}

		// If the move is not valid, bring all pieces to front
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pictureBoxes[i][j]->BringToFront();
			}
		}
		return false;
	}
	//check rook
	bool BoardForm::check_Rookmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		Point startPos = start_location;
		Point targetPos = selected_pb->Location;

		int dx = abs(targetPos.X - startPos.X) / selected_pb->Width;
		int dy = abs(targetPos.Y - startPos.Y) / selected_pb->Height;

		int startRow = startPos.Y / selected_pb->Height;
		int startCol = startPos.X / selected_pb->Width;
		int targetRow = targetPos.Y / selected_pb->Height;
		int targetCol = targetPos.X / selected_pb->Width;

		startRow = Math::Min(startRow, 7);
		startCol = Math::Min(startCol, 7);
		targetRow = Math::Min(targetRow, 7);
		targetCol = Math::Min(targetCol, 7);

		if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8 ||
			targetRow < 0 || targetRow >= 8 || targetCol < 0 || targetCol >= 8) {
			return false;
		}

		if (dx == 0 || dy == 0) {
			int stepX = (targetCol - startCol) == 0 ? 0 : (targetCol - startCol) / abs(targetCol - startCol);
			int stepY = (targetRow - startRow) == 0 ? 0 : (targetRow - startRow) / abs(targetRow - startRow);

			int steps = Math::Max(dx, dy);

			for (int i = 1; i < steps; ++i) {
				int currentRow = startRow + i * stepY;
				int currentCol = startCol + i * stepX;
				custom_picturebox^ current_pb = pictureBoxes[currentRow][currentCol];

				if (current_pb->check_piece(current_pb) != EMPTY) {
					return false;
				}
			}

			custom_picturebox^ target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color(target_pb);
			Piece target_piece = target_pb->check_piece(target_pb);

			if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color(selected_pb) && target_piece != KING)) {

				if (selected_pb->check_color(selected_pb) == WHITE)
				{
					if(startCol >= 7)white_kingside_rook_moved = true;
					if (startCol <= 7)white_queenside_rook_moved = true;
				}
				else
				{
					if (startCol >= 7)black_kingside_rook_moved = true;
					if (startCol <= 7)black_queenside_rook_moved = true;
				}
				return true;
			}
			else {
				return false;
			}
		}

		// If the move is not valid, bring all pieces to front
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pictureBoxes[i][j]->BringToFront();
			}
		}
		return false;
	}
	//check queen
	bool BoardForm::check_Queenmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		Point startPos = start_location;
		Point targetPos = selected_pb->Location;

		int dx = abs(targetPos.X - startPos.X) / selected_pb->Width;
		int dy = abs(targetPos.Y - startPos.Y) / selected_pb->Height;

		int startRow = startPos.Y / selected_pb->Height;
		int startCol = startPos.X / selected_pb->Width;
		int targetRow = targetPos.Y / selected_pb->Height;
		int targetCol = targetPos.X / selected_pb->Width;

		startRow = Math::Min(startRow, 7);
		startCol = Math::Min(startCol, 7);
		targetRow = Math::Min(targetRow, 7);
		targetCol = Math::Min(targetCol, 7);

		if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8 ||
			targetRow < 0 || targetRow >= 8 || targetCol < 0 || targetCol >= 8) {
			return false;
		}

		// Rook-like move (horizontal or vertical)
		if (dx == 0 || dy == 0) {
			int stepX = (targetCol - startCol) == 0 ? 0 : (targetCol - startCol) / abs(targetCol - startCol);
			int stepY = (targetRow - startRow) == 0 ? 0 : (targetRow - startRow) / abs(targetRow - startRow);

			int steps = Math::Max(dx, dy);

			for (int i = 1; i < steps; ++i) {
				int currentRow = startRow + i * stepY;
				int currentCol = startCol + i * stepX;
				custom_picturebox^ current_pb = pictureBoxes[currentRow][currentCol];

				if (current_pb->check_piece(current_pb) != EMPTY) {
					return false;
				}
			}
		}
		// Bishop-like move (diagonal)
		else if (dx == dy) {
			int stepX = (targetCol - startCol) / dx;
			int stepY = (targetRow - startRow) / dy;

			for (int i = 1; i < dx; ++i) {
				int currentRow = startRow + i * stepY;
				int currentCol = startCol + i * stepX;
				custom_picturebox^ current_pb = pictureBoxes[currentRow][currentCol];

				if (current_pb->check_piece(current_pb) != EMPTY) {
					return false;
				}
			}
		}
		else {
			return false;
		}

		custom_picturebox^ target_pb = pictureBoxes[targetRow][targetCol];
		PieceColor check_targetpb = target_pb->check_color(target_pb);
		Piece target_piece = target_pb->check_piece(target_pb);

		if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color(selected_pb) && target_piece != KING)) {
			return true;
		}
		else {
			return false;
		}
	}
	//check king
	bool BoardForm::check_Kingmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		Point startPos = start_location; 
		Point targetPos = selected_pb->Location; 

		
		int dx = abs(targetPos.X - startPos.X) / selected_pb->Width;
		int dy = abs(targetPos.Y - startPos.Y) / selected_pb->Height; 

		
		int startRow = startPos.Y / selected_pb->Height;
		int startCol = startPos.X / selected_pb->Width;
		int targetRow = targetPos.Y / selected_pb->Height;
		int targetCol = targetPos.X / selected_pb->Width;

		startRow = Math::Max(0, Math::Min(startRow, 7));
		startCol = Math::Max(0, Math::Min(startCol, 7));
		targetRow = Math::Max(0, Math::Min(targetRow, 7));
		targetCol = Math::Max(0, Math::Min(targetCol, 7));

	
		if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8 ||
			targetRow < 0 || targetRow >= 8 || targetCol < 0 || targetCol >= 8) {
			return false;
		}

		if (dx <= 1 && dy <= 1) {
			custom_picturebox^ target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color(target_pb);
			Piece target_piece = target_pb->check_piece(target_pb);

			if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color(selected_pb) && target_piece != KING)) {
				PieceColor king_piece = selected_pb->check_color(selected_pb);

				if (king_piece == WHITE)
				{
					white_king_moved = true;
				}
				else if(king_piece == BLACK)
				{
					black_king_moved = true;
				}
				return true;
			}
		}

		
		if (dy == 0 && dx == 2 && targetCol > startCol) {
			custom_picturebox^ rook_pb = pictureBoxes[startRow][7];
			Piece rook_piece = rook_pb->check_piece(rook_pb);
			if (rook_piece == ROOK && rook_pb->check_color(rook_pb) == selected_pb->check_color(selected_pb)) 
			{
	
				bool pathClear = true;
				for (int i = startCol + 1; i < 7; i++) {
					if (pictureBoxes[startRow][i]->check_piece(pictureBoxes[startRow][i]) != EMPTY) {
						pathClear = false;
						break;
					}
				}
				if (pathClear) {
					if (selected_pb->check_color(selected_pb) == WHITE && !white_king_moved && !white_kingside_rook_moved)
					{
						castle(selected_pb, pictureBoxes[startRow][startCol + 2], rook_pb, pictureBoxes[startRow][startCol + 1]);
					}
					else if (selected_pb->check_color(selected_pb) == BLACK && !black_king_moved && !black_kingside_rook_moved)
					{
						castle(selected_pb, pictureBoxes[startRow][startCol + 2], rook_pb, pictureBoxes[startRow][startCol + 1]);
					}
					else
					{
						return false;
					}

				}
			}
		}
		if (dy == 0 && (dx == 3 || dx == 4) && targetCol < startCol) {
			custom_picturebox^ Qside_rook = pictureBoxes[startRow][0];
			Piece rook_piece2 = Qside_rook->check_piece(Qside_rook);

			if (rook_piece2 == ROOK && Qside_rook->check_color(Qside_rook) == selected_pb->check_color(selected_pb)) {
				bool pathClear = true;
				for (int i = startCol - 1; i > 0; i--) {
					if (pictureBoxes[startRow][i]->check_piece(pictureBoxes[startRow][i]) != EMPTY) {
						pathClear = false;
						break;
					}
				}
				if (pathClear) {
					if (selected_pb->check_color(selected_pb) == WHITE && !white_king_moved && !white_queenside_rook_moved)
					{
						castle(selected_pb, pictureBoxes[startRow][startCol - 2], Qside_rook, pictureBoxes[startRow][startCol - 1]);
					}
					else if (selected_pb->check_color(selected_pb) == BLACK && !black_king_moved && !black_queenside_rook_moved)
					{
						castle(selected_pb, pictureBoxes[startRow][startCol - 2], Qside_rook, pictureBoxes[startRow][startCol - 1]);
					}
					else
					{
						return false;
					}
				}
			}
		}

		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pictureBoxes[i][j]->BringToFront();
			}
		}
		return false;
	}
	
	void BoardForm::castle(custom_picturebox^ king, custom_picturebox^ king_dest, custom_picturebox^ rook, custom_picturebox^ rook_dest)
	{
		if (!white_king_on_checked || !black_king_on_checked)
		{
				Point start_king = king->Location;
				Point start_rook = rook->Location;

				String^ king_filepath = king->ImageLocation;
				PieceColor king_piececolor = king->check_color(king);
				Piece king_piece = king->check_piece(king);

				String^ rook_filepath = rook->ImageLocation;
				PieceColor rook_piececolor = rook->check_color(rook);
				Piece rook_piece = rook->check_piece(rook);

				rook_dest->ImageLocation = rook_filepath;
				rook_dest->set_color(rook_dest, rook_piececolor);
				rook_dest->set_piece(rook_dest, rook_piece);

				king_dest->ImageLocation = king_filepath;
				king_dest->set_color(king_dest, king_piececolor);
				king_dest->set_piece(king_dest, king_piece);


				king->ImageLocation = "";
				king->set_color(king, NONE);
				king->set_piece(king, EMPTY);

				rook->ImageLocation = "";
				rook->set_color(rook, NONE);
				rook->set_piece(rook, EMPTY);

				king->Enabled = false;
				rook->Enabled = false;

				king->Location = start_king;
				rook->Location = start_rook;

				king->BringToFront();
				rook->BringToFront();

				whiteonMove = !whiteonMove;
		}
	}

	void BoardForm::grid_panel_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		reset_highlight_moves();

		if (e->Button == System::Windows::Forms::MouseButtons::Right && e->Clicks == 1)
		{
			selectedPictureBox = dynamic_cast<custom_picturebox^>(sender);

			if (selectedPictureBox != nullptr && selectedPictureBox->Enabled == true)
			{
				current_color = selectedPictureBox->check_color(selectedPictureBox);

				if ((whiteonMove && current_color != WHITE) || (!whiteonMove && current_color != BLACK))
				{
					if (current_color != EMPTY && chosen_piece == nullptr)
					{
						return;
					}
				}

				if (chosen_piece == nullptr) 
				{
					HandlePieceSelection(selectedPictureBox);

					switch (current_piece)
					{
					case PAWN:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_PAWM(selectedPictureBox);
						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::Gray;
						break;
					case KNIGHT:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_KNIGHT(selectedPictureBox);
						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::Gray;
						break;
					case BISHOP:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_BISHOP(selectedPictureBox);
						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::Gray;
						break;
					case ROOK:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_ROOK(selectedPictureBox);

						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::Gray;
						break;
					case QUEEN:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_QUEEN(selectedPictureBox);

						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::Gray;
						break;
					case KING:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_KING(selectedPictureBox);

						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::Gray;
						break;
					case EMPTY:
						break;
					default:
						MessageBox::Show("Nieprawid³owa figura.");
						break;
					}
				}
				else  // If a piece is already selected
				{
					if (selectedPictureBox == chosen_piece)
					{
						reset_highlight_moves();
						chosen_piece->BackColor = System::Drawing::Color::Transparent;
						chosen_piece = nullptr;
					}
					else
					{
						HandlePieceSelection(chosen_piece);
						chosen_piece->Location = selectedPictureBox->Location;
						targetPictureBox = selectedPictureBox;
						HandlePieceUp(chosen_piece, selectedPictureBox);

						player_turnClick();
						chosen_piece = nullptr;
					}
				}
			}
		}
		else
		{
			reset_highlight_moves();
			if (chosen_piece != nullptr)
			{
				chosen_piece->BackColor = System::Drawing::Color::Transparent;  // Reset background color
				chosen_piece = nullptr;  // Deselect the piece
			}
			return;
		}
	}
   void BoardForm::highlight_possible_moves_PAWM(custom_picturebox^ selected_pb) {
	   // Resetuj podœwietlenia i cele ruchów
	   reset_highlight_moves();

	   if (selected_pb->ImageLocation != "") {
		   int startRow = -1;
		   int startCol = -1;
		   // Pobierz pozycjê wybranego pola
		   Point startPos = selected_pb->Location;
		   startRow = startPos.Y / selected_pb->Height;
		   startCol = startPos.X / selected_pb->Width;
		   int direction = selected_pb->check_color(selected_pb) == WHITE ? -1 : 1;

		   if(boardFlipped)direction = selected_pb->check_color(selected_pb) == WHITE ? 1 : -1;

		   PieceColor start_color = selected_pb->check_color(selected_pb);
		   Piece start_piece = selected_pb->check_piece(selected_pb);

		   // Upewnij siê, ¿e wiersz i kolumna s¹ w granicach planszy
		   startRow = Math::Min(startRow, 7);
		   startCol = Math::Min(startCol, 7);

		   // SprawdŸ, czy indeksy s¹ w zakresie planszy
		   if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8) {
			   return;
		   }

		   // Przesuniêcie do przodu o jedno pole
		   int targetRow = startRow + direction;
		   targetRow = Math::Min(targetRow, 7);

		   if (targetRow >= 0 && targetRow < 8) {
			   if (pictureBoxes[targetRow][startCol]->check_piece(pictureBoxes[targetRow][startCol]) == EMPTY) {
				   if (pictureBoxes[targetRow][startCol]->ImageLocation == "" && pictureBoxes[startRow][startCol] != nullptr) {
					   pictureBoxes[targetRow][startCol]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
				   }
				   selected_pb->set_piece(selected_pb, start_piece);
				   selected_pb->set_color(selected_pb, start_color);
			   }
		   }

		   // Przesuniêcie o dwa pola przy pierwszym ruchu
		   if ((startRow == 1 && direction == 1) || (startRow == 6 && direction == -1)) {
			   targetRow = startRow + 2 * direction;
			   if (targetRow >= 0 && targetRow < 8) {
				   if (pictureBoxes[startRow + direction][startCol]->check_piece(pictureBoxes[startRow + direction][startCol]) == EMPTY &&
					   pictureBoxes[targetRow][startCol]->check_piece(pictureBoxes[targetRow][startCol]) == EMPTY) {
					   if (pictureBoxes[targetRow][startCol]->ImageLocation == "" && pictureBoxes[startRow][startCol] != nullptr) {
						   pictureBoxes[targetRow][startCol]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
					   }
					   selected_pb->set_piece(selected_pb, start_piece);
					   selected_pb->set_color(selected_pb, start_color);
				   }
			   }
		   }

		   // Zbicie po skosie
		   int cols[2] = { startCol - 1, startCol + 1 };
		   for (int i = 0; i < 2; i++) {
			   if (cols[i] >= 0 && cols[i] < 8) {
				   targetRow = startRow + direction;
				   if (targetRow >= 0 && targetRow < 8) {
					   target_pb = pictureBoxes[targetRow][cols[i]];
					   enPassant_pb = pictureBoxes[startRow][cols[i]];

					   // SprawdŸ normalne zbicie
					   if (target_pb->check_piece(target_pb) != EMPTY &&
						   target_pb->check_color(target_pb) != selected_pb->check_color(selected_pb)) {
						   color_before = target_pb->check_color(target_pb);
						   target_pb->BackColor = System::Drawing::Color::DarkGreen;
						   target_pb->set_color(target_pb, GREEN);
					   }
					   // SprawdŸ bicie w przelocie
					   else if (target_pb->check_piece(target_pb) == EMPTY &&
						   enPassant_pb->check_piece(enPassant_pb) == PAWN &&
						   enPassant_pb->check_color(enPassant_pb) != selected_pb->check_color(selected_pb) &&
						   enPassant_pb == passantable) {

						   target_pb->onMoveIMG = true;
						   if (target_pb->ImageLocation == "" && enPassant_pb != nullptr) {
							   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
						   }

						   // Podœwietl pole za pionkiem, który mo¿na zbiæ
						   int enPassantRow = startRow + direction;
						   if (enPassantRow >= 0 && enPassantRow < 8) {
							   enPassantTarget_pb = pictureBoxes[enPassantRow][cols[i]];
							   if (target_pb->ImageLocation == "" && enPassant_pb != nullptr) {
								   enPassantTarget_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
							   }
						   }
					   }
				   }
			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_KNIGHT(custom_picturebox^ selected_pb)
   {
	   reset_highlight_moves();

	   Point startPos = selected_pb->Location;
	   int startRow = startPos.Y / selected_pb->Height;
	   int startCol = startPos.X / selected_pb->Width;

	   startRow = Math::Min(startRow, 7);
	   startCol = Math::Min(startCol, 7);

	   int knightMoves[8][2] = { {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2} };

	   for (int i = 0; i < 8; i++)
	   {
		   int targetRow = startRow + knightMoves[i][0];
		   int targetCol = startCol + knightMoves[i][1];

		   if (targetRow >= 0 && targetRow < 8 && targetCol >= 0 && targetCol < 8)
		   {
			   custom_picturebox^ target_pb = pictureBoxes[targetRow][targetCol];

			   if (target_pb->check_piece(target_pb) == EMPTY || target_pb->check_color(target_pb) != selected_pb->check_color(selected_pb))
			   {
				   if (target_pb->ImageLocation == "")
				   {
					   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; 
				   }
				   else
				   {
					   target_pb->BackColor = System::Drawing::Color::DarkGreen;
				   }

			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_BISHOP(custom_picturebox^ selected_pb)
   {
	   reset_highlight_moves();

	   Point startPos = selected_pb->Location;
	   int startRow = startPos.Y / selected_pb->Height;
	   int startCol = startPos.X / selected_pb->Width;

	   startRow = Math::Min(startRow, 7);
	   startCol = Math::Min(startCol, 7);

	   if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8) {
		   return; 
	   }

	   PieceColor bishopColor = selected_pb->check_color(selected_pb);

	   int directions[4][2] = {
		   {-1, -1}, 
		   {-1,  1}, 
		   { 1, -1}, 
		   { 1,  1}  
	   };

	   for (int d = 0; d < 4; ++d) {
		   int row = startRow;
		   int col = startCol;

		   while (true) {
			   row += directions[d][0];
			   col += directions[d][1];

			   if (row < 0 || row >= 8 || col < 0 || col >= 8) {
				   break;
			   }

			   custom_picturebox^ target_pb = pictureBoxes[row][col];

			   if (target_pb->check_piece(target_pb) == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }
			   else if (target_pb->check_color(target_pb) != bishopColor) {
				   target_pb->BackColor = System::Drawing::Color::DarkGreen;
				   break;
			   }
			   else {
				   break;
			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_ROOK(custom_picturebox^ selected_pb)
   {
	   reset_highlight_moves();

	   Point startPos = selected_pb->Location;
	   int startRow = startPos.Y / selected_pb->Height;
	   int startCol = startPos.X / selected_pb->Width;

	   startRow = Math::Min(startRow, 7);
	   startCol = Math::Min(startCol, 7);


	   if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8) {
		   return;  
	   }

	   PieceColor rookColor = selected_pb->check_color(selected_pb);

	   int directions[4][2] = {
		   {-1,  0},
		   { 1,  0}, 
		   { 0, -1},
		   { 0,  1} 
	   };

	   for (int d = 0; d < 4; ++d) {
		   int row = startRow;
		   int col = startCol;

		   while (true) {
			   row += directions[d][0];
			   col += directions[d][1];

			   if (row < 0 || row >= 8 || col < 0 || col >= 8) {
				   break;
			   }

			   custom_picturebox^ target_pb = pictureBoxes[row][col];

			   if (target_pb->check_piece(target_pb) == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }

			   else if (target_pb->check_color(target_pb) != rookColor) {
				   target_pb->BackColor = System::Drawing::Color::DarkGreen;
				   break;
			   }
			   else {
				   break;
			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_QUEEN(custom_picturebox^ selected_pb)
   {
	   reset_highlight_moves();

	   Point startPos = selected_pb->Location;
	   int startRow = startPos.Y / selected_pb->Height;
	   int startCol = startPos.X / selected_pb->Width;

	   startRow = Math::Min(startRow, 7);
	   startCol = Math::Min(startCol, 7);


	   if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8) {
		   return;  
	   }

	   PieceColor queenColor = selected_pb->check_color(selected_pb);

	   int bishopDirections[4][2] = {
		   {-1, -1}, 
		   {-1,  1}, 
		   { 1, -1}, 
		   { 1,  1}  
	   };

	   int rookDirections[4][2] = {
		   {-1,  0}, 
		   { 1,  0}, 
		   { 0, -1}, 
		   { 0,  1}  
	   };


	   for (int d = 0; d < 4; ++d) {
		   int row = startRow;
		   int col = startCol;

		   while (true) {
			   row += bishopDirections[d][0];
			   col += bishopDirections[d][1];

			   if (row < 0 || row >= 8 || col < 0 || col >= 8) {
				   break;
			   }

			   custom_picturebox^ target_pb = pictureBoxes[row][col];

			   if (target_pb->check_piece(target_pb) == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }

			   else if (target_pb->check_color(target_pb) != queenColor) {
				   target_pb->BackColor = System::Drawing::Color::DarkGreen;
				   break;
			   }

			   else {
				   break;
			   }
		   }
	   }

	   for (int d = 0; d < 4; ++d) {
		   int row = startRow;
		   int col = startCol;

		   while (true) {
			   row += rookDirections[d][0];
			   col += rookDirections[d][1];

			   if (row < 0 || row >= 8 || col < 0 || col >= 8) {
				   break;
			   }

			   custom_picturebox^ target_pb = pictureBoxes[row][col];

			   if (target_pb->check_piece(target_pb) == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }

			   else if (target_pb->check_color(target_pb) != queenColor) {
				   target_pb->BackColor = System::Drawing::Color::DarkGreen;
				   break;
			   }

			   else {
				   break;
			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_KING(custom_picturebox^ selected_pb)
   {
	   reset_highlight_moves(); // Resetuj poprzednie podœwietlenia ruchów

	   // Ustal pozycjê startow¹ króla
	   Point startPos = selected_pb->Location;
	   int startRow = startPos.Y / selected_pb->Height;
	   int startCol = startPos.X / selected_pb->Width;

	   // Upewnij siê, ¿e pozycje startowe s¹ w zakresie planszy
	   startRow = Math::Min(startRow, 7);
	   startCol = Math::Min(startCol, 7);

	   if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8) {
		   return;
	   }

	   PieceColor kingColor = selected_pb->check_color(selected_pb);

	   // Kierunki ruchów króla (wszystkie 8 mo¿liwych)
	   int kingDirections[8][2] = {
		   {-1, -1}, {-1,  0}, {-1,  1},
		   { 0, -1},          { 0,  1},
		   { 1, -1}, { 1,  0}, { 1,  1}
	   };

	   // SprawdŸ wszystkie mo¿liwe ruchy dla króla
	   for (int d = 0; d < 8; ++d) {
		   int row = startRow + kingDirections[d][0];
		   int col = startCol + kingDirections[d][1];

		   // SprawdŸ czy pozycja znajduje siê w zakresie planszy
		   if (row < 0 || row >= 8 || col < 0 || col >= 8) {
			   continue;
		   }

		   custom_picturebox^ target_pb = pictureBoxes[row][col];

		   // SprawdŸ czy pole nie jest pod atakiem
		   if (!is_square_under_attack(row, col, kingColor)) {
			   // Jeœli pole jest puste, podœwietl jako mo¿liwy ruch
			   if (target_pb->check_piece(target_pb) == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }
			   // Jeœli na polu jest przeciwnik, podœwietl jako mo¿liwoœæ zbicia
			   else if (target_pb->check_color(target_pb) != kingColor) {
				   target_pb->BackColor = System::Drawing::Color::DarkGreen;
			   }
		   }
	   }

	   // Obs³uga roszady
	   if (kingColor == WHITE && !white_king_moved && !white_king_on_checked) {
		   // SprawdŸ roszadê po stronie królewskiej (król w prawo)
		   custom_picturebox^ kingsideRook = pictureBoxes[startRow][7];
		   if (kingsideRook->check_piece(kingsideRook) == ROOK &&
			   kingsideRook->check_color(kingsideRook) == WHITE &&
			   !white_kingside_rook_moved) {

			   bool pathClear = true;
			   for (int i = startCol + 1; i < 7; i++) {
				   if (pictureBoxes[startRow][i]->check_piece(pictureBoxes[startRow][i]) != EMPTY) {
					   pathClear = false;
					   break;
				   }
			   }

			   // Upewnij siê, ¿e pola miêdzy królem a wie¿¹ s¹ wolne i nie s¹ pod atakiem
			   if (pathClear &&
				   !is_square_under_attack(startRow, startCol + 1, WHITE) &&
				   !is_square_under_attack(startRow, startCol + 2, WHITE)) {

				   pictureBoxes[startRow][startCol + 2]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; // Podœwietlenie pola na roszadê
				   kingsideRook->BackColor = System::Drawing::Color::LightBlue; // Podœwietlenie wie¿y
			   }
		   }

		   // SprawdŸ roszadê po stronie hetmañskiej (król w lewo)
		   custom_picturebox^ queensideRook = pictureBoxes[startRow][0];
		   if (queensideRook->check_piece(queensideRook) == ROOK &&
			   queensideRook->check_color(queensideRook) == WHITE &&
			   !white_queenside_rook_moved) {

			   bool pathClear = true;
			   for (int i = startCol - 1; i > 0; i--) {
				   if (pictureBoxes[startRow][i]->check_piece(pictureBoxes[startRow][i]) != EMPTY) {
					   pathClear = false;
					   break;
				   }
			   }

			   // Upewnij siê, ¿e pola miêdzy królem a wie¿¹ s¹ wolne i nie s¹ pod atakiem
			   if (pathClear &&
				   !is_square_under_attack(startRow, startCol - 1, WHITE) &&
				   !is_square_under_attack(startRow, startCol - 2, WHITE)) {

				   pictureBoxes[startRow][startCol - 2]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; // Podœwietlenie pola na roszadê
				   queensideRook->BackColor = System::Drawing::Color::LightBlue; // Podœwietlenie wie¿y
			   }
		   }
	   }
	   else if (kingColor == BLACK && !black_king_moved && !black_king_on_checked) {
		   // Analogiczna obs³uga roszady dla czarnego króla
		   custom_picturebox^ kingsideRook = pictureBoxes[startRow][7];
		   if (kingsideRook->check_piece(kingsideRook) == ROOK &&
			   kingsideRook->check_color(kingsideRook) == BLACK &&
			   !black_kingside_rook_moved) {

			   bool pathClear = true;
			   for (int i = startCol + 1; i < 7; i++) {
				   if (pictureBoxes[startRow][i]->check_piece(pictureBoxes[startRow][i]) != EMPTY) {
					   pathClear = false;
					   break;
				   }
			   }

			   if (pathClear &&
				   !is_square_under_attack(startRow, startCol + 1, BLACK) &&
				   !is_square_under_attack(startRow, startCol + 2, BLACK)) {

				   pictureBoxes[startRow][startCol + 2]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; // Podœwietlenie pola na roszadê
				   kingsideRook->BackColor = System::Drawing::Color::LightBlue; // Podœwietlenie wie¿y
			   }
		   }

		   custom_picturebox^ queensideRook = pictureBoxes[startRow][0];
		   if (queensideRook->check_piece(queensideRook) == ROOK &&
			   queensideRook->check_color(queensideRook) == BLACK &&
			   !black_queenside_rook_moved) {

			   bool pathClear = true;
			   for (int i = startCol - 1; i > 0; i--) {
				   if (pictureBoxes[startRow][i]->check_piece(pictureBoxes[startRow][i]) != EMPTY) {
					   pathClear = false;
					   break;
				   }
			   }

			   if (pathClear &&
				   !is_square_under_attack(startRow, startCol - 1, BLACK) &&
				   !is_square_under_attack(startRow, startCol - 2, BLACK)) {

				   pictureBoxes[startRow][startCol - 2]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; // Podœwietlenie pola na roszadê
				   queensideRook->BackColor = System::Drawing::Color::LightBlue; // Podœwietlenie wie¿y
			   }
		   }
	   }
   }

   void BoardForm::reset_highlight_moves()
   {
	   for (int i = 0; i < 8; ++i) {
		   for (int j = 0; j < 8; ++j) {

			   // Reset t³a, jeœli pole by³o podœwietlone na zielono lub szaro
			   if (pictureBoxes[i][j]->BackColor == System::Drawing::Color::DarkGreen ||
				   pictureBoxes[i][j]->BackColor == System::Drawing::Color::Gray ||
				   pictureBoxes[i][j]->BackColor == System::Drawing::Color::LightBlue) {

				   pictureBoxes[i][j]->BackColor = System::Drawing::Color::Transparent;
			   }
			   // Resetowanie obrazka dla pól podœwietlonych jako mo¿liwe ruchy
			   if (pictureBoxes[i][j]->ImageLocation == "C:\\Users\\USER\\Desktop\\on_move.png")
			   {
				   pictureBoxes[i][j]->BackColor = System::Drawing::Color::Transparent;
				   pictureBoxes[i][j]->ImageLocation = "";
			   }
		   }
	   }

	   one_piece = true; // Reset stanu, by pozwoliæ na wybór nowej figury
   }

   bool BoardForm::is_square_under_attack(int row, int col, PieceColor kingColor)
   {
	   // Iterate through all squares on the board
	   for (int r = 0; r < 8; ++r) {
		   for (int c = 0; c < 8; ++c) {
			   custom_picturebox^ pieceBox = pictureBoxes[r][c];
			   if (pieceBox->check_color(pieceBox) != kingColor && pieceBox->check_piece(pieceBox) != EMPTY) {
				   // If the piece is an opponent piece and not empty, check if it attacks the square
				   if (is_king_under_attack(pieceBox, row, col)) {
					   return true;
				   }
			   }
		   }
	   }
	   return false;
   }

   void BoardForm::reset_pb(array<array<custom_picturebox^>^>^ pictureBoxes)
   {
	  for (int i = 0; i < 8; i++) {
		   for (int j = 0; j < 8; j++)
		   {
			   if (pictureBoxes[i][j]->ImageLocation == "C:\\Users\\USER\\Desktop\\on_move.png")pictureBoxes[i][j]->ImageLocation = "";
		   }
	  }
   }
   bool BoardForm::king_checked(array<array<custom_picturebox^>^>^ pictureBoxes,custom_picturebox^ selected_piece)
   {
	   custom_picturebox^ whiteKingBox = nullptr;
	   custom_picturebox^ blackKingBox = nullptr;
	   int whiteKingRow = -1, whiteKingCol = -1;
	   int blackKingRow = -1, blackKingCol = -1;

	   whiteKingRow = std::min(whiteKingRow, 7);
	   whiteKingCol = std::min(whiteKingCol, 7);

	   blackKingRow = std::min(blackKingRow, 7);
	   blackKingCol = std::min(blackKingCol, 7);

	   white_king_on_checked = false;
	   black_king_on_checked = false;

	   for (int i = 0; i < 8; i++) {
		   for (int j = 0; j < 8; j++) {
			   if (pictureBoxes[i][j]->check_piece(pictureBoxes[i][j]) == KING) {
				   if (pictureBoxes[i][j]->check_color(pictureBoxes[i][j]) == WHITE) {
					   whiteKingBox = pictureBoxes[i][j];
					   whiteKingRow = i;
					   whiteKingCol = j;
				   }
				   else {
					   blackKingBox = pictureBoxes[i][j];
					   blackKingRow = i;
					   blackKingCol = j;
				   }
			   }
		   }
	   }
	   // SprawdŸ szachowanie bia³ego króla
	   if (whiteKingBox != nullptr) {
		   // Przejrzyj wszystkie pola, aby znaleŸæ figury przeciwnika
		   for (int i = 0; i < 8; i++) {
			   for (int j = 0; j < 8; j++) {
				   if (pictureBoxes[i][j]->check_color(pictureBoxes[i][j]) == BLACK && pictureBoxes[i][j] != selected_piece) {

					   pictureBoxes[i][j]->column = std::min(j, 7);
					   pictureBoxes[i][j]->row = std::min(i, 7);

						   if (is_king_under_attack(pictureBoxes[i][j], whiteKingRow, whiteKingCol)) {
							   // Ustawienie obrazka na szachowanego króla
							   whiteKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king_checked.png";
							   // Ustaw ostatni¹ ruchom¹ figurê
							   last_moved_piece = selected_piece;
							   white_king_on_checked = true;
							   return true;
			               }
				   }
			   }
		   }

		   whiteKingBox->row = whiteKingRow;
		   whiteKingBox->column = whiteKingCol;
		   whiteKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.png";


	   }

	   // SprawdŸ szachowanie czarnego króla
	   if (blackKingBox != nullptr) {
		   // Przejrzyj wszystkie pola, aby znaleŸæ figury przeciwnika
		   for (int i = 0; i < 8; i++) {
			   for (int j = 0; j < 8; j++) {
				   if (pictureBoxes[i][j]->check_color(pictureBoxes[i][j]) == WHITE && pictureBoxes[i][j] != selected_piece) {

					   pictureBoxes[i][j]->column = std::min(j, 7);
					   pictureBoxes[i][j]->row = std::min(i, 7);

						   if (is_king_under_attack(pictureBoxes[i][j], blackKingRow, blackKingCol)) {
							   // Ustawienie obrazka na szachowanego król
							   blackKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king_checked.png";
							   // Ustaw ostatni¹ ruchom¹ figurê
							   last_moved_piece = selected_piece;
							   black_king_on_checked = true;
							   return true;
						   }			  
				   }
			   }

		   }
		   // Powrót do normalnego obrazka króla po wyjœciu ze szacha
		    blackKingBox->row = std::min(blackKingRow, 7);
		    blackKingBox->column = std::min(blackKingCol, 7);
		    blackKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";
	   }


	   return false;
   }

   bool BoardForm::is_king_under_attack(custom_picturebox^ piece, int kingRow, int kingCol)
   {
	   switch (piece->check_piece(piece)) {
	   case PAWN:
		   return check_Pawn_Attack(piece, kingRow, kingCol);
	   case KNIGHT:
		   return check_Knight_Attack(piece, kingRow, kingCol);
	   case BISHOP:
		   return check_Bishop_Attack(piece, kingRow, kingCol);
	   case ROOK:
		   return check_Rook_Attack(piece, kingRow, kingCol);
	   case QUEEN:
		   return check_Queen_Attack(piece, kingRow, kingCol);
	   default:
		   return false;
	   }
   }

   bool BoardForm::check_Pawn_Attack(custom_picturebox^ pawnBox, int kingRow, int kingCol)
   {
	   int pawnRow = pawnBox->row;
	   int pawnCol = pawnBox->column;
	   PieceColor pawnColor = pawnBox->check_color(pawnBox);

	   if (pawnColor == WHITE)
	   {
		   if ((pawnRow - 1 == kingRow) && (pawnCol - 1 == kingCol || pawnCol + 1 == kingCol))
			   return true;
		   if (pawnRow == 6 && (pawnRow - 2 == kingRow) && (pawnCol - 1 == kingCol || pawnCol + 1 == kingCol))
			   return true;
	   }
	   else if (pawnColor == BLACK) 
	   {
		   if ((pawnRow + 1 == kingRow) && (pawnCol - 1 == kingCol || pawnCol + 1 == kingCol))
			   return true;
		   if (pawnRow == 1 && (pawnRow + 2 == kingRow) && (pawnCol - 1 == kingCol || pawnCol + 1 == kingCol))
			   return true;
	   }

	   return false;
   }
   bool BoardForm::check_Knight_Attack(custom_picturebox^ knightBox, int kingRow, int kingCol)
   {
	   int knightRow = knightBox->row;
	   int knightCol = knightBox->column;

	
	   array<Point>^ knightMoves = gcnew array<Point>
	   {
		   Point(-2, -1), Point(-2, 1), Point(-1, -2), Point(-1, 2),
			   Point(1, -2), Point(1, 2), Point(2, -1), Point(2, 1)
	   };

	   for each (Point move in knightMoves)
	   {
		   int newRow = knightRow + move.X;
		   int newCol = knightCol + move.Y;

		   if (newRow == kingRow && newCol == kingCol) 
		   {
			   return true;
		   }
	   }

	   return false;
   }

   bool BoardForm::check_Bishop_Attack(custom_picturebox^ bishopBox, int kingRow, int kingCol)
   {
	   int bishopRow = bishopBox->row;
	   int bishopCol = bishopBox->column;

	   if (abs(kingRow - bishopRow) == abs(kingCol - bishopCol)) {
		   int rowDirection = (kingRow > bishopRow) ? 1 : -1;
		   int colDirection = (kingCol > bishopCol) ? 1 : -1;

		   int currentRow = bishopRow + rowDirection;
		   int currentCol = bishopCol + colDirection;
		   while (currentRow != kingRow && currentCol != kingCol) {
			   if (pictureBoxes[currentRow][currentCol]->check_piece(pictureBoxes[currentRow][currentCol]) != NONE) {
				   return false;
			   }
			   currentRow += rowDirection;
			   currentCol += colDirection;
		   }
		   return true;
	   }

	   return false;
   }

   bool BoardForm::check_Rook_Attack(custom_picturebox^ rookBox, int kingRow, int kingCol)
   {
	   int rookRow = rookBox->row;
	   int rookCol = rookBox->column;

	   if (rookRow == kingRow || rookCol == kingCol)
	   {
		   if (rookRow == kingRow) 
		   {
			   int startCol, endCol;
			   if (rookCol < kingCol)
			   {
				   startCol = rookCol + 1;
				   endCol = kingCol;
			   }
			   else
			   {
				   startCol = kingCol + 1;
				   endCol = rookCol;
			   }

			   for (int col = startCol; col < endCol; ++col)
			   {
				   if (pictureBoxes[rookRow][col]->check_piece(pictureBoxes[rookRow][col]) != NONE)
				   {
					   return false;
				   }
			   }
			   return true; 
		   }
		   else 
		   {
			   int startRow, endRow;
			   if (rookRow < kingRow)
			   {
				   startRow = rookRow + 1;
				   endRow = kingRow;
			   }
			   else
			   {
				   startRow = kingRow + 1;
				   endRow = rookRow;
			   }

			   for (int row = startRow; row < endRow; ++row)
			   {
				   if (pictureBoxes[row][rookCol]->check_piece(pictureBoxes[row][rookCol]) != NONE)
				   {
					   return false; 
				   }
			   }
			   return true; 
		   }
	   }

	   return false;
   }
   bool BoardForm::check_Queen_Attack(custom_picturebox^ queenBox, int kingRow, int kingCol)
   {
	   if (check_Rook_Attack(queenBox, kingRow, kingCol)||check_Bishop_Attack(queenBox, kingRow, kingCol))
	   {
		   return true;
	   }
	   return false;
   }

   Void BoardForm::picturebox_bishop_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
   {
	   if (!whiteonMove)
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_bishop.png";
		   targetPictureBox->set_color(targetPictureBox, WHITE);
	   }
	   else
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_bishop.png";
		   targetPictureBox->set_color(targetPictureBox, BLACK);
	   }
	   targetPictureBox->set_piece(targetPictureBox, BISHOP);
	   grid_panel->Enabled = true;
	   promote_panel->Visible = false;
	   promote_panel->Enabled = false;
	   promote_panel->SendToBack();
   }
   Void BoardForm::picturebox_rook_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
   {
	   if (!whiteonMove)
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_rook.png";
		   targetPictureBox->set_color(targetPictureBox, WHITE);
	   }
	   else
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_rook.png";
		   targetPictureBox->set_color(targetPictureBox, BLACK);
	   }
	   targetPictureBox->set_piece(targetPictureBox, ROOK);
	   grid_panel->Enabled = true;
	   promote_panel->Visible = false;
	   promote_panel->Enabled = false;
	   promote_panel->SendToBack();
   }
   Void BoardForm::picturebox_knight_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
   {
	   if (!whiteonMove)
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_knight.png";
		   targetPictureBox->set_color(targetPictureBox, WHITE);
	   }
	   else
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_knight.png";
		   targetPictureBox->set_color(targetPictureBox, BLACK);
	   }

	   targetPictureBox->set_piece(targetPictureBox, KNIGHT);
	   grid_panel->Enabled = true;
	   promote_panel->Visible = false;
	   promote_panel->Enabled = false;
	   promote_panel->SendToBack();
   }
   Void BoardForm::picturebox_queen_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
   {
	   if (!whiteonMove)
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_queen.png";
		   targetPictureBox->set_color(targetPictureBox, WHITE);
	   }
	   else
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_queen.png";
		   targetPictureBox->set_color(targetPictureBox, BLACK);
	   }
	   targetPictureBox->set_piece(targetPictureBox, QUEEN);
	   grid_panel->Enabled = true;
	   promote_panel->Visible = false;
	   promote_panel->Enabled = false;
	   promote_panel->SendToBack();
   }

   //check is king chechmated

   bool BoardForm::is_king_still_in_check_after_move(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ selected, custom_picturebox^ target) {
	   // Temporarily make the move
	   Piece originalPiece = target->check_piece(target);
	   PieceColor originalColor = target->check_color(target);
	   String^ originalImageLocation = target->ImageLocation;

	   target->set_piece(target, selected->check_piece(selected));
	   target->set_color(target, selected->check_color(selected));
	   target->ImageLocation = selected->ImageLocation;

	   selected->set_piece(selected, EMPTY);
	   selected->set_color(selected, NONE);
	   selected->ImageLocation = "";

	   bool stillInCheck = king_still_checked(pb, selected, target, nullptr);

	   // Revert the move
	   selected->set_piece(selected, target->check_piece(target));
	   selected->set_color(selected, target->check_color(target));
	   selected->ImageLocation = target->ImageLocation;

	   target->set_piece(target, originalPiece);
	   target->set_color(target, originalColor);
	   target->ImageLocation = originalImageLocation;

	   return stillInCheck;
   }

   bool BoardForm::pawn_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox)
   {
	   int row = currentBox->row;
	   int col = currentBox->column;
	   PieceColor pieceColor = currentBox->check_color(currentBox);

	   // Kierunek ruchu pionka zale¿y od koloru (bia³e pionki id¹ w górê, czarne w dó³)
	   int direction = (pieceColor == WHITE) ? -1 : 1;

	   // Sprawdzamy ruch do przodu o jedno pole
	   if (row + direction >= 0 && row + direction < 8) {
		   if (pb[row + direction][col]->check_piece(pb[row + direction][col]) == EMPTY) {
			   // Symulujemy ruch pionka
			   custom_picturebox^ originalBox = pb[row + direction][col];
			   Piece originalPiece = originalBox->check_piece(originalBox);
			   PieceColor originalColor = originalBox->check_color(originalBox);
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[row + direction][col]->ImageLocation = currentBox->ImageLocation;
			   pb[row + direction][col]->set_piece(pb[row + direction][col], currentBox->check_piece(currentBox));
			   pb[row + direction][col]->set_color(pb[row + direction][col], currentBox->check_color(currentBox));

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(currentBox, EMPTY);
			   currentBox->set_color(currentBox, NONE);

			   // Sprawdzamy, czy król jest nadal w szachu
			   if (!king_still_checked(pb, nullptr, nullptr, nullptr)) {
				   // Przywracamy pierwotny stan
				   currentBox->ImageLocation = pb[row + direction][col]->ImageLocation;
				   currentBox->set_piece(currentBox, pb[row + direction][col]->check_piece(pb[row + direction][col]));
				   currentBox->set_color(currentBox, pb[row + direction][col]->check_color(pb[row + direction][col]));

				   pb[row + direction][col]->ImageLocation = originalImageLocation;
				   pb[row + direction][col]->set_piece(pb[row + direction][col], originalPiece);
				   pb[row + direction][col]->set_color(pb[row + direction][col], originalColor);

				   return true; // Pionek mo¿e zas³oniæ szacha
			   }

			   // Przywracamy pierwotny stan
			   currentBox->ImageLocation = pb[row + direction][col]->ImageLocation;
			   currentBox->set_piece(currentBox, pb[row + direction][col]->check_piece(pb[row + direction][col]));
			   currentBox->set_color(currentBox, pb[row + direction][col]->check_color(pb[row + direction][col]));

			   pb[row + direction][col]->ImageLocation = originalImageLocation;
			   pb[row + direction][col]->set_piece(pb[row + direction][col], originalPiece);
			   pb[row + direction][col]->set_color(pb[row + direction][col], originalColor);
		   }
	   }

	   // Sprawdzamy ruch do przodu o dwa pola (tylko z pozycji pocz¹tkowej)
	   if ((pieceColor == WHITE && row == 6) || (pieceColor == BLACK && row == 1)) {
		   if (pb[row + direction][col]->check_piece(pb[row + direction][col]) == EMPTY &&
			   pb[row + 2 * direction][col]->check_piece(pb[row + 2 * direction][col]) == EMPTY) {
			   // Symulujemy ruch pionka
			   custom_picturebox^ originalBox = pb[row + 2 * direction][col];
			   Piece originalPiece = originalBox->check_piece(originalBox);
			   PieceColor originalColor = originalBox->check_color(originalBox);
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[row + 2 * direction][col]->ImageLocation = currentBox->ImageLocation;
			   pb[row + 2 * direction][col]->set_piece(pb[row + 2 * direction][col], currentBox->check_piece(currentBox));
			   pb[row + 2 * direction][col]->set_color(pb[row + 2 * direction][col], currentBox->check_color(currentBox));

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(currentBox, EMPTY);
			   currentBox->set_color(currentBox, NONE);

			   // Sprawdzamy, czy król jest nadal w szachu
			   if (!king_still_checked(pb, nullptr, nullptr, nullptr)) {
				   // Przywracamy pierwotny stan
				   currentBox->ImageLocation = pb[row + 2 * direction][col]->ImageLocation;
				   currentBox->set_piece(currentBox, pb[row + 2 * direction][col]->check_piece(pb[row + 2 * direction][col]));
				   currentBox->set_color(currentBox, pb[row + 2 * direction][col]->check_color(pb[row + 2 * direction][col]));

				   pb[row + 2 * direction][col]->ImageLocation = originalImageLocation;
				   pb[row + 2 * direction][col]->set_piece(pb[row + 2 * direction][col], originalPiece);
				   pb[row + 2 * direction][col]->set_color(pb[row + 2 * direction][col], originalColor);

				   return true; // Pionek mo¿e zas³oniæ szacha
			   }

			   // Przywracamy pierwotny stan
			   currentBox->ImageLocation = pb[row + 2 * direction][col]->ImageLocation;
			   currentBox->set_piece(currentBox, pb[row + 2 * direction][col]->check_piece(pb[row + 2 * direction][col]));
			   currentBox->set_color(currentBox, pb[row + 2 * direction][col]->check_color(pb[row + 2 * direction][col]));

			   pb[row + 2 * direction][col]->ImageLocation = originalImageLocation;
			   pb[row + 2 * direction][col]->set_piece(pb[row + 2 * direction][col], originalPiece);
			   pb[row + 2 * direction][col]->set_color(pb[row + 2 * direction][col], originalColor);
		   }
	   }

	   // Sprawdzamy ruchy bij¹ce (po skosie)
	   if (col > 0 && row + direction >= 0 && row + direction < 8) {
		   if (pb[row + direction][col - 1]->check_piece(pb[row + direction][col - 1]) != EMPTY &&
			   pb[row + direction][col - 1]->check_color(pb[row + direction][col - 1]) != pieceColor) {
			   // Symulujemy ruch pionka
			   custom_picturebox^ originalBox = pb[row + direction][col - 1];
			   Piece originalPiece = originalBox->check_piece(originalBox);
			   PieceColor originalColor = originalBox->check_color(originalBox);
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[row + direction][col - 1]->ImageLocation = currentBox->ImageLocation;
			   pb[row + direction][col - 1]->set_piece(pb[row + direction][col - 1], currentBox->check_piece(currentBox));
			   pb[row + direction][col - 1]->set_color(pb[row + direction][col - 1], currentBox->check_color(currentBox));

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(currentBox, EMPTY);
			   currentBox->set_color(currentBox, NONE);

			   // Sprawdzamy, czy król jest nadal w szachu
			   if (!king_still_checked(pb, nullptr, nullptr, nullptr)) {
				   // Przywracamy pierwotny stan
				   currentBox->ImageLocation = pb[row + direction][col - 1]->ImageLocation;
				   currentBox->set_piece(currentBox, pb[row + direction][col - 1]->check_piece(pb[row + direction][col - 1]));
				   currentBox->set_color(currentBox, pb[row + direction][col - 1]->check_color(pb[row + direction][col - 1]));

				   pb[row + direction][col - 1]->ImageLocation = originalImageLocation;
				   pb[row + direction][col - 1]->set_piece(pb[row + direction][col - 1], originalPiece);
				   pb[row + direction][col - 1]->set_color(pb[row + direction][col - 1], originalColor);

				   return true; // Pionek mo¿e zas³oniæ szacha
			   }

			   // Przywracamy pierwotny stan
			   currentBox->ImageLocation = pb[row + direction][col - 1]->ImageLocation;
			   currentBox->set_piece(currentBox, pb[row + direction][col - 1]->check_piece(pb[row + direction][col - 1]));
			   currentBox->set_color(currentBox, pb[row + direction][col - 1]->check_color(pb[row + direction][col - 1]));

			   pb[row + direction][col - 1]->ImageLocation = originalImageLocation;
			   pb[row + direction][col - 1]->set_piece(pb[row + direction][col - 1], originalPiece);
			   pb[row + direction][col - 1]->set_color(pb[row + direction][col - 1], originalColor);
		   }
	   }

	   if (col < 7 && row + direction >= 0 && row + direction < 8) {
		   if (pb[row + direction][col + 1]->check_piece(pb[row + direction][col + 1]) != EMPTY &&
			   pb[row + direction][col + 1]->check_color(pb[row + direction][col + 1]) != pieceColor) {
			   // Symulujemy ruch pionka
			   custom_picturebox^ originalBox = pb[row + direction][col + 1];
			   Piece originalPiece = originalBox->check_piece(originalBox);
			   PieceColor originalColor = originalBox->check_color(originalBox);
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[row + direction][col + 1]->ImageLocation = currentBox->ImageLocation;
			   pb[row + direction][col + 1]->set_piece(pb[row + direction][col + 1], currentBox->check_piece(currentBox));
			   pb[row + direction][col + 1]->set_color(pb[row + direction][col + 1], currentBox->check_color(currentBox));

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(currentBox, EMPTY);
			   currentBox->set_color(currentBox, NONE);

			   // Sprawdzamy, czy król jest nadal w szachu
			   if (!king_still_checked(pb, nullptr, nullptr, nullptr)) {
				   // Przywracamy pierwotny stan
				   currentBox->ImageLocation = pb[row + direction][col + 1]->ImageLocation;
				   currentBox->set_piece(currentBox, pb[row + direction][col + 1]->check_piece(pb[row + direction][col + 1]));
				   currentBox->set_color(currentBox, pb[row + direction][col + 1]->check_color(pb[row + direction][col + 1]));

				   pb[row + direction][col + 1]->ImageLocation = originalImageLocation;
				   pb[row + direction][col + 1]->set_piece(pb[row + direction][col + 1], originalPiece);
				   pb[row + direction][col + 1]->set_color(pb[row + direction][col + 1], originalColor);

				   return true; // Pionek mo¿e zas³oniæ szacha
			   }

			   // Przywracamy pierwotny stan
			   currentBox->ImageLocation = pb[row + direction][col + 1]->ImageLocation;
			   currentBox->set_piece(currentBox, pb[row + direction][col + 1]->check_piece(pb[row + direction][col + 1]));
			   currentBox->set_color(currentBox, pb[row + direction][col + 1]->check_color(pb[row + direction][col + 1]));

			   pb[row + direction][col + 1]->ImageLocation = originalImageLocation;
			   pb[row + direction][col + 1]->set_piece(pb[row + direction][col + 1], originalPiece);
			   pb[row + direction][col + 1]->set_color(pb[row + direction][col + 1], originalColor);
		   }
	   }

	   return false;
   }
   
   bool BoardForm::knight_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox)
   {
	   int row = currentBox->row;
    int col = currentBox->column;
    PieceColor pieceColor = currentBox->check_color(currentBox);

    array<Point>^ knightMoves = gcnew array<Point>
    {
        Point(-2, -1), Point(-2, 1),
        Point(-1, -2), Point(-1, 2),
        Point(1, -2), Point(1, 2),
        Point(2, -1), Point(2, 1)
    };

    for each (Point move in knightMoves)
    {
        int newRow = row + move.X;
        int newCol = col + move.Y;

        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
        {
            if (pb[newRow][newCol]->check_color(pb[newRow][newCol]) != pieceColor)
            {
                // Symulujemy ruch skoczka
                custom_picturebox^ originalBox = pb[newRow][newCol];
                Piece originalPiece = originalBox->check_piece(originalBox);
                PieceColor originalColor = originalBox->check_color(originalBox);
                String^ originalImageLocation = originalBox->ImageLocation;

                pb[newRow][newCol]->ImageLocation = currentBox->ImageLocation;
                pb[newRow][newCol]->set_piece(pb[newRow][newCol], currentBox->check_piece(currentBox));
                pb[newRow][newCol]->set_color(pb[newRow][newCol], currentBox->check_color(currentBox));

                currentBox->ImageLocation = "";
                currentBox->set_piece(currentBox, EMPTY);
                currentBox->set_color(currentBox, NONE);

                // Sprawdzamy, czy król jest nadal w szachu
                if (!king_still_checked(pb, nullptr, nullptr, nullptr))
                {
                    // Przywracamy pierwotny stan
                    currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
                    currentBox->set_piece(currentBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
                    currentBox->set_color(currentBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

                    pb[newRow][newCol]->ImageLocation = originalImageLocation;
                    pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
                    pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

                    return true; // Skoczek mo¿e zas³oniæ szacha
                }

                // Przywracamy pierwotny stan
                currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
                currentBox->set_piece(currentBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
                currentBox->set_color(currentBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

                pb[newRow][newCol]->ImageLocation = originalImageLocation;
                pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
                pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);
            }
        }
    }
    return false;
   }
   
   bool BoardForm::bishop_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox)
   {
	   int row = currentBox->row;
	   int col = currentBox->column;
	   PieceColor pieceColor = currentBox->check_color(currentBox);

	   // Sprawdzenie mo¿liwych kierunków ruchu goñca (diagonalnie)
	   array<Point>^ bishopDirections = gcnew array<Point>
	   {
		   Point(-1, -1), Point(-1, 1),
			   Point(1, -1), Point(1, 1)
	   };

	   for each (Point direction in bishopDirections)
	   {
		   int newRow = row + direction.X;
		   int newCol = col + direction.Y;

		   while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
		   {
			   if (pb[newRow][newCol]->check_color(pb[newRow][newCol]) == pieceColor)
				   break; // Stop jeœli napotkano w³asn¹ figurê

			   // Symulacja ruchu goñca
			   custom_picturebox^ originalBox = pb[newRow][newCol];
			   Piece originalPiece = originalBox->check_piece(originalBox);
			   PieceColor originalColor = originalBox->check_color(originalBox);
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[newRow][newCol]->ImageLocation = currentBox->ImageLocation;
			   pb[newRow][newCol]->set_piece(pb[newRow][newCol], currentBox->check_piece(currentBox));
			   pb[newRow][newCol]->set_color(pb[newRow][newCol], currentBox->check_color(currentBox));

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(currentBox, EMPTY);
			   currentBox->set_color(currentBox, NONE);

			   // Sprawdzenie, czy król jest nadal w szachu
			   if (!king_still_checked(pb, nullptr, nullptr, nullptr))
			   {
				   // Przywrócenie pierwotnego stanu
				   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   currentBox->set_piece(currentBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
				   currentBox->set_color(currentBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
				   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

				   return true; // Goñcze mo¿e zas³oniæ szacha
			   }

			   // Przywrócenie pierwotnego stanu
			   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
			   currentBox->set_piece(currentBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
			   currentBox->set_color(currentBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

			   pb[newRow][newCol]->ImageLocation = originalImageLocation;
			   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
			   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

			   // Przesuniêcie do kolejnego pola na przek¹tnej
			   newRow += direction.X;
			   newCol += direction.Y;
		   }
	   }

	   return false;
   }
   
   bool BoardForm::rook_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox)
   {
	   int row = currentBox->row;
	   int col = currentBox->column;
	   PieceColor pieceColor = currentBox->check_color(currentBox);

	   // Sprawdzenie mo¿liwych kierunków ruchu wie¿y (poziomo i pionowo)
	   array<Point>^ rookDirections = gcnew array<Point>
	   {
		   Point(-1, 0), Point(1, 0), // ruchy pionowe
			   Point(0, -1), Point(0, 1)  // ruchy poziome
	   };

	   for each (Point direction in rookDirections)
	   {
		   int newRow = row + direction.X;
		   int newCol = col + direction.Y;

		   while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
		   {
			   if (pb[newRow][newCol]->check_color(pb[newRow][newCol]) == pieceColor)
				   break; // Stop jeœli napotkano w³asn¹ figurê

			   // Symulacja ruchu wie¿y
			   custom_picturebox^ originalBox = pb[newRow][newCol];
			   Piece originalPiece = originalBox->check_piece(originalBox);
			   PieceColor originalColor = originalBox->check_color(originalBox);
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[newRow][newCol]->ImageLocation = currentBox->ImageLocation;
			   pb[newRow][newCol]->set_piece(pb[newRow][newCol], currentBox->check_piece(currentBox));
			   pb[newRow][newCol]->set_color(pb[newRow][newCol], currentBox->check_color(currentBox));

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(currentBox, EMPTY);
			   currentBox->set_color(currentBox, NONE);

			   // Sprawdzenie, czy król jest nadal w szachu
			   if (!king_still_checked(pb, nullptr, nullptr, nullptr))
			   {
				   // Przywracanie pierwotnego stanu
				   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   currentBox->set_piece(currentBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
				   currentBox->set_color(currentBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
				   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

				   return true; // Wie¿a mo¿e zas³oniæ szacha
			   }

			   // Przywracanie pierwotnego stanu
			   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
			   currentBox->set_piece(currentBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
			   currentBox->set_color(currentBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

			   pb[newRow][newCol]->ImageLocation = originalImageLocation;
			   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
			   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

			   // Przesuniêcie do kolejnego pola w kierunku
			   newRow += direction.X;
			   newCol += direction.Y;
		   }
	   }

	   return false;
   }
   
   bool BoardForm::queen_cansaveking(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ currentBox)
   {
	   int row = currentBox->row;
	   int col = currentBox->column;
	   PieceColor pieceColor = currentBox->check_color(currentBox);

	   // Tablica kierunków ruchu hetmana (poziomo, pionowo i po skosie)
	   array<Point>^ queenDirections = gcnew array<Point>
	   {
		   Point(-1, 0), Point(1, 0),    // ruchy pionowe
			   Point(0, -1), Point(0, 1),    // ruchy poziome
			   Point(-1, -1), Point(-1, 1),  // ruchy po skosie w górê
			   Point(1, -1), Point(1, 1)     // ruchy po skosie w dó³
	   };

	   for each (Point direction in queenDirections)
	   {
		   int newRow = row + direction.X;
		   int newCol = col + direction.Y;

		   while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
		   {
			   if (pb[newRow][newCol]->check_color(pb[newRow][newCol]) == pieceColor)
				   break; // Stop jeœli napotkano w³asn¹ figurê

			   // Symulacja ruchu hetmana
			   custom_picturebox^ originalBox = pb[newRow][newCol];
			   Piece originalPiece = originalBox->check_piece(originalBox);
			   PieceColor originalColor = originalBox->check_color(originalBox);
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[newRow][newCol]->ImageLocation = currentBox->ImageLocation;
			   pb[newRow][newCol]->set_piece(pb[newRow][newCol], currentBox->check_piece(currentBox));
			   pb[newRow][newCol]->set_color(pb[newRow][newCol], currentBox->check_color(currentBox));

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(currentBox, EMPTY);
			   currentBox->set_color(currentBox, NONE);

			   // Sprawdzenie, czy król jest nadal w szachu
			   if (!king_still_checked(pb, nullptr, nullptr, nullptr))
			   {
				   // Przywracanie pierwotnego stanu
				   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   currentBox->set_piece(currentBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
				   currentBox->set_color(currentBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
				   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

				   return true; // Hetman mo¿e zas³oniæ szacha
			   }

			   // Przywracanie pierwotnego stanu
			   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
			   currentBox->set_piece(currentBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
			   currentBox->set_color(currentBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

			   pb[newRow][newCol]->ImageLocation = originalImageLocation;
			   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
			   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

			   // Przesuniêcie do kolejnego pola w kierunku
			   newRow += direction.X;
			   newCol += direction.Y;
		   }
	   }

	   return false;
   }
   

   bool BoardForm::is_checkmate(array<array<custom_picturebox^>^>^ pb, custom_picturebox^ kingBox) {
	   int kingRow = kingBox->row;
	   int kingCol = kingBox->column;

	   array<Point>^ kingMoves = gcnew array<Point>
	   {
		   Point(-1, -1), Point(-1, 0), Point(-1, 1),
			   Point(0, -1), Point(0, 1),
			   Point(1, -1), Point(1, 0), Point(1, 1)
	   };

	   // Sprawdzenie czy król mo¿e wykonaæ jakiœ ruch
	   for each (Point move in kingMoves) {
		   int newRow = kingRow + move.X;
		   int newCol = kingCol + move.Y;

		   if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
			   if (pb[newRow][newCol]->check_color(pb[newRow][newCol]) != kingBox->check_color(kingBox)) {
				   custom_picturebox^ originalBox = pb[newRow][newCol];
				   Piece originalPiece = originalBox->check_piece(originalBox);
				   PieceColor originalColor = originalBox->check_color(originalBox);
				   String^ originalImageLocation = originalBox->ImageLocation;

				   // Przeniesienie króla na docelow¹ pozycjê
				   pb[newRow][newCol]->ImageLocation = kingBox->ImageLocation;
				   pb[newRow][newCol]->set_piece(pb[newRow][newCol], kingBox->check_piece(kingBox));
				   pb[newRow][newCol]->set_color(pb[newRow][newCol], kingBox->check_color(kingBox));

				   // Aktualizacja pozycji króla
				   kingBox->ImageLocation = "";
				   kingBox->set_piece(kingBox, EMPTY);
				   kingBox->set_color(kingBox, NONE);

				   // Sprawdzenie czy po ruchu król nadal jest w szachu
				   if (!king_still_checked(pb, pb[newRow][newCol], originalBox, nullptr)) {
					   // Przywrócenie pierwotnego stanu
					   kingBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
					   kingBox->set_piece(kingBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
					   kingBox->set_color(kingBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

					   pb[newRow][newCol]->ImageLocation = originalImageLocation;
					   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
					   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

					   return false; // Król mo¿e siê unikn¹æ szacha
				   }

				   // Przywrócenie pierwotnego stanu
				   kingBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   kingBox->set_piece(kingBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
				   kingBox->set_color(kingBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
				   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);
			   }
		   }
	   }

	   // Sprawdzenie czy król mo¿e zbic figurê przeciwnika
	   for each (Point move in kingMoves) {
		   int newRow = kingRow + move.X;
		   int newCol = kingCol + move.Y;

		   if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
			   if (pb[newRow][newCol]->check_color(pb[newRow][newCol]) == kingBox->check_color(kingBox)) {
				   continue; // Ignoruj pola z w³asnymi figurami
			   }

			   custom_picturebox^ originalBox = pb[newRow][newCol];
			   Piece originalPiece = originalBox->check_piece(originalBox);
			   PieceColor originalColor = originalBox->check_color(originalBox);
			   String^ originalImageLocation = originalBox->ImageLocation;

			   // Przeniesienie króla na docelow¹ pozycjê
			   pb[newRow][newCol]->ImageLocation = kingBox->ImageLocation;
			   pb[newRow][newCol]->set_piece(pb[newRow][newCol], kingBox->check_piece(kingBox));
			   pb[newRow][newCol]->set_color(pb[newRow][newCol], kingBox->check_color(kingBox));

			   // Aktualizacja pozycji króla
			   kingBox->ImageLocation = "";
			   kingBox->set_piece(kingBox, EMPTY);
			   kingBox->set_color(kingBox, NONE);

			   // Sprawdzenie czy po ruchu król nadal jest w szachu
			   if (!king_still_checked(pb, pb[newRow][newCol], originalBox, nullptr)) {
				   // Przywrócenie pierwotnego stanu
				   kingBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   kingBox->set_piece(kingBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
				   kingBox->set_color(kingBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
				   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);

				   return false; // Król mo¿e siê unikn¹æ szacha
			   }

			   // Przywrócenie pierwotnego stanu
			   kingBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
			   kingBox->set_piece(kingBox, pb[newRow][newCol]->check_piece(pb[newRow][newCol]));
			   kingBox->set_color(kingBox, pb[newRow][newCol]->check_color(pb[newRow][newCol]));

			   pb[newRow][newCol]->ImageLocation = originalImageLocation;
			   pb[newRow][newCol]->set_piece(pb[newRow][newCol], originalPiece);
			   pb[newRow][newCol]->set_color(pb[newRow][newCol], originalColor);
		   }
	   }


	   // Check if any piece can block the check or capture the threatening piece
	   for (int row = 0; row < 8; row++) {
		   for (int col = 0; col < 8; col++) {
			   custom_picturebox^ currentBox = pb[row][col];

			   if (currentBox->check_color(currentBox) == kingBox->check_color(kingBox)) {
				   switch (currentBox->check_piece(currentBox)) {
				   case PAWN:
					   if (pawn_cansaveking(pb, currentBox))
						   return false;
					   break;
				   case KNIGHT:
					   if (knight_cansaveking(pb, currentBox))
						   return false;
					   break;
				   case BISHOP:
					   if (bishop_cansaveking(pb, currentBox))
						   return false;
					   break;
				   case ROOK:
					   if (rook_cansaveking(pb, currentBox))
						   return false;
					   break;
				   case QUEEN:
					   if (queen_cansaveking(pb, currentBox))
						   return false;
					   break;
				   default:
					   continue;
				   }
			   }
		   }
	   }

	   return true;  // Brak mo¿liwoœci unikniêcia szacha - szachmat
   }



};


