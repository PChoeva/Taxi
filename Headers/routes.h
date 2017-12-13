#include <nodes.h>
#include <cwchar>
#include <vector>

#ifndef ROUTES_H
#define ROUTES_H

class route{
	private:
		vector<node> nodes;

		double length;
		int laps;
	public:
		route();
		route(vector<node> n, double len, int l);
		~route();
		void readConsole(vector<node> allNodes);
		friend ostream &operator<<(ostream &out,route &r);
		//void printConsole();
		
		void set_nodes(vector<node> n);
		void set_length(double len);
		void set_laps(int l);
		
		vector<node> get_nodes();
		double get_length();
		int get_laps();
};
#endif
