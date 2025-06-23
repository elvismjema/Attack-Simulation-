#pragma once
#include "gameHeader.h"


/*------------------
* Tessy Pauline Mugisha
* February 5 2023
* Programming Assignment #3
* Description: Alien Attack game using Classes
*--------------------*/

/*Name:Pixie.h
* Purpose:Pixie's Header File that holds the pixie class, and the constants
*/


// constants to identify the kind of game objects the Pixie holds
const int UNDEFINED_PIXIE = 35;//constant for the undefined pixie
const int PLAYER_SHIP_PIXIE = 12;// constant for the ship
const int PLAYER_MISSILE_PIXIE = 10;//constant for the missile
const int BACKGROUND_PIXIE = 45;//constant for the bavkground

class Pixie
{
private:
	Texture textureObject;//oject to hold the texture
	Sprite spriteObject;//object to hold the sprite 
	float x;//float that holds the value of x
	float y;//float to hold the value of y
	Pixie* nextPixie;//a pixie pointer called nextPixie
	Pixie* previousPixie;//a pixie pointer called previousPixie
	static int nextPixieID;//static member variable 
	int myID;//integer to hold the ID
	int pixieType;//integer to hold the pixieType
	Pixie* nextAlien;
public:
	Pixie();//Pixie default constructor
	Pixie(string, float, float, int);//Pixie constructor
	void draw(RenderWindow& window);//is passed the window object and uses the window object to draw this Pixie’s Sprite on the window.
	void move(float x, float y);//This method changes the x and y location members in the Pixie and the x and y location in the Sprite.
	void setScale(float xScale, float yScale);//This function simply calls the Sprite’s setScale function
	void setPosition(float x, float y);//This function calls the Sprite’s setPosition function, passing x and y

	float getPosX() const//returns the current x location
	{
		return x;
	}
	float getPosY() const//returns the current y location
	{
		return y;
	}
	Sprite getSprite()//returns the sprite object
	{
		return spriteObject;
	}
	Texture getTexture()//returns the Texture object
	{
		return textureObject;
	}
	int getID()//returns the integer value of the ID
	{
		return myID;
	}
	int getType()//returns the type value
	{
		return pixieType;
	}
	Pixie* getPreviousPixie()//returns the pointer previous
	{
		return previousPixie;
	}
	Pixie* getNext()//returns the pointer next
	{
		return nextPixie;
	}
	Pixie* getSelfPointer()//returns the pointer to “this”
	{
		return this;
	}

	void setType(int pixieType)//sets the type to the value passed in
	{
		this->pixieType = pixieType;
	}
	void setX(float x)//sets the x value and also sets the x value in the Sprite
	{
		this->x = x;
		spriteObject.setPosition(x, y);
	}
	void setY(float y)//sets the y value and also sets the y value in the Sprite
	{
		this->y = y;
		spriteObject.setPosition(x, y);
	}

	void setTextureSourceFile(string fileName);// Passed the name of an image file
	void moveShip(Pixie& ship);//passed the address of the ship's Pixie object 

	//AlienArmy functions
	void moveAlienMissile(Pixie& missile);
	void moveAlien(Pixie& enemy, bool& move, int& counter);
	Pixie setNextAlien(Pixie* NextAlien)
	{
		nextAlien = NextAlien;
	}
};

