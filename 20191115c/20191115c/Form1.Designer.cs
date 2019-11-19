namespace _20191115c
{
    partial class Form1
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
            this.BthAdd = new System.Windows.Forms.Button();
            this.BthSub = new System.Windows.Forms.Button();
            this.fileSystemWatcher1 = new System.IO.FileSystemWatcher();
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).BeginInit();
            this.SuspendLayout();
            // 
            // BthAdd
            // 
            this.BthAdd.Location = new System.Drawing.Point(38, 53);
            this.BthAdd.Name = "BthAdd";
            this.BthAdd.Size = new System.Drawing.Size(101, 23);
            this.BthAdd.TabIndex = 0;
            this.BthAdd.Text = "增加透明度";
            this.BthAdd.UseVisualStyleBackColor = true;
            this.BthAdd.Click += new System.EventHandler(this.button1_Click);
            // 
            // BthSub
            // 
            this.BthSub.Location = new System.Drawing.Point(225, 52);
            this.BthSub.Name = "BthSub";
            this.BthSub.Size = new System.Drawing.Size(97, 23);
            this.BthSub.TabIndex = 1;
            this.BthSub.Text = "降低透明度";
            this.BthSub.UseVisualStyleBackColor = true;
            // 
            // fileSystemWatcher1
            // 
            this.fileSystemWatcher1.EnableRaisingEvents = true;
            this.fileSystemWatcher1.SynchronizingObject = this;
            this.fileSystemWatcher1.Changed += new System.IO.FileSystemEventHandler(this.fileSystemWatcher1_Changed);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(469, 318);
            this.Controls.Add(this.BthSub);
            this.Controls.Add(this.BthAdd);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BthAdd;
        private System.Windows.Forms.Button BthSub;
        private System.IO.FileSystemWatcher fileSystemWatcher1;
    }
}

