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
	/*�������� ����� ������
�������� ����� ��������
�������� ����� ������
���������� ����� ������
���������� ����� ��������
���������� ����� ������*/
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
	}
}
