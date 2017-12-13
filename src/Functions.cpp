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


ostream &operator<<(ostream &out, car &c)
{
	out<<c.brand<<"| "<<c.model<<" | "<<c.years
			<<" | "<<c.seats<<" | "<<c.loadCapasity
			<<" | "<<c.fuelConsumption<<endl;
	return out;
}

//Add Cars
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
		cout<<"Car "<<i+1<<": "<<cars[i];
	}
}
void saveCarsToFile()
{
	ofstream outfile("cars.txt");//, ios::out);
		for(int i=0;i<cars.size();i++)
		{
			cout<<"Save cars to file";
			outfile<<cars[i];
		}
	outfile.close();
}



//Routes
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
//Show routes
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

//Redefine <<
ostream &operator<<(ostream &out,route &r)
{
	for(int k=0;k<r.nodes.size();k++)
	{
		out<<r.nodes[k].get_id()<<" "<<r.nodes[k].get_name()<<" ";
		cout<<"write a single node"<<endl;
	}
	out<<"|"<<r.length<<"|"<<r.laps<<endl;
	cout<<"end with writing into the file"<<endl;
	return out;
}
void saveRoutesToFile()
{
	ofstream outfile("routes.txt", ios::out);
	cout<<"Save to file"<<endl;
	for(int i=0;i<routes.size();i++)
	{
		outfile<<routes[i];
	}
	outfile.close();
}
void readRoutesFromFile()
{
	ifstream infile("routes.txt", ios::in);
	char delimiter = '|';
	int i = 0;
	cout<<"read routes.txt"<<endl;
	while(!infile.eof()) // For every route
	{
		vector<node> tempnodes;
		int len;
		int laps;
		route temproute;
		//routes.clear();
		int k = 0;

		while((infile.peek() != delimiter) && (infile.peek() != -1)) // For Every Node
		{
			if(infile.peek() == ' ')
			{
				infile.get();
				continue;
			}
			int nodeId;
			string nodeName;
			node tempnode;
			infile >> nodeId;
			infile >> nodeName;
			tempnode.set_id(nodeId);
			tempnode.set_name(nodeName);
			tempnodes.push_back(tempnode);
		}
		infile.get();
		infile >> len;
		infile.get();
		infile >> laps;
		infile.get();

		temproute.set_nodes(tempnodes);
		temproute.set_length(len);
		temproute.set_laps(laps);
		routes.push_back(temproute);
	}
	infile.close();
	cout<<"finished reading routes.txt"<<endl;
}
//Add Notes
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
			cout<<nodes[i];
		}
}

//Redefine <<
ostream &operator<<(ostream &out, node &n)
{
	out<<n.id<<" | "<<n.name<<endl;
	return out;
}
void saveNodesToFile()
{
	ofstream outfile("nodes.txt", ios::out);
	for(int i=0;i<nodes.size();i++)
	{
		cout<<"Save to file";
		outfile<<nodes[i];;
	}
	outfile.close();
}
void readNodesFromFile()
{
	int id;
	string name;
	char delimiter;
	ifstream infile("nodes.txt", ios::in);
	cout<<"Read file node"<<endl;
	for(int i=0;i<nodes.size();i++)
	{
		infile>>id>>delimiter>>name;
		nodes[i].set_id(id);
		nodes[i].set_name(name);
		cout<<"print node "<<i<<": "<<id<<delimiter<<" "<<name<<endl;
	}
	cout<<"finished reading note.txt"<<endl;
	infile.close();
}

//Calculate Fuel Consumption
void calcFuel()
{
	int carId,routeId;

	cout<<"Enter car id: "; cin>>carId; carId-=1;
	cout<<"Enter route id: "; cin>>routeId; routeId-=1;
	cars[carId].calcFuelConsumption(routes[routeId]);
}
