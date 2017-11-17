#include <vector>
#include <iostream>
#include "nodes.h"
#include "routes.h"
using namespace std;
route::~route(){}
route::route(){
//четене на много записи от клавиатурата и записване във вектор или ------
//четене на един запис ++++++
}
//vector<node> route::readFromConsole(){
//	int count = 0;
//	cout << "Enter the amount of bus stops to add:" << endl;
//	cin >> count;
//
//	//string firstName, lastName;
//	for(int i = 0; i < count; ++i)
//	{
//		node *n = new node();
//
//		v.push_back(*n);
//	}
//	return v;
//}
//void route::printConsole(){
//	cout<<"---Print all bus stops---"<<endl;
//	for(int i=0;i<v.size();i++){
//		v[i].printToFile();
//		v[i].printConsole();
//	}
//}
//setters
void route::set_nodes(vector<node> n){
	nodes = n;
}
void route::set_length(double len){
	length = len;
}
void route::set_laps(int l){
	
	laps = l;
}
//getters
vector<node> route::get_nodes(){
	return nodes;
}
double route::get_length(){
	return length;
}
int route::get_laps(){
	return laps;
}

void route::readConsole(vector<node> allNodes)
{
		cout<<"---Route Info---"<<endl;
		cout<<"Enter number of nodes:";
		int nodesCount; cin>>nodesCount;
		vector<int> nodeIdInput;
		int nodeId;
		for(int i=0;i<nodesCount;i++)
		{
			cout<<"Enter node "<<i+1<<" id:";
			cin>>nodeId;	nodeIdInput.push_back(nodeId);

		}
		vector<node> newRouteNodes;
		for(int i=0;i<nodeIdInput.size();i++)
		{
			for(int k=0;k<allNodes.size();k++)
			{
				if(nodeIdInput[i]==allNodes[k].get_id())
				{
					newRouteNodes.push_back(allNodes[k]);
				}
			}
		}
		set_nodes(newRouteNodes);


		cout<<"Enter length:";		cin>>length;
		cout<<"Enter laps:";		cin>>laps;

}
