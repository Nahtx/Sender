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

	sf::TcpSocket socket;
	std::string input;

	std::cout << "Uwaga Odbiorca jako pierwszy musi zostac zadeklarowyny\n";

	std::cout << "\nNapisz czy jestes Nadawca czy Odbiorca(n/o):";
	std::cin >> input;

	std::cout << "\nPrzygotowywanie...\n";

	if(input == "o") {
		getComputerInfo();
		std::filesystem::create_directory("output");

		std::cout << "\n=====Odbiorca=====\n";

		handleRecevier(socket);
	} 
	else if (input == "n") {
		getComputerInfo();
		std::filesystem::create_directory("input");

		std::cout << "\n=====Nadawca=====\n";
		std::cout << "Umiesc pliki input.zip w folderze \"input\" i napisz \"y\" jezeli gotowe: ";
		std::cin >> input;
		if (input == "y") {
			handleSender(socket);
		}
		else {
			std::cout << "Podano zly znak\n";
			return -1;
		}
	}
	else {
		std::cout << "Podano zly znak\n";
		return -1;
	}

	std::cout << "\n\nNacisnij Enter, aby zamknac program...";
	std::cin.ignore();
	std::cin.get();

	return 0;
}