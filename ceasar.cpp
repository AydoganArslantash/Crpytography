#include <iostream>
using namespace std;
 

string encrypt(string text, int shift)
{
    string result = "";
 
    // traverse text
    for (int i = 0; i < text.length(); i++) {
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i] + shift - 65) % 26 + 65);
 
        // Encrypt Lowercase letters
        else
            result += char(int(text[i] + shift - 97) % 26 + 97);
    }
 

    return result;
}
 
int main()
{
    string text;
    int shift;

    cout << "Enter a text to encrypt(No Spaces!): ";
    cin >> text;

    cout << "Enter the shift(number): ";
    cin >> shift;

    cout << "Text : " << text;
    cout << "\nShift: " << shift;
    cout << "\nCipher: " << encrypt(text, shift);
    return 0;
}
