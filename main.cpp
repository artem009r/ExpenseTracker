// main.cpp - Главный файл программы для системы учёта расходов и доходов

#include <iostream>
#include <string>
#include "user.h"
#include "transaction.h"

using namespace std;

int main() 
{
    setlocale(LC_ALL, "");
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
            cout << "1. Добавить транзакцию\n";
            cout << "2. Удалить транзакцию\n";
            cout << "3. Показать транзакции\n";
            cout << "4. Выход из аккаунта\n";
            cout << "5. Завершить программу\n";
        }
        else 
        {
            cout << "1. Вход\n";
            cout << "2. Регистрация\n";
            cout << "3. Выход\n";
        }
        cout << "Выберите действие: ";

        int choice;
        while (!(cin >> choice)) 
        {
            cout << "Ошибка: Введите число.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Выберите действие: ";
        }
        cin.ignore();

        if (isLoggedIn) 
        {
            switch (choice) 
            {
            case 1: 
            {
                double amount;
                string type, category, date, description;
                cout << "Введите сумму: ";
                while (!(cin >> amount)) 
                {
                    cout << "Ошибка: Введите число.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Введите сумму: ";
                }
                cin.ignore();
                cout << "Введите тип (income/expense): ";
                getline(cin, type);
                cout << "Введите категорию (Зарплата, продукты, транспорт): ";
                getline(cin, category);
                cout << "Введите дату (YYYY-MM-DD): ";
                getline(cin, date);
                cout << "Введите описание: ";
                getline(cin, description);
                addTransaction(currentUser.login, amount, type, category, date, description);
                break;
            }
            case 2: 
            {
                int index;
                cout << "Введите индекс транзакции для удаления: ";
                while (!(cin >> index)) 
                {
                    cout << "Ошибка: Введите число.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Введите индекс транзакции для удаления: ";
                }
                cin.ignore();
                deleteTransaction(currentUser.login, index);
                break;
            }
            case 3:
                listTransactions(currentUser.login);
                break;
            case 4:
                isLoggedIn = false;
                currentUser = User();
                cout << "Вы вышли из аккаунта.\n";
                break;
            case 5:
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
