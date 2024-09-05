#include "BoardForm.h"


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
		pictureBoxInstance->InitializeBoard();
		pictureBoxes = pictureBoxInstance->GetPictureBoxes(); 

		for (int row = 2; row < 6; ++row) {
			for (int col = 0; col < 8; ++col) {
				// Upewnij siê, ¿e pictureBoxes[row][col] to ChessPiece
				ChessPiece^ pieceBox = dynamic_cast<ChessPiece^>(pictureBoxes[row][col]);
				if (pieceBox != nullptr) {
					this->grid_panel->Controls->Add(pieceBox);
					pieceBox->ImageLocation = "";
					pieceBox->Enabled = true;
					pieceBox->set_color(PieceColor::NONE);
					pieceBox->set_piece(Piece::EMPTY);
				}
			}
		}

	
		for (int col = 0; col < 8; ++col) {
		
			this->grid_panel->Controls->Add(pictureBoxes[6][col]);
			if(!boardFlipped)pictureBoxes[6][col]->set_color(WHITE);
			else
			{
				pictureBoxes[6][col]->set_color(BLACK);
			}
			pictureBoxes[6][col]->set_piece(PAWN);

			this->grid_panel->Controls->Add(pictureBoxes[7][col]);
			switch (col) {
			case 0:
			case 7:
				pictureBoxes[7][col]->set_piece(ROOK);
				break;
			case 1:
			case 6:
				pictureBoxes[7][col]->set_piece(KNIGHT);
				break;
			case 2:
			case 5:
				pictureBoxes[7][col]->set_piece(BISHOP);
				break;
			case 3:
				pictureBoxes[7][col]->set_piece(QUEEN);
				break;
			case 4:
				pictureBoxes[7][col]->set_piece(KING);
				if(!boardFlipped)white_king = pictureBoxes[7][col];
				else
				{
					black_king = pictureBoxes[7][col];
				}
				break;
			}
			if(!boardFlipped)pictureBoxes[7][col]->set_color(WHITE);
			else
			{
				pictureBoxes[7][col]->set_color(BLACK);
			}
		}

		
		for (int col = 0; col < 8; ++col) {
		
			this->grid_panel->Controls->Add(pictureBoxes[0][col]);
			switch (col) {
			case 0:
			case 7:
				pictureBoxes[0][col]->set_piece(ROOK);
				break;
			case 1:
			case 6:
				pictureBoxes[0][col]->set_piece(KNIGHT);
				break;
			case 2:
			case 5:
				pictureBoxes[0][col]->set_piece(BISHOP);
				break;
			case 3:
				pictureBoxes[0][col]->set_piece(QUEEN);
				break;
			case 4:
				pictureBoxes[0][col]->set_piece(KING);
				if(!boardFlipped)black_king = pictureBoxes[0][col];
				else
				{
					white_king = pictureBoxes[0][col];
				}
				break;
			}
			if(!boardFlipped)pictureBoxes[0][col]->set_color(BLACK);
			else
			{
				pictureBoxes[0][col]->set_color(WHITE);
			}

			this->grid_panel->Controls->Add(pictureBoxes[1][col]);
			if(!boardFlipped)pictureBoxes[1][col]->set_color(BLACK);
			else
			{
				pictureBoxes[1][col]->set_color(WHITE);
			}
			pictureBoxes[1][col]->set_piece(PAWN);
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
        //picture box bg
		this->picturebox_bg->Location = System::Drawing::Point(0, 0);
		this->picturebox_bg->Size = System::Drawing::Size(460, 460);
		this->picturebox_bg->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg";
		this->picturebox_bg->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
		this->picturebox_bg->Dock = System::Windows::Forms::DockStyle::Fill;
		this->picturebox_bg->SendToBack();
		this->picturebox_bg->TabIndex = 6;
		this->picturebox_bg->TabStop = false;
		// 
		// grid_panel
		// 
		this->grid_panel->Location = System::Drawing::Point(121, 5);
		this->grid_panel->Name = L"grid_panel";
		this->grid_panel->Size = System::Drawing::Size(460, 460);
		this->grid_panel->Controls->Add(picturebox_bg);
		this->grid_panel->Controls->Add(promote_panel);
		this->grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg");
		if(boardFlipped)grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\flipedboard1");
		this->grid_panel->TabIndex = 47;
		this->grid_panel->Visible = true;
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


		this->grid_panel->Controls->Clear();
		grid_panel->BackgroundImage = nullptr;

		whiteonMove = true;

		white_king = nullptr;
		black_king = nullptr;

		white_king_on_checked = false;
		black_king_on_checked = false;

		black_king_moved = false;
		white_king_moved = false;

		boardFlipped = !boardFlipped;

		if (!boardFlipped)
		{
			Application::Restart();
		}

		if (boardFlipped) {
			pictureBoxInstance->FlipBoard();
			grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\flipedboard1.jpg");
		}
		else {
			pictureBoxInstance->InitializeBoard(); 
			grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg");
		}
		promote_panel->BackColor = System::Drawing::Color::Black;
		promote_panel->Location = System::Drawing::Point(20, 20);

		this->pictureBoxes = pictureBoxInstance->GetPictureBoxes();

			array<array<ChessPiece^>^>^ flippedPictureBoxes = gcnew array<array<ChessPiece^>^>(8);
			for (int i = 0; i < 8; i++) {
				flippedPictureBoxes[i] = gcnew array<ChessPiece^>(8);
				for (int j = 0; j < 8; j++) {
					flippedPictureBoxes[i][j] = pictureBoxes[7 - i][7 - j];
				}
			}
			this->pictureBoxes = flippedPictureBoxes;

		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 8; j++) {
				this->grid_panel->Controls->Add(pictureBoxes[i][j]);
				pictureBoxes[i][j]->ImageLocation = "";
				pictureBoxes[i][j]->Enabled = true;
				pictureBoxes[i][j]->set_color(NONE);
				pictureBoxes[i][j]->set_piece(EMPTY);
			}
		}

		for (int i = 0; i < 8; i++) {
			pictureBoxes[1][i]->set_piece(PAWN);
			pictureBoxes[1][i]->set_color(WHITE);
			pictureBoxes[1][i]->BringToFront();
			grid_panel->Controls->Add(pictureBoxes[1][i]);
		}

		for (int i = 0; i < 8; i++) {
			pictureBoxes[6][i]->set_piece(PAWN);
			pictureBoxes[6][i]->set_color(BLACK);
		
			pictureBoxes[6][i]->BringToFront();
			grid_panel->Controls->Add(pictureBoxes[6][i]);
		}

		for (int i = 0; i < 8; i++) {
			switch (i) {
			case 0:
			case 7:
				pictureBoxes[7][i]->set_piece(ROOK);
				break;
			case 1:
			case 6:
				pictureBoxes[7][i]->set_piece(KNIGHT);
				break;
			case 2:
			case 5:
				pictureBoxes[7][i]->set_piece(BISHOP);
				break;
			case 4:
				pictureBoxes[7][i]->set_piece(QUEEN);
				break;
			case 3:
				
					flipped_black_kingbox = pictureBoxes[7][i];
					flipped_black_kingbox->row = 7;
					flipped_black_kingbox->column = 3;
					black_king = flipped_black_kingbox;
			
				pictureBoxes[7][i]->set_piece(KING);
				break;
			}
			pictureBoxes[7][i]->set_color(BLACK);
			pictureBoxes[7][1]->BringToFront();
			grid_panel->Controls->Add(pictureBoxes[7][i]);
		}

		for (int i = 0; i < 8; i++) {
			switch (i) {
			case 0:
			case 7:
				pictureBoxes[0][i]->set_piece(ROOK);
				break;
			case 1:
			case 6:
				pictureBoxes[0][i]->set_piece(KNIGHT);
				break;
			case 2:
			case 5:
				pictureBoxes[0][i]->set_piece(BISHOP);
				break;
			case 4:
				pictureBoxes[0][i]->set_piece(QUEEN);
				break;
			case 3:
				flipped_white_kingbox = pictureBoxes[0][i];
				flipped_white_kingbox->row = 0;
				flipped_white_kingbox->column = 3;
			
				pictureBoxes[0][i]->set_piece(KING);
				break;
			}
			pictureBoxes[0][i]->set_color(WHITE);
		
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
				pictureBoxes[i][j]->MouseDown += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseDown);
				pictureBoxes[i][j]->MouseMove += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseMove);
				pictureBoxes[i][j]->MouseUp += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseUp);
				pictureBoxes[i][j]->MouseClick += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseClick);
				grid_panel->Controls->Add(pictureBoxes[i][j]);
				pictureBoxes[i][j]->BringToFront();
			}
		}
		this->Refresh();
	}
}
	   //open panel with time
