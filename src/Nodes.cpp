#include "nodes.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

node::node(){
//	cout<<"---Bus stop Info---"<<endl;
//
//	cout<<"Enter id:";		cin>>id;
//	cin.clear();fflush(stdin);
//	cout<<"Enter name:";	getline(cin,name);


}
node::~node(){}
//void node::printConsole(){
//	cout<<"id "<<id<<" | name "<<name<<endl;
//}
//void node::printToFile(){
//
//	ofstream fout("nodes.txt", ios::app);
//	if (fout.is_open()) {
//
//		fout<<"id "<<id<<" | name "<<name<<"\n";
//		fout.close();
//	}
//
//}
void node::set_id(int i)
{
	id = i;
}
void node::set_name(string n)
{
	name = n;
}
int node::get_id()
{
	return id;
}
string node::get_name()
{
	return name;
}
void node::readConsole(int lastId)
{
		//cout<<"---Node "<<lastId+1<<"Info---"<<endl;
		//cout<<"Enter id:";			cin>>id; //this->set_id(id);
		//cin.clear();
		id=lastId;
		cout<<"Enter name:";		cin>>name; //this->set_name(name);//getline(cin,name);
		//cout<<"--debug note cpp--"<<endl;
		//cin.clear();
}
