#include "EnemyMove.h"

//-----------------------------------------------
//�������Ȃ�
void EMove_NoMotion::Move(ML::Vec2& moveVec)
{
	//�����Ɂu�������Ȃ��v����������
}

//-----------------------------------------------
//�E�ɕ���
void EMove_WalkRight::Move(ML::Vec2& moveVec)
{
	++moveVec.x;
}

//-----------------------------------------------
//��Ɉړ�����
void EMove_Up::Move(ML::Vec2& moveVec)
{
	--moveVec.y;
}

//-----------------------------------------------
//���Ɉړ�����
void EMove_Down::Move(ML::Vec2& moveVec)
{
	++moveVec.y;
}