#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <windows.h>
#include <stdlib.h>
using namespace std;
int main() {
	int live = 7;                      //Số lần còn lại có thể sai
	int choice;                       // chọn mức độ khó
	int num;
	string letter;                   //chữ cái người chơi đoán
	string word;                    // Từ cần đoán
	string guessedLetter;//Chữ cái đã đoán
	cin >> choice;
	while (choice < 1 || choice>3) {
		system("cls");              // Xoa man hinh
		cin >> choice;
	}



}

//RandomNumber là hàm sinh số ngẫu nhiên dựa trên đầu vào là mức độ trò chơi choice. random trả về sẽ được sdung để chọn 1 từ trong ds từ vựng
int RandomNumber(int choice) {
	srand(time(NULL)); //Số ngẫu nhiên sẽ thay đổi sau mỗi lần ctr chạy
	int random;
	if (choice == 1)
		random = (rand() % (158 + 1 - 1)) + 1;

	if (choice == 2)
		random = (rand() % (456 + 1 - 159)) + 159;

	if (choice == 3)
		random = (rand() % (669 + 1 - 457)) + 457;

	return random;
}