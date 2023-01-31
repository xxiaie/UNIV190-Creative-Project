#ifndef DEFS_H_INCLUDED
#define DEFS_H_INCLUDED

#include<iostream>
#include "house.h"
using namespace std;

void House::inventory() const
{
	if (bedKey == true) cout << "Bedroom Key\n";
	if (basKey == true) cout << "Basement Key\n";
	if ((bedKey == false) && (basKey == false)) cout << "You have nothing\n";
	cout << endl;
}

void House::base()
{
	char a;
	cout << "You creep down the creeking steps.\n";
	cin.get(a);
	cout << "......creeeeeeeeeeeeeeek......\n";
	cin.ignore(256, '\n');
	cin.get(a);
	cout << "You examine the basement. It is very dark.";
	cin.get(a);
	cout << "You see what appears to be a body on the floor.\n";
	cin.get(a);
	cout << "No......... it can't be...... I need to get out of here now!\n";
	cin.get(a);
}

void House::attic()
{
	char a;
	cout << "You enter the attic to find webs and what appear to be egg sacs all over the floor.";
	cin.ignore(256, '\n');
	cin.get(a);
	cout << "You look around and find something shiny in one of the egg sacs.";
	cin.get(a);
	cout << "You pick up the key, which leads to the basement.\n";
	cin.get(a);
	cout << "I gotta get out of here... somethings bugging me out about all this.\n";
	cin.get(a);
	cout << "You exit the attic and the ladder shuts behind you. You here a loud noise come from the basement of the house.\n";
	cin.get(a);
	basKey = true;
}

void House::bed()
{
	cout << "The bedroom is completely empty. The bedsheets are everywhere and there is no one in sight. You notice something on the ceiling as you look around.\n";
	char choice;
	bool inside = true;

	do {
		cout << "Bedroom\n";
		cout << "What would you like to do? [C]heck [I]nventory [E]xit\n";
		cin >> choice;

		switch (choice) {

		case('C'):
			char y;
			cout << "You reach up and a ladder falls down from the ceiling. Enter the attic? Y/N\n";
			cin >> y;
			if ((y == 'y') || (y == 'Y')) attic();
			break;

		case('I'):
			cout << endl;
			inventory();
			break;

		case('E'):
			cout << endl;
			inside = false;
			break;

		default:
			cout << "Invalid action\n" << endl;
		}
	} while (inside);
}

void House::live()
{
	cout << "You enter the living room to find a TV, couch, a safe on a shelf, a door to the basement, and a door to a bedroom.\n";
	bool inside = true;
	char choice;

	do {
		cout << "Living Room\n";
		cout << "What would you like to do? [C]heck [I]nventory [G]o\n";
		cin >> choice;

		switch (choice) {

		case('C'):
			char a, b;
			cout << "What would you like to check? [T]V [S]afe [B]ack\n";
			cin >> a;

			switch (a) {
				
			case('T'):
				cout << "You notice static on the old CRT. Upon closer inspection, you see its not static at all.";
				cin.ignore(256, '\n');
				cin.get(b);
				cout << "The web build up on the TV made it look like static. You question why there are webs everywhere in this household.";
				cin.get(b);
				cout << endl;
				break;

			case('S'):
				int pass;
				char y;
				cout << "The safe has a keypad on it with 4 number slots.";
				cin.get(b);
				cout << "Would you like to try to open the safe? Y/N\n";
				cin >> y;
				if ((y == 'y') || (y == 'Y')) {
					cout << "Password: ";
					cin >> pass;
					if (pass == 7487) {
						cout << "The safe unlocks. Inside, you find a key to the bedroom.\n";
						cin.get(b);
						bedKey = true;
					}
					else cout << "Wrong Password.\n";
				}
				break;

			case('B'):
				cout << endl;
				break;

			default:
				cout << "Invalid action\n";
			}
			break;

		case('I'):
			cout << endl;
			inventory();
			break;

		case('G'):
			char e;
			cout << "Where would you like to go? [K]itchen [B]edroom [b]asement [S]tay\n";
			cin >> e;
			switch (e) {

			case('K'):
				dinKit();
				break;

			case('B'):
				if (bedKey == false) cout << "It's locked.\n" << endl;
				else bed();
				break;

			case('b'):
				if (basKey == false) cout << "It's locked.\n" << endl;
				else inside = false;
				break;

			case('S'):
				cout << endl;
				break;

			default:
				cout << "Invalid action\n";
			}
			break;

		default:
			cout << "Invalid action\n";
		}
	} while (inside);
}

