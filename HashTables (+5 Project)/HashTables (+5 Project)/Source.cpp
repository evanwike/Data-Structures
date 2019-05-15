#include <iostream>
#include <string>

using namespace std;

const int SIZE = 7;
const int HASH_KEY = 7;

struct HashEntry {
	string data;
	HashEntry *next;

	HashEntry() {
		this->next = nullptr;
	}
};

struct HashTable {
	HashEntry *table[SIZE];

	static int getIndex(const string &key) {
		int index = 0;

		for (const auto &c : key)
			index += c - '0';

		return index % HASH_KEY;
	}

	void insert(const string &key, const string &data) {
		auto *entry = new HashEntry;
		entry->data = data;
		int index = getIndex(key);

		if (table[index] == nullptr)
			table[index] = entry;
		else {
			auto *temp = table[index];

			while (temp->next)
				temp = temp->next;

			temp->next = entry;
		}
	}

	void displayTable() {
		for (int i = 0; i < SIZE; i++) {
			auto *entry = table[i];
			cout << i << ". ";

			if (entry != nullptr) {
				cout << entry->data;
				auto *temp = entry->next;

				while (temp) {
					cout << " -> " << temp->data;
					temp = temp->next;
				}
			}
			cout << endl;
		}
	}

	pair<int, HashEntry *> search(const string &key, const string &data) {
		int index = getIndex(key);
		auto *temp = table[index];

		if (temp)
			while (temp->next && temp->data != data)
				temp = temp->next;
		else
			return { -1, nullptr };

		if (temp->data != data)
			return { -1, nullptr };
		return { index, temp };
	}
};

int main() {
	HashTable table{};

	pair<string, string> inserts[] = {
			{"100", "Adam"}, {"101", "Steve"}, {"151", "John"}, {"111", "Kratos"}, {"190", "Lara"},
			{"201", "Mario"}, {"133", "Nathan"}, {"913", "Zelda"}, {"555", "Cortana"}, {"717", "Gordon"}
	}, searches[] = {
			{"111", "Kratos"}, {"555", "Cortana"}, {"190", "Lara"}, {"111", "Malukah"}
	};

	cout << "Hash Table" << endl;
	cout << string(10, '*') << endl;
	for (const auto &p : inserts)
		table.insert(p.first, p.second);

	table.displayTable();

	cout << "\nSearches" << endl;
	cout << string(10, '*') << endl;
	for (const auto &p : searches) {
		auto result = table.search(p.first, p.second);
		cout << result.first << ' ' << p.second << endl;
	}

	system("pause");
}