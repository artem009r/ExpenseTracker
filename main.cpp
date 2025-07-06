// main.cpp - Главный файл программы для системы учёта расходов и доходов

#include <iostream>
#include <string>
#include "user.h"

using namespace std;


int main() 
{
    cout << "=== Система учёта расходов и доходов ===\n";

    bool isRunning = true;
    while (isRunning) 
    {
        cout << "\nГлавное меню:\n";
        cout << "1. Вход\n";
        cout << "2. Регистрация\n";
        cout << "3. Выход\n";
        cout << "Выберите действие (1-3): ";

        int choice;
        cin >> choice;
        cin.ignore(); 

        switch (choice) 
        {
        case 1: {
            // Вход
            string login, password;
            cout << "Введите логин: ";
            getline(cin, login);
            cout << "Введите пароль: ";
            getline(cin, password);
            loginUser(login, password);
            break;
        }
        case 2: {
            // Регистрация
            string login, password;
            cout << "Введите логин: ";
            getline(cin, login);
            cout << "Введите пароль: ";
            getline(cin, password);
            registerUser(login, password);
            break;
        }
        case 3:
            cout << "До свидания!\n";
            isRunning = false;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }

    return 0;
}
