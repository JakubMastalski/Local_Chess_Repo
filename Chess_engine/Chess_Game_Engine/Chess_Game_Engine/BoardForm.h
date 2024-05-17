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
	private: System::Windows::Forms::ToolStripMenuItem^ setTimeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ flipBoardToolStripMenuItem;
















	protected:

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->board_panel = (gcnew System::Windows::Forms::Panel());
			this->time_white = (gcnew System::Windows::Forms::Label());
			this->time_black = (gcnew System::Windows::Forms::Label());
			this->label_whitetime = (gcnew System::Windows::Forms::Label());
			this->label_blacktime = (gcnew System::Windows::Forms::Label());
			this->picturebox_board = (gcnew System::Windows::Forms::PictureBox());
			this->chess_menu = (gcnew System::Windows::Forms::MenuStrip());
			this->setTimeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipBoardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->board_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->BeginInit();
			this->chess_menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// board_panel
			// 
			this->board_panel->Controls->Add(this->time_white);
			this->board_panel->Controls->Add(this->time_black);
			this->board_panel->Controls->Add(this->label_whitetime);
			this->board_panel->Controls->Add(this->label_blacktime);
			this->board_panel->Controls->Add(this->picturebox_board);
			this->board_panel->Location = System::Drawing::Point(89, 56);
			this->board_panel->Name = L"board_panel";
			this->board_panel->Size = System::Drawing::Size(698, 411);
			this->board_panel->TabIndex = 0;
			// 
			// time_white
			// 
			this->time_white->AutoSize = true;
			this->time_white->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(5)));
			this->time_white->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->time_white->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->time_white->Location = System::Drawing::Point(565, 257);
			this->time_white->Name = L"time_white";
			this->time_white->Size = System::Drawing::Size(126, 59);
			this->time_white->TabIndex = 4;
			this->time_white->Text = L"00:00";
			this->time_white->Visible = false;
			// 
			// time_black
			// 
			this->time_black->AutoSize = true;
			this->time_black->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(5)));
			this->time_black->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->time_black->Font = (gcnew System::Drawing::Font(L"Segoe UI", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->time_black->Location = System::Drawing::Point(565, 70);
			this->time_black->Name = L"time_black";
			this->time_black->Size = System::Drawing::Size(126, 59);
			this->time_black->TabIndex = 5;
			this->time_black->Text = L"00:00";
			this->time_black->Visible = false;
			// 
			// label_whitetime
			// 
			this->label_whitetime->AutoSize = true;
			this->label_whitetime->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(5)),
				static_cast<System::Int32>(static_cast<System::Byte>(5)));
			this->label_whitetime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_whitetime->Font = (gcnew System::Drawing::Font(L"Georgia", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_whitetime->Location = System::Drawing::Point(565, 203);
			this->label_whitetime->Name = L"label_whitetime";
			this->label_whitetime->Size = System::Drawing::Size(103, 35);
			this->label_whitetime->TabIndex = 3;
			this->label_whitetime->Text = L" White";
			// 
			// label_blacktime
			// 
			this->label_blacktime->AutoSize = true;
			this->label_blacktime->BackColor = System::Drawing::Color::Black;
			this->label_blacktime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_blacktime->Font = (gcnew System::Drawing::Font(L"Georgia", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_blacktime->Location = System::Drawing::Point(565, 20);
			this->label_blacktime->Name = L"label_blacktime";
			this->label_blacktime->Size = System::Drawing::Size(89, 35);
			this->label_blacktime->TabIndex = 2;
			this->label_blacktime->Text = L"Black";
			// 
			// picturebox_board
			// 
			this->picturebox_board->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->picturebox_board->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(7)),
				static_cast<System::Int32>(static_cast<System::Byte>(7)));
			this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard1.jpg";
			this->picturebox_board->Location = System::Drawing::Point(3, 0);
			this->picturebox_board->Name = L"picturebox_board";
			this->picturebox_board->Size = System::Drawing::Size(672, 411);
			this->picturebox_board->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picturebox_board->TabIndex = 0;
			this->picturebox_board->TabStop = false;
			// 
			// chess_menu
			// 
			this->chess_menu->BackColor = System::Drawing::Color::Black;
			this->chess_menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->chess_menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->setTimeToolStripMenuItem,
					this->flipBoardToolStripMenuItem
			});
			this->chess_menu->Location = System::Drawing::Point(0, 0);
			this->chess_menu->Name = L"chess_menu";
			this->chess_menu->Size = System::Drawing::Size(828, 36);
			this->chess_menu->TabIndex = 2;
			this->chess_menu->Text = L"menuStrip1";
			// 
			// setTimeToolStripMenuItem
			// 
			this->setTimeToolStripMenuItem->BackColor = System::Drawing::Color::Black;
			this->setTimeToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->setTimeToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->setTimeToolStripMenuItem->Name = L"setTimeToolStripMenuItem";
			this->setTimeToolStripMenuItem->Size = System::Drawing::Size(98, 32);
			this->setTimeToolStripMenuItem->Text = L"Set time";
			// 
			// flipBoardToolStripMenuItem
			// 
			this->flipBoardToolStripMenuItem->BackColor = System::Drawing::Color::Black;
			this->flipBoardToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->flipBoardToolStripMenuItem->ForeColor = System::Drawing::Color::White;
			this->flipBoardToolStripMenuItem->Name = L"flipBoardToolStripMenuItem";
			this->flipBoardToolStripMenuItem->Size = System::Drawing::Size(116, 32);
			this->flipBoardToolStripMenuItem->Text = L"Flip board";
			this->flipBoardToolStripMenuItem->Click += gcnew System::EventHandler(this, &BoardForm::flipBoardToolStripMenuItem_Click);
			// 
			// BoardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(828, 538);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->EndInit();
			this->chess_menu->ResumeLayout(false);
			this->chess_menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		Point start_black = Point(565, 20);
		Point start_white = Point(575, 203);

private: System::Void flipBoardToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
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
};
}
