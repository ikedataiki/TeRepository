#pragma once

class Stage
{
private:
	int stageModel;
public:
	Stage(int);
	~Stage();
	void Update(void);
	void Render(void);

};
