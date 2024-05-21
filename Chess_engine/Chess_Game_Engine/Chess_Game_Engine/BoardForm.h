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

	private: System::Windows::Forms::PictureBox^ white_bishopC;

	private: System::Windows::Forms::PictureBox^ white_pawnB;
	private: System::Windows::Forms::PictureBox^ white_pawnD;
	private: System::Windows::Forms::PictureBox^ white_rookH;




	private: System::Windows::Forms::PictureBox^ white_pawnF;
	private: System::Windows::Forms::PictureBox^ white_pawnH;
	private: System::Windows::Forms::PictureBox^ white_knightG;




	private: System::Windows::Forms::PictureBox^ white_bishopF;



	private: System::Windows::Forms::PictureBox^ white_king;
	private: System::Windows::Forms::PictureBox^ white_queen;
	private: System::Windows::Forms::PictureBox^ white_knightB;




	private: System::Windows::Forms::PictureBox^ white_pawnG;


	private: System::Windows::Forms::PictureBox^ white_pawnE;

	private: System::Windows::Forms::PictureBox^ white_pawnC;

	private: System::Windows::Forms::PictureBox^ white_rookA;






private: System::Windows::Forms::PictureBox^ black_pawnA;
private: System::Windows::Forms::PictureBox^ black_rookH;


private: System::Windows::Forms::PictureBox^ black_knightG;

private: System::Windows::Forms::PictureBox^ black_bishopF;

private: System::Windows::Forms::PictureBox^ black_king;

private: System::Windows::Forms::PictureBox^ black_queen;

private: System::Windows::Forms::PictureBox^ black_bishopC;

private: System::Windows::Forms::PictureBox^ black_knightB;

private: System::Windows::Forms::PictureBox^ black_rookA;

private: System::Windows::Forms::PictureBox^ black_pawnB;
private: System::Windows::Forms::PictureBox^ black_pawnH;


private: System::Windows::Forms::PictureBox^ black_pawnF;

private: System::Windows::Forms::PictureBox^ black_pawnD;
private: System::Windows::Forms::PictureBox^ black_pawnG;



private: System::Windows::Forms::PictureBox^ black_pawnE;

