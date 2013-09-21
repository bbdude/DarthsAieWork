using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;


namespace _3DModel
{
    class MainMenu
    {
        float symbolPosManager;
        float slidePosManager;
        Rectangle alteredPos;
        bool slide;
        bool partTwoActive = false;

        Texture2D slideTex;
        Texture2D symbolTex;
        Texture2D mainTex;

        public MainMenu(Texture2D theSlideTex, Texture2D theSymbolTex,Texture2D theMainTex)
        {
            slideTex = theSlideTex;
            symbolTex = theSymbolTex;
            mainTex = theMainTex;
            symbolPosManager = 0f;
            slidePosManager = 0f;
            slide = false;
        }
        public bool updateMainMenu()
        {
            if (!partTwoActive)
            {
                if (Keyboard.GetState().IsKeyDown(Keys.Space) && !slide)
                {
                    slide = true;
                }
                if (slide)
                {
                    if (slidePosManager >= 600)
                        partTwoActive = true;
                    else if (symbolPosManager >= 375f)
                        slidePosManager = slidePosManager + 5f;
                    else
                        symbolPosManager = symbolPosManager + 5f;
                    Console.Write(symbolPosManager.ToString());

                }
            }
            else
            {
                if (new Rectangle(521, 33, 734 - 521, 90 - 33).Intersects(new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 1, 1)))
                {
                    alteredPos = new Rectangle(521 - (int)symbolTex.Width, 33, (int)symbolTex.Width, (int)symbolTex.Height);
                    if (Mouse.GetState().LeftButton == ButtonState.Pressed)
                        return true;
                }
                else if (new Rectangle(521, 99, 734 - 521, 192 - 99).Intersects(new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 1, 1)))
                {
                    alteredPos = new Rectangle(521 - (int)symbolTex.Width, 110, (int)symbolTex.Width, (int)symbolTex.Height);
                }
                else if (new Rectangle(521, 200, 734 - 521, 260 - 200).Intersects(new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 1, 1)))
                {
                    alteredPos = new Rectangle(521 - (int)symbolTex.Width, 207, (int)symbolTex.Width, (int)symbolTex.Height);
                }
            }
            if (Keyboard.GetState().IsKeyDown(Keys.Space))
                Console.Write("(" + Mouse.GetState().X + "'" + Mouse.GetState().Y + ")");
            return false;
        }
        public void drawMainMenu(SpriteBatch theSpriteBatch)
        {
            theSpriteBatch.Begin();
            theSpriteBatch.Draw(mainTex, new Rectangle(0, 0, 800, 500), Color.White);
            if (!partTwoActive)
            {
                theSpriteBatch.Draw(slideTex, new Vector2(0, 0 - slidePosManager), Color.White);
                //theSpriteBatch.Draw(symbolTex, new Vector2(325 - symbolPosManager, 400), Color.White);
                //theSpriteBatch.Draw(symbolTex, new Vector2(425 + symbolPosManager, 400), Color.White,Color.White,0f,Vector2.Zero,SpriteEffects.FlipHorizontally,0);
                theSpriteBatch.Draw(symbolTex, new Rectangle(425 + (int)symbolPosManager, 400, (int)symbolTex.Width, (int)symbolTex.Height), null, Color.White, 0f, Vector2.Zero, SpriteEffects.FlipHorizontally, 0);
                theSpriteBatch.Draw(symbolTex, new Rectangle(325 - (int)symbolPosManager, 400, (int)symbolTex.Width, (int)symbolTex.Height), null, Color.White, 0f, Vector2.Zero, SpriteEffects.None, 0);
            }
            else
            {
                theSpriteBatch.Draw(symbolTex, alteredPos, null, Color.White, 0f, Vector2.Zero, SpriteEffects.FlipHorizontally, 0);
                theSpriteBatch.Draw(symbolTex, new Rectangle(325 - (int)symbolPosManager, 400, (int)symbolTex.Width, (int)symbolTex.Height), null, Color.White, 0f, Vector2.Zero, SpriteEffects.None, 0);
            }
            theSpriteBatch.End();
        }
    }
}
