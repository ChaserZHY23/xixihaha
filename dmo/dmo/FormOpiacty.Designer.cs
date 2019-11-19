namespace dmo
{
    partial class FormOpiacty
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
            this.BtnAdd = new System.Windows.Forms.Button();
            this.SubAtn = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // BtnAdd
            // 
            this.BtnAdd.Location = new System.Drawing.Point(50, 60);
            this.BtnAdd.Name = "BtnAdd";
            this.BtnAdd.Size = new System.Drawing.Size(98, 23);
            this.BtnAdd.TabIndex = 0;
            this.BtnAdd.Text = "增加透明度";
            this.BtnAdd.UseVisualStyleBackColor = true;
            this.BtnAdd.Click += new System.EventHandler(this.BtnAdd_Click);
            // 
            // SubAtn
            // 
            this.SubAtn.Location = new System.Drawing.Point(187, 59);
            this.SubAtn.Name = "SubAtn";
            this.SubAtn.Size = new System.Drawing.Size(104, 23);
            this.SubAtn.TabIndex = 1;
            this.SubAtn.Text = "降低透明度";
            this.SubAtn.UseVisualStyleBackColor = true;
            this.SubAtn.Click += new System.EventHandler(this.SubAtn_Click);
            // 
            // FormOpiacty
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(330, 440);
            this.Controls.Add(this.SubAtn);
            this.Controls.Add(this.BtnAdd);
            this.Name = "FormOpiacty";
            this.Text = "可调节透明度的窗体";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button BtnAdd;
        private System.Windows.Forms.Button SubAtn;
    }
}