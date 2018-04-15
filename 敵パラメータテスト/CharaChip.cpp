#include "CharaChip.h"

//コンストラクタ
CharaChip::CharaChip() : chipSheetNum(0), animSpd(0.f) {}

//デストラクタ
CharaChip::~CharaChip()
{
	for (auto it : chip)
		delete it;
}

//-----------------------------------------------------------------------------
//キャラチップを作成
void CharaChip::CreateChip(int startPosX, int startPosY, int chipWidth, int chipHeight, int sheet, float spd)
{
	for (int i = 0; i < sheet; ++i)
	{
		chip.emplace_back(new ML::Box2D(startPosX + i * chipWidth, startPosY, chipWidth, chipHeight));
	}
	chipSheetNum = chip.size();

	animSpd = spd;
}