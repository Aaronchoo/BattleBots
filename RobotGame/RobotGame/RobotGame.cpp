// RobotGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
//Holds information
std::string battleName[2];
int battlePlayers[5][2];
//A void function that has a short introduction to the game
void introduction()
{
	//Welcomes the player
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	std::cout << "     WELCOME TO BATTLE BOTS!!!!!" << "\n" << "     --------- HYPE ------------" << "\n" << "          ARE YOU READY???" << "\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	std::string temp;
	//gets input
	std::cin.ignore();
	std::getline(std::cin, temp);
	//Ignores the input and let's the user know the game will begin
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
	std::cout << "DOESN'T MATTER!! LET'S START!!!" << "\n";
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n";
}
//Temp for the actual function
void playAgain();
//Capitalize each letter in a word or leave it as it is
std::string upperAllLetters(std::string word) {
	//Temp variable to hold word
	std::string fixUp = "";
	//Upper case the input if it vaguely fits the size of the desired inputs
	if (word.length() == 6 || word.length() == 7 || word.length() == 9) {
		//Run through each character and make a word
		for (int i = 0; i < word.length(); i++) {
			if (islower(word[i])) {
				fixUp += toupper(word[i]);
			}
			else {
				//Assume the character is alreayd capitalized
				fixUp += word[i];
			}
		}
	}
	return fixUp;
}
//This function will return a string that will give information on the # of players and game type
std::string chooseGameMode()
{
	//Will prompt the users to fill out if there are 1 or 2 player 
	std::cout << "----------------------------------------------------------------------" << "\n";
	std::cout << "Enter the number of players: 1 player or 2 players? (Just the number!)" << "\n";
	std::cout << "Note that 1 player will lead to a tournament style while 2 players will be fighting against each other!" << "\n";
	std::string players;
	std::getline(std::cin, players);
	//Checks for invalid responses and will continually prompt users to enter either or
	while (true) {
		//Checks if the input is not any of the 2 desired
		if (players != "1" && players != "2") {
			//Continue to prompt user to enter the follwoing
			std::cout << "Invalid input." << "\n" << "Enter: 1 or 2!" << "\n";
			std::getline(std::cin, players);
		}
		else {
			//if so exit out of the while loop
			break;
		}
	}
	//Holds the type of game choice they will play
	std::string gameType;
	//Will figure out if the user wants to play automatically or manually
	std::cout << "----------------------------------------------" << "\n";
	std::cout << "Enter the type of game: manual or automatic?" << "\n" << "Note that manual means you can choose to attack or defend while automatic is done by the computer" << "\n";
	//Get their choice
	std::getline(std::cin, gameType);
	gameType = upperAllLetters(gameType);
	//Ensures that one of the two inputs were submitted
	while (true) {
		//Checks if the input was one of the two
		if (gameType == "AUTOMATIC" || gameType == "MANUAL") {
			break;
		}
		else {
			//Continue to prompt them to choose of of the options
			std::cout << "Enter either manual or automatic for game type!" << "\n";
			//Get their choice
			std::getline(std::cin, gameType);
			//UpperCase all letters so automatic == AUTOMATIC
			gameType = upperAllLetters(gameType);
		}
	}
	//return the combination of the # of players and game type
	return (players + gameType);
}

//Creating the class for the robots
class robotBuild {
	std::string name;
	int health, attack, defense,randomAttack,swift;
public:
	//Gets information and build robot
	void buildbot(std::string, int, int, int, int,int);
	//Pass back information
	std::string namebot() { return name; }
	int healthBot() { return health; }
	int attackBot() { return attack; }
	int defenseBot() { return defense; }
	int randomBot() { return randomAttack; }
	int swiftBot() { return swift; }
};

