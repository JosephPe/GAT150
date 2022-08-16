#pragma once
#include "Framework/Component.h"

namespace anthemum
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;
	};
}