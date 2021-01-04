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
std::string Crypt_Vigenere(std::string B,std::string C);
std::string Decrypt_Vigenere(std::string B, std::string C);
std::string Crypt_Caesar(std::string buff,int key);
std::string Decrypt_Caesar(std::string buff, int key);
//Конвертируем System::string ^ в std::string 
std::string Convert_String_to_string(System::String^ s, std::string& os);
std::string Enigma(const char* ct);
#pragma warning(pop)