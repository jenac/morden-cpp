#include <string>
void init_chars() {
    char utf8c = u8'a';
    // char utf8cc = u8'好';  does not fit utf 8?
    char16_t utf16c = u'好';
    char32_t utf32c = U'好';
    // char utf8[] = u8"师姐你好"; //error: ISO C++20 does not permit initialization of char array with UTF-8 string literal
    char8_t utf8[] = u8"师姐你好"; 
    char16_t utf16[] = u"师姐你好";
    char32_t utf32[] = U"师姐你好";
}

int main() {

}