private: System::Windows::Forms::PictureBox^ black_pawnC;
private: System::Windows::Forms::PictureBox^ white_pawnA;
private: System::Windows::Forms::PictureBox^ picturebox_board;







































































































































































































































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
			this->white_rookA = (gcnew System::Windows::Forms::PictureBox());
			this->white_bishopC = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawnB = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawnD = (gcnew System::Windows::Forms::PictureBox());
			this->white_rookH = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawnF = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawnH = (gcnew System::Windows::Forms::PictureBox());
			this->white_knightG = (gcnew System::Windows::Forms::PictureBox());
			this->white_bishopF = (gcnew System::Windows::Forms::PictureBox());
			this->white_king = (gcnew System::Windows::Forms::PictureBox());
			this->white_queen = (gcnew System::Windows::Forms::PictureBox());
			this->white_knightB = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawnG = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawnE = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawnC = (gcnew System::Windows::Forms::PictureBox());
			this->time_white = (gcnew System::Windows::Forms::Label());
			this->label_whitetime = (gcnew System::Windows::Forms::Label());
			this->label_blacktime = (gcnew System::Windows::Forms::Label());
			this->time_black = (gcnew System::Windows::Forms::Label());
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
			this->chess_menu = (gcnew System::Windows::Forms::MenuStrip());
			this->flipBoardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->flipBoardToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setTimeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->restartToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menu_timer_black = (gcnew System::Windows::Forms::Timer(this->components));
			this->menu_timer_white = (gcnew System::Windows::Forms::Timer(this->components));
			this->black_pawnA = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawnC = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawnE = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawnG = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawnD = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawnF = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawnH = (gcnew System::Windows::Forms::PictureBox());
			this->black_pawnB = (gcnew System::Windows::Forms::PictureBox());
			this->black_rookA = (gcnew System::Windows::Forms::PictureBox());
			this->black_knightB = (gcnew System::Windows::Forms::PictureBox());
			this->black_bishopC = (gcnew System::Windows::Forms::PictureBox());
			this->black_queen = (gcnew System::Windows::Forms::PictureBox());
			this->black_king = (gcnew System::Windows::Forms::PictureBox());
			this->black_bishopF = (gcnew System::Windows::Forms::PictureBox());
			this->black_knightG = (gcnew System::Windows::Forms::PictureBox());
			this->black_rookH = (gcnew System::Windows::Forms::PictureBox());
			this->picturebox_board = (gcnew System::Windows::Forms::PictureBox());
			this->white_pawnA = (gcnew System::Windows::Forms::PictureBox());
			this->board_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_rookA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_bishopC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_rookH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnF))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_knightG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_bishopF))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_king))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_queen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_knightB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnC))->BeginInit();
			this->timeset_panel->SuspendLayout();
			this->increment_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_secincrement))->BeginInit();
			this->timeroptions_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackbar_minperside))->BeginInit();
			this->chess_menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnF))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_rookA))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_knightB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_bishopC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_queen))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_king))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_bishopF))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_knightG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_rookH))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnA))->BeginInit();
			this->SuspendLayout();
			// 
			// board_panel
			// 
			this->board_panel->Controls->Add(this->white_pawnA);
			this->board_panel->Controls->Add(this->black_rookH);
			this->board_panel->Controls->Add(this->timeset_panel);
			this->board_panel->Controls->Add(this->black_knightG);
			this->board_panel->Controls->Add(this->black_bishopF);
			this->board_panel->Controls->Add(this->black_king);
			this->board_panel->Controls->Add(this->black_queen);
			this->board_panel->Controls->Add(this->black_bishopC);
			this->board_panel->Controls->Add(this->black_knightB);
			this->board_panel->Controls->Add(this->black_rookA);
			this->board_panel->Controls->Add(this->black_pawnB);
			this->board_panel->Controls->Add(this->black_pawnH);
			this->board_panel->Controls->Add(this->black_pawnF);
			this->board_panel->Controls->Add(this->black_pawnD);
			this->board_panel->Controls->Add(this->black_pawnG);
			this->board_panel->Controls->Add(this->black_pawnE);
			this->board_panel->Controls->Add(this->black_pawnC);
			this->board_panel->Controls->Add(this->black_pawnA);
			this->board_panel->Controls->Add(this->white_rookA);
			this->board_panel->Controls->Add(this->white_bishopC);
			this->board_panel->Controls->Add(this->white_pawnB);
			this->board_panel->Controls->Add(this->white_pawnD);
			this->board_panel->Controls->Add(this->white_rookH);
			this->board_panel->Controls->Add(this->white_pawnF);
			this->board_panel->Controls->Add(this->white_pawnH);
			this->board_panel->Controls->Add(this->white_knightG);
			this->board_panel->Controls->Add(this->white_bishopF);
			this->board_panel->Controls->Add(this->white_king);
			this->board_panel->Controls->Add(this->white_queen);
			this->board_panel->Controls->Add(this->white_knightB);
			this->board_panel->Controls->Add(this->white_pawnG);
			this->board_panel->Controls->Add(this->white_pawnE);
			this->board_panel->Controls->Add(this->white_pawnC);
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
			// white_rookA
			// 
			this->white_rookA->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_rookA.Image")));
			this->white_rookA->Location = System::Drawing::Point(127, 411);
			this->white_rookA->Name = L"white_rookA";
			this->white_rookA->Size = System::Drawing::Size(45, 49);
			this->white_rookA->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_rookA->TabIndex = 22;
			this->white_rookA->TabStop = false;
			// 
			// white_bishopC
			// 
			this->white_bishopC->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_bishopC.Image")));
			this->white_bishopC->Location = System::Drawing::Point(238, 411);
			this->white_bishopC->Name = L"white_bishopC";
			this->white_bishopC->Size = System::Drawing::Size(49, 49);
			this->white_bishopC->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_bishopC->TabIndex = 21;
			this->white_bishopC->TabStop = false;
			// 
			// white_pawnB
			// 
			this->white_pawnB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawnB.Image")));
			this->white_pawnB->Location = System::Drawing::Point(183, 352);
			this->white_pawnB->Name = L"white_pawnB";
			this->white_pawnB->Size = System::Drawing::Size(45, 49);
			this->white_pawnB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_pawnB->TabIndex = 20;
			this->white_pawnB->TabStop = false;
			// 
			// white_pawnD
			// 
			this->white_pawnD->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawnD.Image")));
			this->white_pawnD->Location = System::Drawing::Point(297, 352);
			this->white_pawnD->Name = L"white_pawnD";
			this->white_pawnD->Size = System::Drawing::Size(45, 49);
			this->white_pawnD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_pawnD->TabIndex = 19;
			this->white_pawnD->TabStop = false;
			// 
			// white_rookH
			// 
			this->white_rookH->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_rookH.Image")));
			this->white_rookH->Location = System::Drawing::Point(521, 411);
			this->white_rookH->Name = L"white_rookH";
			this->white_rookH->Size = System::Drawing::Size(45, 48);
			this->white_rookH->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_rookH->TabIndex = 18;
			this->white_rookH->TabStop = false;
			// 
			// white_pawnF
			// 
			this->white_pawnF->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawnF.Image")));
			this->white_pawnF->Location = System::Drawing::Point(410, 352);
			this->white_pawnF->Name = L"white_pawnF";
			this->white_pawnF->Size = System::Drawing::Size(45, 49);
			this->white_pawnF->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_pawnF->TabIndex = 17;
			this->white_pawnF->TabStop = false;
			// 
			// white_pawnH
			// 
			this->white_pawnH->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawnH.Image")));
			this->white_pawnH->Location = System::Drawing::Point(521, 352);
			this->white_pawnH->Name = L"white_pawnH";
			this->white_pawnH->Size = System::Drawing::Size(45, 49);
			this->white_pawnH->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_pawnH->TabIndex = 16;
			this->white_pawnH->TabStop = false;
			// 
			// white_knightG
			// 
			this->white_knightG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_knightG.Image")));
			this->white_knightG->Location = System::Drawing::Point(466, 411);
			this->white_knightG->Name = L"white_knightG";
			this->white_knightG->Size = System::Drawing::Size(49, 48);
			this->white_knightG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_knightG->TabIndex = 15;
			this->white_knightG->TabStop = false;
			// 
			// white_bishopF
			// 
			this->white_bishopF->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_bishopF.Image")));
			this->white_bishopF->Location = System::Drawing::Point(410, 411);
			this->white_bishopF->Name = L"white_bishopF";
			this->white_bishopF->Size = System::Drawing::Size(49, 49);
			this->white_bishopF->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_bishopF->TabIndex = 14;
			this->white_bishopF->TabStop = false;
			// 
			// white_king
			// 
			this->white_king->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_king.Image")));
			this->white_king->Location = System::Drawing::Point(354, 411);
			this->white_king->Name = L"white_king";
			this->white_king->Size = System::Drawing::Size(47, 48);
			this->white_king->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_king->TabIndex = 13;
			this->white_king->TabStop = false;
			// 
			// white_queen
			// 
			this->white_queen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_queen.Image")));
			this->white_queen->Location = System::Drawing::Point(297, 411);
			this->white_queen->Name = L"white_queen";
			this->white_queen->Size = System::Drawing::Size(50, 49);
			this->white_queen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_queen->TabIndex = 12;
			this->white_queen->TabStop = false;
			// 
			// white_knightB
			// 
			this->white_knightB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_knightB.Image")));
			this->white_knightB->Location = System::Drawing::Point(183, 411);
			this->white_knightB->Name = L"white_knightB";
			this->white_knightB->Size = System::Drawing::Size(48, 48);
			this->white_knightB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_knightB->TabIndex = 11;
			this->white_knightB->TabStop = false;
			// 
			// white_pawnG
			// 
			this->white_pawnG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawnG.Image")));
			this->white_pawnG->Location = System::Drawing::Point(470, 352);
			this->white_pawnG->Name = L"white_pawnG";
			this->white_pawnG->Size = System::Drawing::Size(45, 49);
			this->white_pawnG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_pawnG->TabIndex = 10;
			this->white_pawnG->TabStop = false;
			// 
			// white_pawnE
			// 
			this->white_pawnE->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawnE.Image")));
			this->white_pawnE->Location = System::Drawing::Point(354, 352);
			this->white_pawnE->Name = L"white_pawnE";
			this->white_pawnE->Size = System::Drawing::Size(45, 49);
			this->white_pawnE->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_pawnE->TabIndex = 9;
			this->white_pawnE->TabStop = false;
			// 
			// white_pawnC
			// 
			this->white_pawnC->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawnC.Image")));
			this->white_pawnC->Location = System::Drawing::Point(238, 352);
			this->white_pawnC->Name = L"white_pawnC";
			this->white_pawnC->Size = System::Drawing::Size(45, 49);
			this->white_pawnC->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_pawnC->TabIndex = 8;
			this->white_pawnC->TabStop = false;
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
			this->timeset_panel->Location = System::Drawing::Point(204, 122);
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
			this->flipBoardToolStripMenuItem1->Size = System::Drawing::Size(224, 34);
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
			this->setTimeToolStripMenuItem->Size = System::Drawing::Size(224, 34);
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
			this->restartToolStripMenuItem1->Size = System::Drawing::Size(224, 34);
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
			this->exitToolStripMenuItem->Size = System::Drawing::Size(224, 34);
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
			// black_pawnA
			// 
			this->black_pawnA->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawnA.Image")));
			this->black_pawnA->Location = System::Drawing::Point(123, 67);
			this->black_pawnA->Name = L"black_pawnA";
			this->black_pawnA->Size = System::Drawing::Size(45, 49);
			this->black_pawnA->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_pawnA->TabIndex = 24;
			this->black_pawnA->TabStop = false;
			// 
			// black_pawnC
			// 
			this->black_pawnC->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawnC.Image")));
			this->black_pawnC->Location = System::Drawing::Point(238, 67);
			this->black_pawnC->Name = L"black_pawnC";
			this->black_pawnC->Size = System::Drawing::Size(45, 49);
			this->black_pawnC->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_pawnC->TabIndex = 25;
			this->black_pawnC->TabStop = false;
			// 
			// black_pawnE
			// 
			this->black_pawnE->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawnE.Image")));
			this->black_pawnE->Location = System::Drawing::Point(356, 67);
			this->black_pawnE->Name = L"black_pawnE";
			this->black_pawnE->Size = System::Drawing::Size(45, 49);
			this->black_pawnE->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_pawnE->TabIndex = 26;
			this->black_pawnE->TabStop = false;
			// 
			// black_pawnG
			// 
			this->black_pawnG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawnG.Image")));
			this->black_pawnG->Location = System::Drawing::Point(470, 67);
			this->black_pawnG->Name = L"black_pawnG";
			this->black_pawnG->Size = System::Drawing::Size(45, 49);
			this->black_pawnG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_pawnG->TabIndex = 27;
			this->black_pawnG->TabStop = false;
			// 
			// black_pawnD
			// 
			this->black_pawnD->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawnD.Image")));
			this->black_pawnD->Location = System::Drawing::Point(297, 67);
			this->black_pawnD->Name = L"black_pawnD";
			this->black_pawnD->Size = System::Drawing::Size(45, 49);
			this->black_pawnD->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_pawnD->TabIndex = 28;
			this->black_pawnD->TabStop = false;
			// 
			// black_pawnF
			// 
			this->black_pawnF->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawnF.Image")));
			this->black_pawnF->Location = System::Drawing::Point(410, 67);
			this->black_pawnF->Name = L"black_pawnF";
			this->black_pawnF->Size = System::Drawing::Size(45, 49);
			this->black_pawnF->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_pawnF->TabIndex = 29;
			this->black_pawnF->TabStop = false;
			// 
			// black_pawnH
			// 
			this->black_pawnH->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawnH.Image")));
			this->black_pawnH->Location = System::Drawing::Point(521, 67);
			this->black_pawnH->Name = L"black_pawnH";
			this->black_pawnH->Size = System::Drawing::Size(45, 49);
			this->black_pawnH->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_pawnH->TabIndex = 30;
			this->black_pawnH->TabStop = false;
			// 
			// black_pawnB
			// 
			this->black_pawnB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_pawnB.Image")));
			this->black_pawnB->Location = System::Drawing::Point(183, 67);
			this->black_pawnB->Name = L"black_pawnB";
			this->black_pawnB->Size = System::Drawing::Size(45, 49);
			this->black_pawnB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_pawnB->TabIndex = 31;
			this->black_pawnB->TabStop = false;
			// 
			// black_rookA
			// 
			this->black_rookA->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_rookA.Image")));
			this->black_rookA->Location = System::Drawing::Point(123, 12);
			this->black_rookA->Name = L"black_rookA";
			this->black_rookA->Size = System::Drawing::Size(45, 49);
			this->black_rookA->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_rookA->TabIndex = 32;
			this->black_rookA->TabStop = false;
			// 
			// black_knightB
			// 
			this->black_knightB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_knightB.Image")));
			this->black_knightB->Location = System::Drawing::Point(183, 12);
			this->black_knightB->Name = L"black_knightB";
			this->black_knightB->Size = System::Drawing::Size(48, 48);
			this->black_knightB->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_knightB->TabIndex = 33;
			this->black_knightB->TabStop = false;
			// 
			// black_bishopC
			// 
			this->black_bishopC->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_bishopC.Image")));
			this->black_bishopC->Location = System::Drawing::Point(242, 12);
			this->black_bishopC->Name = L"black_bishopC";
			this->black_bishopC->Size = System::Drawing::Size(49, 49);
			this->black_bishopC->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_bishopC->TabIndex = 34;
			this->black_bishopC->TabStop = false;
			// 
			// black_queen
			// 
			this->black_queen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_queen.Image")));
			this->black_queen->Location = System::Drawing::Point(297, 12);
			this->black_queen->Name = L"black_queen";
			this->black_queen->Size = System::Drawing::Size(50, 49);
			this->black_queen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_queen->TabIndex = 35;
			this->black_queen->TabStop = false;
			// 
			// black_king
			// 
			this->black_king->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_king.Image")));
			this->black_king->Location = System::Drawing::Point(356, 12);
			this->black_king->Name = L"black_king";
			this->black_king->Size = System::Drawing::Size(47, 48);
			this->black_king->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_king->TabIndex = 36;
			this->black_king->TabStop = false;
			// 
			// black_bishopF
			// 
			this->black_bishopF->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_bishopF.Image")));
			this->black_bishopF->Location = System::Drawing::Point(410, 12);
			this->black_bishopF->Name = L"black_bishopF";
			this->black_bishopF->Size = System::Drawing::Size(49, 49);
			this->black_bishopF->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_bishopF->TabIndex = 37;
			this->black_bishopF->TabStop = false;
			// 
			// black_knightG
			// 
			this->black_knightG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_knightG.Image")));
			this->black_knightG->Location = System::Drawing::Point(466, 12);
			this->black_knightG->Name = L"black_knightG";
			this->black_knightG->Size = System::Drawing::Size(49, 48);
			this->black_knightG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_knightG->TabIndex = 38;
			this->black_knightG->TabStop = false;
			// 
			// black_rookH
			// 
			this->black_rookH->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"black_rookH.Image")));
			this->black_rookH->Location = System::Drawing::Point(521, 12);
			this->black_rookH->Name = L"black_rookH";
			this->black_rookH->Size = System::Drawing::Size(45, 48);
			this->black_rookH->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->black_rookH->TabIndex = 39;
			this->black_rookH->TabStop = false;
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
			// white_pawnA
			// 
			this->white_pawnA->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"white_pawnA.Image")));
			this->white_pawnA->Location = System::Drawing::Point(127, 352);
			this->white_pawnA->Name = L"white_pawnA";
			this->white_pawnA->Size = System::Drawing::Size(45, 49);
			this->white_pawnA->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->white_pawnA->TabIndex = 40;
			this->white_pawnA->TabStop = false;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_rookA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_bishopC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_rookH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnF))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_knightG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_bishopF))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_king))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_queen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_knightB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnC))->EndInit();
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnF))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_pawnB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_rookA))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_knightB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_bishopC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_queen))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_king))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_bishopF))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_knightG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->black_rookH))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturebox_board))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->white_pawnA))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
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
