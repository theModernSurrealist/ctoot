#include <audio/dynamics/izcompressor/ChannelControl.hpp>

using namespace ctoot::audio::dynamics::izcompressor;
using namespace ctoot::control;
using namespace std;

ChannelControl::ChannelControl(int32_t id, std::string name)
	: EnumControl(id, name, string("LR"))
{
}

ChannelControl::~ChannelControl() {
}

vector<boost::any> ChannelControl::getValues() {
	vector<boost::any> res{ string("M"), string("S"), string("L"), string("R"), string("LR") };
	return res;
}
