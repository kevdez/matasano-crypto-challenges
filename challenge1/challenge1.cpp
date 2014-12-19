#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned char byte;

/*
 hex = 0 - F ( 0 to 16 )
 0xF8 =  1111  1000


 base64 = A - / ( 0 to 64)
*/


static const string base64_chars = 
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "abcdefghijklmnopqrstuvwxyz"
  "0123456789+/";

int from_hex_to_decimal(char hex) {
  if ('0' <= hex && hex <= '9')
  {
      return hex - '0';
  }
  if (hex >= 'A' && hex <= 'Z')
  {
      return hex - 'A'  + 10;
  }
  return hex - 'a' + 10;
}

char from_byte_to_base64(byte b1, byte b2, bool halfByteOnEnd)
{
  if(halfByteOnEnd)
  {
    byte b2Half = b2 & 0xF0;
    unsigned int result = b1 << 8;
    result = result | b2Half;
    return base64_chars[result];
  }
  else
  {
    byte b1Half = b1 & 0x0F;
    unsigned int result = b1Half << 8;
    result = result | b2;
    return base64_chars[result];
  }
}


string from_hex_to_base64(string s){
  string result = "";
  for(int i = 0; i < s.length(); i+6)
  {
    byte c0 = from_hex_to_decimal(s[i]);
    byte c1 = from_hex_to_decimal(s[i+1]);
    byte c2 = from_hex_to_decimal(s[i+2]);
    byte c3 = from_hex_to_decimal(s[i+3]);
    byte c4 = from_hex_to_decimal(s[i+4]);
    byte c5 = from_hex_to_decimal(s[i+5]);

    char a = from_byte_to_base64(c0, c1, true);
    char b = from_byte_to_base64(c1, c2, false);
    char c = from_byte_to_base64(c3, c4, true);
    char d = from_byte_to_base64(c4, c5, false);
    result += a + b + c + d;
  }
}

int main()
{
  string hexString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  string base64String = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
  char c = 'c';
  byte b = from_hex_to_decimal(c) | 0xC;
  cout << sizeof(c) << " " << c << " and b " << b << endl;
//  cout << from_hex_to_base64(hexString);
  return 0;
}

