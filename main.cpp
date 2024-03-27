#include "stdafx.h"
#include "FUNCTION.h"
#include "BaseObject.h"
#include "MainObject.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
BaseObject g_background;
vector<bool>so(10, false);


bool InitData() {
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0) return false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
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


int main(int argc, char* argv[]) {




	if (InitData() == false) return -1;
	if (LoadBackground() == false) return -1;

	bool is_quit = false;

	MainObject p_object01;
	MainObject p_object02;
	MainObject p_object03;
	MainObject p_object04;
	MainObject p_object05;
	MainObject p_object06;
	MainObject p_object07;

	bool ret = p_object01.LoadImg("hinhanh//hm1.png", g_screen);
	bool ret02 = p_object02.LoadImg("hinhanh//hm2.png", g_screen);
	bool ret03 = p_object03.LoadImg("hinhanh//hm3.png", g_screen);
	bool ret04 = p_object04.LoadImg("hinhanh//hm4.png", g_screen);
	bool ret05 = p_object05.LoadImg("hinhanh//hm6.png", g_screen);
	bool ret06 = p_object06.LoadImg("hinhanh//hm7.png", g_screen);
	bool ret07 = p_object07.LoadImg("hinhanh//snapedit_1710953551881.png", g_screen);

	p_object01.SetRect(290, 205);
	p_object02.SetRect(278, 286);
	p_object03.SetRect(145, 282);
	p_object04.SetRect(395, 282);
	p_object05.SetRect(265, 452);
	p_object06.SetRect(337, 451);
	p_object07.SetRect(240, 50);
	int live = 7;

	if (!ret)return false;
	
    string s = "HANGMAN";
	
	while (!is_quit) {
		while (SDL_PollEvent(&g_event) != 0) {
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
			}
			else if (g_event.type == SDL_MOUSEBUTTONDOWN) {
				// Lấy vị trí của con trỏ chuột
				int mouseX = g_event.motion.x;
				int mouseY = g_event.motion.y;
				SDL_Log("Vị trí con trỏ chuột: (%d, %d)", mouseX, mouseY);
			}
			else if (g_event.type == SDL_KEYDOWN) { // Sự kiện phím được nhấn
				string keyName = SDL_GetKeyName(g_event.key.keysym.sym);
				cout << "Người dùng đã nhấn phím: " << keyName << endl ;
				if (s.find(keyName) == -1) {
					live--;
					so[live] = true;
				}
				else {
					continue;
				}
				cout << live<<endl;
			}

			SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
			SDL_RenderClear(g_screen);
			g_background.Render(g_screen, NULL);
			p_object07.Render(g_screen, NULL);
			for (int i = 1; i < so.size(); ++i) {
				if (so[i]) {
					switch (i) {
					case 1:
						p_object06.Render(g_screen, NULL);
						break;
					case 2:
						p_object05.Render(g_screen, NULL);
						break;
					case 3:
						p_object04.Render(g_screen, NULL);
						break;
					case 4:
						p_object03.Render(g_screen, NULL);
						break;
					case 5:
						p_object02.Render(g_screen, NULL);
						break;
					case 6:
						p_object01.Render(g_screen, NULL);
						break;
					default:
						break;
					}
				}
			}
			
			SDL_RenderPresent(g_screen);
		}
	}

	close();
	




	return 0;
}