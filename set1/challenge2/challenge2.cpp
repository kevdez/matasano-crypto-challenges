#include <iostream>
#include <string>

using namespace std;
typedef unsigned char byte;

// gets the numerical (0-15) value of a hex character (0-9, a-f)
int from_hex_to_decimal(char hex)
{
  if ('0' <= hex && hex <= '9')
      return hex - '0';
  if (hex >= 'A' && hex <= 'Z')
      return hex - 'A'  + 10;
  return hex - 'a' + 10;
}

char from_decimal_to_hex(int decimal)
{
	switch (decimal)
	{
		case 0:
			return '0';
			break;
		case 1:
			return '1';
			break;
		case 2:
			return '2';
			break;
		case 3:
			return '3';
			break;
		case 4:
			return '4';
			break;
		case 5:
			return '5';
			break;
		case 6:
			return '6';
			break;
		case 7:
			return '7';
			break;
		case 8:
			return '8';
			break;
		case 9:
			return '9';
			break;
		case 10:
			return 'a';
			break;
		case 11:
			return 'b';
			break;
		case 12:
			return 'c';
			break;
		case 13:
			return 'd';
			break;
		case 14:
			return 'e';
			break;
		case 15:
			return 'f';
			break;
		default:
			return 'X';
			break;
	}
}

string fixedXOR(string s1, string s2)
{
	string result = "";

	if(s1.length() == s2.length())
	{
		for(int i = 0; i < s1.length(); i++)
		{
			int x = from_hex_to_decimal(s1[i]);
			int y = from_hex_to_decimal(s2[i]);
			
			int c = x ^ y; // ^ means XOR

			result += from_decimal_to_hex(c);
		}
	}

	return result;
}

int main()
{
	string s1 = "1c0111001f010100061a024b53535009181c";
	string s2 = "686974207468652062756c6c277320657965";

	string s3 = "746865206b696420646f6e277420706c6179";
	cout << "Expected result:\t" << s3 << endl;
	cout << "Actual result:\t\t" << fixedXOR(s1, s2) << endl;
	return 0;
}