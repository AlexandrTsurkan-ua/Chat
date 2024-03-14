#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "ctype.h"
#include "User.h"
#include "message.h"
#include <stdlib.h>

int chekChoose(int&& a, int&& b); // функция проверки верности выбора пункта меню


string LoginCheck(vector < unique_ptr<User>>& VtrUser);//функция аутентификации пользователя


void MainMenu(); // Главное меню


void ChatMenu(); // Меню чата


void MessageMenu(); // Подменю чата: меню сообщений


void PrintRegUsers(vector < unique_ptr<User>>& VtrUser); // вывод на экран всех зарегистрированных пользователей

