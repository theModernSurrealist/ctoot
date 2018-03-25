#pragma once

#include <audio/core/AudioControls.hpp>
#include <audio/dynamics/DynamicsVariables.hpp>

#include <memory>

namespace ctoot {

	namespace control {
		class ControlLaw;
		class FloatControl;
		class BooleanControl;
	}

	namespace audio {

		namespace core {
			class TapControl;
		}

		namespace dynamics {

			class GainReductionIndicator;

			class DynamicsControls
				: public ctoot::audio::core::AudioControls
				, public virtual DynamicsVariables
			{

			private:
				static std::weak_ptr<ctoot::control::ControlLaw> THRESH_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> RATIO_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> INVERSE_RATIO_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> KNEE_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> ATTACK_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> HOLD_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> RELEASE_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> DRY_GAIN_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> GAIN_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> DEPTH_LAW();
				static std::weak_ptr<ctoot::control::ControlLaw> HYSTERESIS_LAW();

				std::weak_ptr<GainReductionIndicator> gainReductionIndicator{};
				std::weak_ptr<ctoot::control::FloatControl> thresholdControl{};
				std::weak_ptr<ctoot::control::FloatControl> ratioControl{};
				std::weak_ptr<ctoot::control::FloatControl> kneeControl{};
				std::weak_ptr<ctoot::control::BooleanControl> rmsControl{};
				std::weak_ptr<ctoot::control::FloatControl> attackControl{};
				std::weak_ptr<ctoot::control::FloatControl> holdControl{};
				std::weak_ptr<ctoot::control::FloatControl> releaseControl{};
				std::weak_ptr<ctoot::control::FloatControl> dryGainControl{};
				std::weak_ptr<ctoot::control::FloatControl> gainControl{};
				std::weak_ptr<ctoot::control::FloatControl> depthControl{};
				std::weak_ptr<ctoot::control::FloatControl> hysteresisControl{};
				std::weak_ptr<ctoot::audio::core::TapControl> keyControl{};

				float sampleRate{ 44100.0f };
				float threshold{}, inverseThreshold{}, thresholddB{}, inverseRatio{}, kneedB{ 10.0f };
				float attack{}, release{}, gain{ 1.0f }, dryGain{ 0.0f }, depth{ 40.0f }, hysteresis{ 0.0f };
				bool rms{ false };

			public:
				int32_t hold{ 0 };

			private:
				ctoot::audio::core::AudioBuffer* key{};
				int32_t idOffset{ 0 };

			public:
				void update(float sampleRate) override;
			
			protected:
				void init();

			private:
				bool initialized = false;

			protected:
				void derive(ctoot::control::Control* c) override;
				virtual void deriveThreshold();
				virtual void deriveRatio();
				virtual void deriveKnee();
				virtual void deriveRMS();

			private:
				static float& LOG_0_01();

			protected:
				virtual float deriveTimeFactor(float milliseconds);
				virtual void deriveAttack();
				virtual void deriveHold();
				virtual void deriveRelease();
				virtual void deriveDryGain();
				virtual void deriveGain();
				virtual void deriveDepth();
				virtual void deriveHysteresis();
				virtual void deriveKey();
				void setParent(ctoot::control::CompoundControl* parent) override;
				virtual bool hasGainReductionIndicator();
				virtual ctoot::control::ControlLaw* getThresholdLaw();
				virtual bool hasInverseRatio();
				virtual bool hasRatio();
				virtual bool hasKnee();
				virtual bool hasRMS();
				virtual ctoot::control::ControlLaw* getAttackLaw();
				virtual bool hasHold();
				virtual ctoot::control::ControlLaw* getHoldLaw();
				virtual ctoot::control::ControlLaw* getReleaseLaw();
				virtual bool hasDryGain();
				virtual ctoot::control::ControlLaw* getDryGainLaw();
				virtual bool hasGain();
				virtual ctoot::control::ControlLaw* getGainLaw();
				virtual bool hasDepth();
				virtual ctoot::control::ControlLaw* getDepthLaw();
				virtual bool hasHysteresis();
				virtual ctoot::control::ControlLaw* getHysteresisLaw();
				virtual bool hasKey();

				virtual std::shared_ptr<ctoot::control::FloatControl> createDepthControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createGainControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createDryGainControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createThresholdControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createRatioControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createKneeControl();
				virtual std::shared_ptr<ctoot::control::BooleanControl> createRMSControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createAttackControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createHoldControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createReleaseControl();
				virtual std::shared_ptr<ctoot::control::FloatControl> createHysteresisControl();
				virtual std::shared_ptr<ctoot::audio::core::TapControl> createKeyControl();

			public:
				float getThreshold() override;
				float getInverseThreshold() override;
				float getThresholddB() override;
				float getKneedB() override;
				float getInverseRatio() override;
				float getAttack() override;
				int32_t getHold() override;
				float getRelease() override;
				float getDryGain() override;
				float getGain() override;
				float getDepth() override;
				float getHysteresis() override;
				ctoot::audio::core::AudioBuffer* getKeyBuffer() override;
				bool isRMS() override;
				void setDynamicGain(float dynamicGain) override;

			protected:
				virtual ctoot::control::ControlLaw* getInverseRatioLaw();

			public:
				static std::vector<std::string> ratioPresets2;

			public:
				DynamicsControls(int32_t id, std::string name);
				DynamicsControls(int32_t id, std::string name, int32_t idOffset);

			public:
				virtual bool isBypassed();

			private:
				friend class InverseRatioControl;

			};
		}
	}
}
