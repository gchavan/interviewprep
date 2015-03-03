using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clustering.UI
{
    struct Line
    {
        public Line(Point start, Point end)
        {
            this.start = start;
            this.end = end;
        }

        public Point start;
        public Point end;
    };

    struct cell
    {
        public cell(int row, int col)
        {
            this.row = row;
            this.col = col;
        }

        public int row;
        public int col;
    }

    public partial class Graph : Form
    {
        Graphics CurrentGraphics = null;

        static int left = 100;
        static int top = 100;

        static int rows = 10;
        static int cols = 10;

        int[,] arr = {
                { 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
                { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
                { 1, 0, 0, 1, 1, 1, 0, 0, 1, 1 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 },
                { 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
                { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1 },
                { 1, 0, 0, 1, 1, 1, 0, 0, 1, 1 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 1, 0, 1, 0, 1, 1, 0, 1, 0, 1 }
            };
        Point[,] nodes = null;
        bool[,] visited = null;

        public Graph()
        {
            InitializeComponent();
        }

        private void ExitButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void DrawGraphButton_Click(object sender, EventArgs e)
        {
            SolidBrush textBrush = new SolidBrush(Color.White);
            SolidBrush circleBackground = new SolidBrush(Color.Black);
            Pen blue = new Pen(Color.DarkBlue);
            
            Graphics graphics = this.CreateGraphics();

            graphics.Clear(Color.White);

            nodes = new Point[rows, cols];
            for(int i = 0; i < rows; i++)
            {
                int y = top + i * 50;
                for (int j = 0; j < cols; j++)
                {
                    int x = left + j * 50;
                    graphics.FillEllipse(circleBackground, x, y, 25, 25);
                    graphics.DrawString(arr[i,j].ToString(), new Font("Arial", 12, FontStyle.Bold), textBrush, new Point(x + 6, y + 4));

                    nodes[i, j] = new Point(x + 12, y + 12);
                }
            }
        }

        private void RunClusteringButton_Click(object sender, EventArgs e)
        {
            Graphics graphics = this.CreateGraphics();
            List<Line> path = new List<Line>();
            Pen blue = new Pen(Color.DarkBlue, 5);
            visited = new bool[rows, cols];

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    path.Clear();
                    RunClusteringAlgorithm(i, j, i, j, path);

                    if (path.Count > 0)
                    {
                        Line first = path.First();

                        if (path.Count == 1 && first.start == first.end)
                        {
                            int x = path.First().start.X;
                            int y = path.First().start.Y;
                            graphics.DrawEllipse(blue, x, y, 25, 25);
                        }
                        else
                        {
                            foreach (Line l in path)
                            {
                                graphics.DrawLine(blue, l.start, l.end);
                            }
                        }
                    }
                }
            }
        }

        private bool RunClusteringAlgorithm(int prevRow, int prevCol, int currRow, int currCol, List<Line> path)
        {
            if ((currRow < 0 || currRow >= rows) || (currCol < 0 || currCol >= cols))
                return false;

            if (visited[currRow, currCol])
                return false;

            if (arr[currRow, currCol] == 0)
                return false;

            var left = new cell(currRow, currCol - 1);
            var right = new cell(currRow, currCol + 1);
            var top = new cell(currRow - 1, currCol);
            var bottom = new cell(currRow + 1, currCol);
            var topLeft = new cell(currRow - 1, currCol - 1);
            var topRight = new cell(currRow - 1, currCol + 1);
            var bottomLeft = new cell(currRow + 1, currCol - 1);
            var bottomRight = new cell(currRow + 1, currCol + 1);

            path.Add(new Line(nodes[prevRow, prevCol], nodes[currRow, currCol]));

            visited[currRow, currCol] = true;

            RunClusteringAlgorithm(currRow, currCol, topLeft.row, topLeft.col, path);

            RunClusteringAlgorithm(currRow, currCol, top.row, top.col, path);

            RunClusteringAlgorithm(currRow, currCol, topRight.row, topRight.col, path);

            RunClusteringAlgorithm(currRow, currCol, right.row, right.col, path);

            RunClusteringAlgorithm(currRow, currCol, bottomRight.row, bottomRight.col, path);

            RunClusteringAlgorithm(currRow, currCol, bottom.row, bottom.col, path);

            RunClusteringAlgorithm(currRow, currCol, bottomLeft.row, bottomLeft.col, path);

            RunClusteringAlgorithm(currRow, currCol, left.row, left.col, path);

            return false;
        }
    }
}
