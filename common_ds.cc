#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <unordered_set>


void PracticeString() {
	std::string name("Sahil");
	std::stringstream deets;
	deets << name << " Shah" << "\n" << "141 Tiffany Ave";
	std::cout << deets.str() << std::endl;
}

void PracticeSet() {
	std::set<int> s{3,2,4};
	s.insert(1);
	s.insert(3);
	std::cout << "Set is: ";
	std::for_each(s.begin(), s.end(),[](const int a){std::cout << a << std::endl;});
}


int main() {

	PracticeString();
	PracticeSet();

	return 0;
}