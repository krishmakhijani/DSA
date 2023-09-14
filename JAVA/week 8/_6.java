// 6. Write JDBC program to update contents of a library management system using JDBC
// connection.

import java.sql.*;

public class _6 {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager
                    .getConnection("jdbc:mysql://localhost:3306/java_lab", "root", "root");
            Statement stmt = con.createStatement();
            stmt.executeUpdate("update student set name='Rahul' where id=1");
            ResultSet rs = stmt.executeQuery("select * from student");
            while (rs.next())
                System.out.println(rs.getInt(1) + "  " + rs.getString(2) + "  " + rs.getString(3));
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}