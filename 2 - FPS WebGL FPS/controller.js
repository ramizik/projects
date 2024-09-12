//FileName:		controller.js
//Programmers: Ramis Hasanli, Wil Bauer, Vanessa Kan
//Programmer:	Dan Cliburn
//Date:			9/22/2020
//Purpose:		This file defines the code for our controller
//The "controller" runs the program and handles events.

let model;
let view; //the "view" is our Canvas
let timer; //used for Task 3 in the lab
let nearNPC, nearRobot1, nearRobot2, foundRobot1, foundRobot2;
let clock;

function checkKey(event) {
    switch (event.keyCode) {
        //left arrow key was pressed (37 in ASCII)
        case 37: {
            updateRotY(-0.1); //defined in model.js			
            break;
        }

        //up arrow key was pressed (38 in ASCII)
        case 38: {
            updateEye(0.4); //defined in model.js
            break;
        }

        //right arrow key was pressed (39 in ASCII)
        case 39: {
            updateRotY(0.1); //defined in model.js
            break;
        }

        //down arrow key was pressed (40 in ASCII)
        case 40: {
            updateEye(-0.4); //defined in model.js
            break;
        }

        //ESC key was pressed
        case 27: {
            resetModel(); //defined in model.js
            break;
        }
         //a key was pressed (65 in ASCII)
        case 65:
        {
            updateRotY(-0.1); //defined in model.js
            break;
        }
        //w key was pressed (87 in ASCII)
        case 87:
        {
            updateEye(0.4); //defined in model.js
            break;   
        }
        //s key was pressed (83 in ASCII)
        case 83:
        {
            updateEye(-0.4);    //defined in model.js    
            break;
        }
        // d key was pressed (68 in ASCII)
        case 68: 
        {
            updateRotY(0.1); //defined in model.js
            break;
        }
    }
    isNearNPC();
    isNearRobot1();
    isNearRobot2();

    //If both robot friends are found, player wins and game resets
    if(foundRobot1 && foundRobot2){
      alert('Thanks for helping me find all my friends! You WON! 🥳')
      resetModel();
      nearNPC = false;
      nearRobot1= false;
      nearRobot2 = false;
      foundRobot1 = false;
      foundRobot2 = false;
      clock = 0;
      }

    //If the clock hits the time limit, player loses and game resets
    if(clock >= 35){ //20
      alert('OH NO!\nTime is up!\n💥💥💥💥💥💥💥\n💥💥💥💥💥💥💥\n💥💥💥💥💥💥💥')
      resetModel();
      nearNPC = false;
      nearRobot1= false;
      nearRobot2 = false;
      foundRobot1 = false;
      foundRobot2 = false;
      clock = 0;
    }
    //redraw the scene so that we can see changes
    drawModel(); //defined in model.js
}

//Checks to see if player is near the main robot
function isNearNPC(){
  if(!nearNPC){
    if(checkNear(0,0,0, 5)){
      alert('Not me. Find my friends!');
      nearNPC = true;
    }
  }
  else{
    if(!checkNear(0,0,0, 5)){
      nearNPC = false;
    }
  }
}

//checks to see if player is near one of the robot friends
function isNearRobot1(){
  if(!nearRobot1){
    if(checkNear(25,0,-28, 5)){
      alert('You found me!');
      nearRobot1 = true;
      foundRobot1 = true;
    }
  }
  else{
    if(!checkNear(25,0,-28, 5)){
      nearRobot1 = false;
    }
  }
}

//checks to see if player is near the other robot friend
function isNearRobot2(){
  if(!nearRobot2){
    if(checkNear(25,0,28, 5)){
      alert('You found me!');
      nearRobot2 = true;
      foundRobot2 = true;
    }
  }
  else{
    if(!checkNear(25,0,28, 5)){
      nearRobot2 = false;
    }
  }
}

function controller() {
    //set up the view and the model
    view = initView();  //initView is defined in view.js
    model = initModel(view); //initModel is defined in model.js
    if (model) //make sure everything got initialized before proceeding
    {
        drawModel(); // defined in model.js
        alert('            🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖\nHello! I am Robot. Help me to find my friends! They are hiding behind the walls.\nYou have 35 seconds to find them before the room EXPLODES. BE FAST! 🏎\n\nInstructions: use arrow keys (or wasd) to move left-right and back-forward. Hold keyboard keys and move with your mouse to look around.\n            🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖🤖');
        nearNPC = false;
        nearRobot1= false;
        nearRobot2 = false;
        foundRobot1 = false;
        foundRobot2 = false;
        clock = 0;
        timer = setInterval(incrementTime, 1000);
        //updateCountdown();
        
      
        window.onmousemove = checkMouse;
        window.onkeydown = checkKey; //call checkKey whenever a key is pressed
    }
    else
    {
        alert('Could not initialize the view and model');
    }
}

function incrementTime(){
  clock++;
}

//Mouse function to look around (based on rotations)
function checkMouse(e)
{
    if (e.movementX < 0)
    {    
        updateRot(1, -0.05);
    }
    else if (e.movementX > 0)
    {
        updateRot(1, 0.05);
    } 
    if(e.movementY < 0)
    {
        updateRot(2, 0.05);
    }
    else if(e.movementY > 0){
        updateRot(2, -0.05);
    }
    drawModel();
}   