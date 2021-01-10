#include "MyForm.h"
#include "Header.h"
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace System;
using namespace System::Windows::Forms;
std::string inputstr="", outputstr="";
std::string fileinput, fileoutput;
int key = 0;
std::string keyEnigma = "";
std::string keyvishz = "";
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
	Convert_String_to_string(textBox1->Text, fileinput);
	Convert_String_to_string(textBox2->Text, fileoutput);
	std::ifstream input(fileinput);
	std::ofstream output(fileoutput);
	if (textBox1->Text == "" && textBox2->Text == "") {
		MessageBox::Show("Введите название файла!", "Внимание!");
	}
	else {
		if (textBox3->Text != "" && (ShifrBox->SelectedIndex == 1 || ShifrBox->SelectedIndex == 4)) {
			key = System::Convert::ToInt32(textBox3->Text);
		}
		else if (textBox3->Text != "" && (ShifrBox->SelectedIndex == 0 || ShifrBox->SelectedIndex == 3)) {
			keyvishz = Convert_String_to_string(textBox3->Text, keyvishz);
		}
		else if (textBox3->Text != "" && (ShifrBox->SelectedIndex == 2 || ShifrBox->SelectedIndex == 5)) {
			keyEnigma = Convert_String_to_string(textBox3->Text, keyEnigma);;
		}
		else {
			MessageBox::Show("Заполните все поля!", "Ошибка!");
		}

		if (input) {
			getline(input, inputstr);
			Check = true;
		}
		else {
			MessageBox::Show("Один из файлов не найден!", "Ошибка!");
		}
	}
	if (Check) {
		int size = inputstr.size();
		int shifrBoxIndex = ShifrBox->SelectedIndex;
		switch (shifrBoxIndex) {
		case 0:
			outputstr=Crypt_Caesar(inputstr, key);
			output << outputstr;
			break;
		case 1:
			outputstr = Crypt_Vigenere(inputstr, keyvishz);
			output << outputstr;
			break;
		case 2:
			//for (int i = 0; i < size; i++) {
			//	if (72 < (int)inputstr[i] < 99)
			//	{
			//		inputstr[i] = (int)inputstr[i] - 32;
			//	}
			//}
			outputstr = Enigma(inputstr, keyEnigma);
			output << outputstr;
			break;
		case 3:
			outputstr = Decrypt_Caesar(inputstr, key);
			output << outputstr;
			break;
		case 4:
			outputstr = Decrypt_Vigenere(inputstr, keyvishz);
			output << outputstr;
			break;
		case 5:
/*			for (int i = 0; i < size; i++) {
				if (72 < (int)inputstr[i] < 99)
				{
					inputstr[i] = (int)inputstr[i] - 32;
				}
			}	*/		
			outputstr = Enigma(inputstr, keyEnigma);
			output << outputstr;		
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
	if (textBox1->Text != "" && textBox2->Text != "") {

		textBox4->Text = textBox1->Text;
		textBox1->Text = textBox2->Text;
		textBox2->Text = textBox4->Text;

	}
}

System::Void Kursach::MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
}

System::Void Kursach::MyForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{

	textBox1->Text = "input.txt";
	textBox2->Text = "output.txt";

}
