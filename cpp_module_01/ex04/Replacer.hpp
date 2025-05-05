#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>

class Replacer {
public:
    Replacer(const std::string& s1, const std::string& s2);
    std::string  replaceInLine(const std::string& line) const;
private:
    std::string  _s1;
    std::string  _s2;
};

#endif