#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"
#include "Texture.h"
#include "Math/Rect.h"
#include "Math/Matrix3_3.h"

struct SDL_Renderer;
struct SDL_Window;

namespace anthemum
{
	class Texture;
	struct Transform;
	struct Rect;

	class Renderer
	{
	public:
		Renderer() = default;
		~Renderer() = default;


		void Initialize();
		void Shutdown();

		void CreateWindow(const char* name, int width, int height);
		void BeginFrame();
		void EndFrame();
		void SetClearColor(const Color& color) { m_clearColor = color; }

		void Draw(std::shared_ptr<Texture> texture, const Vector2& position, float angle = 0, const Vector2& scale = Vector2{ 1, 1 }, const Vector2& registration = Vector2{ 0.5f, 0.5f});
		void Draw(std::shared_ptr<Texture> texture, const Transform& transform, const Vector2& registration = Vector2{ 0.5f, 0.5f });
		void Draw(std::shared_ptr<Texture> texture, const Rect& source,const Transform& transform, const Vector2& registration = Vector2{ 0.5f, 0.5f }, bool flipH = false);
		
		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawLine(const Vector2& v1, const Vector2& v2, const Color& color);
		void DrawPoint(float x, float y);
		void DrawPoint(const Vector2& v, const Color& color);

		void SetViewMatrix(const Matrix3_3 view) { m_view = view; }
		void SetViewportMatrix(const Matrix3_3& viewport) { m_viewport = viewport; }

		int GetWidth() { return m_width; }
		int GetHeight() { return m_height;}

		Renderer* g_renderer = nullptr;

		auto* GetRenderer(){return m_renderer;}

		friend class Texture;
		friend class Text;
	private:
		Matrix3_3 m_view;
		Matrix3_3 m_viewport;

		int m_width = 0;
		int m_height = 0;

		Color m_clearColor{ 0, 0, 0, 255 };

		SDL_Renderer* m_renderer = nullptr;
		SDL_Window* m_window = nullptr;
	};
}