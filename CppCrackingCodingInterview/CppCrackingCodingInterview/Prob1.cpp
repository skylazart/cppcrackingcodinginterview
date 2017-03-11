#include "stdafx.h"
#include "Prob1.h"

Prob1::Prob1(const std::vector<int>& V)
{
	std::unordered_set<int> set;

	for (size_t i = 0; i < V.size(); i++) {
		for (size_t j = i + 1; j < V.size(); j++) {
			int x = V[i] + V[j];
			int needed = -x;

			if (set.find(needed) == set.end()) {
				set.insert(V[i]);
				continue;
			}

			std::cout << V[i] << " " << V[j] << " " << needed << '\n';
		}
	}
}

Prob1::~Prob1()
{
}