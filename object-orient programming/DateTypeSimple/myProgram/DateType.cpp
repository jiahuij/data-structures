// Define member functions of class DateType.
// This is file DateType.cpp.

#include "DateType.h" // gain access to specification of class
#include <iostream>
using namespace std;

//The first constructor method to initialize a DateType object
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
DateType::DateType()
{
  year = 2000;
  month = 1;
  day = 1;
}


//The second constructor method to initialize a DateType object
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
DateType::DateType(int newMonth, int newDay, int newYear)
{
  year = newYear;
  month = newMonth;
  day = newDay;
}



//A method to set a new date for the DateType object.
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//   do not change the date stored in the object and then return false.
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
//   and then return true.
bool DateType::SetDate(int newMonth, int newDay, int newYear)
{
  year = newYear;
  month = newMonth;
  day = newDay;


  return true;
}

int DateType::MonthIs()
// Accessor function for data member month.
{
  return month;
}

int DateType::YearIs()
// Accessor function for data member year.
{
  return year;
}


int DateType::DayIs()
// Accessor function for data member day.
{
    return day;
}


void DateType::ReadDate()
{
	bool monthCheck=true , yearCheck =true, dayCheck =true;
	//boolians for checking the validty of month day and yaer.

	cout << endl 
		 << "Read in the information of a date: " ;
		 
	cout << endl << "The month is: "; 
	cin >> month;


	while (monthCheck){

		
		if ((month < 1) || (month>12)){
			/* If the month is less than 1 and greater than 12, 
			tell the user that it is not a valid input and as for a new input.
			Otherwise set the validity check to false.
			*/

			cout << "Invalid month informarion." << endl;
			cout << endl << "The month is: ";
			cin >> month;
		}
		else
			monthCheck = false;
	}

	cout << endl << "The day is: "; 
	cin >> day;

	while (dayCheck){
		/* If the day is less than 1 and greater than 30,
		tell the user that it is not a valid input and as for a new input.
		Otherwise set the validity check to false.
		*/
		if ((day < 1) || (day>30)){
			cout << "Invalid day informarion." << endl;
			cout << endl << "The day is: ";
			cin >> day;
		}
		else
			dayCheck = false;
	}

	cout << endl << "The year is: "; 
	cin >> year;

	while (yearCheck){
		/* If the month is less than 1 and greater than 12,
		tell the user that it is not a valid input and as for a new input.
		Otherwise set the validity check to false.
		*/

		if (year < 1){
			cout << "Invalid year informarion." << endl;
			cout << endl << "The year is: ";
			cin >> year;
		}
		else
			yearCheck = false;
	}



	

}

void DateType::PrintDate()
{
	
	cout << year << "/ " << month << "/ " << day << endl;

}


int DateType::ComparedTo(DateType aDate)
// Pre: Self and aDate have been initialized.
// Post: return
//  LESS, if self comes before aDate.
//  EQUAL, if self is the same as aDate.
//  GREATER, if self comes after aDate.
{
	if ((year == aDate.year) && (month == aDate.month) && (day == aDate.day)){
		// If the self  year, month and day are all the same with aDate year, month and day, return 0, which means equel.
		return 0;
	}

	else if ((year > aDate.year) || (month > aDate.month) || (day > aDate.day)){
		/*if the self year is greater than aDate year, or the self month is greater than aDate month, or
		the self day is greater than aDate day, return 1, which means greater than.  */
	
		return 1;

	}
		
	else 
		// Otherwise return -1, which means less than.

	return -1;
}

int DateType::ComparedCentury(DateType aDate)
// Pre: Self and aDate have been initialized.
// Post: return
//	LESS, if the object itSelf comes before the century of aDate.
//	EQUAL, if the object itSelf is in the same century as aDate.
//	GREATER, if the object itSelf comes after the century of aDate.
{

	if ((year/100) == (aDate.year/100)){
	/* one century = 100 years. Divid the years by 100 to get which century they are in. 
	Since it is a int data type, number after decimal point will be deleted.
	If they are in the same century, return 0, which means equal.*/
		return 0;
	
	}

	else if ((year / 100) > (aDate.year / 100)){
		//If they self century is greater than aDate century, return 1, which means greater than

		return 1;

	}

	else
		// otherwise return -1, which means less than.
		return -1;
}

