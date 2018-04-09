#pragma once

namespace ctoot {
	namespace audio {
		namespace dynamics {

			class DynamicsControlIds
			{

			public:
				static constexpr int32_t KEY{ 0 };
				static constexpr int32_t THRESHOLD{ 1 };
				static constexpr int32_t RATIO{ 2 };
				static constexpr int32_t KNEE{ 3 };
				static constexpr int32_t ATTACK{ 4 };
				static constexpr int32_t HOLD{ 5 };
				static constexpr int32_t RELEASE{ 6 };
				static constexpr int32_t GAIN{ 7 };
				static constexpr int32_t DRY_GAIN{ 8 };
				static constexpr int32_t DEPTH{ 9 };
				static constexpr int32_t CROSSOVER_FREQUENCY{ 10 };
				static constexpr int32_t HYSTERESIS{ 11 };
				static constexpr int32_t RMS{ 12 };
				static constexpr int32_t DETECTION_CHANNEL_MODE{ 13 };
				static constexpr int32_t ATTENUATION_CHANNEL_MODE{ 14 };
				static constexpr int32_t INPUT_GAIN{ 15 };
			};

		}
	}
}
