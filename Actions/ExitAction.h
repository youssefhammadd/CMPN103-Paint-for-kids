#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class ExitAction :public Action
{
public:
	ExitAction(ApplicationManager *pApp);
	~ExitAction();
	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};

