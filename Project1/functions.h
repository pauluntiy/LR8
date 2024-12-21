#pragma once
#include "struct.h"

worker* New_list(int&, int&);
void Add_worker(worker*, int, int);
bool Input_worker(worker&, int);
void Show_list(worker*, int);
void Output_worker(worker&);
void Search_worker(worker*, int);
void Update_worker(worker*, int);
worker* Delete_worker(worker*, int&);
void Sort_workers_by_sallary(worker*, int);

void Start_interface();
void End_interface();
int Get_mark();


