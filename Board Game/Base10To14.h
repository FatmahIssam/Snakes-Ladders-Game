#pragma once
#include "Card.h"
#include "Player.h"

class Base10To14 :
	public Card
{
protected:
	Player* pOwner;
	bool IsBought;
	string cardName;

public:
	Base10To14(const CellPosition& pos);
	virtual void ReadCardParameters(Grid*);
	virtual void Edit(Grid*);
	virtual void Apply(Grid*, Player*);
	virtual bool Validate();

	virtual int getFee() = 0;
	virtual int getPrice() = 0;
	virtual void setFee(int) = 0;
	virtual void setPrice(int) = 0;
	virtual void setPlayer(Player*) = 0;
	virtual Player* getPlayer() = 0;

	void Save(ofstream& OutFile, TYPE CARD);
	void Read(ifstream& Infile);

	~Base10To14(void);
};

