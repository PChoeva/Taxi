#include<string>
#ifndef NODES_H
#define NODES_H
using namespace std;
class node{
	private:
		int id;
		string name;
	public:
		node();
		node(int i, string n);
		~node();
		void readConsole(int lastId);
		//void printConsole();
		//void printToFile();
		friend ostream &operator<<(ostream &out, node &n);
		
		void set_id(int id);
		void set_name(string n);
		int get_id();
		string get_name();
};
#endif
