package TigerGame;

import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

import acm.graphics.*;

public class MainApplication extends GraphicsApplication implements ActionListener {

	// constant variables
	public static final int WINDOW_WIDTH = 600;
	public static final int WINDOW_HEIGHT = 436;
	public static final int GRAVITY_TIMER_MS = 200;
	public static final int ARROW_KEY = 38;
	public static final int W_KEY = 87;
	public static final int GAME = 0;
	public static final int JUMP = 1;
	public static final int MENU = 2;
	public static final int POWERUP = 3;
	
	public static final String MUSIC_FOLDER = "";	
	
	public ArrayList<Sound> sounds = new ArrayList<Sound>() {
		{
			add(new Sound(SoundType.GAME));
			add(new Sound(SoundType.JUMP));
			add(new Sound(SoundType.MENU));
			add(new Sound(SoundType.POWERUP));
		}
	};

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
		audio.playSound(MUSIC_FOLDER, sounds.get(MENU).location(MENU));
		switchToScreen(mainMenu);
	}

	public void switchToManual() {
		switchToScreen(manualMenu);
		audio.playSound(MUSIC_FOLDER, sounds.get(MENU).location(MENU), true);
	}

	public void switchToSinglePlayer() {
		singleMenu = new SinglePlayerModePane(this);
		isTwoPlayers = false;
		switchToScreen(singleMenu);
		audio.stopSound(MUSIC_FOLDER, sounds.get(MENU).location(MENU));
		audio.playSound(MUSIC_FOLDER, sounds.get(GAME).location(GAME), true);
	}

	public void switchToMultiPlayer() {
		multiMenu = new MultiPlayerMode(this);
		isTwoPlayers = true;
		switchToScreen(multiMenu);
		audio.stopSound(MUSIC_FOLDER, sounds.get(MENU).location(MENU));
		audio.playSound(MUSIC_FOLDER, sounds.get(GAME).location(GAME), true);
	}

	public void switchToDeathScreenPane() {
		audio.stopSound(MUSIC_FOLDER, sounds.get(GAME).location(GAME));
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
			manualMenu.clickedAt(button);
		}
		if (curScreen == gameOverMenu) { 
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
			if (e.getKeyCode() == ARROW_KEY) {		
				multiMenu.LevelOne.player.jump();
			} else if (e.getKeyCode() == W_KEY) {		
				multiMenu.LevelTwo.player.jump();
			}
		}

	}

	public static void main(String[] args) {
		new MainApplication().start();
	}
}