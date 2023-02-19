#include <iostream>
#include <string>
#include "User.h"
#include <vector>
#include <stdlib.h>
#include <iomanip>

//Function declaration
void displayUsers(std::vector<User>users);
void displayMainMenu(std::vector<User>&users);
void addUser(std::vector<User>&users);
void displayUserMenu(User &user);
void changePersonalInformation(User &user);
//end of declaration

void changePersonalInformation(User &user){
    std::string newName;
    int age;

    std::cout<<"Enter new first name: ";
    std::cin.ignore();
    getline(std::cin,newName);
    user.setUserFirstName(newName);

    std::cout<<"Enter new last name: ";
    getline(std::cin,newName);
    user.setUserLastname(newName);

    std::cout<<"Enter new age: ";
    std::cin>>age;
    user.setUserAge(age);
}

void displayUserMenu(User &user) {
    int select=1;
    while(select!=0) {
        system("cls");

        std::cout << user << std::endl;

        std::cout << "Training plan:" << std::endl;
        user.displayExercises();

        std::cout << std::endl;
        std::cout << std::left<<std::setw(25)<<"1. Add exercise."<<"4. Change personal information."<<std::endl;
        std::cout << std::left<<std::setw(25)<<"2. Delete exercise."<<"5. Change user weight."<<std::endl;
        std::cout << std::left<<std::setw(25)<<"3. Update exercise."<<"0. Return."<<std::endl;
        std::cout<<"Enter: ";
        std::cin>>select;
        switch(select){
            case 0:
                break;
            case 1:
                user.addExercise();
                break;
            case 2:
                user.deleteExercise();
                break;
            case 3:
                user.updateExercise();
                break;
            case 4:
                changePersonalInformation(user);
                break;
            case 5:
                std::cout<<"Enter new weight:";
                double weight;
                user.setUserWeight(weight);
                break;
            default:
                std::cout<<"Wrong choice, try again."<<std::endl;
        }
    }
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

        std::cout << "\nType '+' to add another profile."
                     "\nType '0' to exit."
                     "\nEnter your profile: ";
        std::cin >> select;

        if(select=='+')
            addUser(users);
        else if(select=='0')
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
