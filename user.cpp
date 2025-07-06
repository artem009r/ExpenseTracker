// user.cpp - Реализация функций для работы с пользователями

#include "user.h"
#include <fstream>
#include <iostream>

using namespace std;

bool userExists(const string& login) 
{
    ifstream file("users.csv");
    string line;

    while (getline(file, line)) 
    {
        size_t commaPos = line.find(",");
        if (commaPos != string::npos) 
        {
            string existingLogin = line.substr(0, commaPos);
            if (existingLogin == login) 
            {
                file.close();
                return true;
            }
        }
    }
    file.close();
    return false;
}

bool registerUser(const string& login, const string& password) 
{
    if (userExists(login)) 
    {
        cout << "Ошибка: Логин уже занят.\n";
        return false;
    }

    ofstream file("users.csv", ios::app);
    if (!file.is_open()) 
    {
        cout << "Ошибка: Не удалось открыть файл users.csv.\n";
        return false;
    }

    file << login << "," << password << "\n";
    file.close();
    cout << "Регистрация успешна!\n";
    return true;
}

bool loginUser(const string& login, const string& password) 
{
    ifstream file("users.csv");
    string line;

    while (getline(file, line)) 
    {
        size_t commaPos = line.find(",");
        if (commaPos != string::npos) 
        {
            string existingLogin = line.substr(0, commaPos);
            string existingPassword = line.substr(commaPos + 1);
            if (existingLogin == login && existingPassword == password) 
            {
                file.close();
                cout << "Вход успешен!\n";
                return true;
            }
        }
    }
    file.close();
    cout << "Ошибка: Неверный логин или пароль.\n";
    return false;
}
