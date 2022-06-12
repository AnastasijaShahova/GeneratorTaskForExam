#ifndef UNTITLED5_ALGORITHMSHANNON_H
#define UNTITLED5_ALGORITHMSHANNON_H

#include <stdio.h>
#include <string>
#include <vector>
#include <cctype>
#include <map>

class AlgorithmShannon {
public:
    struct node {
        char sym[10];
        float pro;
        int arr[20];
        int top;
    } massive[20];

    typedef struct node node;


public:
    void shannon(int l,int h,node s[]);
    std::vector<float> probability(std::string word);
    void solver(std::vector<char> alphabet, std::string &word, std::vector<std::string> &binary, int &res, int n);
};


#endif //UNTITLED5_ALGORITHMSHANNON_H
