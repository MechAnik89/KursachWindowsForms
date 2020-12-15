#include "MyForm.h"
#include "Header.h"

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
	default:
		MessageBox::Show("Вы не выбрали тип операции!", "Ошибка!");
		break;
	}
}

System::Void Kursach::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	//if (textBox1->Text == "" || textBox2->Text == "") {

	//	MessageBox::Show("Введите название файла!", "Внимание!");

	//}
	//else {
	return System::Void();
	//	std::string fileinput,fileoutput;
	//	Convert_String_to_string(textBox1->Text, fileinput);
	//	Convert_String_to_string(textBox2->Text, fileoutput);

	//	MessageBox::Show("Вы ввели", "Успех!");

	//}
}