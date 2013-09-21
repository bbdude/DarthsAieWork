using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Graphics;

namespace _3DModel
{
    internal class Gui
    {
        private Rectangle scaleOneBoundry = new Rectangle(20, 40, 10, 100);
        private Rectangle scaleTwoBoundry = new Rectangle(50, 40, -10, -100);

        private Texture2D scaleTexture;

        private float balanceOne = 10;
        private float balanceTwo = -10;
        private float defense = 1;
        private float speed = 1;
        private float attack = 1;
        private float healthMax = 20;
        private float healthCurrent;
        private float healthRegen = 0.01f;

        private int level = 1;

        private string name = "Player";
        private string emotion = "Perfect";

        public void loadGui(GraphicsDevice device)
        {
            SpriteBatch theSpriteBatch = new SpriteBatch(device);
            healthCurrent = healthMax;
            scaleTexture = new Texture2D(device, 1, 1);
            scaleTexture.SetData(new Color[] { Color.White });
        }

        public void updateGui()
        {
            if (healthCurrent < healthMax)
            {
                healthCurrent += healthRegen;
                if (healthCurrent > healthMax)
                    healthCurrent = healthMax;
            }
            if (balanceOne >= 5 && balanceTwo >= 5)
            {
                emotion = "Pain";
                healthRegen = 0;
                //Pain Aura
            }
            else if (balanceOne >= 5 && balanceTwo <= -5)
            {
                emotion = "Cold";
                speed = -.2f;
                defense = 3;
            }
            else if (balanceOne <= -5 && balanceTwo >= 5)
            {
                emotion = "Insane";
                defense = -1;
                attack = 3;
            }
            else if (balanceOne <= -5 && balanceTwo <= -5)
            {
                emotion = "Mellow";
                healthRegen = .001f;
                defense = 3;
                //Notin Yet
            }
            else if (balanceOne >= 5)
            {
                emotion = "Sad";
                speed = .5f;
                //Slow Aura
            }
            else if (balanceOne <= -5)
            {
                emotion = "Happy";
                healthRegen = 0.05f;
                attack = .5f;
            }
            else if (balanceTwo >= 5)
            {
                emotion = "Angry";
                attack = 2;
                defense = 0.5f;
            }
            else if (balanceTwo <= -5)
            {
                emotion = "Calm";
                defense = 2;
                healthRegen = 0;
            }
            else
            {
                emotion = "Perfect";
                defense = .8f;
                healthRegen = 0.01f;
                speed = .8f;
                attack = .8f;
            }
            if (healthCurrent <= 0)
            {
                emotion = "Dead";
            }
            scaleOneBoundry.Height = (int)balanceOne * 3;
            //Console.Write(scaleOneBoundry.Height.ToString());
            scaleTwoBoundry.Height = (int)balanceTwo * 3;

            if (scaleTwoBoundry.Height < 0)
                scaleTwoBoundry.Width = -10;
            else
                scaleTwoBoundry.Width = 10;

            if (scaleOneBoundry.Height < 0)
                scaleOneBoundry.Width = -10;
            else
                scaleOneBoundry.Width = 10;
        }

        public void drawGui(SpriteBatch theSpriteBatch)
        {
            Color currentEmotionOne;
            Color currentEmotionTwo;

            if (balanceOne >= 0)
                currentEmotionOne = Color.White;
            else
                currentEmotionOne = Color.Blue;
            if (balanceTwo >= 0)
                currentEmotionTwo = Color.Green;
            else
                currentEmotionTwo = Color.Red;

            theSpriteBatch.Begin();
            theSpriteBatch.Draw(scaleTexture, scaleOneBoundry, currentEmotionOne);
            theSpriteBatch.Draw(scaleTexture, scaleTwoBoundry, currentEmotionTwo);
            theSpriteBatch.End();
        }

        public string getEmotion()
        {
            return emotion;
        }
        public string getBalanceOne()
        {
            if (balanceOne >= 5)
            {
                return "Sad";
            }
            else if (balanceOne <= -5)
            {
                return "Happy";
            }
            else
                return "Null";
        }
        public string getBalanceTwo()
        {
            if (balanceOne >= 5)
            {
                return "Angry";
            }
            else if (balanceOne <= -5)
            {
                return "Calm";
            }
            else
                return "Null";
        }
    }

    /*
    public class RectangleOverlay : DrawableGameComponent{
        SpriteBatch spriteBatch;
        Texture2D dummyTexture;
        Rectangle dummyRectangle;
        Color Colori;

        public RectangleOverlay(Rectangle rect, Color colori)
        {
            // Choose a high number, so we will draw on top of other components.
            DrawOrder = 1000;
            dummyRectangle = rect;
            Colori = colori;
        }

        protected override void LoadContent()
        {
            spriteBatch = new SpriteBatch(GraphicsDevice);
            dummyTexture = new Texture2D(GraphicsDevice, 1, 1);
            dummyTexture.SetData(new Color[] { Color.White });
        }

        public override void Draw(GameTime gameTime)
        {
            spriteBatch.Begin();
            spriteBatch.Draw(dummyTexture, dummyRectangle, Colori);
            spriteBatch.End();
        }
    }
     */
}