package tron;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;


public class Database 
{

	private final PreparedStatement insertStatement;
    private final PreparedStatement countStatement;
    private final PreparedStatement toplistStatement;
    private final Connection connection;
    
    public Database() throws SQLException 
    {
        Properties connectionProps = new Properties();

        connectionProps.put("user", "tanulo");
        connectionProps.put("password", "asd123");
        connectionProps.put("serverTimezone", "UTC");
        String dbURL = "jdbc:mysql://localhost:3306/highscores";
        connection = DriverManager.getConnection(dbURL, connectionProps);
        
        
        String insertQuery = "INSERT INTO HIGHSCORES (time, name) VALUES (?, ?)";
        insertStatement = connection.prepareStatement(insertQuery);
        String countQuery = "SELECT COUNT(name) AS score FROM highscores WHERE name=?";
        countStatement = connection.prepareStatement(countQuery);
        String toplistQuery = "SELECT name, COUNT(name) AS score FROM highscores GROUP BY name ORDER BY score DESC";
        toplistStatement = connection.prepareStatement(toplistQuery);
    }

    public int getWins(String name) throws SQLException 
    {        
        countStatement.setString(1, name);
        ResultSet results = countStatement.executeQuery();
        results.next();
        return results.getInt("score");
    }

    public void insertWin(String name) throws SQLException 
    {
        Timestamp ts = new Timestamp(System.currentTimeMillis());
        insertStatement.setTimestamp(1, ts);
        insertStatement.setString(2, name);
        insertStatement.executeUpdate();
    }
    
    public List<String> getToplist() throws SQLException 
    {
    	List<String> collector = new ArrayList<String>();
    	ResultSet results = toplistStatement.executeQuery();
    	while(results.next())
    		collector.add(results.getString("name") + " - " + results.getInt("score"));
    	return collector;
    }

}
