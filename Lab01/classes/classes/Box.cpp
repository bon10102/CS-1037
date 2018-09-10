#include "stdafx.h"
#include "Box.h"
std::string Box::getDescription() {
	std::string desc = "Box W:";
	desc += std::to_string(_w) +
		" H:" + std::to_string(_h) +
		" D:" + std::to_string(_d);
	return desc;
}
