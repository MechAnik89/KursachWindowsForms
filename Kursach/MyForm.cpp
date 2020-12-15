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
		MessageBox::Show("�� ������� �������� ����� ������", "�������� comboBox");
		break;
	case 1:
		MessageBox::Show("�� ������� �������� ����� ��������", "�������� comboBox");
		break;
	case 2:
		MessageBox::Show("�� ������� �������� ����� ������", "�������� comboBox");
		break;
	case 3:
		MessageBox::Show("�� ������� ���������� ����� ������", "�������� comboBox");
		break; 
	case 4:
		MessageBox::Show("�� ������� ���������� ����� ��������", "�������� comboBox");
		break; 
	case 5:
		MessageBox::Show("�� ������� ���������� ����� ������", "�������� comboBox");
		break; 
	default:
		MessageBox::Show("�� �� ������� ��� ��������!", "������!");
		break;
	}
}

System::Void Kursach::MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (textBox1->Text == "" && textBox2->Text == "") {

		MessageBox::Show("������� �������� �����!", "��������!");

	}
	else {
		std::string fileinput,fileoutput;
		std::string inputstr, outputstr;
		Convert_String_to_string(textBox1->Text, fileinput);
		Convert_String_to_string(textBox2->Text, fileoutput);
		if (textBox3->Text != "") {
			int key = System::Convert::ToInt32(textBox3->Text);
		}
		else {
			MessageBox::Show("��������� ��� ����!", "������!");
		}
		std::ifstream input(fileinput);
		std::ofstream output(fileoutput);

		if (input && output) {
			
			input >> inputstr;
			MessageBox::Show("����� ������� �������","�����!");

		}
		else {

			MessageBox::Show("���� �� ������ �� ������!", "������!");

		}
	}
}