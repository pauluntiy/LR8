#include <iostream>
#include "functions.h"

void Search_worker(worker* workers, int size)
{
	int target;
	std::cout << "¬ведите # искомого сотрудника:\n";
	std::cin >> target;
	for (int i = 0; i < size; ++i) {
		if (workers[i].id == target) {
			Output_worker(workers[i]);
		}
	}
}

void quick_sort(worker* workers, int left, int right) {
    if (left >= right) return;

    double pivot = workers[(left + right) / 2].sallary;
    int l = left, r = right;

    while (l <= r) {
        while (workers[l].sallary > pivot) ++l;
        while (workers[r].sallary < pivot) --r;

        if (l <= r) {
            worker temp = workers[l];
            workers[l] = workers[r];
            workers[r] = temp;
            ++l;
            --r;
        }
    }

    if (left < r) quick_sort(workers, left, r);
    if (l < right) quick_sort(workers, l, right);
}

void Sort_workers_by_sallary(worker* workers, int size)
{
    quick_sort(workers, 0, size - 1);
    std::cout << "—писок отсортирован по убыванию зарплаты.\n";
}