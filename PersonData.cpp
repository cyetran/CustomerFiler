include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#include "person.h"

// Constructor for the Person class.
Person::Person() {
    age = 0;
    gender = "default";
    yearlyIncome = 0;
    return;
}

// Print the Person class.
void Person::Print() {
    cout << "Age = " << this->age
         << ", gender = " << this->gender
         << ", yearly income = " << this->yearlyIncome
         << endl;
    return;
}

// Set the age, gender, and yearlyIncome of a Person.
void Person::SetData(int a, string gender, int yearlyIncome) {   // FIXME Also set gender and yearly income
    this->age = a;
    this->gender = gender;
    this->yearlyIncome = yearlyIncome;
    return;
}

// Get the age, gender, and yearlyIncome of a Person.
int Person::GetAge() {
    return this->age;
}

int Person::GetIncome(){
    return this ->yearlyIncome;
}

string Person::GetGender(){
    return this ->gender;
}

// Get a filename from program arguments, then make a Person for each line in the file.
bool ReadPeopleFromFile(int argc, char* argv[], vector<Person> &people) {
    Person tmpPrsn;
    ifstream inFS;
    int tmpAge = 0;
    string tmpGender = "";
    int tmpYI = 0;
    
    if (argc != 2) {
        cout << "\nUsage: [EXECUTABLE FILE] [TEXT DATA FILE], e.g. myprog.exe dev_people.txt" << endl;
        return true; // indicates error
    }
    
    cout << "Opening file " << argv[1] << ".\n";
    inFS.open(argv[1]); // Try to open file
    if (!inFS.is_open()) {
        cout << "Could not open file " << argv[1] << ".\n";
        return true; // indicates error
    }
    
    while (!inFS.eof()) {
        inFS >> tmpAge;
        inFS >> tmpGender;
        inFS >> tmpYI;
        tmpPrsn.SetData(tmpAge,tmpGender,tmpYI);
        tmpPrsn.Print();
        people.push_back(tmpPrsn);
    }
    inFS.close();
    cout << "Finished reading file." << endl;
    
    return false; // indicates no error
}

// Ask user to enter age range.
void GetUserInput(int &ageLowerRange, int&ageUpperRange, string&gender, int&yILowerRange, int&yIUpperRange) {
    cout<<"\nEnter lower range of age: ";
    cin >> ageLowerRange;
    
    cout << "Enter upper range of age: ";
    cin >> ageUpperRange;
    
    cout<<"Enter gender(female, male, or any): ";
    cin >> gender;
    
    cout<<"Enter lower range of yearly income: ";
    cin >> yILowerRange;
    
    cout<<"Enter upper range of yearly income: ";
    cin >> yIUpperRange;
    
    return;
}

// Return people within the given age range.
vector<Person> GetPeopleInAgeRange(vector<Person> ppl, int lowerRange, int upperRange) {
    unsigned int i = 0;
    
    vector<Person> pplInAgeRange;
    int age = 0;
    for (i = 0; i < ppl.size(); ++i) {
        age = ppl.at(i).GetAge();
        if ((age >= lowerRange) && (age <= upperRange)) {
            pplInAgeRange.push_back(ppl.at(i));
        }
    }
    
    return pplInAgeRange;
}

//Return people within the given gender.
vector<Person> GetPeopleWithSpecificGender(vector<Person> ppl, string pergender) {
    unsigned int j = 0;
    
    vector<Person> pplWithSpecificGender;
    for (j= 0; j < ppl.size(); j++)  {
       string tmpgender = ppl.at(j).GetGender();
        if ((pergender == pergender) || (pergender == "any")) {
            pplWithSpecificGender.push_back(ppl.at(j));
        }
    }
    return pplWithSpecificGender;
}


// Return people within the given income range.
vector<Person> GetPeopleInIncomeRange(vector<Person> ppl, int iLowerRange, int iUpperRange) {
    unsigned int f = 0;
    
    vector<Person> pplInIncomeRange;
    int income = 0;
    for(f= 0; f < ppl.size(); ++f) {
        income = ppl.at(f).GetIncome();
        if ((income >= iLowerRange) && (income <=iUpperRange)) {
            pplInIncomeRange.push_back(ppl.at(f));
        }
    }
    return pplInIncomeRange;
}


int main(int argc, char* argv[]) {
    vector<Person> ptntlCstmrs;
    bool hadError = false;
    int ageLowerRange = 0;
    int ageUpperRange = 0;
    string gender = "";
    int yILowerRange = 0;
    int yIUpperRange = 0;
    
    hadError = ReadPeopleFromFile(argc, argv, ptntlCstmrs);
    if( hadError ) {
        return 1; // indicates error
    }
    
    GetUserInput(ageLowerRange, ageUpperRange, gender, yILowerRange, yIUpperRange);
    ptntlCstmrs = GetPeopleInAgeRange(ptntlCstmrs, ageLowerRange, ageUpperRange);
    ptntlCstmrs = GetPeopleInIncomeRange(ptntlCstmrs, yILowerRange, yIUpperRange);
    ptntlCstmrs = GetPeopleWithSpecificGender(ptntlCstmrs, gender);
    
   
    cout << "\nNumber of potential customers = "<<ptntlCstmrs.size() << endl;
    
    return 0;
}
