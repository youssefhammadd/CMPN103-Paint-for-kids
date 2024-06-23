#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager *pApp):Action(pApp)
{

}
ExitAction::~ExitAction()
{

}
void ExitAction::Execute()
{
	ReadActionParameters();
	pManager->ClearAll();
	EXIT_SUCCESS;
}
void ExitAction::Undoaction()
{

}
void ExitAction::Redoaction()
{

}
void ExitAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}