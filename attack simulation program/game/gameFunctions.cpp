#include "gameHeader.h"
/*------------------
* Tessy Pauline Mugisha
* February 5 2023
* Programming Assignment #3
* Description: Alien Attack game using Classes
*--------------------*/

/*Name:gameFunctions.cpp
* Purpose:Holds the functions that will be used in the game(main) cpp
*/

/*Name:moveShip
* Purpose:instructions on how the user will move the ship
* Input:address to the Pixie through the ship object
*	choice:keyboard is pressed left or right
*	Values:DISTANCE(X), 0(Y)
* Return:void
*/
void Pixie::moveShip(Pixie& ship)
{
	/*
	 *  This first If-then-else-if Block handles
	 */
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		// left arrow is pressed: move our ship left 5 pixels ( this is -5 pixels to go left)
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
	if (ship.getPosX() < 0)//if the ship's x position is less than 0 
	{
		ship.setX(0.0);//sets the ships x cordinate to 0
	}
	else if (ship.getPosX() + ship.getSprite().getGlobalBounds().width > WINDOW_WIDTH)//returns the sum of current X-coordinate and width of the spaceship's image and to see if it greater than the window
	{
		ship.setX(WINDOW_WIDTH - ship.getSprite().getGlobalBounds().width);//gets the X-coordinate of the ship's position to the difference between the window width and the sprite width
	}//in general this helps the ship not go beyond the window

}

// Function moveTheMissile - moves the missile. 
// There is no input. 
// return value - no return value (void).
void moveTheMissile(Pixie& missile) 
{
	missile.move(0, -DISTANCE);// moves the missile
}
// Function moveTheAlienMissile - moves the alien missile.  
// There is no input. 
// return value - no return value (void).
void moveTheAlienMissile(Pixie& missile)
{
	missile.move(0, DISTANCE);// move the missile
}
// Function moveEnemy - moves the enemy. 
// There is no input. 
// return value - no return value (void).
void moveAlien(Pixie& alien, bool& alienMoveRight, int& counter) {

	alien.setY(counter); // call to move the enemy down towards ship.

	// statements to keep the enemy moving and to prevent them from moving off screen.
	if (alienMoveRight) {
		//cout << "Inside enemy move right\n";
		if (alien.getPosX() > 740)
		{
			alienMoveRight = false;
			alien.move(DISTANCE, 0);
			counter += 10;
		}
		else {
			alien.move(DISTANCE, 0);
		}
	}
	else {

		if (alien.getPosX() < 0)
		{
			alienMoveRight = true;
			alien.move(DISTANCE, 0);
		}
		else
			alien.move(-DISTANCE, 0);
	}
}


