#include <iostream> // I/o

short mode;

int main() {
	std::cout << "Hello and welcome to Project Play.\n" << std::endl;
	std::cout << "------------| Input" << std::endl
		      << "Mod Creator | 1" << std::endl;
	std::cout << "What do you want to do ?";
	std::cin >> mode;
	if(mode == 1) {}
	return 0;
}