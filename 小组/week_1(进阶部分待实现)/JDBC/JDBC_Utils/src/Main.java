import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
//不使用JDBCUtils
public class Main {
    public static void main(String[] args) throws Exception {
     Class.forName("com.mysql.jdbc.Driver");
     Connection conn= DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/itcast?useSSL=false&userServerPreStmts=true"
     ,"root","123456");

       String sql="update score set math=59 where id=1";
        Statement statement= conn.createStatement();
        int result = statement.executeUpdate(sql);
        System.out.println(result);
        statement.close();
        conn.close();
    }
}