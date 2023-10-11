#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "main.h"


enum MOD_BUS
{
   BUS_NAME = 1,
   BUS_ID = 2,
   COMPANY_NAME = 3,
   DEP_TIME = 4,
   ARR_TIME = 5
};

enum SCHEDULE
{
   EXIT = 0,
   DEPARTURE_TIMEE = 1,
   ARRIVAL_TIME = 2,
 
};

// admin class
namespace Admin
{
   void Admin::add(std::vector<Admin> &b_lists)
   {
         std::cout<< "Enter the bus name: " << std::endl;
         std::getline(std::cin, bus_Name);

         std::cout <<"Enter the bus id: " << std::endl;
         std::getline(std::cin, bus_Id);

         std::cout <<"Enter the bus company name " << std::endl;
         std::getline(std::cin, bus_Company);
         
         std::cout << "Enter the departure time " << std::endl;
         std::getline(std::cin, departure_time);

         std::cout << "Enter the arrival time " << std::endl;
         std::getline(std::cin, arrival_time);
   }

   void Admin::list(std::vector<Admin> &b_lists)
   {
      int counter = 0;
      std::cout << "************"
                   "*  Welcome  *"
                   "************";
      std::cout<< "\n";
      for(int i=0; i<b_lists.size(); i++)
      {
         std::cout << "Bus number : " << counter << std::endl;
         std::cout << "Bus Name: " << b_lists[i].bus_Name << std::endl;
         std::cout << "Bus Id: " << b_lists[i].bus_Id << std::endl;
         std::cout << "Bus Company Name: " << b_lists[i].bus_Company << std::endl;
         std::cout << "Bus Departure Time: " << b_lists[i].departure_time << std::endl;
         std::cout << "Bus Arrival Time: " << b_lists[i].arrival_time << std::endl;
         counter++;
         std::cout << "\n";
      }
   }

   void Admin::set_busName()
   {
      std::cout<< "Enter a new Bus Name" << std::endl;
      std::getline(std::cin, newBusName);
      bus_Name = newBusName;
   }
   void Admin::set_busId()
   {
      std::cout << "Enter a new Bus ID" << std::endl;
      std::getline(std::cin, newBusId);
      bus_Id = newBusId;
   }

   void Admin::set_companyName()
   {
      std::cout<< "Enter a new Company Name" << std::endl;
      std::getline(std::cin, newComName);
      bus_Company = newComName;
   }
   
   void Admin::set_departureTime()
   {
      std::cout<< "Enter a new Departure Time" << std::endl;
      std::getline(std::cin, newDepartureTime);
      departure_time = newDepartureTime;

   }


   void Admin::set_newArrivalTime()
   {
      std::cout<< "Enter a new Arrival Time" << std::endl;
      std::getline(std::cin, newArrivalTime);
      arrival_time = newDepartureTime;
   }


    std::string Admin::get_departTime()
   {
      return departure_time;
   }

   
   std::string Admin::get_arrivalTime()
   {
      return arrival_time;
   }

   void Admin::del(std::vector<Admin> &b_lists, int index)
   {
      if(index >=0 && index < b_lists.size())
      {
         b_lists.erase(b_lists.begin() + index);
         std:: cout << "Bus number: " << index << " has been deleted" << std::endl;
      }
      else
      {
         std::cout << "Invalid Index" << std::endl;
      }
   }
}




// Bus class
namespace Bus
{ 
  
   void Bus::modify(std::vector<Admin> &b_lists, int index)
   {
      std:: cout << "Enter 1: To modify Bus Name\n"
                    "Enter 2: to modify Bus ID \n"
                    "Enter 3: to modify Company Name\n"
                    "Enter 4: to modify Departure Time\n"
                    "Enter 5: to modify Arrival Time\n";
      int modNum;
      std::cin>>modNum;
      std::cin.ignore(1000, '\n');

      switch(modNum)
      {
         case BUS_NAME:
         b_lists[index].set_busName();
         break;

         case BUS_ID:
         b_lists[index].set_busId();
         break;

         case COMPANY_NAME:
         b_lists[index].set_busName();
         break;

         case DEP_TIME:
         b_lists[index].set_departureTime();
         break;

         case ARR_TIME:
         b_lists[index].set_newArrivalTime();
      }
       std::cout << "Modified has been made  " << std::endl;
 
   }
};



// Client class with inherited
namespace Client
{
   void Client::list_bus(std::vector<Admin> &bus_lists)
   {
      Admin::list(bus_lists);
   }

   void Client::list_schedule()
   {
      std::cout<< "Press 1: to see the Departure Schedule\n"
                  "Press 2: to see the Arrival Schedule\n"
                  "Press 0 : To exit\n";
      int x;
      std::cin>> x;
      if(x == DEPARTURE_TIMEE)
      {
         std::cout<< "Departure Time: " << get_departTime() << std::endl;
      }
      else if(x == ARRIVAL_TIME)
      {
        std::cout<< "Arrival Time: " << get_arrivalTime()<< std::endl;
      }
    
   }
}