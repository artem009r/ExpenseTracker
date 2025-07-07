// main.cpp - Главный файл программы для системы учёта расходов и доходов

#include <iostream>
#include <string>
#include "user.h"
#include "transaction.h"
#include "report.h"

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
        if (isLoggedIn) {
            cout << "Вы вошли как: " << currentUser.login << "\n";
            cout << "1. Добавить транзакцию\n";
            cout << "2. Удалить транзакцию\n";
            cout << "3. Показать транзакции\n";
            cout << "4. Показать баланс\n";
            cout << "5. Показать отчёт по категориям\n";
            cout << "6. Фильтровать по дате\n";
            cout << "7. Фильтровать по категории\n";
            cout << "8. Выход из аккаунта\n";
            cout << "9. Завершить программу\n";
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
                cout << "Введите тип (income(доход)/expense(расход)): ";
                getline(cin, type);
                if (type == "доход") type = "income";
                else if (type == "расход") type = "expense";
                cout << "Введите категорию: ";
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

                showBalance(currentUser.login);
                break;
            case 5:
                showCategoryReport(currentUser.login);
                break;
            case 6: 
            {
                string date;
                cout << "Введите дату (YYYY-MM-DD): ";
                getline(cin, date);
                filterByDate(currentUser.login, date);
                break;
            }
            case 7: 
            {
                string category;
                cout << "Введите категорию: ";
                getline(cin, category);
                filterByCategory(currentUser.login, category);
                break;
            }
            case 8:
                isLoggedIn = false;
                currentUser = User();
                cout << "Вы вышли из аккаунта.\n";
                break;
            case 9:
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
