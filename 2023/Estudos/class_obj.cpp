#include <bits/stdc++.h>
using namespace std;

class Student
{
    public:

        // Atributos
        int id, age;
        int numberTests;
        double sumGrades;

        // Construtores
        Student(int age, int id, int numberTests, double sumGrades)
        {
            this->id = id;
            this->age = age;
            this->numberTests = numberTests;
            this->sumGrades = sumGrades;
        }

        // Métodos
        double getGradesAverage()
        {
            double average = this->sumGrades/this->numberTests;
            return average;
        }
};

main(){
    Student dantovisk(17, 0123, 5, 40);
    cout<<dantovisk.getGradesAverage();
}