//Save info for the robot
void robotBuild::buildbot(std::string names, int x, int y, int z, int ran, int s) {
	//Assign information of Robot to player
	name = names;
	health = x;
	attack = y;
	defense = z;
	randomAttack = ran;
	swift = s;
}
//Assign information about the robot to the array that holds contestants
void assignBot(int x, robotBuild bot) {
	//Assign specific details to their bot parts
	battleName[x] = bot.namebot();
	battlePlayers[0][x] = bot.healthBot();
	battlePlayers[1][x] = bot.attackBot();
	battlePlayers[2][x] = bot.defenseBot();
	battlePlayers[3][x] = bot.randomBot();
	battlePlayers[4][x] = bot.swiftBot();
	//Show off stats of robot
	std::cout << "We have " << battleName[x] << " with an ATTACK OF " << bot.attackBot() << " and DEFENSE OF " << bot.defenseBot() << "!!! Not to mention, the total health is " << bot.healthBot() << "!!! THIS IS GOING TO BE A FIGHT!" << "\n";
}
//Will produce a  true or false if the robot dodged
bool dodgeAttack(int playerNumber) {
	//Will dodge if the chanceOfDodge is greater than the 
	int chanceOfDodge = rand() % battlePlayers[4][playerNumber];
	int dodgeRate = rand() % 10000 + 1;
	//Will only dodge if the chanceofDodge is greater than the dodgeRate
	return chanceOfDodge > dodgeRate;
}
//Decipher the input for the move of the player
int decidedMove(int x) {
	//The string that will hold the input of what they want to do
	std::string move;
	//Will hold either 0 which means they will attack or 10000 which means they defend
	int v1;
	//Prompt user to choose a move
	std::cout << "----------------------------------------------------" << "\n";
	std::cout << battleName[x] << "'s turn! Enter attack or defense" << "\n";
	//Take in what the user wants to do
	std::getline(std::cin, move);
	move = upperAllLetters(move);
	while (true) {
		if (move == "ATTACK") {
			//Set the act value so it guarantees attack
			v1 = 0;
			break;
		}
		else if (move == "DEFENSE") {
			//ensures they have to attack
			v1 = 10000;
			break;
		}
		else {
			//Prompt them to correctly enter stuff
			std::cout << "Invalid input!! " << battleName[x] << "'s turn! Please enter attack or defense" << "\n";
			std::getline(std::cin, move);
			//Capitalize all letters
			move = upperAllLetters(move);
		}
	}
	//Return the decision
	return v1;
}
//This is the battle portion of the subprogram
bool startBattle(robotBuild p1, robotBuild p2, std::string gameType) {
	//Introduce the game
	std::cout << "-------------------------------------------------------------------------------" << "\n";
	std::cout << "WE HAVE TWO ROBOTS WITH AMAZING BUILDS! LET'S SEE WHAT THEY CAN DO NOW!" << "\n";
	//take it from healthbot/attack/etc and save it
	assignBot(0, p1);
	assignBot(1, p2);
	bool result;
	//start the autobattle
	while (true) {
		if (battlePlayers[0][0] <= 0 && battlePlayers[0][1] <= 0){
			//Will continue to have the robots enter more and more rounds until someone won
			std::cout << "-----------------------------------------------------" << "\n";
			std::cout << "Since there is a tie... WE WILL GO INTO ANOTHER ROUND!"<< "\n";
			result = startBattle(p1,p2,gameType);
			break;
		}
		else if (battlePlayers[0][1] <= 0) {
			//Tells the user that player 1 won
			std::cout << "--------------------------------------------------" << "\n";
			std::cout << "WINNER!!!! " << battleName[0] << " WON THIS ROUND!!" << "\n";
			std::cout << "--------------------------------------------------" << "\n";
			result = true;
			break;
		}
		else if (battlePlayers[0][0] <= 0) {
			//Says that Player 2 won
			std::cout << "--------------------------------------------------" << "\n";
			std::cout << battleName[1] << " IS THE WINNNNNNNNNNNNNNNER! :O" << "\n";
			std::cout << "--------------------------------------------------" << "\n";
			result = false;
			break;

		}
		//Initialize player 1 and player 2 move
		int v1, v2;
		//Checks the gamemode
		if (gameType == "1AUTOMATIC" || gameType == "2AUTOMATIC") {
			//randomly generate a number between 1 to 100
			v1 = rand() % 100 + 1;
			v2 = rand() % 100 + 1;
		}
		else if (gameType == "1MANUAL") {
			v1 = decidedMove(0);
			//Randomly decide if the second player should attack
			v2 = rand() % 100 + 1;
		}
		else {
			if (rand() % battlePlayers[4][0] + 1 > rand() % battlePlayers[4][1] + 1) {
				//Prompt the user to make a move (player 1 goes first)
				v1 = decidedMove(0);
				v2 = decidedMove(1);
			}
			else {
				//Prompt the user to make a move (player 2 goes first)
				v2 = decidedMove(1);
				v1 = decidedMove(0);
			}
		}

		//Checks the attack and defend pattern based off the result
		if (v1 <= battlePlayers[3][0] && v2 <= battlePlayers[3][1]) {
			//Both players attacked, let the player know
			std::cout << "WOW! BOTH ROBOTS ATTACKED EACH OTHER!!" << "\n";
			//Check if any of them dodged
			int dodge1 = dodgeAttack(0),dodge2 = dodgeAttack(1);
			if (dodge1 && dodge2) {
				//When they both dodged, no damage is taken
				std::cout << "HOW IS THIS POSSIBLE! THEY BOTH DODGED THE ATTACKS?!??" << "\n";
			}
			else if (dodge1) {
				//Only player 2 gets hurt since player 1 dodged
				std::cout << "Somehow " << battleName[0] << " ended up dodging that attack!" << "\n";
				battlePlayers[0][1] -= battlePlayers[1][0];
				
			}
			else if (dodge2) {
				//Player 2 dodged and managed to hit player 1
				std::cout << "Woah! " << battleName[1] << " managed to hit " << battleName[0] << " and dodged the attack!!" << "\n";
				battlePlayers[0][0] -= battlePlayers[1][1];
			}
			else {
				//Reduce health since no one dodged
				battlePlayers[0][0] -= battlePlayers[1][1];
				battlePlayers[0][1] -= battlePlayers[1][0];
			}
		}
		else if (v1 <= battlePlayers[3][0] && v2 > battlePlayers[3][1]) {
			int dodge1 = dodgeAttack(1);
			if (dodge1) {
				//Player 2 managed to dodge player 1's attack
				std::cout << battleName[0] << " went for the attack! Good thing " << battleName[1] << " dodged!!! " << "\n";
			}
			else {			
				//Informs the user that the first player attacked while the second defended
				std::cout << battleName[0] << " went for the attack! Good thing " << battleName[1] << " blocked! ";
				//Checks if the attack is greater than the defense
				if (battlePlayers[1][0] > battlePlayers[2][1]) {
					//If so, subtract the health damage
					battlePlayers[0][1] -= (battlePlayers[1][0] - battlePlayers[2][1]);
					std::cout << "Even while defending, that's gotta hurt!" << "\n";
				}
				else {
					//Otherwise inform user that no damage was taken
					std::cout << battleName[1] << "'s defenses are too strong! " << battleName[1] << " didn't look hurt at all!" << "\n";
				}
			}
		}
		//If player 1 defends and player 2 attacks
		else if (v1 > battlePlayers[3][0] && v2 <= battlePlayers[3][1]) {
			int dodge1 = dodgeAttack(0);
			if (dodge1) {
				//Similair to the above
				std::cout << battleName[1] << " went for the attack! Good thing " << battleName[0] << " dodged that attack!! ";
			}
			else {
				//Similair to the above
				std::cout << battleName[1] << " went for the attack! Good thing " << battleName[0] << " blocked! ";
				if (battlePlayers[1][1] > battlePlayers[2][0]) {
					//Will subtract damage taken since defense is not enough
					battlePlayers[0][0] -= (battlePlayers[1][1] - battlePlayers[2][0]);
					std::cout << "Even while defending, that's gotta hurt!" << "\n";
				}
				else {
					//Otherwise tell the user that defense is too weak
					std::cout << battleName[1] << "'s defenses are too strong! " << battleName[1] << " didn't look hurt at all!" << "\n";
				}
			}
		}
		else {
			//The case where no one attacks
			std::cout << "THEY BOTH DEFENDED! LOOKS LIKE THEY'RE PLAYING A BIT SAFE!!!!" << "\n";
		}
		//Updates health and condition of robots
		std::cout << battleName[0] << " is at " << battlePlayers[0][0] << " and " << battleName[1] << " is at " << battlePlayers[0][1] << "\n";
		
		if (gameType == "1AUTOMATIC" || gameType == "2AUTOMATIC") {
			//When the game type is automatic, this will allow players to break down steps of what is happening
			std::cout << "[Press Enter to Continue]" << "\n";
			//Allows players to slowly see the progress
			std::string tempVariable;
			std::getline(std::cin, tempVariable);
		}
	}
	//Returns if they lost or won
	return result;
}
//A subprogram that will continue to prompt users to enter valid integers
int correctInteger(std::string statType,int boundValue) {
	int x;
	std::cout <<statType <<": ";
	std::cin >> x;
	while (std::cin.fail() || x > boundValue || x < 0) {
		//Clear the error state of the buffering
		std::cin.clear();
		//Ignores the rest of the line of the input
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//Prompt them to input a valid integer
		std::cout << "Enter a valid integer within the bounds!!!!" << "\n" << statType<<": ";
		//Read inputs again
		std::cin >> x;
	}
	//Ignores the rest of the line of the input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return x;
}

