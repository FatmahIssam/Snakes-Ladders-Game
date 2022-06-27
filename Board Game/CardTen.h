#pragma once
#include "Base10To14.h"

class CardTen :
	public Base10To14
{


public:
	//Staitc Members
	static int Fee;
	static int Price;
	static Player* pPointer;
	//Const
	CardTen(const CellPosition& pos);
	//virtual Setters/getters
	virtual void setPlayer(Player*);
	void CopyCard(Grid* pGrid);
	void CutCard(Grid* pGrid);
	void PasteCard(Grid* pGrid);
	virtual Player* getPlayer();
	virtual int getFee();
	virtual int getPrice();
	virtual void setFee(int);
	virtual void setPrice(int);
	~CardTen(void);
};

