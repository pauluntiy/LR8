#pragma once
#include <string>

typedef struct marks {
	int mat;
	int phys;
	int bel;
} marks;

typedef struct address {
	std::string city;
	std::string loc_addr;
} address;

union extra_info {
	const char* gold_medal;
	int olympiad_place = 0;
};

typedef struct applicant {
	int id;
	std::string SNP;
	address add;
	marks m;
	double avg_m;
	extra_info extra;
} applicant;