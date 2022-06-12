#include "Task23.h"

Task23::Task23(int num)
{
    table = std::make_unique<DataTask>(23);
    vectorId = table->getVectorId(num);
}

void Task23::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            //нужно проверять не выпало ли две одинаковые операции
            std::vector<int> limitVec = { 3, 4, 3 , 20, 9 };
            std::vector<int> minVec = { 1, 2, 1, 10,5 };
            genRandMin(5,  limitVec,minVec, number_);
            if (number_.at(0) == number_.at(1)) {
                number_.at(0) = number_.at(1) + 1;
            }
            solverType1();
            break;
        }
        case type2:
        {
            std::vector<int> limitVec = { 3, 4, 3 , 20, 9 };
            std::vector<int> minVec = { 1, 2, 1, 10,5 };
            genRandMin(5,  limitVec,minVec, number_);
            if (number_.at(0) == number_.at(1)) {
                number_.at(0) = number_.at(1) + 1;
            }
            solverType2();
            break;
        }
        case type3:
        {
            std::vector<int> limitVec = { 3, 4,2, 3 , 20, 9 };
            std::vector<int> minVec = { 1, 2,1, 1, 10,5 };
            genRandMin(6,  limitVec,minVec, number_);
            solverType3();
            break;
        }
        case type4:
        {
            std::vector<int> limitVec = { 3, 4,2, 3 , 20, 9 };
            std::vector<int> minVec = { 1, 2,1, 1, 10,5 };
            genRandMin(6,  limitVec,minVec, number_);
            solverType4();
            break;
        }
        default:
            break;
    }
}

void Task23::checkResult(int result)
{
    table->putTableAnswer(number_);
}

void Task23::solverType1()
{
    int count = 0;
    int output;

    while (count != 1) {
        int array[100];
        for (int &i: array) {
            i = 0;
        }

        array[number_.at(4)] = 1;
        array[number_.at(3)] = 1;

        for (int j = number_.at(4) - 1; j > number_.at(2) - 1; j--) {
            array[j] = array[j * number_.at(0)] + array[j + number_.at(1)];
        }
        for (int j = number_.at(3) - 1; j > number_.at(4) - 1; j--) {
            array[j] = array[j * number_.at(0)] + array[j + number_.at(1)];
        }

        output = array[number_.at(2)] * array[number_.at(4)];

        if (output != 0) {
            count += 1;

        }
        else
            number_.at(1) -= 1;

    }
    number_.push_back(output);
    table->putTableAnswer(number_);
}

void Task23::solverType2()
{
    int count = 0;
    int output;

    while (count != 1) {
        int array[100];
        for (int &i: array) {
            i = 0;
        }

        array[number_.at(4)] = 1;
        array[number_.at(3)] = 1;

        for (int j = number_.at(4) - 1; j > number_.at(2) - 1; j--) {
            array[j] = array[j * number_.at(0)] + array[j + number_.at(1)];
        }
        for (int j = number_.at(3) - 1; j > number_.at(4) - 1; j--) {
            array[j] = array[j * number_.at(0)] + array[j + number_.at(1)];
        }

        output = array[number_.at(2)] * array[number_.at(4)];

        if (output != 0) {
            count += 1;

        }
        else
            number_.at(1) -= 1;

    }
    number_.push_back(output);
    table->putTableAnswer(number_);
}

void Task23::solverType3()
{
    int count = 0;
    int output;

    while (count != 1) {
        int array[100];
        for (int &i: array) {
            i = 0;
        }

        array[number_.at(5)] = 1;
        array[number_.at(4)] = 1;

        for (int j = number_.at(5) - 1; j > number_.at(3) - 1; j--) {
            array[j] = array[j + number_.at(0)] + array[j + number_.at(1)] + array[j + number_.at(2)];
        }
        for (int j = number_.at(4) - 1; j > number_.at(5) - 1; j--) {
            array[j] = array[j + number_.at(0)] + array[j + number_.at(1)] + array[j + number_.at(2)];
        }

        output = array[number_.at(3)] * array[number_.at(5)];

        if (output != 0) {
            count += 1;
        }
        else
            number_.at(1) -= 1;
    }

    number_.push_back(output);
    table->putTableAnswer(number_);

}

void Task23::solverType4()
{
    int count = 0;
    int output;

    while (count != 1) {
        int array[100];
        for (int &i: array) {
            i = 0;
        }

        array[number_.at(5)] = 1;
        array[number_.at(4)] = 1;

        for (int j = number_.at(5) - 1; j > number_.at(3) - 1; j--) {
            array[j] = array[j + number_.at(0)] + array[j + number_.at(1)] + array[j * number_.at(2)];
        }
        for (int j = number_.at(4) - 1; j > number_.at(5) - 1; j--) {
            array[j] = array[j + number_.at(0)] + array[j + number_.at(1)] + array[j * number_.at(2)];
        }

        output = array[number_.at(3)] * array[number_.at(5)];

        if (output != 0) {
            count += 1;
        }
        else
            number_.at(1) -= 1;
    }

    number_.push_back(output);
    table->putTableAnswer(number_);
}

void Task23::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    replacementText(text);
}

void Task23::replacementText(std::string& textTaskString)
{
    textTaskString = table->getTextTask();
    textTaskString += table->getTextQuestion();
    textTaskString += table->getSizeType();
    for (int j = 0;  j < number_.size() - 1; ++j) {
        int found = textTaskString.find('0');
        if (found != std::string::npos) {
            textTaskString.replace(found, std::to_string(number_[j]).length(), std::to_string(number_.at(j)));

        }
    }
}

int Task23::getNumber()
{
    return number_.back();
}