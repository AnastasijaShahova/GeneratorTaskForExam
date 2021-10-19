#ifndef UNTITLED5_RANDOMGENERATOR_H
#define UNTITLED5_RANDOMGENERATOR_H
#include <random>

class Random
{
private:
    int low_;
    int high_;
    std::uniform_int_distribution<> dist_;
public:
    Random(int low, int high) : low_(low), high_(high), dist_(low, high){}
    int DefaultRandomEngine()
    {
        static std::default_random_engine e;
        return dist_(e);
    }
    int Mt19937()
    {
        static std::mt19937 e;
        return dist_(e);
    }
    int rand()
    {
        return rand() % high_ + low_;
    }
};

class Distribution
{
public:
    Distribution(){}
    Random random(int low, int high)
    {
        Random rnd(low, high);
        return rnd;
    }

};

template<int min = std::numeric_limits<int>::min(),
        int max = std::numeric_limits<int>::max()>
class RandomGenerator {
public:
    RandomGenerator()
    {
        std::random_device rd;
        generator_.seed(rd());
    }
    ~RandomGenerator() = default;

    int operator()()
    {
        return distribution_(generator_);
    }

protected:
    std::uniform_int_distribution<int> distribution_{min, max};
    std::mt19937 generator_;
};
#endif //UNTITLED5_RANDOMGENERATOR_H
