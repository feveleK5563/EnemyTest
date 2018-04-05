#pragma once
#include "MyPG.h"

//----------------------------------------------
//フレーム時間を計測クラス
//----------------------------------------------
class FrameMeasurement
{
public:
	FrameMeasurement();
	~FrameMeasurement();


	//--------------------------/
	//処理
	//--------------------------/
	virtual void	MeasureTime();			//時間を計測
	virtual int		GetNowTime();			//現在の時間を取得
	virtual bool	CheckSpecifiedTime(int time);	//指定時間を調べる
	virtual bool	CheckTimeElaped(int time);		//時間が経過したか調べる
	virtual bool	CheckTimeReach(int time);		//指定した時間に達したか
	virtual void	SetTime(int time);				//時間をセット
	
private:
	int		count;		//ふれーむ時間
};

