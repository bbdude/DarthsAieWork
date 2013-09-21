using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace _3DModel
{
    internal class Floor
    {
        private Model model;
        private Matrix world;
        private Vector3 position = Vector3.Zero;

        public Floor(Model theModel, Vector3 whereAt)
        {
            model = theModel;
            world = Matrix.CreateTranslation(whereAt) * Matrix.CreateScale(30.0f, 0.1f, 30.0f);
            position = whereAt;
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