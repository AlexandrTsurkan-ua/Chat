#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Message
{
public:
    Message(string const& TextMessage, string const& LoginSender, string const& LoginReceiver);
    Message();
    ~Message() = default;// Деструктор

    Message& operator++(); // Перегрузка пре-инкремента
    Message& operator--(); // Перегрузка пре-декремента

    Message operator++(int); // Перегрузка пост-инкремента
    Message operator--(int); // Перегрузка пост-декремента

    Message vector(); // Перегрузка вектора
    Message insert(Message); // Перегрузка вставки в вектор
    Message size(Message); // Перегрузка размера вектора


    void NewMessage(string TextMessage, string LoginSender, string LoginReceiver);
    void SetTextMessage(string TextMessage); // сеттер текста сообщения
    void SetLoginSender(string LoginSender); // сеттер логина отправителя
    void SetLoginReceiver(string LoginReceiver); // сеттер логина получателя
    string GetTextMessage() const; // геттер текста сообщения
    string GetLoginSender() const; // геттер логина отправителя
    string GetLoginReceiver() const; // геттер логина получателя



private:
    string _TextMessage;
    string _LoginSender;
    string _LoginReceiver;

};


