#include "Move.h"


//--------------------------------------
//コンストラクタ
//--------------------------------------
Move::Move() : walkSpeed(0.0f), runSpeed(0.0f), jumpPow(0.0f),fallSpeed(-6.0f),frameCnt(new FrameMeasurement())
{

}

//--------------------------------------
//デストラクタ
//--------------------------------------
Move::~Move()
{
	delete frameCnt;
}


//-----------------------------------------------------------
//歩く動き
//-----------------------------------------------------------
void	Move::Walk(ML::Vec2& pos,ML::Vec2& dir)
{
	pos += dir * walkSpeed;
}

//-----------------------------------------------------------
//走る動き
//-----------------------------------------------------------
void	Move::Run(ML::Vec2& pos, ML::Vec2& dir)
{
	pos += dir * runSpeed;
}

//-----------------------------------------------------------
//ジャンプする動き
//-----------------------------------------------------------
void	Move::Jump(ML::Vec2& pos)
{
	pos.y += fallSpeed;
}

void	Move::SetJumpPow(float jumpPow)
{
	fallSpeed = jumpPow;
}

void	Move::SetFallSpeed(float& fall)
{
	fallSpeed = fall;
}

//パラメータの設定
void	Move::SetParam(float walk, float run, float& jump, float& fall)
{
	walkSpeed = walk;
	runSpeed = run;
	jumpPow = jump;
	fallSpeed = fall;
}