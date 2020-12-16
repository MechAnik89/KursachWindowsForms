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
#include<cctype>
#include<fstream>
static const size_t npos = -1;
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
std::string Crypt_Vigenere(std::string text, std::string key) {
    string result = text;
    int i = 0;
    for (auto& c : result)
    {
        /*провер€ем буквы на нижний или верхний регистр*/
        if (islower(c))
        {
            c = (((c - 'a') + (key[i++ % key.size()] - 'a')) % 26) + 'a';
        }
        else if (isupper(c))
        {
            c = tolower(c);//реализовал это из-за того, что функци€ выше по непон€тным причинам не работала с большими буквами при замене а на ј
            c = (((c - 'a') + (key[i++ % key.size()] - 'a')) % 26) + 'a';
            c = toupper(c);
        }
    }
    return result;
}

string Decrypt_Vigenere(string str,string key) {
        string k = key;
        for (auto& c : k)
        {
            c = tolower(c) - 'a' - 1;
            c = 'z' - c;
        }
        return Crypt_Vigenere(str, k);
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
#pragma warning(pop)