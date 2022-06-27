#pragma once
#include "GameObject.h"
#include <fstream>
#include <iostream>

class Snake : public GameObject
{
	CellPosition StartCell;
	CellPosition endCellPos;
public:
	Snake();
	Snake(const CellPosition & startCellPos, const CellPosition & endCellPos);
	virtual void Draw(Output* pOut) const;
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void Save(ofstream &OutFile, TYPE SNAKE);	// Saves the GameObject parameters to the file
	void Read(ifstream &Infile) ;	// Loads and Reads the GameObject parameters from the file
	CellPosition GetEndPosition() const;
	CellPosition GetStartPosition() const;
	virtual ~Snake();
};

