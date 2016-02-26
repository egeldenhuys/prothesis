using System;

namespace TargetLifeApplication
{
	[Serializable]
	public struct UserInfo
	{
		public Mbti mbti;

		public Mission mission;

		public Career career;

		public Analysis missionAnalysis;

		public Analysis careerAnalysis;
	}
}
