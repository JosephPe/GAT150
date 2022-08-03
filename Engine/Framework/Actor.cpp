#include "Actor.h"

namespace anthemum
{
	void anthemum::Actor::Draw(Renderer& renderer)
	{
		m_model.Draw(renderer, m_transform.position, m_transform.rotation, m_transform.scale);
	}
}
