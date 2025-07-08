import std;
#include "basicsheader.h"

/* 
	Keywords are the reserved words that have special meanings in the C++ language. 
	They are the words that have special meaning in the language. C++ uses keywords for 
	specifying the components of the language, such as void, int, public, etc. They can't 
	be used for a variable name, function name or any other identifiers.
*/

// The total number of keywords in C++ are 93 up to C++ 23 specification

void keywordDemo(){

    std::vector<std::string> cpp_keywords = {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break",
        "case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const",
        "consteval", "constexpr", "constinit", "const_cast", "continue", "co_await", "co_return", "co_yield",
        "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit", "export",
        "extern", "false", "final", "float", "for", "friend", "goto", "if", "inline", "int", "long", "mutable",
        "namespace", "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private",
        "protected", "public", "register", "reinterpret_cast", "requires", "return", "short", "signed", "sizeof",
        "static", "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", "virtual", "void", "volatile",
        "wchar_t", "while", "xor", "xor_eq"
    };

    for (const auto &keywords : cpp_keywords){
        std::cout << keywords << std::endl;
    }

}