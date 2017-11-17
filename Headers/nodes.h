/*
 * -----nice idea for development-----
 * създава се масив от обекти link(спирка, спирка, разстояние);
 * при въвеждане на маршрут, последователността се пази
 * (примерно в масив sequence/order)
 * чрез цикъл се използва последователността
 * и се проверява разстояние м/у сегашна и следваща спирка
 */

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
		~node();
		void readConsole(int lastId);
		//void printConsole();
		//void printToFile();
		
		void set_id(int id);
		void set_name(string n);
		int get_id();
		string get_name();
};
#endif
