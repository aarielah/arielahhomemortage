//Author: Arielah Arana CS14 2/22/23
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
char loanType;
double amountOfLoan;
double annualInterestRate;        // as a percent
double rateMonth;                 //interest rate per month as decimal

int term;                         //term is in years
int termMonths;                   //term in months
double monthlyPayment;
double totalPaidBack;
double interestPaid;

cout << "Do you want to get a loan to purchase a house or a vehicle? (enter H for house, V for vehicle) " << endl;
cin >> loanType;
loanType = toupper(loanType);

//home loan
if(loanType == 'H')
{
cout <<"Enter amount of the loan in the range 50000.00 to 5000000.00 ";
cin >> amountOfLoan;
if( (amountOfLoan < 50000.00) && (amountOfLoan > 5000000.00))
{
    cout << "Unacceptable Amount Please Try Again" << endl;
    return 0;
}

cout << "Enter annual interest rate (from 1 through 20) as a percent ";
cin >> annualInterestRate;
if( (annualInterestRate < 1) || (annualInterestRate > 20))
{
    cout << "Unacceptable Amount Please Try Again " << endl;
    return 0;
}

cout << "Enter term. Must be 10, 15, or 30 years ";
cin >> term;
if( (term != 10) && (term != 15) && (term != 30))
{
    cout << "Unaceptable Amount Please Try Again" << endl;
    return 0;
}
}
//vehicle loan
else if (loanType == 'V')
{
cout << "Enter amount of loan in the range 5000.00 to 100000.00 ";
cin >> amountOfLoan;
if( (amountOfLoan < 5000.00) && (amountOfLoan > 100000.00))
{
    cout << "Unacceptable amount please try again";
    return 0;
}

cout << "Enter annual interest rate as a percent such as 4.5, in the range of 1% through 10% ";
cin >> annualInterestRate;
if( (annualInterestRate < 1) && (annualInterestRate > 10) )
{
    cout << "Unacceptable amount please try again";
    return 0;
}

cout << "Enter term, must be ONLY the numbers 3, 4, 5, or 6 ";
cin >> term;
if( (term != 3) && (term != 4) && (term != 5) && (term != 6))
{
    cout << "Unacceptable amount please try again";
    return 0;
}

}

else{
    cout << "I don't do any other kinds of loans" << endl;
    return 0;
}

//calculations and output
if ((loanType == 'H') || (loanType == 'V'))
{
termMonths = term * 12;
rateMonth = annualInterestRate / 1200;

monthlyPayment = amountOfLoan * rateMonth * (pow(1 + rateMonth, termMonths)) / (pow(1 + rateMonth, termMonths) - 1);
totalPaidBack = monthlyPayment * termMonths; 
interestPaid = totalPaidBack - amountOfLoan;

monthlyPayment = static_cast<int>(100.0 * monthlyPayment + 0.5)/100.0;
cout << fixed << setprecision(2);
cout << "Monthly payment rounded is $" << monthlyPayment << endl;
cout << "Total paid back including interest if loan runs full term $" << totalPaidBack << endl;
cout << "Interest paid over life of the loan $" << interestPaid << endl;
}
return 0;


}
