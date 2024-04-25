#include "RandomNumber.h"

int RandomNumber(int choice) {
	srand(time(NULL)); //Số ngẫu nhiên sẽ thay đổi sau mỗi lần ctr chạy
	int random=0;
	if (choice == 1)
		random = (rand() % (158 + 1 - 1)) + 1;

	if (choice == 2)
		random = (rand() % (456 + 1 - 159)) + 159;

	if (choice == 3)
		random = (rand() % (669 + 1 - 457)) + 457;

	return random;
}