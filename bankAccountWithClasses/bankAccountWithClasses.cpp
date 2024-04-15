#include <iostream>
#include <math.h>

class Bank_account {
    double balance;
    public:
        Bank_account (double b) : balance (b) {
            std::cout << "Account created! your balance is: USD " << b << ". The interest rate is 5%.\n";
        }
        // Calculate balance after given number of months and years.
        double finalBalance () {
            float months, years;
            std::cout << "Input the number of years. If it's less than one, enter 0.\n";
            std::cin >> years;
            do {
                std::cout << "Input the number of months (less than 12).\n";
                std::cin >> months;
                if (months >= 12) {
                    printf("Invalid input.\n");
                }
            } while (months >= 12);
            months += years * 12;
            return balance + (balance * 0.05 * months);
        }
        ~Bank_account () {
            std::cout << "Closed bank account.\n";
        }
};

int main () {
    std::cout << "";
    return 0;
}