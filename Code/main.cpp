#include <iostream>
#include "menu.h"


int main()
{
	string state = "";
	cout << "Do you want to fill the deque? (to fill, enter: 1; do not fill out, enter something else)\n"
			"Enter: ";
	cin >> state;

	if (state == "1")
	{
		Menu* me = new Menu(true);
		cout << "Deque was filled." << endl;
		me->run();
	}
	else 
	{ 
		Menu* me = new Menu(false);
		cout << "Deque wasn't filled." << endl;
		me->run();
	}
}
