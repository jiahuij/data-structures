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


	if ((DateType::IsValidDate(month, day, year)) == false){
		cout << "Invalid date. " << endl;
		cout << "The date has been defaulted to 1/1/2000. " << endl;

		year = 2000;
		month = 1;
		day = 1;
	}


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

	if ((DateType::IsValidDate(month, day, year)) == true){
		//call the date validity check function.
		// if the function returns true, set the dates as the user input dates


		year = newYear;
		month = newMonth;
		day = newDay;
		return true;
	}

	else
		//if the function returns false and and leave the contents of  the date unchanged.

		return false;

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

	cout << endl
		<< "Read in the information of a date: ";


	bool validDate = true;

	while (validDate == true){


		cout << endl << "The month is: ";
		cin >> month;

		cout << endl << "The day is: ";
		cin >> day;

		cout << endl << "The year is: ";
		cin >> year;


		if ((DateType::IsValidDate(month, day, year)) == false){
			//call the date validity check function.
			// if the function returns false, infrom the user and loop back

			cout << endl;
			cout << "Invalid date. Please enter again. " << endl;
		}
		else
			//If the function returns true, end the loop 

			validDate = false;
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

	if ((year / 100) == (aDate.year / 100)){
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



// set a for loop that loops  for the days that the user wants advance.
// in each loop, add the days by one
// if the month equels to 4,6,9,11 and the day is greater than  31 which is one day more 
// than the max of the day in those months,  add one to the month and set the day to 1.
// if the month equels to 1,3,5,7,8,10 and the day is greater than  32  which is one day more
//  than the max of the day in those months,  add one to the month and set the day to 1.
//If the month equels to 12 and the day is greater than 32, set the month and day to 1 and add one to year.

void DateType::AdvanceDays(long NumDays){



	if (NumDays <= 0){
		//If the use input is a negative number, call the backDay function .

		DateType::BackDays(-NumDays);

	}

	else {


		bool leapYear;

		for (int i = 0; i < NumDays; i++){

			day++;



			// If the year is a leap year, return true, else return false

			if (((year % 4 == 0) || (year % 100 == 0) && year % 400 == 0)){

				leapYear = true;
			}

			else
				leapYear = false;



			if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31){
				month++;
				day = 1;
			}
			else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 32){
				month++;
				day = 1;
			}
			else if (month == 12 && day == 32){
				year++;
				month = 1;
				day = 1;
			}
			else if (leapYear == true && month == 2 && day == 30){
				month++;
				day = 1;
			}

			else if (leapYear == false && month == 2 && day == 29){
				month++;
				day = 1;
			}

		}
	}
}

// set a for loop that loops  for the days that the user wants back down.
// in each loop, substract the days by one
// if the month equels to 5,7,10,12 which are the nest months of the months that has 30 days and
// the day equel to 0, substract one from month and set the days to 30
// if the month equels to 2,4,6,8,9,11 which are the nest months of the months that has 31 days and
// the day equel to 0, substract one from month and set the days to 31
//If the month equels to 1 and the day equels to 0, set the month to 12 and day to 1 and substract one to year.

void DateType::BackDays(long NumDays){

	bool leapYear;



	if (NumDays <= 0){
		// If the use input is a negative number, call the advance day function .
		DateType::AdvanceDays(-NumDays);
	}

	else{
		for (int i = 0; i < NumDays; i++){

			day--;


			// If the year is a leap year, return true, else return false

			if (((year % 4 == 0) || (year % 100 == 0) && year % 400 == 0)){
				leapYear = true;
			}

			else
				leapYear = false;



			if ((month == 5 || month == 7 || month == 10 || month == 12) && day == 0){
				month--;
				day = 30;
			}

			else if ((month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11) && day == 0){
				month--;
				day = 31;
			}
			else if (month == 1 && day == 0){
				year--;
				month = 12;
				day = 31;
			}
			else if (leapYear == true && month == 3 && day == 0){
				month--;
				day = 29;
			}

			else if (leapYear == false && month == 3 && day == 0){
				month--;
				day = 28;
			}

		}

	}


}

