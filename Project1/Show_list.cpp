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
    std::cout << "��������� #" << workers.id << ".\n";
    std::cout << "���: " << workers.SNP << '\n';
    std::cout << "���������� ������� ����� � �����" << workers.hours << ".\n";
    std::cout << "�����������:" << workers.id << ".\n";
    std::cout << "��������:" << workers.sallary << ".\n";

    std::cout << "���. ����������: ";
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