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
	private: System::Windows::Forms::Label^ label_onmove;

	private: System::Windows::Forms::Label^ label_blacktime;
	private: System::Windows::Forms::Label^ label_whitetime;


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
			this->picturebox_board = (gcnew System::Windows::Forms::PictureBox());
			this->label_onmove = (gcnew System::Windows::Forms::Label());
			this->label_blacktime = (gcnew System::Windows::Forms::Label());
			this->label_whitetime = (gcnew System::Windows::Forms::Label());
			this->board_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->BeginInit();
			this->SuspendLayout();
			// 
			// board_panel
			// 
			this->board_panel->Controls->Add(this->label_whitetime);
			this->board_panel->Controls->Add(this->label_blacktime);
			this->board_panel->Controls->Add(this->picturebox_board);
			this->board_panel->Location = System::Drawing::Point(89, 56);
			this->board_panel->Name = L"board_panel";
			this->board_panel->Size = System::Drawing::Size(672, 411);
			this->board_panel->TabIndex = 0;
			// 
			// picturebox_board
			// 
			this->picturebox_board->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(7)), static_cast<System::Int32>(static_cast<System::Byte>(7)),
				static_cast<System::Int32>(static_cast<System::Byte>(7)));
			this->picturebox_board->Dock = System::Windows::Forms::DockStyle::Fill;
			this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard.jpg";
			this->picturebox_board->Location = System::Drawing::Point(0, 0);
			this->picturebox_board->Name = L"picturebox_board";
			this->picturebox_board->Size = System::Drawing::Size(672, 411);
			this->picturebox_board->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->picturebox_board->TabIndex = 0;
			this->picturebox_board->TabStop = false;
			// 
			// label_onmove
			// 
			this->label_onmove->AutoSize = true;
			this->label_onmove->BackColor = System::Drawing::Color::Black;
			this->label_onmove->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_onmove->Font = (gcnew System::Drawing::Font(L"Georgia", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_onmove->Location = System::Drawing::Point(301, 21);
			this->label_onmove->Name = L"label_onmove";
			this->label_onmove->Size = System::Drawing::Size(232, 32);
			this->label_onmove->TabIndex = 1;
			this->label_onmove->Text = L"White on Move";
			// 
			// label_blacktime
			// 
			this->label_blacktime->AutoSize = true;
			this->label_blacktime->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->label_blacktime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_blacktime->Font = (gcnew System::Drawing::Font(L"Georgia", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_blacktime->Location = System::Drawing::Point(565, 20);
			this->label_blacktime->Name = L"label_blacktime";
			this->label_blacktime->Size = System::Drawing::Size(89, 35);
			this->label_blacktime->TabIndex = 2;
			this->label_blacktime->Text = L"Black";
			// 
			// label_whitetime
			// 
			this->label_whitetime->AutoSize = true;
			this->label_whitetime->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->label_whitetime->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_whitetime->Font = (gcnew System::Drawing::Font(L"Georgia", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label_whitetime->Location = System::Drawing::Point(565, 206);
			this->label_whitetime->Name = L"label_whitetime";
			this->label_whitetime->Size = System::Drawing::Size(103, 35);
			this->label_whitetime->TabIndex = 3;
			this->label_whitetime->Text = L" White";
			// 
			// BoardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(894, 606);
			this->Controls->Add(this->label_onmove);
			this->Controls->Add(this->board_panel);
			this->Font = (gcnew System::Drawing::Font(L"Georgia", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ForeColor = System::Drawing::Color::White;
			this->Name = L"BoardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BoardForm";
			this->board_panel->ResumeLayout(false);
			this->board_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
