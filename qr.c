#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);

void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);

int main()
{
	// 1

	bool bits1[8];
	encode_char('A', bits1);
	for(int i = 0; i < 8; i++){
	    printf("%d", bits1[i]);
	}
	printf("\n");
	// prints: 01000001

	bool bits2[8] = {0,1,0,0,0,0,0,1};
	printf("%c\n", decode_byte(bits2));
	// prints: A

	// 2

	char* text = "Hello, how are you?";
	const int len = strlen(text);
	bool bytes1[len+1][8];
	encode_string(text, bytes1);
	for(int j = 0; j <= len; j++){
	    printf("%c: ", text[j]);
	    for(int i = 0; i < 8; i++){
	        printf("%d", bytes1[j][i]);
	    }
	    printf("\n");
	}
	// prints:
	// H: 01001000
	// e: 01100101
	// l: 01101100
	// l: 01101100
	// o: 01101111
	// ,: 00101100
	//  : 00100000
	// h: 01101000
	// o: 01101111
	// w: 01110111
	//  : 00100000
	// a: 01100001
	// r: 01110010
	// e: 01100101
	//  : 00100000
	// y: 01111001
	// o: 01101111
	// u: 01110101
	// ?: 00111111
	// : 00000000

	bool bytes2[7][8] = {
	    {0,1,0,0,1,0,0,0},
	    {0,1,1,0,0,1,0,1},
	    {0,1,1,0,1,1,0,0},
	    {0,1,1,0,1,1,0,0},
	    {0,1,1,0,1,1,1,1},
	    {0,0,1,0,0,0,0,1},
	    {0,0,0,0,0,0,0,0}
	};
	char string[7];
	decode_bytes(7, bytes2, string);
	printf("%s\n", string);
	// prints: Hello!

	return 0;
}

void encode_char(const char character, bool bits[8])
{
	char mask = 0;
	for(int bit = 0; bit < 8; ++bit)
	{
		mask = 1 << bit;
		bits[7 - bit] = character & mask;
	}

	return;
}

char decode_byte(const bool bits[8])
{
	char character = '\0';

	for(int bit = 0; bit < 8; ++bit)
	{
		character |= (bits[7 - bit] << (bit));
	}

	return character;
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8])
{
	int str_pos = 0;
	for(; string[str_pos]; ++str_pos)
	{
		encode_char(string[str_pos], bytes[str_pos]);
	}
	encode_char(string[str_pos], bytes[str_pos]);

	return;
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
	int str_pos = 0;
	for(; str_pos < rows; ++str_pos)
	{
		string[str_pos] = decode_byte(bytes[str_pos]);
	}

	return;
}
