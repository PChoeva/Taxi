#include <string>
#include "routes.h"
#ifndef CARS_H
#define CARS_H
using namespace std;
class car{
	private:
		string brand;
		string model;
		int years;
		int seats;
		int loadCapasity;
		double fuelConsumption;
	public:
		car();
		~car();
		void printConsole();
		void readConsole();
		void calcFuelConsumption(route r);

		void set_brand(string b);
		void set_model(string m);
		void set_years(int y);
		void set_seats(int s);
		void set_loadCapasity(int l);
		void set_fuelConsumption(double f);
		
		string get_brand();
		string get_model();
		int get_years();
		int get_seats();
		int get_loadCapasity();
		double get_fuelConsumption();


};
#endif
