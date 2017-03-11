#include "stdafx.h"
#include <iostream>
#include "Prob2.h"

#include <vector>
#include <string>

namespace prob2 {

	std::vector<std::string> split(const char *p, size_t n) {
		std::vector <std::string> V;
		int begin = 0;

		for (size_t i = 0; i < n; i++) {
			if (p[i] == '\0' && begin <= i) {
				V.push_back(std::string(&p[begin], &p[i]));
				begin = i + 1;
			}
		}
		return V;
	}

	int main(int argc, char *argv[]) {
		char p[] = "teste\0\0felipe\0cerqueira";
		auto V = split(p, sizeof(p));

		for (auto s : V) {
			std::cout << s << '\n';
		}

		return 0;
	}
}

