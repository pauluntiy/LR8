#include <iostream>

int Get_mark()
{
    int x;
    while (true)
    {
        std::cin >> x;
        if (x < 1 || x > 10 || std::cin.fail() || std::isalpha(std::cin.peek())) {
            std::cout << "<������ �����! ��������� ������ ����������� �����, ���������� ��� ���>" << '\n';
            std::cin.clear();
            std::cin.ignore(99, '\n');
        }
        else {
            return x;
        }
    }
}