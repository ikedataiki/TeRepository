#pragma once

class AttackSword
{
private:

public:
	AttackSword();
	~AttackSword();


	void Init(void);
	void Update(void);
	void Render(void);

	bool RodVsSphere(VECTOR rodPosA, VECTOR rodPosB, float spherePos, float sphereR);
};
