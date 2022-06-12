#include "Task4.h"
#include <math.h>
#include "../Utils/AlgorithmShannon.h"

const std::string rus = {"АБВГДЕЁЖЗИӢКЛМНОПРСТУФХЦЧШЩЫЭЮЯ"};


Task4::Task4(int num)
{
    table = std::make_unique<DataTask>(4);
    vectorId = table->getVectorId(num);
}

std::string delete_dupl(std::string word) {

    int n,m;
    std::string out_word;

    for (n = 0; n < word.size(); n++) {
        if (word[n] == word[n + 1]) {
            word.erase(n, 1);
        }
    }
    out_word = word;
    for (n = 0; n < word.size(); n++) {
        for (m = n + 1; m < out_word.size() + 1; m++) {
            if (word[n] == out_word[m]) {
                out_word.erase(m, 1);
            }
        }
    }

    return out_word;
}

int different_num(std::string word) {

    std::string text = word;
    size_t size=text.size();

    int count = 1;
    int sum_different = 0;
    std::map <char, float> m;


    for (size_t i = 0; i < size; i++)
    {
        if(isupper(text[i])) text[i]=tolower(text[i]);
        if(isalpha(text[i])) m[text[i]]++;
    }


    for (auto i = m.begin(); i != m.end(); i++) {

        sum_different = count;
        count += 1;
    }

    return sum_different;
}

void Task4::solutionTask(Type type)
{
    switch (type) {
        case type1:
        {
            solverType1();
            break;
        }
        default:
            break;
    }
}

void Task4::checkResult(int result)
{
}

void Task4::solverType1()
{
    int n;
    generationAlphabet(7, alphabet);
    while (n < 4) {
        question_word.clear();
        for (int k = 0; k < 5; k++) {
            int rand_num = rand() % 7;
            question_word.push_back(alphabet[rand_num]);
        }
        n = different_num(question_word);
    }
    std::string out_word = delete_dupl(question_word);
    int res;
    shenon->solver(alphabet,question_word,binary, res, n);
    number_.push_back(res);
    table->putTableAnswer(number_);
}

void Task4::createTask(int id, int number, std::string& text, int& answer)
{
    table = std::make_unique<DataTask>(number, id);
    number_.clear();
    solutionTask(table->getTypeFromString(table->getTypeTask()));
    answer = number_.back();
    replacementText(text);
}

void Task4::replacementText(std::string& textTaskString)
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

int Task4::getNumber()
{
    return number_.back();
}

void Task4::generationAlphabet(int count, std::vector<char> &alphabet)
{
    for(int i = 0; i < count; ++i) {
        int rnd = rand() % rus.length();
        alphabet.push_back(rus[rnd]);
    }
}
