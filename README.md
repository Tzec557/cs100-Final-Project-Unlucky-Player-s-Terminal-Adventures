 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date.
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# \<Unlucky Player’s Terminal Adventures\>
 Authors: \<[Nathan Tewinpagti](https://github.com/ntewi001), [Tristan Zhao](https://github.com/Tzec557), [Hikaru Shimada](https://github.com/hika583), [Kevin Carrillo](https://github.com/kevcarrillo03)\>

## Project Description

 * As a group, we believed this project would be interesting because we all grew up playing video games. We believed it would be fun to recreate the nostalgia of popular games we played such as Oregon trail, Pokemon and other RPG games through coding. This project also seems important for our future projects/endeavors, serving as an introduction into game design. 
 * For the coding language we will be using C++. We will also be using Github to distribute our game. The main means of communication between the user and the system will be through the terminal screen. 
 * For input/output, users will be able to input their choice of action through text in the terminal. All the outputs will be visible to the users through the terminal screen in a form of text feedback. 
 * For features, we will create a text-based RPG game featuring characters equipped with different weapons and customizable actions and attributes.  
    * Players can personalize their characters by changing their attributes and traits through stats points, earned via the leveling combat system. Within our system, users can choose actions displayed on the terminal, like fighting, running away, or changing equipment. 
    * Character progression involves a combat system where battles with other non-playable characters allows to gain experience points to level up. We will introduce bosses and a narrative for the user characters for an immersive experience.


## User Interface Specification
* [User Interface Specification](https://lucid.app/lucidchart/3a26727c-9df4-4e01-a2cc-66bdd428f6e6/edit?viewport_loc=-404%2C-1447%2C2216%2C3168%2C0_0&invitationId=inv_866891d5-7aba-4d15-a045-91cf5d1855c0)


### Navigation Diagram
![alt text](https://github.com/cs100/final-project-ezhao012-hshim023-ntewi001-kcarr079/blob/master/Diagrams/Navigation%20Diagram.jpeg)

#### Home
- Starting point of the narrative.

#### Play
- The player decides whether to enter the game.
  - **Yes:** Proceeds to the introduction of the game, continuing the virtual adventure.
  - **No:** Ends the game, acknowledging the player's decision to avoid entering the virtual world.

#### Intro
- **Transported to the Hospital:** The protagonist is taken to the hospital, setting the stage for a medical situation.
- **Told by the Doctor that You Have Terminal Cancer:** The doctor delivers the grim news of a terminal illness, introducing a critical turning point.

#### Option
- Choose to Enter a Game to Heal the Cancer, or Wait Till Die (Ends the Game).
- The player is presented with a choice to either enter a game for healing or wait for the terminal condition to take its course.

#### Character Creation (Choose the Character Info)
- If the player chooses to enter the game, they proceed to create their in-game character, providing personalization to the narrative.

#### Spawns in the Bed <- Save Point
- The character spawns in a bed, indicating a save point within the virtual world.

#### Play Against the Boss (If Win, Then Get Heal a Little)
- The player engages in a boss battle. Winning the battle results in partial healing (add points), introducing a game mechanic.

#### If Dead, Goes Back to Bed
- If the player loses the boss battle, they return to the bed save point, allowing for retries.

#### The Boss Drops Points and the Weapon
- Upon defeating the boss, the player receives points and a weapon, indicating progress and rewards.

#### If More Than 100 Points -> Ends the Game “You Have Healed the Cancer”
- If the accumulated points surpass a threshold (100), the game concludes with a positive outcome, symbolized by the healing of the terminal cancer.

This diagram represents a dynamic and interactive narrative where player decisions and actions directly influence the storyline and outcomes. It incorporates elements of choice, consequence, and game mechanics to engage the player in a unique and evolving experience.





### Screen Layouts
![alt text](https://github.com/cs100/final-project-ezhao012-hshim023-ntewi001-kcarr079/blob/master/Diagrams/%E6%88%AA%E5%B1%8F2024-03-14%20%E4%B8%8B%E5%8D%887.31.47.png)

#### Start Screen
- **Options:** New Game, Exit
- **Purpose:** Allows the player to start a new game, or exit the application.

#### Character Creation
- **Components:**
  - Choose Name
  - Confirm Choices
- **Purpose:** Enables the player to create their character with a chosen name, and class.

#### Main Game Screen
- **Components:** Player Stats (Name, Health, Attack, Defense)
- **Purpose:** Displays essential player information and provides access to different game features.

#### Player Stats
- **Components:** Health, Attack, Defense
- **Purpose:** Shows the player's current stats.

#### Boss Battle Screen
- **Components:**
  - Boss HP
  - Player Options (Attack, Defend, Flee)
- **Purpose:** Represents the interface during a boss battle, where the player can choose actions.




## Class Diagram
![alt text](https://github.com/cs100/final-project-ezhao012-hshim023-ntewi001-kcarr079/blob/master/Diagrams/%E6%88%AA%E5%B1%8F2024-03-14%20%E4%B8%8B%E5%8D%887.22.27.png)

>In our updated class diagram we applied the single responsibility principle. We applied it by changing our player class so that it splits into 3 classes of player, enemy, and character which both player and enemy derive from. This helped our code as it made it look less cluttered. 

>In our second update to our class diagram, we applied the single responsibility principle again. In our original player class, it contained functions that should have been done in a separate class.  So we created a point class and weapon class that deals with those aspects of our game. This change made so our player class doesn't contain functions that it should not be responsible for.


* [Class Diagram](https://www.canva.com/design/DAF8Q2YofAE/3AaZgaXJxIf-3V4Yf_nnZA/edit?utm_content=DAF8Q2YofAE&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)
 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application:
>  In our game the way you run it is by running a command in the terminal and this command is ./bin/runMain which will then start the game.
>  You will then be given an option to either start the game by pressing 1 or quit with 2. If you start the game you be met with intro dialogue welcoming you into the game and then asking the user  if they want to enter the game to heal by fighting bosses by pressing 1 or quitting with 2. If the user presses 1 then they will be met with a prompt asking for their name which the user would type in and then the user will be asked if he wants confrim his name or quit using 1 and 2. If user confirms his name choice they will then be met with a story for the game and explained how the battling will work. User will then spawn in checkpoint where he could check his stats by pressing s, then going into battle by pressing y or quitting by pressing q. after starting battle, you can confirm by pressing s or quitting by pressing q. In battle user will press x to roll a dice where if he gets a higher number he can attack or else the enemy can attack and both the user and enemy have a chance at dodging the attack. The User will then keep fighting where he will spawn back to bed checkpoint if he dies or wins and keep fighting till he has 100 points. As he reaches certain points, his weapon will also increase, increasing the damage he does to the boss.
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
