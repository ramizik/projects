package TigerGame;

public enum MapElementType {
	CLOUD, BUSH, TREE;
	
	public String toString() {
		switch(this) {
			case CLOUD: return "cloud";
			case BUSH: return "bush";
			case TREE: return "tree";
		}
		return "n/a";
	}
}
