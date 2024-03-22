import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/*使用JDBCUtils*/



public class test {
    public static void main(String[] args) throws Exception {
        Connection connection=JDBCUtils.getConnection();

        String sql="update score set math=100 where id=1";
        Statement statement= connection.createStatement();
        int result=statement.executeUpdate(sql);
        System.out.println(result);
        JDBCUtils.close(statement,connection);


    }
}
