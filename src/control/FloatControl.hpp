#pragma once
#include <control/LawControl.hpp>

namespace ctoot {
	namespace control {


		class FloatControl
			: public LawControl
		{

		private:
			std::string minLabel{ "" };
			std::string maxLabel{ "" };
			std::string midLabel{ "" };
	
		public:
			virtual bool isRotary();
			virtual float getMaximum();
			virtual float getMinimum();
			virtual std::string getMinLabel();
			virtual std::string getMidLabel();
			virtual std::string getMaxLabel();
			std::string toString();

		public:
			FloatControl(int id, std::string name, std::weak_ptr<ControlLaw> law, float precision, float initialValue) 
				: FloatControl(id, name, law, precision, initialValue, "", "", "") {};
			FloatControl(int id, std::string name, std::weak_ptr<ControlLaw> law, float precision, float initialValue, std::string minLabel, std::string midLabel, std::string maxLabel);
			virtual ~FloatControl();

		};

	}
}
