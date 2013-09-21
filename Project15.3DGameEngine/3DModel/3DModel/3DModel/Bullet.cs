using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace _3DModel
{
    class Bullet
    {
        private Model bulletModel;
        private Vector3 bulletTarget;
        public Vector3 bulletPosition;
        private Vector3 bulletVelocity;
        public bool isActive;
        private float moveSpeed;

        public Bullet()
        {
            isActive = false;
        }

        public void ActivateBullet(Vector3 target, Vector3 pos, Model theModel)
        {
            bulletTarget = target;
            bulletPosition = pos;
            bulletModel = theModel;
            moveSpeed = 200;
            isActive = true;
            SetVelocity();
        }
        private void SetVelocity()
        {
            bulletVelocity = -(bulletPosition - bulletTarget);
            bulletVelocity.Normalize();
        }
        public void Update(GameTime gameTime)
        {
            float elapsedTime = (float)gameTime.ElapsedGameTime.TotalSeconds;
            if (bulletPosition.Y < -30)
                isActive = false;
            if (bulletPosition.X < -30 || bulletPosition.X > 600)
                isActive = false;
            bulletPosition += (bulletVelocity * moveSpeed * elapsedTime);
            //bulletRectangle = new Rectangle((int)bulletPosition.X, (int)bulletPosition.Y, bulletTexture.Width, bulletTexture.Height);
            //HandleCollisions();
        }
        public void Draw(GameTime gameTime, SpriteBatch spriteBatch)
        {
            //spriteBatch.Draw(bulletModel, bulletPosition, null, Color.Black, rotation, new Vector2(bulletTexture.Width / 2, bulletTexture.Height / 2), 1.0f, SpriteEffects.None, 0f);
        }

        public void Kill()
        {
            isActive = false;
        }
    }
}
