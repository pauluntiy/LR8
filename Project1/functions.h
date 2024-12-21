#pragma once
#include "struct.h"

applicant* New_list(int&, int&);
void Add_applicant(applicant*, int, int);
void Input_applicant(applicant&, int);
void Show_list(applicant*, int);
void Output_applicant(applicant&);
void Search_applicant(applicant*, int);
void Update_applicant(applicant*, int);
applicant* Delete_applicant(applicant*, int&);
void Sort_applicants_by_avgm(applicant*, int);

void Start_interface();
void End_interface();
int Get_mark();


