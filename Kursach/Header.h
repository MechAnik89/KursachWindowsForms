#pragma once
#pragma warning(push)
#pragma warning(disable:4018)
#pragma warning(disable:6031)
#pragma warning(disable:6001)
#pragma warning(disable:6385)
#include <ctime>
#include <string>
#include <iostream>
#include <conio.h>
#include<fstream>
#include"MyForm.h"
void Crypt_Vigenere();
void Decrypt_Vigenere();
std::string Crypt_Caesar(std::string buff,int key);
std::string Decrypt_Caesar(std::string buff, int key);
void ReadFile(std::string filename);
//Конвертируем System::string ^ в std::string 
std::string Convert_String_to_string(System::String^ s, std::string& os);
//Конвертируем std::string в System::string ^
System::String^ Convert_string_to_String(std::string& os, System::String^ s);
#pragma warning(pop)