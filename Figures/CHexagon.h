#ifndef CHEX_H
#define CHEX_H

#include"DEFS.h"
#include "Figures/CFigure.h"
#include "GUI/Output.h"

class CHexagon :public CFigure
{
private:
	Point center;   //hexagon center
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	CHexagon();
	virtual void Draw(Output* pOut) const;
	virtual bool insidefig(int x,int y);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void MoveFig(Point p);
	virtual Point GetOldPoint();
	void PrintInfo(Output* pOut);
};






#endif