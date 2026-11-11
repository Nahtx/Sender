#include "recevier.hpp"

void handleRecevier(sf::TcpSocket& socket) {
	sf::TcpListener listener;

	if (listener.listen(53000) != sf::Socket::Status::Done) {
		std::cout << "Chujnia z portem\n";
		return;
	}

	std::cout << "Czekanie na polaczenie... \n";

	if (listener.accept(socket) != sf::Socket::Status::Done) {
		std::cout << "Chujnia \n";
		return;
	}

	auto remoteIp = socket.getRemoteAddress();
	std::cout << "Adres IP polaczonego urzadzenia: " << (remoteIp.has_value() ? remoteIp.value().toString() : "Nieznany") << "\n";

	std::cout << "=====Pakiet=====\n";

	std::string fullPath = "output/output.zip";

	std::ofstream outFile(fullPath, std::ios::binary);
	if (!outFile.is_open()) {
		std::cout << "Nie mozna utworzyc pliku output.zip!\n";
		return;
	}

	std::cout << "Odbieranie pliku...\n";
	
	sf::Packet packet;
	while (socket.receive(packet) == sf::Socket::Status::Done) {
		if (packet.getDataSize() == 0) {
			break;
		}

		outFile.write(static_cast<const char*>(packet.getData()), packet.getDataSize());
		packet.clear();
	}

	std::cout << "Zakonczono\n";
}