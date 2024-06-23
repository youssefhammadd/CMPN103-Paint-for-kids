#include "RedoAction.h"
RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{
}
void RedoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Redo is selected!!");
}
void RedoAction::Undoaction()
{

}
void RedoAction::Redoaction()
{

}
void RedoAction::Execute()
{
	ReadActionParameters();
	pManager->RedoLastAction();
}
RedoAction::~RedoAction()
{

}