//Build the robot for the players
robotBuild makeRobot(std::string typeOfBattle) {
	//Prompt player to start building the robot and explain the stats quickly
	std::cout << "Split the 2500 points between the Health, Attack and Defense by entering stats:" << "\n";
	std::cout << "To clarify, health is how much additonal health (to the base of 5000) the robot has, attack is the damage the robot will give, defense will reduce damage taken from enemy's attack, and swift gives a chance to dodge!" << "\n";
	//variables to hold the health, attack, and defense
	int healthStat, attackStat, swiftStat, defenseStat;
	//Ensures that the points are all fully used without extra stats
	while (true) {
		//Gets input for stats & prompt users to initially add stats
		healthStat = correctInteger("Health", 2500);
		attackStat = correctInteger("Attack", 2500);
		defenseStat = correctInteger("Defense", 2500);
		swiftStat = correctInteger("Swift", 2500);
		//Tell them what they made
		std::cout << "Heath: " << healthStat << ", Attack: " << attackStat << ", Defense: " << defenseStat << ", and Swiftness: " << swiftStat << "\n";
		//Checks if the stats are properly allocated
		if (healthStat + attackStat + defenseStat  +swiftStat== 2500) {
			break;
		}
		else {
			//Will warn them of the issue
			if (healthStat + attackStat + defenseStat +swiftStat> 2500) {
				//Warns them they have uused more than they are allowed
				std::cout << "ERROR!! You had " << healthStat + attackStat + defenseStat + swiftStat - 2500 << " more points than desired. Try again! ";
			}
			else {
				//Warms them they have not used all their points
				std::cout << "ERROR!! You still have " << 2500 - healthStat - attackStat - defenseStat - swiftStat << " more points! Try again! ";
			}
			//Will prompt them to try again
			std::cout << "\n" << "Split the 2500 points between the Health, Attack and Defense by entering stats:" << "\n";
		}
	}
	//Gives the player the que to give the robot a name
	std::cout << "Now we have the robot...: ";
	//Saves the name
	std::string name;
	std::getline(std::cin, name);
	std::cout << "\n";
	//For automatic game types, have a % of how often they want the robot to attack
	int box = 0;
	if (typeOfBattle == "1AUTOMATIC" || typeOfBattle == "2AUTOMATIC") {
		//Choose how often the person attacks
		std::cout << "Put in a number from 1 to 100. The higher the number the more likely you'll attack!" << "\n";
		box = correctInteger("Attack rate of: ", 100);
	}
	//Create an object for the player
	robotBuild player;
	player.buildbot(name, healthStat + 5000, attackStat, defenseStat, box, swiftStat + 1);
	return  player;
}
//Sets up the robots based on players preference
void setUpPlayerMode(std::string typeOfBattle) {
	//Build the
	robotBuild player1,player2;
	player1 = makeRobot(typeOfBattle);
	//Checks if a second player data needs to be made
	if (typeOfBattle == "2AUTOMATIC" || typeOfBattle == "2MANUAL") {
		player2 = makeRobot(typeOfBattle);
	}
	//start the automatic battle between the robots
	if (typeOfBattle == "1AUTOMATIC" || typeOfBattle == "1MANUAL") {
		//Creation of the enemies
		robotBuild playerEnemy[5];
		//Build the 4 enemies they have to face in the tournament
		playerEnemy[0].buildbot("King Round", 4520, 750, 750, 50,250);
		playerEnemy[1].buildbot("B.I.G. Boy", 6750, 1500, 250, 75,100);
		playerEnemy[2].buildbot("The Defender", 9000, 500, 1000, 45,200);
		//Note that his stats are slightly greater than 25000
		playerEnemy[3].buildbot("Ulti-bot", 6009, 650, 550, 70,2000);
		playerEnemy[4].buildbot("Shadow the Champion", 10500, 1250, 750, 80, 4500);
		for (int i = 0; i <= 4; i++) {
			//Pass in the robots and let them battle
			if (!startBattle(player1, playerEnemy[i], typeOfBattle)) {
				std::cout << "YOU LOST!!!" <<"\n";
				i = 5;
				//have a restart thing?
			}
			else if (i == 4) {
				//Introducing the boss stage
				std::cout << "============================================================================================================" << "\n";
				std::cout << "NEXT IS SHADOW! HE IS the STRONGEST ROBOT EVER!!!!!!!!!! DOES ANYONE HAVE A CHANCE AGAINST OUR CHAMPION???" << "\n";
				std::cout << "============================================================================================================" << "\n";
			}
			else {
				//Let them continue to fight the rounds
				std::string name;
				std::cout << "Are you ready to face another tough enemy? What do you say to the challenge?!?!" << "\n";
				std::getline(std::cin, name);
			}

		}
	}
	else {
		//Introduce the event
		std::cout << player1.namebot() << " VS " << player2.namebot() << "\n";
		//Holds the number of wins player 1 has
		int winner1 = 0;
		//start the battle between robots! Let them have 3 rounds
		for (int i = 0; i < 3; i++) {
			std::cout << "===========================================" << "\n";
			std::cout << "    OFFICIALLY ENTERING ROUND " << i << "!!!!!" << "\n";
			std::cout << "===========================================" << "\n";
			if (startBattle(player1, player2, typeOfBattle)) {
				winner1++;
			}
			
			//Allows players to slowly see the progress
			std::cout << "[Press Enter to Continue]" << "\n";
			std::string tempVariable;
			std::getline(std::cin, tempVariable);
		}
		if (winner1 > 1) {
			std::cout << "=======================================================================================================================================" << "\n";
			std::cout << "CONGRATZ " << battleName[0] << " ON DESTROYING THE COMPETITION!!!!!" << "\n";
			std::cout << "=======================================================================================================================================" << "\n";
		}
		else {
			std::cout << "=======================================================================================================================================" << "\n";
			std::cout << "CONGRATZ " << battleName[1] << " ON DESTROYING THE COMPETITION!!!!!" << "\n";
			std::cout << "=======================================================================================================================================" << "\n";
		}
	}
	playAgain();

}

//Start the entire game
void startGame(std::string gameMode)
{
	//Introduces how the points system work for the robots
	std::cout << "-------------------------------------------------------------------------------" << "\n";
	std::cout << "Let's begin by building the stats for the robot! You have 2500 points to build your robot." << "\n";
	//Start up game modes
	setUpPlayerMode(gameMode);
}
//Asks them if they want to play again
void playAgain() {
	//Tells them to enter anything if they want to procceed
	std::cout << "--------------------------------------------------------------------------" << "\n" << "\n";
	std::cout << "To continue playing, enter anything! Otherwise close the game now!" << "\n" << "\n";
	std::cout << "--------------------------------------------------------------------------" << "\n" << "\n";
	std::string tempVariable;
	std::getline(std::cin, tempVariable);
	//Give them the options for game mode and start-instructions
	startGame(chooseGameMode());
}
int main()
{
	//Gives the players an introduction to the game
	introduction();
	//Give them the options for game mode and start-instructions
	startGame(chooseGameMode());
    return 0;
}


