#include <iostream>
#include <string>
#include <cstdlib>
#include "PhoneBook.hpp"

static std::basic_string<char>  promptField(const std::basic_string<char>& prompt)  {
    std::basic_string<char> input;
    while (true)    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return std::string();
        if (!input.empty())
            return input;
        std::cout << "  >> This field cannot be empty. Try again.\n";
    }
}

int main()  {
    PhoneBook   phonebook;
    std::basic_string<char> cmd;

    while (true)    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd) || cmd == "EXIT" || cmd == "exit")
            break ;
        if (cmd == "ADD" || cmd == "add")   {
            Contact c;
            c.setFirstName      (promptField("First Name: "));
            if (c.getFirstName().empty())   break ;
            c.setLastName       (promptField("Last Name: "));
            if (c.getLastName().empty())   break ;
            c.setNickName       (promptField("Nickname: "));
            if (c.getNickName().empty())   break ;
            c.setPhoneNumber    (promptField("Phone Number: "));
            if (c.getPhoneNumber().empty())   break ;
            c.setDarkestSecret  (promptField("Darkest Secret: "));
            if (c.getDarkestSecret().empty())   break ;
            if (c.isComplete())
                phonebook.add(c);
        }
        else if (cmd == "SEARCH" || cmd == "search")   {
            if (phonebook.size() == 0)  {
                std::cout << ">> PhoneBook is empty. \n";
                continue ;
            }
            while (true)    {
                phonebook.displayList();
                std::cout << "Enter index to view details (or press enter to cancel): ";
                std::basic_string<char> idxStr;
                if (!std::getline(std::cin, idxStr))    {
                    std::cout << "\nGoodbye\n";
                    return 0;
                }
                if (idxStr.empty())
                    break ;
                int idx = std::atoi(idxStr.c_str());
                if (idx < 1 || idx > phonebook.size())  {
                    std::cout << ">> Invalid index; please try again.\n";
                    continue ;
                }
                phonebook.displayContact(idx - 1);
                break ;
            }
        }
    }
    std::cout << "\nGoodbye!\n";
    return 0;
}