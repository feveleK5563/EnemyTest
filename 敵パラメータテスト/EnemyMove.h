#pragma once
#include "MyPG.h"

//“®ì‚ÌŠî’êƒNƒ‰ƒX
class EnemyMove
{
public:
	virtual void Move(ML::Vec2& moveVec) = 0;
};

//-----------------------------------------------
//‰½‚à‚µ‚È‚¢
class EMove_NoMotion : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//‰E‚ÉˆÚ“®‚·‚é
class EMove_WalkRight : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//ã‚ÉˆÚ“®‚·‚é
class EMove_Up : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};

//-----------------------------------------------
//‰º‚ÉˆÚ“®‚·‚é
class EMove_Down : public EnemyMove
{
public:
	void Move(ML::Vec2& moveVec);
};