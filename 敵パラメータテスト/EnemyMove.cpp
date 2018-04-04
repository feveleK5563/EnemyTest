#include "EnemyMove.h"

//-----------------------------------------------
//何もしない
void EMove_NoMotion::Move(ML::Vec2& pos)
{
	//ここに「何もしない」処理を書く
}

//-----------------------------------------------
//右に歩く
void EMove_WalkRight::Move(ML::Vec2& pos)
{
	++pos.x;
}

//-----------------------------------------------
//上に移動する
void EMove_Up::Move(ML::Vec2& pos)
{
	--pos.y;
}

//-----------------------------------------------
//下に移動する
void EMove_Down::Move(ML::Vec2& pos)
{
	++pos.y;
}