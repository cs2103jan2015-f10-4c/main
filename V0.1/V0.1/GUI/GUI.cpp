//@author generated
#include "GUI.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	GUI::MyForm mainWindow;
	Application::Run(%mainWindow);
}