Overview of the feature to be implemented:
Professor offered following:
"Create a list with the sounds and their filenames that is one place that can be edited and make it so that the AudioPlayer does not crash (this should not be happening), but if there's an exception, perhaps it can be handled gracefully and then you can move on."
In the past, I used to pass the name of the sound to function as a hardcoded string. 
For this assignment I'll make the sounds as enums and create a list for their names. 
Then, I'll pass location of the sound in the list to audio player.


Pseudocode for the feature:
In my case, new feature is a enum class for a sound names. I'm providing pseudocode for new enum class and example usage in mainApp file
Enum class pseudocode (soundClassType.java):
	Enum constants names separated with ","
	Method converting constants to words:
		Based on constant's name:
			Return the location of the file for the constant name.

Whenever sound is played in main app or level:
Create instance of audio player;
Whenever needed to play sound:
	Play sound by utilizing playSound method of audio player. Provide audio player with name of desired file to be played in form of enum constant (!)


The set of steps that demonstrates that the feature (Commit 6):


P.S:
