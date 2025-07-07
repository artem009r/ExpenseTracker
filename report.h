// report.h - Заголовочный файл для работы с отчётами

#ifndef REPORT_H
#define REPORT_H

#include <string>

using namespace std;

void showBalance(const string& login);

void showCategoryReport(const string& login);

void filterByDate(const string& login, const string& date);

void filterByCategory(const string& login, const string& category);

#endif // REPORT_H
