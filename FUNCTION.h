#pragma once
#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "ctime"
#include"fstream"
#include <cctype>
#include <SDL_mixer.h>
//#include <SDL_ttf.h>
using namespace std;
static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;
// AM THANH 
static Mix_Chunk* g_sound_bullet[5];
static Mix_Chunk* g_sound_exp[2];

// MAN HINH
const int SCREEN_WIDTH = 1300;
const int SCREEN_HEIGHT = 700;
const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;
const int RENDER_DRAW_COLOR = 0Xff;
#endif
