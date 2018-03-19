#pragma once

#include <audio/filter/AbstractFilter.hpp>

namespace ctoot {
	namespace audio {
		namespace filter {

			class BiQuadFilter
				: public AbstractFilter
			{

			private:
				double a0{  };
				double a1{  };
				double a2{  };
				double a3{  };
				double a4{  };

			public:
				void filter(std::vector<float>* buffer, std::vector<float>* mixBuffer, int32_t length, int32_t chan, bool doMix) override;

			protected:
				void updateFilterCoefficients() override;
				FilterDesign* createDesign(FilterSpecification* spec) override;
				FilterState* createState() override;

			public:
				BiQuadFilter(FilterSpecification* spec, bool relative);

			};

		}
	}
}
