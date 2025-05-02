#include <iostream>
#include <string>
#include <fstream>
#include "Replacer.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)  {
        std::cerr
            << "Usage: " << argv[0]
            << " <filename> <search_string> <replace_string>"
            << std::endl;
        return 1;
    }
    const std::string infile = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];
    if (s1.empty()) {
        std::cerr << "Error: s1 is empty" << std::endl;
        return 1;
    }
    std::ifstream ifs(infile.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: could not open file to read" << infile << std::endl;
        return 1;
    }
    const std::string outfile = infile + ".replace";
    std::ofstream ofs(outfile.c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error: could not open file to write" << outfile << std::endl;
        return 1;
    }
    Replacer replacer(s1, s2);
    std::string line;
    while (std::getline(ifs, line)) {
        ofs << replacer.replaceInLine(line);
        if (!ifs.eof()) {
            ofs << std::endl;
        }
    }
    std::cout << "Created => " << outfile << " with " << s1 << " replaced by " << s2 << std::endl;
    return 0;
}