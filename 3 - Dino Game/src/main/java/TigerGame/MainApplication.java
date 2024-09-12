package TigerGame;

import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;

import acm.graphics.*;

public class MainApplication extends GraphicsApplication implements ActionListener {

	public static final int WINDOW_WIDTH = 600;
	public static final int WINDOW_HEIGHT = 436;
	public static final int GRAVITY_TIMER_MS = 200;
	public static final String MUSIC_FOLDER = "sounds";	

	public int windowWidth = 600;
	public int windowHeight = 436;
	public StartMenuPane mainMenu;
	public PlayerManualPane manualMenu;
	public SinglePlayerModePane singleMenu;
	public MultiPlayerMode multiMenu;
	public DeathScreenPane gameOverMenu;
	private AudioPlayer audio = AudioPlayer.getInstance();
	public boolean isTwoPlayers;

	public void init() {
		setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	}

	public void run() {
		// Loads main menu pane
		mainMenu = new StartMenuPane(this);		
		// Loads player manual pane
		manualMenu = new PlayerManualPane(this);
		// Loads game over menu
		gameOverMenu = new DeathScreenPane(this, isTwoPlayers);
		setupInteractions();		
		// Initially loads main menu
		switchToMainMenu();		
	}

	public void switchToMainMenu() {
		audio.playSound(MUSIC_FOLDER, "MMenu.mp3");
		switchToScreen(mainMenu);
	}

	public void switchToManual() {
		switchToScreen(manualMenu);
		audio.playSound(MUSIC_FOLDER, "MMenu.mp3");

	}

	public void switchToSinglePlayer() {
		singleMenu = new SinglePlayerModePane(this);
		isTwoPlayers = false;
		switchToScreen(singleMenu);
		audio.playSound(MUSIC_FOLDER, "GMusic.mp3", true);
	}

	public void switchToMultiPlayer() {
		multiMenu = new MultiPlayerMode(this);
		isTwoPlayers = true;
		switchToScreen(multiMenu);
		audio.playSound(MUSIC_FOLDER, "GMusic.mp3", true);
	}

	public void switchToDeathScreenPane() {
		gameOverMenu = new DeathScreenPane(this, isTwoPlayers);
		switchToScreen(gameOverMenu);
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// Get where the mouse cursor is when clicked
		GObject button = getElementAt(e.getX(), e.getY());	
		
		if (curScreen == mainMenu) { 
			mainMenu.clickedAt(button);
		} 
		else if (curScreen == manualMenu) {
			audio.playSound(MUSIC_FOLDER, "MMenu.mp3");
			manualMenu.clickedAt(button);
		}
		if (curScreen == gameOverMenu) { 
			audio.pauseSound(MUSIC_FOLDER, "MMenu.mp3");
			gameOverMenu.clickedAt(button);
		} 
	}

	@Override
	public void keyPressed(KeyEvent e) {
		
		if (isTwoPlayers == false) {
			if (e.getKeyCode() == 38) {		
				// Jump function from player from level one from SingleMenu
				singleMenu.LevelOne.player.jump();
			}
		}
		else {
			if (e.getKeyCode() == 38) {		
				multiMenu.LevelOne.player.jump();
			} else if (e.getKeyCode() == 87) {		
				multiMenu.LevelTwo.player.jump();
			}
		}

	}

	public static void main(String[] args) {
		new MainApplication().start();
	}
}