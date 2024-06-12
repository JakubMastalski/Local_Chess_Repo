#include "BoardForm.h"
#include <cmath> 
#include <algorithm> 

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
		custom_picturebox^ pictureBoxInstance = gcnew custom_picturebox();
		pictureBoxInstance->InitializeBoard(); // init board in pb_instance
		this->pictureBoxes = pictureBoxInstance->GetPictureBoxes(); 
		//add picture boxed to form
	// Inicjalizacja czarnych pionk�w (rz�dy 6 i 7) i przypisanie im zdarze� myszy
	
		// Inicjalizacja pustych p�l planszy (rz�dy 2 do 5) i przypisanie im zdarze� myszy
		for (int row = 2; row < 6; row++) {
			for (int col = 0; col < 8; col++) {
				this->grid_panel->Controls->Add(pictureBoxes[row][col]);
				pictureBoxes[row][col]->ImageLocation = "";
				//pictureBoxes[row][col]->MouseDown += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseDown);
				//pictureBoxes[row][col]->MouseMove += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseMove);
				//pictureBoxes[row][col]->MouseUp += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseUp);
				pictureBoxes[row][col]->Enabled = true;
				pictureBoxes[row][col]->ImageLocation = "";
				pictureBoxes[row][col]->set_color(pictureBoxes[row][col], NONE);
				pictureBoxes[row][col]->set_piece(pictureBoxes[row][col], EMPTY);
				//pictureBoxes[row][col]->Visible = true;;
			}
		}

		for (int col = 0; col < 8; col++) {
			this->grid_panel->Controls->Add(pictureBoxes[6][col]);
			this->grid_panel->Controls->Add(pictureBoxes[7][col]);
			pictureBoxes[6][col]->set_color(pictureBoxes[6][col], WHITE);
			pictureBoxes[6][col]->set_piece(pictureBoxes[6][col], PAWN);

			pictureBoxes[7][col]->set_color(pictureBoxes[7][col], WHITE);
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
				break;
			}
		}

		// Inicjalizacja bia�ych pionk�w (rz�dy 0 i 1) i przypisanie im zdarze� myszy
		for (int col = 0; col < 8; col++) {
			this->grid_panel->Controls->Add(pictureBoxes[0][col]);
			this->grid_panel->Controls->Add(pictureBoxes[1][col]);

			pictureBoxes[0][col]->set_color(pictureBoxes[0][col], BLACK);
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
				break;
			}
			pictureBoxes[1][col]->set_color(pictureBoxes[1][col],BLACK);
			pictureBoxes[1][col]->set_piece(pictureBoxes[1][col], PAWN);

		}
		
	
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				pictureBoxes[i][j]->MouseDown += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseDown);
				pictureBoxes[i][j]->MouseMove += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseMove);
				pictureBoxes[i][j]->MouseUp += gcnew MouseEventHandler(this, &BoardForm::grid_panel_MouseUp);

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
		this->board_panel->Controls->Add(this->label_blacktime);
		this->board_panel->Controls->Add(this->time_black);
		this->board_panel->Controls->Add(this->picturebox_board);
		this->board_panel->Location = System::Drawing::Point(50, 57);
		this->board_panel->Name = L"board_panel";
		this->board_panel->Size = System::Drawing::Size(700, 469);
		this->board_panel->TabIndex = 0;
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
		this->grid_panel->BackColor = System::Drawing::Color::Transparent;
		this->grid_panel->Location = System::Drawing::Point(121, 5);
		this->grid_panel->Name = L"grid_panel";
		this->grid_panel->Size = System::Drawing::Size(460, 460);
		this->grid_panel->Controls->Add(picturebox_bg);
		this->grid_panel->BackgroundImage = Image::FromFile(L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg");
		this->grid_panel->TabIndex = 47;
		this->grid_panel->Visible = true;
		this->grid_panel->BringToFront();
		this->grid_panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::grid_panel_MouseDown);
		this->grid_panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::grid_panel_MouseMove);
		this->grid_panel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &BoardForm::grid_panel_MouseUp);
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
		this->timeset_panel->ResumeLayout(false);
		this->timeset_panel->PerformLayout();
		this->increment_panel->ResumeLayout(false);
		this->increment_panel->PerformLayout();
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
	}
