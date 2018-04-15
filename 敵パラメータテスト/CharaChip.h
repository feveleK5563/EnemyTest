#pragma once
#include "MyPG.h"

//画像の分割情報(キャラチップ)を保持するやつ
class CharaChip
{
public:
	vector<ML::Box2D*>	chip;
	int					chipSheetNum;
	float				animSpd;

	//コンストラクタ
	CharaChip();

	//デストラクタ
	~CharaChip();

	//----------------------------------------------
	//アニメーション用チップを作成
	//引数：左上の座標(int, int), チップの横幅(int), チップの縦幅(int), アニメーション枚数(int)
	void CreateChip(int startPosX, int startPosY, int chipWidth, int chipHeight, int sheet, float spd);
};