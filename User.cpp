//
// Created by szymu on 18.02.2023.
//

#include "User.h"
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, const User &user){
    os<<"Name: "<<user.UserName<<" "<<user.UserSurname<<
      "\nAge: "<<user.UserAge<<" y/o\nWeight: "<<user.UserWeight<<" kg"<<std::endl;
    return os;
}

std::string User::getUserName() const{
    return UserName;
}

std::string User::getUserSurname() const{
    return UserSurname;
}

unsigned int User::getUserAge() const{
    return UserAge;
}

double User::getUserWeight() const{
    return UserWeight;
}

void User::setUserName(std::string name) {
    UserName=name;
}

void User::setUserSurname(std::string surname) {
    UserSurname=surname;
}

void User::setUserAge(int age) {
    UserAge=age;
}

void User::setUserWeight(double weight) {
    UserWeight=weight;
}