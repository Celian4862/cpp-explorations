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
    std::cout << "Welcome to your personal bank! Because this is your first time here, you must open a bank account and input how much money you would like to deposit. The interest rate is set by us and will be displayed right after you deposit your money.\n";
	double balance;
	std::cout << "Input your desired deposit in US dollars.\n";
	std::cin >> balance;
	Bank_account b (balance);
	std::cout << "Would you like to calculate your future balance based on the current interest and the number of months for which you will leave your deposit? (Input 1 for \"yes\", and 0 for \"no\".)\n";
	int interestDecision;
	std::cin >> interestDecision;
	if (interestDecision == 1) {
		double x = b.finalBalance() * 100;
		printf("Your future balance is USD %.2f.\n", round(x)/100);
	}
	cout << "Pleasure doing business with you; have a pleasant day!\n";
	
	return 0;
}
}