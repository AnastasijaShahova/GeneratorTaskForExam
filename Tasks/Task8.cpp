#include "Task8.h"
#include <math.h>

const std::string rus = {"АБВГДЕЁЖЗИӢКЛМНОПРСТУФХЦЧШЩЫЭЮЯ"};
const char *question0 = "не более 0";
const char *question1 = "не менее 0 и не более 0";

Task8::Task8(int num)
{
    table = std::make_unique<DataTask>(8);
    vectorId = table->getVectorId(num);
}

int isVowel(const std::vector<char> &alphabet) {

    int count = 0;
    std::string str = "УЕОАЫЯИЮ";
    for (int i =0; i < alphabet.size(); ++i) {
        if (str.find (alphabet[i]) != std::string:: npos) {
           count++;
        }
    }
    return count;
}

void Task8::solutionTask(Type type)
{
    switch (type) {
        // Подсчет количества слов с ограничениями
        case type1:
        {
            std::vector<int> limitVec = { 9, 5 };
            genRand(2, limitVec, number_);
            if (number_.front() < number_.back()) {
                std::swap(number_[0], number_[1]);
            }
            solverType1();
            break;
        }
        // Подсчет кол-ва слов
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
        // Подсчет кол-ва разных последовательностей
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
        // Cлова
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

int Task8::getNumber()
{
    return number_.back();
}

void Task8::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    alphabet.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    if (table->getTypeTask() == "type4") {
        replacementTextForType4(text);
    } else {
        replacementText(text);
    }
}

void Task8::replacementTextForType4(std::string& textTaskString) {
    textTaskString = table->getTextTask();
    textTaskString += table->getTextQuestion();
    std::string t;
    generationAlphabet(number_.at(1), alphabet);
    // Нужен для формирования вопроса
    std::vector<std::string> vec;
    // Хранит вектор строк с последующими записями
    generateVectorChar(vec);

    for (int j = 0;  j < number_.size() - 1; ++j) {
        int found_char = textTaskString.find('1');
        if ( found_char != std::string::npos) {
            for (int i = 0 ; i < number_.at(1); ++i) {
                textTaskString.replace( found_char, 1, std::to_string(question_word[i]));
            }
            if (number_.at(1) < 5) {
                textTaskString.erase(textTaskString.length() - (5 - number_.at(1)), 2);
            }

        }
    }
}



void Task8::replacementText(std::string& textTaskString)
{
    textTaskString = table->getTextTask();
    textTaskString += table->getTextQuestion();
    std::string t;
    for (int j = 0;  j < number_.size() - 1; ++j) {
        int found = textTaskString.find('0');
        if (found != std::string::npos) {
            if (number_.at(1) == 0) {
                textTaskString += question0;
            } else {
                textTaskString += question1;
            }
            textTaskString.replace(found, std::to_string(number_[j]).length(), std::to_string(number_.at(j)));
        }
        int found_char = textTaskString.find('A');
        if ( found_char != std::string::npos) {
            replaceChar(textTaskString, found_char, alphabet);
        }

        if (textTaskString.find('1') != std::string ::npos) {
            if (isVowel(alphabet) == 0) {
                textTaskString.replace(textTaskString.find('1'), 2, "со");
            } else {
                textTaskString.erase(textTaskString.find('1'), 2);
            }
        }

    }
}

void Task8::replaceChar(std::string& textTaskString, int found_char, std::vector<char> &alphabet) {

    generationAlphabet(number_.at(1), alphabet);

    for (int i = 0 ; i < number_.at(1); ++i) {
        textTaskString.replace( found_char, 1, std::to_string(alphabet[i]));
    }
    if (number_.at(1) < 5) {
        textTaskString.erase(textTaskString.length() - (5 - number_.at(1)), 2);
    }

};

void Task8::generationAlphabet(int count, std::vector<char> &alphabet)
{
    for(int i = 0; i < count; ++i) {
        int rnd = rand() % rus.length();
        alphabet.push_back(rus[rnd]);
    }
}

void Task8::solverType2()
{
    int result = pow(number_.at(1), number_.at(0));
    number_.push_back(result);
}

void Task8::solverType1()
{
    int count = isVowel(alphabet);

    int res;
    if (count != 0) {
        res = count * pow(number_.at(1), number_.at(0));
    } else {
        res = pow(number_.at(1), number_.at(0));
    }
    number_.push_back(res);
}

void Task8::solverType3()
{
    int result;
    int rnd = rand() % 2 +1;
    // Значит условие одно
    if (rnd == 1) {
        for (int i = 0; i < number_.at(0); ++i) {
            result += pow(2,i);
        }
        number_.at(1) = 0;
    } else {

        for (int i = number_.at(0); i < number_.at(1); ++i) {
            result += pow(2,i);
        }

    }
    number_.push_back(result);
}

void Task8::solverType4()
{

    // Генерация слов для вопроса
    int rnd = rand() % number_.at(0);
    std::vector<int> vec_int;
    for (int i = 0;i < number_.at(0); ++i)
        question_word += std::to_string(rnd);

    // Полученное число
    number_.push_back(convertTo10(std::stoi(question_word)));
}

void Task8::checkResult(int result){
    table->putTableAnswer(number_);

}

// Генерация вектора строк для вывода в задаче
void Task8::generateVectorChar(std::vector<std::string> & vec) {
    for (int i=0; i < number_.at(1) -1;++i){
        std::string str(number_.at(1) -1, alphabet[0]);
        str += alphabet[i];
        vec.push_back(str);
    }

}

// Переводим в 10 сс
int Task8::convertTo10(int number) {
    int s;
    for (int i=0; i<number_.at(0); ++i) {
        s = s + (number % 10)*pow(number_.at(0),i);
        number = number / 10;
    }
    return (s+1);
}