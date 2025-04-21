#include <iostream>
#include <string>
#include <random>
#include <time.h>
using namespace std;

long enc(char l, long key, int ind) {
	int encrypted = ((int(l) ^ key) * key) ^ ind;
	return encrypted;
}

long encp(char lp, char l, long key, int ind) {
	int encrypted = ((int(l) ^ key) * key) ^ enc(lp,key,ind);
	return encrypted;
}

char dec(long encrypted, long key, int ind) {
	long decrypted = (encrypted ^ ind);
	decrypted = decrypted / key;
	decrypted = decrypted ^ key;
	return char(decrypted);
}



long getLastMDigits(long long num, int n) {
	int total_digits = log10(num) + 1;
	int m = total_digits - n;
	long mod_val = pow(10, m);
	return num % mod_val;
}


char decp(long encryptedp,long encrypted, long key, int ind) {
	encrypted = getLastMDigits(encrypted, key);

	long decrypted = encrypted ^ encryptedp;
	decrypted = decrypted / key;
	decrypted = decrypted ^ key;
	return char(decrypted);
}
void deci() {
	cout << "\nwhat is the length of your ciphertext?: ";
	int leng = 0;
	cin >> leng;
	cout << "what is the key?: ";
	long key = 0;
	cin >> key;

	cout << "\nwhat would you like to decrypt?: ";
	long first;
	cin >> first;
	char prevdec = dec(first, key, 0);
	cout << prevdec;

	for (int i = 1; i < leng; i++) {
		long cur;
		cin >> cur;
		char current = decp(enc(prevdec, key, i), cur, key, i);
		cout << current;
		prevdec = current;
	}
}

void enci() {
	srand(time(0));
	string s;
	cout << "what would you like to encrypt? : ";
	cin.ignore();
	getline(cin, s);
	cout << "what\'s the key?";
	long key = 0;
	cin >> key;

	for (int i = 0; i < s.length(); i++)
	{
		if(i==0)
		cout<<enc(s[i], key, i)<<" ";

		if (i >= 1) {
			for (int j = 0; j < key; j++) {
				cout << rand() % 10;
			}
			cout << encp(s[i - 1], s[i], key, i)<< " ";
		}
		

	}
}


int main()
{
	
	char ch;
	bool leave = false;
	while (!leave) {
		cout << "\nDo you want to Encrypt (1) or Decrypt (2) leave (3): ";
		cin >> ch;
		switch (ch)
		{
		case '1':
			enci();
			break;
		case '2':
			deci();
			break;
		case '3':
			leave = true;
			break;
		default:
			cout << "Invalid input";
			break;
		}
	}
	
	return 0;

}

