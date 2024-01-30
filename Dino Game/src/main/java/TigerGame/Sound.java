package TigerGame;

public class Sound {
	private SoundType soundType;
	
	public Sound(SoundType sound) {
		soundType = sound;
	}
	
	public String location(int number) {
		switch(number) {
		case 0: return "gameSound.mp3";
		case 1: return "jump-arcade.mp3";
		case 2: return "mainMenuSound.mp3";
		case 3: return "PowerUp.mp3";
		}
		return "n/a";
	}
}
