//FileName:		walls.js
//Programmers: Ramis Hasanli, Wil Bauer, Vanessa Kan
//Date:	11/18/2022
//Purpose: This file defines the code for textured walls.
//These variables can be accessed in any function
let wallsVAO;

//Set up the buffer and VAO we need for rendering the ground
function initWalls(gl) {
    //Vertex position data for the ground
    const positions = [-30.0, 20.0, -30.0, //back
                        -30.0, 0.0, -30.0,
                        30.0, 20.0, -30.0,
                        30.0, 0.0, -30.0,
                        30.0, 20.0, 30.0, //front
                        30.0, 0.0, 30.0,
                        -30.0, 20.0, 30.0,
                        -30.0, 0.0, 30.0,
                        30.0, 20.0, -30.0, //right
                        30.0, 0.0, -30.0,
                        30.0, 20.0, 30.0,
                        30.0, 0.0, 30.0,
                        -30.0, 20.0, 30.0, //left
                        -30.0, 0.0, 30.0,
                        -30.0, 20.0, -30.0,
                        -30.0, 0.0, -30.0,
    ];
    const tex_coords = [0.0, 0.0,
        0.0, 1.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 0.0,
        0.0, 1.0,
        1.0, 0.0,
        1.0, 1.0,
        0.0, 0.0,
        0.0, 1.0,
        1.0, 0.0,
        1.0, 1.0, 
        0.0, 0.0,
        0.0, 1.0,
        1.0, 0.0,
        1.0, 1.0 
    ];

    //Set up Vertex Array Object for the ground
    wallsVAO = gl.createVertexArray();
    gl.bindVertexArray(wallsVAO);

    //Set up the VBO for the vertex positions 
    var vertexPB = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, vertexPB);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(positions), gl.STATIC_DRAW);
    gl.vertexAttribPointer(0, 3, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(0); //vertex position will be passed to the vertex shader in location 0

    var tcBuffer = gl.createBuffer();
    gl.bindBuffer(gl.ARRAY_BUFFER, tcBuffer);
    gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(tex_coords), gl.STATIC_DRAW);
    gl.vertexAttribPointer(4, 2, gl.FLOAT, false, 0, 0);
    gl.enableVertexAttribArray(4);

    //Clean
    gl.bindVertexArray(null);
    gl.bindBuffer(gl.ARRAY_BUFFER, null);
}


//We call drawGround to render the background model
function drawWalls(gl, color, shininess) 
{  
    //bind the VAO for the WALLS
    gl.bindVertexArray(wallsVAO);
    
    gl.vertexAttrib3f(2, 0, 0, 1); //use a static vertex attribute (location == 2) to set the normal vector
    gl.vertexAttrib1f(3, shininess); //use a static vertex attribute (location == 3) to set shininess
    gl.drawArrays(gl.TRIANGLE_STRIP, 0, 4);

    gl.vertexAttrib3f(2, 0, 0, 1); //use a static vertex attribute (location == 2) to set the normal vector
    gl.vertexAttrib1f(3, shininess); //use a static vertex attribute (location == 3) to set shininess
    gl.drawArrays(gl.TRIANGLE_STRIP, 4, 4);

    gl.vertexAttrib3f(2, 0, 0, 1); //use a static vertex attribute (location == 2) to set the normal vector
    gl.vertexAttrib1f(3, shininess); //use a static vertex attribute (location == 3) to set shininess
    gl.drawArrays(gl.TRIANGLE_STRIP, 8, 4);
    
    gl.vertexAttrib3f(2, 0, 0, 1); //use a static vertex attribute (location == 2) to set the normal vector
    gl.vertexAttrib1f(3, shininess); //use a static vertex attribute (location == 3) to set shininess
    gl.drawArrays(gl.TRIANGLE_STRIP, 12, 4);

    //Clean
    gl.bindVertexArray(null);
    gl.bindBuffer(gl.ARRAY_BUFFER, null);
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, null);
}