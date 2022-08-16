#pragma once
#include <string>

namespace anthemum
{
	class Resource
	{
	public : 
		virtual bool Create(const std::string& name, void* data = nullptr) = 0;
	};
}