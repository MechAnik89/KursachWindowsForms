#include "MyForm.h"
#include "Header.h"
#include <algorithm>
#include <iterator>
#include <cctype>
#define MIN -999999
#define MAX 999999
//ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
using namespace System;
using namespace System::Windows::Forms;
const char Alfavit[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
std::string inputstr="", outputstr="";
std::string fileinput, fileoutput;
int key = 0;
std::string keyEnigma = "";
std::string keyvishz = "";
bool Check = false;
bool CheckOpVE = false;
bool CheckSuc = false;
bool CheckOpE = false;

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
	std::string CheckKey = "";
	CheckKey = Convert_String_to_string(textBox3->Text, CheckKey);

	if (input) {
		getline(input, inputstr);
	}
	else {
		MessageBox::Show("Один из файлов не найден!", "Ошибка!");
	}

	for (int i = 0; CheckKey.length() > i; i++) {

		if (isdigit(CheckKey[i])) {
			CheckOpE = true;
			CheckOpVE = false;

		}
		else {

			CheckOpVE = true;
			CheckOpE = false;

		}

	}


	if (textBox1->Text == "" || textBox2->Text == "") {
		MessageBox::Show("Введите название файлов!", "Ошибка!");
	}
	else {

		if (ShifrBox->SelectedIndex == 6) {

			MessageBox::Show("Выберите тип операции", "Ошибка!");

		}
		if (ShifrBox->SelectedIndex == 0 || ShifrBox->SelectedIndex == 3) {
			if (textBox3->Text != "" && CheckOpE == true) {
				key = System::Convert::ToInt32(textBox3->Text);
				Check = true;
			}
			else {
				MessageBox::Show("Ключ шифра Цезаря - это целое число!", "Ошибка!");
			}
		}
		if (ShifrBox->SelectedIndex == 1 || ShifrBox->SelectedIndex == 4) {
			if (textBox3->Text != "" && CheckOpVE==true) {
				keyvishz = Convert_String_to_string(textBox3->Text, keyvishz);
				Check = true;
			}
			else {
				MessageBox::Show("Ключ шифра Виженера - это символ/строка(только из букв)!", "Ошибка!");
			}
		}
		if (ShifrBox->SelectedIndex == 2 || ShifrBox->SelectedIndex == 5) {
			if (textBox3->Text != "" && CheckOpVE == true) {
				keyEnigma = Convert_String_to_string(textBox3->Text, keyEnigma);
				Check = true;
			}
		}
	}

	if (Check) {
		int size = inputstr.size();
		int shifrBoxIndex = ShifrBox->SelectedIndex;
		switch (shifrBoxIndex) {
		case 0:
			outputstr=Crypt_Caesar(inputstr, key);
			output << outputstr;
			CheckSuc = true;
			break;
		case 1:
			outputstr = Crypt_Vigenere(inputstr, keyvishz);
			output << outputstr;
			CheckSuc = true;
			break;
		case 2:
			for (int i = 0; i != inputstr.length();i++)
				inputstr[i] = toupper(inputstr[i]);
			for (int i = 0; i != keyEnigma.length(); i++)
				keyEnigma[i] = toupper(keyEnigma[i]);
			outputstr = Enigma(inputstr, keyEnigma);
			output << outputstr;
			CheckSuc = true;
			break;
		case 3:
			outputstr = Decrypt_Caesar(inputstr, key);
			output << outputstr;
			CheckSuc = true;
			break;
		case 4:
			outputstr = Decrypt_Vigenere(inputstr, keyvishz);
			output << outputstr;
			CheckSuc = true;
			break;
		case 5:
			for (int i = 0; i != inputstr.length(); i++)
				inputstr[i] = toupper(inputstr[i]);
			for (int i = 0; i != keyEnigma.length(); i++)
				keyEnigma[i] = toupper(keyEnigma[i]);
			outputstr = Enigma(inputstr, keyEnigma);
			output << outputstr;
			CheckSuc = true;
			break;
		default:
			MessageBox::Show("Вы не выбрали тип операции!", "Ошибка!");
			break;
		}
	}
	else {
		MessageBox::Show("Файлы не были считаны!", "Ошибка!");
	}
	if (CheckSuc) {
		MessageBox::Show("Результат записан в выходной файл!", "Успех!");
		CheckOpE = false;
		CheckOpVE = false;
		CheckSuc = false;
		Check = false;
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

System::Void Kursach::MyForm::кукуToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Для введения имени файлов введите названия входного и выходного файла в окна: \nInput File(входной файл)\nOutput File(выходной файл)\n\nВведите ключ в зависимости от нужного вам вида шифра в окно:\nInput Key(введите ключ)\n\nВыберите нужный вам вид шифра в выпадающем списке:\nOperation Type(тип операции)\n\nЗатем нажмите на кнопку Run(выполнить)\n\nДля очистки окон ввода имени файлов используйте кнопку Clear(очистить)\n\nДля перестановки файлов местами используйте кнопку под окном Input File(входной файл)\n\nПосле этого появится окно об успешном или же неуспешном выполнении программы!", "F.A.Q.");
}
