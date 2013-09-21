using System;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Design;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Media;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;

namespace _3DModel
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        private GraphicsDeviceManager graphics;
        private SpriteBatch spriteBatch;

        private Matrix view;// = Matrix.CreateLookAt(new Vector3(0,5,10),new Vector3(0,0,0),Vector3.UnitY);
        private Matrix projection = Matrix.CreatePerspectiveFieldOfView(MathHelper.ToRadians(45), 800f / 480f, 0.1f, 100f);

        private Player player;
        private Crate box;
        private Crate[,] crate;
        private Floor floor;
        private Sword sword;
        private Gun gun;
        private Gui gui;
        private Inventory inv;
        MainMenu mainMenu;

        //True is FP False is 3rdP
        private bool camMode = true;
        private bool collisionEnabled = true;
        private bool invScreenUp = false;

        enum LEVEL { MENU, LVL1, LVL2, LVL3, EXIT, INVENTORY };
        LEVEL currLevel = LEVEL.MENU;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here
            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.

            spriteBatch = new SpriteBatch(GraphicsDevice);
            Map.ReadFile(@"Content\map2.txt");

            inv = new Inventory(Content.Load<SpriteFont>(@"Font"), Content.Load<Texture2D>(@"GUI"), Content.Load<Texture2D>(@"healthbar"), Content.Load<Texture2D>(@"healthbar2"), Content.Load<Texture2D>(@"INV"), Content.Load<Texture2D>(@"map"), Content.Load<Texture2D>(@"SpellBook"), Content.Load<Texture2D>(@"selectbar"), Content.Load<Texture2D>(@"mapSmall"), Content.Load<Texture2D>(@"smallPlayer"), Content.Load<Texture2D>(@"head"), Content.Load<Texture2D>(@"lefthand"), Content.Load<Texture2D>(@"righthand"), Content.Load<Texture2D>(@"chest"), Content.Load<Texture2D>(@"legs"), Content.Load<Texture2D>(@"leftFoot"), Content.Load<Texture2D>(@"rightFoot"));
            mainMenu = new MainMenu(Content.Load<Texture2D>("splash"), Content.Load<Texture2D>("mainsymbol"), Content.Load<Texture2D>("MainMenu"));
            player = new Player(Content.Load<Model>("Ship"));
            floor = new Floor(Content.Load<Model>(@"floor"), new Vector3(0, -50f, 0));
            box = new Crate(Content.Load<Model>(@"crate2"), new Vector3(-6f, 0, 0));
            sword = new Sword(Content.Load<Model>(@"sword"), player.getPosition());
            gun = new Gun(Content.Load<Model>(@"gun"), player.getPosition());
            gui = new Gui();
            gui.loadGui(GraphicsDevice);

            crate = new Crate[30, 30];

            for (int x = 0; x <= 29; x++)
            {
                for (int y = 0; y <= 29; y++)
                {
                    //1blue,2green,3red,4white
                    crate[x, y] = new Crate(Content.Load<Model>(@"crate2"), new Vector3(-4f, -12f, 0));
                    crate[x, y].setType(Map.getMapPart(x, y));
                    string modelToLoad = "";
                    if (crate[x, y].getType() == 1)
                        modelToLoad = "blueCrate";
                    else if (crate[x, y].getType() == 2)
                        modelToLoad = "greenCrate";
                    else if (crate[x, y].getType() == 3)
                        modelToLoad = "redCrate";
                    else if (crate[x, y].getType() == 4)
                        modelToLoad = "whiteCrate";
                    else if (crate[x, y].getType() == 11)
                        modelToLoad = "blackCrate";
                    else if (crate[x, y].getType() == 9)
                        modelToLoad = "brownCrate";
                    else if (crate[x, y].getType() == 5)
                        modelToLoad = "blueDoor";
                    else if (crate[x, y].getType() == 6)
                        modelToLoad = "greenDoor";
                    else if (crate[x, y].getType() == 7)
                        modelToLoad = "redDoor";
                    else if (crate[x, y].getType() == 8)
                        modelToLoad = "whiteDoor";
                    else if (crate[x, y].getType() == 10)
                        modelToLoad = "roller";
                    else
                        modelToLoad = "greyCrate";
                    crate[x, y].reloadModel(Content.Load<Model>(@modelToLoad));

                    crate[x, y].setWorldX((x - 15) * 12);
                    crate[x, y].setWorldZ((y - 15) * 12);
                    if (crate[x, y].getType() == 11 || crate[x, y].getType() == 5 || crate[x, y].getType() == 10 || crate[x, y].getType() == 6 || crate[x, y].getType() == 7 || crate[x, y].getType() == 8)
                    {
                        crate[x, y].setWorldY(-1);
                    }
                    if (crate[x, y].getType() == 10)
                    {
                        crate[x, y].setWorldX(crate[x, y].getPosition().X + 1.5f);
                        crate[x, y].setWorldZ(crate[x, y].getPosition().Z + 1.5f);
                        crate[x, y].reloadModelTwo(Content.Load<Model>(@"blackCrate"));
                    }
                }
            }

            // TODO: use this.Content to load your game content here
        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            MouseState mouse = Mouse.GetState();
            KeyboardState keyboard = Keyboard.GetState();

            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed || keyboard.IsKeyDown(Keys.Escape))
                this.Exit();

            switch (currLevel)
            {
                case LEVEL.MENU:
                    if (mainMenu.updateMainMenu())
                        currLevel = LEVEL.LVL1;
                    IsMouseVisible = true;
                    break;
                case LEVEL.LVL1:
                    if (keyboard.IsKeyDown(Controls.getInvKey()) && !invScreenUp)
                    {
                        invScreenUp = true;
                    }

                    if (!invScreenUp)
                    {

                        bool movePlayer = true;

                        if (keyboard.IsKeyDown(Keys.OemMinus) && !(keyboard.IsKeyDown(Keys.LeftShift) || keyboard.IsKeyDown(Keys.RightShift)))
                            camMode = false;
                        else if (keyboard.IsKeyDown(Keys.OemPlus) && !(keyboard.IsKeyDown(Keys.LeftShift) || keyboard.IsKeyDown(Keys.RightShift)))
                            camMode = true;

                        if (keyboard.IsKeyDown(Keys.OemMinus) && (keyboard.IsKeyDown(Keys.LeftShift) || keyboard.IsKeyDown(Keys.RightShift)))
                            collisionEnabled = true;
                        else if (keyboard.IsKeyDown(Keys.OemPlus) && (keyboard.IsKeyDown(Keys.LeftShift) || keyboard.IsKeyDown(Keys.RightShift)))
                            collisionEnabled = false;

                        Vector3 angleToShow = player.getAngleToPush() + player.getPosition();
                        view = Matrix.CreateLookAt(angleToShow, player.getPosition(), Vector3.UnitY);

                        player.updatePlayer();
                        sword.swordUpdate(player.getPosition(), player.getAngle());
                        gun.gunUpdate(player.getPosition(), player.getAngle(), gameTime);
                        gui.updateGui();

                        //crate[0, 0].checkCollision(playerBoundry);

                        for (int x = 0; x <= 29; x++)
                        {
                            for (int y = 0; y <= 29; y++)
                            {
                                if (crate[x, y].getType() == 11 && collisionEnabled)
                                {
                                    if (CheckForCollisions(ref crate[x, y], ref player))
                                    {
                                        //player.clearPlannedDirection();
                                        //Console.Write(player.getPosition().X + "," + player.getPosition().Y + "," + player.getPosition().Z);
                                        //movePlayer = false;
                                    }
                                    if (CheckForCollisions(ref crate[x, y], ref player, true))
                                    {
                                        player.clearPlannedDirectionX();
                                        //Console.Write(player.getPosition().X + "," + player.getPosition().Y + "," + player.getPosition().Z);
                                        //movePlayer = false;
                                    }
                                    if (CheckForCollisions(ref crate[x, y], ref player, false))
                                    {
                                        player.clearPlannedDirectionY();
                                        //Console.Write(player.getPosition().X + "," + player.getPosition().Y + "," + player.getPosition().Z);
                                        //movePlayer = false;
                                    }
                                }
                                else if (crate[x, y].getType() == 5)
                                {
                                    //Blue Wall
                                    if (CheckForCollisions(ref crate[x, y], ref player))
                                    {
                                        if (gui.getBalanceOne() == "Sad")
                                        {
                                            crate[x, y].setType(0);
                                            crate[x, y].setWorldY(-12);
                                        }
                                        else
                                            movePlayer = false;
                                    }
                                }
                                else if (crate[x, y].getType() == 6)
                                {
                                    //Green Wall
                                    if (CheckForCollisions(ref crate[x, y], ref player))
                                    {
                                        if (gui.getBalanceOne() == "Calm")
                                        {
                                            crate[x, y].setType(0);
                                            crate[x, y].setWorldY(-12);
                                        }
                                        else
                                            movePlayer = false;
                                    }
                                }
                                else if (crate[x, y].getType() == 7)
                                {
                                    //Red Wall
                                    if (CheckForCollisions(ref crate[x, y], ref player))
                                    {
                                        if (gui.getBalanceOne() == "Angry")
                                        {
                                            crate[x, y].setType(0);
                                            crate[x, y].setWorldY(-12);
                                        }
                                        else
                                            movePlayer = false;
                                    }
                                }
                                else if (crate[x, y].getType() == 8)
                                {
                                    //White Wall
                                    if (CheckForCollisions(ref crate[x, y], ref player))
                                    {
                                        if (gui.getBalanceOne() == "Happy")
                                        {
                                            crate[x, y].setType(0);
                                            crate[x, y].setWorldY(-12);
                                        }
                                        else
                                            movePlayer = false;
                                    }
                                }
                            }
                        }
                        if (movePlayer)
                            player.updateDirection();
                    }
                    else
                    {
                        IsMouseVisible = true;
                    }
                    //inv.updateQuest();
                    
                    break;
            }
            base.Update(gameTime);
        }

        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);
            switch (currLevel)
            {
                case LEVEL.MENU:
                    mainMenu.drawMainMenu(spriteBatch);
                    break;
                case LEVEL.LVL1:
                    if (!invScreenUp)
                    {
                        IsMouseVisible = false;
                        DrawModel(sword.getModel(), sword.getWorld(), view, projection);
                        DrawModel(gun.getModel(), gun.getWorld(), view, projection);


                        for (int x = 0; x <= 29; x++)
                        {
                            for (int y = 0; y <= 29; y++)
                            {
                                DrawModel(crate[x, y].getModel(), crate[x, y].getWorld(), view, projection);
                                if (crate[x, y].getType() == 10)
                                    DrawModel(crate[x, y].getModelTwo(), Matrix.CreateTranslation(new Vector3(crate[x, y].getPosition().X - 1.5f, -6f, crate[x, y].getPosition().Z - 1.5f)), view, projection);
                            }
                        }

                        gui.drawGui(spriteBatch);
                        GraphicsDevice.BlendState = BlendState.Opaque;
                        GraphicsDevice.DepthStencilState = DepthStencilState.Default;
                        GraphicsDevice.SamplerStates[0] = SamplerState.LinearWrap;
                        base.Draw(gameTime);
                    }
                    else
                    {
                        inv.drawGUI(spriteBatch,20,20);
                    }
                    break;
            }
        }

        public Vector2 changeAngleToVector(float angle)
        {
            return new Vector2((float)Math.Sin(angle), (float)Math.Cos(angle));
        }

        private void DrawModel(Model model, Matrix world, Matrix view, Matrix projection)
        {
            foreach (ModelMesh mesh in model.Meshes)
            {
                foreach (BasicEffect effect in mesh.Effects)
                {
                    effect.World = world;
                    effect.View = view;
                    effect.Projection = projection;
                }
                mesh.Draw();
            }
        }

        private static bool CheckForCollisions(ref Crate c1, ref Player c2)
        {
            for (int i = 0; i < c1.model.Meshes.Count; i++)
            {
                // Check whether the bounding boxes of the two cubes intersect.
                BoundingSphere c1BoundingSphere = c1.model.Meshes[i].BoundingSphere;
                c1BoundingSphere.Center += c1.position + new Vector3(2, 0, 2);
                c1BoundingSphere.Radius = c1BoundingSphere.Radius / 2;

                for (int j = 0; j < c2.model.Meshes.Count; j++)
                {
                    BoundingSphere c2BoundingSphere = c2.model.Meshes[j].BoundingSphere;
                    c2BoundingSphere.Center += c2.position + new Vector3(c2.getPlannedDirection().X, 0, c2.getPlannedDirection().Y);
                    //c2BoundingSphere.Center += c2.position;

                    if (c1BoundingSphere.Intersects(c2BoundingSphere))
                    {
                        //Console.Write("Collide");
                        //c2.ReverseVelocity();
                        //c1.Backup();
                        //c1.ReverseVelocity();
                        return true;
                    }
                }
            }
            return false;
        }
        private static bool CheckForCollisions(ref Crate c1, ref Player c2,bool direction)
        {
            for (int i = 0; i < c1.model.Meshes.Count; i++)
            {
                // Check whether the bounding boxes of the two cubes intersect.
                BoundingSphere c1BoundingSphere = c1.model.Meshes[i].BoundingSphere;
                c1BoundingSphere.Center += c1.position + new Vector3(2, 0, 2);
                c1BoundingSphere.Radius = c1BoundingSphere.Radius / 1.5f;

                for (int j = 0; j < c2.model.Meshes.Count; j++)
                {
                    BoundingSphere c2BoundingSphere = c2.model.Meshes[j].BoundingSphere;
                    if (direction)
                        c2BoundingSphere.Center += c2.position + new Vector3(c2.getPlannedDirection().X, 0, 0);
                    else if (!direction)
                        c2BoundingSphere.Center += c2.position + new Vector3(0, 0, c2.getPlannedDirection().Y);
                    //c2BoundingSphere.Center += c2.position;

                    if (c1BoundingSphere.Intersects(c2BoundingSphere))
                    {
                        //Console.Write("Collide");
                        //c2.ReverseVelocity();
                        //c1.Backup();
                        //c1.ReverseVelocity();
                        return true;
                    }
                }
            }
            return false;
        }
        private static bool CorrectCollisions(ref Crate c1, ref Player c2)
        {
            for (int i = 0; i < c1.model.Meshes.Count; i++)
            {

            }
            /*
            for (int i = 0; i < c1.model.Meshes.Count; i++)
            {
                // Check whether the bounding boxes of the two cubes intersect.
                BoundingSphere c1BoundingSphere = c1.model.Meshes[i].BoundingSphere;

                c1BoundingSphere.Center += c1.position + new Vector3(2, 0, 2);
                c1BoundingSphere.Radius = c1BoundingSphere.Radius / 1.5f;

                for (int j = 0; j < c2.model.Meshes.Count; j++)
                {
                    BoundingSphere c2BoundingSphere = c2.model.Meshes[j].BoundingSphere;
                    c2BoundingSphere.Center += c2.position;

                    Vector3 dir = c2BoundingSphere.Center - c1BoundingSphere.Center;
                    float center_dist_sq = dir.dot(dir);
                    float min_dist = c2BoundingSphere.Radius + c1BoundingSphere.Radius;
                    if (center_dist_sq < min_dist * min_dist)
                    {
                        dir.Normalize();
                        c2.position.X += dir.X * (float)(min_dist - Math.Sqrt(center_dist_sq));
                        c2.position.Z += dir.Z * (float)(min_dist - Math.Sqrt(center_dist_sq));
                    }
                }
            }
             */
            return false;
        } 
        
    }
}

/*
DrawModel(box.getModel(), box.getWorld(), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(6, 0, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(-4, -4, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(-6, -2, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(4, -4, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(2, -4, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(0, -4, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(-2, -4, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(-4, -4, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(-6, -4, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(6, -2, 0)), view, projection);
DrawModel(box.getModel(), Matrix.CreateTranslation(new Vector3(6, -4, 0)), view, projection);

//Vector2 plannedDirection = Vector2.Zero;
 * */
/*
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
for (int x = 0; x <= 29; x++)
{
    for (int y = 0; y <= 29; y++)
    {
        if (crate[x, y].checkCollision(new Vector2(position.X, position.Z) + plannedDirection) && crate[x, y].getType() == 10)
            plannedDirection = Vector2.Zero;
    }
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
//position.X += player.getPlannedDirection().X;
//position.Z += player.getPlannedDirection().Y;
//view = Matrix.CreateLookAt(new Vector3(position.X,position.Y + 20,position.Z + 15),position,Vector3.UnitY);
 */