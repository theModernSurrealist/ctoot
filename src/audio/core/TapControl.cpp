#include <audio/core/TapControl.hpp>

#include <audio/basic/tap/TapControls.hpp>
#include <audio/core/AudioBuffer.hpp>
#include <audio/core/Taps.hpp>

#include <lang/StrUtil.hpp>

using namespace ctoot::audio::core;
using namespace ctoot::control;
using namespace std;

string TapControl::SELF_STR = "Self";

void TapControl::init()
{
	prevTapName = SELF_STR;
}

constexpr int32_t TapControl::SELF_VAL;

TapControl::TapControl(int32_t id, std::string name)
	: EnumControl(id, name, SELF_STR)
{
	init();
}

ctoot::audio::core::AudioBuffer* TapControl::getBuffer()
{
	return buffer;
}

void TapControl::remove()
{
	reference(boost::any_cast<string>(getValue()), -1);
}

void TapControl::derive(ctoot::control::Control* obj)
{
	auto tapName = boost::any_cast<string>(getValue());
	reference(prevTapName, -1);
	reference(tapName, 1);
	prevTapName = tapName;
	if (tapName.compare(SELF_STR) == 0) {
		buffer = nullptr;
		return;
	}
	buffer = Taps::getBuffer(tapName);
	if (buffer == nullptr) {
		string errormsg = "Taps returned null buffer for Tap " + tapName;
		printf(errormsg.c_str());
	}
}

void TapControl::reference(string name, int32_t ref)
{
	if (name.compare(SELF_STR) == 0)
		return;

	auto c = Taps::getControls(name);
	if (c != nullptr) {
		c->reference(ref);
	}
	else {
		string errormsg = "Taps couldn't find Tap " + name;
		printf(errormsg.c_str());
	}
}

std::vector<boost::any> TapControl::getValues()
{
	auto values = std::vector<boost::any>();
	values.push_back(SELF_STR);
	for (auto& t : Taps::taps) {
		values.push_back(Taps::tapName(t));
	}
	return values;
}

void TapControl::setIntValue(int32_t value)
{
	if (value == SELF_VAL) {
		setValue(SELF_STR);
		return;
	}
	auto instance = value & int32_t(7);
	auto strip = value >> int32_t(3);
	auto name = to_string(strip + 1);
	if (instance > 0)
		name = name + "#" + to_string(instance + 1);

	setValue(name);
}

int32_t TapControl::getIntValue()
{
	auto name = getValueString();
	if (name.compare(SELF_STR) == 0)
		return SELF_VAL;

	auto instance = int32_t(0);
	int32_t strip;
	if (name.find('#') != string::npos) {
		auto parts = moduru::lang::StrUtil::split(name, '#');
		instance = parts.size() > 0 ? stoi(parts[1]) - 1 : 0;
		strip = stoi(parts[0]) - 1;
	}
	else {
		strip = stoi(name) - 1;
	}
	return strip * 8 + instance;
}

bool TapControl::hasLabel()
{
	return true;
}
