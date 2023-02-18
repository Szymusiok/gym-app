//
// Created by szymu on 18.02.2023.
//

#ifndef GYM_APP_USER_H
#define GYM_APP_USER_H

#include "Exercise.h"
#include <iostream>
#include <string>
#include <vector>


class User {
    friend std::ostream &operator<<(std::ostream &os, const User &user);
private:
    std::string UserName;
    std::string UserSurname;
    unsigned int UserAge;
    double UserWeight;

    std::vector<Exercise>UserExercises;
public:
    User() = default;
    User(std::string name, std::string surname, unsigned int age, double weight)
    : UserName{name}, UserSurname{surname}, UserAge{age}, UserWeight{weight} {}
    ~User() = default;

    std::string getUserName() const;
    std::string getUserSurname() const;
    unsigned int getUserAge() const;
    double getUserWeight() const;

    void setUserName(std::string name);
    void setUserSurname(std::string surname);
    void setUserAge(int age);
    void setUserWeight(double weight);

    void addExercise();
    void deleteExercise();
    void updateExercise();
    void displayExercises();
};


#endif //GYM_APP_USER_H
