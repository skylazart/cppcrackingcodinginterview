#include "stdafx.h"
#include "Prob3.h"
#include <iostream>
#include <string>
#include <memory>

namespace prob3 {
	template <typename T>
	struct bt_node {
		T value;
		std::shared_ptr<bt_node<T>> left;
		std::shared_ptr<bt_node<T>> right;

		bt_node(T  v) : value{ v }, left{ nullptr }, right{ nullptr } {
			
		}
	};

	typedef std::shared_ptr<bt_node<char>> bt_node_char_ptr;

	void dfs(bt_node_char_ptr t1, bt_node_char_ptr t2, std::string in_order, size_t n) {
		if (t1 == nullptr && t2 == nullptr) {
			if (n >= 2) {
				std::cout << "In order: " << in_order << '\n';
				return;
			}
		}

		if (t1 == nullptr || t2 == nullptr)
			return;

		if (t1->value != t2->value) {
			return;
		}

		std::string left = in_order + t1->value + " ";
		std::string right = in_order + t1->value + " ";
		dfs(t1->left, t2->left, left, n + 1);
		dfs(t1->right, t2->right, right, n + 1);
	}

	void find_duplicated_subtrees(bt_node_char_ptr t1, bt_node_char_ptr t2) {
		if (t1 == nullptr) return;
		dfs(t1, t2, "", 0);
		find_duplicated_subtrees(t1->left, t2);
		find_duplicated_subtrees(t1->right, t2);
	}

	int main(int argc, char *argv[]) {
		bt_node_char_ptr t1(new bt_node<char>('A'));
		t1->left = std::make_shared<bt_node<char>> (bt_node<char>('B'));
		
		t1->left->left = std::make_shared<bt_node<char>>(bt_node<char>('D'));
		t1->left->right = std::make_shared<bt_node<char>>(bt_node<char>('E'));

		t1->right = std::make_shared<bt_node<char>>(bt_node<char>('C'));
		t1->right->right = std::make_shared<bt_node<char>>(bt_node<char>('B'));
		t1->right->right->left = std::make_shared<bt_node<char>>(bt_node<char>('D'));
		t1->right->right->right = std::make_shared<bt_node<char>>(bt_node<char>('E'));
		
		find_duplicated_subtrees(t1->right, t1->left);
		return 0;
	}
};
