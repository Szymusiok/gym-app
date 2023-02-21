//
// Created by szymu on 18.02.2023.
//

#include "User.h"
#include "Exercise.h"
#include <iostream>
#include <string>
#include <iomanip>

bool isValidNumber0(std::string word){
    for (char const letter : word)
        if(std::isdigit(letter)==0)
            return false;
    return true;
}

std::ostream &operator<<(std::ostream &os, const User &user){
    os << "Name: " << user.UserFirstName << " " << user.UserLastname <<
       "\nAge: " << user.UserAge<<" y/o\nWeight: "<<user.UserWeight<<" kg"<<std::endl;
    return os;
}

std::string User::getUserFirstName() const{
    return UserFirstName;
}

std::string User::getUserLastname() const{
    return UserLastname;
}

unsigned int User::getUserAge() const{
    return UserAge;
}

double User::getUserWeight() const{
    return UserWeight;
}

void User::setUserFirstName(std::string name) {
    UserFirstName=name;
}

void User::setUserLastname(std::string surname) {
    UserLastname=surname;
}

void User::setUserAge(int age) {
    UserAge=age;
}

void User::setUserWeight(double weight) {
    UserWeight=weight;
}

void User::addExercise() {
    std::string exerciseName;

    std::cout<<"Enter name: ";
    std::cin.clear();
    getline(std::cin,exerciseName);
    if(exerciseName.size()>25)
        throw 4;

    UserExercises.push_back(Exercise(exerciseName));
    std::cout<<"Exercise "<<exerciseName<<" added succesfully!"<<std::endl;
}

void User::deleteExercise() {
    std::string select;
    std::cout<<"Which exercise you want to delete: ";
    getline(std::cin,select);

    if(!isValidNumber0(select))
        throw 2;
    if(std::stoi(select)==0 || std::stoi(select)>UserExercises.size())
        throw 3;

    UserExercises.erase(UserExercises.begin() + stoi(select) - 1);

    std::cout<<"Exercise deleted succesfully!"<<std::endl;
}

void User::updateExercise() {
    double ExerciseWeight;
    unsigned int ExerciseSeries, ExerciseReps;
    int Select;

    std::cout<<"Which exercise you want to update: ";
    std::cin>>Select;

    std::cout<<"Enter new weight: ";
    std::cin>>ExerciseWeight;
    UserExercises.at(Select-1).setExerciseWeight(ExerciseWeight);

    std::cout<<"Enter number of series: ";
    std::cin>>ExerciseSeries;
    UserExercises.at(Select-1).setExerciseSeries(ExerciseSeries);

    std::cout<<"Enter number of reps: ";
    std::cin>>ExerciseReps;
    UserExercises.at(Select-1).setExerciseReps(ExerciseReps);

    std::cout<<"Exercise udpated succesfully!"<<std::endl;
}

void User::displayExercises() {
    if(UserExercises.empty())
        std::cout<<"There are no exercises, add some!"<<std::endl;
    else {
        int ID = 1;
        std::cout << std::left << std::setw(3) << "ID" << std::left << std::setw(25) << "Name" << std::left
                  << std::setw(8) << "Weight" << std::left << std::setw(8) << "Series" << std::left << std::setw(8)
                  << "Reps" << std::endl;
        for (Exercise exercise: UserExercises) {
            std::cout << ID << ". " << exercise;
            ID++;
        }
    }
}