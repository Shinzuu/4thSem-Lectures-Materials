<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "set3q2";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} else {
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_POST["name"];
        $email = $_POST["email"];
        $dob = $_POST["dob"];
        $gender = strtolower($_POST["gender"]);  // Make sure gender is lowercase
        $department = strtolower($_POST["department"]);  // Make sure department is lowercase
        $address = $_POST["address"];

        // Ensure gender and department values match ENUM
        $allowed_genders = ['male', 'female'];
        $allowed_departments = ['cse', 'eee'];

        if (in_array($gender, $allowed_genders) && in_array($department, $allowed_departments)) {
            $sql = "INSERT INTO students (name, email, dob, gender, department, address) VALUES ('$name', '$email', '$dob', '$gender', '$department', '$address')";
            $result = mysqli_query($conn, $sql);

            if ($result) {
                echo "Success";
            } else {
                die("Error: " . mysqli_error($conn));
            }
        } else {
            echo "Invalid gender or department value!";
        }
    }
}
?>
<!doctype html>
<html lang="en">
    <head>
        <title>Data Collection</title>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" />
    </head>

    <body>
        <header></header>
        <main>
            <div class="container">
                <h1>Data Form</h1>
                <form action="" method="post">
                    <div class="mb-3">
                        <label for="name" class="form-label">Enter name</label>
                        <input type="text" class="form-control" name="name" id="name" required>
                    </div>
                    <div class="mb-3">
                        <label for="email" class="form-label">Enter email</label>
                        <input type="email" class="form-control" name="email" id="email" required>
                    </div>
                    <div class="mb-3">
                        <label for="dob" class="form-label">DOB</label>
                        <input type="date" class="form-control" name="dob" id="dob" required>
                    </div>
                    <div class="mb-3">
                        <label for="gender" class="form-label">Gender</label>
                        <div class="form-check">
                            <input class="form-check-input" type="radio" name="gender" id="male" value="male" required>
                            <label class="form-check-label" for="male">Male</label>
                        </div>
                        <div class="form-check">
                            <input class="form-check-input" type="radio" name="gender" id="female" value="female" required>
                            <label class="form-check-label" for="female">Female</label>
                        </div>
                    </div>
                    <div class="mb-3">
                        <label for="department" class="form-label">Department</label>
                        <div class="form-check">
                            <input class="form-check-input" type="radio" name="department" id="cse" value="cse" required>
                            <label class="form-check-label" for="cse">CSE</label>
                        </div>
                        <div class="form-check">
                            <input class="form-check-input" type="radio" name="department" id="eee" value="eee" required>
                            <label class="form-check-label" for="eee">EEE</label>
                        </div>
                    </div>
                    <div class="mb-3">
                        <label for="address" class="form-label">Address</label>
                        <input type="text" class="form-control" name="address" id="address" required>
                    </div>
                    <button type="submit" class="btn btn-primary">Submit</button>
                </form>
            </div>
        </main>
        <footer></footer>
        <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js"></script>
        <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.min.js"></script>
    </body>
</html>
