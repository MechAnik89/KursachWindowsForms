#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Kursach::MyForm form;
	Application::Run(% form);
}

System::Void Kursach::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	/*Шифратор шифра Цезаря
Шифратор шифра Виженера
Шифратор шифра Энигма
Дешифратор шифра Цезаря
Дешифратор шифра Виженера
Дешифратор шифра Энигма*/
	int shifrBoxIndex = ShifrBox->SelectedIndex;
	switch (shifrBoxIndex) {
	case 0:
	MessageBox::Show("Вы выбрали шифратор шифра Цезаря", "Проверка comboBox");
	break;
	case 1:
	MessageBox::Show("Вы выбрали шифратор шифра Виженера", "Проверка comboBox");
	break;
	case 2:
	MessageBox::Show("Вы выбрали шифратор шифра Энигмы", "Проверка comboBox");
	break;
	case 3:
	MessageBox::Show("Вы выбрали дешифратор шифра Цезаря", "Проверка comboBox");
	break; 
	case 4:
	MessageBox::Show("Вы выбрали дешифратор шифра Виженера", "Проверка comboBox");
	break; 
	case 5:
	MessageBox::Show("Вы выбрали дешифратор шифра Энигмы", "Проверка comboBox");
	break; 
	}
}
