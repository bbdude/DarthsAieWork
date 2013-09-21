using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace _3DModel
{
    internal class Sword
    {
        private Model model;
        private Matrix world = Matrix.CreateTranslation(new Vector3(6, 0, 0));
        private Vector3 position = Vector3.Zero;

        public Sword(Model theModel, Vector3 whereAt)
        {
            model = theModel;
            world = Matrix.CreateTranslation(whereAt);
            position = whereAt;
            position.X = whereAt.Y - 20;
            position.Y -= 5;
        }

        public void swordUpdate(Vector3 playerPos, float angle)
        {
            world = Matrix.CreateRotationY(angle) * Matrix.CreateTranslation(playerPos + new Vector3(1, 0, 0));
        }

        public Model getModel()
        {
            return model;
        }

        public Matrix getWorld()
        {
            return world;
        }

        public Vector3 getPosition()
        {
            return position;
        }
    }
}