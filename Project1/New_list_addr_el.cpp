#include <iostream>
#include "functions.h"
#include <string>
#include <fstream>

applicant* Case_1(int&, int&);
applicant* Case_2(int&, int&);
applicant* Case_3(int&, int&);
applicant* Default(int&, int&);

applicant* New_list(int& i, int& size)
{
    int choise;
    std::cout << "Список доступных параметров:\n";
    std::cout << "-------------------------------------------------------------------------------------\n";
    std::cout << "1. Ввести заданное количество абитуриентов\n";
    std::cout << "2. Вводить абитуриентов пока не появится абитуриент Полоцка\n";
    std::cout << "3. После каждого введённого абитуриента, спрашивать о необходимости дальнейшего ввода\n";
    std::cout << "(по умолчанию инициализируется список из 5 абитуриентов)\n";
    std::cout << "-------------------------------------------------------------------------------------\n";
    std::cout << "Чтобы выбрать параметр, введите его номер\n";
    std::cin >> choise;
    applicant* applicants;
    size = 5;

    switch (choise) {
    case 1:
        applicants = Case_1(i, size);
        break;

    case 2:
        applicants = Case_2(i, size);
        break;

    case 3:
        applicants = Case_3(i, size);
        break;

    default:
        applicants = Default(i, size);
        break;
    }
    return applicants;
}

applicant* Case_1(int& i, int& size)
{
    std::cin >> size;
    applicant* applicants = new applicant[size];
    i = 0;
    std::cout << "=================================================\n";
    for (; i < size; ++i) {
        Input_applicant(applicants[i], i);
    }
    return applicants;
}

applicant* Case_2(int& i, int& size)
{
    applicant* applicants = new applicant[size];
    bool repeat = true;
    i = 0;
    std::cout << "=================================================\n";
    do {
        Add_applicant(applicants, i, size);
        if (applicants[i].add.city == "Polotsk") {
            repeat = false;
        }
        ++i;
    } while (repeat);
    return applicants;
}

applicant* Case_3(int& i, int& size)
{
    applicant* applicants = new applicant[size];
    bool repeat;
    i = 0;
    std::cout << "=================================================\n";
    do {
        Add_applicant(applicants, i, size);
        ++i;
        std::cout << "Ïðîäîëæèòü?[0 - íåò/1 - äà]\n";
        std::cin >> repeat;
    } while (repeat);
    return applicants;
}

applicant* Default(int& i, int& size)
{
    applicant* applicants = new applicant[size];
    i = 0;
    std::cout << "=================================================\n";
    for (; i < size; ++i) {
        Input_applicant(applicants[i], i);
    }
    return applicants;
}

void Input_applicant(applicant& applicants, int i)
{
    applicants.id = i + 1;
    std::cout << "#" << applicants.id << ".\n";
    std::cout << "Введите ФИО: ";
    std::cin.ignore();
    std::getline(std::cin, applicants.SNP);

    std::cout << "Введите город: ";
    std::getline(std::cin, applicants.add.city);

    std::cout << "Введите улицу, дом (дом/квартуру): ";
    std::getline(std::cin, applicants.add.loc_addr);

    std::cout << "Введите оценку по математикe: \n";
    applicants.m.mat = Get_mark();
    
    std::cout << "Введите оценку по физике: \n";
    applicants.m.phys = Get_mark();

    std::cout << "Введите оценку по белорусскому: \n";
    applicants.m.bel = Get_mark();

    if (applicants.add.city == "Minsk") {
        applicants.avg_m = static_cast<double>(applicants.m.mat + applicants.m.phys + applicants.m.bel) / 3.0;
    }
    
    std::cout << "Вписать доп. информацию [0 - нет / 1 - медалист / 2 - есть диплом по олимпиаде]: \n";
    int extra;
    std::cin >> extra;
    if (extra == 2) {
        std::cout << "Введите степень диплома (1 / 2 / 3): \n";
        std::cin >> applicants.extra.olympiad_place;
    }
    else if (extra == 1) {
        applicants.extra.gold_medal = "медалист";
    }
}

void Add_applicant(applicant* applicants, int i, int size)
{
    if (i >= size) {
        size += 2;
        applicant* more_applicants = new applicant[size];
        for (int i = 0; i < size - 2; ++i) {
            more_applicants[i] = applicants[i];
        }
        delete[] applicants;
        applicants = more_applicants;
    }
    Input_applicant(applicants[i], i);
}
