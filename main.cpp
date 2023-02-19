#include <iostream>
#include <string>
#include "User.h"
#include <vector>
#include <stdlib.h>

//Function declaration
void displayUsers(std::vector<User>users);
void displayMainMenu(std::vector<User>&users);
void addUser(std::vector<User>&users);
void displayUserMenu(User user);
//end of declaration

void displayUserMenu(User user) {
    system("cls");

    std::cout << user;

    std::cout << "Training plan"<<std::endl<<std::endl;
    user.displayExercises();
}

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

    std::cin.ignore();
    std::cout << "Enter the first name: ";
    getline(std::cin,UserFirstName);
    std::cout << "Enter the last name: ";
    getline(std::cin,UserLastName);
    std::cout << "Enter user age: ";
    std::cin >> UserAge; //todo: only int
    std::cout << "Enter user weight: ";
    std::cin >> UserWeight; //todo only double
    users.emplace_back(UserFirstName, UserLastName, UserAge, UserWeight);

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

void displayMainMenu(std::vector<User>&users){
    char select='1';

    while(select!='x') {
        std::cout << "GYM PROGRESS TRACKING APP" << std::endl << std::endl;
        if (users.empty())
            std::cout << "There are no users, add some!" << std::endl << std::endl;
        else
            displayUsers(users);

        std::cout << "\nType '0' to add another profile."
                     "\nType 'x' to exit."
                     "\nEnter your profile: ";
        std::cin >> select;

        if(select=='0')
            addUser(users);
        else if(select=='x')
            break;
        else if(int(select)-48>=1&&int(select)-48<=users.size()) //todo: readme why that
            displayUserMenu(users.at(int(select)-49));
        else
            std::cout<<"Wrong choice, try again."<<std::endl;
        system("pause");
        system("cls");
    }

}

int main() {
    std::vector<User>users;

    users.emplace_back("Szymon","Kubica",21,85);

    displayMainMenu(users);

    return 0;
}
