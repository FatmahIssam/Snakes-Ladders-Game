#pragma once
#include"Base10To14.h"
class CardEleven :
	public Base10To14
{

public:
	//Static Members
	static int Fee;
	static int Price;
	static Player* pPointer;
	//Const
	CardEleven(const CellPosition& pos);
	//Virtual Getters/setters
	virtual void setPlayer(Player*);
	void CopyCard(Grid* pGrid);
	void CutCard(Grid* pGrid);
	void PasteCard(Grid* pGrid);
	virtual Player* getPlayer();
	virtual int getFee();
	virtual int getPrice();
	virtual void setFee(int);
	virtual void setPrice(int);
	~CardEleven(void);
};