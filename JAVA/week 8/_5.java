// 5. Write JDBC program to insert records to a table using JDBC connection.

import java.sql.*;

public class _5 {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager
                    .getConnection("jdbc:mysql://localhost:3306/java_lab", "root", "root");
            Statement stmt = con.createStatement();
            stmt.executeUpdate("insert into student values(3,'Rahul','CSE')");
            ResultSet rs = stmt.executeQuery("select * from student");
            while (rs.next())
                System.out.println(rs.getInt(1) + "  " + rs.getString(2) + "  " + rs.getString(3));
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}