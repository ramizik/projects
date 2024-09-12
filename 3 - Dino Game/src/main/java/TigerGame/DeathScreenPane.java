package TigerGame;

import acm.graphics.GImage;
import acm.graphics.GObject;
import acm.graphics.GRect;

public class DeathScreenPane extends GraphicsPane {
	
    private MainApplication program;
    public boolean isTwoPlayer;
    private AudioPlayer audio = AudioPlayer.getInstance();
    public static final String MUSIC_FOLDER = "sounds";	
    private GImage gameOver = new GImage("images/game-over.png");
    // button 1: try again
    public GRect but1 = new GRect(174,92,251,54);
    // button 2: main menu
    public GRect but2 = new GRect(174,159,251,54);
    public boolean minimizeScreen;

    public DeathScreenPane(MainApplication app, boolean isTwoPlayers) {
        super();
        program = app;
        program.add(gameOver);
        but1.setLineWidth(0);
        but2.setLineWidth(0);
        isTwoPlayer = isTwoPlayers;   
    }

    public void clickedAt(GObject objIn) {
        if (objIn == but1 && isTwoPlayer == false) {
        	audio.stopSound(MUSIC_FOLDER, "GMusic.mp3");
            program.switchToSinglePlayer();
            program.setSize(MainApplication.WINDOW_WIDTH, MainApplication.WINDOW_HEIGHT);
        }
        else if(objIn == but1 && isTwoPlayer == true) {
        	audio.stopSound(MUSIC_FOLDER, "GMusic.mp3");
        	program.switchToMultiPlayer();
        }
        else if(objIn == but2) {
        	audio.stopSound(MUSIC_FOLDER, "GMusic.mp3");
        	program.removeAll();
            program.switchToMainMenu();
            program.setSize(MainApplication.WINDOW_WIDTH, MainApplication.WINDOW_HEIGHT);
        } 
    }

    @Override
    public void showContents() {
        program.add(but1);
        program.add(but2);
    }

    @Override
    public void hideContents() {
        program.remove(but1);
        program.remove(but2);
    }

}
