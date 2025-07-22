#pragma once

#include<iostream>

using namespace std;

class clsPerson
{

private:

	// Private data members.
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	// Parameterized Constructor.
	clsPerson(string FirstName, string Lastname, string Email, string Phone)
	{
		_FirstName = FirstName;
		_LastName = Lastname;
		_Email = Email;
		_Phone = Phone;
	}

	// Property set first name.
	void setFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	// Property get fist name.
	string getFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = getFirstName, put = setFirstName)) string FirstName;

	// Property set last name.
	void setLastName(string LastName)
	{
		_LastName = LastName;
	}
	

	// Property get last name.
	string getLastName()
	{
		return _LastName;
	}
	__declspec(property(get = getLastName, put = setLastName)) string LastName;

	// Property set email.
	void setEmail(string Email)
	{
		_Email = Email;
	}

	// Property get email.
	string getEmail()
	{
		return _Email;
	}
	__declspec(property(get = getEmail, put = setEmail)) string Email;

	// Property set phone number.
	void setPhone(string Phone)
	{
		_Phone = Phone;
	}

	// Property get phone number.
	string getPhone()
	{
		return _Phone;
	}
	__declspec(property(get = getPhone, put = setPhone)) string Phone;

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}
};

