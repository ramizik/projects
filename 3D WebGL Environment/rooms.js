//FileName:		rooms.js
//Programmers: Ramis Hasanli, Wil Bauer, Vanessa Kan
//Date:	11/18/2022
//Purpose: This file defines the code for our rooms.

//These variables can be accessed in any function
let roomsVAO;

//Set up the buffer and VAO we need for rendering the ground
function initRooms(gl) {
    //Vertex position data for the ground
    const positions = [-20.0, 10.0, -30.0, //back-R
                        -20.0, 0.0, -30.0,
                        -20.0, 10.0, -20.0,
                        -20.0, 0.0, -20.0,                 
                        20.0, 10.0, -30.0, //back-L
                        20.0, 0.0, -30.0,
                        20.0, 10.0, -10.0,
                        20.0, 0.0, -10.0,
                        20.0, 10.0, 20.0, // front - L1 
                        20.0, 0.0,  20.0,
                        0.0,  10.0, 20.0,
                        0.0,  0.0,  20.0,
                        20.0, 10.0, 20.0, // front - L2 
                        20.0, 0.0,  20.0,
                        20.0, 10.0, 0.0,
                        20.0, 0.0, 0.0,
                        30, 10, 0,   //center -  L
                        30, 0, 0,
                        20, 10, 0,
                        20, 0, 0,
                        -10, 10, 20, //front - R
                        -10, 0, 20,
                        -30, 10, 20,
                        -30, 0, 20,
                        -10, 10, -10, //back - R2
                        -10, 0, -10,
                        -30, 10, -10,
                        -30, 0, -10,
                       -20, 10, 20, //center - R
                        -20, 0, 20,
                        -20, 10, 0,
                        -20, 0, 0
    ];

    //Set up Vertex Array Object for the ground
    roomsVAO = gl.createVertexArray();
    gl.bindVertexArray(roomsVAO);

    //Set up the VBO for the vertex positions 
    var vertexPB = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, vertexPB);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(positions), gl.STATIC_DRAW);
    gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(0); //vertex position will be passed to the vertex shader in location 0

    
    //Clean
    gl.bindVertexArray(null);
    gl.bindBuffer(gl.ARRAY_BUFFER, null);
}


//We call drawGround to render the background model
function drawRooms(gl, color, shininess) 
{  
    //bind the VAO for the WALLS
    gl.bindVertexArray(roomsVAO);
    
    gl.vertexAttrib3f(1, 1, 0.7, 0.4); //use a static vertex attribute (location == 1) to set color
    gl.vertexAttrib3f(2, 0, 0, 1); //use a static vertex attribute (location == 2) to set the normal vector
    gl.vertexAttrib1f(3, shininess); //use a static vertex attribute (location == 3) to set shininess
    gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);
    gl.drawArrays(gl.TRIANGLE_STRIP, 4, 4);
    gl.drawArrays(gl.TRIANGLE_STRIP, 8, 4);
    gl.drawArrays(gl.TRIANGLE_STRIP, 12, 4);
    gl.drawArrays(gl.TRIANGLE_STRIP, 16, 4);
  gl.drawArrays(gl.TRIANGLE_STRIP, 20, 4);
  gl.drawArrays(gl.TRIANGLE_STRIP, 24, 4);
  gl.drawArrays(gl.TRIANGLE_STRIP, 28, 4);


    //Clean
    gl.bindVertexArray(null);
    gl.bindBuffer(gl.ARRAY_BUFFER, null);
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, null);
}