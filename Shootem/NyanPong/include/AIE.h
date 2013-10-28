//////////////////////////////////////////////////////////////////////////
//	Author:	Jamie Stewart
//	Date:	12/11/2012
//	Brief:	This is the main entry point for access to the functionality provided by the
//			AIE Static OpenGL Framework.
//////////////////////////////////////////////////////////////////////////
#ifndef _AIE_H_
#define _AIE_H_
//////////////////////////////////////////////////////////////////////////

#define DLLEXPORT __declspec(dllexport)

const unsigned int KEY_SPACE		=	 32;
const unsigned int KEY_ESC		    =	257;

//////////////////////////////////////////////////////////////////////////
//Removed the "DLLEXPORT" from before the struct;
//Its used as a way of declaring structs in c not c++
struct SColour
{
	DLLEXPORT SColour() {}
	DLLEXPORT SColour(unsigned int a_iColour) : colour(a_iColour) { }
	DLLEXPORT SColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		colours.r = r;
		colours.g = g;
		colours.b = b;
		colours.a = a;
	}

	union
	{
		unsigned int colour;
		struct SColours
		{
			unsigned char a, r, g, b;
		} colours;
	};
};

//////////////////////////////////////////////////////////////////////////
// Call this function to initialise the framework
//////////////////////////////////////////////////////////////////////////
DLLEXPORT int			Initialise( int a_iWidth, int a_iHeight, bool a_bFullscreen = false );
DLLEXPORT void			Shutdown();
DLLEXPORT bool			FrameworkUpdate();
DLLEXPORT void			ClearScreen();
DLLEXPORT void			SetRenderColour( float a_fRed, float a_fGreen, float a_fBlue, float a_fAlpha = 1.f );

//////////////////////////////////////////////////////////////////////////
// Basic Sprite creation and manipulation functionality
//////////////////////////////////////////////////////////////////////////
DLLEXPORT unsigned int	CreateSprite( const char* a_pTextureName, int a_iWidth, int a_iHeight, bool a_bDrawFromCenter = true );
DLLEXPORT void			MoveSprite( unsigned int a_uiSpriteID, int a_iXPos, int a_iYPos );
DLLEXPORT void			RotateSprite( unsigned int a_uiSpriteID, int a_iRotation );
DLLEXPORT void			DestroySprite( unsigned int a_uiSpriteID );
DLLEXPORT void			DrawSprite( unsigned int a_uiSpriteID );

//////////////////////////////////////////////////////////////////////////
// Basic Line Drawing Functionality
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY );
DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY, SColour a_sColour );
DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY, SColour a_sStartColour, SColour a_sEndColour );

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			DrawString( const char* a_pText, int a_iXPos, int a_iYPos, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF));

//////////////////////////////////////////////////////////////////////////
// Input Handling Functionality
//////////////////////////////////////////////////////////////////////////
DLLEXPORT bool			IsKeyDown( int a_iKey );
DLLEXPORT void			GetMouseLocation( int& a_iMouseX, int& a_iMouseY );
DLLEXPORT bool			GetMouseButtonDown( int a_iMouseButtonToTest );

//////////////////////////////////////////////////////////////////////////
#endif //_AIE_H_
//////////////////////////////////////////////////////////////////////////