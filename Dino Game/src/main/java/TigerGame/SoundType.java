package TigerGame;

public enum SoundType {
	
GAME, JUMP, MENU, POWERUP;
	
	public String toString() {
		switch(this) {
			case GAME: return "gameSound.mp3";
			case JUMP: return "jump-arcade.mp3";
			case MENU: return "mainMenuSound.mp3";
			case POWERUP: return "PowerUp.mp3";
		}
		return "n/a";
	}
}
