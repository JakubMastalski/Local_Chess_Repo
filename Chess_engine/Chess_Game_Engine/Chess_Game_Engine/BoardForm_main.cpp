#include "BoardForm.h"


using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)

{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	ChessGameEngine::BoardForm form;
	Application::Run(% form);
}