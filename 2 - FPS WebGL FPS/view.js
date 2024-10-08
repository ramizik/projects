//FileName:		view.js
//Programmers: Ramis Hasanli, Wil Bauer, Vanessa Kan
//Programmer:	Dan Cliburn
//Date:			8/7/2020
//Purpose:		This file defines the code for our view
//The "view" is our our graphics area (i.e. the "canvas").

let canvas; //The canvas variable can be accessed in any function

function getCanvas() 
{
    return canvas;
}

//setup and return the canvas to the caller
function initView()
{
    canvas = document.getElementById('webgl-canvas');
    if (!canvas) 
    {
        console.error('Sorry! No HTML5 Canvas was found on this page');
        return null;
    }
    return canvas;
}