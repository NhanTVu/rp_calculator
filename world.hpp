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
	void removeItemById(int id);
	item* getItemPtrById(int id);

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
		roll*= modifier; 			//note that extra decimal will be truncated here
		if(roll < success){ return false;}
		else{ return true;}			//true is a success
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
			//confirmation print
			std::cout<<"-----------------"<<'\n'<<
			"There is already an item with that id"<<'\n';
		}
		/*
		//debugger print
		std::cout<<"item in vector's id: "<<all_items[i]->getId()
		<<"| item's id: "<<Item.getId()<<"|"<<'\n';
		*/
		if(all_items[i]->getName().compare(Item.getName())==0){
			name_exist = true;
			//confirmation print
			std::cout<<"-----------------"<<'\n'<<
			"There is already an item with that name"<<'\n';
		}
		/*
		//debugger print		
		std::cout<<"item in vector's name: "<<all_items[i]->getName()
		<<"| item's name: "<<Item.getName()<<"|"<<'\n'<<
		"comparison yield: "<<all_items[i]->getName().compare(Item.getName())<<'\n';
		*/
		if(all_items[i]->getDescription().compare(Item.getDescription())==0){
			info_exist = true;
			//confirmation print
			std::cout<<"-----------------"<<'\n'<<
			"There is already an item with that description"<<'\n';
		}
		/*
		//debugger print		
		std::cout<<"item in vector's description: "<<all_items[i]->getDescription()
		<<"| item's description: "<<Item.getDescription()<<"|"<<'\n'<<
		"comparison yield: "<<all_items[i]->getDescription().compare(Item.getDescription())<<'\n';
		*/
	}
	//if pass all test	
	if(	!(name_exist) 	&& 
		!(id_exist)		&&
		!(info_exist	))
	{				
		item* entry = &Item;			//typecast into *item
		all_items.push_back(entry);		//actually adding the *item
		//conformation print
		std::cout<<"-----------------"<<'\n'<<"item added"<<'\n';
	}
}

void world_builder::removeItemById(int id){
	int i;
	if (all_items.empty()){
		std::cout<<"There are no items with that id"<<'\n';
	}else{
		for (i=0; i<all_items.size(); i++){		//check all items
			if( all_items[i]->getId()==id){
				all_items.erase(all_items.begin()+i);
				//debugger print
				std::cout<<"-----------------"<<'\n'<<"Item (id: "
				<<all_items[i]->getId()<<") has been removed"<<'\n';
			}
		}
	}

}

item* world_builder::getItemPtrById(int id){
	
	//debugger print
	//std::cout<<"-----------------"<<
	//'\n'<<"running getItemById..."<<'\n';

	int i;
	if (all_items.empty()){
		//error print
		std::cout<<"-----------------"<<'\n'
		<<"!!!ERROR!!"<<
		"There are no items"<<'\n';
		return NULL;
	}else{
		//debugger print
		//std::cout<<"Here 1"<<'\n';
		for (i=0; i<all_items.size(); i++){		//check all items
			//debugger print
			//std::cout<<"Here 2"<<'\n';
			if( all_items[i]->getId()==id){
				//debugger print
				//std::cout<<"Here 3"<<'\n';
				//confirmation print
				std::cout<<"-----------------"<<
				'\n'<<"item pointer retrieved"<<'\n';
				return all_items[i];
			}
		}
		//error print
		std::cout<<"-----------------"<<'\n'
		<<"!!!ERROR!!"<<
		"There are no items with the id: "
		<<id<<'\n';
		return NULL;
	}
	//debugger print
	std::cout<<"-----------------"<<
	'\n'<<"no result from getItemById"<<'\n';
}


