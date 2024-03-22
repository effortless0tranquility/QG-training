/*测试CRUDUtils*/


import java.util.List;

public class test2 {
    public static void main(String[] args) {
        String sql="update score set math= ? where id= ?";
        int count=CRUDUtils.update(sql,11,1);
        System.out.println(count);

        String sql1="select * from score ";
        List<Student> list=CRUDUtils.query(sql1,new Thandler<>(Student.class));
        for (Student student : list) {
            System.out.println(student);
        }
    }
}
