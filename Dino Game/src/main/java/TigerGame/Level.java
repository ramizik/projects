package TigerGame;
import acm.graphics.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import acm.util.RandomGenerator;
import javax.swing.*;

public class Level implements ActionListener  {

	private MainApplication program;
	private RandomGenerator rgen;
	public Player player;
	private Timer NewObstacleTimer;
	private Timer collisionCheckTimer;
	private Timer powerUpTimer;
	public boolean isSecond;
	private ArrayList<MapElement> clouds;
	private ArrayList<MapElement> bushes;
	private ArrayList<Obstacle> obstacles;
	private ArrayList<PowerUp> powers;
	GImage backgroundImg = new GImage("images/blank_background.png");

	public Level(MainApplication app, boolean secondPlayer) {
		super();
		int scaleY = 0;
		if (secondPlayer == true) {
			isSecond = true;
			scaleY = 400;
		} else {
			isSecond = false;
			scaleY = 0;
		}
		rgen = RandomGenerator.getInstance();
		program = app;
		program.add(backgroundImg, 0, 0 + scaleY);
		
		// Add clouds
		clouds = new ArrayList<MapElement>();
		for(int i = 0; i <= 2; i++) {
			clouds.add(new MapElement(program, MapElementType.CLOUD, i * 200, 0 + scaleY,this));
		}

		// Add bushes
		bushes = new ArrayList<MapElement>();
		for(int i = 0; i <= 1; i++) {
			bushes.add(new MapElement(program, MapElementType.BUSH, i * 370, 0 + scaleY,this));
		}

		// Add obstacles
		obstacles = new ArrayList<Obstacle>();

		// Add player
		player = new Player(program, this);
		
		// Add powerUp
		powers = new ArrayList<PowerUp>();
		
		// Add timer
		NewObstacleTimer = new Timer(rgen.nextInt(2000,4000), this);
		NewObstacleTimer.start();
		
		powerUpTimer = new Timer(rgen.nextInt(5000,7000), this);
		powerUpTimer.start();
		
		collisionCheckTimer = new Timer(100, this);
		collisionCheckTimer.start();
	}

	public void actionPerformed(ActionEvent e) {
		// Generate obstacles on the screen
		if (e.getSource() == NewObstacleTimer) {
			obstacles.add(new Obstacle(program, this));
			NewObstacleTimer.stop();
			NewObstacleTimer = new Timer(rgen.nextInt(1000,2000), this);
			NewObstacleTimer.start();
		}

		// Loop through each obstacle & check collision
		for(Obstacle obstacle: obstacles) {
			if(obstacle != null) {
				if(player.isCollided(obstacle)) {
					System.out.println("Player has collided with obstacle");
					stopAllTimersOnce();
					// Show game over menu
					program.switchToDeathScreenPane();
					
				}
				if(obstacle.getX() + obstacle.getWidth() < 0) {
					obstacles.remove(obstacle);
					break;
					
				}
			}
		}
		// Generate power-up
		if(e.getSource() == powerUpTimer) {
			powers.add(new PowerUp(program,this));
			powerUpTimer.stop();
			powerUpTimer = new Timer(rgen.nextInt(8000, 12000), this);
			powerUpTimer.start();
		}

		// Loop through each power-up and check collision
		for(PowerUp power: powers) {
			if(power != null) {
				if(player.isCollided(power)) {
					program.remove(power.getGImage());
				}
				if(power.getX() + power.getWidth() < 0) {
					powers.remove(power);
					break;
				}
			}
		}
		
	}

	public void stopAllTimersOnce() {
		for(Obstacle obs: obstacles) {
			obs.getObsMoveTimer().stop();
		}
		for(MapElement cloud: clouds) {
			cloud.getObsMoveTimer().stop();
		}
		for(MapElement bush: bushes) {
			bush.getObsMoveTimer().stop();
		}
		for(PowerUp power: powers) {
			power.getPowerTimer().stop();
		}
		player.getGravityTimer().stop();
		NewObstacleTimer.stop();
		collisionCheckTimer.stop();	
		powerUpTimer.stop();
	}
	
	public void jump(GObject playerIn) {
		player.jump();
	}

	public void gravity(GObject playerIn) {
		player.fall();
	}
	
	public boolean isTwoPlayers() {
		return 	isSecond;
	}

}