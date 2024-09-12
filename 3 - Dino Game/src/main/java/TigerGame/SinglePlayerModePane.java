package TigerGame;

public class SinglePlayerModePane extends GraphicsPane {
	private MainApplication program;
	public Level LevelOne;
	public static final int WINDOW_WIDTH = 600;
	public static final int WINDOW_HEIGHT = 436;


	public SinglePlayerModePane(MainApplication app) {
		super();
		program = app;
		LevelOne = new Level(program, false);
	}
	
	
	@Override
	public void showContents() {
		
	}

	@Override
	public void hideContents() {

	}
}