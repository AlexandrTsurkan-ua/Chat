#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "sha1.h"

using namespace std;

class User
{
public:
    User(string const& NameUser, string const& LoginUser, string const& PassUser);
    User();
    ~User();// ����������
    //~User() = default;// ����������


    void NewUser(string& NameUser, string& LoginUser, string& PassUser);
    void SetNameUser(string NameUser); // ������ ����� ������������
    void SetLoginUser(string LoginUser); // ������ ������ ������������
    void SetPassUser(string PassUser); // ������ ������ ������������

    string GetNameUser() const; // ������ ����� ������������
    string GetLoginUser() const; // ������ ������ ������������
    uint* GetPassUser() const; // ������ ������ ������������

    User& operator++(); // ���������� ���-����������
    User& operator--(); // ���������� ���-����������

    User operator++(int); // ���������� ����-����������
    User operator--(int); // ���������� ����-����������
    User vector(); // ���������� �������
    User insert(User); // ���������� ������� � ������
    User size(User); // ���������� ������� �������




private:
    string _NameUser;
    string _LoginUser;
    uint* _Hash_PassUser;
};
