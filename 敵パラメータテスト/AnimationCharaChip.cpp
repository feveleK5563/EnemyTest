#include "AnimationCharaChip.h"

//�R���X�g���N�^
AnimationCharaChip::AnimationCharaChip(	const ML::Box2D& src,
										const int sheet,
										const float spd,
										const bool ir):
			chip(src), chipSheetNum(sheet), animSpd(spd), isAnimRoop(ir) {}

//�f�X�g���N�^
AnimationCharaChip::~AnimationCharaChip() {}