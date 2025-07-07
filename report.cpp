// report.cpp - Реализация функций для работы с отчётами

#include "report.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

void showBalance(const string& login) 
{
    ifstream file("transactions.csv");
    string line;
    double balance = 0.0;

    while (getline(file, line)) 
    {
        size_t pos = line.find(",");
        if (pos != string::npos && line.substr(0, pos) == login) 
        {
            stringstream ss(line);
            string login, type, category, date, description, temp;
            double amount;

            getline(ss, login, ',');
            getline(ss, temp, ',');
            amount = stod(temp);
            getline(ss, type, ',');

            if (type == "income") 
            {
                balance += amount;
            }
            else if (type == "expense") 
            {
                balance -= amount;
            }
        }
    }
    file.close();

    cout << "\nОбщий баланс для " << login << ": " << balance << "\n";
}

void showCategoryReport(const string& login) 
{
    ifstream file("transactions.csv");
    string line;
    map<string, pair<double, double>> categoryTotals;

    while (getline(file, line)) 
    {
        size_t pos = line.find(",");
        if (pos != string::npos && line.substr(0, pos) == login) 
        {
            stringstream ss(line);
            string login, type, category, date, description, temp;
            double amount;

            getline(ss, login, ',');
            getline(ss, temp, ',');
            amount = stod(temp);
            getline(ss, type, ',');
            getline(ss, category, ',');

            if (type == "income") 
            {
                categoryTotals[category].first += amount; // Доходы
            }
            else if (type == "expense") 
            {
                categoryTotals[category].second += amount; // Расходы
            }
        }
    }
    file.close();

    cout << "\nОтчёт по категориям для " << login << ":\n";
    cout << "----------------------------------------\n";
    if (categoryTotals.empty()) 
    {
        cout << "Транзакции отсутствуют.\n";
    }
    else 
    {
        for (const auto& pair : categoryTotals) 
        {
            cout << "Категория: " << pair.first << "\n";
            cout << "  Доходы: " << pair.second.first << "\n";
            cout << "  Расходы: " << pair.second.second << "\n";
            cout << "----------------------------------------\n";
        }
    }
}

void filterByDate(const string& login, const string& date) 
{
    ifstream file("transactions.csv");
    string line;
    int index = -1;
    bool hasTransactions = false;

    cout << "\nТранзакции за " << date << " для " << login << ":\n";
    cout << "----------------------------------------\n";

    while (getline(file, line)) 
    {
        size_t pos = line.find(",");
        if (pos != string::npos && line.substr(0, pos) == login) 
        {
            stringstream ss(line);
            string login, type, category, transDate, description, temp;
            double amount;

            getline(ss, login, ',');
            getline(ss, temp, ',');
            amount = stod(temp);
            getline(ss, type, ',');
            getline(ss, category, ',');
            getline(ss, transDate, ',');
            getline(ss, description, ',');

            if (transDate == date) 
            {
                index++;
                hasTransactions = true;
                cout << "Индекс: " << index << "\n";
                cout << "Сумма: " << amount << "\n";
                cout << "Тип: " << type << "\n";
                cout << "Категория: " << category << "\n";
                cout << "Дата: " << transDate << "\n";
                cout << "Описание: " << description << "\n";
                cout << "----------------------------------------\n";
            }
        }
    }
    file.close();

    if (!hasTransactions) 
    {
        cout << "Транзакции за указанную дату отсутствуют.\n";
    }
}

void filterByCategory(const string& login, const string& category) 
{
    ifstream file("transactions.csv");
    string line;
    int index = -1;
    bool hasTransactions = false;

    cout << "\nТранзакции в категории " << category << " для " << login << ":\n";
    cout << "----------------------------------------\n";

    while (getline(file, line)) 
    {
        size_t pos = line.find(",");
        if (pos != string::npos && line.substr(0, pos) == login) 
        {
            stringstream ss(line);
            string login, type, transCategory, date, description, temp;
            double amount;

            getline(ss, login, ',');
            getline(ss, temp, ',');
            amount = stod(temp);
            getline(ss, type, ',');
            getline(ss, transCategory, ',');
            getline(ss, date, ',');
            getline(ss, description, ',');

            if (transCategory == category) 
            {
                index++;
                hasTransactions = true;
                cout << "Индекс: " << index << "\n";
                cout << "Сумма: " << amount << "\n";
                cout << "Тип: " << type << "\n";
                cout << "Категория: " << transCategory << "\n";
                cout << "Дата: " << date << "\n";
                cout << "Описание: " << description << "\n";
                cout << "----------------------------------------\n";
            }
        }
    }
    file.close();

    if (!hasTransactions) 
    {
        cout << "Транзакции в указанной категории отсутствуют.\n";
    }
}
