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

/*
std::ifstream ifs(infile.c_str());
if (!ifs.is_open()) {
    std::cerr << "Error: could not open file to read " << infile << std::endl;
    return 1;
}

const std::string outfile = infile + ".replace";
std::ofstream ofs(outfile.c_str());
if (!ofs.is_open()) {
    std::cerr << "Error: could not open file to write " << outfile << std::endl;
    return 1;
}
ifstream ifs opens infile for reading.

ofstream ofs opens a new file named "<infile>.replace" for writing.

Each gets checked—if opening fails, the program prints an error
and exits.

In C++, std::ifstream and std::ofstream are the two primary
file-stream classes you use for file I/O. They live in the
<fstream> header and are built on top of the lower-level
file-descriptor APIs, but give you the familiar C++ stream
interface (>>, <<, getline, etc.) plus automatic resource
management (RAII).
Inheritance: derives from std::istream → std::ios → std::ios_base.
Inheritance: derives from std::ostream → std::ios → std::ios_base.

*/