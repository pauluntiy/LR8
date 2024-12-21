#include <iostream>
#include "functions.h"
#include <string>
#include <fstream>

worker* Case_1(int&, int&);
worker* Case_3(int&, int&);
worker* Default(int&, int&);

worker* New_list(int& i, int& size)
{
    int choise;
    std::cout << "Список доступных параметров:\n";
    std::cout << "-------------------------------------------------------------------------------------\n";
    std::cout << "1. Ввести заданное количество абитуриентов\n";
    std::cout << "2. После каждого введённого абитуриента, спрашивать о необходимости дальнейшего ввода\n";
    std::cout << "(по умолчанию инициализируется список из 5 абитуриентов)\n";
    std::cout << "-------------------------------------------------------------------------------------\n";
    std::cout << "Чтобы выбрать параметр, введите его номер\n";
    std::cin >> choise;
    worker* workers;
    size = 5;

    switch (choise) {
    case 1:
        workers = Case_1(i, size);
        break;

    case 2:
        workers = Case_3(i, size);
        break;

    default:
        workers = Default(i, size);
        break;
    }
    return workers;
}

worker* Case_1(int& i, int& size)
{
    std::cin >> size;
    worker* workers = new worker[size];
    i = 0;
    std::cout << "=================================================\n";
    for (; i < size; ++i) {
        Input_worker(workers[i], i);
    }
    return workers;
}



worker* Case_3(int& i, int& size)
{
    worker* workers = new worker[size];
    bool repeat;
    i = 0;
    std::cout << "=================================================\n";
    do {
        Add_worker(workers, i, size);
        ++i;
        std::cout << "Продолжить?[0 - нет/1 - да]\n";
        std::cin >> repeat;
    } while (repeat);
    return workers;
}

worker* Default(int& i, int& size)
{
    worker* workers = new worker[size];
    i = 0;
    std::cout << "=================================================\n";
    for (; i < size; ++i) {
        Input_worker(workers[i], i);
    }
    return workers;
}

bool Input_worker(worker& workers, int i)
{
    std::cout << "Введите ФИО: ";
    std::cin.ignore();
    std::getline(std::cin, workers.SNP);

    std::cout << "Введите табельный номер: ";
    std::cin >> workers.id;

    std::cout << "Количество рабочих часов в месяц";
    std::cin >> workers.hours;

    std::cout << "Введите тарификацию: \n";
    std::cin >> workers.rate;

    double extra_h = (workers.hours > 144) ? workers.hours - 144 : 0;
    workers.sallary = static_cast<double>(workers.hours + extra_h) * (workers.rate);
    
    std::cout << "Вписать доп. информацию [1 - пол / 2 - возраст]: \n";
    int extra;
    std::cin >> extra;
    if (extra == 1) {
        std::cout << "Введите пол: \n";
        std::cin >> workers.extra.sex;
    }
    else if (extra == 2) {
        flag = true;
        std::cout << "Введите возраст: \n";
        std::cin >> workers.extra.age;
    }
    return flag;
}

void Add_worker(worker* workers, int i, int size)
{
    if (i >= size) {
        size += 2;
        worker* more_workers = new worker[size];
        for (int i = 0; i < size - 2; ++i) {
            more_workers[i] = workers[i];
        }
        delete[] workers;
        workers = more_workers;
    }
    Input_worker(workers[i], i);
}