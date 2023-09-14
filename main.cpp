#include <iostream>
#include "application.h"
#include "matrix.h"
#include <ctime>

using namespace std;

int main() {
	setlocale(0, "");
	srand(time(NULL));
	
	TApplication a;

	return a.exec();
}
