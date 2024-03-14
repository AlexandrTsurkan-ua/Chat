#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "ctype.h"
#include "User.h"
#include "message.h"
#include <stdlib.h>
#include "Myfunc.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "");

    string OnRegLogin; // ���������� ����� ��������� ������������
    string NewestName; // ���������� ��� ����� ����� ������ ������������
    string NewestLogin;
    string NewestPass;
    string NewestMessageText; // ���������� ��� ����� ������ ������ ���������
    string NewestMessageSender;
    string NewestMessageReceiver;



    vector < unique_ptr<User>> VtrUser; // ������� ������ �������������
    VtrUser.reserve(100);
    VtrUser.emplace_back(make_unique<User>("admin", "All", "admin"));
    VtrUser.emplace_back(make_unique<User>("Alex", "AlexTs", "123456"));
    VtrUser.emplace_back(make_unique<User>("Anna", "AIvanova", "Anna21"));
    VtrUser.emplace_back(make_unique<User>("Max", "Max1982", "Kx12Q"));


    vector < unique_ptr<Message>>VtrMessage; // ������� ������ ���������
    VtrMessage.reserve(100);
    VtrMessage.emplace_back(make_unique<Message>("Hello!!", "All", "All"));
    VtrMessage.emplace_back(make_unique<Message>("Hello, Alex!!", "AIvanova", "AlexTs"));
    VtrMessage.emplace_back(make_unique<Message>("Hello, Anna!!", "Max1982", "AIvanova"));
    VtrMessage.emplace_back(make_unique<Message>("Hello, Max!!", "AlexTs", "Max1982"));




    int Y = 1; // ������� ����� �������� ����
    cout << "������ ����. ��� ������������ ���������� ���!!!" << endl;
    do
    {
        PrintRegUsers(VtrUser);
        MainMenu(); // ����� �������� ����

        int ChooseSelectMain = chekChoose(1, 3); // ��������� � �������������� ����� ������� ���������� ������ ������ ����

        switch (ChooseSelectMain)
        {
        case 1: // �.1 �������� ����: ����� � ���, ���� �� ��� ����������������
        {
            int Z = 1; // ������� ����� �������� ����

            string ConfirmRegLogin;
            ConfirmRegLogin = LoginCheck(VtrUser); // ���� � �������� ���������!
            if (ConfirmRegLogin == "No") // ���� ������� ������� "No" - ������� � �������� ����!
            {
                continue;
            }
            do {
                ChatMenu(); // ����� ���� ����
                int ChooseSelectChat = chekChoose(1, 3); // ��������� � �������������� ����� ������� ���������� ������ ������ ����
                switch (ChooseSelectChat)
                {
                case 1: // �.1 ���� ����: �������� ����� ���������
                {
                    int checkMessage = 0;
                    for (auto& MessIt : VtrMessage)
                    {
                        if ((MessIt->GetLoginReceiver() == ConfirmRegLogin) || (MessIt->GetLoginReceiver() == "All"))
                        {
                            cout << "\n\n" << endl;
                            cout << "� ��� ����� ���������!!" << endl;
                            cout << "�����������: " << MessIt->GetLoginSender() << "." << endl;
                            cout << "���������: " << MessIt->GetTextMessage() << "." << endl;
                            checkMessage = 1;
                            cout << "\n" << endl;
                            cout << "�������� �� ���������? (��: ������� 1; ���: ������� 0)" << endl;
                            int checkAnswer = chekChoose(0, 1);
                            if (checkAnswer == 0)
                            {
                                continue;
                            }
                            else if (checkAnswer == 1)
                            {
                                cout << "������� ����� ���������:" << endl;
                                cin >> NewestMessageText;
                                VtrMessage.emplace_back(make_unique<Message>(NewestMessageText, ConfirmRegLogin, MessIt->GetLoginSender()));
                            }
                        }
                    }
                    break;
                }
                case 2: // �.2 ���� ����: �������� ���������
                {
                    int X = 1; // ������� ����� ���� ���������
                    do
                    {
                        PrintRegUsers(VtrUser);
                        MessageMenu();
                        int ChooseSelectMessage = chekChoose(1, 3); // ��������� � �������������� ����� ������� ���������� ������ ������ ����
                        switch (ChooseSelectMessage)
                        {
                        case 1: // �.1 ���� ���������: �������� <����>
                        {
                            cout << "\n" << endl;
                            cout << "������� ����� ���������:" << endl;
                            cin >> NewestMessageText;
                            VtrMessage.emplace_back(make_unique<Message>(NewestMessageText, ConfirmRegLogin, "All"));
                            break;
                        }
                        case 2: // �.1 ���� ���������: �������� ������������� ������������
                        {
                            cout << "\n" << endl;
                            cout << "������� ����� ���������:" << endl;
                            cin >> NewestMessageText;
                            cout << "������� ����� ���������� ���������:" << endl;
                            cin >> NewestMessageReceiver;
                            VtrMessage.emplace_back(make_unique<Message>(NewestMessageText, ConfirmRegLogin, NewestMessageReceiver));
                            break;
                        }
                        case 3: // �.1 ���� ���������: ����� � ���� ����
                        {
                            X = 0;
                            break;
                        }
                        }

                    } while (X > 0);
                    break;
                }
                case 3: // �.3 ���� ����: ����� � ������� ����
                {
                    Z = 0;
                    break;
                }
                }
            } while (Z > 0);
            break;
        }
        case 2: // �.2 �������� ����: ����������� ������ ������������
        {
            cout << "��� ����� ����������� �������, ��� ������������ ����� All ���������!!" << endl; // �������� �����������!!!

            int chekRegLog;
            do
            {
                chekRegLog = 0;
                cout << "������� ���� ���:" << endl;
                cin >> NewestName;
                cout << "������� ���� �����:" << endl;
                cin >> NewestLogin;
                cout << "������� ���� ������:" << endl;
                cin >> NewestPass;
                for (auto& Usr : VtrUser) // �������� ������������ ������
                {
                    if (NewestLogin == Usr->GetLoginUser())
                    {
                        cout << "���� ����� �����!!" << endl;
                        chekRegLog = 1;
                    }
                }
            } while (chekRegLog > 0);

            VtrUser.emplace_back(make_unique<User>(NewestName, NewestLogin, NewestPass));

        }
        break;
        case 3: // �.3 �������� ���� : ����� �� ���������
        {
            Y = 0;
            break;
        }
        }

    } while (Y > 0);
    cout << "�� ��������!" << endl;
    return 0;
}