bool DateType::IsValidDate(int newMonth, int newDay, int newYear){


	bool leapYear, validDay, validMonth, validYear;


	if (((newYear % 4 == 0) || ((newYear % 100 == 0) && newYear % 400 == 0))){

		leapYear = true;
	}

	else
		leapYear = false;




	//If the month equels to 4,6,9,11 and the days are smaller than 1 or greater than 30, it is a invalid date
	if ((newMonth == 4 || newMonth == 6 || newMonth == 9 || newMonth == 11) && (newDay < 1) || (newDay > 30)){
		validDay = false;
	}

	//If the month equels to 1,3,5,7,8,10 and the days are smaller than 1 or greater than 31, it is a invalid date
	else if ((newMonth == 1 || newMonth == 3 || newMonth == 5 || newMonth == 7 || newMonth == 8 || newMonth == 10 || newMonth == 12) && (newDay < 1) || (newDay > 31)){
		validDay = false;
	}

	//If leap year is true and  the month equels to 2 and the days are smaller than 1 or >= than 30,it is a invalid date
	else if (leapYear == true && newMonth == 2 && ((newDay <  1) || (newDay >= 30))){

		validDay = false;
	}

	//If leap year is false and  the month equels to 2 and the days are smaller than 1 or >= than 29,it is a invalid date
	else if (leapYear == false && newMonth == 2 && ((newDay < 1) || (newDay >= 29))){

		validDay = false;
	}

	else
		validDay = true;

	//If month is greater than 12 or smaller than 1, it is an invalid date
	if (newMonth > 12 || newMonth < 1){
		validMonth = false;
	}
	else
		validMonth = true;

	//If the year is smaller than 1, it is an invalid date
	if (newYear < 1){
		validYear = false;
	}
	else
		validYear = true;


	// if all days, months, and years are valid, return true
	if (validDay == true && validMonth == true && validYear == true){
		return true;
	}
	else
		return false;
}

//this function sets the date to a random valid date by using rand and call the valid date check
void DateType::SetRandomDate(){

	bool validRandomDate = true;

	while (validRandomDate){

		day = rand() % 31;
		month = rand() % 12;
		year = rand() % 2017;

		if (IsValidDate(month, day, year) == true){

			validRandomDate = false;
		}


	}
}
// this function overloads the > operator which compares two dates and returns the truth value
bool  DateType::operator> (const DateType & aDate){
	bool status;

	/* Used  if statement to check whether the year is > ,< or = to the date, if if the year is > just return true and if
	it is < just return false, however if it is equel, go and check the months. if the month is still the same so go and
	check the days. */
	if (year > aDate.year)
		status = true;

	else if (year == aDate.year){

		if (month > aDate.month)
			status = true;

		else if (month == aDate.month){

			if (day > aDate.day)
				status = true;

			else if (day == aDate.day)
				status = false;
			else
				status = false;
		}
		else
			status = false;
	}

	else
		status = false;

	return status;

}
// this function overloads the < operator which compares two dates and returns the truth value
bool  DateType::operator< (const DateType & aDate){

	bool status;

	/* Used  if statement to check whether the year is > ,< or = to the date, if if the year is < just return true and if
	it is > just return false, however if it is equel, go and check the months. if the month is still the same so go and
	check the days. */

	if (year < aDate.year)
		status = true;

	else if (year == aDate.year){

		if (month < aDate.month)
			status = true;

		else if (month == aDate.month){

			if (day < aDate.day)
				status = true;

			else if (day == aDate.day)
				status = false;
			else
				status = false;
		}
		else
			status = false;
	}

	else
		status = false;

	return status;

}
// this function overloads the == operation which compares two dates and returns the truth value
bool  DateType::operator== (const DateType & aDate){
	bool status;

	if (day == aDate.day && month == aDate.month && year == aDate.year)
		status = true;
	else
		status = false;

	return status;
}
// this function overloads the != operator which compares two dates and returns the truth value
bool  DateType::operator!= (const DateType & aDate){

	bool status;

	if (day != aDate.day || month != aDate.month || year != aDate.year)
		status = true;

	else
		status = false;

	return status;
}
// this function overloads the >= operator which compares two dates and returns the truth value
bool  DateType::operator>= (const DateType & aDate){

	/* Used  if statement to check whether the year is > ,< or = to the date, if if the year is < just return true and if
	it is > just return false, however if it is equel, go and check the months. if the month is still the same so go and
	check the days.If the day is equel or > return true, else return false */
	bool status;

	if (year > aDate.year)
		status = true;

	else if (year == aDate.year){

		if (month > aDate.month)
			status = true;

		else if (month == aDate.month){

			if (day > aDate.day)
				status = true;

			else if (day == aDate.day)
				status = true;
			else
				status = false;
		}
		else
			status = false;
	}

	else
		status = false;

	return status;
}
// this function overloads the <= operator which compares two dates and returns the truth value
bool  DateType::operator<= (const DateType & aDate){

	bool status;

	/* Used  if statement to check whether the year is > ,< or = to the date, if if the year is < just return true and if
	it is > just return false, however if it is equel, go and check the months. if the month is still the same so go and
	check the days.If the day is equel or > return true, else return false */

	if (year < aDate.year)

		status = true;

	else if (year == aDate.year){

		if (month < aDate.month)
			status = true;

		else if (month == aDate.month){

			if (day < aDate.day)
				status = true;

			else if (day == aDate.day)
				status = true;
			else
				status = false;
		}
		else
			status = false;
	}

	else
		status = false;

	return status;
}

