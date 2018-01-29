#pragma once

#include "header.hpp"
#include "character.hpp"
#include "item.hpp"

class world_builder{
public:
	void DoSomething(){
		std::cout<<"-called from world_builder"<<'\n';
	}

	bool roll(int side, int success, double modifier){
		srand(time(NULL));			//random seed
		int roll = rand()%side+1; 	//return a num 1-side
		roll*= modifier; 			//mult result *modifier
		if(roll < success){ return false;}
		else{ return true;}
	}


private:
	std::vector<item*> all_items;
	std::vector<character*> all_characters;
};	