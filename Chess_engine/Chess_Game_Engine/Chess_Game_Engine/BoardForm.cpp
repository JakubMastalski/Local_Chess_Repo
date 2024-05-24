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
	}

	BoardForm::~BoardForm()
	{
		if (components)
		{
			delete components;
		}
	}




};


