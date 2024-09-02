<?php
echo ("Hello World from outside HTML body<br>");
echo ("-----------------------------------new section-----------------------------------<br>");

$course_name = "DSML";
$semester = 4;
$session = "Spring";
echo ("Course Name: " . $course_name . "<br>" . "Semester: " . $semester . "<br>" . "Session: " . $session . "<br>");
echo ("-----------------------------------new section-----------------------------------<br>");
$conn = mysqli_connect("localhost", "root", "", "dsml_c11");

if (mysqli_connect_error())
    die("Connection failed: " . mysqli_connect_error());
else
    echo "Connected without a hitch!<br>";

?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP Practice</title>
</head>

<body
    style="border-left: 20px; border-top: 20px ;">
    <?php
    echo ("Hello World from inside a HTML body<br>");
    echo ("-----------------------------------new section-----------------------------------<br>");
    $number = 39;
    $grade = "";
    if ($number >= 80)
        $grade = "A";
    elseif ($number >= 70)
        $grade = "B";
    elseif ($number >= 60)
        $grade = "C";
    elseif ($number >= 50)
        $grade = "D";
    else
        $grade = "F";
    echo ("Grade: " . $grade . "<br>");
    echo ("-----------------------------------new section-----------------------------------<br>");

    $course_id = 2222;
    switch ($course_id) {
        case 1111:
            echo ("Course: MM<br>");
            break;
        case 2222:
            echo ("Course: DSM<br>");
            break;
        case 3333:
            echo ("Course: ADA<br>");
            break;
        case 4444:
            echo ("Course: MLD<br>");
            break;
        default:
            echo ("Course: Unknown<br>");
    }
    echo ("-----------------------------------new section-----------------------------------<br>");

    for ($i = 0; $i <= 15; $i++) {
        echo ("Number is: " . $i . "<br>");
    }
    echo ("-----------------------------------new section-----------------------------------<br>");

    $array_variable = array("MM", "DSM", "ADA", "MLD", "DSML", "ADAL");
    for ($i = 0; $i < count($array_variable); $i++) {
        echo ("Course: " . $array_variable[$i] . "<br>");
    }
    echo ("-----------------------------------new section-----------------------------------<br>");

    $associated_array = [
        "MM" => 1111,
        "DSM" => 2222,
        "ADA" => 3333,
        "MLD" => 4444,
        "DSML" => 5555,
        "ADAL" => 6666
    ];
    foreach ($associated_array as $key => $value) {
        echo ("Course: $key, Course ID: $value <br>");
    }

    echo ("-----------------------------------new section-----------------------------------<br>");

    //insert into users automatically
    // $insert_name = "John";
    // $insert_age = 30;
    // $sql = "INSERT INTO users (name, age) VALUES ('$insert_name', $insert_age)";
    // if ($conn->query($sql) === TRUE) {
    //     echo "New record created successfully<br>";
    // } else {
    //     echo "Error: " . $sql . "<br>" . $conn->error;
    // }

    // echo ("-----------------------------------new section-----------------------------------<br>");

    ?>
    <h2>Add a New User</h2>
    <form method="post" action="">
        <label for="name">Name:</label><br>
        <input type="text" id="name" name="name" required><br><br>

        <label for="age">Age:</label><br>
        <input type="number" id="age" name="age" required><br><br>

        <input type="submit" value="Submit">
    </form>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $insert_name = $_POST['name'];
        $insert_age = $_POST['age'];

        $sql = "INSERT INTO users (name, age) VALUES ('$insert_name', $insert_age)";
        if ($conn->query($sql) === TRUE) {
            echo "New record created successfully<br>";
            // header("Location: " . $_SERVER['PHP_SELF']);
            // exit();
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        echo ("-----------------------------------new section-----------------------------------<br>");
    }

    ?>

</body>

</html>