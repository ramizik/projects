package TigerGame;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.Timer;

import acm.graphics.GLabel;

public class MultiPlayerMode extends GraphicsPane implements ActionListener {
	
	public static final int WINDOW_WIDTH = 600;
	public static final int WINDOW_HEIGHT = 436;
	private MainApplication program;
	private Timer collisionCheckTimer;
	public Level LevelTwo;
	public Level LevelOne;
	public GLabel winLabel;

	public MultiPlayerMode(MainApplication app) {
		super();
		program = app;
		program.setSize(WINDOW_WIDTH, WINDOW_HEIGHT * 2);
		LevelOne = new Level(program, false);
		LevelTwo = new Level(program, true);
		collisionCheckTimer = new Timer(100, this);
		collisionCheckTimer.start();
		winLabel = new GLabel("");
	}
	
	
	@Override
	public void showContents() {
		program.remove(winLabel);
	}

	@Override
	public void hideContents() {
		program.remove(winLabel);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (LevelOne.player.continueGame == false || LevelTwo.player.continueGame == false) {
			collisionCheckTimer.stop();
			if (LevelOne.player.continueGame == false) {
				winLabel = new GLabel("Player 2 WON!");
			}else if (LevelTwo.player.continueGame == false) {
				winLabel = new GLabel("Player 1 WON!");
			}
			program.add(winLabel);
			winLabel.setFont(new Font("Serif", Font.BOLD, 30));
			winLabel.setLocation(200, 500);
			winLabel.setColor(Color.black);
			LevelOne.stopAllTimersOnce();
			LevelTwo.stopAllTimersOnce();
		}
	}
}
