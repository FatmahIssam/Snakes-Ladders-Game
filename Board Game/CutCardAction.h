#pragma once
#include "Action.h"
#include"Card.h"
class CutCardAction :public Action
{
	Card* CC2;
	Cell* pCell;
public:
	CutCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CutCardAction();







};

