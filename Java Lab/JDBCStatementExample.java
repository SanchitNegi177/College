import java.sql.*;

public class JDBCStatementExample {
    // JDBC driver name and database URL
    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver"; 
    static final String DB_URL = "jdbc:mysql://localhost:3306/employeedb";
    
    // Database credentials
    static final String USER = "root";
    static final String PASS = "";

    public static void main(String[] args) 
    {
        Connection conn = null;
        Statement stmt = null;
        try {
            //STEP 2: Register JDBC driver
            Class.forName(JDBC_DRIVER);
            
            //STEP 3: Open a connection
            System.out.println("Connecting to database...");
            conn = DriverManager.getConnection(DB_URL, USER, PASS);
            
            //STEP 4: Execute an update query
            System.out.println("Creating statement...");
            stmt = conn.createStatement();
            
            // Parameters
            int empcode = 999;
            String empname = "AAA";
            
            // SQL update statement
            String sql = "UPDATE pers SET empcode = " + empcode + " WHERE empname = '" + empname + "'";
            int rows = stmt.executeUpdate(sql);
            System.out.println("Rows impacted: " + rows);
            
            // Let us select all the records and display them.
            sql = "SELECT * FROM pers";
            ResultSet rs = stmt.executeQuery(sql);
            
            //STEP 5: Extract data from result set
            System.out.println("Employee Code\t Employee Name\t Designation \t Department No.");
            while (rs.next()) {
                // Retrieve by column name
                System.out.print(rs.getInt("empcode") + "\t");
                System.out.print(rs.getString("empname") + "\t");
                System.out.print(rs.getString("designation") + "\t");
                System.out.println(rs.getInt("dno"));
            }
            // Clean-up environment
            rs.close();
            stmt.close();
            conn.close();
        } catch (SQLException se) {
            // Handle errors for JDBC
            se.printStackTrace();
        } catch (Exception e) {
            // Handle errors for Class.forName
            e.printStackTrace();
        }
        System.out.println("Goodbye!");
    } // End main
} // End JDBCStatementExample
