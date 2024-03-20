import java.io.FileReader;
import java.sql.*;
import java.util.Properties;

public class JDBCUtils {

    private static  String url  ;
    private static  String user ;
    private static  String password;

    static {
        //获取配置文件
        Properties properties=new Properties();
        try {
            //加载配置文件
            properties.load((new FileReader("src/jdbc.properties")));
            url=properties.getProperty("url");
            user=properties.getProperty("user");
            password=properties.getProperty("password");
            //注册驱动
            Class.forName(properties.getProperty("driver"));

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public static Connection getConnection()  {
        Connection connection=null;
        try {
            //获取连接
            connection= DriverManager.getConnection(url,user,password);
        } catch (Exception e) {
           e.printStackTrace();
        }
        //返回对象
        return connection;
    }
    public static void close( Statement statement,Connection connection,ResultSet... set) throws Exception {
        for (ResultSet resultSet : set) {
            resultSet.close();
        }
        statement.close();
        connection.close();

    }
}
