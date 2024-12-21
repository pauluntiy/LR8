#include <iostream>
#include "functions.h"

void menu()
{
	int choise;
	int i, size;
	std::cout << "Создать список абитуриентов\n";
	applicant* applicants = New_list(i, size);
	do {
		std::cout << "--------------------------------------------------\n";
		std::cout << "Список доступных функций\n";
		std::cout << "1. Создать новый список абитуриентов\n";
		std::cout << "2. Добавить абитуриента\n";
		std::cout << "3. Просмотреть абитуриентов\n";
		std::cout << "4. Найти абитуриента по его номеру в списке\n";
		std::cout << "5. Обновить запись\n";
		std::cout << "6. Удалить запись\n";
		std::cout << "7. Сортировать по среднему баллу\n";
		std::cout << "0. Выход\n";
		std::cout << "--------------------------------------------------\n";
		std::cout << "Чтобы выбрать опцию, введите её номер\n";
		std::cin >> choise;

		switch (choise) {

		case 1:
			applicants = New_list(i, size);
			break;

		case 2:
			Add_applicant(applicants, i, size);
			++i;
			break;

		case 3:
			Show_list(applicants, i);
			break;

		case 4:
			Search_applicant(applicants, i);
			break;

		case 5:
			Update_applicant(applicants, i);
			break;

		case 6:
			applicants = Delete_applicant(applicants, i);
			break;

		case 7:
			Sort_applicants_by_avgm(applicants, i);
			break;

		default:
			std::cout << "Введён номер несуществующей опции";
			break;
		}
	} while (choise != 0);
}

int main()
{
	Start_interface();
	setlocale(LC_ALL, "ru");
	menu();
	End_interface();
	return 0;
}
