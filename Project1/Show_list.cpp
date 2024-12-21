#include <iostream>
#include "functions.h"

void Show_list(worker* workers, int size)
{
    std::cout << "==================================================\n";
    for (int i = 0; i < size; ++i) {
        Output_worker(workers[i]);
    }
}

void Output_worker(worker& workers) {
    std::cout << "Табельный #" << workers.id << ".\n";
    std::cout << "ФИО: " << workers.SNP << '\n';
    std::cout << "Количество рабочих часов в месяц" << workers.hours << ".\n";
    std::cout << "Тарификация:" << workers.id << ".\n";
    std::cout << "Зарплата:" << workers.sallary << ".\n";

    std::cout << "Доп. информация: ";
    if (flag) {
        std::cout << workers.extra.age << "\n";
        std::cout << "--------------------------------------------------\n";
        return;
    }
    else {
        std::cout << workers.extra.sex << "\n";
        std::cout << "--------------------------------------------------\n";
    }
}