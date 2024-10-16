#include <iostream>
#include <sstream>

class Name {
    std::string fname, lname, mname;

    public:
        Name(std::string lname = "", std::string fname = "", std::string mname = "") : lname(lname), fname(fname), mname(mname) {}
        ~Name() {}

        void setName(std::string lname = "", std::string fname = "", std::string mname = "") {
            this->lname = lname;
            this->fname = fname;
            this->mname = mname;
        }

        void setLname(std::string lname = "") {
            this->lname = lname;
        }

        void setFname(std::string fname = "") {
            this->fname = fname;
        }

        void setMname(std::string mname = "") {
            this->mname = mname;
        }

        std::string getLname() {
            return lname;
        }

        std::string getFname() {
            return fname;
        }

        std::string getMname() {
            return mname;
        }

        char getMnameInitial() {
            return mname[0];
        }

        std::string toString() {
            if (mname.empty()) {
                return fname + " " + mname + " " + lname;
            } else {
                return fname + " " + lname;
            }
        }

        void display() {
            std::cout << fname + " " + (mname.empty() ? "" : std::string(1, mname[0]) + " ") +  lname << std::endl;
        }
};

class Date {
    int day, month, year;
    
    public:
        Date(int year = 0, int month = 0, int day = 0) : year(year), month(month), day(day) {}
        ~Date() {}

        void setDate(int day, int month, int year) {
            this->day = day;
            this->month = month;
            this->year = year;
        }

        void setYear(int year) {
            this->year = year;
        }

        void setMonth(int month) {
            this->month = month;
        }

        void setDay(int day) {
            this->day = day;
        }

        int getYear() {
            return year;
        }

        int getMonth() {
            return month;
        }

        int getDay() {
            return day;
        }

        std::string toString() {
            std::stringstream ss;
            ss << day << "." << month << "." << year;
            return ss.str();
        }

        void display() {
            std::cout << toString() << std::endl;
        }
};

class Employee {
    int empID;
    Name name;
    Date empDOB, empDOJ;

    public:
        Employee(int empID = 0, Name name = Name(), Date empDOB = Date(), Date empDOJ = Date()) : empID(empID), name(name), empDOB(empDOB), empDOJ(empDOJ) {}
        ~Employee() {}

        void setEmpID(int empID) {
            this->empID = empID;
        }

        void setName(std::string lname = "", std::string fname = "", std::string mname = "") {
            name = Name(lname, fname, mname);
        }

        void setEmpDOB(int year = 0, int month = 0, int day = 0) {
            empDOB = Date(year, month, day);
        }

        void setEmpDOJ(int year = 0, int month = 0, int day = 0) {
            empDOJ = Date(year, month, day);
        }

        int getEmpID() {
            return empID;
        }

        Name getName() {
            return name;
        }

        Date getEmpDOB() {
            return empDOB;
        }

        Date getEmpDOJ() {
            return empDOJ;
        }

        std::string toString() {
            std::stringstream ss;
            ss << "Employee ID: " << empID << "\nEmployee name: " << name.toString() << "\nDate of birth: " << empDOB.toString() << "\nDate joined: " << empDOJ.toString();
            return ss.str();
        }

        void display() {
            std::cout << toString() << std::endl;
        }
};

class HourlyEmployee : public Employee {
    float totalHoursWorked;
    double ratePerHour;

    public:
        HourlyEmployee(int empID = 0, Name name = Name(), Date empDOB = Date(), Date empDOJ = Date(), float totalHoursWorked = 0, double ratePerHour = 0) : Employee(empID, name, empDOB, empDOJ), totalHoursWorked(totalHoursWorked), ratePerHour(ratePerHour) {}
        ~HourlyEmployee() {}

        void setTotalHoursWorked(float totalHoursWorked) {
            this->totalHoursWorked = totalHoursWorked;
        }

        void setRatePerHour(double ratePerHour) {
            this->ratePerHour = ratePerHour;
        }

        float getTotalHoursWorked() {
            return totalHoursWorked;
        }

        double getRatePerHour() {
            return ratePerHour;
        }

        double computeSalary() {
            if (totalHoursWorked <= 40) {
                return totalHoursWorked * ratePerHour;
            }
            return (40 * ratePerHour) + (totalHoursWorked - 40) * 1.5;
        }

        std::string toString() {
            std::stringstream ss;
            ss << Employee::toString() << "\nTotal hours worked: "<< totalHoursWorked << "\nRate per hour: " << ratePerHour;
            return ss.str();
        }
        
        void display() {
            std::cout << toString() << std::endl;
        }
};

int main(int argc, char **argv) {
    HourlyEmployee emp(1, Name("Doe", "John", "Horace"), Date(2000, 1, 1), Date(2024, 6, 15), 10.5, 5.3);
    emp.display();
    return 0;
}