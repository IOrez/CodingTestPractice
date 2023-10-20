#include <iostream>
#include <regex>
#include <string>

std::string input;
int t;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	std::cin >> t; std::cin.ignore();
	while (t--) {
		std::getline(std::cin, input);
		std::cout << (std::regex_match(input, std::regex("(100+1+|01)+")) ? "YES" : "NO") << '\n';
	}
	return 0;
}