#include "SaveAction.h"
#include "fstream"
#include"ApplicationManager.h"
using namespace std;
SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{

}
SaveAction::~SaveAction()
{

}
void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();  //get a pointer to the input/output interfaces
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter File's Name: ");
}
void SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();  //get a pointer to the input/output interfaces
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	FileName = pIn->GetSrting(pOut);      //Reads file name from the user
	std::ofstream fileout(FileName+".txt");
	if (fileout.is_open())
	{
		fileout << pOut->color_to_string(pOut->getCrntDrawColor());             //  Save the current draw color
		fileout <<"\t"<< pOut->color_to_string(pOut->getCrntFillColor())<<endl; // Save the current filled color
		fileout << to_string(pManager->GetFigCount())<<endl;                          // Save the total number of figures
		pManager->SaveAll(fileout);
		fileout.close();
	}
	pOut->PrintMessage("File is Saved.");
}
void SaveAction::Undoaction()
{

}
void SaveAction::Redoaction()
{

}



