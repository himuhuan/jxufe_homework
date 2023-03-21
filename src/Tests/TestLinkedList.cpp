#include "LinkedList.hpp"

int main() {
	LinkedList<int> l;
	
	for (auto i = 1; i < 15; i++)
		l.push_back(i);
	l.display();
	l.push_front(0);
	l.push_back(15);
	l.display();

	std::cout << l.find(2)->val() << std::endl;
	l.erase(2);
	l.display();
	l.insert(l.find(1), -1);
	l.display();
	return 0;
}