### Question 1: Signup and Login Page (10 marks)

#### Requirements:

- **Signup Page**:
    - Create a signup page that allows new users to create an account.
    - The form should include:
        - Username
        - Password (stored in an encrypted format)
        - Email
    - Save the user data into a MySQL database table named `users`.

- **Login Page**:
    - Create a login page where users can enter their username and password.
    - On successful login, redirect them to a welcome page with a "Logout" option.
    - Use session handling to manage the login and logout state.

- **Database Setup**:
    - Create a `users` table in MySQL with the following fields:
        - `id` (Primary key, Auto Increment)
        - `username` (Unique)
        - `password` (Encrypted using `md5` or `password_hash`)
        - `email`
    - Ensure appropriate validation for the form (e.g., email format, username uniqueness).

---

### Question 2: Student Form Submission and Data Display (15 marks)

#### Requirements:

- **Student Information Form**:
    - Create a webpage with a form that collects student details:
        - Name
        - Email
        - Date of Birth
        - Gender (Dropdown)
        - Department (Dropdown or Radio Buttons)
        - Address (Textarea)
    - Store the submitted data into a MySQL database table named `students`.

- **Database Setup**:
    - Create a `students` table in MySQL with the following fields:
        - `id` (Primary key, Auto Increment)
        - `name`
        - `email`
        - `dob` (Date of Birth)
        - `gender`
        - `department`
        - `address`

- **Display Data in Table**:
    - On another webpage, retrieve and display all student information from the database in a list or table format.
    - Ensure proper formatting of data in the table (e.g., DOB in `YYYY-MM-DD` format, gender and department showing text).

- **Bonus**: (Optional, 5 Marks)
    - Add a search/filter functionality on the student list webpage, allowing the user to filter students by department.
