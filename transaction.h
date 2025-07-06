// transaction.h - Заголовочный файл для работы с транзакциями

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;


struct Transaction 
{
    string login;
    double amount;
    string type;
    string category;
    string date;
    string description;
};

bool addTransaction(const string& login, double amount, const string& type,
    const string& category, const string& date, const string& description);

bool deleteTransaction(const string& login, int index);

void listTransactions(const string& login);

#endif // TRANSACTION_H
