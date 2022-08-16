#pragma once
#include "Framework/Component.h"


namespace anthemum
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent();


		void Update() override;
	};
}