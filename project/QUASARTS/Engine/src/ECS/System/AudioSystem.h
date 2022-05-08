#pragma once
#include "Core/IManager.h"

#include "System.h"
#include "QuasartsEngine.h"
#include "Audio/AudioDevice.h"
#include "Audio/ClipBuffer.h"
#include "Audio/ClipSource.h"
#include "Audio/TrackSource.h"
#include <string>

namespace Engine {

	class QS_API AudioSystem : public System
	{
		// singleton
	private:
		static AudioSystem* instance;
		AudioSystem() :
			sound_path(""),
			audio_dev(nullptr),
			clip_src(nullptr),
			clip_buffer(nullptr),
			track_src(nullptr),
			cur_work_dir("")
		{}
	public:
		static AudioSystem* Instance();
		~AudioSystem() {};

	public:
		void init();
		int start();
		void update();
		int stop();
		void release();

		// Usage functions //

		//--------------------------
		//clip
		void playSoundClip(const std::string& name);
		void stopClip();
		void pauseClip();
		void resumeClip();
		void playAllClips();
		//--------------------------

		//--------------------------
		//track
		void playTrack(const std::string& name);
		void stopTrack();
		void pauseTrack();
		void resumeTrack();
		//--------------------------

		void getWorkPath(const std::string& path);


	private:
		std::string cur_work_dir;
		std::string sound_path;
		AudioDevice* audio_dev;
		ClipBuffer* clip_buffer;
		ClipSource* clip_src;
		TrackSource* track_src;
	};
}