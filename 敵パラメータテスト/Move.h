#pragma once
#include "MyPG.h"
#include "TimeCnt.h"


//----------------------------------------
//������񋟂���N���X
//----------------------------------------
class Move
{
public:
	Move();
	~Move();

	//-------------------------/
	//����
	//-------------------------/
	void	Walk(ML::Vec2& pos,ML::Vec2& dir);
	void	Run(ML::Vec2& pos, ML::Vec2& dir);
	void	Jump(ML::Vec2& pos);	

	void	SetParam(float walk,float run,float& jump,float& fall);
	void	SetJumpPow(float jumpPow);
	void	SetFallSpeed(float& fall);

private:
	FrameMeasurement*	frameCnt;
	float	walkSpeed;
	float	runSpeed;
	float	jumpPow;
	float	fallSpeed;
};

