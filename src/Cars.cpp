#include "cars.h"
#include <iostream>
using namespace std;
//marka, model, godini, kolko mestna e, tovaropodemost,razhod gorivo
car::~car(){}
car::car()
{
//	cout<<"---Car Info---"<<endl;
//	cout<<"Enter brand:";			cin>>brand;
//	cout<<"Enter model:";			cin>>model;
//	cout<<"Enter years:";			cin>>years;
//	cout<<"Enter number of seats:"; cin>>seats;
//	cout<<"Enter load capasity:";	cin>>loadCapasity;
//	cout<<"Enter fuel consumption"; cin>>fuelConsumption;
}
void car::printConsole()
{
	cout<<brand<<" | "<<model<<" | "<<years<<" years | "<<seats<<" seats | "<<loadCapasity<<" loadCap | "<<fuelConsumption<<" fuelConsumption"<<endl;
}
//setters
void car::set_brand(string b)
{
	brand = b;
}
void car::set_model(string m)
{
	model = m;
}
void car::set_years(int y)
{
	years = y;
}
void car::set_seats(int s)
{
	seats = s;
}
void car::set_loadCapasity(int l)
{
	loadCapasity = l;
}
void car::set_fuelConsumption(double f)
{
	fuelConsumption = f;
}
//getters
string car::get_brand()
{
	return brand;
}
string car::get_model()
{
	return model;
}
int car::get_years()
{
	return years;
}
int car::get_seats()
{
	return seats;
}
int car::get_loadCapasity()
{
	return loadCapasity;
}
double car::get_fuelConsumption()
{
	return fuelConsumption;
}


/*car*/ void car::readConsole(){
	cout<<"---Car Info---"<<endl;
	cout<<"Enter brand:";			getline(cin,brand);
	cout<<"Enter model:";			getline(cin,model);
	cout<<"Enter years:";			cin>>years;
	cout<<"Enter number of seats:"; cin>>seats;
	cout<<"Enter load capasity:";	cin>>loadCapasity;
	cout<<"Enter fuel consumption:"; cin>>fuelConsumption;
}
void car::calcFuelConsumption(route r)
{
	//(len*laps)*fuelConsumption	(разход/100)*км
	cout<<"---Calculate fuel---\n"<<"car: "<<this->brand<<" | "<<this->model<<" | "<<this->fuelConsumption<<endl;
	cout<<"Needed fuel:"<<(fuelConsumption/100)*(r.get_length()*r.get_laps())<<endl;
}
