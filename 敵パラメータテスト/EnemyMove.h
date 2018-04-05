#pragma once
#include "MyPG.h"

//“®ì‚ÌŠî’êƒNƒ‰ƒX
class EnemyMove
{
public:
	virtual void Move(ML::Vec2& pos) = 0;
};

//-----------------------------------------------
//‰½‚à‚µ‚È‚¢
class EMove_NoMotion : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//‰E‚ÉˆÚ“®‚·‚é
class EMove_WalkRight : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//ã‚ÉˆÚ“®‚·‚é
class EMove_Up : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};

//-----------------------------------------------
//‰º‚ÉˆÚ“®‚·‚é
class EMove_Down : public EnemyMove
{
public:
	void Move(ML::Vec2& pos);
};