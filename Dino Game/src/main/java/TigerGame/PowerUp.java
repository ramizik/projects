package TigerGame;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.Timer;
import acm.graphics.*;
import acm.util.RandomGenerator;


public class PowerUp implements ActionListener {

	private MainApplication program;
	public static final int POWER_WIDTH = 65;
	public static final int POWER_HEIGHT = 65;
	public static final int START_X = 600;
	public static final int START_Y = 290;
	private PowerUpType powerType;
	private double posX;
	private double posY;
	private int moveSpeed;
	private GImage powerImage;
	private Timer powerTimer;
	public RandomGenerator rgen;

	public PowerUp(MainApplication app, Level level) {
		rgen = RandomGenerator.getInstance();
		program = app;
		moveSpeed = 5;
		posX = START_X;
		if (level.isTwoPlayers() == false) {
			posY = START_Y;
		} else {
			posY = 400 + START_Y;
		}
		randomizePowerUp(level);
		
		powerImage.move(posX, posY);
		program.add(powerImage);
		powerImage.setSize(POWER_WIDTH, POWER_HEIGHT);
		
		powerTimer = new Timer (15,this);
		powerTimer.start();
	}
		
	public void actionPerformed(ActionEvent e) {
		powerImage.move(-moveSpeed, 0);
	}
	
	// Generate random image for power-up
	public void randomizePowerUp(Level level) {
		int randNum = rgen.nextInt(1,3);
		if(randNum == 1) {
			powerImage = new GImage("images/invincibility.png");
			powerType = PowerUpType.INVINCIBILITY;
		}
		if(randNum == 2) {
			powerImage = new GImage("images/oneup.png");
			powerType = PowerUpType.ONEUP;
		}
		if(randNum == 3) {
			powerImage = new GImage("images/doublejump.png");
			powerType = PowerUpType.DOUBLEJUMP;
		}
	}	
	
	// Getters and setters
	public PowerUpType getPowerType() {
		return this.powerType;
	}
	
	public double getX() {
		return powerImage.getX();
	}

	public double getY() {
		return powerImage.getY();
	}
	
	public double getWidth() {
		return powerImage.getWidth();
	}
	
	public double getHeight() {
		return powerImage.getHeight();
	}

	public GImage getGImage() {
		return powerImage;
	}
	
	public Timer getPowerTimer() {
		return powerTimer;
	}
	
	public void setY(double posY) {
		this.posY = posY;
	}
	
	public void setX(double posX) {
		this.posX = posX;
	}

	public int getMoveSpeed() {
		return moveSpeed;
	}
	
	public void setMoveSpeed(int moveSpeed) {
		this.moveSpeed = moveSpeed;
	}
	
	public void move(int moveSpeed) {
		powerImage.move(-moveSpeed, 0);
	}

}
