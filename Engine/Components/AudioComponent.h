#pragma once
#include "Framework/Component.h"
#include "Engine.h"

namespace anthemum
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent();
		
		void Update() override;
		void Play();
		void Stop();

	public:
		std::string m_soundName;
		bool PlayOnAwake;
		float volume = 1;
		float m_pitch = 1;
		bool loop = false;
	};
}