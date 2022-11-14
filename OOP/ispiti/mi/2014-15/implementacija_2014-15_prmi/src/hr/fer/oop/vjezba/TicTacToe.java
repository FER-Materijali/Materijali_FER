package hr.fer.oop.vjezba;

import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

/**
 * Fourth task from midterm exam.
 * 
 * @author KarloVrbic
 * @version 1.0
 */
public class TicTacToe {
	private String[] board = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
	private int[][] winCombo = {{0, 1, 2}, {0, 3, 6}, {0, 4, 8},
								{3, 4, 5}, {1, 4, 7}, {2, 4, 6},
								{6, 7, 8}, {2, 5, 8}};
	private String player = "X";
	private boolean human = true;
	private boolean computer = false;
	private String humanChar = "X";
	private String computerChar = "O";
	private double difficulty = 1.0;
	
	/**
	 * Main method used for testing purposes
	 * @param args Not used
	 */
	public static void main(String[] args){
		TicTacToe game = new TicTacToe();
		Scanner scan = new Scanner(System.in);
		boolean gameIsON = true;
		
		while(true){
			String choice = "X";
			Integer diff = 1;
			boolean flag = false;
			
			do{
				System.out.println("Choose(X/O):");
				choice = scan.next();
			} while(!choice.toUpperCase().equals("X") && !choice.toUpperCase().equals("O"));
			
			do{
				System.out.println("Enter difficulty(1/2/3): ");
				try{
					diff = (Integer) scan.nextInt();
					flag = true;
				} catch(InputMismatchException e){
					flag = false;
				}
			} while(!flag);
			
			game.initialize(choice, diff);
			game.displayBoard();
			
			while(gameIsON){
				boolean notGood;
				
				do{
					try{
						if(game.human){
							System.out.println("Player " + game.getPlayer() + " input your move:");
							Integer moveDecision = 0;

							do{
								try{
									moveDecision = (Integer) scan.nextInt();
									flag = true;
								}catch (InputMismatchException e){
									flag = false;
								}
								
								if(moveDecision < 1 && moveDecision > 9){
									flag = false;
								}
							}while(!flag);
							
							moveDecision--;
							game.move(moveDecision, game.getPlayer());
						}
						else if(game.computer)
							game.move(game.getComputerMove(), game.getPlayer());
						notGood = false;
					}catch(IllegalArgumentException e){
						notGood = true;
						if(e.toString().endsWith("Place index out of range."))
							System.out.println("Place index out of range.");
						else if(e.toString().endsWith("This place is taken."))
							System.out.println("This place is taken.");
					}
				}while(notGood);
				
				game.changePlayer();
				game.changeOrder();
				
				game.clearScreen();
				game.displayBoard();
				int score = game.checkScore();
				if(score == 1){
					if(game.isHuman("X"))
						System.out.println("You(\"X\") won.");
					else
						System.out.println("Computer(\"X\") won.");
					gameIsON = false;
				}
				else if(score == 2){
					if(game.isHuman("O"))
						System.out.println("You(\"O\") won.");
					else
						System.out.println("Computer(\"O\") won.");
					gameIsON = false;
				}
				else if(score == 3){
					System.out.println("It's a draw");
					gameIsON = false;
				}
			}
				
			System.out.println("Do you want to play again?(y/n)");
			
			if(scan.next().toLowerCase().equals("n")){
				System.out.println("Thank you for playing!");
				scan.close();
				return;
			}
			else{
				gameIsON = true;
			}
			game.clearScreen();
		}
	}
	
	/**
	 * Method used for initializing game(It is necessary to do it before playing new game)
	 * @param choice Players choice of character("X"/"O")
	 * @param diff Difficulty level(1/2/3)
	 */
	public void initialize(String choice, Integer diff){
		this.player = "X";
		
		this.human = true;
		this.computer = false;
		
		this.humanChar = "X";
		this.computerChar = "O";
		
		for(int i = 0; i < 9; i++)
			this.clearPlace(i);
		
		this.choosePlayer(choice);
		this.getDifficulty(diff);
		
		this.clearScreen();
	}
	
	/**
	 * Method used for getting difficulty
	 * @param diff Integer which we use to determine difficulty(1 = easy, 2 = medium, 3 = hard)
	 */
	private void getDifficulty(final int diff){
		switch(diff){
		case 1:		this.difficulty = 0.5;
					break;
		case 2:		this.difficulty = 0.7;
					break;
		case 3:		this.difficulty = 0.9;
					break;
		default:	this.difficulty = 1.0;
		}
	}

/**
 * Method for clearing the screen
 */
public void clearScreen(){
	for (int i = 0; i < 25; i++) {
        System.out.println();
    }
}
	
