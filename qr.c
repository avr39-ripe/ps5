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


	return 0;
}

void encode_char(const char character, bool bits[8])
{

	return;
}

char decode_byte(const bool bits[8])
{
	return 'A';
}
