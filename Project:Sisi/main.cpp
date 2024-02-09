#include <iostream>
#include <string>
#include <limits>
#include "CeasarCipher.cpp"
#include "VigenereCipher.cpp"

using namespace std;

int main() {
    string text, KEY;
    int SHIFT, usr_en_choice, usr_dec_choice, usr_EncryptOrDecrypt;

    cout << "Welcome to Project Sisi!\nHere you can either encrypt or decrypt messages.\nWhich operation would you like to do?\n";
    cout << "1. Encryption\n2. Decryption\n";
    cout << "Your choice: ";
    cin >> usr_EncryptOrDecrypt;

    while (usr_EncryptOrDecrypt != 1 && usr_EncryptOrDecrypt != 2) {
        cout << "Invalid choice. Please enter 1 for Encryption or 2 for Decryption: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> usr_EncryptOrDecrypt;
    }

    if (usr_EncryptOrDecrypt == 1) {  // FOR ENCRYPTION
        cout << "Enter a text to encrypt (No Spaces!): ";
        cin >> text;

        cout << "Choose your encryption method:\n";
        cout << "1. Caesar Cipher \n";
        cout << "2. Vigenere Cipher \n ";
        cout << "Your choice: ";
        cin >> usr_en_choice;

        while (usr_en_choice != 1 && usr_en_choice != 2) {
            cout << "Invalid choice. Please enter 1 for Caesar Cipher or 2 for Vigenere Cipher: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> usr_en_choice;
        }

        if (usr_en_choice == 1) {  // CEASAR CIPHER
            cout << "Enter the shift (number) for Caesar Cipher: ";
            cin >> SHIFT;
            CaesarCipher caesar;
            string caesarEncrypted = caesar.encrypt(text, SHIFT);
            cout << "Caesar Cipher (Encrypted text): " << caesarEncrypted << endl;
            cout << "Caesar Cipher (Decrypted text): " << caesar.decrypt(caesarEncrypted, SHIFT) << endl;
        } else if (usr_en_choice == 2) {  // VIGENERE CIPHER
            cout << "Enter the key for Vigenere Cipher: ";
            cin >> KEY;
            VigenereCipher vigenere(KEY);
            string vigenereEncrypted = vigenere.encrypt(text);
            cout << "Vigenere Cipher (Encrypted text): " << vigenereEncrypted << endl;
            cout << "Vigenere Cipher (Decrypted text): " << vigenere.decrypt(vigenereEncrypted) << endl;
        }
    } else if (usr_EncryptOrDecrypt == 2) {  // FOR DECRYPTION
        cout << "Enter a text to Decrypt (No Spaces!): ";
        cin >> text;

        cout << "Choose your decryption method:\n";
        cout << "1. Caesar Cipher \n";
        cout << "2. Vigenere Cipher \n ";
        cout << "Your choice: ";
        cin >> usr_dec_choice;

        while (usr_dec_choice != 1 && usr_dec_choice != 2) {
            cout << "Invalid choice. Please enter 1 for Caesar Cipher or 2 for Vigenere Cipher: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> usr_dec_choice;
        }

        if (usr_dec_choice == 1) {  // CEASAR CIPHER
            cout << "Enter the shift (number) for Caesar Cipher: ";
            cin >> SHIFT;
            CaesarCipher caesar;
            string caesarEncrypted = caesar.encrypt(text, SHIFT);
            cout << "Caesar Cipher (Decrypted text): " << caesarEncrypted << endl;
            cout << "Caesar Cipher (Encrypted text): " << caesar.decrypt(caesarEncrypted, SHIFT) << endl;
        } else if (usr_dec_choice == 2) {  // VIGENERE CIPHER
            cout << "Enter the key for Vigenere Cipher: ";
            cin >> KEY;
            VigenereCipher vigenere(KEY);
            string vigenereEncrypted = vigenere.encrypt(text);
            cout << "Vigenere Cipher (Decrypted text): " << vigenereEncrypted << endl;
            cout << "Vigenere Cipher (Encrypted text): " << vigenere.decrypt(vigenereEncrypted) << endl;
        }
    }

    return EXIT_SUCCESS;
}
