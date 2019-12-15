namespace MDI
{
    partial class MDIForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.打开ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.窗口ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.垂直平铺ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.层叠ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.水平平铺ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.全部关闭ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.请在此处键入ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.打开ToolStripMenuItem,
            this.窗口ToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.MdiWindowListItem = this.窗口ToolStripMenuItem;
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(282, 28);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // 打开ToolStripMenuItem
            // 
            this.打开ToolStripMenuItem.Name = "打开ToolStripMenuItem";
            this.打开ToolStripMenuItem.Size = new System.Drawing.Size(51, 24);
            this.打开ToolStripMenuItem.Text = "打开";
            // 
            // 窗口ToolStripMenuItem
            // 
            this.窗口ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.垂直平铺ToolStripMenuItem,
            this.层叠ToolStripMenuItem,
            this.水平平铺ToolStripMenuItem,
            this.全部关闭ToolStripMenuItem,
            this.请在此处键入ToolStripMenuItem});
            this.窗口ToolStripMenuItem.Name = "窗口ToolStripMenuItem";
            this.窗口ToolStripMenuItem.Size = new System.Drawing.Size(51, 24);
            this.窗口ToolStripMenuItem.Text = "窗口";
            // 
            // 垂直平铺ToolStripMenuItem
            // 
            this.垂直平铺ToolStripMenuItem.Name = "垂直平铺ToolStripMenuItem";
            this.垂直平铺ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.垂直平铺ToolStripMenuItem.Text = "垂直平铺";
            this.垂直平铺ToolStripMenuItem.Click += new System.EventHandler(this.垂直平铺ToolStripMenuItem_Click);
            // 
            // 层叠ToolStripMenuItem
            // 
            this.层叠ToolStripMenuItem.Name = "层叠ToolStripMenuItem";
            this.层叠ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.层叠ToolStripMenuItem.Text = "层叠";
            this.层叠ToolStripMenuItem.Click += new System.EventHandler(this.层叠ToolStripMenuItem_Click);
            // 
            // 水平平铺ToolStripMenuItem
            // 
            this.水平平铺ToolStripMenuItem.Name = "水平平铺ToolStripMenuItem";
            this.水平平铺ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.水平平铺ToolStripMenuItem.Text = "水平平铺";
            this.水平平铺ToolStripMenuItem.Click += new System.EventHandler(this.水平平铺ToolStripMenuItem_Click);
            // 
            // 全部关闭ToolStripMenuItem
            // 
            this.全部关闭ToolStripMenuItem.Name = "全部关闭ToolStripMenuItem";
            this.全部关闭ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.全部关闭ToolStripMenuItem.Text = "全部关闭";
            this.全部关闭ToolStripMenuItem.Click += new System.EventHandler(this.全部关闭ToolStripMenuItem_Click);
            // 
            // 请在此处键入ToolStripMenuItem
            // 
            this.请在此处键入ToolStripMenuItem.Name = "请在此处键入ToolStripMenuItem";
            this.请在此处键入ToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.请在此处键入ToolStripMenuItem.Text = "请在此处键入";
            this.请在此处键入ToolStripMenuItem.Click += new System.EventHandler(this.请在此处键入ToolStripMenuItem_Click);
            // 
            // MDIForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(282, 253);
            this.Controls.Add(this.menuStrip1);
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MDIForm";
            this.Text = "多文档记事本";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem 打开ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 窗口ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 垂直平铺ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 层叠ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 水平平铺ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 全部关闭ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 请在此处键入ToolStripMenuItem;
    }
}

