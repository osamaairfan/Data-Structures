#include <iostream>
using namespace std;

class Hash {
public:
	int hashtable[10];

	Hash() {
		for (int i = 0; i < 10; i++) {        //Initially put every element -1 or 0 in the table
			hashtable[i] = -1;
		}
	}

	int hashfunction(int key) {              //Hash 1 Method
		return key % 10;
	}

	int hashfunction2(int key) {             //Hash 2 Method
		return (7 - (key % 7));
	}

	void insertkey(int key) {
		int i = hashfunction(key);

		if (hashtable[i] == -1)
			hashtable[i] = key;
		else {
			int i2 = hashfunction2(key);
			int j = 0;
			for (int k = 0; k < 10; k++) {
				int i3 = (i + (j * i2)) % 10;
				if (hashtable[i3] == -1)
				{
					hashtable[i3] = key;
					break;
				}
				j++;
			}
		}
	}

	int searchkey(int key) {
		int i = hashfunction(key);

		if (hashtable[i] == key)
			return i;
		else {
			int i2 = hashfunction2(key);
			int j = 0;
			for (int k = 0; k < 10; k++) {
				int i3 = (i + (j * i2)) % 10;
				if (hashtable[i3] == key) {
					return key;
				}
				i++;
			}
		}
	}

	void deletekey(int key) {
		int i = hashfunction(key);

		if (hashtable[i] == key)
			hashtable[i] = -1;
		else {
			int i2 = hashfunction2(key);
			int j = 0;
			for (int k = 0; k < 10; k++) {
				int i3 = (i + (j * i2)) % 10;
				if (hashtable[i3] == key)
				{
					hashtable[i3] = -1;
					break;
				}
				j++;
			}
		}
	}

	void display() {
		cout << endl;
		for (int i = 0; i < 10; i++) {
			cout << hashtable[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Hash h1;
	h1.insertkey(43);
	h1.insertkey(145);
	h1.insertkey(72);
	h1.insertkey(23);
	h1.insertkey(99);
	h1.insertkey(19);
	h1.insertkey(82);

	int i = h1.searchkey(99);
	cout << "99 is at index: " << i << endl;
	h1.display();
	h1.deletekey(99);
	h1.display();
}