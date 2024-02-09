#include <iostream>
#include <string>
using namespace std;


class VigenereCipher {
private:
    string key;

public:
    VigenereCipher(string key) : key(key) {}

    string encrypt(string text) {
        string result = "";
        int keyLength = key.length();
        int j = 0;

        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int shift = key[j % keyLength] - 'a';
                result += char((c + shift - base) % 26 + base);
                j++;
            } else {
                result += c;
            }
        }

        return result;
    }

    string decrypt(string text) {
        string result = "";
        int keyLength = key.length();
        int j = 0;

        for (char c : text) {
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                int shift = key[j % keyLength] - 'a';
                result += char((c - shift - base + 26) % 26 + base);
                j++;
            } else {
                result += c;
            }
        }

        return result;
    }
};