#pragma endregion
#pragma endregion
	//chess board init

		//flip board
	

void BoardForm::flipBoardToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->grid_panel->Controls->Clear();
	//init grid panel

	if (this->picturebox_board->ImageLocation == L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg")
	{
		//array of board classes objects
		custom_picturebox^ pictureBoxInstance = gcnew custom_picturebox();
		pictureBoxInstance->FlipBoard(); // init board in pb_instance
		this->pictureBoxes = pictureBoxInstance->GetPictureBoxes();
		//add picture boxed to form
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				this->grid_panel->Controls->Add(pictureBoxes[i][j]);
			}
		}
		this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\flipedboard1.jpg";
		picturebox_board->Refresh();
		label_blacktime->Location = start_white;
		label_whitetime->Location = start_black;
	}
	else
	{
		//array of board classes objects
		custom_picturebox^ pictureBoxInstance = gcnew custom_picturebox();
		pictureBoxInstance->InitializeBoard(); // init board in pb_instance
		this->pictureBoxes = pictureBoxInstance->GetPictureBoxes();
		//add picture boxed to form
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				this->grid_panel->Controls->Add(pictureBoxes[i][j]);
			}
		}
		this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg";
		picturebox_board->Refresh();
		label_blacktime->Location = start_black;
		label_whitetime->Location = start_white;
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
	   void BoardForm::menu_timer_white_Tick(System::Object^ sender, System::EventArgs^ e) {
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

    void BoardForm::grid_panel_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			selectedPictureBox = dynamic_cast<custom_picturebox^>(sender);

			if (selectedPictureBox->ImageLocation != "")
			{
				if (selectedPictureBox != nullptr) {
					selectedPictureBox->Capture = true;
					selectedPictureBox->BringToFront();
					chosen_piece_val = selectedPictureBox->get_value(selectedPictureBox);
					current_piece = selectedPictureBox->check_piece(selectedPictureBox);
					start_location = selectedPictureBox->Location;
					file_path = selectedPictureBox->ImageLocation;
					selectedPictureBox->Tag = "Dragging";
				}
			}
		}
   }
	void BoardForm::grid_panel_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		if (e->Button == System::Windows::Forms::MouseButtons::Left && selectedPictureBox != nullptr && selectedPictureBox->Tag->ToString() == "Dragging") {
			Point new_location = selectedPictureBox->Parent->PointToClient(Control::MousePosition);
			new_location.Offset(-selectedPictureBox->Width / 2, -selectedPictureBox->Height / 2);
		    selectedPictureBox->BringToFront();
			selectedPictureBox->Location = new_location;
		}

	}


	void BoardForm::grid_panel_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left && selectedPictureBox != nullptr && selectedPictureBox->Tag->ToString() == "Dragging") {
			selectedPictureBox->Capture = false;
			selectedPictureBox->Tag = "";

		    isWithinBounds = check_sent(selectedPictureBox);

			if (selectedPictureBox->Location != start_location && isWithinBounds) {
				switch (current_piece) {
				case PAWN:
					if (!check_Pawnmove(pictureBoxes, selectedPictureBox)) {
						selectedPictureBox->Location = start_location;
						return;
					}
					break;
				case KNIGHT:
					if (!check_Knightmove(pictureBoxes, selectedPictureBox)) {
						selectedPictureBox->Location = start_location;
						return;
					}
					break;
				case BISHOP:
					if (!check_Bishopmove(pictureBoxes, selectedPictureBox)) {
						selectedPictureBox->Location = start_location;
						return;
					}
					break;
				case ROOK:
					if (!check_Rookmove(pictureBoxes, selectedPictureBox)) {
						selectedPictureBox->Location = start_location;
						return;
					}
					break;
				case QUEEN:
					if (!check_Queenmove(pictureBoxes, selectedPictureBox)) {
						selectedPictureBox->Location = start_location;
						return;
					}
					break;
				case KING:
					if (!check_Kingmove(pictureBoxes, selectedPictureBox)) {
						selectedPictureBox->Location = start_location;
						return;
					}
					break;
				default:
					selectedPictureBox->Location = start_location;
					return;
				}
				selectedPictureBox->SendToBack();
			}
			else {
				selectedPictureBox->Location = start_location;
				selectedPictureBox->ImageLocation = file_path;
				return;
			}

			controlUnderCursor = selectedPictureBox->Parent->GetChildAtPoint(selectedPictureBox->Parent->PointToClient(Control::MousePosition));
			targetPictureBox = dynamic_cast<custom_picturebox^>(controlUnderCursor);

			if (targetPictureBox != nullptr && targetPictureBox != selectedPictureBox) {
				BoardForm::change_pb(selectedPictureBox, targetPictureBox);
			}
		}
	}
	//swap pb
	void BoardForm::change_pb(custom_picturebox^ selected_pb, custom_picturebox^ target_pb)
	{
		Piece chossen_piece = selected_pb->check_piece(selected_pb);

		if (!check_Pawnmove(pictureBoxes,selected_pb)) {
			selected_pb->Location = start_location;
			return;
		}

		String^ pb_newfilepath = selected_pb->ImageLocation;
		target_pb->BringToFront();
		PieceColor piece_color1  = selected_pb->check_color(selected_pb);
		Piece piece1 = selected_pb->check_piece(selected_pb);
		int piece_value = selected_pb->get_value(selected_pb);
		

		target_pb->ImageLocation = pb_newfilepath;
		target_pb->set_color(target_pb, piece_color1);
		target_pb->set_piece(target_pb, piece1);
		target_pb->set_value(target_pb, piece_value);
		
		selected_pb->ImageLocation = "";
		selected_pb->set_color(selected_pb, NONE);
		selected_pb->set_value(selected_pb, 0);
		selected_pb->set_piece(selected_pb, EMPTY);
		selected_pb->Location = start_location;
		selected_pb->BringToFront();
	}
	//check pawn
	bool BoardForm::check_Pawnmove(array<array<custom_picturebox^>^>^ pictureBoxes,custom_picturebox^ selected_pb)
	{
		Point startPos = start_location; // Original position of the piece
		Point targetPos = selected_pb->Location; // New position of the piece

		// Calculate the difference in positions
		int dx = abs(targetPos.X - startPos.X) / selected_pb->Width; // difference in columns
		int dy = abs(targetPos.Y - startPos.Y) / selected_pb->Height; // difference in rows

		// Check if the move is exactly one step forward or backward
		if (dx == 0 && dy == 1) {
			return true;
		}

		// If the move is not valid, bring all pieces to front (as in the original code)
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				pictureBoxes[i][j]->BringToFront();
			}
		}

		return false;
		
	}
	//check does pb in board border
	bool BoardForm::check_sent(custom_picturebox^ selected_pb)
	{
		int x = selected_pb->Location.X;
		int y = selected_pb->Location.Y;
		int pb_value;


		int pbWidth = selected_pb->Width;
		int pbHeight = selected_pb->Height;
		int panelWidth = 460;  
		int panelHeight = 460;

		
		if (x >= 0 && x + pbWidth <= panelWidth && y >= 0 && y + pbHeight <= panelHeight) {
			return true;
		}
		else {
			return false;
		}
		pb_value = selected_pb->get_value(selected_pb);
	}
	//check knight
	bool BoardForm::check_Knightmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		return true;
	}
	//check bishop
	bool BoardForm::check_Bishopmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		return true;
	}
	//check rook
	bool BoardForm::check_Rookmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		return true;
	}
	//check queen
	bool BoardForm::check_Queenmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		return true;
	}
	//check king
	bool BoardForm::check_Kingmove(array<array<custom_picturebox^>^>^ pictureBoxes, custom_picturebox^ selected_pb)
	{
		return true;
	}


};


