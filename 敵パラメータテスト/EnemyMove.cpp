#include "EnemyMove.h"

//-----------------------------------------------
//�������Ȃ�
void EMove_NoMotion::Move(ML::Vec2& pos)
{
	//�����Ɂu�������Ȃ��v����������
}

//-----------------------------------------------
//�E�ɕ���
void EMove_WalkRight::Move(ML::Vec2& pos)
{
	++pos.x;
}

//-----------------------------------------------
//�W�����v
void EMove_Jump::Move(ML::Vec2& pos)
{
	--pos.y;
}