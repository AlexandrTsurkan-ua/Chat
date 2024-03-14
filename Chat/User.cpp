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


void User::NewUser(string& NameUser, string& LoginUser, string& PassUser) // ������� �������� ������ ������������
{
    _NameUser = NameUser;
    _LoginUser = LoginUser;
    const char* PassforHash = PassUser.c_str();
    _Hash_PassUser = sha1(PassforHash, sizeof(PassforHash) - 1);

}


void User::SetNameUser(string NameUser) // ������ ����� ������������
{
    _NameUser = NameUser;
}


void User::SetLoginUser(string LoginUser) // ������ ������ ������������
{
    _LoginUser = LoginUser;
}


void User::SetPassUser(string PassUser) // ������ ������ ������������
{
    const char* PassforHash = PassUser.c_str();
    _Hash_PassUser = sha1(PassforHash, sizeof(PassforHash) - 1);
}


string User::GetNameUser() const // ������ ����� ������������
{
    return _NameUser;
}


string User::GetLoginUser() const // ������ ������ ������������
{
    return _LoginUser;
}


uint* User::GetPassUser() const // ������ ������ ������������
{
    return _Hash_PassUser;
}
