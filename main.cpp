// main.cpp - Главный файл программы для системы учёта расходов и доходов

#include <iostream>
#include <string>

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
        case 1:
            cout << "Функция входа (будет реализована).\n";
            break;
        case 2:
            cout << "Функция регистрации (будет реализована).\n";
            break;
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
