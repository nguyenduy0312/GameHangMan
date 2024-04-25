#include"RandomNumber.h"
#include"RandomWord.h"

string RandomWord(int choice) {
	string word;
	int tmp = 1;
	int number = RandomNumber(choice);
	ifstream file("danhsachtuvung.txt");
	string tuvung;
	while (getline(file, tuvung)) {
		if (tmp == number) {
			word = tuvung;
		}
		tmp++;
	}
	return word;
}