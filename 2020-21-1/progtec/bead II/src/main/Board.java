package main;

import exception.OutOfRangeException;

public class Board 
{

    private Field[][] board;
    private final int boardSizeX;
    private final int boardSizeY;
    private Check currPlayer;

    public Board(int boardSizeX, int boardSizeY) 
    {
        this.boardSizeX = boardSizeX;
        this.boardSizeY = boardSizeY;
        this.currPlayer = Check.None;
        board = new Field[this.boardSizeX][this.boardSizeY];
        
        for (int i = 0; i < this.boardSizeX; ++i) 
            for (int j = 0; j < this.boardSizeY; ++j) 
                board[i][j] = new Field();
        
        currPlayer = currPlayer.Swap();
    }
    
    public Field get(int x, int y) { return board[x][y];  }
    
    public int getBoardSizeX() { return boardSizeX; }
    
    public int getBoardSizeY() { return boardSizeY; }
    
    public Check getCurrentPlayer() { return currPlayer; }
    
	public Point push(int y) throws OutOfRangeException 
	{
		for(int x = boardSizeX - 1; x >= 0; x--)
			if(board[x][y].getState().equals(Check.None))
			{
				board[x][y].setState(currPlayer);
				currPlayer = currPlayer.Swap();
				return new Point(x,y);
			}
		throw new OutOfRangeException();
	}

    public boolean isOver() 
    {
        for (int i = 0; i < boardSizeX; i++) 
            for (int j = 0; j < boardSizeY; j++) 
                if (board[i][j].getState().equals(Check.None)) 
                    return false;
        return true;
    }

	public Check getWinner()
	{
		Check winner = checkLeves();
		if(winner.isPlayer()) return winner;
		winner = checkDiagonal(true);
		if(winner.isPlayer()) return winner;
		winner = checkDiagonal(false);
		if(winner.isPlayer()) return winner;
		return Check.None;
	}
	
	
	private Check checkLeves()
	{		
		for(int x = 0; x < boardSizeX; x++)
		{
			Check winner = checkLine(board[x]);
			if(winner.isPlayer())
				return winner;
		}
		
		return Check.None;		
	}
		
	private Check checkLine(Field[] line)
	{
		int count = 0;
		Check f = Check.None;
		for(Field field : line)
		{
			if(field!=null)
				if(field.getState().equals(f)) 
					count++;
				else
				{
					f = field.getState();
					count = 0;
				}
				
			if(count > 2 && !f.equals(Check.None))
				return f;
		}
		return Check.None;
	}
	
	private Check checkDiagonal(boolean rtl)
	{
		Field[][] flattened = getFlatterMatrix(board, rtl);
		int x = 0;
		for(Check winner = checkLine(flattened[x]); x < flattened.length; winner = checkLine(flattened[x++]))
			if(winner.isPlayer())
				return winner;
		return Check.None;
	}
	

	public static Field[][] getFlatterMatrix(Field[][] matrix, boolean rightToLeft)
	{
		final int sizeX = matrix.length;
		final int sizeY = matrix[0].length;
		final int min = sizeX < sizeY ? sizeX : sizeY;
		final int dir = rightToLeft ? 1 : -1;
		Field[][] flattened = new Field[sizeX + sizeY - 1][min];
		for(int y = rightToLeft ? -sizeX + 1 : sizeX + sizeY - 2, c = 0; rightToLeft ? y < sizeY : y >= 0 ; y+=dir, c++)
		{
			int d = 0;
			for(int x = 0; x < sizeX; x++) 
				if(y+dir*x>=0 && y+dir*x<sizeY)
					flattened[c][d++] = matrix[x][y + dir*x];
		}
		
		return flattened;		
	}

}
