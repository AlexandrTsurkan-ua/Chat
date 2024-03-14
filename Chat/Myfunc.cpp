#include "Myfunc.h"

int chekChoose(int&& a, int&& b) // ������� �������� �������� ������ ������ ����
{
    int i; //������� �����
    string str;// �������� ������
    do
    {
        i = 1;
        cout << "�������� ���� �����:" << endl;
        if (cin.peek() == '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        getline(cin, str);

        if (str.find_first_not_of("0123456789") != std::string::npos)
        {
            cout << "�������� ����� - ������� �����������. ���������� ��� ���!" << endl;
            cout << "\n\n" << endl;
            i = 0;
            continue;
        }

        if (stoi(str) < a || stoi(str) > b) // �������� ��������(1, 2 ��� 3), ���� int
        {
            cout << "�������� ����� - ����������� ������ ������ �������� ���!" << endl;
            cout << "�������� �������� � ��������� ����� " << a << " � " << b << ". ���������� ��� ���!" << endl;
            cout << "\n\n" << endl;
            i = 0;
        }
    } while (i == 0);
    return stoi(str); // ���������� � int � ������� int

}




string LoginCheck(vector < unique_ptr<User>>& VtrUser)//������� �������������� ������������
{
    int checkReg; // �������� ������������ �����
    string OnRegLogin; // ���������� ����� ��������� ������������
    do {
        checkReg = 1;
        cout << "\n" << endl;
        cout << "������� ���� �����:" << endl;
        string RegLogin; // ���� ������
        cin >> RegLogin;
        cout << "������� ���� ������:" << endl;
        string RegPass;  // ���� ������

        cin >> RegPass;

        const char* PassforHash = RegPass.c_str();

        uint* _Hash_Reg_Pass = sha1(PassforHash, sizeof(PassforHash) - 1);

        for (auto& Usr : VtrUser)
        {
            if (RegLogin == Usr->GetLoginUser() && *_Hash_Reg_Pass == *Usr->GetPassUser())
            {
                cout << "\n\n" << endl;
                cout << Usr->GetNameUser() << ", ������ ����!!" << endl;
                checkReg = 0;
                return OnRegLogin = Usr->GetLoginUser();
            }
        }
        if (checkReg == 1)
        {
            cout << "\n\n" << endl;
            cout << "�������� ���� ������ � ������." << endl;
            cout << "���� ������ ����������� ��� ���, ������� 1" << endl;
            cout << "���� ������ ��������� � ������� ����, ������� 0" << endl;
        }
        checkReg = chekChoose(0, 1);
    } while (checkReg != 0);
    return "No";

}



void MainMenu() // ������� ����
{
    cout << "\n\n" << endl;
    cout << "������� ����." << endl;
    cout << "\n" << endl;
    cout << "����� � ���, ���� �� ��� ����������������, ��������: 1" << endl;
    cout << "����������� ������ ������������, ��������: 2" << endl;
    cout << "��� ���������� ������ � ����������, ��������: 3" << endl;
    cout << endl;
}



void ChatMenu() // ���� ����
{
    cout << "\n\n" << endl;
    cout << "���� ����." << endl;
    cout << "\n" << endl;
    cout << "��� �������� ����� ���������, ��������: 1" << endl;
    cout << "�������� ���������, ��������: 2" << endl;
    cout << "����� ����� �� �������� � ������� � ������� ����, ��������: 3" << endl;
    cout << endl;
}



void MessageMenu() // ������� ����: ���� ���������
{
    cout << "\n\n" << endl;
    cout << "���� �������� ���������." << endl;
    cout << "\n" << endl;
    cout << "��� �������� <����>, ��������: 1" << endl;
    cout << "��� �������� ������������� ������������, ��������: 2" << endl;
    cout << "����� ����� �� ���� � ������� � ���� ����, ��������: 3" << endl;
    cout << endl;
}



void PrintRegUsers(vector < unique_ptr<User>>& VtrUser) // ����� �� ����� ���� ������������������ �������������
{
    cout << "\n\n" << endl;
    cout << "�������� ������������������ �������������:" << endl;

    for (size_t i = 1; i < VtrUser.size(); ++i) // �������� ���� � i = 1, �.�. 0 ������ � ������������ "All"
    {
        cout << "������������ � ������: " << VtrUser[i]->GetNameUser() << ", ����� " << VtrUser[i]->GetLoginUser() << ";" << endl;
    }
}