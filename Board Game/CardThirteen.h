#pragma once
#include"Base10To14.h"
class CardThirteen :
	public Base10To14
{

public:
	//static members
	static int Fee;
	static int Price;
	static Player* pPointer;
	//Const
	CardThirteen(const CellPosition& pos);
	//Virtual Setters / Getters
	virtual void setPlayer(Player*);
	void CopyCard(Grid* pGrid);
	void CutCard(Grid* pGrid);
	void PasteCard(Grid* pGrid);
	virtual Player* getPlayer();
	virtual int getFee();
	virtual int getPrice();
	virtual void setFee(int);
	virtual void setPrice(int);
	~CardThirteen(void);
};
