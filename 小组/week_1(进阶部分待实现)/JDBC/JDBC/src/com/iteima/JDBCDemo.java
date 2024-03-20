package com.iteima;

import java.sql.Connection;
import java.sql.Driver;
import java.sql.DriverManager;
import java.sql.Statement;

public class JDBCDemo {
    public static void main(String[] args) throws Exception {
        //Class.forName("com.mysql.jdbc.Driver");

        String url="jdbc:mysql://127.0.0.1:3306/itcast?useSSL=false&userServerPreStmts=true";
        String username="root";
        String password="123456";
       Connection conn= DriverManager.getConnection(url,username,password);

        String sql ="update score set math=100 where id=1";

        Statement stmt=conn.createStatement();
        int count=stmt.executeUpdate(sql);
        System.out.println(count);

        stmt.close();
        conn.close();

    }
}
