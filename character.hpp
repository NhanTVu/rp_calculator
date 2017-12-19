#pragma once
#include "header.hpp"
#include "item.hpp"

//	characters and subclasses
//------------------------------------------------------------------------

//
//	character class
//
class character {
public:
	character( 	std::string _name, 	
				std::string _description,
				std::string _drop,
				std::string _buff,
				double _str,
				double _int_,
				double _luck,
				double _agi,
				double _hp,
				double _mp,
				double _def,
				double _mdef,
				double _stam,
				int _id)
			:
				name(_name), 
				description(_description), 
				drop(_drop),
				buff(_buff),
				str(_str), 
				_int(_int_), 
				luck(_luck),  
				agi(_agi),   
				hp(_hp), max_hp(_hp),
				mp(_mp), max_mp(_mp),
				def(_def), 
				mdef(_mdef), 
				stam(_stam), max_stam(_stam),	
				id(_id){}
protected:
	double 	str, _int, luck, agi, hp, mp, def, mdef, 
			stam, dmg, max_hp, max_mp, max_stam;
	std::string name, description, drop, buff;
	int id;
	//all euipped item
	std::vector<equipment> equipped;
	//inventory is full of items and its derived clases
	//visit https://stackoverflow.com/questions/6274136/objects-of-different-classes-in-a-single-vector
	//for example
	std::vector<item*> inventory;
	//this character will drop the following when defeated
};

//
//	mob character for grinding
//
class mob : public character{
public:
	mob(	std::string _name, 	
			std::string _description,
			std::string _drop,
			std::string _buff,
			double _str,
			double _int_,
			double _luck,
			double _agi,
			double _hp,
			double _mp,
			double _def,
			double _mdef,
			double _stam,
			int _id)
		:
	character(_name, _description, _drop, _buff,
		_str, _int_, _luck, _agi, _hp, _mp, 
		_def,_mdef, _stam, _id){}
};

//
//	player character
//

class player : public character{
public:
	player(	std::string _name, 	
			std::string _description,
			std::string _drop = "",
			std::string _buff = "playerBuff ",
			double _str,
			double _int_,
			double _luck,
			double _agi,
			double _hp,
			double _mp,
			double _def,
			double _mdef,
			double _stam,
			int _id)
		:
	character(_name, _description, _drop, _buff,
		_str, _int_, _luck, _agi, _hp, _mp, 
		_def,_mdef, _stam, _id){}
};

