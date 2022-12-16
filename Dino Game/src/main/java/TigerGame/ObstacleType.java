package TigerGame;

public enum ObstacleType {
	TRASHCAN, ACORN, ROCK, BENCH; 
	
	public String toString() {
		switch(this) {
			case TRASHCAN: return "trashcan";
			case ACORN: return "acorn";
			case ROCK: return "rock";
			case BENCH: return "bench";
		}
		return "n/a";
	}
}
