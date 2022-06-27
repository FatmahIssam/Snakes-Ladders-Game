#pragma once
#include "Card.h"
class CardSix :public Card
{
	int Step;
public:
	CardSix(const CellPosition& pos); // A Constructor takes card position


	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	//virtual bool Validate();
	virtual void CopyCard(Grid* pGrid);
	virtual void CutCard(Grid* pGrid);
	virtual void PasteCard(Grid* pGrid);
	void Save(ofstream& OutFile, TYPE CARD);
	void Read(ifstream& Infile);
	~CardSix();




};

