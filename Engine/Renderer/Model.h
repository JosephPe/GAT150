#pragma once
#include "Renderer.h"
#include <vector>
#include <string>

namespace anthemum
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<anthemum::Vector2>& points, const anthemum::Color& color) : 
			m_points{ points },
			m_color{ color }
		{
			//std::vector<int> ints;
			//std::vector<int> cints;
		}
		Model(const std::string& filename);

		void Draw(Renderer& renderer, const Vector2 position, float angle, float scale = 1);

		void Load(const std::string& filename);
		float CalculateRadius();

		float GetRadius() { return m_radius; }
	private:
		anthemum::Color m_color;
		std::vector<anthemum::Vector2> m_points;

		float m_radius = 0;
	};
}