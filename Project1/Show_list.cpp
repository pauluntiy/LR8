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
    std::cout << "ФИО: " << applicants.SNP << '\n';
    std::cout << "Адрес: г. " << applicants.add.city << ", " << applicants.add.loc_addr << '\n';
    std::cout << "Оценки:\n\t" << "по математикe:" << applicants.m.mat << "\n\tпо физике:" << applicants.m.phys << "\n\tпо белорусскому:" << applicants.m.bel << '\n';
    if (applicants.add.city == "Minsk") {
        std::cout << "Средний балл: " << applicants.avg_m << "\n";
    }
    std::cout << "Доп. информация: ";
    if (applicants.extra.olympiad_place == 0) {
        std::cout << "нет\n";
        std::cout << "--------------------------------------------------\n";
        return;
    }
    else if (applicants.extra.gold_medal == "медалист") {
        std::cout << applicants.extra.gold_medal << '\n';
        std::cout << "--------------------------------------------------\n";
        return;
    }
    else {
        std::cout << "диплом " << applicants.extra.olympiad_place << " степени по олимпиаде" << '\n';
        std::cout << "--------------------------------------------------\n";
    }
    
}
