#include "ClearAllAction.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
}
ClearAllAction::~ClearAllAction()
{
}
void ClearAllAction::ReadActionParameters()
{

}
void ClearAllAction::Undoaction()
{

}
void ClearAllAction::Redoaction()
{

}
void ClearAllAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	
		pManager->ClearAll();
		pOut->PrintMessage("Clear All Figures");

}