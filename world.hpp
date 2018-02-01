#pragma once

#include "header.hpp"
#include "character.hpp"
#include "item.hpp"

class world_builder{
public:
	//debugger method
	void DoSomething();
	//dice roll method for chance
	bool DiceRoll(int side, int success, double modifier);
	//item methods
	void addItem(item Item);
	void removeItemByID(int id);
	item getItemByID(int id);

	//character methods
	void addCharacter(character Character);
	void removeCharacterByID(int id);
	character getCharacterByID(int id);

private:
	std::vector<item*> all_items;
	std::vector<character*> all_characters;
};	

//---------------------------------------------------------------------------------
void world_builder::DoSomething(){
		std::cout<<"-called from world_builder"<<'\n';
}

//---------------------------------------------------------------------------------
bool world_builder::DiceRoll(int side, int success, double modifier){
		srand(time(NULL));			//random seed
		int roll = rand()%side+1; 	//return a num 1-side
		roll*= modifier; 			//mult result *modifier
		if(roll < success){ return false;}
		else{ return true;}
}

//item methods
//---------------------------------------------------------------------------------

//add a new item to the list and check if it has a unique name, id, and description
void world_builder::addItem(item Item){
	bool id_exist = false, 
	name_exist = false,
	info_exist = false;
	int i;
	for (i=0; i<all_items.size(); i++){
		if(all_items[i]->getId() == Item.getId()){
			id_exist = true;
		}
		/*
		//debugger print
		std::cout<<"item in vector's id: "<<all_items[i]->getId()
		<<"| item's id: "<<Item.getId()<<"|"<<'\n';
		*/
		if(all_items[i]->getName().compare(Item.getName())==0){
			name_exist = true;
		}
		/*
		//debugger print		
		std::cout<<"item in vector's name: "<<all_items[i]->getName()
		<<"| item's name: "<<Item.getName()<<"|"<<'\n'<<
		"comparison yield: "<<all_items[i]->getName().compare(Item.getName())<<'\n';
		*/
		if(all_items[i]->getDescription().compare(Item.getDescription())==0){
			info_exist = true;
		}
		/*
		//debugger print		
		std::cout<<"item in vector's description: "<<all_items[i]->getDescription()
		<<"| item's description: "<<Item.getDescription()<<"|"<<'\n'<<
		"comparison yield: "<<all_items[i]->getDescription().compare(Item.getDescription())<<'\n';
		*/

	}
	if(id_exist){
		std::cout<<"There is already an item with that id"<<'\n';
	}
	if(name_exist){
		std::cout<<"There is already an item with that name"<<'\n';
	}
	if(info_exist){
		std::cout<<"There is already an item with that description"<<'\n';
	}
	//if pass all test	
	if(	!(name_exist) 	&& 
		!(id_exist)		&&
		!(info_exist	))
	{				
		item* entry = &Item;			//typecast into *item
		all_items.push_back(entry);		//actually adding the *item
		//debugger print
		std::cout<<"item added"<<'\n';
	}
}

void world_builder::removeItemByID(int id){
	int i;
	if (all_items.empty()){
		std::cout<<"There are no items"<<'\n';
	}else{
		for (i=0; i<all_items.size(); i++){		//check all items
			if( all_items[i]->getId()==id){
				all_items.erase(all_items.begin()+i);
			}
		}
	}

}
/*
item world_builder::getItemByID(int id){
	int i;
	if (all_items.empty()){
		std::cout<<"There are no items"<<'\n';
	}else{
		for (i=0; i<all_items.size(); i++){		//check all items
			if( all_items[i]->getId()==id){
				return all_items[i];
			}
		}
	}
}*/


