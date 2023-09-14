// 7. Write a simple application program to establish JDBC query execution using
// PreparedStatement.

import java.sql.*;

public class _7 {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            Connection con = DriverManager
                    .getConnection("jdbc:mysql://localhost:3306/java_lab", "root", "root");
            PreparedStatement stmt = con.prepareStatement("select * from student where id=?");
            stmt.setInt(1, 1);
            ResultSet rs = stmt.executeQuery();
            while (rs.next())
                System.out.println(rs.getInt(1) + "  " + rs.getString(2) + "  " + rs.getString(3));
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}