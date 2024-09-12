# Project Title: DORMSTORM

## Team Members and Responsibilities
- **Raymond Lee**: Responsible for front end development using HTML, CSS, and React. Ideated and drafted the entire Figma draft, a draft that would be used by all team members in the creation of the web app. Played a role at the beginning of the project deciding on what customer requirements our team should focus on to create a useful but unique app.


- **Nathan Pader**: Responsible for front end development using HTML, CSS, and React.  Focused on creating the filters and the different views for the dorms.  Also in charge of collecting information about each individual dorm.


- **Ramis Hasanli**: Responsible for back-end development, implementing api routes and running pylint test.  Also initiated database table and attributes.


- **John Ponce**: Responsible for full-stack development.  In frontend, I created the comparison housing page and focused on developing a working functionality for the app such as the filter and sorting of the dorms.  For the backend, I facilitated the creation of api routes as well as setting up the database.  I was also responsible for setting up the environment to accommodate different operating systems and software dependencies.  Lastly, I deployed the app using Netlify for the frontend and Railway for the backend.

## Project Objectives
- **Value Delivered to Client**: Developed an app with two core features highly requested by the client:
  1. **Comparison**: As an incoming first-year Pacific student, I would like to compare the amenities offered by different residence halls, so that I can choose the one that best suits my preferences and needs
  2. **Housing Options Viewing**: As a first-year Pacific student, I would like to explore various on-campus housing options, so that I can make a decision about where to live during my first year at university


- Complete the following **3 out of 6 requirements** provided by the customer, aiming to implement the ones that other external apps do not already do:
  1. As a first-year Pacific student, I would like to explore various on-campus housing options, so that I can make a decision about where to live during my first year at university
  2. As an incoming first-year Pacific student, I would like to compare the amenities offered by different residence halls, so that I can choose the one that best suits my preferences and needs
  3. As an incoming first year student at Pacific, I would like to receive guidance on the housing application procedures, so that I can successfully complete the application process and secure my preferred housing
 

 - Given the other customer requirements as below, we chose to prioritize the aforementioned requirements above since these other requirements below could already be fulfilled with existing apps.
    1. As new Pacific student, I would like to access information about roommate matching services, so that I can find compatible roommates to share the space with.
    2. As an incoming first year Pacific student, I would like to attend housing information sessions, so that I can gain understanding of what housing options are available.
    3. As an incoming Pacific student, I would like to schedule tours of different housing facilities, so that I can physically see the living spaces and facilities before making a decision.

	Given the requirements from the customer, we placed most of our focus toward the implementation of features that we believed would make our app the most unique and give the maximal value to users. Hence, the two primary objectives of our app were the creation of features that would allow comparison between dorms and displaying housing options. These objectives were chosen in particular since we believed that no other existing app or service would allow users to compile and then compare UOP dorms in the specific way we desire. Since these objectives could not be achieved using any other app, they would be more irreplaceable. Additionally, these two project objectives directly fulfilled the customer’s initial requirements of the app which asked for the ability for first-year Pacific students to “compare the amenities offered by different residence halls” and “explore various on-campus housing options, so that I can make a decision about where to live during my first year at university.” Both of these objectives were implemented through the creation of a “Housing Selection Page” and “Dorm Comparison Page.” With both of these core objectives implemented, objectives that could not be replicated with another existing app or service, we already delivered great value to the user.


## Project Design
- **Approach**: 
  The project design was centered around this strategy: creating a simple webapp that maximizes the value to the end user with as few features as possible. Thus, we focused on creating an intuitive webapp that is visually appealing, aiming for a few well implemented over many unpolished features. This maximizes the value of each feature that we did end up implementing. Lastly, in order to deliver the most value with our given features, we avoided implementing features in the app that are already done well by other applications. In doing so, we could maximize the value given to users, since a user would most likely find a better solution for some features. For instance, we avoided creating a scheduling interface for information sessions or a voice meeting system to attend housing information sessions as suggested by the customer since all of this could already be done by other apps quite well.


- **Team Goals**:
  Our team aimed to develop an innovative application that serves as a showcase project for our resumes, providing tangible evidence of our technical skills and problem-solving capabilities. We intended to avoid creating any games, focusing instead on building a tool or service that has real-world utility and aligns with current industry demands. We desire to have this project serve as a platform for us to explore and implement emerging or popular existing technologies such as React and other technologies, thereby equipping us with relevant skills for our future careers. Throughout the development process, we sought to employ industry-standard practices, including version control with Git and collaborative development using GitHub, to ensure our workflow mirrors professional environments. Ultimately, all of these team goals were aimed at maximizing the amount of industry-relevant skills we would be able to hone - avoiding pitfalls that would prevent that.


- **Zenhub**:
  - <img src="README Assets/Zenhub1.png" width="80%" height="80%"/>
  - <img src="README Assets/Zenhub2.png" width="80%" height="80%"/>


