// user.cpp - Реализация функций для работы с пользователями

#include "user.h"
#include <fstream>
#include <iostream>

using namespace std;

// Проверка корректности логина и пароля (не пустые, без запятых)
bool isValidInput(const string& input) 
{
    if (input.empty()) 
    {
        cout << "Ошибка: Ввод не может быть пустым.\n";
        return false;
    }
    if (input.find(",") != string::npos) 
    {
        cout << "Ошибка: Логин и пароль не могут содержать запятые.\n";
        return false;
    }
    return true;
}


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
    if (!isValidInput(login) || !isValidInput(password)) 
    {
        return false;
    }

    if (userExists(login)) 
    {
        cout << "Ошибка: Логин уже занят. Попробуйте другой.\n";
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
    cout << "Регистрация успешна! Теперь вы можете войти.\n";
    return true;
}

User loginUser(const string& login, const string& password) 
{
    User emptyUser; 

    if (!isValidInput(login) || !isValidInput(password)) 
    {
        return emptyUser;
    }

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
                cout << "Вход успешен! Добро пожаловать, " << login << "!\n";
                return User{ login, password };
            }
        }
    }
    file.close();
    cout << "Ошибка: Неверный логин или пароль. Попробуйте снова.\n";
    return emptyUser;
}
