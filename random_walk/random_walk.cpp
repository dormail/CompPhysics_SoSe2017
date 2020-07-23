/*** random_walk.cpp start 
 * 
 * n = Anzahl an Schritten
 * Die Funktion gibt nen Tuple mit der Endposition zurueck
 * ***/

#include <tuple>
#include <list>
#include <cmath>
#include "functions.h"

#include <iostream>

std::tuple<int, int> random_walk(unsigned int n){
	// jeweils eine liste fuer x und y, als int die aktuelle posi
	std::list<int> x;
	std::list<int> y;

	int xnew = 0, ynew = 0;

	// startwert ist koordinaten ursprung
	x.push_back(0);
	y.push_back(0);

	// int der die naechste richtung beschreibt
	// 0 rechts
	// 1 oben
	// 2 links
	// 3 unten
	unsigned int dir = 0;

	// variablen fuer die ueberpruefung auf selbstueberschneidungen
	std::list<int>::iterator x_it;
	std::list<int>::iterator y_it;

	bool test = false;

	// if the path is in a one way he needs to restart
	// break_counter is counting the times the program self crossed
	// after a few times self crossing it raises an exception
	unsigned int break_counter = 0;

	for (unsigned int i = 0; i < n; i++){
		//std::cout << i << '\n';
		// naechste bewegungsrichtung
		dir = rand() % 4 + 0;
		
		// switch case fuer bewegung
		switch(dir){
			case 0:
				xnew = x.back() + 1;
				ynew = y.back();
				break;
			case 1:
				xnew = x.back();
				ynew = y.back() + 1;
				break;
			case 2:
				xnew = x.back() - 1;
				ynew = y.back();
				break;
			case 3:
				xnew = x.back();
				ynew = y.back() - 1;
				break;
		}
	
		// an liste anhaengen
		//x.push_back(xnew);
		//y.push_back(ynew);

		// ueberpruefen ob schon mal an dem ort war
		y_it = y.begin(); // der y iterator muss manuell zurueck gesetzt werden
		if (i > 0){
			for(x_it = x.begin(); x_it != (--x.end()); ++x_it){
				
				// abbruch wenn selbstueberschneidung
				if (*x_it == xnew && *y_it == ynew){
					// Reste vom debuggen
					//std::cout << *x_it << '\t' << xnew << '\t' << *y_it << '\t' << ynew << '\n';
					//std::cout << i << '\n';
					//std::cout << "self crossing detected\n";

					test = true;

					// if the path is in a one way he needs to restart
					++break_counter;
					//std::cout << "Breaks: " << break_counter << '\n';

					test = true;
					break;
				}
	
				++y_it;
			}
		}
		if (!test){
			x.push_back(xnew);
			y.push_back(ynew);
			break_counter = 0;
		}
		else{
			--i;
		}
		test = false;
    
		// if the path is in a one way he needs to restart
		if (break_counter > 4){
			throw 1;
		}

	}


	std::tuple<int, int> result(x.back(), y.back());

	return result;
}


/*** random_walk.cpp end ***/
