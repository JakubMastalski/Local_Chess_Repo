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
			this->board_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->BeginInit();
			this->SuspendLayout();
			// 
			// board_panel
			// 
			this->board_panel->Controls->Add(this->picturebox_board);
			this->board_panel->Location = System::Drawing::Point(138, 59);
			this->board_panel->Name = L"board_panel";
			this->board_panel->Size = System::Drawing::Size(448, 437);
			this->board_panel->TabIndex = 0;
			// 
			// picturebox_board
			// 
			this->picturebox_board->BackColor = System::Drawing::Color::Black;
			this->picturebox_board->Dock = System::Windows::Forms::DockStyle::Fill;
			this->picturebox_board->ImageLocation = L"C:\\Users\\USER\\Desktop\\Local_Chess_Repo\\img\\ChessBoard.jpg";
			this->picturebox_board->Location = System::Drawing::Point(0, 0);
			this->picturebox_board->Name = L"picturebox_board";
			this->picturebox_board->Size = System::Drawing::Size(448, 437);
			this->picturebox_board->TabIndex = 0;
			this->picturebox_board->TabStop = false;
			// 
			// BoardForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(808, 538);
			this->Controls->Add(this->board_panel);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ForeColor = System::Drawing::Color::White;
			this->Name = L"BoardForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BoardForm";
			this->board_panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
