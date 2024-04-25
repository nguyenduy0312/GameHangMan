#pragma once
#ifndef BASEOBJECT_H_
#define BASEOBJECT_H_

#include "FUNCTION.h"

class BaseObject {
	// chu y khai bao public de duoc truy cap tu ben ngoai
public:
	BaseObject();
	~BaseObject();

	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }		// set vị trí

	SDL_Rect GetRect() const { return rect_; }		// lấy vị trí

	SDL_Texture* GetObject() const { return p_object_; }	// lấy đối tượng

	bool LoadImg(std::string path, SDL_Renderer* screen);	// load ảnh

	void Render(SDL_Renderer* des, const SDL_Rect* clip /*=NULL*/);		// in ra ảnh
	void Free();

	SDL_Texture* p_object_;
	SDL_Rect rect_;
};





#endif