void House::bath()
{
	cout << "You enter the bathroom to find a toilet, sink, and mirror.\n";
	bool inside = true;
	char choice;

	do {
		cout << "Bathroom\n";
		cout << "What would you like to do? [C]heck [I]nventory [E]xit\n";
		cin >> choice;

		switch (choice) {

		case('C'):
			char a, b;
			cout << "What would you like to check? [T]oilet [S]ink [B]ack\n";
			cin >> a;

			switch (a) {
			
			case('T'):
				cout << "You peer into the toilet, finding it filled to the brim with webbing. You figure it must not have been used in forever.";
				cin.ignore(256, '\n');
				cin.get(b);
				cout << "...But you can't help but wonder how all that webbing got there.";
				cin.get(b);
				cout << endl;
				break;

			case('S'):
				cout << "The sink is filled with webs and what appears to be egg sacs.";
				cin.get(b);
				cout << "You look up to the mirror, and find something written in red.\n";
				cin.get(b);
				cout << "7...4...8...7\n";
				cin.get(b);
				cout << "7487?\n";
				cin.get(b);
				break;

			case('B'):
				cout << endl;
				break;

			default:
				cout << "Invalid action\n" << endl;
			}
			break;

		case('I'):
			cout << endl;
			inventory();
			break;

		case('E'):
			cout << "\n";
			inside = false;
			break;
		default:
			cout << "Invalid action\n" << endl;
		}
	} while (inside);
}

void House::dinKit()
{
	bool inside = true;
	char choice;

	do {
		cout << "Kitchen\n";
		cout << "What would you like to do? [C]heck [I]nventory [G]o\n";
		cin >> choice;

		switch (choice) {
		
		case('C'):
			char a, b;
			cout << endl << "What would you like to check? [F]ridge [T]able [B]ack\n";
			cin >> a;
			switch (a) {

			case('F'):
				cout << "You look at the fridge. You see drawings of a happy family, seemingly the residents of the household.";
				cin.ignore(256, '\n');
				cin.get(b);
				cout << "As you look closer, you notice something strange. Each person's face is deformed, almost as if they have hundreds of eyes.";
				cin.get(b);
				cout << "You notice another drawing, entirely black, with scribbles of what appear to be a figure with many appendages coming from its body.";
				cin.get(b);
				cout << "A chill runs down your spine, and you step away from the fridge.\n";
				cin.get(b);
				break;

			case('T'):
				cout << "You look at the table, with four chairs perfect for a family. You decide to sit down and read the paper in front of you.";
				cin.ignore(256, '\n');
				cin.get(b);
				cout << "Most of the page is worn beyond recognition, but you can barely read some of the words on it.";
				cin.get(b);
				cout << "\"Woods... Cabin... missing... sp..ers...\"";
				cin.get(b);
				cout << "You get up and put the newspaper back down. What does this all mean?";
				cin.get(b);
				cout << endl;
				break;

			case('B'):
				cout << endl;
				break;

			default:
				cout << "Invalid Action\n" << endl;
			}
			break;

		case('I'):
			cout << endl;
			inventory();
			break;

		case('G'):
			char e;
			cout << "Where would you like to go? [B]athroom [L]iving room [S]tay \n";
			cin >> e;
			switch (e) {

			case('B'):
				bath();
				break;

			case('L'):
				inside = false;
				break;

			case('S'):
				cout << endl;
				break;

			default:
				cout << "Invalid action\n";
			}
			break;

		default:
			cout << "Invalid Action\n";
		}
	} while (inside);
}

static void intro()
{
	char a;
	cout << static_cast<char>(12);
	cout << "Creative Project Univ190 \n Zachary Aiello, Fall 2020 \n" << endl;

	cout << "NIGHTCRAWLERS (WIP)\n";
	cin.get(a);

	cout << "My name is Jack Barnaby. I live in a modest town, very quiet and separated from the outside world. Everyday I must drive";
	cout << " an hour to work through the Meridian Forest. One night, after a long day of work, I was driving home when suddenly...";
	cin.get(a); cout << endl;

	cout << "Awww great... I'm out of gas.";
	cin.get(a);
	cout << "...Guess I'll have to call for help. What? No service? Shoot.";
	cin.get(a);
	cout << "Looks like I'm going to have to go and find someone to help.";
	cin.get(a);

	cout << endl << "As you walk through the woods you come across a large wooden cabin. You find it quite strange, as you didn't know";
	cout << " anyone lived out here this far, especially with no paths leading here. You knock on the door, only to find it locked.";
	cin.get(a);
	cout << endl << "After checking around, you find that the side door is unlocked. You enter to find a small dining room and a kitchen.";
	cin.get(a);

	cout << endl << "No one's home... guess I should look around and see if anyone's here.";
	cin.get(a);
	cout << endl;
}

static void credits()
{
	char a;
	cout << "You exit the basement as fast as you can.";
	cin.get(a);
	cout << "As you exit the house, the front door swings open right in front of you.";
	cin.get(a);
	cout << "A giant, 3 foot arachnid scurries towards you from the woods.";
	cin.get(a);
	cout << "You close your eyes out of shock, but it draws closer and closer with each second.\n";
	cin.get(a);
	
	cout << "...Until....\n";
	cin.get(a);

	cout << "The End (?)";
	cin.get(a);
}

#endif