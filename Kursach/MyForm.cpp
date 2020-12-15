#include "MyForm.h"
#include "Header.h"

using namespace System;
using namespace System::Windows::Forms;

int key = 0;
bool Check = false;

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
	if (Check) {
		int shifrBoxIndex = ShifrBox->SelectedIndex;
		switch (shifrBoxIndex) {
		//case 0:
		//	outputstr=Crypt_Caesar(inputstr, key);
		//	output << outputstr;
		//	break;
		//case 1:
		//	outputstr = Decrypt_Caesar(inputstr, key);
		//	output << outputstr;
		//	break;
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
	else {
		MessageBox::Show("Файлы не были считаны!", "Ошибка!");
	}
}

System::Void Kursach::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (textBox1->Text == "" && textBox2->Text == "") {

		MessageBox::Show("Введите название файла!", "Внимание!");

	}
	else {
		
		if (textBox3->Text != "") {
			key = System::Convert::ToInt32(textBox3->Text);
		}
		else {
			MessageBox::Show("Заполните все поля!", "Ошибка!");
		}
		std::string inputstr, outputstr;
		std::string fileinput, fileoutput;
		std::ifstream input(fileinput);
		std::ofstream output(fileoutput);
		if (input) {
			
			input >> inputstr;
			MessageBox::Show("Файлы успешно считаны","Успех!");
			Check = true;

		}
		else {

			MessageBox::Show("Один из файлов не найден!", "Ошибка!");

		}
	}
}