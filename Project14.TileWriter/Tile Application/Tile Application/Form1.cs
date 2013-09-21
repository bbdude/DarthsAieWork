using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Diagnostics;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Tile_Application
{
    public partial class Form1 : Form
    {
        private int chosenType = 0;
        /// <summary> Big Variable
        private int[,] map = new int[30, 30] { 
        { 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11 }, 
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 11 },
        { 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11 }};
        /// </summary>
        
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1261_Click(object sender, EventArgs e)
        {
            chosenType = 11;
        }

        private void pictureBox1262_Click(object sender, EventArgs e)
        {
            chosenType = 1;
        }

        private void pictureBox1264_Click(object sender, EventArgs e)
        {
            chosenType = 2;
        }

        private void pictureBox1263_Click(object sender, EventArgs e)
        {
            chosenType = 3;
        }

        private void pictureBox1268_Click(object sender, EventArgs e)
        {
            chosenType = 4;
        }

        private void pictureBox1267_Click(object sender, EventArgs e)
        {
            chosenType = 5;
        }

        private void pictureBox1266_Click(object sender, EventArgs e)
        {
            chosenType = 6;
        }

        private void pictureBox1265_Click(object sender, EventArgs e)
        {
            chosenType = 7;
        }

        private void pictureBox1276_Click(object sender, EventArgs e)
        {
            chosenType = 8;
        }

        private void pictureBox1275_Click(object sender, EventArgs e)
        {
            chosenType = 9;
        }

        private void pictureBox1274_Click(object sender, EventArgs e)
        {
            chosenType = 10;
        }
        private void changePictureBox(object sender, EventArgs e)
        {
            var pbox = sender as PictureBox;
            int row = 0;
            int column = 0;
            if (pbox.Location.X == -2)
                column = 0;
            else if (pbox.Location.X == 20)
                column = 1;

            for (int i = 0; i <= 29; i++)
            {
                if (pbox.Location.X == -2 + (22 * i))
                {
                    Console.Write("Got " + i.ToString());
                    row = i;
                    i = 29;
                }
            }
            //Console.Write("Got " + i.ToString());
            for (int ii = 0; ii <= 29; ii++){
                if (pbox.Location.Y == -2 + (22 * ii))
                {
                    Console.Write("Got " + ii.ToString());
                    column = ii;
                    ii = 29;
                }
            }
            map[row, column] = chosenType;

            switch (chosenType)
            {
                case 0:
                    pbox.Image = Tile_Application.Properties.Resources.greyTile;
                    break;
                case 1:
                    pbox.Image = Tile_Application.Properties.Resources.blueTile;
                    break;
                case 2:
                    pbox.Image = Tile_Application.Properties.Resources.greenTile;
                    break;
                case 3:
                    pbox.Image = Tile_Application.Properties.Resources.redTile;
                    break;
                case 4:
                    pbox.Image = Tile_Application.Properties.Resources.whiteTile;
                    break;
                case 5:
                    pbox.Image = Tile_Application.Properties.Resources.blueDoor;
                    break;
                case 6:
                    pbox.Image = Tile_Application.Properties.Resources.greenDoor;
                    break;
                case 7:
                    pbox.Image = Tile_Application.Properties.Resources.redDoor;
                    break;
                case 8:
                    pbox.Image = Tile_Application.Properties.Resources.whiteDoor;
                    break;
                case 9:
                    pbox.Image = Tile_Application.Properties.Resources.brownTile;
                    break;
                case 10:
                    pbox.Image = Tile_Application.Properties.Resources.roller;
                    break;
                case 11:
                    pbox.Image = Tile_Application.Properties.Resources.blackTile;
                    break;
                default:
                    pbox.Image = Tile_Application.Properties.Resources.blackTile;
                    break;
            }
        }

        private void pictureBox1273_Click(object sender, EventArgs e)
        {
            chosenType = 0;
        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            //Save File
            saveFileDialog1.Filter = "Text Files | *.txt";
            saveFileDialog1.DefaultExt = "txt";
            saveFileDialog1.FileName = textBox1.Text;
            saveFileDialog1.ShowDialog();
            StreamWriter writer = new StreamWriter(saveFileDialog1.FileName);
            string whatToWrite = "";
            for (int i = 0; i <= 29; i++)
            {
                for (int ii = 0; ii <= 29; ii++)
                {
                    whatToWrite += map[i, ii];
                    //writer.Write(map[i, ii]);
                    if (ii != 29)
                    whatToWrite += ",";
                        //writer.Write(",");
                }
                writer.WriteLine(whatToWrite);
                whatToWrite = "";
            }
            writer.Flush();
            writer.Close();

            DialogResult dialogResult = MessageBox.Show("Would you like to open the file?", "", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            if (dialogResult == DialogResult.Yes)
            {
                Process process = Process.Start(saveFileDialog1.FileName);
                //do something
            }
        }

        private void hoverBox(object sender, EventArgs e)
        {
            try
            {
                var pbox = sender as PictureBox;
                ToolTip tt = new ToolTip();
                tt.SetToolTip(pbox, pbox.Tag.ToString());
            }
            catch (InvalidCastException ee)
            {
                Console.Write(ee);
            }
        }
    }
}
