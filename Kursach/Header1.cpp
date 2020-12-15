#pragma once
#pragma warning(push)
#pragma warning(disable:4018)
#pragma warning(disable:6031)
#pragma warning(disable:6001)
#pragma warning(disable:6385)
#include "Header.h"
#include "MyForm.h"
#include <ctime>
#include <string>
#include <iostream>
#include <conio.h>
#include<fstream>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
void Crypt_Vigenere() {

    string B, C, D = "";
    string A = "abcdefghijklmnopqrstuvwxyz"; //��� �������
    setlocale(LC_ALL, "Rus");
    cout << "������� �����: ";
    cin >> B;
    cout << "������� ����: ";
    cin >> C;
    int* F = new int[B.size()];
    int* G = new int[B.size()];
    int c = C.size(); //������ ������ ���������� ��� ��������
    int b = B.size();
    //������ �������. ���� ����� ��������� ����� ������, ���� ����� ����� �����
    if (b >= c)
    {
        for (int i = 0; i < (b / c); i++)
        {
            D = D + C; //���������� ����� ���������� �����. ���������� ���� �� ����� �����.
        }
        for (int j = 0; j < (b % c); j++)
        {
            D = D + C[j];
        }
    }
    else  //����� ���� ���� ������� �����, ����������� ���� �� ����� �����.
    {
        for (int s = 0; s < b; s++)
        {
            D = D + B[s];
        }
    }
    //cout << D << endl;
    for (int k = 0; k < b; k++)
    {
        for (int n = 0; n < 26; n++)
        {
            if (B[k] == A[n])
            {
                F[k] = n;
            }

            if (D[k] == A[n])
            {
                G[k] = n;
            } //����� �� ��� �������� ���������. ����� ����������� ����, ��� �� ���� ����� ����� �� �������� ����� � ������, � ����� ���� ���������� �� � ������

        }
    }

    int e = 0; //��� ����� ������� ��������. ����� ��� ���������� 26 �����, ��������� ��� �� �����, ������� � ������� ������
    for (int u = 0; u < b; u++)
    {
        e = ((F[u] + G[u]) % 26);
        B[u] = A[e];
    }

    cout << "������������� �����: " << B << endl;

}

void Decrypt_Vigenere() {

    string B, C, D = "";
    string A = "abcdefghijklmnopqrstuvwxyz"; //��� �������
    setlocale(LC_ALL, "Rus");
    cout << "������� �����: ";
    cin >> B;
    cout << "������� ����: ";
    cin >> C;
    int* F = new int[B.size()];
    int* G = new int[B.size()];
    int c = C.size(); //������ ������ ���������� ��� ��������
    int b = B.size();
    //������ �������. ���� ����� ��������� ����� ������, ���� ����� ����� �����
    if (b >= c)
    {
        for (int i = 0; i < (b / c); i++)
        {
            D = D + C; //���������� ����� ���������� �����. ���������� ���� �� ����� �����.
        }
        for (int j = 0; j < (b % c); j++)
        {
            D = D + C[j];
        }
    }
    else  //����� ���� ���� ������� �����, ����������� ���� �� ����� �����.
    {
        for (int s = 0; s < b; s++)
        {
            D = D + B[s];
        }
    }
    //cout << D << endl;
    for (int k = 0; k < b; k++)
    {
        for (int n = 0; n < 26; n++)
        {
            if (B[k] == A[n])
            {
                F[k] = n;
            }

            if (D[k] == A[n])
            {
                G[k] = n;
            } //����� �� ��� �������� ���������. ����� ����������� ����, ��� �� ���� ����� ����� �� �������� ����� � ������, � ����� ���� ���������� �� � ������

        }
    }

    int e = 0; //��� ����� ������� ��������. ����� ��� ���������� 26 �����, ��������� ��� �� �����, ������� � ������� ������

    for (int u = 0; u < b; u++)
    {
        e = ((F[u] - G[u]));
        if (e < 0)
            e += 26;
        B[u] = A[e];
    }
    cout << "������������� �����: " << B << endl;
}

string Crypt_Caesar(string buff, int key) {

    for (int i = 0; i < buff.length(); i++)
        buff[i] += key;
    return buff;

}

string Decrypt_Caesar(string buff, int key) {

    for (int i = 0; i < buff.length(); i++)
        buff[i] -= key;
    return buff;

}
std::string Convert_String_to_string(System::String^ s, std::string& os)
{
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    
    return os;
}
System::String^ Convert_string_to_String(std::string& os, System::String^ s)
{
    s = gcnew System::String(os.c_str());
    return s;
}
void ReadFiles(std::string fileinput, std::string fileoutput)
{
    ifstream input(fileinput);
    ifstream output(fileoutput);

    if (input || output){



    }
    else {

        MessageBox::Show("���� �� ������ �� ������!", "������!");

    }
}
#pragma warning(pop)