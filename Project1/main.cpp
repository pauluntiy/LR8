#include <iostream>
#include "functions.h"

void menu()
{
	std::string filename = "applicants.dat";
	int choise;
	int i, size;
	std::cout << "������� ������ �����������\n";
	worker* workers = New_list(i, size);
	do {
		std::cout << "--------------------------------------------------\n";
		std::cout << "������ ��������� �������\n";
		std::cout << "1. ������� ����� ������ �����������\n";
		std::cout << "2. �������� ����������\n";
		std::cout << "3. ����������� �����������\n";
		std::cout << "4. ����� ���������� �� ��� ������ � ������\n";
		std::cout << "5. �������� ������\n";
		std::cout << "6. ������� ������\n";
		std::cout << "7. ����������� �� ��������\n";
		std::cout << "0. �����\n";
		std::cout << "--------------------------------------------------\n";
		std::cout << "����� ������� �����, ������� � �����\n";
		std::cin >> choise;

		switch (choise) {

		case 1:
			workers = New_list(i, size);
			break;

		case 2:
			Add_worker(workers, i, size);
			++i;
			break;

		case 3:
			Show_list(workers, i);
			break;

		case 4:
			Search_worker(workers, i);
			break;

		case 5:
			Update_worker(workers, i);
			break;

		case 6:
			workers = Delete_worker(workers, i);
			break;

		case 7:
			Sort_workers_by_sallary(workers, i);
			break;

		default:
			std::cout << "����� ����� �������������� �����";
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