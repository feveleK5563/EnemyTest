#pragma once
#include "EnemyMoveManager.h"

class EnemyData
{
public:
	ML::Vec2			pos;			//���W
	EnemyMoveManager	emm;			//����̊Ǘ�
	ML::Box2D			hitBase;		//��_���[�W�����蔻��
	ML::Box2D			atkBase;		//�^�_���[�W�����蔻��
	ML::Box2D			eyesightBase;	//���E�p�����蔻��

	enum Angle { Left, Right };			//�����J��
	Angle angle;

	EnemyData();
	~EnemyData();
};