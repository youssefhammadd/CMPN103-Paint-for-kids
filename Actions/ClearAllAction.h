#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"

class ClearAllAction :public Action
{
public:
	ClearAllAction(ApplicationManager* pApp);
	~ClearAllAction();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};
