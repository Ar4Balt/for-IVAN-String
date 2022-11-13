#include <iostream>
#include "String.h"
/*
определить класс string  и перегрузить операции ввода/вывода
и операцию "+" сложения строк (добавление строки)
*/

using namespace std;

class String
{
private:
    char* str;
    int length;

public:
    String() {
        str = nullptr;
        length = 0;
    }
    String(const char* str) {
        length = strlen(str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
            this->str[i] = str[i];

        this->str[length] = '\0';
    }
    String(const String& other) {
        if (str != nullptr)
            delete[] str;
        length = strlen(other.str);
        str = new char[length + 1];
        for (int i = 0; i < length; i++)
            str[i] = other.str[i];

        str[length] = '\0';
    }    
    String(String&& other) noexcept {
        length = other.length;
        str = other.str;
        other.str = nullptr;
    }   
    ~String() {
        delete[] str;
    }

    char& operator[] (size_t i) const {
        return str[i];
    }

    bool operator== (const String& other) {
        if (length != other.length)
        {
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (str[i] != other.str[i])
                return false;
        }

        return true;
    }

    size_t Length() {
        return length;
    }
    void show() {
        cout << str;
    }

    friend ostream& operator<< (ostream& os, const String& s) {
        os << s.str;
        return os;
    }
    friend istream& operator>> (istream& in, String& s) {
        in >> s.str;
        return in;
    }
};


int main() {
	cout << "Hello World!\n";

	String str("Vany luchiy!");
	cout << str;

	cin >> str;
	cout << str;

	return 0;
}