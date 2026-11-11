#include "sender.hpp"

void handleSender(sf::TcpSocket& socket) {
	std::string recevierIP;
	std::cout << "Podaj ip odbiorcy: ";
	std::cin >> recevierIP;

	auto remoteIp = sf::IpAddress::fromString(recevierIP);

	if (!remoteIp.has_value()) {
		std::cout << "Blednie napisane IP spierdalaj\n";
		return;
	}

	std::cout << "\nLaczenie z " << recevierIP << " port 53000...\n";

	if (socket.connect(remoteIp.value(), 53000) != sf::Socket::Status::Done) {
		std::cout << "Chujnia\n";
		return;
	}

	std::cout << "Polaczono\n";

	std::string path = "input/input.zip";

	std::ifstream file(path, std::ios::binary);
	if (!file.is_open()) {
		std::cout << "\nNie da sie otworzyc pliku input/input.zip!\n";
		return;
	}
	else {
		std::cout << "\nOtwarto plik input.zip\n";
	}

	std::cout << "=====Pakiet=====\n";
	std::cout << "Wysylanie...\n";

	char buffer[4096];

	while (file) {
		file.read(buffer, sizeof(buffer));
		std::streamsize bytesRead = file.gcount();

		if (bytesRead <= 0) {
			break;
		}
		sf::Packet packet;
		packet.append(buffer, bytesRead);

		if (socket.send(packet) != sf::Socket::Status::Done) {
			std::cout << "Blad przy wysylaniu\n";
			break;
		}
	}

	sf::Packet endPacket;
	socket.send(endPacket);

	std::cout << "Wyslano\n";
}