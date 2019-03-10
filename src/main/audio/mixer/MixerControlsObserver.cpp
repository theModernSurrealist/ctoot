#include <audio/mixer/MixerControlsObserver.hpp>
#include <audio/mixer/Mutation.hpp>
#include <audio/mixer/AudioMixer.hpp>

using namespace ctoot::audio::mixer;

MixerControlsObserver::MixerControlsObserver(AudioMixer* am)
{
	this->am = am;
}

void MixerControlsObserver::update(std::any a)
{
	Mutation* m = nullptr;
	try {
		m = std::any_cast<Mutation*>(a);
	}
	catch (const std::bad_any_cast& e) {
		//printf(e.what());
		return;
	}
	if (m != nullptr) {
		if (am->isEnabled() && am->getAudioServer().lock()->isRunning()) {
			am->getMutationQueue().try_enqueue(m);
		}
		else {
			am->processMutation(m);
		}
	}
}
