#include <iostream>
#include <string>
using namespace std;

class CaesarCipher {
public:
    string encrypt(string text, int shift) {
        string result = "";

        for (char c : text) {
            if (isupper(c))
                result += char(int(c + shift - 'A') % 26 + 'A');
            else if (islower(c))
                result += char(int(c + shift - 'a') % 26 + 'a');
            else
                result += c;
        }

        return result;
    }

    string decrypt(string text, int shift) {
        return encrypt(text, 26 - shift);
    }
};
