#include "MyForm.h"
#include "Header.h"

using namespace System;
using namespace System::Windows::Forms;
std::string inputstr="", outputstr="";
std::string fileinput, fileoutput;
int key = 0;
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
		MessageBox::Show("������� �������� �����!", "��������!");
	}
	else {
		if (textBox3->Text != "" && (ShifrBox->SelectedIndex != 1 && ShifrBox->SelectedIndex != 4)) {
			key = System::Convert::ToInt32(textBox3->Text);
		}
		else if(textBox3->Text != "" && (ShifrBox->SelectedIndex == 1 || ShifrBox->SelectedIndex == 4)) {
			keyvishz = Convert_String_to_string(textBox3->Text, keyvishz);
		}
		else {
			MessageBox::Show("��������� ��� ����!", "������!");
		}

		if (input) {
			getline(input,inputstr);
			Check = true;
		}
		else {
			MessageBox::Show("���� �� ������ �� ������!", "������!");
		}
	}
	if (Check) {
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
			MessageBox::Show("�� ������� �������� ����� ������", "�������� comboBox");
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
			MessageBox::Show("�� ������� ���������� ����� ������", "�������� comboBox");
			break;
		default:
			MessageBox::Show("�� �� ������� ��� ��������!", "������!");
			break;
		}
	}
	else {
		MessageBox::Show("����� �� ���� �������!", "������!");
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
