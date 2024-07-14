<!doctype html>
<html lang="en">

<head>
    <title>Command Center</title>
    <!-- Required meta tags -->
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no" />

    <!-- Bootstrap CSS v5.2.1 -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous" />
</head>

<body>
    <header>
        <!-- place navbar here -->
    </header>
    <main>
        <!-- place main content here -->
        <section class="container" style="padding: 20px; border: 3px dotted magenta;">
            <h5>Adding Student Info</h5>

            <form action="add_student.php" method="post">
                <div class="mb-3">
                    <label for="name" class="form-label">Name</label>
                    <input type="text" class="form-control" name="name" id="name" aria-describedby="helpId" placeholder="John Doe" required />
                </div>
                <div class="mb-3">
                    <label for="email" class="form-label">Email</label>
                    <input type="email" class="form-control" name="email" id="email" aria-describedby="emailHelpId" placeholder="John@mail.com" required />
                </div>
                <button type="submit" class="btn btn-primary">Submit</button>
            </form>
        </section>
        <section class="container" style="padding: 20px; border: 3px dotted Pink;">
            <h5>List of Students</h5>

            <div class="table-responsive">
                <table class="table table-primary">
                    <thead>
                        <tr>
                            <th scope="col">Student ID</th>
                            <th scope="col">Student Name</th>
                            <th scope="col">Student Email</th>
                        </tr>
                    </thead>
                    <tbody id="student_table_row">
                        <!-- Table row via dynamic PHP -->
                        <?php
                        include_once "show_student.php";
                        ?>
                    </tbody>
                </table>
            </div>

        </section>
        <section class="container" style="padding: 20px; border: 3px dotted red;" >
            <h5>Create Course</h5>
            <form action="create_course.php" method="post">
                <div class="mb-3"></div>
                    <label for="course_name" class="form-label">Course Name</label>
                    <input type="text" class="form-control" name="course_name" id="course_name" aria-describedby="helpId" placeholder="Course Name" required />
                </div>
                <div class="mb-3">
                    <label for="course_code" class="form-label">Course Code</label>
                    <input type="text" class="form-control" name="course_code" id="course_code" aria-describedby="emailHelpId" placeholder="Course Code" required />
                </div>
                <button type="submit" class="btn btn-primary">Submit</button>
            </form>
        </section>
        <section class="container" style="padding: 20px; border: 3px dotted blue;">
            <h5>Update Student Email</h5>

            <form action="update_student_email.php" method="post">
                <div class="mb-3">
                    <label for="student_id" class="form-label">Student ID</label>
                    <input type="text" class="form-control" name="student_id" id="student_id" aria-describedby="helpId" placeholder="Student ID" required />
                </div>
                <div class="mb-3">
                    <label for="new_email" class="form-label">New Email</label>
                    <input type="email" class="form-control" name="new_email" id="new_email" aria-describedby="emailHelpId" placeholder="New Email" required />
                </div>
                <button type="submit" class="btn btn-primary">Submit</button>
            </form>
        </section>
    </main>
    <footer>
        <!-- place footer here -->
    </footer>
    <!-- Bootstrap JavaScript Libraries -->
    <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js" integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r" crossorigin="anonymous"></script>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.min.js" integrity="sha384-BBtl+eGJRgqQAUMxJ7pMwbEyER4l1g+O15P+16Ep7Q9Q+zqX6gSbd85u4mG4QzX+" crossorigin="anonymous"></script>
</body>

</html>