//FileName:		model.js
//Programmers: Ramis Hasanli, Wil Bauer, Vanessa Kan
//Programmer:	Dan Cliburn
//Date:			9/22/2020
//Purpose:		This file defines the code for our WebGL 2 model
//The "model" is all of the WebGL2 code that draws our graphics scene
//These variables can be accessed in any function
let gl;
let phong_tex_program, toon_program, point_sprite_program;
let projection_matrix, view_matrix, model_matrix;
let rotY, eye = [], aim = []; //variables to control movement
let modelMatrixLoc, viewMatrixLoc, projectionMatrixLoc;
let floorText, wallsText, NPCText, robot1Text, robot2Text;
let mat4;

function getGLContext(canvas) {
    return canvas.getContext('webgl2') || console.error('WebGL2 is not available in your browser.');
}

function getShader(id) {
    const script = document.getElementById(id);
    const shaderString = script.text.trim();
   
    // Assign shader depending on the type of shader  
    let shader;  
    if (script.type === 'shader.vert') 
    {    
        shader = gl.createShader(gl.VERTEX_SHADER);
    }  
    else if (script.type === 'shader.frag') 
    {    
        shader = gl.createShader(gl.FRAGMENT_SHADER);
    }  
    else 
    {    
        return null;  
    }  
    // Compile the shader using the supplied shader code  
    gl.shaderSource(shader, shaderString);
    gl.compileShader(shader);
    // Ensure the shader is valid  
    if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS))
    {
        console.error(gl.getShaderInfoLog(shader));
        return null;
    }
    return shader;
}

//Load all of the shader programs
function initPrograms()
{
    //Load, compile, and link the shader code for the phong_tex_program
    const vertexShader1 = getShader('phong-tex-vertex-shader');
    const fragmentShader1 = getShader('phong-tex-fragment-shader');
    phong_tex_program = gl.createProgram(); //create a program 
      
    gl.attachShader(phong_tex_program, vertexShader1); //Attach the vertex shader to this program
    gl.attachShader(phong_tex_program, fragmentShader1); //Attach the fragment shader to this program
    gl.linkProgram(phong_tex_program);
    if (!gl.getProgramParameter(phong_tex_program, gl.LINK_STATUS))
    {
        console.error('Could not initialize phong_tex_program shaders');
    }
    
    //Load, compile, and link the shader code for the toon_program
    const vertexShader2 = getShader('toon-vertex-shader');
    const fragmentShader2 = getShader('toon-fragment-shader');
    toon_program = gl.createProgram(); //create a program 
      
    gl.attachShader(toon_program, vertexShader2); //Attach the vertex shader to this program
    gl.attachShader(toon_program, fragmentShader2); //Attach the fragment shader to this program
    gl.linkProgram(toon_program);
    if (!gl.getProgramParameter(toon_program, gl.LINK_STATUS))
    {
        console.error('Could not initialize phong_tex_program shaders');
    }

    //Load, compile, and link the shader code for the point_sprite_program
    const vertexShader3 = getShader('point-sprite-vertex-shader');
    const fragmentShader3 = getShader('point-sprite-fragment-shader');
    point_sprite_program = gl.createProgram(); //create a program 
      
    gl.attachShader(point_sprite_program, vertexShader3); //Attach the vertex shader to this program
    gl.attachShader(point_sprite_program, fragmentShader3); //Attach the fragment shader to this program
    gl.linkProgram(point_sprite_program);
    if (!gl.getProgramParameter(point_sprite_program, gl.LINK_STATUS))
    {
        console.error('Could not initialize point_sprite_program shaders');
    }
}

//Find the locations of the matrices in the active shader program
function initMatrices(program)
{
    modelMatrixLoc = gl.getUniformLocation(program, "modelMatrix");
    viewMatrixLoc = gl.getUniformLocation(program, "viewMatrix");
    projectionMatrixLoc = gl.getUniformLocation(program, "projectionMatrix");
}

//Initialize the light for the active shader program
function initLights(program)
{
    //setup directional lights
    var directionalLightColor = gl.getUniformLocation(program, "light_color");
    var directionalLightPos = gl.getUniformLocation(program, "light_position");
    var globalAmbientLightLoc = gl.getUniformLocation(program, "globalAmbientLight");

    gl.uniform3f(globalAmbientLightLoc, 0.4, 0.4, 0.4);  //minimum light level in the scene
    gl.uniform4f(directionalLightColor, 1,1,1,1);
    gl.uniform4f(directionalLightPos, 0.0, 1.0, -1.0, 1);
}

