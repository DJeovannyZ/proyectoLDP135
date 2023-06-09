#include <string>
namespace dtos {
    class Employee {
        public:
            //Constructor
            Employee(std::string name, std::string lastName, std::string addres, std::string phoneNumber, float salary, char gender, int bornDay, int bornMonth, int bornYear);
            Employee(std::string name, std::string lastName, std::string addres, std::string phoneNumber, char gender, int bornDay, int bornMonth, int bornYear);

            //Getters
            std::string getName();
            std::string getLastName();
            std::string getAddres();
            std::string getPhoneNumber();
            float getSalary();
            char getGender();
            int getBornDay();
            int getBornMonth();
            int getBornYear();

            //setters
            void setName(std::string name);
            void setLastName(std::string lastName);
            void setAddres(std::string addres);
            void setPhoneNumber(std::string phoneNumber);
            void setSalary(float salary);
            void setGender(char gender);
            void setBornDay(int bornDay);
            void setBornMonth(int bornMonth);
            void setBornYear(int bornYear);

        private:
            std::string name, lastName, address, phoneNumber;
            float salary;
            char gender[1];
            // bornDateEmployee
            int bornDay, bornMonth, bornYear;
    };
} 
