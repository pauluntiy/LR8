#pragma once
#include <string>

union extra_info {
    char sex;
    int age = 0;
};

typedef struct worker {
    std::string SNP;
    int id;
    int hours;
    double rate;
    double sallary;
    extra_info extra;
} worker;


extern bool flag;