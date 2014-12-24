#include <iostream>
#include <sstream>
#include <string>

using namespace std;
typedef unsigned char byte;

static const string base64_chars = 
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz"
  "0123456789+/";

// gets the numerical (0-15) value of a hex character (0-9, a-f)
int from_hex_to_decimal(char hex)
{
  if ('0' <= hex && hex <= '9')
      return hex - '0';
  if (hex >= 'A' && hex <= 'Z')
      return hex - 'A'  + 10;
  return hex - 'a' + 10;
}

// given 2 bytes where only each bottom 4 bits matter(the numbers from 0 to 15, from hex):
//   b1 = WWWW XXXX (binary)
//   b2 = YYYY ZZZZ (binary)
// it returns either:
//   base64_chars[XXXXZZ] (all X's + first 2 Z's)
//   or     
//   base64_chars[XXZZZZ] (first 2 X's + all Z's)
//      where XXXXZZ or XXZZZZ are a binary value (from 0 to 63)
char from_byte_to_base64(byte b1, byte b2, bool halfByteOnEnd)
{
  if(halfByteOnEnd)
    return base64_chars[((b1 << 2) | ((b2 & 0x0C) >> 2))];
  else
    return base64_chars[((b1 & 0x03) << 4) | b2];
}

string from_hex_to_base64(string s){
  stringstream result;
  for(int i = 0; i+5 < s.length(); i+=6)
  {
    byte c0 = from_hex_to_decimal(s[i]);
    byte c1 = from_hex_to_decimal(s[i+1]);
    byte c2 = from_hex_to_decimal(s[i+2]);
    byte c3 = from_hex_to_decimal(s[i+3]);
    byte c4 = from_hex_to_decimal(s[i+4]);
    byte c5 = from_hex_to_decimal(s[i+5]);

    char a = from_byte_to_base64(c0, c1, true);
    char b = from_byte_to_base64(c1, c2, false);
    // notice how there's no (c2, c3)
    char c = from_byte_to_base64(c3, c4, true);
    char d = from_byte_to_base64(c4, c5, false);
    result <<  a << b << c << d;
  }
  return result.str();
}

int main()
{
  string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  string base64String = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  cout << "Challenge 1: Hex to Base64" << endl
    << "hex:\t" << hexString << endl
    << "base64:\t" << base64String << endl
    << endl
    << "result:\t" << from_hex_to_base64(hexString) << endl;
  return 0;
}

