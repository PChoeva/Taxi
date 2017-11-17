/*
 * -----nice idea for development-----
 * ������� �� ����� �� ������ link(������, ������, ����������);
 * ��� ��������� �� �������, ������������������ �� ����
 * (�������� � ����� sequence/order)
 * ���� ����� �� �������� ������������������
 * � �� ��������� ���������� �/� ������� � �������� ������
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
