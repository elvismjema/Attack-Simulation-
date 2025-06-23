#include "gameHeader.h"
/*------------------
* Tessy Pauline Mugisha
* February 5 2023
* Programming Assignment #3
* Description: Alien Attack game using Classes
*--------------------*/


/*Name:game.cpp
* Purpose:creates ship, missile, and background Pixie then displays them
*/


int main()
{

	// Create the window for graphics. 
	//  The "aliens" is the text in the title bar on the window. 
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");//Create the window for graphics using the SFML library with a width, height and title


	//// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	Pixie ship("ship.png", X, Y, PLAYER_SHIP_PIXIE);//Ship Pixie object with its x and y coordinates 

	ship.setScale(1.5, 1.5);//the size of the ship

	Pixie missile("missile.bmp", X, Y, PLAYER_MISSILE_PIXIE);//missile Pixie object with its x and y coordinates 

	Pixie alienMissile("missile.bmp", X, Y, PLAYER_MISSILE_PIXIE);

	missile.setScale(1.5, 1.5);//the size of the missile

	Pixie background("stars.jpg", X1, Y1, BACKGROUND_PIXIE);//Backgound Pixie object with its x and y coordinates 

	background.setScale(1.5, 1.5);//the size of the background

	bool isMissileInFlight = false; // used to know if a missile is 'on screen'.
	
	bool isAlienMissileInFlight = false; // used to know if the alien missile is 'on screen'. 

	AlienArmy alien[10];

	int counter = 40; // y position of enemy. 
	int counterAlien = 10;
	//Variable to hold the lives of the ships.
	int lives = 3;
	// When the enemy hits the wall, it should go down towards the ship. 
	int j = 40; // intialize the position of j (enemies)
	for (int i = 0; i < 10; i++) 
	{
		alien[i].setX(j);
		j += 60;
	}

	int randomVariable = rand() % 10; // random variable to let the alien shoot the ship randomly. 
	// set the position of the alien missile using the one of the aliens. 
	if (!isAlienMissileInFlight)
	{
		isAlienMissileInFlight = true;
		float AlienX = alien[randomVariable].getSprite().getPosition().x;
		float AlienY = alien[randomVariable].getSprite().getPosition().y;
		alienMissile.setPosition(AlienX, AlienY);
	}

	for (int i = 0; i < 10; i++) {
		if (alien[i].getType() == ALIEN_ARMY) {
			alien[i].draw(window);
			moveAlien(alien[i], alienMoveRight, counter);
		}
	}

	// check if the missile and the enemy are in the same position
	for (int i = 0; i < 10; i++) {
		FloatRect missileBounds = missile.getSprite().getGlobalBounds();
		FloatRect enemyBounds = alien[i].getSprite().getGlobalBounds();
		// if the missile and the enemy are in the same position send a message and delete an enemy. 
		if (missileBounds.intersects(enemyBounds) && alien[i].getType() == ALIEN_ARMY)
		{
			cout << "we hit the enemy " << endl;
			alien[i].setPixieType(-100);
			isMissileInFlight = false;
			counterAlien--;
			if (counterAlien == 0) {
				cout << "You won. Game over ";
			}
		}
	}

if (isMissileAlienInFlight)
{
	// draw the missile
	alienMissile.drawPixie(window);
	// move the missile
	moveTheAlienMissile(alienMissile);

	// if the missile position is off-screen stop it from moving. 
	if (alienMissile.getSprite().getPosition().y >= 600) {
		isMissileAlienInFlight = false;
	}
	FloatRect missileBounds = alienMissile.getSprite().getGlobalBounds();
	FloatRect enemyBounds = ship.getSprite().getGlobalBounds();
	
	if (missileBounds.intersects(enemyBounds))
	{
		cout << "we hit the ship. " << endl;
		isMissileAlienInFlight = false;
		lives--;
	}
	// if the lives are equal to zero the game is over and the user has lost. 
	if (lives == 0) {
		cout << "Game Over, you lost! ";
		exit(0);
	}
}
// end the current frame; this makes everything that we have 
// already "drawn" actually show up on the screen

// end body of animation loop  



	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		// This while loop checks to see if anything happened since last time
		// we drew the window and all its graphics. 
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) // Did the user kill the window by pressing the "X"?
				window.close();
			else if (event.type == Event::KeyPressed) // did the user press a key on the keyboard?
			{
				if (event.key.code == Keyboard::Space && !isMissileInFlight)
				{
					isMissileInFlight = true;
					// You add the code to initialize missile position
					//  You should have created a missile pixie 
					// above the main loop, maybe around line 60? 
					missile.setPosition(ship.getPosX(), ship.getPosY() - missile.getSprite().getGlobalBounds().height);
				}
			}
		}
		window.clear();//clears the screen 
		background.draw(window);//draws the background
		ship.draw(window);//draws the ship
		ship.moveShip(ship);//moves the ship

		if (isMissileInFlight)//the missile is moving right 
		{
			// ***code goes here to handle a missile in flight
			// 
			missile.move(0, -DISTANCE);//the x value is 0 and the y value would move upwords towards the window
			// Draw the missile,
			if (missile.getPosY() <= 0)//if the missile's position is less than or equal to 0
			{
				isMissileInFlight = false;//the missile will move to the left 
			}
			else
				missile.draw(window);//redraw the missile

		}

		window.display();//display the window
	}
	return 0;

}