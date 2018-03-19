#pragma once

#include <control/EnumControl.hpp>

#include <boost/any.hpp>

#include <vector>
#include <string>

namespace ctoot {
	namespace audio {
		namespace core {

			class AudioBuffer;

			class TapControl
				: public ctoot::control::EnumControl
			{

			private:
				static constexpr int32_t SELF_VAL{ 16000 };
				static std::string SELF_STR;
				std::string prevTapName{  };
				AudioBuffer* buffer{  };

			private:
				void init();

			public:
				virtual AudioBuffer* getBuffer();
				virtual void remove();

			protected:
				void derive(ctoot::control::Control* obj) override;
				virtual void reference(std::string name, int32_t ref);

			public:
				std::vector<boost::any> getValues() override;
				void setIntValue(int32_t value) override;
				int32_t getIntValue() override;
				bool hasLabel() override;

				TapControl(int32_t id, std::string name);
			};

		}
	}
}
