#pragma once

namespace OP {


	class OPEvent {
	private:
		const char* l_name;
		void * l_Source;
	public:

		OPEvent(const char* name, void * Source);

		~OPEvent();
		void * getSource();

		const char* getName();

		void runFunction();

	};
}