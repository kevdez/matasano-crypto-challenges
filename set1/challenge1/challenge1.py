import sys

"""
	Matasano Set 1, Challenge 1: Hex to Base64 

	Implemented in Python 2.7.9
"""

base64 ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

def hex_to_decimal(hex):
	if ord('0') <= ord(hex) <= ord('9'):
		return ord(hex) - ord('0')
	elif ord('a') <= ord(hex) <= ord('f'):
		return ord(hex) - ord('a') + 10
	elif ord('A') <= ord(hex) <= ord('F'):
		return ord(hex) - ord('A') + 10
	else:
		return 0

def byte_to_base64(byte1, byte2, isHalfByteOnEnd):
	if isHalfByteOnEnd:
		return base64[(byte1 << 2) | ((byte2 & 0x0C) >> 2)]
	else:
		return base64[((byte1 & 0x03) << 4) | byte2]

def hex_to_base64(s1):
	result = ""
	for i in range(0, len(s1) - 5, 6):
		uno = hex_to_decimal(s1[i])
		dos = hex_to_decimal(s1[i + 1])
		tres = hex_to_decimal(s1[i + 2])
		quatro = hex_to_decimal(s1[i + 3])
		cinco = hex_to_decimal(s1[i + 4])
		seis = hex_to_decimal(s1[i + 5])

		c1 = byte_to_base64(uno, dos, True)	# uno + half of dos
		c2 = byte_to_base64(dos, tres, False) # half of dos + tres
		c3 = byte_to_base64(quatro, cinco, True) # quatro + half of cinco
		c4 = byte_to_base64(cinco, seis, False) # half of cinco + seis

		result += c1 + c2 + c3 + c4

	print result


def main():
	s1 = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
	s2 = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"
	hex_to_base64(s1)
	print s2

if __name__ == "__main__":
	main()