#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact   {
private:
    std::basic_string<char> _firstName;
    std::basic_string<char> _lastName;
    std::basic_string<char> _nickName;
    std::basic_string<char> _phoneNumber;
    std::basic_string<char> _darkestSecret;
public:
    // Setters
    void    setFirstName        (const std::basic_string<char>& first);
    void    setLastName         (const std::basic_string<char>& last);
    void    setNickName         (const std::basic_string<char>& nick);
    void    setPhoneNumber      (const std::basic_string<char>& pnum);
    void    setDarkestSecret    (const std::basic_string<char>& secret);
    // Getters
    const   std::basic_string<char>& getFirstName       ()  const;
    const   std::basic_string<char>& getLastName        ()  const;
    const   std::basic_string<char>& getNickName        ()  const;
    const   std::basic_string<char>& getPhoneNumber     ()  const;
    const   std::basic_string<char>& getDarkestSecret   ()  const;

    // Utility
    bool    isComplete() const;
};

#endif