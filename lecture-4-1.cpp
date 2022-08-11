// Use case

// Write a program to manage the student's records in a classroom. Each student has a unique ID, name and grade. The program should
// be able to print all the students in the classroom, find the grade of a student based on their ID and update the grade of a student. The program
// should write the students' records to a file and also read the records from a file. 

#include <iostream>
#include <string>
#include <fstream>

#include "lecture-4-2.cpp"

using namespace std;


class Classroom
{
private:
    int class_size;
    Student* students_records;

public:
    Classroom(){
       class_size=0;
       students_records = new Student[class_size]; 
    };
    Classroom(int a_class_size){
        class_size = a_class_size;
        students_records = new Student[class_size];       
        
    }
    ~Classroom(){
        delete[] students_records;
    };
    void read_students_records(string filename){
        ifstream students_records_file;
        students_records_file.open(filename);
        for(size_t i = 0; i < class_size; i++)
        {
            string name;
            int id;
            double grade;
            students_records_file >> name >> id >> grade;
            students_records[i].set_name(name);
            students_records[i].set_ID(id);
            students_records[i].set_grade(grade);

        }
    }
    void print_classroom(){
        for (size_t i = 0; i<class_size; i++)
        {
            cout << students_records[i].get_name() << " | " << students_records[i].get_ID() << " | " << students_records[i].get_grade() << endl;  
        }
    }
};



int main()
{

    Classroom oop2022(3);

    oop2022.read_students_records("classroom.txt");

    oop2022.print_classroom();

    return 0;

}