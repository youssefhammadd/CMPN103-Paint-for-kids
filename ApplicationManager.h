#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures and Actions
private:
	int FigCount;		//Actual number of figures
	int ID;             // ID for each figure
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	//RY Changed here
	//Action* ActionList[MaxFigCount]; //List of last five actions
	Action* ActionList[MaxUndoCount];  //List of last five actions
	Action* LastAction;   //Pointer to last Action
	int ActionCount;
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void DeleteFigure(CFigure* pFig);        //Deletes a figure from FigList 
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SetSelectedFigure(CFigure* FigPtr);               //make "SelectedFig" point to the selected figure
	CFigure* GetSelected();                 //return a pointer to the selected figure
	void unselectall();                    //unselects all figures
	void UndoLastAction();                           //Undo an Action
	void RedoLastAction();                           //Redo the Undo Action
	// -- Interface Management Functions
	bool DeleteLastFig();               //Remove figure from the figlist
	void IncrementFigCount();               //Adds the removed figure from the figlist
	//void IncrementActionCount();            //Add the Action done
	//void DecrementFigCount();               //
	int GetActionCount();
	int GetFigCount();                      //Getter to Number of figures
	void SetFigCount(int NoOfFig);                     //Setter to Number of figures
	Input* GetInput() const;               //Return pointer to the input
	Output* GetOutput() const;             //Return pointer to the output
	void UpdateInterface() const;	       //Redraws all the drawing window	
	//  --  SaveAll Management Function
	void SaveAll(ofstream& OutFile);
	// --  ClearAll Management
	void ClearAll();
};

#endif