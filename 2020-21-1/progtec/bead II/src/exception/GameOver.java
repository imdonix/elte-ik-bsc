package exception;

import main.Check;

public class GameOver extends Exception 
{
	private final Check winner;
	
	public GameOver(Check winner) {this.winner = winner;}
	
	public Check getWinner() { return winner; }
}
