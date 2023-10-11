#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "main.h"


// compile: g++ -o main.exe main.cpp admin.cpp  -I C:\Users\Golden\Desktop\vscode\c++\cpp\projects\bus\main.h

enum USER_INPUT
{
    QUIT = 0,
    ADMIN = 1,
    USER = 2,
};

enum ADMIN
{
   
    ADD = 1,
    LIST = 2,
    MODIFY = 3,
    DELETE = 4,
    EXIT = 5,
    
};

enum USER
{
    BUS_LIST = 1,
    SCHEDULE = 2,
};

int main()
{
    bool prog_is_running = true; // program while loop

    // CLASS OBJECT
    Admin::Admin admin; 
    Bus::Bus bus;
    Client::Client client;

    // vector
    std::vector<Admin::Admin> bus_lists;


    while(prog_is_running)
    {

           std:: cout << "Enter 1: Admin\n"
                         "Enter 2: User\n"
                         "Enter 0: to exit\n";
           int x; // user input
           std::cin>>x;
        switch(x)
        {
            case ADMIN:
            std:: cout <<"Press 1: to add\n" 
                        "Press 2: to list\n"
                        "Press 3: to modify\n"
                        "Press 4: to delete\n"
                        "Press 5: to exit\n";
            int x1;
            std::cin>>x1;
            std::cin.ignore(1000, '\n'); // escape newline
            if(x1 == ADD)
            {
                admin.add(bus_lists);
                bus_lists.push_back(admin);
                x1 = 0; // resetting admin choices
                break;
            }
            else if(x1 == LIST)
            {
                admin.list(bus_lists);
                x1 = 0;  // resetting admin choices
                break;
            }

            else if(x1 == MODIFY)
            {
                std::cout << "Enter the Bus Numer you want to modify" << std::endl;
                int index;
                std::cin>>index;
                bus.modify(bus_lists, index); // modifying the bus object
                x1 = 0;
                break;
            }
            else if(x1 == DELETE)
            {
                std::cout << "Enter the bus number you want to delete " << std::endl;
                int x2;
                std::cin>>x2;
                admin.del(bus_lists, x2);
                x1 = 0;  // resetting admin choices
                break;
            }
            else if(x1 == EXIT)
            {   x1 = 0; //  // resetting admin choices
                break;
            }

            case USER:
            std::cout<< "Press 1: to List the buses \n"
                        "Press 2 : to List the schedule \n";
            int x;
            std::cin>>x;
            if(bus_lists.size() == 0)
            {
                std::cout<< "No data is found. If you are an Admin try to add some data" << std::endl;
                break;
            }
            if(x == BUS_LIST)
            {
                client.list_bus(bus_lists);
                break;
            }
            else if(x == SCHEDULE)
            {
                client.list_schedule();
                break;
            }

            case QUIT:
            prog_is_running = false;
            break;

        }

    }
 
    return 0;
}