#include <iostream>
#include "functions.h"

void Update_applicant(applicant* applicants, int size)
{
	int target;
	std::cout << "Введите # абитуриента, данные которого нужно изменить:\n";
	std::cin >> target;
	for (int i = 0; i < size; ++i) {
		if (applicants[i].id == target) {
			Input_applicant(applicants[i], i);
		}
	}
}

applicant* Delete_applicant(applicant* applicants, int& size)
{
	applicant* less_applicants = new applicant [--size];
	int target;
	std::cout << "Введите # абитуриента, запись о котором нужно удалить:\n";
	std::cin >> target;
	for (int i = 0, j = 0; i < size; ++i) {
		if (applicants[i].id == target) {
			continue;
		}
		less_applicants[j++] = applicants[i];
	}
	delete[] applicants;
	return less_applicants;
}
