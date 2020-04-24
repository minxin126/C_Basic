using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    internal static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        private static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}

//using System;
//using System.Windows.Forms;

//using Microsoft.Office.Interop.Excel;
//using System.Data.SqlClient;

//namespace WindowsFormsApp1
//{
//    public partial class Form1 : Form
//    {
//        public Form1()
//        {
//            InitializeComponent();
//        }

//        private void button1_Click(object sender, EventArgs e)
//        {
//            //保存文件对话框
//            SaveFileDialog sfd = new SaveFileDialog();
//            sfd.Filter = "Excel文件|*.xlsx|Word文件|*.docx";
//            sfd.FilterIndex = 0;
//            if (sfd.ShowDialog() == DialogResult.OK)
//            {
//                //连接数据库，查询数据
//                using (SqlConnection conn = new SqlConnection(@"server=pc;database=Mytest;trusted_connection=true"))
//                {
//                    using (SqlDataAdapter sda = new SqlDataAdapter("select * from Table_2", conn))
//                    {
//                        using (System.Data.DataTable dt = new System.Data.DataTable())
//                        {
//                            //将数据库中查到的数据填充到DataTable数据表
//                            sda.Fill(dt);
//                            //调用导出Excel的方法，传入DataTable数据表和路径
//                            ExportExcel(dt, sfd.FileName);
//                        }
//                    }
//                }
//            }
//        }

//        private void ExportExcel(System.Data.DataTable dt, string filepath)
//        {
//            //创建Excel应用程序类的一个实例，相当于从电脑开始菜单打开Excel
//            ApplicationClass xlsxapp = new ApplicationClass();
//            //新建一张Excel工作簿
//            Workbook wbook = xlsxapp.Workbooks.Add(true);
//            //第一个sheet页
//            Worksheet wsheet = (Worksheet)wbook.Worksheets.get_Item(1);
//            //将DataTable的列名显示在Excel表第一行
//            for (int i = 0; i < dt.Columns.Count; i++)
//            {
//                //注意Excel表的行和列的索引都是从1开始的
//                wsheet.Cells[1, i + 1] = dt.Columns[i].ColumnName;
//            }
//            //遍历DataTable，给Excel赋值
//            for (int i = 0; i < dt.Rows.Count; i++)
//            {
//                for (int j = 0; j < dt.Columns.Count; j++)
//                {
//                    //从第二行第一列开始写入数据
//                    wsheet.Cells[i + 2, j + 1] = dt.Rows[i][j];
//                }
//            }
//            //保存文件
//            wbook.SaveAs(filepath);
//            //释放资源
//            xlsxapp.Quit();
//        }

//        private static void Main()
//        {
//            Application.EnableVisualStyles();
//            Application.SetCompatibleTextRenderingDefault(false);
//            Application.Run(new Form1());
//        }
//    }
//}