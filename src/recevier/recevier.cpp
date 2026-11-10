#include "recevier.hpp"

void handleRecevier(sf::TcpSocket& socket) {
	sf::TcpListener listener;

	if (listener.listen(53000) != sf::Socket::Status::Done) {
		std::cout << "Chujnia z portem\n";
		return;
	}

	std::cout << "\nNadawca:\n";

	std::cout << "Czekanie na polaczenie... \n";

	if (listener.accept(socket) != sf::Socket::Status::Done) {
		std::cout << "Chujnia \n";
		return;
	}

	auto remoteIp = socket.getRemoteAddress();
	std::cout << "Adres IP polaczonego urzadzenia: " << (remoteIp.has_value() ? remoteIp.value().toString() : "Nieznany") << "\n";
}