/**********************************************************************************************************************************
Title: Employee Salary Calculator 
Name: Starasia Wright
Description: The program stores the user's inputs, which  consists of: hourly pay rate, regular and overtime hours worked, and the 
number of tax ememptions, and uses the input to calculate the employee's net pay.  
**********************************************************************************************************************************/
#include <iostream>
#include <string>
using namespace std;

//Function Declarations
double calculateWeeklyGrossPay(float regularHoursWorked, float hourlyPayRate, float overtimeHoursWorked);
double calculateAdjustedGrossPa();
double calculateStateTaxDeductions(double adjustedGrossPay, char maritalStatusInput);
double calculateFederalTaxDeductions(double adjustedGrossPay, char maritalStatusInput);
double calculateWeeklyGrossPay(float regularHoursWorked, float hourlyPayRate, float overtimeHoursWorked);
float regularHoursWorked, hourlyPayRate, overtimeHoursWorked;
void calculateNetPay();

//Global Variables
int taxExemptions;
char continueInput;

//Functions
//This function calculates the weekly gross pay by multiplying the regulars hours worked, entered by the user, by the hourly pay rate, and then adds the over time pay
double calculateWeeklyGrossPay(float regularHoursWorked, float hourlyPayRate, float overtimeHoursWorked){
	return (regularHoursWorked * hourlyPayRate) + (overtimeHoursWorked * (regularHoursWorked * hourlyPayRate) * 1.5);
}

//This function calculates the adjusted gross pay by subtracting the product of the tax exemption received from the user and 13.50, from the calculated weekly gross pay
double calculateAdjustedGrossPa(){
    return (calculateWeeklyGrossPay(regularHoursWorked, hourlyPayRate, overtimeHoursWorked) - (taxExemptions * 13.50));
}

//This function calculates the State Tax Deduction for Married/Single employees, by passing the calculated adjusted gross pay and marital status received from the user
double calculateStateTaxDeductions(double adjustedGrossPay, char maritalStatusInput) {
    switch(maritalStatusInput) {
        case 'M':
            if (adjustedGrossPay > 0 && adjustedGrossPay < 100)
                return adjustedGrossPay*0.05;
            else if (adjustedGrossPay > 101 && adjustedGrossPay < 300)
                return adjustedGrossPay*0.1;
            else if (adjustedGrossPay > 301 && adjustedGrossPay < 600)
                return adjustedGrossPay*0.15;
            else if (adjustedGrossPay > 601 && adjustedGrossPay < 9999)
                return adjustedGrossPay*0.25;
            break;
        case 'S':
            if (adjustedGrossPay > 0 && adjustedGrossPay < 100)
                return adjustedGrossPay*0.05;
            else if (adjustedGrossPay > 101 && adjustedGrossPay < 300)
                return adjustedGrossPay*0.08;
            else if (adjustedGrossPay > 301 && adjustedGrossPay < 600)
                return adjustedGrossPay*0.12;
            else if (adjustedGrossPay > 601 && adjustedGrossPay < 9999)
                return adjustedGrossPay*0.12;
            break;
        default:
            cout << "Please enter a valid response.";
            return 0;
            break;
    }
    return 0;
}

//This function calculates the Federal Tax Deduction for Married/Single employees, by passing the calculated adjusted gross pay and marital status received from the user 
double calculateFederalTaxDeductions(double adjustedGrossPay, char maritalStatusInput) {
    switch(maritalStatusInput) {
        case 'M':
            if (adjustedGrossPay > 0 && adjustedGrossPay < 100)
                return adjustedGrossPay*0.1;
            else if (adjustedGrossPay > 101 && adjustedGrossPay < 300)
                return adjustedGrossPay*0.2;
            else if (adjustedGrossPay > 301 && adjustedGrossPay < 600)
                return adjustedGrossPay*0.3;
            else if (adjustedGrossPay > 601 && adjustedGrossPay < 9999)
                return adjustedGrossPay*0.4;
            break;
        case 'S':
            if (adjustedGrossPay > 0 && adjustedGrossPay < 100)
                return adjustedGrossPay*0.1;
            else if (adjustedGrossPay > 101 && adjustedGrossPay < 300)
                return adjustedGrossPay*0.15;
            else if (adjustedGrossPay > 301 && adjustedGrossPay < 600)
                return adjustedGrossPay*0.25;
            else if (adjustedGrossPay > 601 && adjustedGrossPay < 9999)
                return adjustedGrossPay*0.30;
            break;
        default:
            cout << "Please enter a valid response.";
			return 0;
            break;
    }
	return 0;
}

