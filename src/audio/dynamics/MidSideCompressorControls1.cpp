#include <audio/dynamics/MidSideCompressorControls1.hpp>

#include <audio/dynamics/MidSideCompressorControls.hpp>

using namespace ctoot::audio::dynamics;
using namespace std;

MidSideCompressorControls1::MidSideCompressorControls1(string name, int32_t idOffset)
	: CompressorControls(name, idOffset)
{
}

bool MidSideCompressorControls1::hasKey()
{
    return false;
}

bool MidSideCompressorControls1::canBypass()
{
    return false;
}
