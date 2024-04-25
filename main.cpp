#include "stdafx.h"
#include "FUNCTION.h"
#include "BaseObject.h"
#include "MainObject.h"
#include "Windows.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include "RandomNumber.h"
#include"RandomWord.h"

BaseObject g_background;
vector<bool>so(10, false);
int RandomNumber(int);


bool InitData() {
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0) return false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"1");
	g_window = SDL_CreateWindow("Tro Choi HangMan",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (g_window == NULL) {
		success = false;
	}
	else {
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_window == NULL) success = false;
		else {
			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags)) {
				success = false;
			}
		}
	}
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		success= false;
	}

	// doc file âm thanh

	g_sound_bullet[0] = Mix_LoadWAV("sound//Am-thanh-tra-loi-sai-wav.wav");
	g_sound_bullet[1] = Mix_LoadWAV("sound//nhac-pk-thua-www_tiengdong_com (mp3cut.net).wav");
	g_sound_bullet[2] = Mix_LoadWAV("sound//Right-Answer-sound-effect-tiengdong_com-_mp3cut.net_-_1_.wav");
	g_sound_bullet[3] = Mix_LoadWAV("sound//nhac-pk-win-pk-chien-thang-www_tiengdong_com (mp3cut.net).wav");
	g_sound_bullet[4] = Mix_LoadWAV("sound//menu.wav");




	if (g_sound_bullet[0] == NULL ) {
		success =false;
	}


	return success;
}
// them anh
bool LoadBackground() {
	bool ret = g_background.LoadImg("hinhanh//e8b96056-178a-4620-8430-2b3a9c0880c3.png", g_screen);
	if (ret == false) return false;
	return true;

}




void close() {
	g_background.Free();
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	IMG_Quit();
	SDL_Quit();



}

