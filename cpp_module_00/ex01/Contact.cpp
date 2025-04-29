#include "Contact.hpp"

//Setters
void    Contact::setFirstName       (const  std::basic_string<char>& first)    {_firstName = first;}
void    Contact::setLastName        (const  std::basic_string<char>& last)    {_lastName = last;}
void    Contact::setNickName        (const  std::basic_string<char>& nick)    {_nickName = nick;}
void    Contact::setPhoneNumber     (const  std::basic_string<char>& pnum)    {_phoneNumber = pnum;}
void    Contact::setDarkestSecret   (const  std::basic_string<char>& secret)    {_darkestSecret= secret;}

//Getters
const   std::basic_string<char>&    Contact::getFirstName       ()  const   {return _firstName;}
const   std::basic_string<char>&    Contact::getLastName        ()  const   {return _lastName;}
const   std::basic_string<char>&    Contact::getNickName        ()  const   {return _nickName;}
const   std::basic_string<char>&    Contact::getPhoneNumber     ()  const   {return _phoneNumber;}
const   std::basic_string<char>&    Contact::getDarkestSecret   ()  const   {return _darkestSecret;}

bool    Contact::isComplete()  const   {
    return  !_firstName.empty()
        &&  !_lastName.empty()
        &&  !_nickName.empty()
        &&  !_phoneNumber.empty()
        &&  !_darkestSecret.empty();
}