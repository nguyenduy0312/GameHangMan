#include"Function.h"
#include"Design.h"
#include"RandumNumber.h"
#include"RandomWord.h"

bool win = false;
string RandomWord(int);
int RandomNumber(int);
void Design(int);
void PrinWord(string word, string letter);



int main() {
	int live = 7;                      //Số lần còn lại có thể sai
	int choice;                       // chọn mức độ khó
	int num;
	string letter;                   //chữ cái người chơi đoán
	string word;                    // Từ cần đoán
	string guessedLetter;           //Chữ cái đã đoán
	cout << "Nhap vao muc do ban muon choi (do kho tang dan tu 1--->3): ";
	cin >> choice;
	while (choice < 1 || choice>3) {
		system("cls");              // Xoa man hinh
		cout << "Muc do choi khong hop le, hay nhap lai: ";
		cin >> choice;
	}
	word = RandomWord(choice);
	system("cls");
	bool help = false;
	while (live > 0) {
		win = true;
		Design(live);
		PrinWord(word, guessedLetter);
		if (help) {
			help = false;
			win = false;
		}
		if (win == true) {
			break;
		}

		cout << endl;
		cout << "Neu can tro giup hay nhap 'help', luu y se bi tru 1 mang!!!" << endl;
		cout << "Chu cai da nhap la: " << guessedLetter << endl;
		cout << "Hay nhap vao 1 chu cai ban doan: ";
		cin >> letter;
		int x = 0;
		for (int i = 0; i < letter.length(); i++) {
			x++;
		}
		if (x >= 2) {
			if (letter == "help") {
				live--;
				help = true;
				cout << "Chu cai goi y: " << word[0];
				letter = word[0];
				system("pause");
			}
			else {
				system("cls");
				cout << "Luu y chi duoc nhap 1 chu cai duy nhat";
			}
		}
		guessedLetter += letter[0];
		if (word.find(letter) != -1 || help) {
			system("cls");
			continue;
		}
		else {
			live--;
			system("cls");
		}
	}
	if (live == 0) {
		system("cls");
		cout << "Ban da thua cuoc" << endl;
		cout << "Tu can doan: " << word;
		system("pause");
	}
	if (live > 0) {
		system("cls");
		cout << "Ban da thang" << endl;
		cout << "Tu can doan: " << word;
		system("pause");
	}
	return 0;
}
//PrinWord là hàm in ra chữ cái người chơi đoán
void PrinWord(string word, string letter) {
	for (int i = 0; i < word.size(); i++) {
		if (letter.find(word[i]) != -1) {
			cout << word[i] << " ";
		}
		else {
			cout << "*";
			win = false;
		}
	}
}
