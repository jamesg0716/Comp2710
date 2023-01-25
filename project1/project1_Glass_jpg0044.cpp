/* 
 * Name: James Glass
 * AU Email: jpg0044@auburn.edu
 * FileName: project1_Glass_jpg0044.cpp 
 * Compiler: g++ project1_Glass_jpg0044.cpp -o project1.out
 * Run: ./project1.out
 * Sources: 
 * 1. Used the Visual Studio Code text editor
 * 2. Used the Piazza chat to handle wrong data type inputs.
 * 3. Used Handout1_1.pdf in class to find the proper formatting.
 * 4. Used https://www.cplusplus.com/reference/cstdlib/ to find the library for the exit() method.
 */ 
 
#include <iostream> 
#include <stdlib.h>
using namespace std;
 
int main() { 
 // VARIABLE INITIALIZATION 
  double loanAm = -1;
  double iRatePerYear = -1;
  double monPayments = -1;
  double iRateC = 0;
  int currentMonth = 0;
  double totalInterest = 0;
  double principal = 0;
  double intPayment = 0;
  
 // CURRENCY FORMATTING 
 cout.setf(ios::fixed); 
 cout.setf(ios::showpoint); 
 cout.precision(2);
  
 // USER INPUT 
 // NOTE: For valid input, the loan, interest, and monthly payment must 
 // be positive. The monthly payment must also be large enough to 
 // terminate the loan.

 // User input for the loan ammount that must be positive.
 // Used Piazza to find the cin.ignore() and cin.fail() functions.
 while (loanAm <= 0) {
 cout << "\nLoan Amount: "; 
 cin >> loanAm;
 cin.ignore();
 if (loanAm <= 0 || cin.fail()) {
      cout << "Error: Invalid Loan Amount" << endl;
      exit(0);
     }
 } 
 
 // User input for interest rate that must be positive.
 while (iRatePerYear <= -1){
 cout << "Interest Rate (% per year): "; 
 cin >> iRatePerYear;
 cin.ignore();
 if (iRatePerYear <= -1 || cin.fail()) {
      cout << "Error: Invalid Rate" << endl;
      exit(0);
     }
 }
  
 // GET PROPER INTEREST RATES FOR CALCULATIONS 

 iRatePerYear /= 12; 
 iRateC = iRatePerYear / 100; 

 // User input for the monthly payment that must be positive and large enough 
 // to terminate the loan.
 while (monPayments <= 0 || monPayments <= loanAm * iRateC) {
 cout << "Monthly Payments: "; 
 cin >> monPayments;
 cin.ignore();
 if (monPayments <= 0 || monPayments <= loanAm * iRateC || cin.fail()) {
      cout << "Error: Invalid Payment" << endl;
      exit(0);
     }
}
 
 cout << endl; 
  
 // AMORTIZATION TABLE 
 cout << "*****************************************************************\n" 
      << "\tAmortization Table\n" 
      << "*****************************************************************\n" 
      << "Month\tBalance\t  Payment\tRate\tInterest\tPrincipal\n"; 
 
 // LOOP TO FILL TABLE 
 while (loanAm > 0) { 
  if (currentMonth == 0) { 
   cout << currentMonth++ << "\t$" << loanAm; 
  if (loanAm < 1000) cout << "\t"; // Formatting MAGIC 
   cout << "  N/A\t\tN/A\tN/A\t\tN/A\n"; 
  } 
  else {
       intPayment = loanAm * iRateC;
       principal = monPayments - intPayment;
       loanAm -= principal;
       totalInterest += intPayment;

       if (loanAm < 0) {
            principal += loanAm;
            monPayments += loanAm;
            loanAm = 0;
       }

       cout << currentMonth++ << "\t$" << loanAm;
       if (loanAm < 1000) cout << "\t";
       cout << "  $" << monPayments << "\t" << iRateC * 100 << "\t$" << intPayment << "\t\t$" << principal << "\n";
    } 
 }
 
 cout << "****************************************************************\n"; 
 cout << "\nIt takes " << --currentMonth << " months to pay off " 
      << "the loan.\n" 
      << "Total interest paid is: $" << totalInterest; 
 cout << endl << endl;  
 return 0; 
} 