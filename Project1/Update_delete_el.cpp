#include <iostream>
#include "functions.h"

void Update_worker(worker* workers, int size)
{
	int target;
	std::cout << "Введите # сотрудника, данные которого нужно изменить:\n";
	std::cin >> target;
	for (int i = 0; i < size; ++i) {
		if (workers[i].id == target) {
			Input_worker(workers[i], i);
		}
	}
}

worker* Delete_worker(worker* workers, int& size)
{
	worker* less_workers = new worker[--size];
	int target;
	std::cout << "Введите # сотрудника, запись о котором нужно удалить:\n";
	std::cin >> target;
	for (int i = 0, j = 0; i < size; ++i) {
		if (workers[i].id == target) {
			continue;
		}
		less_workers[j++] = workers[i];
	}
	delete[] workers;
	return less_workers;
}