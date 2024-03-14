#include "Myfunc.h"

int chekChoose(int&& a, int&& b) // функция проверки верности выбора пункта меню
{
    int i; //счетчик цикла
    string str;// вводимая строка
    do
    {
        i = 1;
        cout << "Сделайте свой выбор:" << endl;
        if (cin.peek() == '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        getline(cin, str);

        if (str.find_first_not_of("0123456789") != std::string::npos)
        {
            cout << "Неверный выбор - символы недопустимы. Попробуйте еще раз!" << endl;
            cout << "\n\n" << endl;
            i = 0;
            continue;
        }

        if (stoi(str) < a || stoi(str) > b) // проверка значений(1, 2 или 3), если int
        {
            cout << "Неверный выбор - возможности выбора такого значения нет!" << endl;
            cout << "Выберите значение в диапазоне между " << a << " и " << b << ". Попробуйте еще раз!" << endl;
            cout << "\n\n" << endl;
            i = 0;
        }
    } while (i == 0);
    return stoi(str); // приведение к int и возврат int

}




string LoginCheck(vector < unique_ptr<User>>& VtrUser)//функция аутентификации пользователя
{
    int checkReg; // проверка корректности входа
    string OnRegLogin; // записываем Логин вошедшего пользователя
    do {
        checkReg = 1;
        cout << "\n" << endl;
        cout << "Введите свой логин:" << endl;
        string RegLogin; // ввод логина
        cin >> RegLogin;
        cout << "Введите свой пароль:" << endl;
        string RegPass;  // ввод пароля

        cin >> RegPass;

        const char* PassforHash = RegPass.c_str();

        uint* _Hash_Reg_Pass = sha1(PassforHash, sizeof(PassforHash) - 1);

        for (auto& Usr : VtrUser)
        {
            if (RegLogin == Usr->GetLoginUser() && *_Hash_Reg_Pass == *Usr->GetPassUser())
            {
                cout << "\n\n" << endl;
                cout << Usr->GetNameUser() << ", добрый день!!" << endl;
                checkReg = 0;
                return OnRegLogin = Usr->GetLoginUser();
            }
        }
        if (checkReg == 1)
        {
            cout << "\n\n" << endl;
            cout << "Неверный ввод логина и пароля." << endl;
            cout << "Если хотите попробовать еще раз, введите 1" << endl;
            cout << "Если хотите вернуться в Главное меню, введите 0" << endl;
        }
        checkReg = chekChoose(0, 1);
    } while (checkReg != 0);
    return "No";

}



void MainMenu() // Главное меню
{
    cout << "\n\n" << endl;
    cout << "Главное меню." << endl;
    cout << "\n" << endl;
    cout << "Войти в чат, если Вы уже зарегистрированы, выберите: 1" << endl;
    cout << "Регистрация нового пользователя, выберите: 2" << endl;
    cout << "Для завершения работы с программой, выберите: 3" << endl;
    cout << endl;
}



void ChatMenu() // Меню чата
{
    cout << "\n\n" << endl;
    cout << "Меню чата." << endl;
    cout << "\n" << endl;
    cout << "Для проверки новых сообщений, выберите: 1" << endl;
    cout << "Написать сообщение, выберите: 2" << endl;
    cout << "Чтобы выйти из аккаунта и перейти в главное меню, выберите: 3" << endl;
    cout << endl;
}



void MessageMenu() // Подменю чата: меню сообщений
{
    cout << "\n\n" << endl;
    cout << "Меню отправки сообщений." << endl;
    cout << "\n" << endl;
    cout << "Для отправки <Всем>, выберите: 1" << endl;
    cout << "Для отправки определенному пользователю, выберите: 2" << endl;
    cout << "Чтобы выйти из меню и перейти в меню чата, выберите: 3" << endl;
    cout << endl;
}



void PrintRegUsers(vector < unique_ptr<User>>& VtrUser) // вывод на экран всех зарегистрированных пользователей
{
    cout << "\n\n" << endl;
    cout << "Перечень зарегистрированных пользователей:" << endl;

    for (size_t i = 1; i < VtrUser.size(); ++i) // начинаем цикл с i = 1, т.к. 0 индекс у пользователя "All"
    {
        cout << "Пользователь с именем: " << VtrUser[i]->GetNameUser() << ", логин " << VtrUser[i]->GetLoginUser() << ";" << endl;
    }
}