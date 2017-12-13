//============================================================================
// Name        : Taxi.cpp
// Author      : Petya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <functions.h>
#include <iostream>

using namespace std;
int menu();
bool isValidChoice(int choice);
int main() {
	cout << "Taxi :)" << endl;
	menu();
	int choice = 0;

		readNodesFromFile();
		readRoutesFromFile();

		while(true){
			cout<<"-----------------Main Menu-----------------"<<endl;
			cout<<"| 1. Enter new car            		  |"<<endl;
			cout<<"| 2. Enter new route         		  |"<<endl;
			cout<<"| 3. Enter new node(bus stop)		  |"<<endl;
			cout<<"| 4. Show all cars           		  |"<<endl;
			cout<<"| 5. Show all routes          		  |"<<endl;
			cout<<"| 6. Show all nodes           		  |"<<endl;
			cout<<"| 7. Choose a car and a route and view the|"
				"\n|    needed fuel             	  	  |"<<endl;
			cout<<"==========================================="<<endl;
			cout<<"| 0. Exit                                 |"<<endl;
			cout<<"-------------------------------------------"<<endl;

			cout<<"Choice: ";

			cin>>choice;
			if(! isValidChoice(choice)){continue;}
			cout<<"Choice: "<<choice<<endl;

			switch(choice)
			{
				case 1: addCar(); 		break;
				case 2:	addRoute();	break;
				case 3: addNode(); 	break;
				case 4:	showAllCars();	break;
				case 5: showAllRoutes();break;
				case 6: showAllNodes(); break;
				case 7: calcFuel(); break;
				case 0: {
							cout<<"exiting program";
							saveCarsToFile();
							saveNodesToFile();
							saveRoutesToFile();
							readRoutesFromFile();
							return 0;
						}
				default: {cout<<"Not a valid option"<<endl; break;}
			}
		}
	return 0;
}


//MENU
int menu()
{

}

//check boundaries for 'choice'
bool isValidChoice(int choice)
{
	if(choice>=0 && choice <8)
	{
		return true;
	}
	else
	{
		return false;
	}
}
