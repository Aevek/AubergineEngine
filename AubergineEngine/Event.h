#pragma once
namespace AubergineEngine
{
	namespace Events
	{
		struct Awake
		{

		};

		struct LogicUpdate
		{
			LogicUpdate(double deltaTime, double timeScale = 1) : DeltaTime(deltaTime), TimeScale(timeScale) {};
			double DeltaTime;
			double TimeScale;
		};
	}
}