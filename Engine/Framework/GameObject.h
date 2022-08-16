#pragma once

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class);

namespace anthemum 
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual void Update() = 0;
	};
}
