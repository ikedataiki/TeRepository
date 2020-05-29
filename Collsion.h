#pragma once

class Collsion
{
public:
	Collsion(){}
	~Collsion(){}

	//���Ƌ��̓����蔻��
	//sPos,bPos:���苅�̒��S���W
	//aR,bR:���苅�̔��a
	bool SphereVsSphere(VECTOR aPos, float aR, VECTOR bPos, float bR)
	{
		float x = aPos.x - bPos.x;
		float y = aPos.y - bPos.y;
		float z = aPos.z - bPos.z;
		float r = aR + bR;

		if (x*x + y * y + z * z < r*r)
		{
			return true;
		}
		return false;
	}
};
