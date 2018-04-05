#pragma once
#include "MyPG.h"
#include "TimeCnt.h"
#include "Move.h"

//-----------------------------------------
//�G�̃N���X
//-----------------------------------------
class Enemy
{
public:
	Enemy();
	~Enemy();

	//��{����
	void	Initialize();
	void	Finalize();
	void	UpDate();
	void	Render();


private:
	//���̑��̃p�����[�^
	const int	Frame = 60;	//60�t���[��

	float	jumpPow = -9.0f;
	float	fallSpeed = 0.0f;
	float	oneFlag = false;

private:
	int	  life;				//���C�t
	int	  attackPoint;		//�U����
	ML::Vec2  pos;			//�ʒu���W
	ML::Vec2  dir;			//����(����)
	int	  movePatternNum;	//����p�^�[���̐�
	ML::Box2D hitBox;		//�����蔻��(���͓����蔻��̏��͂���Ȃ�)
	int	  texNum;			//�摜�̔ԍ�
	int	  animSpeed;		//�A�j���[�V�������x
	int	  animNum;			//�A�j���[�V������

	Move*	  move;			//�ړ�������N���X
	FrameMeasurement*  frameCnt;	//���Ԍv��
};

