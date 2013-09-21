using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace _3DModel
{
    internal class List
    {
        //N/A = 0, Dropped = 1, Picked up = 2,Advanced = 3
        private int headState, leftArmState, rightArmState, chestState, legsState, leftLegState, rightLegState = 0;

        private Texture2D mHead, mLeftArm, mRightArm, mChest, mLegs, mLeftLeg, mRightLeg;
        private Rectangle[] boundryItems = new Rectangle[7];

        public List(Texture2D head, Texture2D LeftArm, Texture2D RightArm, Texture2D Chest, Texture2D Legs, Texture2D LeftLeg, Texture2D RightLeg)
        {
            mHead = head;
            mLeftArm = LeftArm;
            mRightArm = RightArm;
            mChest = Chest;
            mLegs = Legs;
            mLeftLeg = LeftLeg;
            mRightLeg = RightLeg;

            boundryItems[0] = new Rectangle(-200, -200, 20, 20);
            boundryItems[1] = new Rectangle(-200, -200, 20, 20);
            boundryItems[2] = new Rectangle(-200, -200, 20, 20);
            boundryItems[3] = new Rectangle(-200, -200, 20, 20);
            boundryItems[4] = new Rectangle(-200, -200, 20, 20);
            boundryItems[5] = new Rectangle(-200, -200, 20, 20);
            boundryItems[6] = new Rectangle(-200, -200, 20, 20);

            headState = 0;
            leftArmState = 0;
            rightArmState = 0;
            chestState = 0;
            legsState = 0;
            leftLegState = 0;
            rightLegState = 0;
        }

        public int whichEquipment(bool excludeHead, bool excludeLArm, bool excludeRArm, bool excludeChest, bool excludeLegs, bool excludeLLeg, bool excludeRLeg, Vector2 posE)
        {
            Vector2 pos = posE - new Vector2(40, 90);
            Random rand = new Random();
            int choice = 0;
            choice = rand.Next(1, 8);
            if (choice == 1 && !excludeHead)
            {
                if (headState == 0)
                {
                    boundryItems[0].X = (int)pos.X;
                    boundryItems[0].Y = (int)pos.Y;
                    headState = 1;
                    return 1;
                }
                else if (headState == 2)
                {
                    headState = 3;
                    return 8;
                }
                else
                    excludeHead = true;
            }
            else if (choice == 2 && !excludeLArm)
            {
                if (leftArmState == 0)
                {
                    boundryItems[1].X = (int)pos.X;
                    boundryItems[1].Y = (int)pos.Y;
                    leftArmState = 1;
                    return 2;
                }
                else if (leftArmState == 2)
                {
                    leftArmState = 3;
                    return 9;
                }
                else
                    excludeLArm = true;
            }
            else if (choice == 3 && !excludeRArm)
            {
                if (rightArmState == 0)
                {
                    boundryItems[2].X = (int)pos.X;
                    boundryItems[2].Y = (int)pos.Y;
                    rightArmState = 1;
                    return 3;
                }
                else if (rightArmState == 2)
                {
                    rightArmState = 3;
                    return 10;
                }
                else
                    excludeRArm = true;
            }
            else if (choice == 4 && !excludeChest)
            {
                if (chestState == 0)
                {
                    boundryItems[3].X = (int)pos.X;
                    boundryItems[3].Y = (int)pos.Y;
                    chestState = 1;
                    return 4;
                }
                else if (chestState == 2)
                {
                    chestState = 3;
                    return 11;
                }
                else
                    excludeChest = true;
            }
            else if (choice == 5 && !excludeLegs)
            {
                if (legsState == 0)
                {
                    boundryItems[4].X = (int)pos.X;
                    boundryItems[4].Y = (int)pos.Y;
                    legsState = 1;
                    return 5;
                }
                else if (legsState == 2)
                {
                    legsState = 3;
                    return 12;
                }
                else
                    excludeLegs = true;
            }
            else if (choice == 6 && !excludeLLeg)
            {
                if (leftLegState == 0)
                {
                    boundryItems[5].X = (int)pos.X;
                    boundryItems[5].Y = (int)pos.Y;
                    leftLegState = 1;
                    return 6;
                }
                else if (leftLegState == 2)
                {
                    leftLegState = 3;
                    return 13;
                }
                else
                    excludeLLeg = true;
            }
            else if (choice == 7 && !excludeRLeg)
            {
                if (rightLegState == 0)
                {
                    boundryItems[6].X = (int)pos.X;
                    boundryItems[6].Y = (int)pos.Y;
                    rightLegState = 1;
                    return 7;
                }
                else if (rightLegState == 2)
                {
                    rightLegState = 3;
                    return 14;
                }
                else
                    excludeRLeg = true;
            }
            return (whichEquipment(excludeHead, excludeLArm, excludeRArm, excludeChest, excludeLegs, excludeLLeg, excludeRLeg, posE));
        }

        public void drawList(SpriteBatch theSpriteBatch, Vector2 vladPos, int XOffset, int YOffset)
        {
            //Draw Items around
        }

        public int returnStates(int choice)
        {
            switch (choice)
            {
                case 1:
                    return headState;
                case 2:
                    return leftArmState;
                case 3:
                    return rightArmState;
                case 4:
                    return chestState;
                case 5:
                    return legsState;
                case 6:
                    return leftLegState;
                case 7:
                    return rightLegState;
                default:
                    return 0;
                //break;
            }
        }
    }
}