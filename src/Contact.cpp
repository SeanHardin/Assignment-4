/*
 * Contact.cpp
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 *      Contact class, code for Contact functions and
 *      operators is here.
 */
#include "Contact.h"
#include <iostream>
using namespace std;

	Contact::Contact(){//no arg constructor...technically not needed since i didn't make any others.
		mname = mphoneNo = "";
	}

	string Contact::getName(){//gets name
		return mname;
	}

	void Contact::setName(string& s){//sets name
		mname = s;
	}

	string Contact::getPhoneNo(){//gets phone number
		return mphoneNo;
	}

	void Contact::setPhoneNo(string& s){//sets phone number
		mphoneNo = s;
	}

	bool operator>(Contact& p1, Contact& p2){//compares 2 Contacts by name
			return p1.mname > p2.mname;
	}

	bool operator<(Contact& p1, Contact& p2){//compares 2 Contacts by name
		return p1.mname < p2.mname;
	}

	bool operator==(Contact& p1, Contact& p2){//compares 2 Contacts by name
		return p1.mname == p2.mname;
	}

	bool operator>=(Contact& p1, Contact& p2){//compares 2 Contacts by name
		return p1.mname >= p2.mname;
	}

	ostream& operator<<(ostream& os, Contact& p){//converts Contact to ostream
		os << p.getName() << ' ' << p.getPhoneNo() << '\n';
		return os;
	}

	void Contact::createFullContact(){//sets validated name and phone number into contact
		string temp;//user input string
		bool changed = 0;//bool to loop user until they input reasonable name
		while (!changed){
			cout << "Enter Contact's name:";
			getline (cin, temp);
			if (noNumbers(temp) && temp != ""){//wont take numbers or empty string
				setName(temp);
				changed = 1;
			} else {
				cout << "A name cannot be nothing or have numbers." << '\n';
			}
		}
		changed = 0;
		while (!changed){
			cout << "enter Contact's phone number:";
			getline (cin, temp);
			if (temp != ""){
				setPhoneNo(temp);
				changed = 1;
			} else {
				cout << "Please enter a real phone number" << '\n';
			}
		}
	}

	void Contact::createContactName(){//sets validated name to compare name with full Contact
		string temp;//user input string
		bool changed = 0;//bool to loop user until they input reasonable name
		while (!changed){
			cout << "Enter Contact's name:";
			getline (cin, temp);
			if (noNumbers(temp) && temp != ""){//wont take numbers or empty string
				setName(temp);
				changed = 1;
			} else {
				cout << "A name cannot be nothing or have numbers." << '\n';
			}
		}
	}

	bool Contact::noNumbers(string& s){//checks if a string has no numbers
		bool temp = 1;
		double limit = 4.294967295*1000000000;
		if (s.find('0') < limit) temp = 0;//if number 0 is found, return false
		if (s.find('1') < limit) temp = 0;//etc
		if (s.find('2') < limit) temp = 0;
		if (s.find('3') < limit) temp = 0;
		if (s.find('4') < limit) temp = 0;
		if (s.find('5') < limit) temp = 0;
		if (s.find('6') < limit) temp = 0;
		if (s.find('7') < limit) temp = 0;
		if (s.find('8') < limit) temp = 0;
		if (s.find('9') < limit) temp = 0;
		return temp;
	}
