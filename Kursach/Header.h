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
void Crypt_Vigenere();
void Decrypt_Vigenere();
void Crypt_Caesar();
void Decrypt_Caesar();
void ReadFile(std::string filename);
//Конвертируем System::string ^ в std::string 
std::string Convert_String_to_string(System::String^ s, std::string& os);
//Конвертируем std::string в System::string ^
System::String^ Convert_string_to_String(std::string& os, System::String^ s);
#pragma warning(pop)