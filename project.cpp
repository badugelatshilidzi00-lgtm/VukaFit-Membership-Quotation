

#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;

int main()
{
    //DECLARE VARIABLES
    //STUDENT DETAILS
    string studentNumber;
    string studentName;
    string membershipName;
    
    //MEMBERSHIP DETAILS
    int months = 0;
    int membership = 0;
    char fitnessAssessmentChoice = 0;

    //FINANCIAL VARIABLES
    double monthlyFee = 0.0;
    double subtotal = 0.0;
    double discountRate = 0.0;
    double discount = 0.0;
    double assessmentFee = 0.0;
    double finalAmount = 0.0;   

    const double Assessment_Cost = 180.00;

    cout << "Enter student number: ";
    cin >> studentNumber;

    cin.ignore();

    cout << "Enter student name : ";
    getline(cin, studentName);

    //DISPLAY MEMBERSHIP OPTIONS

    cout << "\n1. Basic Access - R220" << endl;
    cout << "2. Active Plus - R350" << endl;
    cout << "3. Complete Wellness - R480" << endl;
    

    cout << "Select memebrship: ";
    cin >> membership;

    switch (membership) 
    {
     case 1:
         monthlyFee =  220.00;
         membershipName = "Basic Access";
         break;

     case 2:
         monthlyFee = 350.00;
         membershipName = "Active Plus";
         break;

     case 3: 
         monthlyFee = 480.00;
         membershipName = "Complete Wellness";
         break;

     default:
         cout << "Invalid membership! " << endl;
         return 1;

    }
 

    cout << "Number of months (1 - 6): ";
    cin >> months;


    //CALCULATE SUBTOTAL
    subtotal = monthlyFee * months;

    
    if (months == 6)
    {
        discountRate = 0.12;
    }
    else if (months >= 3 and months <= 5)
    {
        discountRate = 0.07;
    }
    else
    {
        discountRate = 0.0;
    }

   //CALCULATE DISCOUNT
    discount = subtotal * discountRate;

    
    cout << "Add finess assessment? (Y/N): ";
    cin >> fitnessAssessmentChoice;

    if (fitnessAssessmentChoice == 'Y' ||
        fitnessAssessmentChoice == 'y')

    {
        assessmentFee = Assessment_Cost;
    }
    else if(fitnessAssessmentChoice == 'N' ||
            fitnessAssessmentChoice == 'n')

    {
        assessmentFee = 0.0;
    }
    else
    {
        cout << "Invalid assessment choice!" << endl;
        return 1;
    }

    //CALCULATE FINALAMOUNT
    finalAmount = subtotal - discount + assessmentFee;

    cout << fixed << setprecision(2);

    cout << "\n========== VUKAFIT MEMBERSHIP QUOTATION ==========" << endl;

    cout << "Student          : " << studentNumber << " - " << studentName << endl;
    cout << "Membership       : " << membershipName << endl;
    cout << "Months           : " << months << endl;
    cout << "Monthly Fee      : R" << monthlyFee << endl; 
    cout << "Subtotal         : R" << subtotal << endl;
    cout << "Discount         : R" << discount << endl;
    cout << "Assessment Fee   : R" << assessmentFee << endl;
    cout << "FINAL AMOUNT     : R" << finalAmount << endl;

    return 0;
}

