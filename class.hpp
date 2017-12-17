#pragma once

#include "function.hpp"
/*
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
*/

//	item class and its derive classes
//-------------------------------------------------------------------
//
//	item class
//
class item{

public:
	item(	std::string arg1, 	std::string arg2,
			int arg3,			int arg4):
			name(arg1),			description(arg2),
			stack_limit(arg4),	current_stack(current_stack){}
	//change field


protected:
	std::string name, description;
	int stack_limit, current_stack;
};

//
//	equipment type enum
//
enum equipmentType{
	helmet,
	cape,
	chest,
	gaunlet,
	leggings,
	shoes,
	weapon,
	secondary,
	offhand,
	backpack,
	ring,
	necklace,
	bracelet,
	belt,
	undergarmet,
	earrings
};


//
//	equipment derived item class 
//
class equipment : public item {
public:
	//constructor
	equipment(	std::string arg1, 	
				std::string arg2,
				double arg3,
				double arg4,
				double arg5,
				double arg6,
				double arg7,
				double arg8,
				double arg9,
				double arg10,
				double arg11,
				double arg12,
				std::string arg13,
				equipmentType arg14)
			:	
		item(	arg1,	arg2, 1, 0),
				req_str(arg3), 
				req_int(arg4), 
				req_luck(arg5), 
				req_agi(arg6), 
				req_hp(arg7), 
				req_mp(arg8),
				req_dmg(arg9),
				req_def(arg10),
				req_mdef(arg11),
				req_stam(arg12),
				modifier(arg13),
				type(arg14){}
	//
	//methods for retrieving a field
	//
	std::string get_name(){return name;}
	std::string get_description(){return description;}
	std::string get_modifier(){return modifier;}
	equipmentType get_type(){return type;}
	double get_str(){return req_str;}
	double get_int(){return req_int;}
	double get_luck(){return req_luck;}
	double get_agi(){return req_agi;}
	double	get_hp(){return req_hp;}
	double	get_mp(){return req_mp;}
	double	get_dmg(){return req_dmg;}
	double	get_def(){return req_def;}
	double	get_mdef(){return req_mdef;}
	double	get_stam(){return req_stam;}
	//
	//methods for changing a field
	//
	void change_str(double arg){req_str = arg;}
	void change_int(double arg){req_int = arg;}
	void change_luck(double arg){req_luck = arg;}
	void change_agi(double arg){req_agi = arg;}
	void change_hp(double arg){req_hp = arg;}
	void change_mp(double arg){req_mp = arg;}
	void change_dmg(double arg){req_dmg = arg;}
	void change_def(double arg){req_def = arg;}
	void change_mdef(double arg){req_mdef = arg;}
	void change_stam(double arg){req_stam = arg;}
	void change_name (std::string arg){name = arg;}
	void change_description (std::string arg){description = arg;}
	void change_modifier (std::string arg){modifier = arg;}
	void change_type(equipmentType arg){type = arg;}

protected: 
	std::string modifier;
	equipmentType type;
	double 	req_str,	req_int, 	req_luck, 
			req_agi, 	req_hp, 	req_mp,
			req_dmg,	req_def,	req_mdef,
			req_stam;
};

class consumables : public item {
public:
	consumables(std::string arg1, 
				std::string arg2,
				int arg3,
				std::string arg4)
			:
				item(arg1, arg2, arg3, 0),
				effect(arg4){}

protected:
	std::string effect;
};

//	characters and its derived classes
//------------------------------------------------------------------------

//
//	character class
//

class character {
public:
	character()

protected:
	double 	str, _int, luck, agi, hp, mp, def, mdef, 
			stam, dmg, max_hp, max_mp, max_stam;
	std::string name, description;
	//check if the character is a player
	bool player_buff; 
	//all euipped item
	std::vector<equipment> equipped;
	//inventory is full of items and its derived clases
	//visit https://stackoverflow.com/questions/6274136/objects-of-different-classes-in-a-single-vector
	//for example
	std::vector<item*> inventory; 
	//this character will drop the following when defeated
	std::string drop;
};