#pragma once
#include "EnemyType.h"
#include "EnemyController.h"

//�ȉ���include��GameObject�ő�ւ���
#include "ImageManager.h"

class Enemy
{
public:
	//����Ǘ�����
	EnemyController* eController;

	//�ȉ��̃����o�ϐ���GameObject��Move�N���X�Ƃ��������Ă���̂��Ǝv��
	int				life;
	ML::Vec2		pos;
	ML::Vec2		moveVec;
	ImageManager*	imgManager;

	//�R���X�g���N�^
	Enemy();
	//�f�X�g���N�^
	~Enemy();

	//�G����ݒ�
	void SetEnemyType(EnemyType* cpyet, ML::Vec2 setPos);

	//�X�V
	void Update();

	//�`��
	void Render();
};