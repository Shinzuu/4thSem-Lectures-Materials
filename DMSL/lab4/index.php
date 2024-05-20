<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
include 'connection.php';

if (isset($_POST['submit'])) {
    $roll = $_POST['roll'];
    $name = $_POST['name'];
    $sql = "INSERT INTO `student` (`roll`, `name`) VALUES ('$roll', '$name')";
    $result = mysqli_query($conn, $sql);

    if ($result) {
        echo "<div class='alert alert-success'>Data inserted successfully</div>";
    } else {
        die("<div class='alert alert-danger'>Error inserting data: " . mysqli_error($conn) . "</div>");
    }
}
?>

<!doctype html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>PHP demo</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
  </head>
  <body>
    <div class="container my-5">
        <form method="post">
            <div class="mb-3">
                <label>Roll</label>
                <input type="number" class="form-control" name="roll" autocomplete="off" placeholder="Enter Roll">
            </div>
            <div class="mb-3">
                <label for="name" class="form-label">Name</label>
                <input type="text" class="form-control" name="name" autocomplete="off" placeholder="Enter Name">
            </div>
            <button type="submit" name="submit" class="btn btn-primary">Submit</button>
        </form>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>
  </body>
</html>