- **Sprint-by-Sprint Breakdown**:

	| Sprint   | Expected                | Actual                   |
	|----------|-------------------------|--------------------------|
	| Sprint 1 | 5 stories, 50 points    | 5 stories, 50 points     |
	| Sprint 2 | 6 stories, 60 points    | 6 stories, 60 points     |
	| Sprint 3 | 7 stories, 45 points    | 7 stories, 45 points     |
	| Sprint 4 | 8 stories, 49 points    | 8 stories, 49 points     |
	| Sprint 5 | 5 stories, 50 points    | 5 stories, 50 points     |
	| **Total**| 31 stories, 254 points  | 31 stories, 254 points   |

- **Completion Details**
  - **31 Stories Completed in Total**: There were no stories that went uncompleted, and we achieved everything we set out to do.
  - **Total Complexity Points**: 254


## Implementation Details
- **Programming Languages**:
  - `JavaScript`: Used with React-Vite for client-side development.
  - `Python`: Used with Flask on the server side
  - `SQL`: Used for managing the PostgreSQL database


- **Libraries and Tools**:
  - **Client Side**: React with Vite
    - `React`: A JavaScript library for building user interfaces.
    - `Vite`: A build tool for modern web development, providing quick setup and auto-updates for React projects
  - **Server Side**: Flask and Flask-RESTful
    - `Flask`: A lightweight and flexible Python web framework for building web applications
    - `Flask-RESTful`: An extension for Flask that adds support for quickly building REST APIs
  - **Database**: PostgreSQL with ElephantSQL
    - `PostgreSQL`: A powerful open-source relational database management system
    - `ElephantSQL`: A cloud-based database service that integrates seamlessly with Flask for handling CRUD operations
    

- **Challenges and Solutions**:
  - **Frontend**: 
    - Learning a new technology like React was challenging, especially since it wasn't covered in any previous classes
      - Overcame the learning curve with React by dedicating time to understand and utilize its components effectively
    - Utilizing React components
      - Overcame by investing time to learn and effectively utilize React components for reusability
    - Designing and planning website page
      - Created `figma` 
    
  - **Backend**:
    - Frontend-Backend Communication: Integrating React frontend with Flask backend
      - Utilize `RESTful API` endpoints to facilitate communication between frontend and backend components
    - User Contact System Implementation: Creating a contact form with email notifications involved integrating frontend form submission with backend email handling
      - Integrated frontend form submission with backend email handling using the `smtplib` framework


  - **Setup & Deployment**: 
    - Configuring the development environment to accommodate different operating systems and software dependencies
      - Created README file which contains instructions for client-side installation, server-side installation, running `PyTest`, and running `PyLint`
    - Configuring code for deployment and deploying both frontend and backend components to reliable hosting platforms
      - Configured code for deployment using hosting platforms like Netlify for frontend and Railway for backend, ensuring reliable deployment processes

## Test Cases
  - Refer to `Testing.md` file for more information

## Project Highlights (Retrospective)
- Parts of the actual software you are proud of
  - **UI**: Proud of mirroring the Figma draft exactly, enhancing usability and user experience
  - **Functionality**: Implemented challenging features like filters and comparison tools effectively
  - **Detail**: Successfully displayed detailed and relevant information for each dorm


- Things you guys did as a team that you think worked really well
  - **Individual time and communication**:
    - At the beginning of the project, we had meetings often almost every day we could and it was hindering our progress. This was because the time we would meet wouldn’t be effective in comparison to independent time. We then switch to a system of taking tasks and communicating with each other. This then allowed us to get more time to get straight into the work and we would only meet in person once or twice a week to assess our progress
  - **Figma draft**:
    - The Figma draft of the webpages was a major help that allowed us as a team to all visualize the end goal of the project to have the same idea. This allowed us to have something to work towards instead of all of us having our interpretations. It also allowed us to figure out the formatting of the webpage


- Troubles that you ended up solving or finding
  - **Learning react**:
    - Learning react/ using react was our first major trouble because it was a new technology to the majority of the group. Our solution was to take the first week to familiarize ourselves with react and then begin trying to use it in the following sprint
  - **Traversing CSS**:
    - Learning and using CSS was one of our major issues because of how confusing it can be to apply it to the whole of the application. Our solution was to trial and error using CSS and having different files for each page/feature reducing the amount of confusion
  - **Merging Work**:
    - Merging work was another major trouble we encountered because of how much of the files we worked on were the same so we had to merge often. Our solution was working in different branches and then merging after so the process became less arduous and less frequent


## Things to be Improved
- **Software Improvements**: 
  - Add more features and images for each dorm, and possibly create individual pages for each dorm instead of linking to the official website.
- **Teamwork/Process**: 
  - Improve communication clarity regarding individual responsibilities to avoid conflicts and redundant work.

## Lessons Learned
- **Advice for Future COMP 129 Students**: 
  - Start early and plan efficiently. Our successes were because of these two pieces of advice. This was because of efficient planning in our first few meetings and the implementation of a Figma, draft got everyone on the same page and had everyone understanding who was doing what for the following weeks. This combined with the early start allowed us to achieve greatness and complete many stories
