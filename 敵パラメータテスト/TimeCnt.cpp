#include "TimeCnt.h"

//------------------------------
//コンストラクタ
//------------------------------
FrameMeasurement::FrameMeasurement() : count(0)
{

}

//------------------------------
//デストラクタ
//------------------------------
FrameMeasurement::~FrameMeasurement()
{

}


//---------------------------------------------------------
//フレーム時間を計測する
//---------------------------------------------------------
void	FrameMeasurement::MeasureTime()
{
	count++;
}

//---------------------------------------------------------
//現在のフレーム時間を返す
//---------------------------------------------------------
int		FrameMeasurement::GetNowTime()
{
	return count;
}

//---------------------------------------------------------
//指定フレーム時間かを調べる
//---------------------------------------------------------
bool	FrameMeasurement::CheckSpecifiedTime(int time)
{
	if (count == time) { return true; }
	return false;
}

//--------------------------------------------------------
//時間が経過したかを調べる
//--------------------------------------------------------
bool	FrameMeasurement::CheckTimeElaped(int time)
{
	if (count > time) { return true; }
	return false;
}

bool	FrameMeasurement::CheckTimeReach(int time)
{
	if (count <= time) { return true; }
	return false;
}

//---------------------------------------------------------
//フレーム時間をセットする
//---------------------------------------------------------
void	FrameMeasurement::SetTime(int time)
{
	count = time;
}