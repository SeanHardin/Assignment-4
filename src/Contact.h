/*
 * Passenger.h
 *
 *  Created on: Oct 17, 2017
 *      Author: Sean
 *      contact header, prototypes for the contact class
 */
#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>
using namespace std;

class Contact {
		string mname;//begrudgingly named with an m before it.
		string mphoneNo;//also begrudgingly named with an m.

	public:
		Contact();
		string getName();//definitions in cpp file.
		void setName(string&);
		string getPhoneNo();
		void setPhoneNo(string&);
		friend bool operator>(Contact&, Contact&);
		friend bool operator<(Contact&, Contact&);
		friend bool operator==(Contact&, Contact&);
		friend bool operator>=(Contact&, Contact&);
		friend ostream& operator<<(ostream& os, Contact&);
		void createFullContact();
		void createContactName();
		bool noNumbers(string&);//check if string has numbers
};

#endif /* CONTACT_H_ */
