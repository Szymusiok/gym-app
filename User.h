//
// Created by szymu on 18.02.2023.
//

#ifndef GYM_APP_USER_H
#define GYM_APP_USER_H

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
public:
    std::string getUserName() const;
    std::string getUserSurname() const;
    unsigned int getUserAge() const;
    double getUserWeight() const;

    void setUserName(std::string name);
    void setUserSurname(std::string surname);
    void setUserAge(int age);
    void setUserWeight(double weight);
};


#endif //GYM_APP_USER_H
