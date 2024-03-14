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
    ~User();// Деструктор
    //~User() = default;// Деструктор


    void NewUser(string& NameUser, string& LoginUser, string& PassUser);
    void SetNameUser(string NameUser); // сеттер имени пользователя
    void SetLoginUser(string LoginUser); // сеттер логина пользователя
    void SetPassUser(string PassUser); // сеттер пароля пользователя

    string GetNameUser() const; // геттер имени пользователя
    string GetLoginUser() const; // геттер логина пользователя
    uint* GetPassUser() const; // геттер пароля пользователя

    User& operator++(); // Перегрузка пре-инкремента
    User& operator--(); // Перегрузка пре-декремента

    User operator++(int); // Перегрузка пост-инкремента
    User operator--(int); // Перегрузка пост-декремента
    User vector(); // Перегрузка вектора
    User insert(User); // Перегрузка вставки в вектор
    User size(User); // Перегрузка размера вектора




private:
    string _NameUser;
    string _LoginUser;
    uint* _Hash_PassUser;
};
