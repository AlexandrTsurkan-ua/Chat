#include "User.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

User::User(string const& NameUser, string const& LoginUser, string const& PassUser)
{
    _NameUser = NameUser;
    _LoginUser = LoginUser;
    const char* PassforHash = PassUser.c_str();
    _Hash_PassUser = sha1(PassforHash, sizeof(PassforHash) - 1);
}


User::~User()
{
    delete _Hash_PassUser;
}


void User::NewUser(string& NameUser, string& LoginUser, string& PassUser) // вставка значений нового пользователя
{
    _NameUser = NameUser;
    _LoginUser = LoginUser;
    const char* PassforHash = PassUser.c_str();
    _Hash_PassUser = sha1(PassforHash, sizeof(PassforHash) - 1);

}


void User::SetNameUser(string NameUser) // сеттер имени пользователя
{
    _NameUser = NameUser;
}


void User::SetLoginUser(string LoginUser) // сеттер логина пользователя
{
    _LoginUser = LoginUser;
}


void User::SetPassUser(string PassUser) // сеттер пароля пользователя
{
    const char* PassforHash = PassUser.c_str();
    _Hash_PassUser = sha1(PassforHash, sizeof(PassforHash) - 1);
}


string User::GetNameUser() const // геттер имени пользователя
{
    return _NameUser;
}


string User::GetLoginUser() const // геттер логина пользователя
{
    return _LoginUser;
}


uint* User::GetPassUser() const // геттер пароля пользователя
{
    return _Hash_PassUser;
}
