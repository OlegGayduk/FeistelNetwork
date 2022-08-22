#include <iostream>
using namespace std;

void crypt(long int &L, long int &R) {
	int k1 = L, k2 = R, k3 = 0;

	for (int i = 1; i <= 2; i++) {
		k3 = k1;
		k1 = k2 ^ ((k1 + i) % 256);
		k2 = k3;
	}

	L = k1;
	R = k2 ^ ((L + 3) % 256);
}

void decrypt(long int &L, long int &R) {
	int k1 = L, k2 = R, k3 = 0;

	for (int i = 3; i > 1; i--) {
		k3 = k1;
		k1 = k2 ^ ((k1 + i) % 256);
		k2 = k3;
	}

	L = k1;
	R = k2 ^ ((L + 1) % 256);
}

int main() {
	_int64 msg;
	long int R = 0, L = 0;

	cout << "Enter your message: ";
	cin >> hex >> msg;

	L = msg / 268435456;
	R = msg % 268435456;

	crypt(L, R);

	cout << "Encrypted message: " << hex << L << hex << R << endl;

	decrypt(L, R);

	cout << "Decrypted message: " << hex << L << hex << R << endl;

	return 0;
}