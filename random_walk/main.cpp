/*** main.cpp start ***/

#include <time.h>
#include <stdlib.h>
#include <iostream>

int main(){
	srand(time(NULL));

	std::cout << rand();
	std::cout << '\n';
	std::cout << time(NULL);
	std::cout << '\n';

	return 0;
}


/*** main.cpp end ***/
