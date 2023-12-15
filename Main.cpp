/* Dakota Alemida
*  11/25/23
*  Banking Tool 
*/

#include <iostream>
#include <iomanip>
using namespace std;

class BankingTool {
private:
	double initialInvestmentAmount;
	double monthlyDeposits;
	double annualInterest;
	int numOfYears;

public:


	BankingTool(double initialInvestmentAmount, double monthlyDeposits, double annualInterest, int numOfYears) {
		this->initialInvestmentAmount = initialInvestmentAmount; // assigns value to initialInvestmentAmount
		this->monthlyDeposits = monthlyDeposits; // assigns value to monthlyDesposits
		this->annualInterest = annualInterest; // assigns value to annualInterest
		this->numOfYears = numOfYears; // assigns value to numOfYears
	}

		 
	

	// Function to calulate the balance with a monthly desposit
	double balanceWithMonthlyDeposit() {
		double monthlyInterestRate = (annualInterest / 100) / 12;
		int yearIndex = 1;
		double totalBalance = initialInvestmentAmount;

		while (yearIndex <= numOfYears) {
			for (int m = 0; m < 12; ++m) {
				totalBalance += totalBalance * monthlyInterestRate;

				if (m > 0) {
					totalBalance += monthlyDeposits;
				}


			}
			
			// calculates the interest for the year based on the total balance, initial investment and monthly deposits
			double interestEarnedThisYear = totalBalance - initialInvestmentAmount + monthlyDeposits * 12 * yearIndex - 1;
			printDetails(yearIndex, totalBalance, interestEarnedThisYear);

			++yearIndex;
		}
		return totalBalance;
	}


	// Function to calulate the balance without a monthly desposit
	double calculateBalanceWithoutMonthlyDeposit() {
		double monthlyInterestRate = (annualInterest / 100) / 12;
		int yearIndex = 1;
		double totalBalance = initialInvestmentAmount;

		while (yearIndex <= numOfYears) {
			for (int m = 0; m < 12; ++m) {
				totalBalance += totalBalance * monthlyInterestRate;

			}

			double interestEarnedThisYear = totalBalance - initialInvestmentAmount;
			printDetails(yearIndex, totalBalance, interestEarnedThisYear);

			++yearIndex;
		}

		return totalBalance;

	}

	// function for calculatin the compounded interest
	double compoundInterest() {
		double monthlyInterest = (annualInterest / 100 / 12);
		int totalMonths = numOfYears * 12;
		double totalBalance = initialInvestmentAmount;

		for (int m = 0; m < totalMonths; ++m) {
			totalBalance += totalBalance * monthlyInterest;

			totalBalance += monthlyDeposits;
		}

		return totalBalance;

	}

	// function to output details of investment for a full year
	void printDetails(int year, double yearEndBalance, double interestEarned) {
		cout << year << "\t$" << fixed << setprecision(2) << yearEndBalance << "\t$" << interestEarned << endl;
	}
	

	

};

	int main(){
		double initialInvestmentAmount = 0.0;
		double monthlyDeposits = 0.0;
		double annualInterest = 0.0;
		int numOfYears = 0;

		// prompts user to enter opening amount
		cout << "Initial Investment Amount: " << initialInvestmentAmount << endl;
		cin >> initialInvestmentAmount;

		// prompt user to enter the the monthly deposits 
		cout << "Monthly Deposits: " << monthlyDeposits << endl;
		cin >> monthlyDeposits;

		//prompts user to enter thiers compounded interest
		cout << "Annual Interest: " << annualInterest << endl;
		cin >> annualInterest;

		// prompts user to enter the amount of years the user wishes to invest for 
		cout << "Number of years: " << numOfYears << endl;
		cin >> numOfYears;

		BankingTool tool(initialInvestmentAmount, monthlyDeposits, annualInterest, numOfYears);

		cout << "\nYear\tEnding Balance\tInterest Earned" << endl;
		tool.balanceWithMonthlyDeposit();
	
		return 0;
}
