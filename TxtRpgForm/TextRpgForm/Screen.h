#ifndef Screen
#define Screen
	void loadLine(int whatLine,string changeLine);
	void setBoarder(int x, int y, int mX,int mY, int mXTwo,int mYTwo, int mXThree, int mYThree);
	void updateLines(int x, int y, int mX,int mY, int mXTwo,int mYTwo, int mXThree, int mYThree);
	void getLoc(int loc);
	int getWindowSize();
	void setWindowSize(int change);
	string getLine(int which);
	bool getWall(int x,int y);
	int getPortalX(int which);
	int getPortalY(int which);
#endif