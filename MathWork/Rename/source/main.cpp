//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>


const int iScreenWidth = 1280;
const int iScreenHeight = 780;

//Declaring an enum for Game States
typedef enum GameStates
{
	GET_USER_INPUT,
	GAME_STATE,
	END
}GameState;

struct Tile
{
	float fXPos;
	float fYPos;
	unsigned int iSpriteID;
};

int main( int argc, char* argv[] )
{	
	int iTileWidth = 0;
	int iTileHeight = 0;
	int iLevelWidth = 0;
	int iLevelHeight = 0;
	unsigned int iLevelSize = 0;

	float fYOffset = 0.f;

	Tile* pGameTiles = nullptr;

	GameState eCurrentState = GET_USER_INPUT;
	srand( time(NULL) );
	
	do 
	{
		
		//Test the current game state
		switch(eCurrentState)
		{
		case GET_USER_INPUT:
		{
			//\======================================================================
			//\ Get some user input to find out the tile size we want for our level
			//\======================================================================
			std::cout << "Please enter the tile Width: ";
			std::cin >> iTileWidth;
			std::cout << std::endl;
			
			std::cout << "Please enter the tile Height: ";
			std::cin >> iTileHeight;
			std::cout << std::endl;
			//\======================================================================
			//\ Get some user input regarding the level size (note two rows will be drawn off screen
			//\ as a scrolling buffer for the height)
			//\
			//\    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx		- rows marked with an x are not visible
			//\    00000000000000000000000000000000000		- rows marked with a 0 are in our view
			//\    00000000000000000000000000000000000
			//\    00000000000000000000000000000000000
			//\    00000000000000000000000000000000000
			//\    00000000000000000000000000000000000
			//\    00000000000000000000000000000000000
			//\    00000000000000000000000000000000000
			//\    xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
			//\
			//\======================================================================

			std::cout << "Please enter the Level Grid Width: ";
			std::cin >> iLevelWidth;
			std::cout << std::endl;
			
			std::cout << "Please enter the Level Grid Height: ";
			std::cin >> iLevelHeight;
			std::cout << std::endl;

			// First we need to create our Game Framework
			unsigned int iVisibleLevelHeight = (iLevelHeight * iTileHeight) - (2 * iTileHeight);
			unsigned int iVisibleLevelWidth = iLevelWidth * iTileWidth;
			Initialise( iVisibleLevelWidth, iVisibleLevelHeight , false, "Pong!" );
			unsigned int iSprite = CreateSprite( "./images/crate_sideup.png", iTileWidth, iTileHeight, false );
			iLevelSize = iLevelHeight * iLevelWidth;
			pGameTiles = new Tile[iLevelSize];
			for( int i = 0; i < iLevelSize; ++i )
			{
				pGameTiles[i].fXPos = (float)iTileWidth * (float)(i % iLevelWidth);
				pGameTiles[i].fYPos = (float)iTileHeight * ( (float)( (i/iLevelWidth) -1 ));
				pGameTiles[i].iSpriteID = iSprite;
			}
	
			eCurrentState = GAME_STATE;
			break;
		}
		
		case GAME_STATE:
		{
			float fDeltaT = GetDeltaTime();
			ClearScreen();
			if( IsKeyDown('W') )
			{
					fYOffset = 1.f;
			}

			for( int i = 0; i < iLevelSize; ++i )
			{
				pGameTiles[i].fYPos += fYOffset;
				if( pGameTiles[i].fYPos >= iTileHeight * (iLevelHeight-1) )
				{
					pGameTiles[i].fYPos = -iTileHeight;
				}

				MoveSprite( pGameTiles[i].iSpriteID, pGameTiles[i].fXPos, pGameTiles[i].fYPos );
				DrawSprite( pGameTiles[i].iSpriteID );
			}
			
			break;
		}
		default:
			break;
		}//End of Switch Statement


	} while ( FrameworkUpdate() == false );
	
	for( int i = 0; i < iLevelSize; ++i )
	{
		DestroySprite(pGameTiles[i].iSpriteID);
	}
	Shutdown();

	return 0;
}

