#pragma once

#include "header.hpp"
#include "character.hpp"
#include "item.hpp"

class world_builder{
public:
	void DoSomething(){
		std::cout<<"-called from world_builder"<<'\n';
	}

private:
	std::vector<item*> all_items;
	std::vector<character*> all_characters;
};	