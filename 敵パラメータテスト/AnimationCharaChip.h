#pragma once
#include "MyPG.h"

//�摜�̕������(�L�����`�b�v)��ێ�������
class AnimationCharaChip
{
public:
	ML::Box2D	chip;			//�L�����`�b�v�̃T�C�Y
	int			chipSheetNum;	//�A�j���[�V��������
	float		animSpd;		//�A�j���[�V�������x
	bool		isAnimRoop;		//���[�v���邩�ۂ�(true�Ń��[�v����)

	//�R���X�g���N�^
	AnimationCharaChip(const ML::Box2D& src, const int sheet, const float spd, const bool ir);

	//�f�X�g���N�^
	~AnimationCharaChip();
};