//This function calculates the net pay by subtracting the sum of the federal and state tax deductions, from the calculated adjusted gross pay 
void calculateNetPay(){
	cout << (calculateAdjustedGrossPa()-(calculateFederalTaxDeductions(double adjustedGrossPay, char maritalStatusInput)+ calculateStateTaxDeductions(double adjustedGrossPay, char maritalStatusInput));
}
int main() {
    string employeeId;
    char maritalStatusInput;
	do {
		
		//Magic Formula to Preserve Decimal Values:
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		
		//Receive the employee's ID
		cout << "Employee number: ";
		cin >> employeeId;
		
		//Error correction for an invalid employee ID
		while(employeeId.length() != 11) {
			cout << "Please enter your ID with the hypens included."<< endl;
			cin >> employeeId;
		}
		
		//Receive the number of regular hours worked
		cout << "Number of Regular Hours Worked: ";
		cin >> regularHoursWorked;
		while (regularHoursWorked > 40) {
			cout << "Regular hours worked should not exceed 40 hours."<< endl;
			cin >> regularHoursWorked;
		}
		
		//Receive over time hours
		cout << "Number of Overtime Hours Worked: ";
		cin >> overtimeHoursWorked;
		
		//Recieve hourly pay rate and make sure it does not exceed $55/hour
		cout << "Hourly Pay Rate: ";
		cin >> hourlyPayRate;
		
		//Error correction for an invalid hourly pay rate input
		while (hourlyPayRate > 55) {
				cout << "Hourly pay rate should not exceed $55/hour. Please enter a valid response!" << endl;
				cin >> hourlyPayRate;
		}
		
		//Receive marital status 
		cout << "Enter Marital Status (M or S): ";
		cin >> maritalStatusInput;
		
		//Error correction for an invalid marital status input
		while (maritalStatusInput != 'M' && maritalStatusInput != 'S') {
			cout << "Please enter either M or S" << endl;
			cin >> maritalStatusInput;
		}
		
		//Receive tax exemptions from the user
		cout << "Enter Tax Expemptions Taken (0-4): ";
		cin >> taxExemptions;
		
		//Error correction for an invalid tax exemption input 
		while (taxExemptions < 0 || taxExemptions > 4) {  
			cout << "Please enter a number within 0-4";
			cin >> taxExemptions;
		}
		//Function Calls
		//Prints Computed Gross Pay
		cout << "Computed Gross Pay: " << calculateWeeklyGrossPay(regularHoursWorked, hourlyPayRate, overtimeHoursWorked) << endl;
		
		//Prints Calculated Federal Tax Deductions
		cout << "Calculated Federal Tax: -$";
		calculateFederalTaxDeductions(calculateAdjustedGrossPa(), maritalStatusInput);
		cout << endl;
		
		//Prints Calculated State Tax Deductions
		cout << "Calculated State Tax: -$";
		calculateStateTaxDeductions(calculateAdjustedGrossPa(), maritalStatusInput);
		cout << endl;
		
		//Prints Net pay
		cout << "Net Pay: ";
		calculateNetPay();
		
		//Option to continue
		cout << "Do you wish to compute for another employee? (Y/N)" << endl;
		cin >> continueInput;
		while(continueInput != 'Y' && continueInput != 'N') {
			cout << "Please enter either Y for yes, or N for no";
			cin >> continueInput;
	} while(continueInput == 'Y');
	cout << "Thank you for using my net pay calculator. Good bye";
}