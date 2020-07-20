/*** random_walk.cpp start 
 * 
 * n = Anzahl an Schritten
 * Die Funktion gibt nen Tuple mit der Endposition zurueck
 * ***/

#include <tuple>
#include <list>

std::tuple<double,double> random_walk(unsigned int n){
	// jeweils eine liste fuer x und y
	std::list<double> x;
	std::list<double> y;

	// startwert ist koordinaten ursprung
	x.push_back(0);
	y.push_back(0);

	// randomizer initialisieren
	

	for (unsigned int i = 0; i < n; i++){




/*** random_walk.cpp end ***/
