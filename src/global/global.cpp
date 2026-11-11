#include "global.hpp"

void checkPath(std::string& path) {
	if (path.length() >= 2 && path.front() == '"' && path.back() == '"') {
		path = path.substr(1, path.length() - 2);
	}

	for (char& c : path) {
		if (c == '\\') {
			c = '/';
		}
	}
}