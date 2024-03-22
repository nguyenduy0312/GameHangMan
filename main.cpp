#include "stdafx.h"
#include "FUNCTION.h"
#include "BaseObject.h"
#include "MainObject.h"
#include <iostream>

BaseObject g_background;


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

	p_object01.SetRect(285, 195);
	p_object02.SetRect(278, 286);
	p_object03.SetRect(145, 282);
	p_object04.SetRect(395, 282);
	p_object05.SetRect(265, 452);
	p_object06.SetRect(337, 451);
	p_object07.SetRect(240, 50);

	if (!ret)return false;

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
		}
		SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
		SDL_RenderClear(g_screen);
		g_background.Render(g_screen, NULL);
		p_object01.Render(g_screen, NULL);
		p_object02.Render(g_screen, NULL);
		p_object03.Render(g_screen, NULL);
		p_object04.Render(g_screen, NULL);
		p_object05.Render(g_screen, NULL);
		p_object06.Render(g_screen, NULL);
		p_object07.Render(g_screen, NULL);




		SDL_RenderPresent(g_screen);

	}

	close();





	return 0;
}