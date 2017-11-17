#include <cars.h>
#include <functions.h>
#include <nodes.h>
#include <routes.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<car> cars;
vector<route> routes;
vector<node> nodes;
void addCar()
{
	car c;
	int num;
	cout<<"How many cars do you want to enter? "; cin>>num;

	for(int i=0;i<num;i++)
	{
		c.readConsole();
		cars.push_back(c);
	}
}
void showAllCars()
{
	for(int i=0;i<cars.size();i++)
	{
		cout<<"Car "<<i+1<<": "<<cars[i].get_brand()<<" | "<<cars[i].get_model()<<" | "<<cars[i].get_years()<<" | "<<cars[i].get_seats()<<" | "<<cars[i].get_loadCapasity()<<" | "<<cars[i].get_fuelConsumption()<<endl;
	}
}
void addRoute()
{
	route r;
	int num;
	cout<<"To enter routes you must add nodes first !"<<endl;
	if(nodes.empty())
	{
		cout<<"There are no nodes to choose from."<<endl;
	}
	else
	{
		cout<<"How many routes do you want to enter? "; cin>>num;
		for(int i=0;i<num;i++)
		{
			r.readConsole(nodes);
			routes.push_back(r);
		}
	}

}
void showAllRoutes()
{
	vector<node> ns;
	cout<<"=====Show all routes====="<<endl;
	for(int i=0;i<routes.size();i++)
	{
		ns=routes[i].get_nodes();
		cout<<"Route "<<i+1<<" : "<<endl;
		if(ns.empty())
		{
			cout<<"Cannot take nodes from the vector."<<endl;
		}
		for(int k=0;k<ns.size();k++)
		{
			cout<<"Node "<<k+1<<" info: "<<ns[k].get_id()<<" | "<<ns[k].get_name()<<endl;
		}
		cout<<"route length: "<<routes[i].get_length()<<"\nlaps:  "<<routes[i].get_laps()<<endl;
		cout<<"========================="<<endl;
	}
}
void saveRoutesToFile()
{
	ofstream outfile("routes.txt", ios::out);
	cout<<"Save to file"<<endl;
	for(int i=0;i<routes.size();i++)
	{

		for(int k=0;k<routes[i].get_nodes().size();k++)
		{
			outfile<<routes[i].get_nodes()[k].get_id()<<" ";
			cout<<"write a single node"<<endl;
		}
		outfile<<"|"<<routes[i].get_length()<<"|"<<routes[i].get_laps()<<endl;
		cout<<"end with writing into the file"<<endl;
	}
}
void readRoutesFromFile()
{
	int length,laps,k=0;
	vector< vector<int> > stops;//масив с ид номерата на спирките
	char delimiter='|';
	int c;
	ifstream infile("routes.txt", ios::in);
	cout<<"Read file routes"<<endl;
	for(int i=0;i<routes.size();i++)
	{
		cout<<"for 1"<<endl;
		vector<int> temp;

		while(infile.peek()!=delimiter && infile.peek()!=-1/*>>delimiter && delimiter==' '*/)// '|'
		{
			if(infile.peek()==32)
			{
				infile.get();
				continue;
			}
			cout<<"Peek:"<<infile.peek()<<endl;
			cout<<"for 2 - read nodes from file"<<endl;
			infile>>c;
			temp.push_back(c);

			k++;
			cout<<"for 2 - end of while"<<endl;
		}
		stops.push_back(temp);
		cout<<"Print stops:"<<endl;
		for(int r=0;r<stops[i].size();r++)
		{
			cout<<stops[i][r]<<" ";
		}
//		cout<<"continue reading from file"<<endl;
		infile>>delimiter>>length>>delimiter>>laps;
//		cout<<"length:"<<length<<endl;
//		cout<<"laps:"<<laps<<endl;

		cout<<"---Try to print nodes from 2D vector---"<<endl;
		for(int p=0;p<stops.size();p++)
		{
			cout<<"loop 1-out"<<endl;
			for(int y=0;y<stops[p].size();y++)
			{
				cout<<"loop2-in"<<endl;
				cout<<stops[p][y]<<" /";
			}
		}

		routes[i].set_length(length);

		routes[i].set_laps(laps);

		cout<<"print route "<<i<<": ";
		for(int j=0;j<stops[i].size();j++)
		{
			cout<<routes[i].get_nodes()[j].get_id()<<" "<<routes[i].get_nodes()[j].get_name()<<" ";
		}

		cout<<delimiter<<length<<" "<<delimiter<<" "<<laps<<endl;
	}
}
void addNode()
{
	node n;
	int num;
	int lastId=0;
	cout<<"How many nodes do you want to enter? "; cin>>num;
	if(!nodes.empty())
	{
		lastId=nodes[nodes.size()-1].get_id();
	}

	for(int i=0;i<num;i++)
	{
		cout<<"---Node "<<i+1<<" ---"<<endl;
		n.readConsole(lastId);
		nodes.push_back(n);
		lastId++;
	}
}
void showAllNodes()
{
	for(int i=0;i<nodes.size();i++)
		{
			cout<<nodes[i].get_id()<<" | "<<nodes[i].get_name()<<endl;
		}
}
void saveNodesToFile()
{
	ofstream outfile("nodes.txt", ios::out);
		for(int i=0;i<nodes.size();i++)
		{
			cout<<"Save to file";
			outfile<<nodes[i].get_id()<<" | "<<nodes[i].get_name()<<endl;
		}
}
void readNodesFromFile()
{
	int id;
	string name;
	char delimiter;
	ifstream infile("nodes.txt", ios::in);
	cout<<"Read file"<<endl;
	for(int i=0;i<nodes.size();i++)
	{
		infile>>id>>delimiter>>name;
		nodes[i].set_id(id);
		nodes[i].set_name(name);
		cout<<"print node "<<i<<": "<<id<<delimiter<<" "<<name<<endl;
	}
}
void calcFuel()
{
	int carId,routeId;

	cout<<"Enter car id: "; cin>>carId; carId-=1;
	cout<<"Enter route id: "; cin>>routeId; routeId-=1;
	cars[carId].calcFuelConsumption(routes[routeId]);
//	for(int i=0,k=0;i<cars.size(),k<routes.size();i++,k++)
//	{
//		if(carId==i && routeId==k)
//		{
//			cars[i].calcFuelConsumption(routes[k]);
//		}
//	}
}
