#include "EnemyMove.h"

//-----------------------------------------------
//âΩÇ‡ÇµÇ»Ç¢
void EMove_NoMotion::Move(ML::Vec2& moveVec)
{
	//Ç±Ç±Ç…ÅuâΩÇ‡ÇµÇ»Ç¢ÅvèàóùÇèëÇ≠
}

//-----------------------------------------------
//âEÇ…ï‡Ç≠
void EMove_WalkRight::Move(ML::Vec2& moveVec)
{
	++moveVec.x;
}

//-----------------------------------------------
//è„Ç…à⁄ìÆÇ∑ÇÈ
void EMove_Up::Move(ML::Vec2& moveVec)
{
	--moveVec.y;
}

//-----------------------------------------------
//â∫Ç…à⁄ìÆÇ∑ÇÈ
void EMove_Down::Move(ML::Vec2& moveVec)
{
	++moveVec.y;
}