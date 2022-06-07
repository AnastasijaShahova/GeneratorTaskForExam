#include "Task17.h"
#include <fstream>
#include <ctime>
#include <iostream>

Task17::Task17(int num)
{
    table = std::make_unique<DataTask>(8);
    vectorId = table->getVectorId(num);
}

void Task17::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            // макисмальная разность пар, разность кратна
            std::vector<int> limitVec = { 100 };
            genRand(1, limitVec, number_);
            writeNumberInFile();
            solverType1();
            break;
        }
        case type2:
        {
            // макисмальная сумм пчар, произв делится без остатка на
            std::vector<int> limitVec = { 50 };
            writeNumberInFile();
            genRand(1, limitVec, number_);
            solverType2();
            break;
        }
        case type3:
        {
            //максимальная сумма пар, сумма чет/нечет и произвед делится
            std::vector<int> limitVec = { 20 };
            writeNumberInFile();
            chet = rand() % 1;
            genRand(1, limitVec, number_);
            solverType3();
            break;
        }
        case type4:
        {
            //максимальная сумма пар, сумма кратна
            std::vector<int> limitVec = { 20, 15 };
            writeNumberInFile();
            genRand(2, limitVec, number_);
            solverType4();
            break;
        }
        default:
            break;
    }
}

// Алгоритм решения заданий 1 типа
void Task17::solverType1()
{
    int count = 0, d = 0;
    std::vector<int> vec;
    std::string s;
    std::ifstream fin("17.txt");
    if (!fin.is_open()) // если файл не открыт
        std::cout << "File is not open!\n";
    else {
        //считываем содержимое файла в вектор для дальнейшего удобства работы
        while(getline(fin, s)){
            vec.push_back(std::atoi(s.c_str()));
        }
    }
    for (int i =0; i< vec.size() - 1; ++i) {
        for (int k = i + 1; k < vec.size(); ++k) {
            if (vec[i] - vec[k] % number_.at(0) == 0) {
                ++count;
                if (d < abs(vec[k] - vec[i]))
                    d = abs(vec[k]-vec[i]);
            }
        }
    }
    number_.push_back(count);
    number_.push_back(d);
}

// Алгоритм решения заданий 2 типа
void Task17::solverType2()
{
    int count = 0, maxSum = 0;
    std::vector<int> vec;
    std::string s;
    std::ifstream fin("17.txt");
    if (!fin.is_open()) // если файл не открыт
        std::cout << "File is not open!\n";
    else {
        //считываем содержимое файла в вектор для дальнейшего удобства работы
        while(getline(fin, s)){
            vec.push_back(std::atoi(s.c_str()));
        }
    }
    for (int i =0; i< vec.size() - 1; ++i) {
        for (int k = i + 1; k < vec.size(); ++k) {
            if (vec[i] * vec[k] % number_.at(0) == 0) {
                ++count;
                if (maxSum < abs(vec[k] + vec[i]))
                    maxSum = abs(vec[k] + vec[i]);
            }
        }
    }
    number_.push_back(count);
    number_.push_back(maxSum);
}

// Алгоритм решения заданий 3 типа
void Task17::solverType3()
{
    int count = 0, maxSum = 0;
    std::vector<int> vec;
    std::string s;
    std::ifstream fin("17.txt");
    if (!fin.is_open()) // если файл не открыт
        std::cout << "File is not open!\n";
    else {
        //считываем содержимое файла в вектор для дальнейшего удобства работы
        while(getline(fin, s)){
            vec.push_back(std::atoi(s.c_str()));
        }
    }
    for (int i =0; i < vec.size() - 1; ++i) {
        for (int k = i + 1; k < vec.size(); ++k) {
            if (vec[i] * vec[k] % number_.at(0) == 0) {
                if (chet) {
                    if (vec[i] + vec[k] % 2 == 0) {
                        ++count;
                        if (maxSum < abs(vec[k] + vec[i]))
                            maxSum = abs(vec[k] + vec[i]);
                    }
                } else {
                    if (vec[i] + vec[k] % 2 != 0) {
                        ++count;
                        if (maxSum < abs(vec[k] + vec[i]))
                            maxSum = abs(vec[k] + vec[i]);
                    }
                }
            }
        }
    }
    number_.push_back(count);
    number_.push_back(maxSum);
}

// Алгоритм решения заданий 4 типа
void Task17::solverType4()
{
    int count = 0, maxSum = 0;
    std::vector<int> vec;
    std::string s;
    std::ifstream fin("17.txt");
    if (!fin.is_open()) // если файл не открыт
        std::cout << "File is not open!\n";
    else {
        //считываем содержимое файла в вектор для дальнейшего удобства работы
        while(getline(fin, s)){
            vec.push_back(std::atoi(s.c_str()));
        }
    }
    for (int i =0; i < vec.size() - 1; ++i) {
        for (int k = i + 1; k < vec.size(); ++k) {
            if (vec[i] + vec[k] % number_.at(0) == 0) {
                ++count;
                if (maxSum < abs(vec[k] + vec[i]))
                    maxSum = abs(vec[k] + vec[i]);
            }
        }
    }
    number_.push_back(count);
    number_.push_back(maxSum);
}

// Генерируем случайные числа для записи в файл
void Task17::writeNumberInFile() {
    std::ofstream file("17.txt");

    for (int i = 0; i < 10000; i++) {
        long int rnd = rand() % 20001 + (-10000);
        file << rnd << "\n";
    }

    file.close();
}

void Task17::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    replacementText(text);
}

int Task17::getNumber()
{
    return number_.back();
}

void Task17::replacementText(std::string& textTaskString)
{
    textTaskString = table->getTextTask();
    textTaskString += table->getTextQuestion();
    textTaskString += table->getSizeType();
    for (int j = 0;  j < number_.size() - 1; ++j) {
        int found = textTaskString.find('0');
        if (found != std::string::npos) {
            textTaskString.replace(found, std::to_string(number_[j]).length(), std::to_string(number_.at(j)));

        }
        // для 3 задания
        int found1 = textTaskString.find('!');
        if (found1 != std::string::npos) {
            if (chet) {
                textTaskString.replace(found1, 2, " ");
            }
            else {
                textTaskString.replace(found1, 2, "не");
            }
        }
    }
}