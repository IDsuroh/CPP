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

Why std::basic_string<char>::size_type?
That’s the right unsigned type for string indices—no signed/unsigned mismatch, and it can represent very large strings.
It is a type alias (typedef) defined inside the std::basic_string template that tells you what integer type to use
for any string‐size or string‐index values.

    using size_type = typename Traits::size_type;

    where "Traits is std::char_traits<char>", "Traits::size_type" is itself an alias for "std::size_t".

    So is std::string::size_type always std::size_t?
    No, but almost always in every mainstream C++ standard‐library implementation.
    but the C++ Standard only mandates that it be an unsigned integral type large enough to represent any string’s length or position.
whenever you need the raw numeric value of a byte—especially before calling functions like std::toupper
that expect an unsigned-char range—you cast explicitly to unsigned char:

    unsigned char uc = static_cast<unsigned char>(someChar);

This guarantees you get a 0…255 value, no surprises if plain char happened to be signed on your system.
*/