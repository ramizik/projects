package TigerGame;

import acm.graphics.*;
 
public class PlayerManualPane extends GraphicsPane {

    private MainApplication program;
	private AudioPlayer audio = AudioPlayer.getInstance();
	public static final String MUSIC_FOLDER = "sounds";
    GImage manualPage = new GImage("images/player_manual.png");
    public GRect backButton = new GRect(25,22,86,34);

    public PlayerManualPane(MainApplication app) {
        super();
        program = app;
        backButton.setLineWidth(0);
		audio.playSound(MUSIC_FOLDER, "MMenu.mp3");

    }

    public void clickedAt(GObject objIn) {
        if (objIn == backButton) {
        	program.switchToMainMenu();
        }
    }
    
    @Override
    public void showContents() {
        program.add(manualPage);
        program.add(backButton);

    }

    @Override
    public void hideContents() {
        program.remove(manualPage);
        program.remove(backButton);
    }

			
	}