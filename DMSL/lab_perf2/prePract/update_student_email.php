<?php
    if($_SERVER["REQUEST_METHOD"] == "POST"){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "practice";

        $conn = new mysqli($servername, $username, $password, $dbname);
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $student_id = $_POST["student_id"];
        $new_email = $_POST["new_email"];   

        $sql = "UPDATE students SET email = '$new_email' WHERE student_id = '$student_id'";

        if ($conn->query($sql) === TRUE) {
            echo "Record updated successfully";
            header("Location: index.php");
            exit();
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }
        $conn->close();
    }
?>