#ifndef CSQUARE_H
#define CSQUARE_H

#include"DEFS.h"
#include "Figures/CFigure.h"
#include "GUI/Output.h"


class CSquare :public CFigure
{
private:
	Point center;  //square center
public:
	CSquare( Point,GfxInfo FigureGfxInfo);
	CSquare();
	virtual void Draw(Output* pOut) const;
	virtual bool insidefig(int x,int y);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual Point GetOldPoint();
	virtual void MoveFig(Point p);
	void PrintInfo(Output* pOut);
};



#endif