//This function was written to assist with changing the active shader program and binding uniform locations to correct values
function changeShaderProgram(program, lights, projection, view, model) {
    gl.useProgram(program); //set the active shader program

    if (lights == 1) initLights(program); //set up lights to work with this shader program if lights == 1

    initMatrices(program); //set up matrices to work with this shader program, then update to current values
    gl.uniformMatrix4fv(projectionMatrixLoc, false, projection);
    gl.uniformMatrix4fv(viewMatrixLoc, false, view);
    gl.uniformMatrix4fv(modelMatrixLoc, false, model);
}

//initialize all of the buffers we need for our program
function initBuffers()
{
    initGround(gl); //defined in ground.js
    initWalls(gl);
    initRooms(gl);
    initTexSquare(gl);
}

function initTex(id, tex)
{
    var Image = document.getElementById(id);

    //create a texture object, bind an image to the texture object, and define texture filtering modes
    tex = gl.createTexture();
    gl.bindTexture(gl.TEXTURE_2D, tex);
    gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, Image);
    gl.generateMipmap(gl.TEXTURE_2D);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MAG_FILTER, gl.LINEAR);
    gl.texParameteri(gl.TEXTURE_2D, gl.TEXTURE_MIN_FILTER, gl.LINEAR_MIPMAP_LINEAR);



    return tex;
}

//Initialize textures to be used in the program
function initTextures()
{
    floorText = initTex('floor', floorText); //the image with id 'glacier' was loaded in Lab10.html
    wallsText = initTex('wall', wallsText);
    NPCText = initTex('npc', NPCText);
    robot1Text = initTex('npc1', robot1Text);
    robot2Text = initTex('npc2', robot2Text);
    
    //glacierTex = initTex('glacier', glacierTex); //the image with id 'glacier' was loaded in Lab10.html
    gl.bindTexture(gl.TEXTURE_2D, null);
}

//We call drawModel to render to our canvas
function drawModel() 
{  
  
    const color = [1.0, 1.0, 1.0];
    //Clear the scene
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);  
    gl.viewport(0, 0, gl.canvas.width, gl.canvas.height);

    //define the view orientation transformation matrix based on current values for eye, aim, and up
    const up = [0.0, 1.0, 0];
    view_matrix = mat4.lookAt(view_matrix, eye, aim, up);  //calculate the view orientation matrix
    
    // *** Set the active shader program to the toon shader, then bind uniform variables and update matrices for this shader ***
    changeShaderProgram(phong_tex_program, 1, projection_matrix, view_matrix, mat4.identity(model_matrix));
        //Note that the second parameter of 1 indicates that the light uniforms should be bound for this shader

    var samplerLoc = gl.getUniformLocation(phong_tex_program, "tex_image"); //bind samplerLoc for this shader

    // Draw Ground
    gl.activeTexture(gl.TEXTURE0); //Set the current texture number
    gl.uniform1i(samplerLoc, 0); //tell shaders that the sample variable should be associated with gl.TEXTURE0
    gl.bindTexture(gl.TEXTURE_2D, floorText); //use the glacierTex for this square
    drawGround(gl, color, 100); //draw the model of the ground, defined in ground.js
    
    // Draw Walls
    gl.activeTexture(gl.TEXTURE1); //Set the current texture number
    gl.uniform1i(samplerLoc, 1); //tell shaders that the sample variable should be associated with gl.TEXTURE0
    gl.bindTexture(gl.TEXTURE_2D, wallsText); //use the glacierTex for this square
    drawWalls(gl, color, 100); //draw the model of the ground, defined in ground.js

    drawRooms(gl, color, 100);

     // *** Activate and bind uniform variables for the point_sprite_program shader ***
    changeShaderProgram(point_sprite_program, 0, projection_matrix, view_matrix, mat4.identity(model_matrix));
        //Note that the second parameter of 0 indicates that the light uniforms should NOT be bound for this shader
    samplerLoc = gl.getUniformLocation(point_sprite_program, "tex_image"); //bind samplerLoc for this shader

    gl.activeTexture(gl.TEXTURE1); //Set the current texture number
    gl.uniform1i(samplerLoc, 1);
    
    // Main NPC
    gl.bindTexture(gl.TEXTURE_2D, NPCText);
    gl.vertexAttrib3f(0, 0, 2.5, 0); //use a static vertex attribute (location == 0) to set the position to (0,5.0,0)
    gl.drawArrays(gl.POINTS, 0, 1); //draw one point sprite at (0,5.0,0)

    // Robot 1
    gl.bindTexture(gl.TEXTURE_2D, robot1Text);
    gl.vertexAttrib3f(0, 25.0, 1.0, 28.0); //use a static vertex attribute (location == 0) to set the position to (0,5.0,0)
    gl.drawArrays(gl.POINTS, 0, 1); //draw one point sprite at (0,5.0,0)

    // Robot 2
    gl.bindTexture(gl.TEXTURE_2D, robot2Text);
    gl.vertexAttrib3f(0, 25.0, 1.0, -28.0); //use a static vertex attribute (location == 0) to set the position to (0,5.0,0)
    gl.drawArrays(gl.POINTS, 0, 1); //draw one point sprite at (0,5.0,0)

    //Clean
    gl.bindVertexArray(null);
    gl.bindBuffer(gl.ARRAY_BUFFER, null);
    gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, null);
}

