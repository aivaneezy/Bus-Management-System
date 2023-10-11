#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>


namespace Admin
{
    class Admin
    {
    public:
        void add(std::vector<Admin> &b_lists);
        void list(std::vector<Admin> &b_lists);
        void set_busName();
        void set_busId();
        void set_companyName();
        void set_departureTime();
        void set_newArrivalTime();
        std::string get_departTime();
        std::string get_arrivalTime();
        void del(std::vector<Admin> &b_lists, int index);
    protected:
        std::string bus_Name;
        std::string bus_Id;
        std::string bus_Company;    
        std::string departure_time;
        std::string arrival_time;


        std::string newBusName;
        std::string newBusId;
        std::string newComName;
        std::string newDepartureTime;
        std::string newArrivalTime;
    };
};

namespace Bus
{
    class Bus: public Admin::Admin
    {
    public:
    void modify(std::vector<Admin> &b_lists, int index);
    };
};

namespace Client
{
    class Client: public Admin::Admin
    {
    public:
    void list_bus(std::vector<Admin> &bus_lists);
    void list_schedule();
    };
};
