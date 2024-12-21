#include <iostream>
#include "functions.h"

void Show_list(applicant* applicants, int size)
{
    std::cout << "==================================================\n";
    for (int i = 0; i < size; ++i) {
        Output_applicant(applicants[i]);
    }
}

void Output_applicant(applicant& applicants) {
    std::cout << "#" << applicants.id << ".\n";
    std::cout << "���: " << applicants.SNP << '\n';
    std::cout << "�����: �. " << applicants.add.city << ", " << applicants.add.loc_addr << '\n';
    std::cout << "������:\n\t" << "�� ���������e:" << applicants.m.mat << "\n\t�� ������:" << applicants.m.phys << "\n\t�� ������������:" << applicants.m.bel << '\n';
    if (applicants.add.city == "Minsk") {
        std::cout << "������� ����: " << applicants.avg_m << "\n";
    }
    std::cout << "���. ����������: ";
    if (applicants.extra.olympiad_place == 0) {
        std::cout << "���\n";
        std::cout << "--------------------------------------------------\n";
        return;
    }
    else if (applicants.extra.gold_medal == "��������") {
        std::cout << applicants.extra.gold_medal << '\n';
        std::cout << "--------------------------------------------------\n";
        return;
    }
    else {
        std::cout << "������ " << applicants.extra.olympiad_place << " ������� �� ���������" << '\n';
        std::cout << "--------------------------------------------------\n";
    }
    
}