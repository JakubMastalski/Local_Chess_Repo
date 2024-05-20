#pragma once

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
	public:
		BoardForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::PictureBox^ picturebox_board;


	private: System::Windows::Forms::Label^ label_blacktime;
	private: System::Windows::Forms::Label^ label_whitetime;
	private: System::Windows::Forms::Label^ time_white;

	private: System::Windows::Forms::Label^ time_black;

	private: System::Windows::Forms::MenuStrip^ chess_menu;


	private: System::Windows::Forms::ToolStripMenuItem^ flipBoardToolStripMenuItem;
	private: System::Windows::Forms::Panel^ timeset_panel;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ time_options_box;

	private: System::Windows::Forms::ToolStripMenuItem^ setTimeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ restartToolStripMenuItem1;



	private: System::Windows::Forms::ToolStripMenuItem^ flipBoardToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ save_time_button;

	private: System::Windows::Forms::TrackBar^ trackbar_minperside;
	private: System::Windows::Forms::TrackBar^ trackbar_secincrement;
	private: System::Windows::Forms::Label^ label_minperside;

	private: System::Windows::Forms::Label^ label_incpersec;
	private: System::Windows::Forms::Timer^ menu_timer_black;
	private: System::Windows::Forms::Timer^ menu_timer_white;

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
			this->board_panel = (gcnew System::Windows::Forms::Panel());
			this->time_white = (gcnew System::Windows::Forms::Label());
			this->label_whitetime = (gcnew System::Windows::Forms::Label());
			this->label_blacktime = (gcnew System::Windows::Forms::Label());
			this->time_black = (gcnew System::Windows::Forms::Label());
			this->timeset_panel = (gcnew System::Windows::Forms::Panel());
			this->label_minperside = (gcnew System::Windows::Forms::Label());
			this->trackbar_minperside = (gcnew System::Windows::Forms::TrackBar());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label_incpersec = (gcnew System::Windows::Forms::Label());
			this->trackbar_secincrement = (gcnew System::Windows::Forms::TrackBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->save_time_button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->time_options_box = (gcnew System::Windows::Forms::ComboBox());
			this->picturebox_board = (gcnew System::Windows::Forms::PictureBox());
			this->chess_menu = (gcnew System::Windows::Forms::MenuStrip());
			this->flipBoardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipBoardToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setTimeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restartToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_timer_black = (gcnew System::Windows::Forms::Timer(this->components));
			this->menu_timer_white = (gcnew System::Windows::Forms::Timer(this->components));
			this->board_panel->SuspendLayout();
			this->timeset_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_minperside))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_secincrement))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->BeginInit();
			this->chess_menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// board_panel
			// 
			this->board_panel->Controls->Add(this->time_white);
			this->board_panel->Controls->Add(this->label_whitetime);
			this->board_panel->Controls->Add(this->label_blacktime);
			this->board_panel->Controls->Add(this->time_black);
			this->board_panel->Controls->Add(this->timeset_panel);
			this->board_panel->Controls->Add(this->picturebox_board);
			this->board_panel->Location = System::Drawing::Point(26, 61);
			this->board_panel->Name = L"board_panel";
			this->board_panel->Size = System::Drawing::Size(698, 444);
			this->board_panel->TabIndex = 0;
			// 
			// time_white
			// 
			this->time_white->AutoSize = true;
			this->time_white->BackColor = System::Drawing::Color::Gray;
			this->time_white->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->time_white->Font = (gcnew System::Drawing::Font(L"Segoe UI", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->time_white->Location = System::Drawing::Point(564, 237);
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
			this->label_whitetime->Location = System::Drawing::Point(565, 203);
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
			this->label_blacktime->Location = System::Drawing::Point(574, 13);
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
			this->time_black->Location = System::Drawing::Point(563, 45);
			this->time_black->Name = L"time_black";
			this->time_black->Size = System::Drawing::Size(0, 50);
			this->time_black->TabIndex = 5;
			this->time_black->Visible = false;
			// 
			// timeset_panel
			// 
			this->timeset_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->timeset_panel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->timeset_panel->Controls->Add(this->label_minperside);
			this->timeset_panel->Controls->Add(this->trackbar_minperside);
			this->timeset_panel->Controls->Add(this->label2);
			this->timeset_panel->Controls->Add(this->panel3);
			this->timeset_panel->Controls->Add(this->panel2);
			this->timeset_panel->Location = System::Drawing::Point(199, 55);
			this->timeset_panel->Name = L"timeset_panel";
			this->timeset_panel->Size = System::Drawing::Size(330, 232);
			this->timeset_panel->TabIndex = 6;
			this->timeset_panel->Visible = false;
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(107, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(109, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Minutes per side:";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(125)));
			this->panel3->Controls->Add(this->label_incpersec);
			this->panel3->Controls->Add(this->trackbar_secincrement);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 145);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(328, 85);
			this->panel3->TabIndex = 10;
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
			// trackbar_secincrement
			// 
			this->trackbar_secincrement->Location = System::Drawing::Point(41, 29);
			this->trackbar_secincrement->Name = L"trackbar_secincrement";
			this->trackbar_secincrement->Size = System::Drawing::Size(243, 56);
			this->trackbar_secincrement->TabIndex = 12;
			this->trackbar_secincrement->Scroll += gcnew System::EventHandler(this, &BoardForm::trackbar_secincrement_Scroll);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(107, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Increment per sec:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(125)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(125)));
			this->panel2->Controls->Add(this->save_time_button);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->time_options_box);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(328, 56);
			this->panel2->TabIndex = 9;
			// 
			// save_time_button
			// 
			this->save_time_button->BackColor = System::Drawing::Color::Black;
			this->save_time_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->save_time_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->save_time_button->ForeColor = System::Drawing::Color::White;
			this->save_time_button->Location = System::Drawing::Point(3, 16);
			this->save_time_button->Name = L"save_time_button";
			this->save_time_button->Size = System::Drawing::Size(49, 25);
			this->save_time_button->TabIndex = 11;
			this->save_time_button->Text = L"Set";
			this->save_time_button->UseVisualStyleBackColor = false;
			this->save_time_button->Click += gcnew System::EventHandler(this, &BoardForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(58, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 25);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Time control";
			// 
			// time_options_box
			// 
			this->time_options_box->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->time_options_box->ForeColor = System::Drawing::SystemColors::WindowText;
			this->time_options_box->FormattingEnabled = true;
			this->time_options_box->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Real time", L"Unlimited" });
			this->time_options_box->Location = System::Drawing::Point(175, 16);
			this->time_options_box->Name = L"time_options_box";
			this->time_options_box->Size = System::Drawing::Size(131, 28);
			this->time_options_box->TabIndex = 8;
			this->time_options_box->Text = L"Real time";
			// 
			// picturebox_board
			// 
			this->picturebox_board->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->picturebox_board->BackColor = System::Drawing::Color::Gray;
			this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg";
			this->picturebox_board->Location = System::Drawing::Point(21, 3);
			this->picturebox_board->Name = L"picturebox_board";
			this->picturebox_board->Size = System::Drawing::Size(654, 444);
			this->picturebox_board->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picturebox_board->TabIndex = 0;
			this->picturebox_board->TabStop = false;
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
			this->Name = L"BoardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BoardForm";
			this->board_panel->ResumeLayout(false);
			this->board_panel->PerformLayout();
			this->timeset_panel->ResumeLayout(false);
			this->timeset_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_minperside))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_secincrement))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->EndInit();
			this->chess_menu->ResumeLayout(false);
			this->chess_menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		//flip board
	   Point start_black = Point(565, 20);
	   Point start_white = Point(575, 203);

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
		label_blacktime->Visible = true;
		time_black->Visible = true;
		//white
		menu_timer_white->Enabled = true;
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
	}

	increment = trackbar_secincrement->Value;
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
};
}
