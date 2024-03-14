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

    string OnRegLogin; // записываем Логин вошедшего пользователя
    string NewestName; // переменные для ввода новых данных пользователя
    string NewestLogin;
    string NewestPass;
    string NewestMessageText; // переменная для ввода текста нового сообщения
    string NewestMessageSender;
    string NewestMessageReceiver;



    vector < unique_ptr<User>> VtrUser; // создаем вектор Пользователей
    VtrUser.reserve(100);
    VtrUser.emplace_back(make_unique<User>("admin", "All", "admin"));
    VtrUser.emplace_back(make_unique<User>("Alex", "AlexTs", "123456"));
    VtrUser.emplace_back(make_unique<User>("Anna", "AIvanova", "Anna21"));
    VtrUser.emplace_back(make_unique<User>("Max", "Max1982", "Kx12Q"));


    vector < unique_ptr<Message>>VtrMessage; // создаем вектор Сообщений
    VtrMessage.reserve(100);
    VtrMessage.emplace_back(make_unique<Message>("Hello!!", "All", "All"));
    VtrMessage.emplace_back(make_unique<Message>("Hello, Alex!!", "AIvanova", "AlexTs"));
    VtrMessage.emplace_back(make_unique<Message>("Hello, Anna!!", "Max1982", "AIvanova"));
    VtrMessage.emplace_back(make_unique<Message>("Hello, Max!!", "AlexTs", "Max1982"));




    int Y = 1; // счетчик цикла Главного меню
    cout << "Добрый день. Вас приветствует консольный чат!!!" << endl;
    do
    {
        PrintRegUsers(VtrUser);
        MainMenu(); // вывод главного меню

        int ChooseSelectMain = chekChoose(1, 3); // обьявляем и инициализируем через функцию переменную выбора пункта меню

        switch (ChooseSelectMain)
        {
        case 1: // п.1 Главного меню: Войти в чат, если Вы уже зарегистрированы
        {
            int Z = 1; // счетчик цикла Главного меню

            string ConfirmRegLogin;
            ConfirmRegLogin = LoginCheck(VtrUser); // вход и фиксация вошедшего!
            if (ConfirmRegLogin == "No") // если функция вернула "No" - возврат в головное меню!
            {
                continue;
            }
            do {
                ChatMenu(); // вывод меню чата
                int ChooseSelectChat = chekChoose(1, 3); // обьявляем и инициализируем через функцию переменную выбора пункта меню
                switch (ChooseSelectChat)
                {
                case 1: // п.1 Меню чата: проверка новых сообщений
                {
                    int checkMessage = 0;
                    for (auto& MessIt : VtrMessage)
                    {
                        if ((MessIt->GetLoginReceiver() == ConfirmRegLogin) || (MessIt->GetLoginReceiver() == "All"))
                        {
                            cout << "\n\n" << endl;
                            cout << "У Вас новое сообщение!!" << endl;
                            cout << "Отправитель: " << MessIt->GetLoginSender() << "." << endl;
                            cout << "Сообщение: " << MessIt->GetTextMessage() << "." << endl;
                            checkMessage = 1;
                            cout << "\n" << endl;
                            cout << "Ответить на сообщение? (да: введите 1; нет: введите 0)" << endl;
                            int checkAnswer = chekChoose(0, 1);
                            if (checkAnswer == 0)
                            {
                                continue;
                            }
                            else if (checkAnswer == 1)
                            {
                                cout << "Введите текст сообщения:" << endl;
                                cin >> NewestMessageText;
                                VtrMessage.emplace_back(make_unique<Message>(NewestMessageText, ConfirmRegLogin, MessIt->GetLoginSender()));
                            }
                        }
                    }
                    break;
                }
                case 2: // п.2 Меню чата: Написать сообщение
                {
                    int X = 1; // счетчик цикла меню сообщений
                    do
                    {
                        PrintRegUsers(VtrUser);
                        MessageMenu();
                        int ChooseSelectMessage = chekChoose(1, 3); // обьявляем и инициализируем через функцию переменную выбора пункта меню
                        switch (ChooseSelectMessage)
                        {
                        case 1: // п.1 Меню сообщений: отправка <Всем>
                        {
                            cout << "\n" << endl;
                            cout << "Введите текст сообщения:" << endl;
                            cin >> NewestMessageText;
                            VtrMessage.emplace_back(make_unique<Message>(NewestMessageText, ConfirmRegLogin, "All"));
                            break;
                        }
                        case 2: // п.1 Меню сообщений: отправка определенному пользователю
                        {
                            cout << "\n" << endl;
                            cout << "Введите текст сообщения:" << endl;
                            cin >> NewestMessageText;
                            cout << "Введите логин получателя сообщения:" << endl;
                            cin >> NewestMessageReceiver;
                            VtrMessage.emplace_back(make_unique<Message>(NewestMessageText, ConfirmRegLogin, NewestMessageReceiver));
                            break;
                        }
                        case 3: // п.1 Меню сообщений: выход в меню чата
                        {
                            X = 0;
                            break;
                        }
                        }

                    } while (X > 0);
                    break;
                }
                case 3: // п.3 Меню чата: Выход в главное меню
                {
                    Z = 0;
                    break;
                }
                }
            } while (Z > 0);
            break;
        }
        case 2: // п.2 Главного меню: Регистрация нового пользователя
        {
            cout << "При новой регистрации помните, что использовать логин All запрещено!!" << endl; // добавить регистрацию!!!

            int chekRegLog;
            do
            {
                chekRegLog = 0;
                cout << "Введите свое имя:" << endl;
                cin >> NewestName;
                cout << "Введите свой логин:" << endl;
                cin >> NewestLogin;
                cout << "Введите свой пароль:" << endl;
                cin >> NewestPass;
                for (auto& Usr : VtrUser) // проверка уникальности логина
                {
                    if (NewestLogin == Usr->GetLoginUser())
                    {
                        cout << "Этот логин занят!!" << endl;
                        chekRegLog = 1;
                    }
                }
            } while (chekRegLog > 0);

            VtrUser.emplace_back(make_unique<User>(NewestName, NewestLogin, NewestPass));

        }
        break;
        case 3: // п.3 Главного меню : Выход из программы
        {
            Y = 0;
            break;
        }
        }

    } while (Y > 0);
    cout << "До свидания!" << endl;
    return 0;
}
