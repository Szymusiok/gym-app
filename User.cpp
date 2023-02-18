//
// Created by szymu on 18.02.2023.
//

#include "User.h"
#include "Exercise.h"
#include <iostream>
#include <string>

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
    std::string ExerciseName;

    std::cout<<"Enter name: ";
    std::cin>>ExerciseName;

    UserExercises.push_back(Exercise(ExerciseName));
    std::cout<<"Exercise "<<ExerciseName<<" added succesfully!"<<std::endl;
}

void User::deleteExercise() {
    int Select;

    std::cout<<"Which exercise you want to delete: ";
    std::cin>>Select;

    UserExercises.erase(UserExercises.begin()+Select);

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
    UserExercises.at(Select).setExerciseWeight(ExerciseWeight);

    std::cout<<"Enter number of series: ";
    std::cin>>ExerciseSeries;
    UserExercises.at(Select).setExerciseWeight(ExerciseSeries);

    std::cout<<"Enter nnumber of reps: ";
    std::cin>>ExerciseReps;
    UserExercises.at(Select).setExerciseWeight(ExerciseReps);

    std::cout<<"Exercise udpated succesfully!"<<std::endl;
}

void User::displayExercises() {
    int ID = 1;
    for(Exercise exercise : UserExercises){
        std::cout<<ID<<exercise;
        ID++;
    }
}