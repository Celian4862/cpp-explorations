#include <iostream>
#include <sstream>

// Forward declarations
class Name;
class Date;
class Employee;
class HourlyEmployee;
class PieceWorkerEmployee;
class CommissionEmployee;
class BasePlusCommissionEmployee;

int main(int argc, char **argv) {
    // Create and display a Name object
    Name name("Doe", "John", "Michael");
    name.display(); // Only displays the middle name initial
    std::cout << std::endl;

    // Create and display a Date object
    Date dob(1990, 5, 15);
    dob.display();
    std::cout << std::endl;

    // Create and display an Employee object
    Employee emp(1, name, dob, Date(2020, 1, 1));
    emp.display();
    std::cout << std::endl;

    // Create and display an HourlyEmployee object
    HourlyEmployee hourlyEmp(2, name, dob, Date(2021, 2, 1), 45, 20.0);
    hourlyEmp.display();
    std::cout << std::endl;

    // Create and display a PieceWorkerEmployee object
    PieceWorkerEmployee pieceWorkerEmp(3, name, dob, Date(2022, 3, 1), 150, 5.0);
    pieceWorkerEmp.display();
    std::cout << std::endl;

    // Create and display a CommissionEmployee object
    CommissionEmployee commissionEmp(4, name, dob, Date(2023, 4, 1), 50000);
    commissionEmp.display();
    std::cout << std::endl;

    // Create and display a BasePlusCommissionEmployee object
    BasePlusCommissionEmployee basePlusCommissionEmp(5, name, dob, Date(2024, 5, 1), 100000, 5000);
    basePlusCommissionEmp.display();
    std::cout << std::endl;
    return 0;
}

// Class definitions
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
            return (totalHoursWorked <= 40) ? totalHoursWorked * ratePerHour : (40 * ratePerHour) + (totalHoursWorked - 40) * 1.5;
        }

        std::string toString() {
            std::stringstream ss;
            ss << Employee::toString() << "\nTotal hours worked: " << totalHoursWorked << "\nRate per hour: " << ratePerHour;
            return ss.str();
        }
        
        void display() {
            std::cout << toString() << std::endl;
            std::cout << "Salary: " << computeSalary() << std::endl;
        }
};

class PieceWorkerEmployee : public Employee {
    int totalPiecesFinished;
    double ratePerPiece;

    public:
        PieceWorkerEmployee(int empID = 0, Name empName = Name(), Date empDOB = Date(), Date empDOJ = Date(), int totalPiecesFinished = 0, double ratePerPiece = 0) : Employee(empID, empName, empDOB, empDOJ), totalPiecesFinished(totalPiecesFinished), ratePerPiece(ratePerPiece) {}
        ~PieceWorkerEmployee() {}

        void setTotalPiecesFinished(int totalPiecesFinished) {
            this->totalPiecesFinished = totalPiecesFinished;
        }

        void setRatePerPiece(double ratePerPiece) {
            this->ratePerPiece = ratePerPiece;
        }

        int getTotalPiecesFinished() {
            return totalPiecesFinished;
        }

        double getRatePerPiece() {
            return ratePerPiece;
        }

        double computeSalary() {
            return totalPiecesFinished * ratePerPiece + ((int) totalPiecesFinished / 100) * (10 * ratePerPiece);
        }

        std::string toString() {
            std::stringstream ss;
            ss << Employee::toString() << "\nTotal pieces finished: " << totalPiecesFinished << "\nRate per piece: " << ratePerPiece;
            return ss.str();
        }

        void display() {
            std::cout << toString() << std::endl;
            std::cout << "Salary: " << computeSalary() << std::endl;
        }
};

class CommissionEmployee : public Employee {
    double totalSales;

    public:
        CommissionEmployee(int empID = 0, Name empName = Name(), Date empDOB = Date(), Date empDOJ = Date(), double totalSales = 0) : Employee(empID, empName, empDOB, empDOJ), totalSales(totalSales) {}
        ~CommissionEmployee() {}

        void setTotalSales(double totalSales) {
            this->totalSales = totalSales;
        }

        double getTotalSales() {
            return totalSales;
        }

        double computeSalary() {
            return (totalSales < 10000) ? totalSales * 0.05 : ((totalSales < 100000 && totalSales >= 10000) ? totalSales * 0.1 : ((totalSales < 1000000) ? totalSales * 0.2 : totalSales * 0.3));
        }

        std::string toString() {
            std::stringstream ss;
            ss << Employee::toString() << "\nTotal sales: " << totalSales;
            return ss.str();
        }

        void display() {
            std::cout << toString() << std::endl;
            std::cout << "Salary: " << computeSalary() << std::endl;
        }
};

class BasePlusCommissionEmployee : public CommissionEmployee {
    double baseSalary;

    public:
        BasePlusCommissionEmployee(int empID = 0, Name empName = Name(), Date empDOB = Date(), Date empDOJ = Date(), double totalSales = 0, double baseSalary = 0) : CommissionEmployee(empID, empName, empDOB, empDOJ, totalSales), baseSalary(baseSalary) {}
        ~BasePlusCommissionEmployee() {}

        void setBaseSalary(double baseSalary) {
            this->baseSalary = baseSalary;
        }

        double getBaseSalary() {
            return baseSalary;
        }

        double computeSalary() {
            return CommissionEmployee::computeSalary() + baseSalary;
        }

        std::string toString() {
            std::stringstream ss;
            ss << CommissionEmployee::toString() << "\nBase salary: " << baseSalary;
            return ss.str();
        }

        void display() {
            std::cout << toString() << std::endl;
            std::cout << "Salary: " << computeSalary() << std::endl;
        }
};