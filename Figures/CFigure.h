#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
#include "..\Actions\Action.h"
using namespace std;

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool isFilled;
	bool  isDraw;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure
	color getCurrentFillColor();
	bool isColorFilled();
	bool isColorDraw();
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void SetID(int id);             // setter to ID
	int GetID();                    // Getter to ID
	virtual bool insidefig(int x, int y) = 0;  //checks if a point lies inside the figure
	virtual Point GetOldPoint() = 0;    // returns the center of the figure when it is drawen  
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void MoveFig(Point p) = 0;             //Move Figure on the Drawing area
	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
};

#endif