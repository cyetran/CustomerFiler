#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person {
public:
    Person();
    void Print();
    void SetData(int a, string gender, int yearlyIncome);
    int GetAge();
    int GetIncome();
    string GetGender();
private:
    int age;
    string gender;
    int yearlyIncome;
};
#endif
