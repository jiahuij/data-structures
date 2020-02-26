
#include "Appointment.h"

// Include the header file 


//Default constrctor method to initialize a Appointment object.
//We want to initialize firstName and lastName as "John" and "Doe",
//						meeting place and phone as empty strings ""
//						AppointmentDay as Jan. 1 2000
Appointment::Appointment()
{
	Appointment::FirstName == "John";
	Appointment::LastName == "Doe";
	Appointment::MeetingPlace == " ";
	Appointment::Phone == " ";
	Appointment::AppointmentDay.SetDate(1, 1, 2000);
}


//Another constrctor method to initialize a Appointment object
//using what is supplied in te declaration
Appointment::Appointment			
(	string aFirstName,
	string aLastName,
	string aMeetingPlace,
	string aPhone,
	DateType aAppointmentDay
)
{
	Appointment::FirstName == aFirstName;
	Appointment::LastName == aLastName;
	Appointment::MeetingPlace == aMeetingPlace;
	Appointment::Phone == aPhone;
	Appointment::AppointmentDay == aAppointmentDay;

}



//Set the data members of a Appointment object.
// by using the information provided in the parameters above
void Appointment::SetAppointment
					(	string newFirstName,
						string newLastName,
						string newMeetingPlace,
						string newPhone,
						DateType newAppointmentDay
					)
{
	Appointment::FirstName == newFirstName;
	Appointment::LastName == newLastName;
	Appointment::MeetingPlace == newMeetingPlace;
	Appointment::Phone == newPhone;
	Appointment::AppointmentDay == newAppointmentDay;

}


// This member function should prompt the user to key in the first name, the last name,
// the phone number, the meeting place address, and the appointment day of a person.
// This member function should store the user input into the cooresponding data members
// of the object.
void Appointment::ReadInfo()
{
	cout << "Please enter your first name: ";
	cin >> Appointment::FirstName;

	cout << "Please enter your last name: ";
	cin >> Appointment::LastName;

	cout << "Please enter your phone number: ";
	cin >> Appointment::Phone;

	cout << "Please enter the meeting place: ";
	cin >> Appointment::MeetingPlace;

	cout << "Please enter the appointment date: ";
	cin >> Appointment::AppointmentDay;

	cout << endl<<"Appointment saved." << endl << endl;
}


//Just print out the contents of the data members to
void Appointment::PrintInfo()
{
	
	cout <<endl<<"Name: "<< Appointment::FirstName << " " << Appointment::LastName << endl;
	cout << "Phone: " << Appointment::Phone << endl;
	cout << "Place: " << Appointment::MeetingPlace << endl;
	cout << "Date: " << Appointment::AppointmentDay << endl << endl;

	return;
}





// Pre: the object itself and a reference to another Appointment object aappointment
// Post: Function return value is
// LESS, if the full name of the object alphbatically comes before that of aappointment.
// EQUAL, if the full name of the object is the same of that of aappointment.
// GREATER, if the full name of the object alphbatically comes after that of aappointment.
int Appointment::CompareFullName(const Appointment & aappointment)
{
	if (aappointment.LastName > Appointment::LastName)
		return -1;

	else if (aappointment.LastName < Appointment::LastName)
		return 1;

	else if (aappointment.LastName == Appointment::LastName){

		if (aappointment.FirstName > Appointment::FirstName)
			return -1;

		else if (aappointment.FirstName < Appointment::FirstName)
			return 1;

		else if (aappointment.FirstName == Appointment::FirstName)
		return 0;

	}
	    
}



// Pre: the object itself and 2 string objects: aFristName and aLastName
// Post: Function return value is
// LESS, if the full name of the object comes before that of aFristName and aLastName.
// EQUAL, if the full name of the object is the same of that of aFristName and aLastName.
// GREATER, if the full name of the object comes after that of aFristName and aLastName.
int Appointment::CompareFullName(string aFirstName, string aLastName)
{

	if (aLastName > Appointment::LastName)
		return -1;

	else if (aLastName < Appointment::LastName)
		return 1;

	else if (aLastName == Appointment::LastName){

		if (aFirstName > Appointment::FirstName)
			return -1;

		else if (aFirstName < Appointment::FirstName)
			return 1;

		else if (aFirstName == Appointment::FirstName)
			return 0;
	}

}


// Pre: the object itself and a reference to another Appointment object aappointment
// Post: Function return value is
//	true if the full name of the object is the same as that
//		 of aappointment.
//	false otherwise
bool Appointment::SameFullName(const Appointment & aappointment)
{
	if (aappointment.LastName == Appointment::LastName && aappointment.FirstName == Appointment::FirstName)
		return true;

	else
	return false;
}


// Pre: the object itself and 2 string objects: aFristName and aLastName
// Post: Function return value is
//	true if the full name of the object is the same as that
//		 of 2 string objects: aFristName and aLastName.
//	false otherwise
bool Appointment::SameFullName(string aFirstName, string aLastName)
{
	if (aLastName == Appointment::LastName && aFirstName == Appointment::FirstName)
		return true;

	else
		return false;
}



