/*#include "functions.h"

void readFromBinaryFile(Student* studentList, int size, bool isAgList[]) {

    Student* students = new Student[size];
    int count = 0;

    std::ifstream ifs("Students_binary.dat", std::ios::in | std::ios::binary);
    if (ifs.is_open()) {
        for (int i = 0; i < size; ++i) {
            size_t nSize;
            ifs.read(reinterpret_cast<char*>(&nSize), sizeof(nSize));
            students[count].name.resize(nSize);
            ifs.read(const_cast<char*>(students[count].name.data()), nSize);

            size_t lnSize;
            ifs.read(reinterpret_cast<char*>(&lnSize), sizeof(lnSize));
            students[count].lastname.resize(lnSize);
            ifs.read(const_cast<char*>(students[count].lastname.data()), lnSize);

            size_t snSize;
            ifs.read(reinterpret_cast<char*>(&snSize), sizeof(snSize));
            students[count].surname.resize(snSize);
            ifs.read(const_cast<char*>(students[count].surname.data()), snSize);

            ifs.read(reinterpret_cast<char*>(&students[count].groupNumber), sizeof(students[count].groupNumber));
            ifs.read(reinterpret_cast<char*>(&students[count].averageMark), sizeof(students[count].averageMark));
            ifs.read(reinterpret_cast<char*>(&students[count].incomeOnFamilyMember), sizeof(students[count].incomeOnFamilyMember));

            if (isAgList[i]) {
                ifs.read(reinterpret_cast<char*>(&students[count].charactiristics.age), sizeof(students[count].charactiristics.age));
            }
            else {
                ifs.read(reinterpret_cast<char*>(&students[count].charactiristics.sex), sizeof(students[count].charactiristics.sex));
            }
            count++;
        }
    }
    ifs.close();

    std::cout << count << '\n';
    for (int i = 0; i < count; ++i) {
        std::cout << "*************************************************\n";
        std::cout << i + 1 << "-й студент.\n";
        std::cout << "-------------------------------------------------\n";
        std::cout << "Имя: " << students[i].name << '\n';
        std::cout << "Фамилия: " << students[i].lastname << '\n';
        std::cout << "Отчество: " << students[i].surname << '\n';
        std::cout << "Номер группы: " << students[i].groupNumber << '\n';
        std::cout << "Струдний балл: " << students[i].averageMark << '\n';
        std::cout << "Доход на члена семьи: " << students[i].incomeOnFamilyMember << '\n';
        if (isAgList[i]) {
            std::cout << "Возраст: " << students[i].charactiristics.age << '\n';
        }
        else {
            std::cout << "Пол: " << students[i].charactiristics.sex << '\n';
        }
        std::cout << "-------------------------------------------------\n";
    }
}


void informationToBinary_CXXFile(Student* studentList, int size, bool isAgList[]) {


    std::ofstream ofs("Students_binary.dat", std::ios::out | std::ios::binary);
    if (ofs.is_open()) {
        for (int i = 0; i < size; ++i) {
            size_t nameSize = studentList[i].name.size();
            ofs.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
            ofs.write(studentList[i].name.data(), nameSize);

            size_t lastnameSize = studentList[i].lastname.size();
            ofs.write(reinterpret_cast<const char*>(&lastnameSize), sizeof(lastnameSize));
            ofs.write(studentList[i].lastname.data(), lastnameSize);

            size_t surnameSize = studentList[i].surname.size();
            ofs.write(reinterpret_cast<const char*>(&surnameSize), sizeof(surnameSize));
            ofs.write(studentList[i].surname.data(), surnameSize);

            ofs.write(reinterpret_cast<const char*>(&studentList[i].groupNumber), sizeof(studentList[i].groupNumber));
            ofs.write(reinterpret_cast<const char*>(&studentList[i].averageMark), sizeof(studentList[i].averageMark));
            ofs.write(reinterpret_cast<const char*>(&studentList[i].incomeOnFamilyMember), sizeof(studentList[i].incomeOnFamilyMember));
            if (isAgList[i]) {
                ofs.write(reinterpret_cast<const char*>(&studentList[i].charactiristics.age), sizeof(studentList[i].charactiristics.age));
            }
            else {
                ofs.write(reinterpret_cast<const char*>(&studentList[i].charactiristics.sex), sizeof(studentList[i].charactiristics.sex));
            }
        }
    }

    ofs.close();
}


void informationToFile(Student* studentList, int size, bool isAgList[]) {

    std::ofstream ofs("Students.dat");
    if (ofs.is_open()) {
        for (int i = 0; i < size; ++i) {
            ofs << "Student " << i + 1 << '\n';
            ofs << "Name: " << studentList[i].name << '\n';
            ofs << "Lastname: " << studentList[i].lastname << '\n';
            ofs << "Surname: " << studentList[i].surname << '\n';
            ofs << "Group number: " << std::setw(3) << studentList[i].groupNumber << '\n';
            ofs << "Averege mark: " << studentList[i].averageMark << '\n';
            ofs << "Income per femily membor: " << studentList[i].averageMark << '\n';
            if (isAgList[i]) {
                ofs << "Age: " << studentList[i].charactiristics.age << '\n';
            }
            else {
                ofs << "Sex: " << studentList[i].charactiristics.sex << '\n';
            }
        }
    }
    ofs.close();
}

void addStudentToFile(Student s, int i, bool isAge) {
    std::ofstream ofs("Students.dat", std::ios::app);
    if (ofs.is_open()) {
        ofs << "Student " << i + 1 << '\n';
        ofs << "Name: " << s.name << '\n';
        ofs << "Lastname: " << s.lastname << '\n';
        ofs << "Surname: " << s.surname << '\n';
        ofs << "Group number: " << std::setw(3) << s.groupNumber << '\n';
        ofs << "Averege mark: " << s.averageMark << '\n';
        ofs << "Income per femily membor: " << s.averageMark << '\n';
        if (isAge) {
            ofs << "Age: " << s.charactiristics.age << '\n';
        }
        else {
            ofs << "Sex: " << s.charactiristics.sex << '\n';
        }
    }
    ofs.close();
}

void addStudentToBinaryFile(Student s, int i, bool isAge) {
    std::ofstream ofs("Students_binary.dat", std::ios::app);
    if (ofs.is_open()) {

        size_t nameSize = s.name.size();
        ofs.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        ofs.write(s.name.data(), nameSize);

        size_t lastnameSize = s.lastname.size();
        ofs.write(reinterpret_cast<const char*>(&lastnameSize), sizeof(lastnameSize));
        ofs.write(s.lastname.data(), lastnameSize);

        size_t surnameSize = s.surname.size();
        ofs.write(reinterpret_cast<const char*>(&surnameSize), sizeof(surnameSize));
        ofs.write(s.surname.data(), surnameSize);

        ofs.write(reinterpret_cast<const char*>(&s.groupNumber), sizeof(s.groupNumber));
        ofs.write(reinterpret_cast<const char*>(&s.averageMark), sizeof(s.averageMark));
        ofs.write(reinterpret_cast<const char*>(&s.incomeOnFamilyMember), sizeof(s.incomeOnFamilyMember));
        if (isAge) {
            ofs.write(reinterpret_cast<const char*>(&s.charactiristics.age), sizeof(s.charactiristics.age));
        }
        else {
            ofs.write(reinterpret_cast<const char*>(&s.charactiristics.sex), sizeof(s.charactiristics.sex));
        }
    }
    ofs.close();
}


void chageBinaryFile(Student* studentList, int stud, int new_value, bool* isAgList) {
    std::fstream ffs("Students_binary.dat", std::ios::in | std::ios::out | std::ios::binary);
    if (ffs.is_open()) {
        size_t bytes = 0;
        for (int i = 0; i < stud; ++i) {
            size_t lenght = 0;
            ffs.read(reinterpret_cast<char*>(&lenght), sizeof(lenght)); // считываем то значени длины строки которое хранится в std::string в size_t
            bytes += sizeof(lenght) + lenght; // считали одну строку, то есть сначала указатель на её размер, а потом само содержимое
            ffs.seekg(bytes, std::ios::beg);
            size_t l2 = 0;
            ffs.read(reinterpret_cast<char*>(&l2), sizeof(l2)); // считываем то значени длины строки которое хранится в std::string в size_t
            bytes += sizeof(l2) + l2;
            ffs.seekg(bytes, std::ios::beg);
            size_t l3 = 0;
            ffs.read(reinterpret_cast<char*>(&l3), sizeof(l3)); // считываем то значени длины строки которое хранится в std::string в size_t
            bytes += sizeof(l3) + l3;
            int k = sizeof(int) + 2 * sizeof(double);
            bytes += k;
            if (isAgList[i]) {
                bytes += sizeof(int);
            }
            else {
                bytes += sizeof(char);
            }
            ffs.seekg(bytes, std::ios::beg);
        }

            for (int j = 0; j < 3; ++j) {
                size_t l1 = 0;
                ffs.read(reinterpret_cast<char*>(&l1), sizeof(l1));
                bytes += sizeof(l1) + l1;
                ffs.seekg(l1, std::ios::cur);
            }

        char newValue = static_cast<char>(new_value);
        ffs.seekp(bytes, std::ios::beg);
        ffs.write(&newValue, sizeof(newValue));
        ffs.close();
    }
}*/