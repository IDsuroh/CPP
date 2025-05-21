#include "Replacer.hpp"

Replacer::Replacer(const std::string& s1, const std::string& s2)
  : _s1(s1), _s2(s2)
{}

std::string Replacer::replaceInLine(const std::string& line) const {
    std::string out;
    size_t      pos = 0;

    while (true) {
        size_t found = line.find(_s1, pos);
        if (found == std::string::npos) {
            out.append(line, pos, std::string::npos);
            break;
        }
        out.append(line, pos, found - pos);
        out += _s2;
        pos = found + _s1.length();
    }

    return out;
}

/*

What is the difference of append and substr?
In one sentence

    append = glue more text onto the original string.

    substr = cut out a piece and get a new string containing just that piece.

*/