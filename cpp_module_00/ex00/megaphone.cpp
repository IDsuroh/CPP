#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;  
        return 0;
    }
    for (int i = 1; i < argc ; ++i) {
        std::basic_string<char> s = argv[i];
        std::basic_string<char>::size_type start = s.find_first_not_of(" \t");
        if (start == std::string::npos)
            s.clear();
        else {
            std::basic_string<char>::size_type end = s.find_last_not_of(" \t");
            s = s.substr(start, end - start + 1);
        }
        for (std::basic_string<char>::size_type j = 0; j < s.size(); ++j) {
            unsigned char   uc = static_cast<unsigned char>(s[j]);
            std::cout << static_cast<char>(std::toupper(uc));
        }
        if (i < argc - 1)
            std::cout << ' ';
    }
    std::cout << '\n';
    return 0;
}

/*
for (std::string::size_type j = 0; j < s.size(); ++j) { … }
– guarantees no signed/unsigned mix, no compiler warnings, and correct behavior even on extremely large strings.

whenever you need the raw numeric value of a byte—especially before calling functions like std::toupper
that expect an unsigned-char range—you cast explicitly to unsigned char:
    unsigned char uc = static_cast<unsigned char>(someChar);
This guarantees you get a 0…255 value, no surprises if plain char happened to be signed on your system.
*/