// Pre: the object itself and a reference to another Appointment object aappointment
// Post: Function return value is
// LESS, if the appointment day of the object comes before that of aappointment.
// EQUAL, if the appointment day of the object is the same as that of aappointment.
// GREATER, if the appointment day of the object comes after that of aappointment.
int Appointment::CompareAppointmentDay(const Appointment & aappointment)
{
	
	if (Appointment::AppointmentDay < aappointment.AppointmentDay)
		return -1;

	else if (Appointment::AppointmentDay > aappointment.AppointmentDay)
		return 1;

	else if (Appointment::AppointmentDay == aappointment.AppointmentDay)
		return 0;

}


// Pre: the object itself and a DateType object aAppointmentDay
// Post: Function return value is
// LESS, if the appointment day of the object comes before aAppointmentDay.
// EQUAL, if the appointment day of the object is the same as aAppointmentDay.
// GREATER, if the appointment day of the object comes after aAppointmentDay.
int Appointment::CompareAppointmentDay(DateType aAppointmentDay)
{

	if (Appointment::AppointmentDay < aAppointmentDay)
		return -1;

		else if (Appointment::AppointmentDay > aAppointmentDay)
		return 1;

		else if (Appointment::AppointmentDay == aAppointmentDay)
		return 0;
}



// Pre: the object itself and a reference to another Appointment object aappointment
// Post: Function return value is
//	true if the appointment day of the object is the same as that of aappointment;
//	false otherwise.
bool Appointment::SameAppointmentDay(const Appointment & aappointment)
{
	if (Appointment::AppointmentDay == aappointment.AppointmentDay)
		return true;
	else
		return false;
}


// Pre: the object itself and a DateType object aAppointmentDay
// Post: Function return value is
//	true if the appointment day of the object is the same as that of anInfo.
//	false otherwise
bool Appointment::SameAppointmentDay(DateType aAppointmentDay)
{
	if (Appointment::AppointmentDay == aAppointmentDay)
		return true;
	else
		return false;
}


//Define the relationl operator >
bool Appointment::operator> (const Appointment & aappointment)
{
	if (CompareAppointmentDay(aappointment.AppointmentDay) == 1)
		return true;
	else if (SameAppointmentDay(aappointment)  && CompareFullName(aappointment.FirstName, aappointment.LastName) == 1)
		return true;

	else
		return false;


}

//Define the relationl operator >=
bool Appointment::operator>= (const Appointment & aappointment)
{
	if (CompareAppointmentDay(aappointment.AppointmentDay) == -1)
		return false;
	else if (SameAppointmentDay(aappointment.AppointmentDay) &&
		CompareFullName(aappointment.FirstName, aappointment.LastName) == -1)
		return false;
	else
		return true;
}

//Define the relationl operator <
bool Appointment::operator< (const Appointment & aappointment)
{
	
	if (CompareAppointmentDay(aappointment.AppointmentDay) == -1)
		return true;
	else if (SameAppointmentDay(aappointment) && CompareFullName(aappointment.FirstName, aappointment.LastName) == -1)
		return true;

	else
		return false;

}


//Define the relationl operator <=
bool Appointment::operator<= (const Appointment & aappointment)
{
	if (CompareAppointmentDay(aappointment.AppointmentDay) == 1)
		return false;
	else if (SameAppointmentDay(aappointment.AppointmentDay) &&
		CompareFullName(aappointment.FirstName, aappointment.LastName) == 1)
		return false;
	else
		return true;
}



//Define the relationl operator ==
bool Appointment::operator== (const Appointment & aappointment)
{
	if (SameAppointmentDay(aappointment.AppointmentDay) &&
		CompareFullName(aappointment.FirstName, aappointment.LastName) == 0)
		return true;
	else
		return false;

}

//Define the relationl operator !=
bool Appointment::operator!= (const Appointment & aappointment)
{
	if (SameAppointmentDay(aappointment.AppointmentDay) &&
		CompareFullName(aappointment.FirstName, aappointment.LastName) == 0)
		return false;
	else
		return true;
}


ostream & operator<< (ostream & output, const Appointment & aappointment)
{

	output << endl << "Name: " << aappointment.FirstName << " " << aappointment.LastName << endl;
	output << "Phone: " << aappointment.Phone << endl;
	output << "Place: " << aappointment.MeetingPlace << endl;
	output << "Date: " << aappointment.AppointmentDay << endl << endl;
	return output;
}

istream & operator>> (istream & input, Appointment & aappointment)
{


	cout << "Please enter your first name: ";
	input >> aappointment.FirstName;

	cout << "Please enter your last name: ";
	input >> aappointment.LastName;

	cout << "Please enter your phone number: ";
	input >> aappointment.Phone;

	cout << "Please enter the meeting place: ";
	input >> aappointment.MeetingPlace;

	cout << "Please enter the appointment date: ";
	input >>aappointment.AppointmentDay;

	cout << endl << "Appointment saved." << endl << endl;


	return input;
}



