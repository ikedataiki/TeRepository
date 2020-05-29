#pragma once

class Collsion
{
public:
	Collsion(){}
	~Collsion(){}

	//‹…‚Æ‹…‚Ì“–‚½‚è”»’è
	//sPos,bPos:”»’è‹…‚Ì’†SÀ•W
	//aR,bR:”»’è‹…‚Ì”¼Œa
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
