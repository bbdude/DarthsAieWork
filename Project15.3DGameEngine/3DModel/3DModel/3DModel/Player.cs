using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace _3DModel
{
    internal class Player
    {
        public Model model;
        private Matrix world = Matrix.CreateTranslation(new Vector3(0, 0, 0));
        public Vector3 position;
        private Vector3 angleToPush = new Vector3(0, 20, 15);
        //private Vector3 angleToPush = new Vector3(0, 2, 15);
        private float angle;
        private float angleToAdjust = 0;
        private Vector2 plannedDirection = Vector2.Zero;

        public Player(Model theModel)
        {
            model = theModel;
            position = new Vector3(-10, -2.5f, -10);
            angle = 0;
        }

        public void reloadModel(Model theModel)
        {
            model = theModel;
        }

        public void updatePlayer()
        {
            KeyboardState keyboard = Keyboard.GetState();
            plannedDirection = Vector2.Zero;

            if (keyboard.IsKeyDown(Keys.W))
            {
                plannedDirection.X += -changeAngleToVector(angle).X;
                plannedDirection.Y += -changeAngleToVector(angle).Y;
            }
            else if (keyboard.IsKeyDown(Keys.S))
            {
                plannedDirection.X += changeAngleToVector(angle).X;
                plannedDirection.Y += changeAngleToVector(angle).Y;
            }

            if (keyboard.IsKeyDown(Keys.D))
            {
                if (angleToPush.X > 15)
                    angleToPush.X = 15;
                else if (angleToPush.X < -15)
                    angleToPush.X = -15;
                if (angleToPush.Z > 15)
                    angleToPush.Z = 15;
                else if (angleToPush.Z < -15)
                    angleToPush.Z = -15;

                angle -= 0.0206683552631579f;
                if (angleToPush.Z <= 16 + angleToAdjust && angleToPush.Z >= 0 + angleToAdjust && angleToPush.X <= 0 - angleToAdjust && angleToPush.X >= -16 - angleToAdjust)
                {
                    angleToPush.Z -= .2f;
                    angleToPush.X -= .2f;
                }
                if (angleToPush.Z <= 0 - angleToAdjust && angleToPush.Z >= -16 - angleToAdjust && angleToPush.X <= 0 - angleToAdjust && angleToPush.X >= -16 - angleToAdjust)
                {
                    angleToPush.Z -= .2f;
                    angleToPush.X += .2f;
                }
                if (angleToPush.Z <= 0 - angleToAdjust && angleToPush.Z >= -16 - angleToAdjust && angleToPush.X <= 16 + angleToAdjust && angleToPush.X >= 0 + angleToAdjust)
                {
                    angleToPush.Z += .2f;
                    angleToPush.X += .2f;
                }
                if (angleToPush.Z <= 16 + angleToAdjust && angleToPush.Z >= 0 + angleToAdjust && angleToPush.X <= 16 + angleToAdjust && angleToPush.X >= 0 + angleToAdjust)
                {
                    angleToPush.Z += .2f;
                    angleToPush.X -= .2f;
                }
            }
            else if (keyboard.IsKeyDown(Keys.A))
            {
                if (angleToPush.X > 15)
                    angleToPush.X = 15;
                else if (angleToPush.X < -15)
                    angleToPush.X = -15;
                if (angleToPush.Z > 15)
                    angleToPush.Z = 15;
                else if (angleToPush.Z < -15)
                    angleToPush.Z = -15;

                angle += 0.0206683552631579f;
                if (angleToPush.Z <= 16 && angleToPush.Z >= 0 && angleToPush.X >= 0 && angleToPush.X <= 16)
                {
                    angleToPush.Z -= .2f;
                    angleToPush.X += .2f;
                }
                if (angleToPush.Z <= 0 && angleToPush.Z >= -16 && angleToPush.X >= 0 && angleToPush.X <= 16)
                {
                    angleToPush.Z -= .2f;
                    angleToPush.X -= .2f;
                }
                if (angleToPush.Z <= 0 && angleToPush.Z >= -16 && angleToPush.X >= -16 && angleToPush.X <= 0)
                {
                    angleToPush.Z += .2f;
                    angleToPush.X -= .2f;
                }
                if (angleToPush.Z <= 16 && angleToPush.Z >= 0 && angleToPush.X >= -16 && angleToPush.X <= 0)
                {
                    angleToPush.Z += .2f;
                    angleToPush.X += .2f;
                }
            }
            world = Matrix.CreateRotationZ(angle) * Matrix.CreateRotationX((3.14159f / 2) + 3.14159f) * Matrix.CreateTranslation(position);
        }

        public void updateDirection()
        {
            position.X += plannedDirection.X;
            position.Z += plannedDirection.Y;
            clearPlannedDirection();
        }
        public void updateDirectionInverse()
        {
            position.X -= plannedDirection.X;
            position.Z -= plannedDirection.Y;
            clearPlannedDirection();
        }

        public Vector2 changeAngleToVector(float angle)
        {
            return new Vector2((float)Math.Sin(angle), (float)Math.Cos(angle));
        }

        public Model getModel()
        {
            return model;
        }

        public Vector2 getPlannedDirection()
        {
            return plannedDirection;
        }

        public Vector3 getAngleToPush()
        {
            return angleToPush;
        }

        public float getAngle()
        {
            return angle;
        }

        public Matrix getWorld()
        {
            return world;
        }

        public Vector3 getPosition()
        {
            return position;
        }

        public void clearPlannedDirection()
        {
            plannedDirection = Vector2.Zero;
        }
        public void clearPlannedDirectionX()
        {
            plannedDirection.X = 0;
        }
        public void clearPlannedDirectionY()
        {
            plannedDirection.Y = 0;
        }

        public void setWorldX(float x)
        {
            position.X = x;
            world = Matrix.CreateTranslation(position);
        }

        public void setWorldY(float y)
        {
            position.Y = y;
            world = Matrix.CreateTranslation(position);
        }

        public void setWorldZ(float z)
        {
            position.Z = z;
            world = Matrix.CreateTranslation(position);
        }
    }
}