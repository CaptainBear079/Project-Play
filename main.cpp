#include <iostream> // I/o

char mode; // Mode of the program

int main() {
	std::cout << "Hello and welcome to Project Play.\n" << std::endl;
	std::cout << "-------------| Input" << std::endl
		      << "Mod Creator  | 1   Coming soon!" << std::endl
		      << "Game Creator | 2   Coming soon!" << std::endl
		      << "";
	std::cout << "What do you want to do ?";
	std::cin >> mode;
	if(mode == '1') {}
	return 0;
}