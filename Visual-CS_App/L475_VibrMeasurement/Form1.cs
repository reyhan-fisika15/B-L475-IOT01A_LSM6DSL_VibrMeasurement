using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace L475_VibrMeasurement
{
    public partial class Form1 : Form
    {
        public SerialPort port;
        public StringBuilder str;
        public double[] dataAccelX;
        public double[] dataAccelY;
        public double[] dataAccelZ;
        public int i = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Create SerialPort object
            port = new SerialPort();

            // Register DataReceived event
            port.DataReceived += new SerialDataReceivedEventHandler(SerialPort_DataReceived);

            // Allocate memory for measurement data
            // Data length is 10 secs (fs = 50 Hz)
            dataAccelX = new double[500];
            dataAccelY = new double[500];
            dataAccelZ = new double[500];

            // Allocate string builder
            str = new StringBuilder();

            formsPlot1.Plot.AddSignal(dataAccelX, 50, Color.Red);
            formsPlot1.Plot.AddSignal(dataAccelY, 50, Color.Green);
            formsPlot1.Plot.AddSignal(dataAccelZ, 50, Color.Blue);
        }

        private void comboBox1_DropDown(object sender, EventArgs e)
        {
            // Update available COM ports
            comboBox1.Items.Clear();
            comboBox1.Items.AddRange(SerialPort.GetPortNames());
        }

        private void btPortConnect_Click(object sender, EventArgs e)
        {
            // If previously connected.... then disconnect
            if(port.IsOpen == false)
            {
                // Assign the port
                port.PortName = comboBox1.Text;
                // Assign the baud rate
                port.BaudRate = 115200;
                port.NewLine = "\r\n";

                btPortConnect.Text = "Disconnect";
                btPortConnect.BackColor = Color.LightGreen;
                port.Open();

                toolStripStatusLabel1.Text = "Connected to " + comboBox1.Text;
                timer1.Start();
            }
            else
            {
                btPortConnect.Text = "Connect";
                btPortConnect.BackColor = Color.LightCoral;
                port.Close();
                toolStripStatusLabel1.Text = "Disconnected";
                timer1.Stop();
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            // Detach DataReceived event
            port.DataReceived -= SerialPort_DataReceived;
            // Close port connection
            port.Close();
        }

        private void SerialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        { 
            if(port.BytesToRead > 7)
            {
                // Get the data from B-L475E-IOT01A
                str.Clear();
                str.Append(port.ReadLine());

                int portDataX = 0;
                int portDataY = 0;
                int portDataZ = 0;
                double tmp;
                String[] strtmp;

                // Parse X, Y, Z value
                char[] separators = new char[] { ',' };
                strtmp = str.ToString().Split(separators);
                Int32.TryParse(strtmp[0], out portDataX);
                Int32.TryParse(strtmp[1], out portDataY);
                Int32.TryParse(strtmp[2], out portDataZ);

                // Update chart array
                tmp = (double)portDataX / 32768.0 * 2.0;
                dataAccelX[i % 500] = tmp; 
                tmp = (double)portDataY / 32768.0 * 2.0;
                dataAccelY[i % 500] = tmp; 
                tmp = (double)portDataZ / 32768.0 * 2.0;
                dataAccelZ[i % 500] = tmp;

                i = (i + 1) % 500;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            formsPlot1.Render();
        }
    }
}
