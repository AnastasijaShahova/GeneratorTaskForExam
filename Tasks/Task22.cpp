#include "Task22.h"
#include "Task16.h"
#include <string>

static const char *CODE_TYPE1= "#include <iostream>"
                               "using namespace std;"
                               "int main()\n"
                               "{"
                               "int x, a, b;\n"
                               "cin >> x;\n"
                               "a = 0; b = 1;\n"
                               "while (x > 0) {\n"
                               "if (x % 2 > 0)"
                               "a = a+1;\n"
                               "else "
                               "b = b + (x % %1%);\n"
                               "x = x/ %1%;\n"
                               "cout << a << endl << b << endl;\n"
                               "}";

static const char *CODE_TYPE2= "#include <iostream>\n"
                               "using namespace std;\n"
                               "int main()\n"
                               "{\n"
                               "int x, L, M;\n"
                               "cin >> x;\n"
                               "L = 0;\n"
                               "M = %1%;\n"
                               "while (x > 0){\n"
                               "L = L + 1;\n"
                               "if(x % 2 == 0){\n"
                               "M = M + (x % %2%) / 2;\n"
                               "}\n"
                               "x = x / %2%;\n"
                               "}\n"
                               "cout << L << endl << M endl;\n"
                               "}";

Task22::Task22(int num)
{
    table = std::make_unique<DataTask>(22);
    vectorId = table->getVectorId(num);
}

void Task22::solutionTask(Type type)
{
    switch (type) {
        //с a,b
        case type1:
        {
            //a,b,system,
            std::vector<int> limitVec = { 5, 8, 3 };
            std::vector<int> minVec = { 2, 4, 1 };
            genRandMin(3,  limitVec,minVec, number_);
            solverType1();
            break;
        }
        // c L,M
        case type2:
        {
            // m,L_rand,m_rand,system
            std::vector<int> limitVec = { 2, 3, 13 , 8 };
            std::vector<int> minVec = { 0, 2, 6, 2 };
            genRandMin(4,  limitVec,minVec, number_);
            if (number_.at(3) % 2 ==0) {
                number_[3] = 4;
            }
            solverType2();
            break;
        }
        default:
            break;
    }
}

void Task22::checkResult(int result)
{

}

void Task22::solverType1()
{
    int result = twentytwo_min(number_.at(2));
    number_.push_back(result);
    table->putTableAnswer(number_);
}

void Task22::solverType2()
{
    int result = twentytwo_max(number_.at(3));
    number_.push_back(result);
    table->putTableAnswer(number_);
}

void Task22::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    std::string textTaskString = table->getTextTask();
    textTaskString = table->getTextTask();
    textTaskString += table->getTextQuestion();
    for (int j = 0;  j < number_.size() - 1; ++j) {
        int found = textTaskString.find('0');
        if (found != std::string::npos) {
            if (table->getTypeTask() == "type1") {
                int i = j;
                textTaskString.replace(found, std::to_string(number_[j]).length(), std::to_string(number_.at(i)));
                i++;
            } else {
                int i = j + 1;
                textTaskString.replace(found, std::to_string(number_[j]).length(), std::to_string(number_.at(i)));
            }
        }
    }

    if (table->getTypeTask() == "type1") {
        text = textTaskString + (StrFormat(CODE_TYPE1) % number_.at(2) ).str();
    } else {
        text = textTaskString + (StrFormat(CODE_TYPE2) % number_.at(0) % number_.at(3)).str();
    }

}

int Task22::getNumber()
{
    return number_.back();
}

//указывает наименьшее
int Task22::twentytwo_min(int system) {
    int x, a, b, min;
    int a_begin, b_begin;
    int a_rand = number_.at(0);
    int b_rand = number_.at(1);

    a = 0; b = 1; min = 1000000;
    a_begin = a; b_begin = b;

    for (int i = 0; i <= 100000; i++) {
        x = i;

        while (x > 0) {
            if (x % 2 > 0)
                a += x % system;
            else
                b *= x % system;
            x = x / system;
        }

        if (a == a_rand && b == b_rand && i < min) {
            min = i;
            i = 100001;
        }

        a = a_begin; b = b_begin;

    }

    return min;
}

//указывает наибольшее
int Task22::twentytwo_max(int system) {
    int x;
    int L_begin, M_begin;

    int L = 0;
    int M = number_.at(0);
    int max = 0;
    L_begin = L;
    M_begin = M;

    int L_rand = number_.at(1);
    int M_rand = number_.at(2);

    for (int i = 0; i <= 100000; i++) {
        x = i;

        while (x > 0) {
            L = L + 1;
            if (x % 2 != 0)
                M += x % system;
            x = x / system;
        }

        if (L == L_rand && M == M_rand && i > max) {
            max = i;
        }

        L = L_begin; M = M_begin;

    }

    return max;
}