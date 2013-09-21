using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace _3DModel
{
    internal static class Controls
    {
        static Texture2D mScreen;
        static SpriteFont mFont;
        static int changeWhat = 0;
        //KeyboardState ks = Keyboard.GetState();
        //Controls
        //Cast Spell
        private static Keys kSpell = Keys.Space;
        //Enter Turret
        private static Keys kTurretE = Keys.E;
        //Leave Turret
        private static Keys kTurretL = Keys.Q;
        //Read Sign
        private static Keys kRead = Keys.Enter;
        //Inventory
        private static Keys kInv = Keys.Enter;

        static public Keys getSpellKey()
        {
            return kSpell;
        }
        static public Keys getTurretEKey()
        {
            return kTurretE;
        }
        static public Keys getTurretLKey()
        {
            return kTurretL;
        }
        static public Keys getSignKey()
        {
            return kRead;
        }
        static public Keys getInvKey()
        {
            return kInv;
        }

        static public void setSpellKey(Keys key)
        {
            kSpell = key;
        }
        static public void setTurretEKey(Keys key)
        {
            kTurretE = key;
        }
        static public void setSTurretLKey(Keys key)
        {
            kTurretL = key;
        }
        static public void setSignKey(Keys key)
        {
            kRead = key;
        }
        static public void setInvKey(Keys key)
        {
            kInv = key;
        }

        static private Keys detectKeyPress(int changeWhatAgain)
        {
            if (Keyboard.GetState().IsKeyDown(Keys.Q))
                return Keys.Q;
            else if (Keyboard.GetState().IsKeyDown(Keys.W))
                return Keys.W;
            else if (Keyboard.GetState().IsKeyDown(Keys.E))
                return Keys.E;
            else if (Keyboard.GetState().IsKeyDown(Keys.R))
                return Keys.R;
            else if (Keyboard.GetState().IsKeyDown(Keys.T))
                return Keys.T;
            else if (Keyboard.GetState().IsKeyDown(Keys.Y))
                return Keys.Y;
            else if (Keyboard.GetState().IsKeyDown(Keys.U))
                return Keys.U;
            else if (Keyboard.GetState().IsKeyDown(Keys.I))
                return Keys.I;
            else if (Keyboard.GetState().IsKeyDown(Keys.O))
                return Keys.O;
            else if (Keyboard.GetState().IsKeyDown(Keys.P))
                return Keys.P;
            else if (Keyboard.GetState().IsKeyDown(Keys.A))
                return Keys.A;
            else if (Keyboard.GetState().IsKeyDown(Keys.S))
                return Keys.S;
            else if (Keyboard.GetState().IsKeyDown(Keys.D))
                return Keys.D;
            else if (Keyboard.GetState().IsKeyDown(Keys.F))
                return Keys.F;
            else if (Keyboard.GetState().IsKeyDown(Keys.G))
                return Keys.G;
            else if (Keyboard.GetState().IsKeyDown(Keys.H))
                return Keys.H;
            else if (Keyboard.GetState().IsKeyDown(Keys.J))
                return Keys.J;
            else if (Keyboard.GetState().IsKeyDown(Keys.K))
                return Keys.K;
            else if (Keyboard.GetState().IsKeyDown(Keys.L))
                return Keys.L;
            else if (Keyboard.GetState().IsKeyDown(Keys.Z))
                return Keys.Z;
            else if (Keyboard.GetState().IsKeyDown(Keys.X))
                return Keys.X;
            else if (Keyboard.GetState().IsKeyDown(Keys.C))
                return Keys.C;
            else if (Keyboard.GetState().IsKeyDown(Keys.V))
                return Keys.V;
            else if (Keyboard.GetState().IsKeyDown(Keys.B))
                return Keys.B;
            else if (Keyboard.GetState().IsKeyDown(Keys.N))
                return Keys.N;
            else if (Keyboard.GetState().IsKeyDown(Keys.M))
                return Keys.M;

            else if (Keyboard.GetState().IsKeyDown(Keys.Tab))
                return Keys.Tab;
            else if (Keyboard.GetState().IsKeyDown(Keys.CapsLock))
                return Keys.CapsLock;
            else if (Keyboard.GetState().IsKeyDown(Keys.LeftShift))
                return Keys.LeftShift;
            else if (Keyboard.GetState().IsKeyDown(Keys.LeftControl))
                return Keys.LeftControl;
            else if (Keyboard.GetState().IsKeyDown(Keys.LeftWindows))
                return Keys.LeftWindows;
            else if (Keyboard.GetState().IsKeyDown(Keys.LeftAlt))
                return Keys.LeftAlt;
            else if (Keyboard.GetState().IsKeyDown(Keys.Space))
                return Keys.Space;
            else if (Keyboard.GetState().IsKeyDown(Keys.RightAlt))
                return Keys.RightAlt;
            else if (Keyboard.GetState().IsKeyDown(Keys.RightControl))
                return Keys.RightControl;
            else if (Keyboard.GetState().IsKeyDown(Keys.RightShift))
                return Keys.RightShift;
            else if (Keyboard.GetState().IsKeyDown(Keys.Enter))
                return Keys.Enter;
            else if (Keyboard.GetState().IsKeyDown(Keys.Back))
                return Keys.Back;
            if (changeWhatAgain == 1)
                return kSpell;
            else if (changeWhatAgain == 2)
                return kTurretE;
            else if (changeWhatAgain == 3)
                return kTurretL;
            else if (changeWhatAgain == 4)
                return kRead;
            else if (changeWhatAgain == 5)
                return kInv;
            return Keys.Space;
        }

        static public void loadControls(Texture2D screen, SpriteFont font)
        {
            mScreen = screen;
            mFont = font;
        }

        static public void drawControl(SpriteBatch theSpriteBatch)
        {
            theSpriteBatch.Draw(mScreen, Vector2.Zero, Color.White);
            theSpriteBatch.DrawString(mFont, "Spell Key :" + kSpell.ToString(), new Vector2(100, 100), Color.Black);
            theSpriteBatch.DrawString(mFont, "Enter Turret Key :" + kTurretE.ToString(), new Vector2(100, 150), Color.Black);
            theSpriteBatch.DrawString(mFont, "Leave Turret Key :" + kTurretL.ToString(), new Vector2(100, 200), Color.Black);
            theSpriteBatch.DrawString(mFont, "Read Key :" + kRead.ToString(), new Vector2(100, 250), Color.Black);
            theSpriteBatch.DrawString(mFont, "Inventory Key :" + kInv.ToString(), new Vector2(100, 300), Color.Black);
            theSpriteBatch.DrawString(mFont, "Changing :" + changeWhat.ToString(), new Vector2(100, 350), Color.Black);
            theSpriteBatch.DrawString(mFont, "Mouse :" + new Vector2(Mouse.GetState().X,Mouse.GetState().Y).ToString(), new Vector2(100, 400), Color.Black);

            if (Mouse.GetState().LeftButton == ButtonState.Pressed)
            {
                if (Mouse.GetState().Y >= 100 && Mouse.GetState().Y <= 140)
                {
                    if (Mouse.GetState().X >= 100 && Mouse.GetState().X <= 600)
                        changeWhat = 1;
                }
                if (Mouse.GetState().Y >= 150 && Mouse.GetState().Y <= 190)
                {
                    if (Mouse.GetState().X >= 100 && Mouse.GetState().X <= 600)
                        changeWhat = 2;
                }
                if (Mouse.GetState().Y >= 200 && Mouse.GetState().Y <= 240)
                {
                    if (Mouse.GetState().X >= 100 && Mouse.GetState().X <= 600)
                        changeWhat = 3;
                }
                if (Mouse.GetState().Y >= 250 && Mouse.GetState().Y <= 290)
                {
                    if (Mouse.GetState().X >= 100 && Mouse.GetState().X <= 600)
                        changeWhat = 4;
                }
                if (Mouse.GetState().Y >= 300 && Mouse.GetState().Y <= 340)
                {
                    if (Mouse.GetState().X >= 100 && Mouse.GetState().X <= 600)
                        changeWhat = 5;
                }
            }

            if (changeWhat == 1)
            {
                kSpell = detectKeyPress(changeWhat);
            }
            else if (changeWhat == 2)
            {
                kTurretE = detectKeyPress(changeWhat);
            }
            else if (changeWhat == 3)
            {
                kTurretL = detectKeyPress(changeWhat);
            }
            else if (changeWhat == 4)
            {
                kRead = detectKeyPress(changeWhat);
            }
            else if (changeWhat == 5)
            {
                kInv = detectKeyPress(changeWhat);
            }

        }
    }
}