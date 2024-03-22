import java.beans.BeanInfo;
import java.beans.Introspector;
import java.beans.PropertyDescriptor;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class Thandler<T> implements MyHandler<List<T>>{
    private Class<T> tClass;
    public Thandler(Class<T> tClass){
        this.tClass=tClass;
    }

    @Override
    public List<T> handle(ResultSet rs) throws Exception {
        BeanInfo beanInfo= Introspector.getBeanInfo(tClass,Object.class);

        PropertyDescriptor[]pds=beanInfo.getPropertyDescriptors();
        List<T>list=new ArrayList<>();
        while(rs.next()){
            T obj=tClass.newInstance();

            for (PropertyDescriptor pd : pds) {
                Object object=rs.getObject(pd.getName());

                pd.getWriteMethod().invoke(obj,object);
            }
            list.add(obj);

        }
        return list;
    }
}
