import com.mysql.cj.Query;
import com.mysql.cj.QueryInfo;
import com.mysql.cj.QueryResult;
import com.mysql.cj.callback.MysqlCallbackHandler;

import java.sql.*;
import java.util.logging.Handler;

public class CRUDUtils {
    public static int update(String sql, Object... params) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        int count = 0;
        try {
            //获取连接
            connection = JDBCUtils.getConnection();
            //执行查询
            preparedStatement = connection.prepareStatement(sql);
            //设置占位符
            int index = 1;
            for (Object param : params) {
                preparedStatement.setObject(index, param);
                index++;
            }
            //返回更新数据的条数
            count = preparedStatement.executeUpdate();
        } catch (Exception e) {
            //处理异常
            e.printStackTrace();
        } finally {
            //释放资源
            try {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return count;
    }

    public static <T> T query(String sql, MyHandler<T> handler, Object... params) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        ResultSet rs=null;
        try {
            //获取连接
            connection = JDBCUtils.getConnection();
            //执行查询
            preparedStatement = connection.prepareStatement(sql);
            //设置占位符
            int index = 1;
            for (Object param : params) {
                preparedStatement.setObject(index, param);
                index++;
            }
            //执行SQL语句获取结果集
             rs = preparedStatement.executeQuery();
            //处理结果集
            return handler.handle(rs);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            //释放资源
            try {
                rs.close();
                preparedStatement.close();
                connection.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return null;
    }
}
