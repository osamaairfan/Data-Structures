#include <iostream>
using namespace std;

class Hash {
public:
	int hashTable[10];

	Hash() {
		for (int i = 0; i < 10; i++) {
			hashTable[i] = -1;
		}
	}

	int HashFunction(int key) {
		return key % 10;
	}

	void insertKey(int key) {
		int i = HashFunction(key);
		while (i < 10) {
			if (hashTable[i] == -1) {
				hashTable[i] = key;
				return;
			}
			else 
				i++;
		}
	}

	int searchKey(int key) {
		int i = HashFunction(key);
		while (i < 10) {
			if (hashTable[i] == key) {
				cout << "The key " << key << " is at index: " << i << endl;
				return i;
			}
			else 
				i++;
		}
	}

	void deleteKey(int key) {
		int i = HashFunction(key);
		while (i < 10) {
			if (hashTable[i] == key) {
				hashTable[i] = 0;
				return;
			}
			else 
				i++;
		}
	}

	void display() {
		for (int i = 0; i < 10; i++) {
			cout << hashTable[i] << " ";
		}
		cout << endl << endl;
	}
};

int main() {
	Hash h1;
	h1.insertKey(15);
	h1.insertKey(24);
	h1.insertKey(81);
	h1.insertKey(57);
	h1.insertKey(84);
	h1.insertKey(27);
	cout << "Hash Table:" << endl;
	h1.display();
	
	cout << "After Deleting:" << endl;
	h1.deleteKey(84);
	h1.display();
	h1.searchKey(24);

	return 0;
}
