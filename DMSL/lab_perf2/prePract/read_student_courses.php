<?php
session_start();

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "practice";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $student_id = $_POST['student_id'];

    $sql = "SELECT courses.course_id, courses.course_name
            FROM courses
            JOIN enrollments ON enrollments.course_id = courses.course_id
            JOIN students ON students.student_id = enrollments.student_id
            WHERE students.student_id = ?";

    $stmt = $conn->prepare($sql);
    $stmt->bind_param("i", $student_id);
    $stmt->execute();
    $result = $stmt->get_result();

    $tableRows = '';

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $tableRows .= "<tr>";
            $tableRows .= "<td>" . $row["course_id"] . "</td>";
            $tableRows .= "<td>" . $row["course_name"] . "</td>";
            $tableRows .= "</tr>";
        }
    } else {
        $tableRows = "<tr><td colspan='2'>0 results</td></tr>";
    }

    $_SESSION['tableRows'] = $tableRows;

    $stmt->close();
    $conn->close();

    header("Location: index.php");
    exit();
}
?>
