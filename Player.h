#pragma once
#include"MODEL_BASE.h"

class Player :public MODEL_BASE
{
private:
	float dir;
	float modelspeed;

public:
	Player(int);
	~Player();

	void Init(void);
	void Update(void);
	void Render(void);
};