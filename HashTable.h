#pragma once

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

template <typename HashItem>
class HashTable {
private:
	std::vector<std::list<HashItem>> table;

	size_t FindPos(size_t hashedObject) {
		size_t position = hashedObject % (hashedObject/table.capacity());
		return position;
	}

public:
	HashTable() = delete;

	explicit HashTable(size_t table_size) {
		table.reserve(table_size);

		std::list<HashItem> list = {};
		for (size_t i{ 0 }; i < table.capacity(); i++)
			table.push_back(list);
	}

	void Insert(const HashItem& item) {
		std::hash<HashItem> hf;
		size_t hashValue = hf(item);
		auto position = FindPos(hashValue);

	    auto &head=table[position];
		bool found = (std::find(head.begin(), head.end(), item) != head.end());
		if (!found) {
			head.push_back(item);
		}
		else {
			std::cout << "item already exists" << std::endl;
		}
	};

	void Print() {
		for (size_t i{ 0 }; i < table.capacity(); i++) {
			auto list = table[i];
			for (auto & item : list) {
				std::cout<< "index " << i <<" => "<< item << std::endl;
			}
		}
	}

	bool Contains(HashItem& item) {
		std::hash<HashItem> hf;
		size_t hashValue = hf(item);
		size_t position = FindPos(hashValue);

		auto & list = table[position];

		for (auto& value : list)
			if (item == value)
				return true;
		return false;
	}

	/*void Remove(const HashItem& item);*/
};

#endif // !HASH_TABLE_H
