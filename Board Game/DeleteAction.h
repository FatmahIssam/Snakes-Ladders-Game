#pragma once
#include "Action.h"

class DeleteAction : public Action 
{
	CellPosition CellPos;

public:

	DeleteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~DeleteAction();

};

