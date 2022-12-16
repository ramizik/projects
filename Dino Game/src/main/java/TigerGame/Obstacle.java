package TigerGame;
import acm.graphics.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import acm.util.RandomGenerator;

public class Obstacle implements ActionListener  {
	public static final int OBSTACLE_WIDTH = 50;
	public static final int OBSTACLE_HEIGHT = 90;
	public static final int START_X = 600;
	public static final int START_Y = 280;
	private MainApplication program;
	private ObstacleType obstacleType;
	private double posX;
	private double posY;
	private double moveSpeed;
	private GImage obsImage;
	private Timer obsMoveTimer;
	public SinglePlayerModePane gameWindow;
	public RandomGenerator rgen;
	
	public Obstacle(MainApplication app, Level level) {
		rgen = RandomGenerator.getInstance();
		obsImage = randomizeObstacleImage();
		program = app;
		moveSpeed = 5;
		posX = START_X;
		if (level.isTwoPlayers() == false) {
			posY = START_Y;
		} else {
			posY = 400 + START_Y;
		}
		obsImage.move(posX, posY);
		program.add(obsImage);
		obsImage.setSize(OBSTACLE_WIDTH,OBSTACLE_HEIGHT);
		obsMoveTimer = new Timer(15, this);
		obsMoveTimer.start();
	}

	public void actionPerformed(ActionEvent e) {
		obsImage.move(-moveSpeed, 0);
	}
	
	// Generate random image for obstacle
	public GImage randomizeObstacleImage() {
		int randNum = rgen.nextInt(1,4);
		if(randNum == 1) {
			return new GImage("images/trashcan.png");
		}
		if(randNum == 2) {
			return new GImage("images/acorn.png");
		}
		if(randNum == 3) {
			return new GImage("images/bench.png");
		}
		else {
			return new GImage("images/rock.png");
		}	
	}
	
	public ObstacleType getObstacleType() {
		return obstacleType;
	}
	
	public double getX() {
		return obsImage.getX();
	}
	
	public double getY() {
		return obsImage.getY();
	}
	
	public double getWidth() {
		return obsImage.getWidth();
	}
	
	public double getHeight() {
		return obsImage.getHeight();
	}
	
	public void move(int distance) {
		obsImage.move(-distance, 0);
	}
	
	public Timer getObsMoveTimer() {
		return obsMoveTimer;
	}
}
