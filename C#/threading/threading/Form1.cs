using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace threading
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //DelayThreadExecution.Enabled = false;
            //Print.Enabled = true;
            //Task task = new Task(() => DelayThread());
            //task.Start();
            ////DelayThread();
            //DelayThreadExecution.Enabled = true;
            //Print.Enabled = true;

        }
        private void DelayThread()
        {
            //Thread.Sleep(5000);
        }

        private void button1_Click(object sender, EventArgs e)
        {


        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
