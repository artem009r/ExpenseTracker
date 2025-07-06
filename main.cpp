// main.cpp - Главный файл программы для системы учёта расходов и доходов

#include <iostream>
#include <string>
#include "user.h"

using namespace std;

int main() 
{
    cout << "=== Система учёта расходов и доходов ===\n";

    User currentUser; 
    bool isLoggedIn = false;
    bool isRunning = true;

    while (isRunning) 
    {
        cout << "\nГлавное меню:\n";
        if (isLoggedIn) 
        {
            cout << "Вы вошли как: " << currentUser.login << "\n";
            cout << "1. Выход из аккаунта\n";
            cout << "2. Завершить программу\n";
        }
        else 
        {
            cout << "1. Вход\n";
            cout << "2. Регистрация\n";
            cout << "3. Выход\n";
        }
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (isLoggedIn) 
        {
            switch (choice) 
            {
            case 1:
                isLoggedIn = false;
                currentUser = User();
                cout << "Вы вышли из аккаунта.\n";
                break;
            case 2:
                cout << "До свидания!\n";
                isRunning = false;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
                break;
            }
        }
        else 
        {
            switch (choice) 
            {
            case 1: 
            {
                // Вход
                string login, password;
                cout << "Введите логин: ";
                getline(cin, login);
                cout << "Введите пароль: ";
                getline(cin, password);
                currentUser = loginUser(login, password);
                if (!currentUser.login.empty()) 
                {
                    isLoggedIn = true;
                }
                break;
            }
            case 2: 
            {
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
    }

    return 0;
}
