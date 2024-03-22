import java.sql.ResultSet;
import java.util.logging.Handler;

public interface MyHandler<T>   {
    T handle(ResultSet rs) throws Exception;
}
