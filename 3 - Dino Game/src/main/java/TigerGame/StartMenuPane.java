package TigerGame;
import acm.graphics.*;


public class StartMenuPane extends GraphicsPane {

    private MainApplication program;
	private AudioPlayer audio = AudioPlayer.getInstance();
	public static final String MUSIC_FOLDER = "sounds";
    GImage background = new GImage("images/start_menu.png");
    GImage manualPage = new GImage("images/player_manual.png");
    // Button 1: Single-player
    public GRect but1 = new GRect(172,136,255,54);
    // Button 2: Multi-player
    public GRect but2 = new GRect(172,209,255,54);
    // Button 3: Player manual
    public GRect but3 = new GRect(172,281,255,54);

    public StartMenuPane(MainApplication app) {
        super();
        program = app;
        but1.setLineWidth(0);
        but2.setLineWidth(0);
        but3.setLineWidth(0);
        
    }

    public void clickedAt(GObject objIn) {
        if (objIn == but1) {
        	// Stop audio when playing single mode
        	audio.stopSound(MUSIC_FOLDER, "MMenu.mp3");
            program.switchToSinglePlayer();
        } 
        else if(objIn == but3) {
            program.switchToManual();
            
        } 
        else if (objIn == but2) {
        	// Stop audio when playing in multi-player mode
    		audio.pauseSound(MUSIC_FOLDER, "MMenu.mp3");
        	program.switchToMultiPlayer();
        }
    }

    @Override
    public void showContents() {
        program.add(background);
        program.add(but1);
        program.add(but2);
        program.add(but3);
    }

    @Override
    public void hideContents() {
        program.remove(background);
        program.remove(but1);
        program.remove(but2);
        program.remove(but3);
    }

}