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

Commit 3:
I now created a list of sounds and created a class for sounds.

Commit 4:
I fixed the issues related to Audioplayer. No crashes anymore. It's now easier to read a code with new way of calling the sound effects.
I also added new sounds in the game and took care of various conditions (Exit, change of the mode, death, etc.)

Commit 5 & 6:
This is combined commit because I realised that I fixed the issue by reaching commit 5. 
I tried various approaches but eventually made a choice of sticking to enums.
I'll provide more feedback on Canvas.
Here are the steps to repeat the procedure:

Basically once the application is being run, the music is succesfully played.
When switching between game modes, music stops/start accordingly.
Sound effects related to jump, powerups work properly.
Anytime application needs to play sound, it refers to arraylist of sounds (names of the files)
Done.
