#include <iostream>
#include "functions.h"

void Search_applicant(applicant* applicants, int size)
{
	int target;
	std::cout << "Введите # искомого абитуриента:\n";
	std::cin >> target;
	for (int i = 0; i < size; ++i) {
		if (applicants[i].id == target) {
			Output_applicant(applicants[i]);
		}
	}
}

void quick_sort(applicant* applicants, int left, int right) {
    if (left >= right) return;

    double pivot = applicants[(left + right) / 2].m.mat;
    int l = left, r = right;

    while (l <= r) {
        while (applicants[l].avg_m > pivot) ++l;
        while (applicants[r].avg_m < pivot) --r;

        if (l <= r) {
            applicant temp = applicants[l];
            applicants[l] = applicants[r];
            applicants[r] = temp;
            ++l;
            --r;
        }
    }

    if (left < r) quick_sort(applicants, left, r);
    if (l < right) quick_sort(applicants, l, right);
}

void Sort_applicants_by_avgm(applicant* applicants, int size)
{
    quick_sort(applicants, 0, size - 1);
    std::cout << "Список отсортирован по убыванию оценки по математике.\n";
}
