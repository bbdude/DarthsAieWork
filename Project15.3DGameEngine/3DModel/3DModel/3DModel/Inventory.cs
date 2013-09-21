using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace _3DModel
{
    class Inventory
    {
        private Texture2D mTotalGUI;
        private Texture2D mHealthBar;
        private Texture2D mManaBar;
        private Texture2D mInvBoxes;
        private Texture2D mMap;
        private Texture2D mSpellBook;
        private Texture2D mSelection;
        private Texture2D mSmallMap;
        private Texture2D mSmallPlayer;
        private SpriteFont mFont;

        private Texture2D mHead;
        private Texture2D mLeftArm;
        private Texture2D mRightArm;
        private Texture2D mChest;
        private Texture2D mLegs;
        private Texture2D mLeftFoot;
        private Texture2D mRightFoot;

        private Vector2 selctionINVPos;
        private Vector2 selctionPos;
        private Vector2 selectionSize;
        private Vector2 playerPos;
        private int whatScreen;
        private int Health = 100;
        private int Mana = 100;
        private int Score = 0;
        private float DMG;
        private float DEF;
        private float MAG;
        private bool questOne;
        private bool questTwo;
        private bool questThree;
        private bool questFour;
        private bool click = false;
        private int howManyInInv;

        private enum HEAD { NONE, INV, BASIC, ADVANCED };

        private enum LEFTARM { NONE, INV, BASIC, ADVANCED };

        private enum RIGHTARM { NONE, INV, BASIC, ADVANCED };

        private enum CHEST { NONE, INV, BASIC, ADVANCED };

        private enum LEGS { NONE, INV, BASIC, ADVANCED };

        private enum LEFTLEG { NONE, INV, BASIC, ADVANCED };

        private enum RIGHTLEG { NONE, INV, BASIC, ADVANCED };

        private HEAD currHead = HEAD.NONE;
        private LEFTARM currLeftArm = LEFTARM.NONE;
        private RIGHTARM currRightArm = RIGHTARM.NONE;
        private CHEST currChest = CHEST.NONE;
        private LEGS currLegs = LEGS.NONE;
        private LEFTLEG currLeftLeg = LEFTLEG.NONE;
        private RIGHTLEG currRightLeg = RIGHTLEG.NONE;

        public Inventory(SpriteFont Font, Texture2D TotalGUI, Texture2D HealthBar, Texture2D ManaBar, Texture2D InvBoxes, Texture2D Map, Texture2D SpellBook, Texture2D Selction, Texture2D SmallMap, Texture2D SmallPlayer, Texture2D Head, Texture2D LeftArm, Texture2D RightArm, Texture2D Chest, Texture2D Legs, Texture2D LeftFoot, Texture2D RightFoot)
        {
            mTotalGUI = TotalGUI;
            mHealthBar = HealthBar;
            mManaBar = ManaBar;
            mInvBoxes = InvBoxes;
            mMap = Map;
            mFont = Font;
            mSpellBook = SpellBook;
            mSelection = Selction;
            whatScreen = 0;
            selctionPos = new Vector2(-100, -100);
            selectionSize = Vector2.Zero;
            playerPos = Vector2.Zero;
            DMG = 1;
            DEF = 1;
            MAG = 1;
            questOne = false;
            questTwo = false;
            questThree = false;
            questFour = false;
            mSmallMap = SmallMap;
            mSmallPlayer = SmallPlayer;

            mHead = Head;
            mLeftArm = LeftArm;
            mRightArm = RightArm;
            mChest = Chest;
            mLegs = Legs;
            mLeftFoot = LeftFoot;
            mRightFoot = RightFoot;
        }

        public void drawGUI(SpriteBatch theSpriteBatch, int healthAmount, int manaAmount)
        {
            theSpriteBatch.Begin();
            int def = 0, mag = 0, dmg = 0;

            if (currHead == HEAD.BASIC)
                def++;
            else if (currHead == HEAD.ADVANCED)
                def += 2;
            if (currLeftArm == LEFTARM.BASIC)
                dmg++;
            else if (currLeftArm == LEFTARM.ADVANCED)
                dmg += 2;
            if (currRightArm == RIGHTARM.BASIC)
                mag++;
            else if (currRightArm == RIGHTARM.ADVANCED)
                mag += 2;
            if (currChest == CHEST.BASIC)
                def++;
            else if (currChest == CHEST.ADVANCED)
                def += 2;
            if (currLegs == LEGS.BASIC)
                mag++;
            else if (currLegs == LEGS.ADVANCED)
                def += 2;
            if (currLeftLeg == LEFTLEG.BASIC)
                def++;
            else if (currLeftLeg == LEFTLEG.ADVANCED)
                def += 2;
            if (currRightLeg == RIGHTLEG.BASIC)
                def++;
            else if (currRightLeg == RIGHTLEG.ADVANCED)
                def += 2;

            Health = healthAmount;
            Mana = manaAmount;

            theSpriteBatch.Draw(mTotalGUI, new Rectangle(0, 0, mTotalGUI.Width, mTotalGUI.Height), Color.White);

            if (Mouse.GetState().LeftButton == ButtonState.Pressed)
            {
                if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 2, 2).Intersects(new Rectangle(20, 25, 178 - 20, 83 - 20)))
                {
                    whatScreen = 1;
                }
                else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 2, 2).Intersects(new Rectangle(177, 25, 178 - 20, 83 - 20)))
                {
                    whatScreen = 2;
                }
                else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 2, 2).Intersects(new Rectangle(329, 25, 178 - 20, 83 - 20)))
                {
                    whatScreen = 3;
                }
                else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 2, 2).Intersects(new Rectangle(480, 25, 178 - 20, 83 - 20)))
                {
                    whatScreen = 4;
                }
                else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 2, 2).Intersects(new Rectangle(625, 25, 178 - 20, 83 - 20)))
                {
                    whatScreen = 5;
                }
            }
            switch (whatScreen)
            {
                case 1:
                    //Inv
                    theSpriteBatch.Draw(mInvBoxes, new Rectangle(0, 0, mInvBoxes.Width, mInvBoxes.Height), Color.White);

                    //Setting inv position
                    howManyInInv = 0;
                    int howManyRows = 0;
                    int places = 0;
                    string[] whatWhere = new string[7] { "null", "null", "null", "null", "null", "null", "null" };
                    howManyRows = setRows(howManyInInv);
                    if (currHead == HEAD.INV)
                    {
                        whatWhere[places] = "head";
                        places++;
                        howManyInInv++;
                        theSpriteBatch.Draw(mHead, new Rectangle(420 + (160 * (setColumns(howManyInInv) - 1)), 134 + (80 * (howManyRows - 1)), 229 - 162, 186 - 131), Color.White);
                    }
                    howManyRows = setRows(howManyInInv);
                    if (currLeftArm == LEFTARM.INV)
                    {
                        whatWhere[places] = "leftarm";
                        places++;
                        howManyInInv++;
                        theSpriteBatch.Draw(mLeftArm, new Rectangle(420 + (160 * (setColumns(howManyInInv) - 1)), 134 + (80 * (howManyRows - 1)), 98 - 52, 225 - 184), Color.White);
                    }
                    howManyRows = setRows(howManyInInv);
                    if (currRightArm == RIGHTARM.INV)
                    {
                        whatWhere[places] = "rightarm";
                        places++;
                        howManyInInv++;
                        theSpriteBatch.Draw(mRightArm, new Rectangle(420 + (160 * (setColumns(howManyInInv) - 1)), 134 + (80 * (howManyRows - 1)), 339 - 288, 223 - 177), Color.White);
                    }
                    howManyRows = setRows(howManyInInv);
                    if (currChest == CHEST.INV)
                    {
                        whatWhere[places] = "chest";
                        places++;
                        howManyInInv++;
                        theSpriteBatch.Draw(mChest, new Rectangle(420 + (160 * (setColumns(howManyInInv) - 1)), 134 + (80 * (howManyRows - 1)), 255 - 139, 302 - 223), Color.White);
                    }
                    howManyRows = setRows(howManyInInv);
                    if (currLegs == LEGS.INV)
                    {
                        whatWhere[places] = "legs";
                        places++;
                        howManyInInv++;
                        theSpriteBatch.Draw(mLegs, new Rectangle(420 + (160 * (setColumns(howManyInInv) - 1)), 134 + (80 * (howManyRows - 1)), 258 - 138, 376 - 317), Color.White);
                    }
                    howManyRows = setRows(howManyInInv);
                    if (currLeftLeg == LEFTLEG.INV)
                    {
                        whatWhere[places] = "leftleg";
                        places++;
                        howManyInInv++;
                        theSpriteBatch.Draw(mLeftFoot, new Rectangle(420 + (160 * (setColumns(howManyInInv) - 1)), 134 + (80 * (howManyRows - 1)), 162 - 105, 467 - 400), Color.White);
                    }
                    howManyRows = setRows(howManyInInv);
                    if (currRightLeg == RIGHTLEG.INV)
                    {
                        whatWhere[places] = "rightleg";
                        places++;
                        howManyInInv++;
                        theSpriteBatch.Draw(mRightFoot, new Rectangle(420 + (160 * (setColumns(howManyInInv) - 1)), 134 + (80 * (howManyRows - 1)), 275 - 207, 466 - 402), Color.White);
                    }
                    howManyRows = setRows(howManyInInv);

                    //Equipment
                    //Head
                    if (currHead == HEAD.BASIC)
                    {
                        theSpriteBatch.Draw(mHead, new Rectangle(162, 131, 229 - 162, 186 - 131), Color.White);
                    }
                    //Left Arm
                    if (currLeftArm == LEFTARM.BASIC)
                    {
                        theSpriteBatch.Draw(mLeftArm, new Rectangle(52, 184, 98 - 52, 225 - 184), Color.White);
                    }
                    //Right Arm
                    if (currRightArm == RIGHTARM.BASIC)
                    {
                        theSpriteBatch.Draw(mRightArm, new Rectangle(288, 177, 339 - 288, 223 - 177), Color.White);
                    }
                    //Chest Piece
                    if (currChest == CHEST.BASIC)
                    {
                        theSpriteBatch.Draw(mChest, new Rectangle(139, 223, 255 - 139, 302 - 223), Color.White);
                    }
                    //Waist
                    if (currLegs == LEGS.BASIC)
                    {
                        theSpriteBatch.Draw(mLegs, new Rectangle(138, 317, 258 - 138, 376 - 317), Color.White);
                    }
                    //Left Leg
                    if (currLeftLeg == LEFTLEG.BASIC)
                    {
                        theSpriteBatch.Draw(mLeftFoot, new Rectangle(105, 400, 162 - 105, 467 - 400), Color.White);
                    }
                    //Right Leg
                    if (currRightLeg == RIGHTLEG.BASIC)
                    {
                        theSpriteBatch.Draw(mRightFoot, new Rectangle(207, 402, 275 - 207, 466 - 402), Color.White);
                    }
                    if (Mouse.GetState().LeftButton == ButtonState.Pressed)
                    {
                        click = true;
                    }
                    else if (click)
                    {
                        click = false;
                        setSelection();
                        moveInv(whatWhere[0], whatWhere[1], whatWhere[2], whatWhere[3], whatWhere[4], whatWhere[5], whatWhere[6], howManyRows);
                    }
                    theSpriteBatch.Draw(mSelection, new Rectangle((int)selctionINVPos.X, (int)selctionINVPos.Y, (int)selectionSize.X, (int)selectionSize.Y), Color.White);

                    break;

                case 2:
                    //Stats
                    theSpriteBatch.Draw(mHealthBar, new Rectangle(100, 100, (int)((mHealthBar.Width / 2) * ((double)Health / 100)) - 10, 40), new Rectangle(0, 45, mHealthBar.Width, 44), Color.Red);
                    theSpriteBatch.Draw(mHealthBar, new Rectangle(100, 100, mHealthBar.Width / 2, 44), new Rectangle(0, 0, mHealthBar.Width, 44), Color.White);

                    theSpriteBatch.Draw(mHealthBar, new Rectangle(100, 200, (int)((mHealthBar.Width / 2) * ((double)Mana / 100)) - 10, 40), new Rectangle(0, 45, mHealthBar.Width, 44), Color.Blue);
                    theSpriteBatch.Draw(mHealthBar, new Rectangle(100, 200, mHealthBar.Width / 2, 44), new Rectangle(0, 0, mHealthBar.Width, 44), Color.White);

                    theSpriteBatch.DrawString(mFont, "DMG: " + dmg, new Vector2(100, 250), Color.White);
                    theSpriteBatch.DrawString(mFont, "DEF: " + def, new Vector2(100, 300), Color.White);
                    theSpriteBatch.DrawString(mFont, "MAG: " + mag, new Vector2(100, 350), Color.White);
                    theSpriteBatch.DrawString(mFont, "Score: " + Score, new Vector2(100, 400), Color.White);
                    //theSpriteBatch.Draw(mTotalGUI, Rectangle.Empty, Color.White);
                    break;

                case 3:
                    //Quests
                    theSpriteBatch.DrawString(mFont, "1:" + returnQuestText(1), new Vector2(120, 100), Color.Black, 0, Vector2.Zero, 1, SpriteEffects.None, 0);
                    theSpriteBatch.DrawString(mFont, "2:" + returnQuestText(2), new Vector2(120, 175), Color.Black, 0, Vector2.Zero, 1, SpriteEffects.None, 0);
                    theSpriteBatch.DrawString(mFont, "3:" + returnQuestText(3), new Vector2(120, 250), Color.Black, 0, Vector2.Zero, 1, SpriteEffects.None, 0);
                    theSpriteBatch.DrawString(mFont, "4:" + returnQuestText(4), new Vector2(120, 320), Color.Black, 0, Vector2.Zero, 1, SpriteEffects.None, 0);
                    break;

                case 4:
                    //Map
                    Vector2 newSpot = new Vector2(((playerPos.X / 500) * 100) + 150, ((playerPos.Y / 300) * 100) + 150);
                    theSpriteBatch.Draw(mMap, new Rectangle(0, 0, mMap.Width, mMap.Height), Color.White);
                    theSpriteBatch.Draw(mSmallMap, new Rectangle(150, 150, 500, 300), Color.White);
                    theSpriteBatch.Draw(mSmallPlayer, newSpot, Color.White);
                    //theSpriteBatch.DrawString(mFont, newSpot.ToString(), new Vector2(50, 350), Color.Black);
                    break;

                case 5:
                    //Spells
                    theSpriteBatch.Draw(mSpellBook, new Rectangle(0, 0, mSpellBook.Width, mSpellBook.Height), Color.White);
                    theSpriteBatch.DrawString(mFont, "Area freeze spell", new Vector2(50, 150), Color.Black);
                    theSpriteBatch.DrawString(mFont, "Area bleed spell(N/A)", new Vector2(50, 250), Color.Black);
                    theSpriteBatch.DrawString(mFont, "Fire ball(N/A)", new Vector2(50, 350), Color.Black);
                    theSpriteBatch.Draw(mSelection, selctionPos, Color.White);
                    if (Mouse.GetState().LeftButton == ButtonState.Pressed)
                        setSelection();
                    break;

                default:
                    break;
            }

            theSpriteBatch.DrawString(mFont, Mouse.GetState().X + "," + Mouse.GetState().Y, Vector2.Zero, Color.White);
            theSpriteBatch.End();
        }
        
        public bool returnGUI()
        {
            return (whatScreen != 0);
        }

        public void changeUp(bool change)
        {
            if (change)
                whatScreen = 0;
            else
                whatScreen = 2;
        }

        public int getSpell()
        {
            switch ((int)selctionPos.Y)
            {
                case 150:
                    return 1;
                case 250:
                    return 2;
                case 350:
                    return 3;
                default:
                    return 1;
            }
        }

        private void moveInv(string partOne, string partTwo, string partThree, string partFour, string partFive, string partSix, string partSeven, int howManyRows)
        {
            //FIRST
            if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(420 + (160 * 0), 134 + (80 * (0)), 229 - 162, 186 - 131)))
            {
                switch (partOne)
                {
                    case "head":
                        currHead = HEAD.BASIC;
                        break;

                    case "leftarm":
                        currLeftArm = LEFTARM.BASIC;
                        break;

                    case "rightarm":
                        currRightArm = RIGHTARM.BASIC;
                        break;

                    case "chest":
                        currChest = CHEST.BASIC;
                        break;

                    case "legs":
                        currLegs = LEGS.BASIC;
                        break;

                    case "leftleg":
                        currLeftLeg = LEFTLEG.BASIC;
                        break;

                    case "rightleg":
                        currRightLeg = RIGHTLEG.BASIC;
                        break;

                    default:
                        break;
                }
            }//Second
            if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(420 + (160 * 1), 134 + (80 * (0)), 98 - 52, 225 - 184)))
            {
                switch (partTwo)
                {
                    case "head":
                        currHead = HEAD.BASIC;
                        break;

                    case "leftarm":
                        currLeftArm = LEFTARM.BASIC;
                        break;

                    case "rightarm":
                        currRightArm = RIGHTARM.BASIC;
                        break;

                    case "chest":
                        currChest = CHEST.BASIC;
                        break;

                    case "legs":
                        currLegs = LEGS.BASIC;
                        break;

                    case "leftleg":
                        currLeftLeg = LEFTLEG.BASIC;
                        break;

                    case "rightleg":
                        currRightLeg = RIGHTLEG.BASIC;
                        break;

                    default:
                        break;
                }
            }
            //Third
            if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(420 + (160 * 0), 134 + (80 * (1)), 339 - 288, 223 - 177)))
            {
                switch (partThree)
                {
                    case "head":
                        currHead = HEAD.BASIC;
                        break;

                    case "leftarm":
                        currLeftArm = LEFTARM.BASIC;
                        break;

                    case "rightarm":
                        currRightArm = RIGHTARM.BASIC;
                        break;

                    case "chest":
                        currChest = CHEST.BASIC;
                        break;

                    case "legs":
                        currLegs = LEGS.BASIC;
                        break;

                    case "leftleg":
                        currLeftLeg = LEFTLEG.BASIC;
                        break;

                    case "rightleg":
                        currRightLeg = RIGHTLEG.BASIC;
                        break;

                    default:
                        break;
                }
            }
            //Fourth
            if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(420 + (160 * 1), 134 + (80 * (1)), 255 - 139, 302 - 223)))
            {
                switch (partFour)
                {
                    case "head":
                        currHead = HEAD.BASIC;
                        break;

                    case "leftarm":
                        currLeftArm = LEFTARM.BASIC;
                        break;

                    case "rightarm":
                        currRightArm = RIGHTARM.BASIC;
                        break;

                    case "chest":
                        currChest = CHEST.BASIC;
                        break;

                    case "legs":
                        currLegs = LEGS.BASIC;
                        break;

                    case "leftleg":
                        currLeftLeg = LEFTLEG.BASIC;
                        break;

                    case "rightleg":
                        currRightLeg = RIGHTLEG.BASIC;
                        break;

                    default:
                        break;
                }
            }
            //Fifth
            if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(420 + (160 * 0), 134 + (80 * (2)), 258 - 138, 376 - 317)))
            {
                switch (partFive)
                {
                    case "head":
                        currHead = HEAD.BASIC;
                        break;

                    case "leftarm":
                        currLeftArm = LEFTARM.BASIC;
                        break;

                    case "rightarm":
                        currRightArm = RIGHTARM.BASIC;
                        break;

                    case "chest":
                        currChest = CHEST.BASIC;
                        break;

                    case "legs":
                        currLegs = LEGS.BASIC;
                        break;

                    case "leftleg":
                        currLeftLeg = LEFTLEG.BASIC;
                        break;

                    case "rightleg":
                        currRightLeg = RIGHTLEG.BASIC;
                        break;

                    default:
                        break;
                }
            }
            //Sixth
            if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(420 + (160 * 1), 134 + (80 * (2)), 162 - 105, 467 - 400)))
            {
                switch (partSix)
                {
                    case "head":
                        currHead = HEAD.BASIC;
                        break;

                    case "leftarm":
                        currLeftArm = LEFTARM.BASIC;
                        break;

                    case "rightarm":
                        currRightArm = RIGHTARM.BASIC;
                        break;

                    case "chest":
                        currChest = CHEST.BASIC;
                        break;

                    case "legs":
                        currLegs = LEGS.BASIC;
                        break;

                    case "leftleg":
                        currLeftLeg = LEFTLEG.BASIC;
                        break;

                    case "rightleg":
                        currRightLeg = RIGHTLEG.BASIC;
                        break;

                    default:
                        break;
                }
            }
            //Seventh
            if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(420 + (160 * 0), 134 + (80 * (3)), 275 - 207, 466 - 402)))
            {
                switch (partSeven)
                {
                    case "head":
                        currHead = HEAD.BASIC;
                        break;

                    case "leftarm":
                        currLeftArm = LEFTARM.BASIC;
                        break;

                    case "rightarm":
                        currRightArm = RIGHTARM.BASIC;
                        break;

                    case "chest":
                        currChest = CHEST.BASIC;
                        break;

                    case "legs":
                        currLegs = LEGS.BASIC;
                        break;

                    case "leftleg":
                        currLeftLeg = LEFTLEG.BASIC;
                        break;

                    case "rightleg":
                        currRightLeg = RIGHTLEG.BASIC;
                        break;

                    default:
                        break;
                }
            }
        }

        private void setSelection()
        {
            switch (whatScreen)
            {
                case 1:
                    //Head
                    if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(162, 131, 229 - 162, 186 - 131)))
                    {
                        selctionINVPos = new Vector2(162, 131);
                        selectionSize = new Vector2(229 - 162, 186 - 131);
                    }
                    //Right Arm
                    else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(52, 184, 98 - 52, 225 - 184)))
                    {
                        selctionINVPos = new Vector2(52, 184);
                        selectionSize = new Vector2(98 - 52, 225 - 184);
                    }
                    //Left Arm
                    else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(288, 177, 339 - 288, 223 - 177)))
                    {
                        selctionINVPos = new Vector2(288, 177);
                        selectionSize = new Vector2(339 - 288, 223 - 177);
                    }
                    //Chest Piece
                    else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(139, 223, 255 - 139, 302 - 223)))
                    {
                        selctionINVPos = new Vector2(139, 223);
                        selectionSize = new Vector2(255 - 139, 302 - 223);
                    }
                    //Waist
                    else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(138, 317, 258 - 138, 376 - 317)))
                    {
                        selctionINVPos = new Vector2(138, 317);
                        selectionSize = new Vector2(258 - 138, 376 - 317);
                    }
                    //Left Leg
                    else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(105, 400, 162 - 105, 467 - 400)))
                    {
                        selctionINVPos = new Vector2(105, 400);
                        selectionSize = new Vector2(162 - 105, 467 - 400);
                    }
                    //Right Leg
                    else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 5, 5).Intersects(new Rectangle(207, 402, 275 - 207, 466 - 402)))
                    {
                        selctionINVPos = new Vector2(207, 402);
                        selectionSize = new Vector2(275 - 207, 466 - 402);
                    }
                    break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    break;

                case 5:

                    if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 800, 40).Intersects(new Rectangle(50, 150, 800, 90)))
                    {
                        selctionPos = new Vector2(50, 150);
                    }
                    else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 800, 40).Intersects(new Rectangle(50, 250, 800, 90)))
                    {
                        selctionPos = new Vector2(50, 250);
                    }
                    else if (new Rectangle(Mouse.GetState().X, Mouse.GetState().Y, 800, 40).Intersects(new Rectangle(50, 350, 800, 90)))
                    {
                        selctionPos = new Vector2(50, 350);
                    }
                    break;

                default:
                    break;
            }
        }

        public void setStats(float dmg, float def, float mag)
        {
            DMG = dmg;
            def = DEF;
            MAG = mag;
        }

        public void updateQuest(int choice, bool turnIt)
        {
            switch (choice)
            {
                case 1:
                    questOne = turnIt;
                    break;

                case 2:
                    questTwo = turnIt;
                    break;

                case 3:
                    questThree = turnIt;
                    break;

                case 4:
                    questFour = turnIt;
                    break;

                default:
                    Console.Write("You have chosen to change a quest that doesn't exist");
                    break;
            }
        }

        public bool checkQuest(int choice)
        {
            switch (choice)
            {
                case 1:
                    return questOne;
                case 2:
                    return questTwo;
                case 3:
                    return questThree;
                case 4:
                    return questFour;
                default:
                    Console.Write("You are trying to check a quest that doesn't exist");
                    break;
            }
            return false;
        }

        public string returnQuestText(int choice)
        {
            string text = "";
            switch (choice)
            {
                case 1:
                    if (!questOne)
                        text = "Escape the 1st tutorial field by killing the Witch";
                    break;

                case 2:
                    if (!questTwo)
                        text = "Escape the 2st tutorial field by killing the Witch and the archer";
                    break;

                case 3:
                    break;

                case 4:
                    break;

                default:
                    Console.Write("You are trying to get a quest text that doesn't exist");
                    break;
            }
            if (text == "")
                text = "Completed!";
            return text;
        }

        public void getPlayerPos(Vector2 pos)
        {
            playerPos = pos;
        }

        public int setRows(int columns)
        {
            int rows = 1;
            if (columns >= 2)
                rows++;
            if (columns >= 4)
                rows++;
            if (columns >= 6)
                rows++;
            if (columns >= 8)
                rows++;
            return rows;
        }

        public int setColumns(int inv)
        {
            int columns = 0;
            if (inv == 1 || inv == 3 || inv == 5 || inv == 7 || inv == 9)
                columns = 1;
            if (inv == 2 || inv == 4 || inv == 6 || inv == 8 || inv == 10)
                columns = 2;
            return columns;
        }

        public void setInv(int whatItem)
        {
            switch (whatItem)
            {
                case 1:
                    currHead = HEAD.INV;
                    break;

                case 2:
                    currLeftArm = LEFTARM.INV;
                    break;

                case 3:
                    currRightArm = RIGHTARM.INV;
                    break;

                case 4:
                    currChest = CHEST.INV;
                    break;

                case 5:
                    currLegs = LEGS.INV;
                    break;

                case 6:
                    currLeftLeg = LEFTLEG.INV;
                    break;

                case 7:
                    currRightLeg = RIGHTLEG.INV;
                    break;

                case 8:
                    currHead = HEAD.ADVANCED;
                    break;

                case 9:
                    currLeftArm = LEFTARM.ADVANCED;
                    break;

                case 10:
                    currRightArm = RIGHTARM.ADVANCED;
                    break;

                case 11:
                    currChest = CHEST.ADVANCED;
                    break;

                case 12:
                    currLegs = LEGS.ADVANCED;
                    break;

                case 13:
                    currLeftLeg = LEFTLEG.ADVANCED;
                    break;

                case 14:
                    currRightLeg = RIGHTLEG.ADVANCED;
                    break;

                default:
                    break;
            }
        }

        public void setInv(int whatItem, int whatState)
        {
            switch (whatItem)
            {
                case 1:
                    if (whatState == 2 && currHead != HEAD.BASIC && currHead != HEAD.ADVANCED)
                        currHead = HEAD.INV;
                    if (whatState == 3)
                        currHead = HEAD.ADVANCED;
                    break;

                case 2:
                    if (whatState == 2 && currLeftArm != LEFTARM.BASIC && currLeftArm != LEFTARM.ADVANCED)
                        currLeftArm = LEFTARM.INV;
                    if (whatState == 3)
                        currLeftArm = LEFTARM.ADVANCED;
                    break;

                case 3:
                    if (whatState == 2 && currRightArm != RIGHTARM.BASIC && currRightArm != RIGHTARM.ADVANCED)
                        currRightArm = RIGHTARM.INV;
                    if (whatState == 3)
                        currRightArm = RIGHTARM.ADVANCED;
                    break;

                case 4:
                    if (whatState == 2 && currChest != CHEST.BASIC && currChest != CHEST.ADVANCED)
                        currChest = CHEST.INV;
                    if (whatState == 3)
                        currChest = CHEST.ADVANCED;
                    break;

                case 5:
                    if (whatState == 2 && currLegs != LEGS.BASIC && currLegs != LEGS.ADVANCED)
                        currLegs = LEGS.INV;
                    if (whatState == 3)
                        currLegs = LEGS.ADVANCED;
                    break;

                case 6:
                    if (whatState == 2 && currLeftLeg != LEFTLEG.BASIC && currLeftLeg != LEFTLEG.ADVANCED)
                        currLeftLeg = LEFTLEG.INV;
                    if (whatState == 3)
                        currLeftLeg = LEFTLEG.ADVANCED;
                    break;

                case 7:
                    if (whatState == 2 && currRightLeg != RIGHTLEG.BASIC && currRightLeg != RIGHTLEG.ADVANCED)
                        currRightLeg = RIGHTLEG.INV;
                    if (whatState == 3)
                        currRightLeg = RIGHTLEG.ADVANCED;
                    break;

                default:
                    break;
            }
        }

        public void changeScore(int change)
        {
            if (Score + change > 0)
                Score += change;
            else
                Score = 0;
        }
    }
}