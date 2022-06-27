#pragma once
#include "Card.h"
class CardNine : public Card
{
	CellPosition  MoveToCell;
public :

	CardNine (const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual void Edit(Grid* pGrid);

	void Save(ofstream& OutFile, TYPE CARD);

	void Read(ifstream& Infile);

	virtual bool Validate();

	virtual ~CardNine();

};
