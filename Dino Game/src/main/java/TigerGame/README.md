Overview of the feature to be implemented:
Professor offered following:
"Create a list with the sounds and their filenames that is one place that can be edited and make it so that the AudioPlayer does not crash (this should not be happening), but if there's an exception, perhaps it can be handled gracefully and then you can move on."
In the past, I used to pass the name of the sound to function as a hardcoded string. 
For this assignment I'll make the sounds as enums and create a list for their names. 
Then, I'll pass location of the sound in the list to audio player.


Commit 1:
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



Commit 2:
I started with fixing the crash errors of audio player. Also, I brought back the folders for files.
So pictures and images are properly stored in folders. I forgot to mention this implementation in my previous commit,
but the code changes actually are in Commit 1, please refer there. My next task is to add enum class and corresponding list


Commit 3(TBD):
Commit 4(TBD):
Commit 5(TBD):
Commit 6(TBD): The set of steps that demonstrates that the feature:




P.S:
