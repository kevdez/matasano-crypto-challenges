#include <iostream>
#include <string>

using namespace std;

// gets the numerical (0-15) value of a hex character (0-9, a-f)
int from_hex_to_decimal(char hex)
{
        if ('0' <= hex && hex <= '9')
                return hex - '0';
        if (hex >= 'A' && hex <= 'Z')
                return hex - 'A'  + 10;
        return hex - 'a' + 10;
}

string getStats(string s)
{
       cout << "Total characters: " << s.length() << endl;
      // get count of each char

}

int main(int args, char** argv)
{
        string s = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
        bool test = true;
        if(test)
        for(int i = 0; i < 128; i++)
        {
                char keyChar = i;
                string result1 = "";
                string result2 = "";

                for(int j = 0; j < s.length(); j++)
                {
                        int decimal = from_hex_to_decimal(s[j]);
                        char dec = decimal;
                        char resultChar1 = dec ^ keyChar;
                        char resultChar2 = s[j] ^ keyChar;
                        result1 += resultChar1;
                        result2 += resultChar2;
                }
                cout << i << ":\nresult 1:" << endl;
                cout << result1 << endl;
                cout << "result 2:" << endl;
                cout << result2 << endl;
                cout << s << endl;
                cout << endl;
        }
        return 0;
}
