using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace _3DModel
{
    internal class Crate
    {
        public Model model;
        private Model modelTwo;
        private Matrix world = Matrix.CreateTranslation(new Vector3(6, 0, 0));
        public Vector3 position = Vector3.Zero;
        private int crateType = 0;
        private BoundingBox crateBoundry;

        public Crate(Model theModel, Vector3 whereAt)
        {
            model = theModel;
            world = Matrix.CreateTranslation(whereAt);
            position = whereAt;
        }

        public void reloadModel(Model theModel)
        {
            model = theModel;
        }

        public void reloadModelTwo(Model theModel)
        {
            modelTwo = theModel;
        }

        public void boxUpdate()
        {
            crateBoundry = new BoundingBox(position, new Vector3(6, 6, 6));
            world = Matrix.CreateTranslation(position);
        }

        public Model getModel()
        {
            return model;
        }

        public Model getModelTwo()
        {
            return modelTwo;
        }

        public Matrix getWorld()
        {
            return world;
        }

        public int getType()
        {
            return crateType;
        }

        public Vector3 getPosition()
        {
            return position;
        }

        public void setType(int type)
        {
            crateType = type;
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