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
    std::string select, exerciseSeries, exerciseReps,exerciseWeight;

    std::cout<<"Which exercise you want to update: ";
    getline(std::cin,select);
    if(!isValidNumber0(select))
        throw 2;
    if(std::stoi(select)==0 || std::stoi(select)>UserExercises.size())
        throw 3;

    std::cout<<"Enter new weight: ";
    getline(std::cin,exerciseWeight);
    if(!isValidNumber0(exerciseWeight))
        throw 2;
    UserExercises.at(std::stoi(select)-1).setExerciseWeight(std::stoi(exerciseWeight));


    std::cout<<"Enter number of series: ";
    getline(std::cin,exerciseSeries);
    if(!isValidNumber0(exerciseSeries))
        throw 2;
    UserExercises.at(std::stoi(select)-1).setExerciseSeries(std::stoi(exerciseSeries));

    std::cout<<"Enter number of reps: ";
    getline(std::cin,exerciseReps);
    if(!isValidNumber0(exerciseReps))
        throw 2;
    UserExercises.at(std::stoi(select)-1).setExerciseReps(std::stoi(exerciseReps));

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

void User::readExercise(std::string name, double weight, unsigned int series, unsigned int reps) {
    UserExercises.push_back(Exercise(name,weight,series,reps));
}