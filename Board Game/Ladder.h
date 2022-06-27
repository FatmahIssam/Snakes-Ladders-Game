#pragma once

#include "GameObject.h"
#include <fstream>
#include <iostream>
using namespace std;

class Ladder :	public GameObject // inherited from GameObject
{
	// Note: the "position" data member inherited from the GameObject class is used as the ladder's "Start Cell Position"

	CellPosition endCellPos; // here is the ladder's End Cell Position
	CellPosition StartCell;

public:
	Ladder();
	CellPosition GetEndPositionOfCell(Ladder * l);
	Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos); // A constructor for initialization

	virtual void Draw(Output* pOut) const; // Draws a ladder from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the ladder by moving player to ladder's end cell

	void Save(ofstream &OutFile, TYPE);	// Saves the GameObject parameters to the file
	void Read(ifstream &Infile) ;	// Loads and Reads the GameObject parameters from the file

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member
	CellPosition GetStartPosition() const;
	virtual ~Ladder(); // Virtual destructor
};
