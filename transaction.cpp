// transaction.cpp - Реализация функций для работы с транзакциями

#include "transaction.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isValidTransaction(double amount, const string& type, const string& category,
    const string& date, const string& description) 
{
    if (amount <= 0) 
    {
        cout << "Ошибка: Сумма должна быть больше 0.\n";
        return false;
    }
    if (type != "income" && type != "expense") 
    {
        cout << "Ошибка: Тип должен быть 'income' или 'expense'.\n";
        return false;
    }
    if (category.empty() || category.find(",") != string::npos) 
    {
        cout << "Ошибка: Категория не может быть пустой или содержать запятые.\n";
        return false;
    }
    if (date.empty() || date.find(",") != string::npos) 
    {
        cout << "Ошибка: Дата не может быть пустой или содержать запятые.\n";
        return false;
    }
    if (description.find(",") != string::npos) 
    {
        cout << "Ошибка: Описание не может содержать запятые.\n";
        return false;
    }
    return true;
}

bool addTransaction(const string& login, double amount, const string& type,
    const string& category, const string& date, const string& description) 
{
    if (!isValidTransaction(amount, type, category, date, description))
    {
        return false;
    }

    ofstream file("transactions.csv", ios::app);
    if (!file.is_open()) 
    {
        cout << "Ошибка: Не удалось открыть файл transactions.csv.\n";
        return false;
    }

    file << login << "," << amount << "," << type << ","
        << category << "," << date << "," << description << "\n";
    file.close();
    cout << "Транзакция успешно добавлена!\n";
    return true;
}

bool deleteTransaction(const string& login, int index) 
{
    ifstream file("transactions.csv");
    vector<string> lines;
    string line;
    int currentIndex = -1;
    bool found = false;

    while (getline(file, line)) 
    {
        size_t pos = line.find(",");
        if (pos != string::npos && line.substr(0, pos) == login)
        {
            currentIndex++;
            if (currentIndex == index) 
            {
                found = true;
                continue;
            }
        }
        lines.push_back(line);
    }
    file.close();

    if (!found) 
    {
        cout << "Ошибка: Транзакция с индексом " << index << " не найдена.\n";
        return false;
    }

    ofstream fileOut("transactions.csv");
    if (!fileOut.is_open()) 
    {
        cout << "Ошибка: Не удалось открыть файл transactions.csv.\n";
        return false;
    }
    for (const string& l : lines) 
    {
        fileOut << l << "\n";
    }
    fileOut.close();
    cout << "Транзакция успешно удалена!\n";
    return true;
}

void listTransactions(const string& login) 
{
    ifstream file("transactions.csv");
    string line;
    int index = -1;
    bool hasTransactions = false;

    cout << "\nСписок транзакций для " << login << ":\n";
    cout << "----------------------------------------\n";

    while (getline(file, line)) {
        size_t pos = line.find(",");
        if (pos != string::npos && line.substr(0, pos) == login) 
        {
            index++;
            hasTransactions = true;

            stringstream ss(line);
            string login, type, category, date, description;
            double amount;
            string temp;

            getline(ss, login, ',');
            getline(ss, temp, ',');
            amount = stod(temp);
            getline(ss, type, ',');
            getline(ss, category, ',');
            getline(ss, date, ',');
            getline(ss, description, ',');

            cout << "Индекс: " << index << "\n";
            cout << "Сумма: " << amount << "\n";
            cout << "Тип: " << type << "\n";
            cout << "Категория: " << category << "\n";
            cout << "Дата: " << date << "\n";
            cout << "Описание: " << description << "\n";
            cout << "----------------------------------------\n";
        }
    }
    file.close();

    if (!hasTransactions) 
    {
        cout << "Транзакции отсутствуют.\n";
    }
}
