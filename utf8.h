#ifndef UTF8_H
#define UTF8_H

typedef struct{
    char* data;
} utf8_char;

typedef struct{
    char data[9];
} unicode_str;

unicode_str to_unicode_str(const utf8_char* utf_char);
utf8_char to_utf8_char(const unicode_str* str);

void test_to_utf8_char(char* str);

#endif