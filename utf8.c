#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utf8.h"

#define MAX_1_BYTE 0x007F
#define MAX_2_BYTE 0x07FF
#define MAX_3_BYTE 0xFFFF
#define MAX_4_BYTE 0x10FFFF

/*
typedef struct{
    char* data;
} utf8_char;

typedef struct{
    char data[9];
} unicode_str;
 */

unicode_str to_unicode_str(const utf8_char* utf_char){

}

utf8_char to_utf8_char(const unicode_str* str){
    long hex_value = strtol(&str->data[2], NULL, 16);
    utf8_char utf_char;

    if (hex_value <= MAX_1_BYTE){
        utf_char.data = calloc(1, sizeof(char));
        utf_char.data[0] = (char)(hex_value & MAX_1_BYTE);
        return utf_char;
    }

    if (hex_value <= MAX_2_BYTE){
        utf_char.data = calloc(2, sizeof(char));

        utf_char.data[0] += (hex_value & 0x00000700) >> 6;
        utf_char.data[0] += (hex_value & 0x000000F0) >> 6;
        utf_char.data[1] += (hex_value & 0x000000F0);
        utf_char.data[1] += (hex_value & 0x0000000F);

        utf_char.data[0] |= 0xC0; // 1100 0000
        utf_char.data[0] &= 0xDF; // 1101 1111

        utf_char.data[1] |= 0x80;
        utf_char.data[1] &= 0xBF;

        return utf_char;
    }

    if (hex_value <= MAX_3_BYTE){
        utf_char.data = calloc(3, sizeof(char));

        utf_char.data[0] += (hex_value & 0x0000F000) >> 12;
        utf_char.data[1] += (hex_value & 0x00000F00) >> 6;
        utf_char.data[1] += (hex_value & 0x000000F0) >> 6;
        utf_char.data[2] += (hex_value & 0x000000F0);
        utf_char.data[2] += (hex_value & 0x0000000F);

        utf_char.data[0] |= 0xE0; // 1110 0000
        utf_char.data[0] &= 0xEF; // 1110 1111

        utf_char.data[1] |= 0x80;
        utf_char.data[1] &= 0xBF;

        utf_char.data[2] |= 0x80;
        utf_char.data[2] &= 0xBF;

        return utf_char;
    }

    if (hex_value <= MAX_4_BYTE){
        utf_char.data = calloc(4, sizeof(char));

        utf_char.data[0] += (hex_value & 0x00100000) >> 18;
        utf_char.data[0] += (hex_value & 0x000F0000) >> 18;
        utf_char.data[1] += (hex_value & 0x000F0000) >> 12;
        utf_char.data[1] += (hex_value & 0x0000F000) >> 12;
        utf_char.data[2] += (hex_value & 0x00000F00) >> 6;
        utf_char.data[2] += (hex_value & 0x000000F0) >> 6;
        utf_char.data[3] += (hex_value & 0x000000F0);
        utf_char.data[3] += (hex_value & 0x0000000F);

        utf_char.data[0] |= 0xF0; // 1111 0000
        utf_char.data[0] &= 0xF7; // 1111 0111

        utf_char.data[1] |= 0x80;
        utf_char.data[1] &= 0xBF;

        utf_char.data[2] |= 0x80;
        utf_char.data[2] &= 0xBF;

        utf_char.data[3] |= 0x80;
        utf_char.data[3] &= 0xBF;

        return utf_char;
    }

    return utf_char;
}

void test_to_utf8_char(char* str){
    unicode_str ustr;
    strcpy(ustr.data, str);
    utf8_char utf = to_utf8_char(&ustr);
    for (int i = 0; i < 4; i++){
        if (utf.data[i] != 0){
            printf("%02X ", (unsigned char)utf.data[i]);
        }
    }
    printf("\n");
}

/*
int main(){
    test_to_utf8_char("U+0000");   // NULL
    test_to_utf8_char("U+0041");   // 'A'
    test_to_utf8_char("U+007F");   // limite 1 byte

    test_to_utf8_char("U+0080");   // início 2 bytes
    test_to_utf8_char("U+00A9");   // ©
    test_to_utf8_char("U+07FF");   // limite 2 bytes

    test_to_utf8_char("U+0800");   // início 3 bytes
    test_to_utf8_char("U+20AC");   // €
    test_to_utf8_char("U+A013");   // seu caso
    test_to_utf8_char("U+FFFF");   // limite BMP

    test_to_utf8_char("U+10000");  // início 4 bytes
    test_to_utf8_char("U+1F600");  // 😀
    test_to_utf8_char("U+10FFFF"); // máximo Unicode
    return 0;
}
*/