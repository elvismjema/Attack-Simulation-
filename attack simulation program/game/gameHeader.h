#pragma once
/*------------------
* Tessy Pauline Mugisha
* February 5 2023
* Programming Assignment #3
* Description: Alien Attack game using Classes
*--------------------*/


/*Name:gameHeader.h
* Purpose:Holds the constants that will be used in the game
*/


#include <iostream>
using namespace std;

// these two lines are specific to the SFML graphics library. 
#include <SFML/Graphics.hpp>
using namespace sf;

#include"Pixie.h"


// Constants for the game 
const float DISTANCE = 5.0f; // When the ship moves it moves 5 pixels at a time. 
const int WINDOW_WIDTH = 800; // window is 800 pixels wide
const int WINDOW_HEIGHT = 600;// window is 600 pixels vertically "high"
const int X = 300.0;//ship and missile's x values
const int Y = 300.0;//ship and missile's y values
const int X1 = 2.0;//background's x value 
const int Y1 = 2.0;//bacground's y value 
const int ALIEN_ARMY = 10;

#include"AlienArmy.h"


