#include "gameHeader.h"
/*------------------
* Tessy Pauline Mugisha
* February 5 2023
* Programming Assignment #3
* Description: Alien Attack game using Classes
*--------------------*/

/*Name:Pixie.cpp
* Purpose:Assigns values to the constructors, defines the Default constructor, Draw, move, position, and scale
*/


int Pixie::nextPixieID = 0;//static integer in the Pixie is initialized to 0


//Name:Pixie() Default constructor
//* Purpose :needed to initialize variables
//* 
Pixie::Pixie()//Default constructor
{
	x = 0.0;//initialized to 0
	y = 0.0;//initialized to 0
	nextPixie = nullptr;//assigns the nullpointer to the pointer variable nextPixie
	previousPixie = nullptr;//assigns the nullpointer to the pointer variable previousPixie
	myID = nextPixieID++;//assigns the current value of nextPixieID
	pixieType = UNDEFINED_PIXIE;//the constant value in Undefined_PIXIE is assigned to the pixieType
}


//Name:Pixie constructor
//* Purpose : construct an object and assign values to the object's members
//* Values : string fileName, float x, float y, int type
//*Return : void
//* /
Pixie::Pixie(string fileName, float x, float y, int type)//construct an object and assign values to the object's members
{
	nextPixie = nullptr;//assigns the nullpointer to the pointer variable nextPixie
	previousPixie = nullptr;//assigns the nullpointer to the pointer variable previousPixie
	this->x = x;//assigns the local variable x to the member variable x
	this->y = y;//assigns the local variable y to the member variable y
	pixieType = type;////assigns the local variable type to the member variable pixieType
	myID = nextPixieID++;//assigns the current value of nextPixieID
	setTextureSourceFile(fileName);//finds the file and displays the texture if it can't find it displays an error message
	spriteObject.setPosition(x, y);//sets the position of the sprite on the screen using the local variables 
}

//Name:draw(RenderWindow& window)
//* Purpose :This method is passed the window object and uses the window object to draw this Pixie’s Sprite on the window
//* Values : the sprite Object, and draw(RenderWindow& window)
//*Return : void
//* 
void Pixie::draw(RenderWindow& window)//passed the window object and uses the window object to draw this Pixie’s Sprite on the window
{
	window.draw(spriteObject);//draw the sprite
}

//Name:move(float newX, float newY)
//* Purpose :This method changes the x and y location members in the Pixie and the x and y location in the Sprite.
//* Values : the newX and Y local variables
//*Return : void
//* 
void Pixie::move(float newX, float newY)//changes the x and y location members in the Pixie and the x and y location in the Sprite.
{
	x += newX;//adding the newX value to the member value x and then assigning it back to x
	y += newY;//adding the newY value to the member value y and then assigning it back to y
	spriteObject.setPosition(x, y);//sets the final positions to the spriteObject
}

//Name:setScale(float xScale, float yScale)
//* Purpose :This function simply calls the Sprite’s setScale function
//*Return : void
//* 
void Pixie::setScale(float xScale, float yScale)//calls the Sprite’s setScale function, is passed x and y values 
{
	spriteObject.setScale(xScale, yScale);//modify the size of the sprite 
}

//Name:setPosition(float x, float y)
//* Purpose:This function simply calls the Sprite’s setPosition function
//*Return: void
//* 
void Pixie::setPosition(float x, float y)//calls the Sprite’s setPosition function, is passed values for the x and y variables
{
	this->x = x;//assigns the value of the local variable x to the member variable x 
	this->y = y;//assigns the value of the local variable y to the member variable y
	spriteObject.setPosition(x, y);//sets the position of the sprite with the values of x and y
}

//Name:setTextureSourceFile(string filename)
//* Purpose:get the texture based on the filename
//*Return: void
//* 
void Pixie::setTextureSourceFile(string filename)//passed the file name and gets the texture based on the filename and assigns it to a sprite Object
{
	if (!textureObject.loadFromFile(filename))//if the file doesn't load well
	{
		cout << "Unable to load ship texture!" << endl;//display this message
		exit(EXIT_FAILURE);
	}
	spriteObject.setTexture(textureObject);//otherwise display the set the teture to the sprite
}
