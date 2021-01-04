#pragma once
#pragma warning(push)
#pragma warning(disable:4018)
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

char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char rotors[3][27] =
{
  "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
  "AJDKSIRUXBLHWTMCQGZNPYFVOE",
  "BDFHJLCPRTXVZNYEIWGAKMUSQO"
};
char reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
char key[] = "ABC";


long mod26(long a)
{
    return (a % 26 + 26) % 26;
}

int li(char l)
{
    // Letter index
    return l - 'A';
}

int indexof(char* array, int find)
{
    return strchr(array, find) - array;
}

string Enigma(const char* ct)
{
    // Sets initial permutation
    int L = li(key[0]);
    int M = li(key[1]);
    int R = li(key[2]);

    string output;

    for (int x = 0; x < strlen(ct); x++) {
        int ct_letter = li(ct[x]);

        // Step right rotor on every iteration
        R = mod26(R + 1);

        // Pass through rotors
        char a = rotors[2][mod26(R + ct_letter)];
        char b = rotors[1][mod26(M + li(a) - R)];
        char c = rotors[0][mod26(L + li(b) - M)];

        // Pass through reflector
        char ref = reflector[mod26(li(c) - L)];

        // Inverse rotor pass
        int d = mod26(indexof(rotors[0], alpha[mod26(li(ref) + L)]) - L);
        int e = mod26(indexof(rotors[1], alpha[mod26(d + M)]) - M);
        char f = alpha[mod26(indexof(rotors[2], alpha[mod26(e + R)]) - R)];

        output += f;
    }

    return output;
}
#pragma warning(pop)