void BoardForm::setTimeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	timeset_panel->Visible = true;
	timeset_panel->Enabled = true;
}
	   int seconds, seconds_white;
	   int increment;
	   bool on_move = true;

	   void BoardForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	timeset_panel->Visible = false;
	if (time_options_box->Text == "Real time")
	{
		menu_timer_black->Enabled = true;
		label_blacktime->Visible = true;
		time_black->Visible = true;
		//white
		menu_timer_white->Enabled = true;
		label_whitetime->Visible = true;
		time_white->Visible = true;

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
		seconds_white = seconds;
		increment = trackbar_secincrement->Value;
		timer_set = true;
		show = false;
	}
	else
	{
		menu_timer_black->Enabled = false;
		label_blacktime->Visible = false;
		time_black->Visible = false;
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
	   void BoardForm::player_turn(bool onMove, array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected)
	   {
		   reset_highlight_moves();

		   for (int i = 0; i < 8; i++)
		   {
			   for (int j = 0; j < 8; j++)
			   {
				   if (pictureBoxes[i][j] != nullptr)
				   {
					   if (onMove && pictureBoxes[i][j]->check_color() == WHITE)
					   {
						   pictureBoxes[i][j]->Enabled = true;
					   }
					   else if (!onMove && pictureBoxes[i][j]->check_color() == BLACK)
					   {
						   pictureBoxes[i][j]->Enabled = true;
					   }
					   else
					   {
						   pictureBoxes[i][j]->Enabled = false;
					   }
				   }
			   }
		   }
		   if (timer_set)
		   {
			   if (onMove)
			   {
				   menu_timer_black->Start();
				   menu_timer_white->Stop();
			   }
			   else
			   {
				   menu_timer_white->Start();
				   menu_timer_black->Stop();
			   }
		   }
	   }
	   void BoardForm::player_turnClick()
	   {
		   if (timer_set)
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
	   void BoardForm::HandlePieceSelection(ChessPiece^ selectedPictureBox)
	   {
		   if (selectedPictureBox->ImageLocation != "")
		   {
			   if (selectedPictureBox != nullptr && promote_panel->Visible == false)
			   {
				   piece_clicked = true;
				   selectedPictureBox->Capture = true;
				   selectedPictureBox->BringToFront();
				   new_selected = selectedPictureBox;
				   current_piece = selectedPictureBox->check_piece();
				   current_color = selectedPictureBox->check_color();
				   start_location = selectedPictureBox->Location;
				   file_path = selectedPictureBox->ImageLocation;
				   selectedPictureBox->Tag = "Dragging";
			   }
		   }
	   }

	   void BoardForm::HandlePieceUp(ChessPiece^ selectedPictureBox, ChessPiece^ targetPictureBox)
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


		targetPictureBox = dynamic_cast<ChessPiece^>(controlUnderCursor);
		  

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

		   pieceType_selected = selectedPictureBox->check_piece();
		   pieceColor_selected = selectedPictureBox->check_color();
		   imgLocation_selected = selectedPictureBox->ImageLocation;
		   startLocation_selected = start_location;

		   pieceType_target = targetPictureBox->check_piece();
		   pieceColor_target = targetPictureBox->check_color();
		   imgLocation_target = targetPictureBox->ImageLocation;

		   if (!castle_move)
		   {
			   if (targetPictureBox != nullptr && targetPictureBox != selectedPictureBox && selectedPictureBox != nullptr)
			   {
				   if (!BoardForm::change_pb(selectedPictureBox, targetPictureBox))
				   {
					   selectedPictureBox->set_piece(pieceType_selected);
					   selectedPictureBox->set_color(pieceColor_selected);
					   selectedPictureBox->ImageLocation = imgLocation_selected;
					   selectedPictureBox->Location = start_location;

					   targetPictureBox->set_piece(pieceType_target);
					   targetPictureBox->set_color(pieceColor_target);
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
				   selectedPictureBox->set_color(pieceColor_selected);
				   selectedPictureBox->set_piece(pieceType_selected);

				   targetPictureBox->ImageLocation = imgLocation_target;
				   targetPictureBox->set_color(pieceColor_target);
				   targetPictureBox->set_piece(pieceType_target);
				   whiteonMove = !whiteonMove;
			   }
		   }

		   ChessPiece^ whiteKingBox = nullptr;
		   ChessPiece^ blackKingBox = nullptr;

		   for (int i = 0; i < 8; i++)
		   {
			   for (int j = 0; j < 8; j++)
			   {
				   if (pictureBoxes[i][j]->check_piece() == KING)
				   {
					   if (pictureBoxes[i][j]->check_color() == WHITE)
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

		   if (king_checked(pictureBoxes, selectedPictureBox) || white_king_on_checked || black_king_on_checked)
		   {
			   if ((whiteonMove && black_king_on_checked) || (!whiteonMove && white_king_on_checked))
			   {
				   selectedPictureBox->ImageLocation = imgLocation_selected;
				   selectedPictureBox->set_color(pieceColor_selected);
				   selectedPictureBox->set_piece(pieceType_selected);

				   targetPictureBox->ImageLocation = imgLocation_target;
				   targetPictureBox->set_color(pieceColor_target);
				   targetPictureBox->set_piece(pieceType_target);

				   if(white_king_on_checked)whiteKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.png";

				   else if(black_king_on_checked)blackKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";

				   whiteonMove = !whiteonMove;
				   return;
			   }
			   else
			   {
				   if ((!whiteonMove && is_checkmate(pictureBoxes, blackKingBox)) || (whiteonMove && is_checkmate(pictureBoxes, whiteKingBox)))
				   {
					   MessageBox::Show("Checkmate!", "Game Over");
					   grid_panel->Enabled = false;

					   return;
				   }
			   }
		   }

		   game_started = true;
	   }

    void BoardForm::grid_panel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			ChessPiece^ selectedPiece = dynamic_cast<ChessPiece^>(sender);
			if (selectedPiece != nullptr)
			{
				HandlePieceSelection(selectedPiece);
			}
		}
   }
	void BoardForm::grid_panel_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		if (e->Button == System::Windows::Forms::MouseButtons::Left && selectedPictureBox != nullptr && selectedPictureBox->Tag->ToString() == "Dragging") {
			PieceColor current_collor = selectedPictureBox->check_color();
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
	bool BoardForm::change_pb(ChessPiece^ selected_pb, ChessPiece^ target_pb)
	{
		reset_highlight_moves();

		Piece chosen_piece_selected = selected_pb->check_piece();
		Piece chosen_piece_target = target_pb->check_piece();

		PieceColor color_selected = selected_pb->check_color();
		PieceColor color_target = target_pb->check_color();

		String^ img_location_selected = selected_pb->ImageLocation;
		String^ img_location_target = target_pb->ImageLocation;

		Point start_location_selected = selected_pb->Location;
		Point start_location_target = target_pb->Location;

		target_pb->ImageLocation = img_location_selected;
		target_pb->set_color(color_selected);
		target_pb->set_piece(chosen_piece_selected);
		target_pb->BackColor = System::Drawing::Color::Transparent;

		selected_pb->ImageLocation = "";
		selected_pb->set_color(NONE);
		selected_pb->set_piece(EMPTY);
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
				if (pictureBoxes[i][j]->check_color() == GREEN)
				{
					pictureBoxes[i][j]->set_color(color_before);
					color_before = NONE;
				}
			}
		}
	
		if (target_pb->check_piece() == chosen_piece_selected || selected_pb->check_piece() == NONE)
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

	bool BoardForm::king_still_checked(array<array<ChessPiece^>^>^ pb, ChessPiece^ selected, ChessPiece^ target, ChessPiece^ last_moved)
	{
		ChessPiece^ whiteKingBox = nullptr;
		ChessPiece^ blackKingBox = nullptr;
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

				if (pb[actualRow][actualCol]->check_piece() == KING) {
					if (pb[actualRow][actualCol]->check_color() == WHITE) {
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
		if (whiteKingBox != nullptr) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					int actualRow = i;
					int actualCol = j;
					if (boardFlipped) {
						actualRow = 7 - i;
						actualCol = 7 - j;
					}
					if (pb[actualRow][actualCol]->check_color() == BLACK) {
						if (is_king_under_attack(pb[actualRow][actualCol], whiteKingRow, whiteKingCol)) {
							return true;
						}
					}
				}
			}
		}
		if (blackKingBox != nullptr) {
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					int actualRow = i;
					int actualCol = j;
					if (boardFlipped) {
						actualRow = 7 - i;
						actualCol = 7 - j;
					}
					if (pb[actualRow][actualCol]->check_color() == WHITE) {
						if (is_king_under_attack(pb[actualRow][actualCol], blackKingRow, blackKingCol)) {
							reset_highlight_moves();
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	//check pawn
	bool BoardForm::check_Pawnmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb)
	{
		Point startPos = start_location;
		Point targetPos = selected_pb->Location;

		int dx = abs(targetPos.X - startPos.X) / selected_pb->Width;
		int dy = abs(targetPos.Y - startPos.Y) / selected_pb->Height;

		int direction = (targetPos.Y - startPos.Y) / selected_pb->Height;

		int startRow = startPos.Y / selected_pb->Height;
		int startCol = startPos.X / selected_pb->Width;
		int targetRow = targetPos.Y / selected_pb->Height;
		int targetCol = targetPos.X / selected_pb->Width;

		startRow = Math::Min(startRow, 7);
		startCol = Math::Min(startCol, 7);
		targetRow = Math::Min(targetRow, 7);
		targetCol = Math::Min(targetCol, 7);

		ChessPiece^ intermediate_pb = nullptr;
		ChessPiece^ target_pb = nullptr;

		if (selected_pb->check_color() == BLACK && targetRow < startRow && !boardFlipped) {
			passantable = nullptr;
			return false;
		}

		if (selected_pb->check_color() == WHITE && targetRow > startRow && !boardFlipped) {
			passantable = nullptr;
			return false;
		}

		if (boardFlipped)
		{
			if (selected_pb->check_color() == WHITE && targetRow < startRow)
			{
				passantable = nullptr;
				return false;
			}
			if (selected_pb->check_color() == BLACK && targetRow > startRow)
			{
				passantable = nullptr;
				return false;
			}
		}

		if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8 ||
			targetRow < 0 || targetRow >= 8 || targetCol < 0 || targetCol >= 8) {
			return true;
		}

		if (dx == 0 && dy == 1) {
			target_pb = pictureBoxes[targetRow][targetCol];
			if (target_pb->check_piece() == EMPTY) {
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

		else if (dx == 0 && dy == 2 && (startRow == 1 || startRow == 6)) {
			intermediate_pb = pictureBoxes[startRow + direction][startCol];
			target_pb = pictureBoxes[targetRow][targetCol];
			if (intermediate_pb->check_piece() == EMPTY && target_pb->check_piece() == EMPTY) {
				passantable = pictureBoxes[targetRow][targetCol];
				return true;
			}
		}

		else if (dx == 1 && dy == 1) {
			target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color();
			Piece check_piece = target_pb->check_piece();

			if (check_targetpb != EMPTY && selected_pb->check_color() != check_targetpb && check_piece != KING) {
				if (targetRow == 7 || targetRow == 0)
				{
					promote_panel->Visible = true;
					promote_panel->Enabled = true;
					promote_panel->BringToFront();
				}
				passantable = nullptr;
				return true;
			}

			// en passant capture
			else if (check_targetpb == EMPTY) {
				int enPassantRow = 0;
				if (boardFlipped) {
					enPassantRow = selected_pb->check_color() == WHITE ? targetRow - 1 : targetRow + 1;
				}
				else {
					enPassantRow = selected_pb->check_color() == WHITE ? targetRow + 1 : targetRow - 1;
				}

				ChessPiece^ enPassant_pb = pictureBoxes[enPassantRow][targetCol];
				if (enPassant_pb->check_piece() == PAWN && enPassant_pb->check_color() != selected_pb->check_color() && passantable == enPassant_pb) {
					enPassant_pb->ImageLocation = ""; 
					enPassant_pb->set_color(NONE); 
					enPassant_pb->set_piece(EMPTY);
					return true;
				}
			}
		}
		bool king_safe_place = king_still_checked(pictureBoxes, selected_pb, target_pb, last_moved_piece);
		if (!king_safe_place) {
			return false;
		}

		return false;
	}

	bool BoardForm::check_sent(ChessPiece^ selected_pb)
	{
		int x = selected_pb->Location.X;
		int y = selected_pb->Location.Y;

		int pbWidth = selected_pb->Width;
		int pbHeight = selected_pb->Height;
		int panelWidth = 460;
		int panelHeight = 460;
		int cellSize = 50;


		if (x >= 0 && x + pbWidth <= panelWidth && y >= 0 && y + pbHeight <= panelHeight) {
			bool notOnEdgeX = (x % cellSize) != 0 && ((x + pbWidth) % cellSize) != 0;
			bool notOnEdgeY = (y % cellSize) != 0 && ((y + pbHeight) % cellSize) != 0;

			if (notOnEdgeX && notOnEdgeY) {
				return true;
			}
		}

		return false;
	}
	//check knight
	bool BoardForm::check_Knightmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb)
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

		if (boardFlipped) {
			startRow = 7 - startRow;
			startCol = 7 - startCol;
			targetRow = 7 - targetRow;
			targetCol = 7 - targetCol;
		}

		if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
			ChessPiece^ target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color();
			Piece target_piece = target_pb->check_piece();

			if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color() && target_piece != KING)) {
				return true;
			}
			else {
				return false;
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pictureBoxes[i][j]->BringToFront();
			}
		}

		return false;
	}
	bool BoardForm::check_Bishopmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb)
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
				ChessPiece^ current_pb = pictureBoxes[currentRow][currentCol];

				if (current_pb->check_piece() != EMPTY) {
					return false;
				}
			}

			ChessPiece^ target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color();
			Piece target_piece = target_pb->check_piece();

			if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color() && target_piece != KING)) {
				return true;
			}
			else {
				return false;
			}
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pictureBoxes[i][j]->BringToFront();
			}
		}
		return false;
	}
	//check rook
	bool BoardForm::check_Rookmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb)
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
				ChessPiece^ current_pb = pictureBoxes[currentRow][currentCol];

				if (current_pb->check_piece() != EMPTY) {
					return false;
				}
			}

			ChessPiece^ target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color();
			Piece target_piece = target_pb->check_piece();

			if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color() && target_piece != KING)) {

				if (selected_pb->check_color() == WHITE)
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

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pictureBoxes[i][j]->BringToFront();
			}
		}
		return false;
	}
	//check queen
	bool BoardForm::check_Queenmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb)
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
				ChessPiece^ current_pb = pictureBoxes[currentRow][currentCol];

				if (current_pb->check_piece() != EMPTY) {
					return false;
				}
			}
		}

		else if (dx == dy) {
			int stepX = (targetCol - startCol) / dx;
			int stepY = (targetRow - startRow) / dy;

			for (int i = 1; i < dx; ++i) {
				int currentRow = startRow + i * stepY;
				int currentCol = startCol + i * stepX;
				ChessPiece^ current_pb = pictureBoxes[currentRow][currentCol];

				if (current_pb->check_piece() != EMPTY) {
					return false;
				}
			}
		}
		else {
			return false;
		}

		ChessPiece^ target_pb = pictureBoxes[targetRow][targetCol];
		PieceColor check_targetpb = target_pb->check_color();
		Piece target_piece = target_pb->check_piece();

		if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color() && target_piece != KING)) {
			return true;
		}
		else {
			return false;
		}
	}
	//check king
	bool BoardForm::check_Kingmove(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_pb)
	{
		reset_highlight_moves();

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
			ChessPiece^ target_pb = pictureBoxes[targetRow][targetCol];
			PieceColor check_targetpb = target_pb->check_color();
			Piece target_piece = target_pb->check_piece();

			if (target_piece == EMPTY || (check_targetpb != selected_pb->check_color() && target_piece != KING)) {
				ChessPiece^ previous_pb = pictureBoxes[startRow][startCol];
				pictureBoxes[targetRow][targetCol] = selected_pb;
				pictureBoxes[startRow][startCol] = gcnew ChessPiece();

				if (king_checked(pictureBoxes, selected_pb)) {
					pictureBoxes[startRow][startCol] = previous_pb;
					pictureBoxes[targetRow][targetCol] = target_pb; 

					if (selected_pb->check_color() == WHITE) {
						selected_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.png";
					}
					else if (selected_pb->check_color() == BLACK) {
						selected_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";
					}

					return false;
				}
				PieceColor king_piece = selected_pb->check_color();
				if (king_piece == WHITE) {
					white_king_moved = true;
					selected_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king.png";
				}
				else if (king_piece == BLACK) {
					black_king_moved = true;
					selected_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";
				}
				return true;
			}
		}

		// castle
		if (dy == 0 && dx == 2 && targetCol > startCol) {
			ChessPiece^ rook_pb = pictureBoxes[startRow][7];
			Piece rook_piece = rook_pb->check_piece();
			if (rook_piece == ROOK && rook_pb->check_color() == selected_pb->check_color())
			{
				bool pathClear = true;
				for (int i = startCol + 1; i < 7; i++) {
					if (pictureBoxes[startRow][i]->check_piece() != EMPTY) {
						pathClear = false;
						break;
					}
				}
				if (pathClear) {
					if (selected_pb->check_color() == WHITE && !white_king_moved && !white_kingside_rook_moved) {
						castle(selected_pb, pictureBoxes[startRow][startCol + 2], rook_pb, pictureBoxes[startRow][startCol + 1]);
					}
					else if (selected_pb->check_color() == BLACK && !black_king_moved && !black_kingside_rook_moved) {
						castle(selected_pb, pictureBoxes[startRow][startCol + 2], rook_pb, pictureBoxes[startRow][startCol + 1]);
					}
					else {
						return false;
					}
				}
			}
		}

		if (dy == 0 && (dx == 3 || dx == 4) && targetCol < startCol) {
			ChessPiece^ Qside_rook = pictureBoxes[startRow][0];
			Piece rook_piece2 = Qside_rook->check_piece();

			if (rook_piece2 == ROOK && Qside_rook->check_color() == selected_pb->check_color()) {
				bool pathClear = true;
				for (int i = startCol - 1; i > 0; i--) {
					if (pictureBoxes[startRow][i]->check_piece() != EMPTY) {
						pathClear = false;
						break;
					}
				}
				if (pathClear) {
					if (selected_pb->check_color() == WHITE && !white_king_moved && !white_queenside_rook_moved) {
						castle(selected_pb, pictureBoxes[startRow][startCol - 2], Qside_rook, pictureBoxes[startRow][startCol - 1]);
					}
					else if (selected_pb->check_color() == BLACK && !black_king_moved && !black_queenside_rook_moved) {
						castle(selected_pb, pictureBoxes[startRow][startCol - 2], Qside_rook, pictureBoxes[startRow][startCol - 1]);
					}
					else {
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
	
	void BoardForm::castle(ChessPiece^ king, ChessPiece^ king_dest, ChessPiece^ rook, ChessPiece^ rook_dest)
	{
		if (!white_king_on_checked || !black_king_on_checked)
		{
				Point start_king = king->Location;
				Point start_rook = rook->Location;

				String^ king_filepath = king->ImageLocation;
				PieceColor king_piececolor = king->check_color();
				Piece king_piece = king->check_piece();

				String^ rook_filepath = rook->ImageLocation;
				PieceColor rook_piececolor = rook->check_color();
				Piece rook_piece = rook->check_piece();

				rook_dest->ImageLocation = rook_filepath;
				rook_dest->set_color(rook_piececolor);
				rook_dest->set_piece(rook_piece);

				king_dest->ImageLocation = king_filepath;
				king_dest->set_color(king_piececolor);
				king_dest->set_piece(king_piece);


				king->ImageLocation = "";
				king->set_color(NONE);
				king->set_piece(EMPTY);

				rook->ImageLocation = "";
				rook->set_color(NONE);
				rook->set_piece(EMPTY);

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
			selectedPictureBox = dynamic_cast<ChessPiece^>(sender);

			if (selectedPictureBox != nullptr && selectedPictureBox->Enabled == true)
			{
				current_color = selectedPictureBox->check_color();

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
							selectedPictureBox->BackColor = System::Drawing::Color::ForestGreen;
						break;
					case KNIGHT:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_KNIGHT(selectedPictureBox);
						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::ForestGreen;
						break;
					case BISHOP:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_BISHOP(selectedPictureBox);
						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::ForestGreen;
						break;
					case ROOK:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_ROOK(selectedPictureBox);

						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::ForestGreen;
						break;
					case QUEEN:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_QUEEN(selectedPictureBox);

						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::ForestGreen;
						break;
					case KING:
						chosen_piece = selectedPictureBox;
						highlight_possible_moves_KING(selectedPictureBox);

						if (selectedPictureBox->ImageLocation != "")
							selectedPictureBox->BackColor = System::Drawing::Color::ForestGreen;
						break;
					case EMPTY:
						break;
					default:
						MessageBox::Show("Incorrect pieces.");
						break;
					}
				}
				else 
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
				chosen_piece->BackColor = System::Drawing::Color::Transparent;  
				chosen_piece = nullptr;  
			}
			return;
		}
	}
   void BoardForm::highlight_possible_moves_PAWM(ChessPiece^ selected_pb) {
	   reset_highlight_moves();

	   if (selected_pb->ImageLocation != "") {
		   int startRow = -1;
		   int startCol = -1;

		   Point startPos = selected_pb->Location;
		   startRow = startPos.Y / selected_pb->Height;
		   startCol = startPos.X / selected_pb->Width;
		   int direction = selected_pb->check_color() == WHITE ? -1 : 1;

		   if(boardFlipped)direction = selected_pb->check_color() == WHITE ? 1 : -1;

		   PieceColor start_color = selected_pb->check_color();
		   Piece start_piece = selected_pb->check_piece();

		   startRow = Math::Min(startRow, 7);
		   startCol = Math::Min(startCol, 7);

		   if (startRow < 0 || startRow >= 8 || startCol < 0 || startCol >= 8) {
			   return;
		   }

		   int targetRow = startRow + direction;
		   targetRow = Math::Min(targetRow, 7);

		   if (targetRow >= 0 && targetRow < 8) {
			   if (pictureBoxes[targetRow][startCol]->check_piece() == EMPTY) {
				   if (pictureBoxes[targetRow][startCol]->ImageLocation == "" && pictureBoxes[startRow][startCol] != nullptr) {
					   pictureBoxes[targetRow][startCol]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
				   }
				   selected_pb->set_piece(start_piece);
				   selected_pb->set_color(start_color);
			   }
		   }

		   if ((startRow == 1 && direction == 1) || (startRow == 6 && direction == -1)) {
			   targetRow = startRow + 2 * direction;
			   if (targetRow >= 0 && targetRow < 8) {
				   if (pictureBoxes[startRow + direction][startCol]->check_piece() == EMPTY &&
					   pictureBoxes[targetRow][startCol]->check_piece() == EMPTY) {
					   if (pictureBoxes[targetRow][startCol]->ImageLocation == "" && pictureBoxes[startRow][startCol] != nullptr) {
						   pictureBoxes[targetRow][startCol]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
					   }
					   selected_pb->set_piece(start_piece);
					   selected_pb->set_color(start_color);
				   }
			   }
		   }

		   int cols[2] = { startCol - 1, startCol + 1 };
		   for (int i = 0; i < 2; i++) {
			   if (cols[i] >= 0 && cols[i] < 8) {
				   targetRow = startRow + direction;
				   if (targetRow >= 0 && targetRow < 8) {
					   target_pb = pictureBoxes[targetRow][cols[i]];
					   enPassant_pb = pictureBoxes[startRow][cols[i]];

					   if (target_pb->check_piece() != EMPTY &&
						   target_pb->check_color() != selected_pb->check_color()) {
						   color_before = target_pb->check_color();
						   target_pb->BackgroundImage = Image::FromFile("C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\BG.png");
						   target_pb->BackgroundImageLayout = ImageLayout::Stretch;
						   target_pb->set_color(GREEN);
					   }

					   else if (target_pb->check_piece() == EMPTY &&
						   enPassant_pb->check_piece() == PAWN &&
						   enPassant_pb->check_color() != selected_pb->check_color() &&
						   enPassant_pb == passantable) {

						   target_pb->onMoveIMG = true;
						   if (target_pb->ImageLocation == "" && enPassant_pb != nullptr) {
							   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
						   }

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
   void BoardForm::highlight_possible_moves_KNIGHT(ChessPiece^ selected_pb)
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
			   ChessPiece^ target_pb = pictureBoxes[targetRow][targetCol];

			   if (target_pb->check_piece() == EMPTY || target_pb->check_color() != selected_pb->check_color())
			   {
				   if (target_pb->ImageLocation == "")
				   {
					   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; 
				   }
				   else
				   {
					   target_pb->BackgroundImage = Image::FromFile("C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\BG.png");
					   target_pb->BackgroundImageLayout = ImageLayout::Stretch;
				   }
			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_BISHOP(ChessPiece^ selected_pb)
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

	   PieceColor bishopColor = selected_pb->check_color();

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

			   ChessPiece^ target_pb = pictureBoxes[row][col];

			   if (target_pb->check_piece() == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }
			   else if (target_pb->check_color() != bishopColor) {
				   target_pb->BackgroundImage = Image::FromFile("C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\BG.png");
				   target_pb->BackgroundImageLayout = ImageLayout::Stretch;
				   break;
			   }
			   else {
				   break;
			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_ROOK(ChessPiece^ selected_pb)
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

	   PieceColor rookColor = selected_pb->check_color();

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

			   ChessPiece^ target_pb = pictureBoxes[row][col];

			   if (target_pb->check_piece() == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }

			   else if (target_pb->check_color() != rookColor) {
				   target_pb->BackgroundImage = Image::FromFile("C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\BG.png");
				   target_pb->BackgroundImageLayout = ImageLayout::Stretch;
				   break;
			   }
			   else {
				   break;
			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_QUEEN(ChessPiece^ selected_pb)
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

	   PieceColor queenColor = selected_pb->check_color();

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

			   ChessPiece^ target_pb = pictureBoxes[row][col];

			   if (target_pb->check_piece() == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }

			   else if (target_pb->check_color() != queenColor) {
				   target_pb->BackgroundImage = Image::FromFile("C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\BG.png");
				   target_pb->BackgroundImageLayout = ImageLayout::Stretch;
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

			   ChessPiece^ target_pb = pictureBoxes[row][col];

			   if (target_pb->check_piece() == EMPTY) {
				   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
			   }

			   else if (target_pb->check_color() != queenColor) {
				   target_pb->BackgroundImage = Image::FromFile("C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\BG.png");
				   target_pb->BackgroundImageLayout = ImageLayout::Stretch;
				   break;
			   }

			   else {
				   break;
			   }
		   }
	   }
   }

   void BoardForm::highlight_possible_moves_KING(ChessPiece^ selected_pb)
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

	   PieceColor kingColor = selected_pb->check_color();

	   int kingDirections[8][2] = {
		   {-1, -1}, {-1,  0}, {-1,  1},
		   { 0, -1},          { 0,  1},
		   { 1, -1}, { 1,  0}, { 1,  1}
	   };

	   for (int d = 0; d < 8; ++d) {
		   int row = startRow + kingDirections[d][0];
		   int col = startCol + kingDirections[d][1];


		   if (row >= 0 && row < 8 && col >= 0 && col < 8) {
			   ChessPiece^ target_pb = pictureBoxes[row][col];

			   if (!is_square_under_attack(row, col, kingColor)) {
				   if (target_pb->check_piece() == EMPTY) {
					   target_pb->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
				   }
				   else if (target_pb->check_color() != kingColor) {
					   target_pb->BackgroundImage = Image::FromFile("C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\BG.png");
					   target_pb->BackgroundImageLayout = ImageLayout::Stretch;
				   }
			   }
		   }
	   }

	   if (kingColor == WHITE && !white_king_moved && !white_king_on_checked) {
		   ChessPiece^ kingsideRook = pictureBoxes[startRow][7];
		   if (kingsideRook->check_piece() == ROOK &&
			   kingsideRook->check_color() == WHITE &&
			   !white_kingside_rook_moved) {

			   bool pathClear = true;
			   for (int i = startCol + 1; i < 7; i++) {
				   if (pictureBoxes[startRow][i]->check_piece() != EMPTY) {
					   pathClear = false;
					   break;
				   }
			   }

			   if (pathClear &&
				   !is_square_under_attack(startRow, startCol + 1, WHITE) &&
				   !is_square_under_attack(startRow, startCol + 2, WHITE)) {

				   pictureBoxes[startRow][startCol + 2]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; 
				   kingsideRook->BackColor = System::Drawing::Color::LightBlue; 
			   }
		   }

		   ChessPiece^ queensideRook = pictureBoxes[startRow][0];
		   if (queensideRook->check_piece() == ROOK &&
			   queensideRook->check_color() == WHITE &&
			   !white_queenside_rook_moved) {

			   bool pathClear = true;
			   for (int i = startCol - 1; i > 0; i--) {
				   if (pictureBoxes[startRow][i]->check_piece() != EMPTY) {
					   pathClear = false;
					   break;
				   }
			   }

			   if (pathClear &&
				   !is_square_under_attack(startRow, startCol - 1, WHITE) &&
				   !is_square_under_attack(startRow, startCol - 2, WHITE)) {

				   pictureBoxes[startRow][startCol - 2]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png";
				   queensideRook->BackColor = System::Drawing::Color::LightBlue;
			   }
		   }
	   }
	   else if (kingColor == BLACK && !black_king_moved && !black_king_on_checked) {
		   ChessPiece^ kingsideRook = pictureBoxes[startRow][7];
		   if (kingsideRook->check_piece() == ROOK &&
			   kingsideRook->check_color() == BLACK &&
			   !black_kingside_rook_moved) {

			   bool pathClear = true;
			   for (int i = startCol + 1; i < 7; i++) {
				   if (pictureBoxes[startRow][i]->check_piece() != EMPTY) {
					   pathClear = false;
					   break;
				   }
			   }

			   if (pathClear &&
				   !is_square_under_attack(startRow, startCol + 1, BLACK) &&
				   !is_square_under_attack(startRow, startCol + 2, BLACK)) {

				   pictureBoxes[startRow][startCol + 2]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; 
				   kingsideRook->BackColor = System::Drawing::Color::LightBlue; 
			   }
		   }

		   ChessPiece^ queensideRook = pictureBoxes[startRow][0];
		   if (queensideRook->check_piece() == ROOK &&
			   queensideRook->check_color() == BLACK &&
			   !black_queenside_rook_moved) {

			   bool pathClear = true;
			   for (int i = startCol - 1; i > 0; i--) {
				   if (pictureBoxes[startRow][i]->check_piece() != EMPTY) {
					   pathClear = false;
					   break;
				   }
			   }

			   if (pathClear &&
				   !is_square_under_attack(startRow, startCol - 1, BLACK) &&
				   !is_square_under_attack(startRow, startCol - 2, BLACK)) {

				   pictureBoxes[startRow][startCol - 2]->ImageLocation = "C:\\Users\\USER\\Desktop\\on_move.png"; 
				   queensideRook->BackColor = System::Drawing::Color::LightBlue; 
			   }
		   }
	   }
   }

   void BoardForm::reset_highlight_moves()
   {
	   for (int i = 0; i < 8; ++i) {
		   for (int j = 0; j < 8; ++j) {
			   if (pictureBoxes[i][j]->BackColor == System::Drawing::Color::ForestGreen ||
				   pictureBoxes[i][j]->BackColor == System::Drawing::Color::LightBlue) {

				   pictureBoxes[i][j]->BackColor = System::Drawing::Color::Transparent;
			   }

			   if (pictureBoxes[i][j]->ImageLocation == "C:\\Users\\USER\\Desktop\\on_move.png") {
				   pictureBoxes[i][j]->BackColor = System::Drawing::Color::Transparent;
				   pictureBoxes[i][j]->ImageLocation = "";
			   }

			   if (pictureBoxes[i][j]->BackgroundImage != nullptr) {
				   pictureBoxes[i][j]->BackgroundImage = nullptr;
				   pictureBoxes[i][j]->BackgroundImageLayout = ImageLayout::None;
			   }
		   }
	   }
	   one_piece = true;
   }

   bool BoardForm::is_square_under_attack(int row, int col, PieceColor kingColor)
   {
	   if (row < 0 || row >= 8 || col < 0 || col >= 8) {
		   return false;
	   }

	   for (int r = 0; r < 8; ++r) {
		   for (int c = 0; c < 8; ++c) {
			   ChessPiece^ pieceBox = pictureBoxes[r][c];
			   if (pieceBox->check_color() != kingColor && pieceBox->check_piece() != EMPTY) {

				   if (is_king_under_attack(pieceBox, row, col)) {
					   return true;
				   }
			   }
		   }
	   }
	   return false;
   }

   void BoardForm::reset_pb(array<array<ChessPiece^>^>^ pictureBoxes)
   {
	  for (int i = 0; i < 8; i++) {
		   for (int j = 0; j < 8; j++)
		   {
			   if (pictureBoxes[i][j]->ImageLocation == "C:\\Users\\USER\\Desktop\\on_move.png")pictureBoxes[i][j]->ImageLocation = "";
		   }
	  }
   }
   bool BoardForm::king_checked(array<array<ChessPiece^>^>^ pictureBoxes, ChessPiece^ selected_piece)
   {
	   ChessPiece^ whiteKingBox = nullptr;
	   ChessPiece^ blackKingBox = nullptr;
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
			   if (pictureBoxes[i][j]->check_piece() == KING) {
				   if (pictureBoxes[i][j]->check_color() == WHITE) {
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
	   if (whiteKingBox != nullptr) {
		   for (int i = 0; i < 8; i++) {
			   for (int j = 0; j < 8; j++) {
				   if (pictureBoxes[i][j]->check_color() == BLACK && pictureBoxes[i][j] != selected_piece) {

					   pictureBoxes[i][j]->column = j;
					   pictureBoxes[i][j]->row = i;

					   if (is_king_under_attack(pictureBoxes[i][j], whiteKingRow, whiteKingCol)) {
						   whiteKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\white_king_checked.png";
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

	   if (blackKingBox != nullptr) {
		   for (int i = 0; i < 8; i++) {
			   for (int j = 0; j < 8; j++) {
				   if (pictureBoxes[i][j]->check_color() == WHITE && pictureBoxes[i][j] != selected_piece) {

					   pictureBoxes[i][j]->column = j;
					   pictureBoxes[i][j]->row = i;

					   if (is_king_under_attack(pictureBoxes[i][j], blackKingRow, blackKingCol)) {
						   blackKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king_checked.png";
						   last_moved_piece = selected_piece;
						   black_king_on_checked = true;
						   return true;
					   }
				   }
			   }
		   }
		   blackKingBox->row = blackKingRow;
		   blackKingBox->column = blackKingCol;
		   blackKingBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_king.png";
	   }


	   return false;
   }

   bool BoardForm::is_king_under_attack(ChessPiece^ piece, int kingRow, int kingCol)
   {
	   switch (piece->check_piece()) {
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

   bool BoardForm::check_Pawn_Attack(ChessPiece^ pawnBox, int kingRow, int kingCol)
   {
	   int pawnRow = pawnBox->row;
	   int pawnCol = pawnBox->column;
	   PieceColor pawnColor = pawnBox->check_color();

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
   bool BoardForm::check_Knight_Attack(ChessPiece^ knightBox, int kingRow, int kingCol)
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

   bool BoardForm::check_Bishop_Attack(ChessPiece^ bishopBox, int kingRow, int kingCol)
   {
	   int bishopRow = bishopBox->row;
	   int bishopCol = bishopBox->column;

	   bishopRow = Math::Min(Math::Max(bishopRow, 0), 7);
	   bishopCol = Math::Min(Math::Max(bishopCol, 0), 7);

	   if (abs(kingRow - bishopRow) == abs(kingCol - bishopCol)) {
		   int rowDirection = (kingRow > bishopRow) ? 1 : -1;
		   int colDirection = (kingCol > bishopCol) ? 1 : -1;

		   int currentRow = bishopRow + rowDirection;
		   int currentCol = bishopCol + colDirection;

		   while (currentRow != kingRow || currentCol != kingCol) {
			   if (currentRow < 0 || currentRow > 7 || currentCol < 0 || currentCol > 7) {
				   return false;
			   }

			   if (pictureBoxes[currentRow][currentCol]->check_piece() != NONE) {
				   return false;
			   }

			   currentRow += rowDirection;
			   currentCol += colDirection;
		   }

		   if (currentRow == kingRow && currentCol == kingCol) {
			   return true; 
		   }
	   }

	   return false;
   }

   bool BoardForm::check_Rook_Attack(ChessPiece^ rookBox, int kingRow, int kingCol)
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
				   if (pictureBoxes[rookRow][col]->check_piece() != NONE)
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
				   if (pictureBoxes[row][rookCol]->check_piece() != NONE)
				   {
					   return false; 
				   }
			   }
			   return true; 
		   }
	   }

	   return false;
   }
   bool BoardForm::check_Queen_Attack(ChessPiece^ queenBox, int kingRow, int kingCol)
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
		   targetPictureBox->set_color(WHITE);
	   }
	   else
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_bishop.png";
		   targetPictureBox->set_color(BLACK);
	   }
	   targetPictureBox->set_piece(BISHOP);
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
		   targetPictureBox->set_color(WHITE);
	   }
	   else
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_rook.png";
		   targetPictureBox->set_color(BLACK);
	   }
	   targetPictureBox->set_piece(ROOK);
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
		   targetPictureBox->set_color(WHITE);
	   }
	   else
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_knight.png";
		   targetPictureBox->set_color(BLACK);
	   }

	   targetPictureBox->set_piece(KNIGHT);
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
		   targetPictureBox->set_color(WHITE);
	   }
	   else
	   {
		   targetPictureBox->ImageLocation = "C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\black_queen.png";
		   targetPictureBox->set_color(BLACK);
	   }
	   targetPictureBox->set_piece(QUEEN);
	   grid_panel->Enabled = true;
	   promote_panel->Visible = false;
	   promote_panel->Enabled = false;
	   promote_panel->SendToBack();
   }

   //check is king chechmated

   bool BoardForm::is_king_still_in_check_after_move(array<array<ChessPiece^>^>^ pb, ChessPiece^ selected, ChessPiece^ target) {
	   Piece originalPiece = target->check_piece();
	   PieceColor originalColor = target->check_color();
	   String^ originalImageLocation = target->ImageLocation;

	   target->set_piece(selected->check_piece());
	   target->set_color(selected->check_color());
	   target->ImageLocation = selected->ImageLocation;

	   selected->set_piece(EMPTY);
	   selected->set_color(NONE);
	   selected->ImageLocation = "";

	   bool stillInCheck = king_still_checked(pb, selected, target, nullptr);

	   selected->set_piece(target->check_piece());
	   selected->set_color(target->check_color());
	   selected->ImageLocation = target->ImageLocation;

	   target->set_piece(originalPiece);
	   target->set_color(originalColor);
	   target->ImageLocation = originalImageLocation;

	   return stillInCheck;
   }

   bool BoardForm::pawn_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox)
   {
	   int row = currentBox->row;
	   int col = currentBox->column;
	   PieceColor pieceColor = currentBox->check_color();

	   int direction = (pieceColor == WHITE) ? -1 : 1;

	   if (row + direction >= 0 && row + direction < 8) {
		   if (pb[row + direction][col]->check_piece() == EMPTY) {
			   ChessPiece^ originalBox = pb[row + direction][col];
			   Piece originalPiece = originalBox->check_piece();
			   PieceColor originalColor = originalBox->check_color();
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[row + direction][col]->ImageLocation = currentBox->ImageLocation;
			   pb[row + direction][col]->set_piece(currentBox->check_piece());
			   pb[row + direction][col]->set_color(currentBox->check_color());

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(EMPTY);
			   currentBox->set_color(NONE);

			   if (!king_still_checked(pb, nullptr, nullptr, nullptr)) {
				   currentBox->ImageLocation = pb[row + direction][col]->ImageLocation;
				   currentBox->set_piece(pb[row + direction][col]->check_piece());
				   currentBox->set_color(pb[row + direction][col]->check_color());

				   pb[row + direction][col]->ImageLocation = originalImageLocation;
				   pb[row + direction][col]->set_piece(originalPiece);
				   pb[row + direction][col]->set_color(originalColor);

				   return true;
			   }
			   currentBox->ImageLocation = pb[row + direction][col]->ImageLocation;
			   currentBox->set_piece(pb[row + direction][col]->check_piece());
			   currentBox->set_color(pb[row + direction][col]->check_color());

			   pb[row + direction][col]->ImageLocation = originalImageLocation;
			   pb[row + direction][col]->set_piece(originalPiece);
			   pb[row + direction][col]->set_color(originalColor);
		   }
	   }

	   if ((pieceColor == WHITE && row == 6) || (pieceColor == BLACK && row == 1)) {
		   if (pb[row + direction][col]->check_piece() == EMPTY &&
			   pb[row + 2 * direction][col]->check_piece() == EMPTY) {
			   ChessPiece^ originalBox = pb[row + 2 * direction][col];
			   Piece originalPiece = originalBox->check_piece();
			   PieceColor originalColor = originalBox->check_color();
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[row + 2 * direction][col]->ImageLocation = currentBox->ImageLocation;
			   pb[row + 2 * direction][col]->set_piece(currentBox->check_piece());
			   pb[row + 2 * direction][col]->set_color(currentBox->check_color());

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(EMPTY);
			   currentBox->set_color(NONE);

			   if (!king_still_checked(pb, nullptr, nullptr, nullptr)) {
				   currentBox->ImageLocation = pb[row + 2 * direction][col]->ImageLocation;
				   currentBox->set_piece(pb[row + 2 * direction][col]->check_piece());
				   currentBox->set_color(pb[row + 2 * direction][col]->check_color());

				   pb[row + 2 * direction][col]->ImageLocation = originalImageLocation;
				   pb[row + 2 * direction][col]->set_piece(originalPiece);
				   pb[row + 2 * direction][col]->set_color(originalColor);

				   return true;
			   }

			   currentBox->ImageLocation = pb[row + 2 * direction][col]->ImageLocation;
			   currentBox->set_piece(pb[row + 2 * direction][col]->check_piece());
			   currentBox->set_color(pb[row + 2 * direction][col]->check_color());

			   pb[row + 2 * direction][col]->ImageLocation = originalImageLocation;
			   pb[row + 2 * direction][col]->set_piece(originalPiece);
			   pb[row + 2 * direction][col]->set_color(originalColor);
		   }
	   }

	   if (col > 0 && row + direction >= 0 && row + direction < 8) {
		   if (pb[row + direction][col - 1]->check_piece() != EMPTY &&
			   pb[row + direction][col - 1]->check_color() != pieceColor) {
			   ChessPiece^ originalBox = pb[row + direction][col - 1];
			   Piece originalPiece = originalBox->check_piece();
			   PieceColor originalColor = originalBox->check_color();
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[row + direction][col - 1]->ImageLocation = currentBox->ImageLocation;
			   pb[row + direction][col - 1]->set_piece(currentBox->check_piece());
			   pb[row + direction][col - 1]->set_color(currentBox->check_color());

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(EMPTY);
			   currentBox->set_color(NONE);

			   if (!king_still_checked(pb, nullptr, nullptr, nullptr)) {
				   currentBox->ImageLocation = pb[row + direction][col - 1]->ImageLocation;
				   currentBox->set_piece(pb[row + direction][col - 1]->check_piece());
				   currentBox->set_color(pb[row + direction][col - 1]->check_color());

				   pb[row + direction][col - 1]->ImageLocation = originalImageLocation;
				   pb[row + direction][col - 1]->set_piece(originalPiece);
				   pb[row + direction][col - 1]->set_color(originalColor);

				   return true; 
			   }

			   currentBox->ImageLocation = pb[row + direction][col - 1]->ImageLocation;
			   currentBox->set_piece(pb[row + direction][col - 1]->check_piece());
			   currentBox->set_color(pb[row + direction][col - 1]->check_color());

			   pb[row + direction][col - 1]->ImageLocation = originalImageLocation;
			   pb[row + direction][col - 1]->set_piece(originalPiece);
			   pb[row + direction][col - 1]->set_color(originalColor);
		   }
	   }

	   if (col < 7 && row + direction >= 0 && row + direction < 8) {
		   if (pb[row + direction][col + 1]->check_piece() != EMPTY &&
			   pb[row + direction][col + 1]->check_color() != pieceColor) {
			   ChessPiece^ originalBox = pb[row + direction][col + 1];
			   Piece originalPiece = originalBox->check_piece();
			   PieceColor originalColor = originalBox->check_color();
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[row + direction][col + 1]->ImageLocation = currentBox->ImageLocation;
			   pb[row + direction][col + 1]->set_piece(currentBox->check_piece());
			   pb[row + direction][col + 1]->set_color(currentBox->check_color());

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(EMPTY);
			   currentBox->set_color(NONE);

			   if (!king_still_checked(pb, nullptr, nullptr, nullptr)) {
				   currentBox->ImageLocation = pb[row + direction][col + 1]->ImageLocation;
				   currentBox->set_piece(pb[row + direction][col + 1]->check_piece());
				   currentBox->set_color(pb[row + direction][col + 1]->check_color());

				   pb[row + direction][col + 1]->ImageLocation = originalImageLocation;
				   pb[row + direction][col + 1]->set_piece(originalPiece);
				   pb[row + direction][col + 1]->set_color(originalColor);

				   return true;
			   }
			   currentBox->ImageLocation = pb[row + direction][col + 1]->ImageLocation;
			   currentBox->set_piece(pb[row + direction][col + 1]->check_piece());
			   currentBox->set_color(pb[row + direction][col + 1]->check_color());

			   pb[row + direction][col + 1]->ImageLocation = originalImageLocation;
			   pb[row + direction][col + 1]->set_piece(originalPiece);
			   pb[row + direction][col + 1]->set_color(originalColor);
		   }
	   }

	   return false;
   }
   
   bool BoardForm::knight_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox)
   {
	   int row = currentBox->row;
    int col = currentBox->column;
    PieceColor pieceColor = currentBox->check_color();

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
            if (pb[newRow][newCol]->check_color() != pieceColor)
            {
				ChessPiece^ originalBox = pb[newRow][newCol];
                Piece originalPiece = originalBox->check_piece();
                PieceColor originalColor = originalBox->check_color();
                String^ originalImageLocation = originalBox->ImageLocation;

                pb[newRow][newCol]->ImageLocation = currentBox->ImageLocation;
                pb[newRow][newCol]->set_piece(currentBox->check_piece());
                pb[newRow][newCol]->set_color(currentBox->check_color());

                currentBox->ImageLocation = "";
                currentBox->set_piece(EMPTY);
                currentBox->set_color(NONE);

                if (!king_still_checked(pb, nullptr, nullptr, nullptr))
                {
                    currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
                    currentBox->set_piece(pb[newRow][newCol]->check_piece());
                    currentBox->set_color(pb[newRow][newCol]->check_color());

                    pb[newRow][newCol]->ImageLocation = originalImageLocation;
                    pb[newRow][newCol]->set_piece(originalPiece);
                    pb[newRow][newCol]->set_color(originalColor);

                    return true; 
                }
                currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
                currentBox->set_piece(pb[newRow][newCol]->check_piece());
                currentBox->set_color(pb[newRow][newCol]->check_color());

                pb[newRow][newCol]->ImageLocation = originalImageLocation;
                pb[newRow][newCol]->set_piece(originalPiece);
                pb[newRow][newCol]->set_color(originalColor);
            }
        }
    }
    return false;
   }
   
   bool BoardForm::bishop_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox)
   {
	   int row = currentBox->row;
	   int col = currentBox->column;
	   PieceColor pieceColor = currentBox->check_color();

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
			   if (pb[newRow][newCol]->check_color() == pieceColor)
				   break; 

			   ChessPiece^ originalBox = pb[newRow][newCol];
			   Piece originalPiece = originalBox->check_piece();
			   PieceColor originalColor = originalBox->check_color();
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[newRow][newCol]->ImageLocation = currentBox->ImageLocation;
			   pb[newRow][newCol]->set_piece(currentBox->check_piece());
			   pb[newRow][newCol]->set_color(currentBox->check_color());

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(EMPTY);
			   currentBox->set_color(NONE);

			   if (!king_still_checked(pb, nullptr, nullptr, nullptr))
			   {
				   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   currentBox->set_piece(pb[newRow][newCol]->check_piece());
				   currentBox->set_color(pb[newRow][newCol]->check_color());

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(originalPiece);
				   pb[newRow][newCol]->set_color(originalColor);

				   return true; 
			   }
			   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
			   currentBox->set_piece(pb[newRow][newCol]->check_piece());
			   currentBox->set_color(pb[newRow][newCol]->check_color());

			   pb[newRow][newCol]->ImageLocation = originalImageLocation;
			   pb[newRow][newCol]->set_piece(originalPiece);
			   pb[newRow][newCol]->set_color(originalColor);

			   newRow += direction.X;
			   newCol += direction.Y;
		   }
	   }

	   return false;
   }
   
   bool BoardForm::rook_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox)
   {
	   int row = currentBox->row;
	   int col = currentBox->column;
	   PieceColor pieceColor = currentBox->check_color();

	   array<Point>^ rookDirections = gcnew array<Point>
	   {
		   Point(-1, 0), Point(1, 0), 
			   Point(0, -1), Point(0, 1)  
	   };
	   for each (Point direction in rookDirections)
	   {
		   int newRow = row + direction.X;
		   int newCol = col + direction.Y;

		   while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
		   {
			   if (pb[newRow][newCol]->check_color() == pieceColor)
				   break; 

			   ChessPiece^ originalBox = pb[newRow][newCol];
			   Piece originalPiece = originalBox->check_piece();
			   PieceColor originalColor = originalBox->check_color();
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[newRow][newCol]->ImageLocation = currentBox->ImageLocation;
			   pb[newRow][newCol]->set_piece(currentBox->check_piece());
			   pb[newRow][newCol]->set_color(currentBox->check_color());

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(EMPTY);
			   currentBox->set_color(NONE);

			   if (!king_still_checked(pb, nullptr, nullptr, nullptr))
			   {
				   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   currentBox->set_piece(pb[newRow][newCol]->check_piece());
				   currentBox->set_color(pb[newRow][newCol]->check_color());

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(originalPiece);
				   pb[newRow][newCol]->set_color(originalColor);

				   return true;
			   }

			   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
			   currentBox->set_piece(pb[newRow][newCol]->check_piece());
			   currentBox->set_color(pb[newRow][newCol]->check_color());

			   pb[newRow][newCol]->ImageLocation = originalImageLocation;
			   pb[newRow][newCol]->set_piece(originalPiece);
			   pb[newRow][newCol]->set_color(originalColor);

			   newRow += direction.X;
			   newCol += direction.Y;
		   }
	   }

	   return false;
   }
   
   bool BoardForm::queen_cansaveking(array<array<ChessPiece^>^>^ pb, ChessPiece^ currentBox)
   {
	   int row = currentBox->row;
	   int col = currentBox->column;
	   PieceColor pieceColor = currentBox->check_color();

	   array<Point>^ queenDirections = gcnew array<Point>
	   {
		   Point(-1, 0), Point(1, 0),    
			   Point(0, -1), Point(0, 1),   
			   Point(-1, -1), Point(-1, 1),  
			   Point(1, -1), Point(1, 1)     
	   };

	   for each (Point direction in queenDirections)
	   {
		   int newRow = row + direction.X;
		   int newCol = col + direction.Y;

		   while (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8)
		   {
			   if (pb[newRow][newCol]->check_color() == pieceColor)
				   break;

			   ChessPiece^ originalBox = pb[newRow][newCol];
			   Piece originalPiece = originalBox->check_piece();
			   PieceColor originalColor = originalBox->check_color();
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[newRow][newCol]->ImageLocation = currentBox->ImageLocation;
			   pb[newRow][newCol]->set_piece(currentBox->check_piece());
			   pb[newRow][newCol]->set_color(currentBox->check_color());

			   currentBox->ImageLocation = "";
			   currentBox->set_piece(EMPTY);
			   currentBox->set_color(NONE);

			   if (!king_still_checked(pb, nullptr, nullptr, nullptr))
			   {
				   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   currentBox->set_piece(pb[newRow][newCol]->check_piece());
				   currentBox->set_color(pb[newRow][newCol]->check_color());

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(originalPiece);
				   pb[newRow][newCol]->set_color(originalColor);

				   return true;
			   }

			   currentBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
			   currentBox->set_piece(pb[newRow][newCol]->check_piece());
			   currentBox->set_color(pb[newRow][newCol]->check_color());

			   pb[newRow][newCol]->ImageLocation = originalImageLocation;
			   pb[newRow][newCol]->set_piece(originalPiece);
			   pb[newRow][newCol]->set_color(originalColor);

			   newRow += direction.X;
			   newCol += direction.Y;
		   }
	   }

	   return false;
   }
   

   bool BoardForm::is_checkmate(array<array<ChessPiece^>^>^ pb, ChessPiece^ kingBox) {
	   int kingRow = kingBox->row;
	   int kingCol = kingBox->column;

	   array<Point>^ kingMoves = gcnew array<Point>
	   {
		   Point(-1, -1), Point(-1, 0), Point(-1, 1),
			   Point(0, -1), Point(0, 1),
			   Point(1, -1), Point(1, 0), Point(1, 1)
	   };

	   for each (Point move in kingMoves) {
		   int newRow = kingRow + move.X;
		   int newCol = kingCol + move.Y;

		   if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
			   if (pb[newRow][newCol]->check_color() != kingBox->check_color()) {
				   ChessPiece^ originalBox = pb[newRow][newCol];
				   Piece originalPiece = originalBox->check_piece();
				   PieceColor originalColor = originalBox->check_color();
				   String^ originalImageLocation = originalBox->ImageLocation;

				   pb[newRow][newCol]->ImageLocation = kingBox->ImageLocation;
				   pb[newRow][newCol]->set_piece(kingBox->check_piece());
				   pb[newRow][newCol]->set_color(kingBox->check_color());

				   kingBox->ImageLocation = "";
				   kingBox->set_piece(EMPTY);
				   kingBox->set_color(NONE);

				   if (!king_still_checked(pb, pb[newRow][newCol], originalBox, nullptr)) {
					   kingBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
					   kingBox->set_piece(pb[newRow][newCol]->check_piece());
					   kingBox->set_color(pb[newRow][newCol]->check_color());

					   pb[newRow][newCol]->ImageLocation = originalImageLocation;
					   pb[newRow][newCol]->set_piece(originalPiece);
					   pb[newRow][newCol]->set_color(originalColor);

					   return false; 
				   }
				   kingBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   kingBox->set_piece(pb[newRow][newCol]->check_piece());
				   kingBox->set_color(pb[newRow][newCol]->check_color());

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(originalPiece);
				   pb[newRow][newCol]->set_color(originalColor);
			   }
		   }
	   }
	   for each (Point move in kingMoves) {
		   int newRow = kingRow + move.X;
		   int newCol = kingCol + move.Y;

		   if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
			   if (pb[newRow][newCol]->check_color() == kingBox->check_color()) {
				   continue; 
			   }

			   ChessPiece^ originalBox = pb[newRow][newCol];
			   Piece originalPiece = originalBox->check_piece();
			   PieceColor originalColor = originalBox->check_color();
			   String^ originalImageLocation = originalBox->ImageLocation;

			   pb[newRow][newCol]->ImageLocation = kingBox->ImageLocation;
			   pb[newRow][newCol]->set_piece(kingBox->check_piece());
			   pb[newRow][newCol]->set_color(kingBox->check_color());

			   kingBox->ImageLocation = "";
			   kingBox->set_piece(EMPTY);
			   kingBox->set_color(NONE);

			   if (!king_still_checked(pb, pb[newRow][newCol], originalBox, nullptr)) {
				   kingBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
				   kingBox->set_piece(pb[newRow][newCol]->check_piece());
				   kingBox->set_color(pb[newRow][newCol]->check_color());

				   pb[newRow][newCol]->ImageLocation = originalImageLocation;
				   pb[newRow][newCol]->set_piece(originalPiece);
				   pb[newRow][newCol]->set_color(originalColor);

				   return false;
			   }

			   kingBox->ImageLocation = pb[newRow][newCol]->ImageLocation;
			   kingBox->set_piece(pb[newRow][newCol]->check_piece());
			   kingBox->set_color(pb[newRow][newCol]->check_color());

			   pb[newRow][newCol]->ImageLocation = originalImageLocation;
			   pb[newRow][newCol]->set_piece(originalPiece);
			   pb[newRow][newCol]->set_color(originalColor);
		   }
	   }


	   for (int row = 0; row < 8; row++) {
		   for (int col = 0; col < 8; col++) {
			   ChessPiece^ currentBox = pb[row][col];

			   if (currentBox->check_color() == kingBox->check_color()) {
				   switch (currentBox->check_piece()) {
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
	   return true;
   }
};


