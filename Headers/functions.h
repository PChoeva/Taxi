#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cars.h>
#include <nodes.h>
#include <routes.h>


void addCar(/*vector<car> cars*/);
void addNode(/*vector<node> nodes*/);
void addRoute(/*vector<route> routes,vector<node> nodes*/);
void showAllNodes();
void showAllRoutes();
void showAllCars();
void saveCarsToFile();
void calcFuel();

void saveNodesToFile();
void readNodesFromFile();
void saveRoutesToFile();
void readRoutesFromFile();


#endif
