#include "sender.hpp"

void handleSender(sf::TcpSocket& socket) {

	std::string serverIP;
	std::cout << "Podaj ip odbiorcy: ";
	std::cin >> serverIP;

	auto remoteIp = sf::IpAddress::fromString(serverIP);

	if (!remoteIp.has_value()) {
		std::cout << "Blednie napisane IP spierdalaj\n";
		return;
	}

	std::cout << "\nLaczenie z " << serverIP << " port 53000...\n";

	if (socket.connect(remoteIp.value(), 53000) != sf::Socket::Status::Done) {
		std::cout << "Chujnia\n";
		return;
	}

	std::cout << "Polaczono";
}