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
				double _dmg,
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
				dmg(_dmg),id(_id){}

	//methods for retrieving a field
	std::string get_name(){return name;}
	std::string get_description(){return description;}
	std::string get_drop(){return drop;}
	std::string get_buff(){return buff;}
	double get_str(){return str;}
	double get_int(){return _int;}
	double get_luck(){return luck;}
	double get_agi(){return agi;}
	double get_hp(){return hp;}
	double get_mp(){return mp;}
	double get_maxHp(){return max_hp;}
	double get_maxMp(){return max_mp;}
	double get_stam(){return stam;}
	double get_maxStam(){return max_stam;}
	double get_def(){return def;}
	double get_mdef(){return mdef;}
	double get_dmg(){return dmg;}
	int get_id(){return id;}

	//method for changing a field
	void changeName(std::string input){name = input;}
	void changeDescription(std::string input){description = input;}
	void changeDrop(std::string input){drop = input;}
	void changeBuff(std::string input){buff = input;}
	void changeStr(double input){str = input;}
	void changeInt(double input){_int = input;}
	void changeLuck(double input){luck = input;}
	void changeAgi(double input){agi = input;}
	void changeHp(double input){hp = input;}
	void changeMp(double input){mp = input;}
	void changeMaxHp(double input){max_hp = input;}
	void changeMaxMp(double input){max_mp = input;}
	void changeStam(double input){stam = input;}
	void changeMaxStam(double input){max_stam = input;}
	void changeDef(double input){def = input;}
	void changeMDef(double input){mdef = input;}
	void changeDmg(double input){dmg = input;}
	void changeId(int input){id = input;}

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
			double _dmg,
			int _id)
		:
	character(_name, _description, _drop, _buff,
		_str, _int_, _luck, _agi, _hp, _mp, 
		_def,_mdef, _stam, _dmg, _id){}
};

//
//	player character
//

class player : public character{
public:
	player(	std::string _name, 	
			std::string _description,
			double _str,
			double _int_,
			double _luck,
			double _agi,
			double _hp,
			double _mp,
			double _def,
			double _mdef,
			double _stam,
			double _dmg,
			int _id)
		:
	character(_name, _description, "", "playerBuff ",
		_str, _int_, _luck, _agi, _hp, _mp, 
		_def,_mdef, _stam, _dmg, _id){}
};