// this function overloads the - operator which counts the exact number fo days from one date to another
int DateType :: operator- (const DateType & aDate){

	int counter = 0;

	// call the function that checks the greaterness. If the first date is greater, call the  backday function which 
	// go back 1 day for every call. 
	if (DateType::operator > (aDate)){

		while (DateType::operator!= (aDate)){
			DateType::BackDays(1);
			counter++;
		}
	}
	// call the function that checks the less than. If the first date is greater, call the  backday function which 
	// go back 1 day for every call. 
	else if (DateType::operator < (aDate)){

		while (DateType::operator!= (aDate)){

			DateType::AdvanceDays(1);
			counter--;
		}
	}


	else{

		counter = 0;
	}

	DateType::AdvanceDays(counter);



	return counter;
}
// this function performs the subtraction of a date
DateType DateType:: operator- (int numDays) {

	DateType subtract;
	// creating a object

	DateType::BackDays(numDays);
	//back the date to the number of days user entered

	// set the date to the object date 
	subtract.day = day;
	subtract.month = month;
	subtract.year = year;

	// reset the date back to the days that we had backed up.
	DateType::AdvanceDays(numDays);


	return subtract;
}
// this function performs the addition of a date
DateType DateType:: operator+ (int numDays){
	DateType addition;

	DateType::AdvanceDays(numDays);
	//advance the date to the number of days user entered

	// set the date to the object date 
	addition.day = day;
	addition.month = month;
	addition.year = year;

	// reset the date back to the days that we had advanced up.
	DateType::BackDays(numDays);


	return addition;
}

// this function simply overloads the << operator which displays the date to the scream.
ostream & operator<< (ostream & output, const DateType & aDate){

	output << aDate.day << "/" << aDate.month << "/" << aDate.year << endl;


	return output;
}

// this function simply overloads the >> operator which asks the user to input the dates and check for validity
istream & operator>> (istream & input, DateType & aDate){
	bool validDate = true;

	while (validDate){

		cout <<endl<< "The month is :" << endl;
		input >> aDate.month;
		cout << "The day is :" << endl;
		input >> aDate.day;
		cout << "The year is :" << endl;
		input >> aDate.year;

		if (aDate.IsValidDate(aDate.month, aDate.day, aDate.year) == true)
			validDate = false;
		else
			cout << endl << "Invalid date, reeneter: " << endl << endl;

	}

	return input;
}