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

int main() {
	cout << "Taxi :)" << endl;

	/*
	 * route *r = new route();
	 * r->readFromConsole();
	 * r->printConsole();
	 */
	/*
	 * Деструкторът трябва да записва векторите във файл !!!!!!!!!!!
	 * Конструкторът чете данните от файл и ги слага в масив?
	 * трябва ми friend функция за "колко гориво за една обиколка" (в класове: route[length],car[fuelCons])
	 *
	 */
	//MENU
	/*
	 * Да има възможност за избор на маршрутни таксита
	 * на което да се задава маршут
	 * и да извежда информация колко гориво да се зареди за извършване не дневната обиколка
	 */
	/*int choice = 0;*/
	//new version
	char choice ='0';
//	vector<car> cars;
//	vector<route> routes;
//	vector<node> nodes;


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
		//!!!ифовете не работят. Винаги влизат в телата си независимо от входа!!!
		/*if(!(isdigit(cin.get())))
		{
			cout<<"Illegal entry. Must be a number."<<endl;
			continue;
		}*/
		/*if(cin.get()<0||cin.get()>7/*||!(isdigit(cin.get()))*//*)
		{
			cout<<"Illegal entry. Not a valid option"<<endl;
			continue;
		}*/
		cin>>choice;
//		switch(choice)
//		{
//			case 1: addCar(/*cars*/); 		break;
//			case 2:	addRoute(/*routes, nodes*/);	break;
//			case 3: addNode(/*nodes*/); 	break;
//			case 4:	showAllCars();	break;
//			case 5: showAllRoutes();break;
//			case 6: showAllNodes(); break;
//			case 7: calcFuel(); break;
//			case 0: cout<<"exiting program";  saveNodesToFile(); saveRoutesToFile();readRoutesFromFile();/*system("CLS");*/ return 0;
//			default: {cout<<"Not a valid option"<<endl; break;}
//		}
		//new version
		if(isalpha(choice)||choice<'0'||choice>'7')
		{
			cout<<"Invalid option."<<endl;
			continue;
		}
		switch(choice)
				{
					case '1': addCar(/*cars*/); 		break;
					case '2':	addRoute(/*routes, nodes*/);	break;
					case '3': addNode(/*nodes*/); 	break;
					case '4':	showAllCars();	break;
					case '5': showAllRoutes();break;
					case '6': showAllNodes(); break;
					case '7': calcFuel(); break;
					case '0': cout<<"exiting program";  saveNodesToFile(); saveRoutesToFile();readRoutesFromFile();/*system("CLS");*/ return 0;
					default: {cout<<"Not a valid option"<<endl; break;}
				}
	}
	return 0;
}
