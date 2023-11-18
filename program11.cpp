// Problem statement : Write an algorithm to encrypt the user input string using substitute cypher and return the encrypted string then decrypt the string and return it as well.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string secret_message;
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string key = "ZYXWVUTSRQPONMLJKIHGFEDCBAzyxwvutsrqponmlkjihgfedcba";
    char character = '\0';

    cout << "Enter your secret message : ";
    getline(cin, secret_message);

    cout << "\nEncrypting message..." << endl;

    string encrypted_message;

    for(char c : secret_message)
    {
        size_t position = alphabet.find(c);
        if(position != string::npos)
        {
            character = key.at(position);
            encrypted_message += character;
        }
        else
        {
            encrypted_message += c;
        }
    }

    cout << "\nEncrypted message is : " << encrypted_message << endl;

    cout << "\nDecrypting message..." << endl;

    string decrypted_message;

    for(char c : encrypted_message)
    {
        size_t position = key.find(c);
        if(position != string::npos)
        {
            character = alphabet.at(position);
            decrypted_message += character;
        }
        else
        {
            decrypted_message += c;
        }
    }

    cout << "\nDecrypted message is : " << decrypted_message << endl;

    return 0;
}