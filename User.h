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
    std::string UserFirstName;
    std::string UserLastname;
    unsigned int UserAge;
    double UserWeight;

    std::vector<Exercise>UserExercises;
public:
    User() = default;
    User(std::string name, std::string surname, unsigned int age, double weight)
    : UserFirstName{name}, UserLastname{surname}, UserAge{age}, UserWeight{weight} {}
    User(const User &copy_user)
    : UserFirstName{copy_user.UserFirstName}, UserLastname{copy_user.UserLastname}, UserAge{copy_user.UserAge}, UserWeight{copy_user.UserWeight}{}
    ~User()= default;

    std::string getUserFirstName() const;
    std::string getUserLastname() const;
    unsigned int getUserAge() const;
    double getUserWeight() const;

    void setUserFirstName(std::string name);
    void setUserLastname(std::string surname);
    void setUserAge(int age);
    void setUserWeight(double weight);

    void addExercise();
    void deleteExercise();
    void updateExercise();
    void displayExercises();

    void readExercise(std::string name, double weight, unsigned int series, unsigned int reps);
};


#endif //GYM_APP_USER_H
