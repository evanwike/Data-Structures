#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm> 
using namespace std;

struct Node {
	char letter;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(char letter) {
	auto* node = new Node;

	node->letter = letter;
	node->left = nullptr;
	node->right = nullptr;

	return node;
}

void postorder(struct Node* node) {
	if (!node)
		return;

	postorder(node->left);
	postorder(node->right);

	cout << node->letter;
}

Node* buildTree(map<char, string> &key) {
	ifstream fin("morse.txt");
	Node* root = new Node;

	char letter;
	string route;

	while (fin >> letter) {
		Node* node = newNode(letter);		// Node to be inserted
		Node* temp = root;					// Traverse while preserving reference to root

		fin.get();
		getline(fin, route);
		key.insert(pair<char, string>(letter, route));

		for (int i = 0; i < route.length() - 1; i++)
			temp = route[i] == '.' ? temp->left : temp->right;

		if (route.back() == '.')
			temp->left = node;
		else
			temp->right = node;
	}

	return root;
}

string decode(Node* root, const string &message) {
	Node* temp = root;
	string output;
	string code;
	int i = 0;

	while (i < message.length()) {
		char c = message[i];

		if (message[i + 1] == ' ') {
			temp = message[i] == '.' ? temp->left : temp->right;
			output += temp->letter;
			temp = root;
			i += 2;
			continue;
		}

		temp = message[i] == '.' ? temp->left : temp->right;
		code += message[i];
		i++;
	}

	return output;
}

string encode(Node* node, map<char, string> &key, const string &message) {
	string output;
	bool illegal = false;

	for (const auto &c : message) {
		try {
			output += key.at(c);
			output += ' ';
		}
		catch (const out_of_range& oor) {
			printf("Illegal character in message - %s", c);
			output += '?';
		}
	}

	return output;
}

int main() {
	map<char, string> key;
	Node* root = buildTree(key);

	string message;
	cout << "Enter a message to decode or Q/q to quit:" << endl;
	getline(cin, message);

	transform(message.begin(), message.end(), message.begin(), ::tolower);

	while (message != "q") {
		string encoded = encode(root, key, message);
		cout << "Encoded: " << encoded << endl;

		string decoded = decode(root, encoded);
		cout << "Decoded: " << decoded << endl;

		cout << endl;
		cout << "Enter a message to decode or Q/q to quit:" << endl;
		getline(cin, message);
	}
}