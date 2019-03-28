#pragma once
#include <vector>
#include <memory>
#include <functional>

namespace OP {

	struct Initalization
	{
		typedef std::function <void()> function_type;

		static std::vector<function_type>& get_initialization_list()
		{
			static std::vector<function_type> initializer_list;

			return initializer_list;
		}


		static void register_initializer(function_type fn)
		{
			get_initialization_list().push_back(fn);
		}

		static void run_init()
		{
			for (auto fn : get_initialization_list())
				fn();
		}
	};

	struct initializer
	{
		initializer(Initalization::function_type fn)
		{
			Initalization::register_initializer(fn);
		}
	};
}