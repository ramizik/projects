package TigerGame;

public enum PowerUpType {
	
ONEUP, DOUBLEJUMP, INVINCIBILITY, JEOPARDY;
	
	public String toString() {
		switch(this) {
			case ONEUP: return "oneup";
			case DOUBLEJUMP: return "doublejump";
			case INVINCIBILITY: return "invincibility";
		}
		return "n/a";
	}
	
}
