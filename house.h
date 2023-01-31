#ifndef HOUSE_H_INCLUDED
#define HOUSE_H_INCLUDED

class House
{
private:
	bool bedKey = false;
	bool basKey = false;
public:
	void dinKit();
	void bath();
	void live();
	void bed();
	void attic();
	void base();
	void inventory() const;
};

static void intro();

static void credits();

#endif