//return the WebGL context to the caller
function initModel(view) {
    gl = getGLContext(view); 
    if (gl) {
        gl.clearColor(0.1, 0.1, 0.1, 1.0);
        gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
        gl.viewport(0.0, 0.0, view.width, view.height);
        gl.enable(gl.DEPTH_TEST); //turn on the depth test

        initPrograms(); //load the shader programs

        //Define mat4
        mat4 = glMatrix.mat4;      

        //Create matrices then define the projection transformation matrix here since it never changes
        model_matrix = mat4.create();
        view_matrix = mat4.create();
        projection_matrix = mat4.create();
        projection_matrix = mat4.frustum(projection_matrix, -0.1, 0.1, -0.1, 0.1, 0.1, 100.0);

        //create buffers for all the objects we want to render and load textures we will use
        initBuffers();
        initTextures();

        //initialize movement variables
        rotY = 3.14159 / 2.0; //initial angle is PI/2 (90 degrees) which is looking down the positive z axis 
        eye.push(0.0);
        eye.push(5.0);
        eye.push(-10.0);
        aim.push(0.0);
        aim.push(0.0);
        aim.push(0.0);
        updateEye(0.1); //will sets aim to be looking down the positive z-axis

        return gl;
    }
    return null;
}

function updateEye(offset)
{
    eye[0] += Math.cos(rotY) * offset;
    eye[2] += Math.sin(rotY) * offset;

    //Adjust the aim position from the new eye position
    aim[0] = eye[0] + Math.cos(rotY);
    aim[1] = eye[1];
    aim[2] = eye[2] + Math.sin(rotY);
}

//Rotations with mouse for X-axis and Y-axis where 1 is for y and 2 is for x
function updateRot(axis, offset) {
    if (axis == 1)
        rotY = rotY + offset;
    else if (axis == 2){
        rotX = rotX + offset;

        if(rotX > Math.PI/2){
            rotX = Math.PI/2;
        }
        if(rotX < -Math.PI/2){
            rotX = -Math.PI/2;
        }

    }

    //Adjust the aim position based on the new rotY
    aim[0] = eye[0] + Math.cos(rotY);
    aim[1] = eye[1] + Math.sin(rotX);   
    aim[2] = eye[2] + Math.sin(rotY);
}


//Rotation for left(a) and right(d) keys for keyboard
function updateRotY(offset)
{
    rotY = rotY + offset;

    //Adjust the aim position based on the new rotY
    aim[0] = eye[0] + Math.cos(rotY);
    aim[1] = eye[1];
    aim[2] = eye[2] + Math.sin(rotY);
}

function resetModel() {
    rotY = 3.14159 / 2.0;
    eye[0] = 0.0;
    eye[1] = 5.0;
    eye[2] = -10.0;
    updateRotY(0.0);
}

function checkNear(x, y, z, radius){
  if(Math.abs(eye[0] - x) < radius && Math.abs(eye[2] - z) < radius){
    return true;
  }
  return false
}