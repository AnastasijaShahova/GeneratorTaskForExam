#include "Task6.h"
#include <string>

static  char * CODE_TYPE= "int main() {"
                           "int s,n;"
                           "s = %1%;"
                           "n = %2%; "
                           "while (  %3% %4% %5% ) {"
                           "s = s %6% %7% ;"
                           "n = n %8% %9%;"
                           "}"
                           "cout<<%10%<<endl; }";

Task6::Task6(int num)
{
    table = std::make_unique<DataTask>(6);
    vectorId = table->getVectorId(num);
//    initializedTable(num);
}


void Task6::solutionTask(Type type)
{
    switch (type) {
        // s больше
        case type1:
        {
            std::vector<int> limitVec = { 300, 10, 1 , 12, 8 };
            std::vector<int> minVec = { 13, 4, 0, 2,2 };
            genRandMin(5,  limitVec,minVec, number_);
            solverType1();
            break;
        }
        // n меньше
        case type2:
        {
            std::vector<int> limitVec = { 18, 300, 40, 22 };
            std::vector<int> minVec = { 4, 100, 20,5 };
            genRand(4, limitVec, number_);
            solverType2();
            break;
        }
        // минимальный номер
        case type3:
        {
            std::vector<int> limitVec = {112, 14  };
            std::vector<int> minVec = { 20, 3 };
            genRand(2, limitVec, number_);
            solverType3();
            break;
        }
        default:
            break;
    }
}

void Task6::checkResult(int result)
{
}

void Task6::solverType1()
{
    int number_s = number_.at(3);
    int number_greater = number_.at(1);

    int rand_greater = GetRandomNumber(0, 1);
    int rand_mult_sum = GetRandomNumber(0, 1);

    int n = number_.at(2);

    if (rand_greater == 0) {

        if (rand_mult_sum == 0) {

            int number_n = number_.at(4);
            int s = number_.at(0);

            while (s > number_greater) {
                s = s - number_s;
                n = n + number_n;
            }
        }

        else {

            int number_n = number_.at(4);
            int s_reduce =number_.at(0);

            while (s_reduce > number_greater) {
                s_reduce = s_reduce - number_s;
                n = n * number_n;
            }
        }
    }

    else {

        if (rand_mult_sum == 0) {

            int number_n = number_.at(4);
            int s = number_.at(0);

            while (s >= number_greater) {
                s = s - number_s;
                n = n + number_n;
            }
        }
        else {
            int number_n = number_.at(4);
            int s_reduce = number_.at(3);

            while (s_reduce >= number_greater) {
                s_reduce = s_reduce - number_s;
                n = n * number_n;
            }
        }
    }
    number_.push_back(n);
    sign_vec.push_back("n");
    table->putTableAnswer(number_);
}

void Task6::solverType2()
{
    int number_s = number_.at(2);
    int number_less = number_.at(1);

    int rand_greater = GetRandomNumber(0, 1);
    int rand_mult_sum = GetRandomNumber(0, 1);

    int s = 0;

    if (rand_mult_sum == 0) {

        if (rand_greater == 0) {

            int number_n = number_.at(3);
            int n = number_.at(0);


            if (n * number_n > number_less) {
                number_.at(0) = GetRandomNumber(2, 5);
                n = number_.at(0);
            }

            sign_vec.push_back("<=");
            while (n <= number_less) {
                s = s + number_s;
                sign_vec.push_back("+");
                n = n * number_n;
                sign_vec.push_back("*");
            }
        } else {

            int number_n = number_.at(3);
            int n = number_.at(0);

            while (n <= number_less) {
                sign_vec.push_back("<=");
                s = s + number_s;
                sign_vec.push_back("+");
                n = n + number_n;
                sign_vec.push_back("+");
            }
        }
    }
    else {

        if (rand_greater == 0) {

            int number_n = number_.at(3);
            int n = number_.at(0);

            if (n * number_n > number_less) {
                number_.at(0) = GetRandomNumber(2, 5);
                n = number_.at(0);
            }

            while (n < number_less) {
                sign_vec.push_back("<");
                s = s + number_s;
                sign_vec.push_back("+");
                n = n * number_n;
                sign_vec.push_back("*");

            }
        } else {

            int number_n = number_.at(3);
            int n = number_.at(0);

            sign_vec.push_back("<");
            while (n < number_less) {
                s = s + number_s;
                sign_vec.push_back("+");
                n = n + number_n;
                sign_vec.push_back("+");
            }
        }
    }
    number_.push_back(s);
    sign_vec.push_back("s");
    table->putTableAnswer(number_);
}

void Task6::solverType3()
{
    std::vector<int> degree = {32, 64, 128, 256, 512};
    int rand = GetRandomNumber(0, 3);
    number_.push_back(degree[rand]);
    int n = 1;
    int s = 0;
    int min = 10000;
    int threshold = number_.at(0);
    for (int i = 0; i < threshold + 1 ; ++i) {
        while(s <= threshold) {
            sign_vec.push_back("<=");
            s = s + number_.at(1);
            sign_vec.push_back("+");
            n = n * 2;
            sign_vec.push_back("*");
        }
        if (n == degree[rand] && i < min) {
            min = i;
        }
        n = 1;
        s = i + 1;
    }
    sign_vec.push_back("n");
    number_.push_back(min);
    table->putTableAnswer(number_);
}

void Task6::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    sign_vec.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    std::string textTaskString = table->getTextTask();
    int found = textTaskString.find('0');
    if (found != std::string::npos) {
        textTaskString.replace(found, std::to_string(number_[2]).length(), std::to_string(number_.at(2)));
    }

    // сгенерирована строка с заданием
    text = textTaskString + (StrFormat(CODE_TYPE) % number_.at(0) % number_.at(1) % number_.at(2) % sign_vec.at(0) %  number_.at(3) % sign_vec.at(1) % number_.at(4) %  sign_vec.at(2) % number_.at(5) %  sign_vec.at(3)).str();

}

int Task6::getNumber()
{
    return number_.back();
}
