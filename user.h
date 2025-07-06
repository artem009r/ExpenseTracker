// user.h - Заголовочный файл для работы с пользователями

#ifndef USER_H
#define USER_H

#include <string>

using namespace std;


struct User 
{
    string login; 
    string password;
};

bool registerUser(const string& login, const string& password);

bool loginUser(const string& login, const string& password);

#endif // USER_H
