#pragma once
#include "EnemyMoveSet.h"

//EnemyMoveSet�Ƃ��̑��G�̐����ɕK�v�ƂȂ�G���
class EnemyType
{
public:
	EnemyMoveSet*	emSet;		//����܂Ƃ�

	const string	imageName;	//�摜��
	const int		maxLife;	//�̗͏��
	const int		hitDamage;	//�ڐG���A�v���C���[�ɗ^����_���[�W
	//�ڐG�p�R���W�����̃T�C�Y
	//���E�p�R���W�����̃T�C�Y
	//�U������J�ڗp�R���W�����̃T�C�Y


	//�R���X�g���N�^
	EnemyType(string imgName, int ml, int atk);
	//�f�X�g���N�^
	~EnemyType();
};
