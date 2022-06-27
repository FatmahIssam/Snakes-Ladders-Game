#pragma once
#include"Base10To14.h"
class CardFourteen :
	public Base10To14
{

public:
	CardFourteen(const CellPosition& pos);
	//Static Members
	static int Fee;
	static int Price;
	static Player* pPointer;
	//Virtual Setters/Getters
	virtual void setPlayer(Player*);
	void CopyCard(Grid* pGrid);
	void CutCard(Grid* pGrid);
	void PasteCard(Grid* pGrid);
	virtual Player* getPlayer();
	virtual int getFee();
	virtual int getPrice();
	virtual void setFee(int);
	virtual void setPrice(int);
	~CardFourteen(void);
};

