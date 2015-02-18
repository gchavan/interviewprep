namespace Clustering.UI
{
    partial class Graph
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.DrawGraphButton = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            this.RunClusteringButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // DrawGraphButton
            // 
            this.DrawGraphButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DrawGraphButton.Location = new System.Drawing.Point(29, 30);
            this.DrawGraphButton.Name = "DrawGraphButton";
            this.DrawGraphButton.Size = new System.Drawing.Size(129, 29);
            this.DrawGraphButton.TabIndex = 0;
            this.DrawGraphButton.Text = "Draw Graph";
            this.DrawGraphButton.UseVisualStyleBackColor = true;
            this.DrawGraphButton.Click += new System.EventHandler(this.DrawGraphButton_Click);
            // 
            // ExitButton
            // 
            this.ExitButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ExitButton.Location = new System.Drawing.Point(958, 30);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(89, 29);
            this.ExitButton.TabIndex = 1;
            this.ExitButton.Text = "Exit";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.ExitButton_Click);
            // 
            // RunClusteringButton
            // 
            this.RunClusteringButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RunClusteringButton.Location = new System.Drawing.Point(208, 30);
            this.RunClusteringButton.Name = "RunClusteringButton";
            this.RunClusteringButton.Size = new System.Drawing.Size(129, 29);
            this.RunClusteringButton.TabIndex = 2;
            this.RunClusteringButton.Text = "Run Clustering";
            this.RunClusteringButton.UseVisualStyleBackColor = true;
            this.RunClusteringButton.Click += new System.EventHandler(this.RunClusteringButton_Click);
            // 
            // Graph
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1069, 610);
            this.Controls.Add(this.RunClusteringButton);
            this.Controls.Add(this.ExitButton);
            this.Controls.Add(this.DrawGraphButton);
            this.Name = "Graph";
            this.Text = "Graph Clustering";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button DrawGraphButton;
        private System.Windows.Forms.Button ExitButton;
        private System.Windows.Forms.Button RunClusteringButton;
    }
}

