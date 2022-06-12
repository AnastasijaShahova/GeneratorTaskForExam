#include "Task14.h"
#include <math.h>
#include <Python.h>


static const char *VALUE= "%1%^%2% %3% %4%^%5% %6% %7%^%8% %9% %10%";

Task14::Task14(int num)
{
    table = std::make_unique<DataTask>(14);
    vectorId = table->getVectorId(num);
}

//ищет дубликаты в векторе
void Task14::hasDuplicate(std::vector<int>& v)
{
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = i+1; j < 3; ++j)
            // если такой дубликат есть, то перегенерируем значение
            if (v[i] == v[j] && v[i+3] == v[j+3]) {
                v[i+3] = generator.random(128, 4000).Mt19937();
            }
}

void Task14::genRandFor14Task(int count, std::vector<int>& number)
{
    // первые три - основания, затем 3 числа - степень, последнее число - число без степени
    for(int i = 0; i < count  ; ++i)
    {
        if (i < 3) {
            number.push_back(base[generator.random(0, 3).Mt19937()]);
        }
        if (i >= 3 && i != count -1){
            number.push_back(generator.random(128, 4000).Mt19937());
        }
        else {
            number.push_back(generator.random(5, 1024).Mt19937());
        }
    }

    //Необходимо проверить, нет ли одинаковых чисел с одинаковыми степенями
    hasDuplicate(number);
    for (int i = 0; i < 3; ++i) {
        int rand = GetRandomNumber(0,1);

        if (rand == 0) {
            vec_sign.push_back("+");
        } else {
            vec_sign.push_back("-");
        }
    }
}

void Task14::solutionTask(Type type)
{
    switch (type) {
        // Нужно генерировать основание, степень и знак
        // Сколько нулей содержится в двоичной записи
        case type1:
        {
            genRandFor14Task(7, number_);
            solverType1();
            break;
        }
        // Сколько  единиц содержится
        case type2:
        {
            genRandFor14Task(7, number_);
            solverType2();
            break;
        }
        default:
            break;
    }
}

void convertToPyList(const std::vector<int> &number) {
    Py_Initialize();
    PyObject *list_term, *degree, *sign, *val1, *val2, *val3;
    list_term = PyList_New(3);
    for (int i = 0; i < 3;++i) {
        PyList_SetItem(list_term,i, PyLong_FromLong(number[i]));
    }


    Py_Finalize();
}

void Task14::solverType1()
{
    Py_Initialize();
    PyObject* myModuleString = PyUnicode_FromString((char*)"number14");
    PyObject* myModule = PyImport_Import(myModuleString);

    PyObject *list_term, *degree, *sign;
    int last_term = number_.at(6);

    list_term = PyList_New(3);
    for (int i = 0; i < 3;++i) {
        PyList_SetItem(list_term,i, PyLong_FromLong(number_[i]));
    }

    degree = PyList_New(3);
    for (int i = 0; i < 3;++i) {
        PyList_SetItem(list_term,i, PyLong_FromLong(number_[i+3]));
    }
    sign = PyList_New(3);
    for (int i = 0; i < 3;++i) {
        PyList_SetItem(list_term,i, Py_BuildValue(vec_sign[i]));
    }

    PyObject* myFunction = PyObject_GetAttrString(myModule,(char*)"solver");
    PyObject* args = PyTuple_Pack(4, list_term, degree, sign, last_term, 0);

    PyObject* myResult = PyObject_CallObject(myFunction, args);
    Py_Finalize();
    int result = PyFloat_AsDouble(myResult);

    number_.push_back(result);
    table->putTableAnswer(number_);
}

void Task14::solverType2()
{
    Py_Initialize();
    PyObject* myModuleString = PyUnicode_FromString((char*)"number14");
    PyObject* myModule = PyImport_Import(myModuleString);

    PyObject *list_term, *degree, *sign;
    int last_term = number_.at(6);

    list_term = PyList_New(3);
    for (int i = 0; i < 3;++i) {
        PyList_SetItem(list_term,i, PyLong_FromLong(number_[i]));
    }

    degree = PyList_New(3);
    for (int i = 0; i < 3;++i) {
        PyList_SetItem(list_term,i, PyLong_FromLong(number_[i+3]));
    }
    sign = PyList_New(3);
    for (int i = 0; i < 3;++i) {
        PyList_SetItem(list_term,i, Py_BuildValue(vec_sign[i]));
    }

    PyObject* myFunction = PyObject_GetAttrString(myModule,(char*)"solver");
    PyObject* args = PyTuple_Pack(4, list_term, degree, sign, last_term, 1);

    PyObject* myResult = PyObject_CallObject(myFunction, args);
    Py_Finalize();
    int result = PyFloat_AsDouble(myResult);

    number_.push_back(result);
    table->putTableAnswer(number_);
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
    textTaskString += (StrFormat(VALUE) % number_.at(0) % number_.at(3) % vec_sign.at(0) % number_.at(1) % number_.at(4) % vec_sign.at(1) % number_.at(2) % number_.at(5) % vec_sign.at(2) % number_.at(6)).str();
}

int Task14::getNumber()
{

    return number_.back();
}

void Task14::checkResult(int result) {

}