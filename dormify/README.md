# DORMIFY

Table of Contents:
1. [General Overview of Project](https://github.com/comp129/customer-2024-magneton2024#general-overview-of-project)
2. [Features Implemented](https://github.com/comp129/customer-2024-magneton2024#features-implemented)
3. [Installation Guide](https://github.com/comp129/customer-2024-magneton2024/blob/DORMIFY/README.md#installation-guide)
    - 3.1 [Installation for Users](https://github.com/comp129/customer-2024-magneton2024/blob/DORMIFY/README.md#installation-for-users)
    - 3.2 [Installation for Developers](https://github.com/comp129/customer-2024-magneton2024/blob/DORMIFY/README.md#installation-for-developers)
        - [Client Side](https://github.com/comp129/customer-2024-magneton2024/blob/DORMIFY/README.md#client-side)
        - [Server Side](https://github.com/comp129/customer-2024-magneton2024/blob/DORMIFY/README.md#server-side)
        - [Run PyTest](https://github.com/comp129/customer-2024-magneton2024/blob/DORMIFY/README.md#run-pytest)
        - [Run PyLint](https://github.com/comp129/customer-2024-magneton2024/blob/DORMIFY/README.md#run-pylint)
4. [For More Info](https://github.com/comp129/customer-2024-magneton2024/blob/DORMIFY/README.md#for-more-info)


## General Overview of Project
**Problem:** UOP students, especially first year students, have to select the dorms that they prefer to live in for the coming school year. However, to tedious to find information about UOP's dorms and even harder for students to compare each dorm. As a result, many students choose their dorm preference randomly and are left dissatisfied with their dorm upon living in it.
<br/>
**Solution:** Dormify is a full-stack dorm app that compiles UOP dorm information into one place, allowing users to compare dorms easily and make an informed decision about the dorm they choose. This app is intended to make the entire process of selecting UOP dorms easier for UOP students.

## Features Implemented

1. **Housing Selection Page**
    - **Dorm Filtering:** the dorms displayed in the housing selection page can be filtered down based on the user's preferences.
        - Can filter based on the following dorm attributes:
            - 1.) Semester rates
            - 2.) Minimum meal plan
            - 3.) Other miscellaneous attributes
        - <img src="README Assets/COMP129 - Dorm Filter Feature.gif" width="60%" height="60%"/>
    - **Dorm Search Bar:** a user can search for a specific dorm, showing dorms with matching names within the housing selection page.
        - <img src="README Assets/COMP129 - Dorm Search Feature.gif" width="60%" height="60%"/>
    - **Dorm View Sorting:** a user can sort the order of the dorms displayed in the housing selection page based on certain criteria.
        - <img src="README Assets/COMP129 - Sort Dorms Feature.png" width="60%" height="60%"/>
    - 3 Dorm Option Views:
        - 1.) **Gallery View:** each dorm is displayed with its respective image and attributes.
        - 2.) **List View:** each dorm is displayed in text form for concise viewing.
        - 3.) **Map View:** this view is a map that shows where each dorm is on campus. A user can press on a dorm on the map to see more information about it. This is intended to help students better visualize a dorm's location on campus.
        - <img src="README Assets/COMP129 - Dorm Views Feature.gif" width="60%" height="60%"/>
3. **Dorm Comparison Page:** a user can select dorms from within the housing selection and compare them from within the comparison page as seen below:
    - <img src="README Assets/COMP129 - Housing Comparison Feature.gif" width="60%" height="60%"/>
5. **Frequently Asked Question Page (FAQ):** in the case the user has any questions about the housing selection process, they can refer to the FAQ page to see if their question as been answered already. 
    - <img src="README Assets/COMP129 - FAQ Page.gif" width="60%" height="60%"/>
6. **Contact Us Page:** in the case a user has a question that has not been answered yet in the FAQ page or otherwise need to contact the UOP housing department, they can do so in this page.
    - **Email Messaging:** this feature allows a user to send a message with their attached email to the UOP housing department from within the website itself.
    - <img src="README Assets/COMP129 - Contact Us Feature.gif" width="60%" height="60%"/>

## Installation Guide

### Installation for Users
For users, there is no need to download anything. Simply go to
https://dormstorm.netlify.app/ for the working website.

### Installation for Developers
If your intention is to develop, to install the React app, clone the repo and proceed with the following steps:

#### Client Side
1. Navigate to the client directory: `cd client`
2. Install dependencies: `npm install`
3. Install extra packages: `npm install @fortawesome/fontawesome-free`
4. Run the application: `npm run dev`

#### Server Side
1. Navigate to the server directory: `cd server`
2. Create a virtual environment (if not created already): 
   - Mac Users: `python3 -m venv venv`
   - Window Users: `python -m venv venv`
3. Activate the virtual environment: 
   - Mac Users: `source venv/bin/activate`
   - Window Users: `venv\Scripts\activate`
4. Install required packages (Use `pip` for windows): `pip3 install -r backend/requirements.txt`
5. Run the server: `python3 main.py`

#### Run PyTest
1. Navigate to the server directory: `cd server`
2. Create a virtual environment (if not created already): 
   - Mac Users: `python3 -m venv venv`
   - Window Users: `python -m venv venv`
3. Activate the virtual environment: 
   - Mac Users: `source venv/bin/activate`
   - Window Users: `venv\Scripts\activate`
4. Install required packages (Use `pip` for windows): `pip3 install -r backend/requirements.txt`
5. Install pytest module: `pip3 install pytest`
6. Run the test: `pytest`

#### Run PyLint
1. Navigate to the server directory: `cd server`
2. Create a virtual environment (if not created already): 
   - Mac Users: `python3 -m venv venv`
   - Window Users: `python -m venv venv`
3. Activate the virtual environment: 
   - Mac Users: `source venv/bin/activate`
   - Window Users: `venv\Scripts\activate`
4. Install required packages (Use `pip` for windows): `pip3 install -r backend/requirements.txt`
5. Install pytest module: `pip3 install pylint`
6. Run the test: `pylint --ignore=data.py $(git ls-files '*.py' | grep -v 'test_.*\.py')`

## For More Info
1. Refer to the `TraditionalReport.md` file to read the final report for this project.
    - This report will elaborate more on the project's design, implementation, testing strategies, notable features implemented, improvements yet to be made, and lessons learned.
