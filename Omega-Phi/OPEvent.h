#pragma once

namespace OP {


	class OPEvent {
	private:
		const char* l_name;
		const char* l_message;
		void * l_Source;
	public:

		OPEvent(const char* name, void * Source, const char* message = "");

		~OPEvent();
		void * getSource();

		const char* getName();

		const char* getMessage();

	};
}