//============================================================================
// Name        : airlinedb.cpp
// Author      : Sean Hardin
// Version     :
// Copyright   : Your copyright notice
// Description : runs a phonebook, users can add contacts, load from a file,
//				 search for a contact, print all contacts, filter by a contact,
//               and exit as prompted.
//
//				 i used my second assignment as the base for this so it looks similar.
//============================================================================
#include <iostream>
#include "BinarySearchTree.h"
#include "contact.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main(){
	cout << "***Sean Hardin's phonebook application***"<< '\n';//introduction
	BinarySearchTree<Contact> *tree;
	tree = new BinarySearchTree<Contact>;
	cout << "Please choose an operation:" << '\n';//fluff for pseudo UI
	char userInput;//char to read command from user

	while (userInput != 'Q' && userInput != 'q'){//runs until user chooses to quit
		cout << "A(Add)|L(Load)|S(Search)|P(Print)|F(Filter)|Q(Quit)";//list of commands
		string complianceCheckString;//to use sstream/check length

		getline (cin, complianceCheckString);//get user input
		if (complianceCheckString.length() > 1) {//if user inputs more than a char
			userInput = 'z';//FAILURE TO COMPLY BREAKS IT CUZ OF FILTER...
		} else {
			stringstream complianceCheck;//to copy user input without prompting them again
			complianceCheck << complianceCheckString;
			complianceCheck >> userInput;//take whatever the user types and sets it in the character
		}
		switch (userInput){//switch statement looks cleaner than nested if loops.
			case 'A' ://capital and lowercase letters for better usability, wasn't sure how to force capitals
			case 'a' :
			{
				Contact c;
				c.createFullContact();//name says it all.
				tree->insert(c);//insert into tree.
				cout << c.getName() << " was added to the phonebook." << '\n';//verification that insertion happened
				cout << '\n';//formatting
			}
				break;
			case 'S' ://I DISAGREE WITH THE SPACE BEFORE COLON.
			case 's' :
			{
				Contact c;
				bool found = 0;
				c.createContactName();//just makes name to compare between a full contact
				c = tree->search(c);//function to search
				if (c.getPhoneNo() != ""){//only print if a match is found, if it was, p would be changed to one with address.
					cout << c.getName() << "'s Phone number is " <<
							c.getPhoneNo() << '\n' << '\n';
					found = 1;
				}
				if (!found)//print 'error' if nobody was found to print
					cout << "That person is not in our phonebook." << '\n' << '\n';
			}
				break;
			case 'L' :
			case 'l' :
			{
				cout << "Enter file to load:";
				string file;
				getline (cin, file);
				ifstream readIn;//filestream to read the txt
				readIn.open(file.c_str());
				int entriesAdded = 0;//solely for ui purposes, looks pretty so worth keeping.
				string temp;//temporary string to read the text file
				string a,b,d;//temporary variables to hold the first name, last name, and number respectively
				while (getline (readIn, temp)){//runs until getline finds no line
					stringstream temp2;//initialize inside so data resets each loop
					temp2 << temp;//converting string into stream, so far this was the only way i found to
					//read the file with a loop without losing data or hardcoding the limit
					temp2 >> a >> b >> d;//stream values as described in initialization
					a = a + ' ' + b;
					Contact c;
					c.setName(a);//combines first and last name and sets the phonebook entry with it.
					c.setPhoneNo(d);//sets the number
					tree->insert(c);
					entriesAdded++;
				}
				if (entriesAdded == 0)//getline never ran, only cases are as described
					cout << "File doesn't exist or was empty." << '\n';
				else//says how many entries added
					cout << entriesAdded << " contacts have been added to the phonebook." << '\n';
				cout << '\n';
			}
				break;
			case 'P' :
			case 'p' :
				tree->inOrder();//function to list entries
				cout << tree->nodeCount() << " contact(s) found." << '\n';
				cout << '\n';
				break;
			case 'F' :
			case 'f' :
			{
				Contact c;
				c.createContactName();
				c = tree->search(c);//search for contact so not filtering by nonexistent contact
				if (c.getPhoneNo() != ""){//only run if contact was found
					int count = tree->inOrderStop(c);//counts how many contacts were printed
					cout << count << " contact(s) found before "<< c.getName() << '.' << '\n' << '\n';
				} else//if contact not found, say so
					cout << "Cannot filter by someone not in the phonebook." << '\n' << '\n';
				break;
			}
			case 'Q' ://doesn't run any extra code on quitting, included just to avoid the default case
			case 'q' ://leaving a bad message before ending program
				break;
			default://if user tries to type anything other than the listed commands
				cout << "Please enter only the letter for the option you want." << '\n' << '\n';
		}
		if (userInput != 'q' && userInput != 'Q')//reset char so a \0 doesn't run previous operation again
			userInput = 'z';
	}

	cout << "Thank you for using my phonebook!";//mostly a confirmation that the program ended successfully
	delete tree;//cuz dynamic.
	return 0;
}
