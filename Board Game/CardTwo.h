#pragma once
#include "Card.h"

class CardTwo:public Card
{
private:
	int walletvalue;// the wallet value to increase from the player
public:
	CardTwo(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	virtual void CopyCard(Grid* pGrid);
	virtual void CutCard(Grid* pGrid);
	virtual void PasteCard(Grid* pGrid);
	virtual void Edit(Grid*);// by decrementing the player's wallet by the walletAmount data member
	virtual bool Validate();
	void Save(ofstream& OutFile, TYPE CARD);
	void Read(ifstream& Infile);
	 ~CardTwo(); // A Virtual Destructor
};

