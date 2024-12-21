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
    std::cout << "������ ��������� ����������:\n";
    std::cout << "-------------------------------------------------------------------------------------\n";
    std::cout << "1. ������ �������� ���������� ������������\n";
    std::cout << "2. ����� ������� ��������� �����������, ���������� � ������������� ����������� �����\n";
    std::cout << "(�� ��������� ���������������� ������ �� 5 ������������)\n";
    std::cout << "-------------------------------------------------------------------------------------\n";
    std::cout << "����� ������� ��������, ������� ��� �����\n";
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
        std::cout << "����������?[0 - ���/1 - ��]\n";
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
    std::cout << "������� ���: ";
    std::cin.ignore();
    std::getline(std::cin, workers.SNP);

    std::cout << "������� ��������� �����: ";
    std::cin >> workers.id;

    std::cout << "���������� ������� ����� � �����";
    std::cin >> workers.hours;

    std::cout << "������� �����������: \n";
    std::cin >> workers.rate;

    double extra_h = (workers.hours > 144) ? workers.hours - 144 : 0;
    workers.sallary = static_cast<double>(workers.hours + extra_h) * (workers.rate);
    
    std::cout << "������� ���. ���������� [1 - ��� / 2 - �������]: \n";
    int extra;
    std::cin >> extra;
    if (extra == 1) {
        std::cout << "������� ���: \n";
        std::cin >> workers.extra.sex;
    }
    else if (extra == 2) {
        flag = true;
        std::cout << "������� �������: \n";
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