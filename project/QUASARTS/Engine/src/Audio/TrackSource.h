#pragma once
#include <AL/al.h>
#include <sndfile.h>
#include "Core/Core.h"

namespace Engine {

	class QS_API TrackSource
	{
	public:	
		TrackSource();
		~TrackSource();

		void loadTrack(const char* file_name);
		void play();
		bool isPlaying();
		void stop();
		void pause();
		void resume();
		void isLooping();	
		void updateBuffer();
	
	private:

		//track source
		ALuint source;
		ALuint buffers[4];

		//track buffer
		SNDFILE* sndfile = nullptr;
		short* buf = nullptr;
		SF_INFO sf_info;
		ALenum format;

		bool is_paused = false;
		bool is_looping = true;
	};
}

