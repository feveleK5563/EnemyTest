#include "Move.h"


//--------------------------------------
//�R���X�g���N�^
//--------------------------------------
Move::Move() : walkSpeed(0.0f), runSpeed(0.0f), jumpPow(0.0f),fallSpeed(-6.0f),frameCnt(new FrameMeasurement())
{

}

//--------------------------------------
//�f�X�g���N�^
//--------------------------------------
Move::~Move()
{
	delete frameCnt;
}


//-----------------------------------------------------------
//��������
//-----------------------------------------------------------
void	Move::Walk(ML::Vec2& pos,ML::Vec2& dir)
{
	pos += dir * walkSpeed;
}

//-----------------------------------------------------------
//���铮��
//-----------------------------------------------------------
void	Move::Run(ML::Vec2& pos, ML::Vec2& dir)
{
	pos += dir * runSpeed;
}

//-----------------------------------------------------------
//�W�����v���铮��
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

//�p�����[�^�̐ݒ�
void	Move::SetParam(float walk, float run, float& jump, float& fall)
{
	walkSpeed = walk;
	runSpeed = run;
	jumpPow = jump;
	fallSpeed = fall;
}