	/**
	 * Method which returns current player
	 * @return Current player
	 */
	public String getPlayer(){
		return this.player;
	}
	
	/**
	 * Examines if character in parameter is used by human or computer
	 * @param character Holds value of character we want to test
	 * @return True if human player is using character from parameter or false otherwise
	 */
	public boolean isHuman(String character){
		return character.equals(this.humanChar);
	}
	
	/**
	 * Examines if a place on board is free
	 * @param position Position on board
	 * @return True if that place is free and false otherwise
	 */
	private boolean isFree(int position){
		return this.board[position] == " ";
	}
	
	/**
	 * Clears place on board
	 * @param position Position on board
	 */
	private void clearPlace(int position){
		this.board[position] = " ";
	}
	
	/**
	 * Method used for displaying board on standard output
	 */
	private void displayBoard(){
		System.out.println("-------------");
		for (int i = 0; i <= 6; i += 3) {
			System.out.print("| ");
			for (int j = 1; j <= 3; j++)
					System.out.print(board[i + j - 1] + " | ");
			System.out.println();
			System.out.println("-------------");
		}
	}
	
	/**
	 * Method used for choosing human player
	 * @param choice Character user chose for himself
	 */
	public void choosePlayer(String choice){		
		if(choice.toUpperCase().equals("X")){
			this.human = true;
			this.computer = false;
			this.humanChar = "X";
			this.computerChar = "O";
		}
		else if(choice.toUpperCase().equals("O")){
			this.human = false;
			this.computer = true;
			this.humanChar = "O";
			this.computerChar = "X";
		}
		else
			throw new IllegalArgumentException("You need to choose between \"X\" or \"O\"");
	}
	
	/**
	 * Method used for changing player
	 */
	public void changePlayer(){
		if(this.player.equals("X"))
			this.player = "O";
		else
			this.player = "X";
	}
	
	/**
	 * Method which determines if next turn should be played by human or computer player
	 */
	public void changeOrder(){
		this.human = !this.human;
		this.computer = !this.computer;
	}
	
	/**
	 * Method which checks score
	 * @return 0 if score isn't determined yet, 1 if "X" won, 2 if "O" won and 3 if it's a draw
	 */
	public int checkScore(){
		for(int[] i : winCombo)
			if((this.board[i[0]] == this.board[i[1]] && this.board[i[1]]== this.board[i[2]]) && !this.isFree(i[0])){
				if(this.board[i[0]] == "X")
					return 1;
				if(this.board[i[0]] == "O")
					return 2;
			}
		
		boolean draw = true;
		for(String position : this.board)
			if(position.equals(" ")){
					draw = false;
					break;
			}
		
		if(draw)
			return 3;
		
		return 0;
	}
	
	/**
	 * Method used for placing character on board
	 * @param position Position where we will be placing character
	 * @param character Character we want to place on board
	 */
	public void move(Integer position, String character){
		if(position < 0 || position > 8)
			throw new IllegalArgumentException("Place index out of range.");
		if(!this.isFree(position))
			throw new IllegalArgumentException("This place is taken.");
		
		this.board[position] = character;
	}
	
	/**
	 * Method used for getting computers move.
	 * @return Position where we will be placing computers character
	 */
	public int getComputerMove(){
		Random rand = new Random();	
		int pos = 0;
		
		// if computer has chance to win
		for(pos = 0; pos < 9; pos++)
			if(this.isFree(pos)){
				board[pos] = this.computerChar;
				if(this.checkScore() == 1 || this.checkScore() == 2){
					this.clearPlace(pos);
					return pos;
				}
				else
					this.clearPlace(pos);
			}
		
		// if computer has a chance to block human(defined by difficulty)
		double chanceOfBlocking = rand.nextDouble();
		if(chanceOfBlocking <= this.difficulty){
			for(pos = 0; pos < 9; pos++)
				if(this.isFree(pos)){
					board[pos] = this.humanChar;
					if(this.checkScore() == 1 || this.checkScore() == 2){
						this.clearPlace(pos);
						return pos;
					}
					else
						this.clearPlace(pos);
				}
		}
		
		//random
		do{																
			pos = rand.nextInt(9) + 1;
		} while(!this.isFree(pos - 1));
		
		return pos - 1;
	}
	
	/**
	 * Alternative to getComputerMove()(Use is same as getComputerMove() but it is done randomly in every case)
	 * @return Position where we will be placing computers character
	 */
	public int getComputerMoveAlt(){
		Random rand = new Random();
		int pos = 0;
		
		do{
			pos = rand.nextInt(9) + 1;
		} while(!this.isFree(pos - 1));
		
		return pos - 1;
	}
}
