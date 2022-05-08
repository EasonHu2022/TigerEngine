#pragma once
#include <AL/al.h>
#include <glm/glm.hpp>
#include "Core/Core.h"

namespace Engine {

	class QS_API ClipSource
	{
	public:
		ClipSource();
		~ClipSource();
	
		void play(const ALuint buffer);
		bool isPlaying();
		void stop();
		void pause();
		void resume();
		void isLooping();

	
	private:
		ALuint source;
		ALuint buffers = 0;
		bool is_paused = false;
		bool is_looping = true;
		//TODO 3D sound 
		//float pitch = 1.f;
		//float gain = 1.f;
		//glm::vec3 position = { 0,0,0 };
		//glm::vec3	velocity = { 0,0,0 };
		//bool  loopSound = false;
	};
}

