# Testing

## Testing Plan and Strategies (revised/updated)

1. **Testing Strategy:**
    - The overall testing strategy will mainly focus on unit testing that covers important sections for the project. This approach prioritizes testing individual units of code (functions, classes) to ensure their functionality and correctness.

2. **Unit Testing:**
   - Unit tests will be written using:
     - `vitetest:` for the frontend code, focusing on components and their behavior.
     - `pytest:` for the backend code, testing individual functions and classes within the application.
   - Each unit test should focus on a single unit of code (e.g., a function or class)
   - Unit tests should be comprehensive and cover various scenarios

3. **Revision and Updates:**
   - The testing plan and strategies will be revised and updated as the project progresses.
   - New features or changes in the codebase might necessitate additional test cases or adjustments to the testing approach to ensure comprehensive coverage.


## Test Cases

**Frontend (vitetest):**

* **HouseSelection component:**
    * **Test case 1:** Renders correctly without errors.
    * **Test case 2:** Clicking on a DormCard component selects the card and checks the corresponding checkbox.
    * **Test case 3:** Clicking on a selected DormCard deselects the card and unchecks the corresponding checkbox.
    * **Test case 4:** Selecting multiple DormCards checks their corresponding checkboxes.
    * **Test case 5:** Deselecting multiple selected DormCards unchecks their corresponding checkboxes.


* **MinimizeFilter component:**
    * **Test case 1:** Renders correctly with the initial state, displaying the filter title and minimize button.
    * **Test case 2:** Clicking the minimize button for a SliderFilter hides the slider element.
    * **Test case 3:** Clicking the minimize button again for a SliderFilter shows the slider element.
    * **Test case 4:** Clicking the minimize button for a CheckboxFilter hides all the checkbox options.
    * **Test case 5:** Clicking the minimize button again for a CheckboxFilter shows all the checkbox options.

**Backend (pytest):**

* **App creation:**
    * **Test case 1:** Verify that `create_app` returns a valid Flask application instance.
    * **Test case 2:** Ensure blueprints like `dorms` are registered, while others like `bikes` (if not applicable) are not.


* **Database functionality:**
    * **Test case 1:** Verify the existence of expected database tables (e.g., `Dorm`).
    * **Test case 2:** Ensure data has been inserted into the database tables with correct values.


* **API routes:**
    * **Test case 1:** Test the GET `/dorms` route for successful response and data retrieval.
    * **Test case 2:** Verify that non-existent routes like `/students` return a 404 Not Found error.