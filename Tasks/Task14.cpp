#include "Task14.h"
#include <math.h>


Task14::Task14(int num)
{
    table = std::make_unique<DataTask>(14);
    vectorId = table->getVectorId(num);
//    BOOST_PYTHON_MODULE(hello)
//    {
//        class_<World>("to_c")
//        .def("fourteen", &World::fourteen);
//    }
}

void Task14::solutionTask(Type type)
{
    switch (type) {
        // Сколько единиц содержится в двоичной записи
        case type1:
        {
            //Будет 4 числа всегда , затем отдельно генеррировать число 1 или 0 для формулировки вопроса
            std::vector<int> limitVec = { 9, 5, 10 };
            genRand(4, limitVec, number_);
            if (number_.front() < number_.back()) {
                std::swap(number_[0], number_[1]);
            }
            solverType1();
            break;
        }
        // Укажите основание
        case type2:
        {
            std::vector<int> limitVec = { 9, 5};
            if (number_.front() < number_.back()) {
                std::swap(number_[0], number_[1]);
            }
            genRand(2, limitVec, number_);
            solverType2();
            break;
        }
        // Решите уравнение
        case type3:
        {
            std::vector<int> limitVec = { 6, 8 };
            genRand(2, limitVec, number_);
            if (number_.at(0) > number_.at(1)) {
                std::swap(number_[0], number_[1]);
            } else if (number_.at(0) == number_.at(1)) {
                number_.at(0) = rand() % (number_.at(1) - 1);
            }
            solverType3();
            break;
        }
        //
        case type4:
        {
            std::vector<int> limitVec = { 5, 5, 240 };
            genRand(3, limitVec, number_);
            if (number_.at(0) < number_.at(1)) {
                std::swap(number_[0], number_[1]);
            }
            solverType4();
            break;
        }
        default:
            break;
    }
}

void Task14::solverType1()
{
}

void Task14::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    replacementText(text);
}

void Task14::replacementText(std::string& textTaskString)
{
    textTaskString = table->getTextTask();
    textTaskString += table->getTextQuestion();
    textTaskString += table->getSizeType();
    std::string t;
    for (int j = 0;  j < number_.size() - 1; ++j) {
        int found = textTaskString.find('0');
        if (found != std::string::npos) {
            textTaskString.replace(found, std::to_string(number_[j]).length(), std::to_string(number_.at(j)));

        }
    }
}

int Task14::getNumber()
{
    return number_.back();
}

void Task14::solverType2()
{


}

void Task14::solverType3()
{


}

void Task14::solverType4()
{


}

void Task14::checkResult(int result) {

}