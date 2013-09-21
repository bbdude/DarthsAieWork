using System;
using System.Collections.Generic;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace _3DModel
{
    internal class Gun
    {
        private Model model;
        private Model bulletModel;
        private Matrix world = Matrix.CreateTranslation(new Vector3(6, 0, 0));
        private Vector3 position = Vector3.Zero;
        private List<Bullet> bullets = new List<Bullet>();

        public Gun(Model theModel, Vector3 whereAt)
        {
            model = theModel;
            bulletModel = theModel;
            world = Matrix.CreateTranslation(whereAt);
            position = whereAt;
            position.X = whereAt.Y + 10;
            position.Y -= 25;

            for (int i = 0; i < 20; i++)
            {
                bullets.Add(new Bullet());
            }

        }

        public void gunUpdate(Vector3 playerPos, float angle,GameTime gameTime)
        {
            world = Matrix.CreateRotationY(angle) * Matrix.CreateTranslation(playerPos + new Vector3(-1, 0, 0));

            for (int i = 0; i < bullets.Count; ++i)
                if (bullets[i].isActive)
                    bullets[i].Update(gameTime);
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
        public void FireBullet(Vector3 point, Vector3 center)
        {
            for (int i = 0; i < bullets.Count; i++)
            {
                if (!bullets[i].isActive)
                {
                    bullets[i].ActivateBullet(point, center, bulletModel);
                    return;
                }
            }
        }
        protected void Draw(GameTime gameTime,SpriteBatch theSpriteBatch)
        {
            theSpriteBatch.Begin();
            foreach (Bullet bullet in bullets)
                if (bullet.isActive)
                    bullet.Draw(gameTime, theSpriteBatch);
            theSpriteBatch.End();
        }
    }
}