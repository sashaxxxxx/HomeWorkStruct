#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

struct MyStruct
{
    std::string surname;
    int Exp;
    int salary;
    int hours;
    double ExpMany1Years = 0;
    double Exp3Years = 0.05;
    double Exp5Years = 0.08;
    double ExpMore5Years = 0.15;
    void AddElem() {
        std::cout << "Фамилия:";
        std::cin >> surname;
        std::cout << "\nСтаж:";
        std::cin >> Exp;
        std::cout << "\nЧасовая зп:";
        std::cin >> salary;
        std::cout << "\nКол-во отработанных часов:";
        std::cin >> hours;
    }
    void AllSalary() {
        AddElem();
        std::ofstream a;
        a.open("Text.txt");
        a << "Фамилия: " << surname << "\nСтаж: " << Exp << "\nЧасовая зп: " << salary << "\nКол-во отработанных часов:" << hours << "\nЗарплата: " << salary * hours;
        if (Exp < 0)
        {
            std::cout << surname << "\t" << salary * hours << " р.";
            a << "\nПремия: " << salary * hours * ExpMany1Years << "\nОбщ. зарплата: " << salary * hours * ExpMany1Years;
        }
        else if (Exp < 3)
        {
            std::cout << surname << "\t" << salary * hours * (Exp3Years + 1) << " р.";
            a << "\nПремия: " << salary * hours * Exp3Years << "\nОбщ. зарплата: " << salary * hours * (Exp3Years + 1);
        }
        else if (Exp < 5)
        {
            std::cout << surname << "\t" << salary * hours * (Exp5Years = 1) << " р.";
            a << "\nПремия: " << salary * hours * Exp5Years << "\nОбщ. зарплата: " << salary * hours * (Exp5Years + 1);
        }
        else {
            std::cout << surname << "\t" << salary * hours * (ExpMore5Years + 1) << " р.";
            a << "\nПремия: " << salary * hours * ExpMore5Years << "\nОбщ. зарплата: " << salary * hours * (ExpMore5Years + 1);
        }
    }
};


int main()
{
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    MyStruct obj;
    obj.AllSalary();
}
