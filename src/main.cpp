#include "global/global.hpp"

#include "sender/sender.hpp"
#include "recevier/recevier.hpp"

void getComputerInfo() {
	std::cout << "\n=====Info o kompie=====";

	auto ipV4 = sf::IpAddress::getLocalAddress(sf::IpAddress::Type::IpV4);
	std::cout << "\nLokalny adres IPv4: " << (ipV4.has_value() ? ipV4.value().toString() : "Brak");
	
	std::cout << "\nPort: 53000\n";
}

int main() {
	std::cout << "Uwaga Odbiorca jako pierwszy musi zostac zadeklarowyny\n";

	sf::TcpSocket socket;

	std::cout << "\nNapisz \"1\" dla Odbiorcy lub \"2\" dla Nadawcy: ";
	int input;
	std::cin >> input;
	
	switch (input) {
		case 1: {
			getComputerInfo();
			handleRecevier(socket);
			break;
		}
		case 2: {
			getComputerInfo();
			handleSender(socket);
			break;
		}
	}

	std::cout << "\n\nNacisnij Enter, aby zakonczyc program...";
	std::cin.ignore();
	std::cin.get();

	return 0;
}