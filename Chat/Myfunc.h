#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "ctype.h"
#include "User.h"
#include "message.h"
#include <stdlib.h>

int chekChoose(int&& a, int&& b); // ������� �������� �������� ������ ������ ����


string LoginCheck(vector < unique_ptr<User>>& VtrUser);//������� �������������� ������������


void MainMenu(); // ������� ����


void ChatMenu(); // ���� ����


void MessageMenu(); // ������� ����: ���� ���������


void PrintRegUsers(vector < unique_ptr<User>>& VtrUser); // ����� �� ����� ���� ������������������ �������������

