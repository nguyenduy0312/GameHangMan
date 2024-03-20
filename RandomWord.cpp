#include"RandomWord.h"
#include"RandumNumber.h"


string RandomWord(int choice) {
	int cnt = 1;
	string word;
	int number = RandumNumber(choice); // Sinh số ngẫu nhiên
	string tuvung;
	ifstream file("danhsachtuvung.txt"); // mở file chứa từ vựng
	while (getline(file, tuvung)) {      //đọc 1 dòng trong file và lưu vào tuvung
		if (number == cnt) {
			word = tuvung;
			break;
		}
		cnt++;
	}
	return word;
}