bool win(vector <int> guessed, int len) {
	for (int i = 0; i < len; i++) {
		if (guessed[i] == -1) {
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[]) {
	int mouseX, mouseY;
	int choice;//nhap vao muc do muon choi vs 1,2,3 tương ung voi de, trung binh, kho
	int live = 6;
	
	char letter; // chu cai nguoi choi doan
	// tao tu ngau nhien
	vector <MainObject> p_object1(26);
	string word;
	int len;
	string guessedLetter; // chu cai da doan
	int length;
	vector<int> guessed;

	if (InitData() == false) return -1;
	if (LoadBackground() == false) return -1;
	bool is_quit = false;
	bool menu = true;
	bool reset = false;
    // ảnh các nút ở menu
	SDL_Surface* number1 = IMG_Load("hinhanh//nut211.png");
	SDL_Texture* textnumber1 = SDL_CreateTextureFromSurface(g_screen, number1);
	SDL_FreeSurface(number1);

	SDL_Surface* number2 = IMG_Load("hinhanh//nut212.png");
	SDL_Texture* textnumber2 = SDL_CreateTextureFromSurface(g_screen, number2);
	SDL_FreeSurface(number2);

	SDL_Surface* number3 = IMG_Load("hinhanh//nut213.png");
	SDL_Texture* textnumber3 = SDL_CreateTextureFromSurface(g_screen, number3);
	SDL_FreeSurface(number3);

	// tọa độ hiển thị nút ở menu
	SDL_Rect b1 = { 0, 0, 80, 80 };
	SDL_Rect b2 = { 100, 0, 80, 80 };
	SDL_Rect b3 = { 200, 0, 80, 80 };

	MainObject p_object01;
	MainObject p_object02;
	MainObject p_object03;
	MainObject p_object04;
	MainObject p_object05;
	MainObject p_object06;
	MainObject p_object07;
	MainObject p_object08;
	MainObject p_object09;
	MainObject p_object10;
	MainObject p_object18;
	MainObject p_object19;
	MainObject p_object11;
	MainObject p_object12;
	MainObject p_object13;
	MainObject p_object14;
	MainObject p_object15;
	MainObject p_object16;
	MainObject p_object17;
	MainObject p_object20;


	// load ảnh
	vector<SDL_Rect> holder;
	bool ret = p_object01.LoadImg("hinhanh//hm1.png", g_screen);
	bool ret02 = p_object02.LoadImg("hinhanh//hm2.png", g_screen);
	bool ret03 = p_object03.LoadImg("hinhanh//hm3.png", g_screen);
	bool ret04 = p_object04.LoadImg("hinhanh//hm4.png", g_screen);
	bool ret05 = p_object05.LoadImg("hinhanh//hm6.png", g_screen);
	bool ret06 = p_object06.LoadImg("hinhanh//hm7.png", g_screen);
	bool ret07 = p_object07.LoadImg("hinhanh//snapedit_1710953551881.png", g_screen);
	bool ret09 = p_object09.LoadImg("hinhanh//hoicham.jpg", g_screen);
	bool ret11 = p_object11.LoadImg("hinhanh//0.png", g_screen);
	bool ret12 = p_object12.LoadImg("hinhanh//1.png", g_screen);
	bool ret13 = p_object13.LoadImg("hinhanh//2.png", g_screen);
	bool ret14 = p_object14.LoadImg("hinhanh//3.png", g_screen);
	bool ret15 = p_object15.LoadImg("hinhanh//4.png", g_screen);
	bool ret16 = p_object16.LoadImg("hinhanh//5.png", g_screen);
	bool ret17 = p_object17.LoadImg("hinhanh//6.png", g_screen);
	bool ret18 = p_object18.LoadImg("hinhanh//youwin1.jpeg", g_screen);
	bool ret19 = p_object19.LoadImg("hinhanh//youlose1.jpeg", g_screen);
	bool ret20 = p_object20.LoadImg("hinhanh//menu.jpeg", g_screen);

	// tọa độ các ảnh
	p_object01.SetRect(290, 205);
	p_object02.SetRect(278, 286);
	p_object03.SetRect(145, 282);
	p_object04.SetRect(395, 282);
	p_object05.SetRect(265, 452);
	p_object06.SetRect(337, 451);
	p_object07.SetRect(240, 50);
	p_object09.SetRect(460, 440);
	p_object11.SetRect(1220, 20);
	p_object12.SetRect(1220, 20);
	p_object13.SetRect(1220, 20);
	p_object14.SetRect(1220, 20);
	p_object15.SetRect(1220, 20);
	p_object16.SetRect(1220, 20);
	p_object17.SetRect(1220, 20);
	p_object18.SetRect(0, 0);
	p_object19.SetRect(0, 0);
	p_object20.SetRect(0, 0);


	if (!ret)return false;

	int thoigian = 0;
	while (!is_quit) {

		so[6] = true;
		if (menu) {
			SDL_RenderClear(g_screen);
			if (Mix_Playing(-1) == 0) {
				Mix_PlayChannel(-1, g_sound_bullet[4], 0);
			}
			p_object20.Render(g_screen, NULL);
			SDL_RenderCopy(g_screen, textnumber1, NULL, &b1);
			SDL_RenderCopy(g_screen, textnumber2, NULL, &b2);
			SDL_RenderCopy(g_screen, textnumber3, NULL, &b3);
			SDL_RenderPresent(g_screen);
		}else if (win(guessed, len)) {
			SDL_RenderClear(g_screen);
			if (Mix_Playing(-1) == 0) {
				Mix_PlayChannel(-1, g_sound_bullet[3], 0);
			}
			thoigian += 1;
			SDL_Rect a = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
			p_object18.Render(g_screen, &a);
			if (thoigian >= 20000) {
				menu = true;
				thoigian = 0;
				Mix_HaltChannel(-1);
			}
		}
		else if (live == 0) {// phat am thanh khi thua
			SDL_RenderClear(g_screen);
			if (Mix_Playing(-1) == 0){
				Mix_PlayChannel(-1, g_sound_bullet[1], 0);
			}
			SDL_Rect a = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
			p_object19.Render(g_screen, &a);
			thoigian += 1;
			if (thoigian >= 20000) {
				menu = true;
				thoigian = 0;
				Mix_HaltChannel(-1);
			}
		}
		while (SDL_PollEvent(&g_event) != 0) {
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
			}
			else if (g_event.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&mouseX, &mouseY);
				if (menu) {
					if (mouseX >= 0 && mouseX <= 80 && mouseY >= 0 && mouseY <= 80)
					{
						Mix_HaltChannel(-1);
						live = 6;
						choice = 1;
						menu = false;
						word = RandomWord(choice);
						len = word.size();
						guessedLetter = ""; // chu cai da doan
						length = guessedLetter.size();
						vector<int> newguessed(len, -1);
						guessed = newguessed;
						vector<bool> newso(10, 0);
						so = newso;
						newguessed.clear();
						newso.clear();
						for (char i = 'a'; i <= 'z'; i++) {
							string path = "hinhanh//";
							path += i;
							path += ".png";
							if (!p_object1[i - 'a'].LoadImg(path, g_screen)) {
								cout << "khong load duoc chu cai " << i << "\n";
							}
							else {
								p_object1[i - 'a'].rect_.w = p_object09.rect_.w;
								p_object1[i - 'a'].rect_.h = p_object09.rect_.h;
							}
						}

						for (int i = 0; i < len; i++) {
							SDL_Rect tmp = { (i % 6) * p_object09.rect_.w + p_object09.rect_.x,(int)(i / 6) * p_object09.rect_.h + p_object09.rect_.y,p_object09.rect_.w,p_object09.rect_.h };
							holder.push_back(tmp);
						}
					} else if (mouseX >= 100 && mouseX <= 180 && mouseY >= 0 && mouseY <= 80)
					{
						Mix_HaltChannel(-1);
						live = 6;
						choice = 2;
						menu = false;
						word = RandomWord(choice);
						len = word.size();
						guessedLetter = ""; // chu cai da doan
						length = guessedLetter.size();
						vector<int> newguessed(len, -1);
						guessed = newguessed;
						vector<bool> newso(10, 0);
						so = newso;
						newguessed.clear();
						newso.clear();
						for (char i = 'a'; i <= 'z'; i++) {
							string path = "hinhanh//";
							path += i;
							path += ".png";
							if (!p_object1[i - 'a'].LoadImg(path, g_screen)) {
								cout << "khong load duoc chu cai " << i << "\n";
							}
							else {
								p_object1[i - 'a'].rect_.w = p_object09.rect_.w;
								p_object1[i - 'a'].rect_.h = p_object09.rect_.h;
							}
						}

						for (int i = 0; i < len; i++) {
							SDL_Rect tmp = { (i % 6) * p_object09.rect_.w + p_object09.rect_.x,(int)(i / 6) * p_object09.rect_.h + p_object09.rect_.y,p_object09.rect_.w,p_object09.rect_.h };
							holder.push_back(tmp);
						}
					} else if (mouseX >= 200 && mouseX <= 280 && mouseY >= 0 && mouseY <= 80)
					{
						Mix_HaltChannel(-1);
						live = 6;
						choice = 3;
						menu = false;
						word = RandomWord(choice);
						len = word.size();
						guessedLetter = ""; // chu cai da doan
						length = guessedLetter.size();
						vector<int> newguessed(len, -1);
						guessed = newguessed;
						vector<bool> newso(10, 0);
						so = newso;
						newguessed.clear();
						newso.clear();
						for (char i = 'a'; i <= 'z'; i++) {
							string path = "hinhanh//";
							path += i;
							path += ".png";
							if (!p_object1[i - 'a'].LoadImg(path, g_screen)) {
								cout << "khong load duoc chu cai " << i << "\n";
							}
							else {
								p_object1[i - 'a'].rect_.w = p_object09.rect_.w;
								p_object1[i - 'a'].rect_.h = p_object09.rect_.h;
							}
						}
						for (int i = 0; i < len; i++) {
							SDL_Rect tmp = { (i % 6) * p_object09.rect_.w + p_object09.rect_.x,(int)(i / 6) * p_object09.rect_.h + p_object09.rect_.y,p_object09.rect_.w,p_object09.rect_.h };
							holder.push_back(tmp);
						}
					}
				}
			} else if (g_event.type == SDL_KEYDOWN) {
				// Sự kiện phím được nhấn
				string keyName = SDL_GetKeyName(g_event.key.keysym.sym);
				letter = keyName[0]; // chuyen in hoa sang in thuong
				letter = tolower(letter);
				if (word.find(letter) == -1) {
					live--;
					Mix_PlayChannel(-1, g_sound_bullet[0], 0);
					so[live] = true;
				}
				else {
					int tmp = letter - 'a';
					for (int i = 0; i < len; i++) {
						if (word[i] == letter) {
							guessed[i] = tmp;
							guessedLetter += letter;
							Mix_PlayChannel(-1, g_sound_bullet[2], 0);
						}
					}
					continue;
				}
			}
			if (!menu) {
				cout << word << " " << choice << endl;
				SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
				g_background.Render(g_screen, NULL);
				p_object07.Render(g_screen, NULL);
				p_object10.Render(g_screen, NULL);
				// in ra cac tu da doan
				for (int i = 0; i < len; i++) {
					if (guessed[i] == -1) {
						p_object09.rect_.x = holder[i].x;
						p_object09.rect_.y = holder[i].y;
						p_object09.Render(g_screen, NULL);
					}
					else {
						p_object1[guessed[i]].rect_.x = holder[i].x;
						p_object1[guessed[i]].rect_.y = holder[i].y;
						p_object1[guessed[i]].Render(g_screen, NULL);
					}

				}
				p_object09.SetRect(460, 440);

				// in ra so mang song con lai
				for (int i = 0; i < so.size(); i++) {
					if (so[i]) {
						switch (i) {
						case 0:
							p_object11.Render(g_screen, NULL);
							break;
						case 1:
							p_object12.Render(g_screen, NULL);
							break;
						case 2:
							p_object13.Render(g_screen, NULL);
							break;
						case 3:
							p_object14.Render(g_screen, NULL);
							break;
						case 4:
							p_object15.Render(g_screen, NULL);
							break;
						case 5:
							p_object16.Render(g_screen, NULL);
							break;
						case 6:
							p_object17.Render(g_screen, NULL);
							break;
						default:
							break;
						}
						break;
					}
				}
				// in ra bo phan
				for (int i = 0; i < so.size(); ++i) {
					if (so[i]) {
						switch (i) {
						case 0:
							p_object06.Render(g_screen, NULL);
							break;
						case 1:
							p_object05.Render(g_screen, NULL);
							break;
						case 2:
							p_object04.Render(g_screen, NULL);
							break;
						case 3:
							p_object03.Render(g_screen, NULL);
							break;
						case 4:
							p_object02.Render(g_screen, NULL);
							break;
						case 5:
							p_object01.Render(g_screen, NULL);
							break;
						default:
							break;
						}
					}
				}
			}
		}
		SDL_RenderPresent(g_screen);
	}

	close();
	SDL_DestroyTexture(textnumber1);
	SDL_DestroyTexture(textnumber2);
	SDL_DestroyTexture(textnumber3);

	return 0;
}
