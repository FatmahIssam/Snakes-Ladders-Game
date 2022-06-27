#pragma once
#include "Card.h"
class CardThree :public Card
{
	Cell* pCell;
public:

	CardThree(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
	virtual void CopyCard(Grid* pGrid);
	virtual void CutCard(Grid* pGrid);
	virtual void PasteCard(Grid* pGrid);						  // by decrementing the player's wallet by the walletAmount data member
	void Save(ofstream& OutFile, TYPE CARD);
	void Read(ifstream& Infile);
	//virtual bool Validate();


	~CardThree();




};

