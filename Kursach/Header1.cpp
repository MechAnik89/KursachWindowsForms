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
    string A = "abcdefghijklmnopqrstuvwxyz"; //наш алфавит
    setlocale(LC_ALL, "Rus");
    cout << "Введите слово: ";
    cin >> B;
    cout << "Введите ключ: ";
    cin >> C;
    int* F = new int[B.size()];
    int* G = new int[B.size()];
    int c = C.size(); //делаем замену переменных для удобства
    int b = B.size();
    //Первое условие. Если длина вводимого слова больше, либо равна длине ключа
    if (b >= c)
    {
        for (int i = 0; i < (b / c); i++)
        {
            D = D + C; //Записываем целое количество ключа. Растягивая ключ по длине слова.
        }
        for (int j = 0; j < (b % c); j++)
        {
            D = D + C[j];
        }
    }
    else  //Иначе если ключ длиннее слова, укорачиваем ключ до длины слова.
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
            } //Здесь мы уже начинаем шифровать. Смысл заключается втом, что мы ищем номер буквы во вводимом ключе и номере, а после чего записываем их в массив

        }
    }

    int e = 0; //Для суммы номеров символов. Чтобы при достижении 26 буквы, программа шла по кругу, начиная с первого номера
    for (int u = 0; u < b; u++)
    {
        e = ((F[u] + G[u]) % 26);
        B[u] = A[e];
    }

    cout << "Зашифрованное слово: " << B << endl;

}

void Decrypt_Vigenere() {

    string B, C, D = "";
    string A = "abcdefghijklmnopqrstuvwxyz"; //наш алфавит
    setlocale(LC_ALL, "Rus");
    cout << "Введите слово: ";
    cin >> B;
    cout << "Введите ключ: ";
    cin >> C;
    int* F = new int[B.size()];
    int* G = new int[B.size()];
    int c = C.size(); //делаем замену переменных для удобства
    int b = B.size();
    //Первое условие. Если длина вводимого слова больше, либо равна длине ключа
    if (b >= c)
    {
        for (int i = 0; i < (b / c); i++)
        {
            D = D + C; //Записываем целое количество ключа. Растягивая ключ по длине слова.
        }
        for (int j = 0; j < (b % c); j++)
        {
            D = D + C[j];
        }
    }
    else  //Иначе если ключ длиннее слова, укорачиваем ключ до длины слова.
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
            } //Здесь мы уже начинаем шифровать. Смысл заключается втом, что мы ищем номер буквы во вводимом ключе и номере, а после чего записываем их в массив

        }
    }

    int e = 0; //Для суммы номеров символов. Чтобы при достижении 26 буквы, программа шла по кругу, начиная с первого номера

    for (int u = 0; u < b; u++)
    {
        e = ((F[u] - G[u]));
        if (e < 0)
            e += 26;
        B[u] = A[e];
    }
    cout << "Зашифрованное слово: " << B << endl;
}

void Crypt_Caesar() {

    int key = 0;
    cout << "Введите ключ" << endl;
    cin >> key;
    char* buff = new char;
    cout << "Введите сообщение,которое будет закодированно" << endl;
    cin >> buff;

    for (int i = 0; i < strlen(buff); i++)
        buff[i] += key;
    cout << buff << endl;

}

void Decrypt_Caesar() {


    int key = 0;
    cout << "Введите ключ" << endl;
    cin >> key;
    char* buff = new char;
    cout << "Введите сообщение,которое будет расшифрованно" << endl;
    cin >> buff;

    cout << "Decode: " << endl;
    for (int i = 0; i < strlen(buff); i++)
        buff[i] -= key;
    cout << buff << endl;

}
void ReadFile(std::string filename)
{
    ifstream inputfile(filename);

    if (inputfile) {

        MessageBox::Show("Файл прочитан!", "Успех!");

    }
    else {
        MessageBox::Show("Такого файла не существует!","Ошибка!");
    }

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
#pragma warning(pop)