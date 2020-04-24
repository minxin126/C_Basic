using System;
using MySql.Data.MySqlClient;

namespace Conmysql
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string connetStr = "server=127.0.0.1;port=3306;user=root;password=ssaa; database=itsm_fc2020;";
            // server=127.0.0.1/localhost 代表本机，端口号port默认是3306可以不写
            //using (MySqlConnection conn = new MySqlConnection(cs.ToString()))
            MySqlConnection conn = new MySqlConnection(connetStr);
            try
            {
                conn.Open();//打开通道，建立连接，可能出现异常,使用try catch语句
                Console.WriteLine("已经建立连接");
                string sqlstr1 = "SELECT * FROM icd_422;";

                //Console.WriteLine(sqlstr1);
                //在这里使用代码对数据库进行增删查改
            }
            catch (MySqlException ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                conn.Close();
            }
            string sql = "select * from icd_422;";
            MySqlCommand cmd = new MySqlCommand(sql, conn);
            //MySql.Data.MySqlClient.MySqlCommand cmd = new MySql.Data.MySqlClient.MySqlCommand(sql, conn);
            MySqlDataReader reader = cmd.ExecuteReader();//执行ExecuteReader()返回一个MySqlDataReader对象
            while (reader.Read())//初始索引是-1，执行读取下一行数据，返回值是bool
            {
                //Console.WriteLine(reader[0].ToString() + reader[1].ToString() + reader[2].ToString());
                //Console.WriteLine(reader.GetInt32(0)+reader.GetString(1)+reader.GetString(2));
                Console.WriteLine(reader.GetInt32("userid") + reader.GetString("username") + reader.GetString("password"));//"userid"是数据库对应的列名，推荐这种方式
            }
            //Console.WriteLine("Hello World!");
        }
    }
}