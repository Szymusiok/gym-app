#include <iostream>
#include <string>
#include "User.h"
#include <vector>
#include <stdlib.h>

size_t SELECTED_USER;

void displayUsers(std::vector<User>users);
void displayUsersMenu(std::vector<User>&users);

void addUser(std::vector<User>&users);

void addUser(std::vector<User>&users){
    system("cls");
    std::cout<<"Creating new user."<<std::endl<<std::endl;
//    std::cout<<"If you want to return, enter 0."<<std::endl;
//    int returnSign;
//    std::cin>>returnSign;

    std::string UserFirstName;
    std::string UserLastName;
    unsigned int UserAge;
    double UserWeight;

    std::cout << "Enter the first name: ";
    std::cin >> UserFirstName;
    std::cout << "Enter the last name: ";
    std::cin >> UserLastName;
    std::cout << "Enter user age: ";
    std::cin >> UserAge;
    std::cout << "Enter user weight: ";
    std::cin >> UserWeight;
    users.push_back(User(UserFirstName, UserLastName, UserAge, UserWeight));

    std::cout<<"\nCreated a new user!"<<std::endl<<std::endl;
    system("pause");
    system("cls");
}

void displayUsers(std::vector<User>users){
    int ID = 1;
    for (User user : users){
        std::cout << ID << ". " << user.getUserFirstName() << " " << user.getUserLastname() << std::endl;
        ID++;
    }
}

void displayUsersMenu(std::vector<User>&users){
    std::cout<<"GYM PROGRESS TRACKING APP"<<std::endl<<std::endl;
    if(users.empty())
        std::cout<<"There are no users, add some!"<<std::endl<<std::endl;
    else
        displayUsers(users);

    std::cout<<"\nSelect your profile or type '0' to add another one: ";
    int select;
    std::cin>>select;

    if(select==0)
        addUser(users);
    else
        SELECTED_USER = select;
        //TODO: menu of user with his plan etc.
}

int main() {
    std::vector<User>users;

    users.emplace_back("Szymon","Kubica",21,85);
    while(true) {
        displayUsersMenu(users);
    }

    return 0;
}
