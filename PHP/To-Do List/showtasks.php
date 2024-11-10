<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
    <meta charset="utf-8">
    <title>TODO APP</title>
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
</head>
<body>
    <div class="container">
        <h1 class="row">TODO APP</h1>
        <br/><br/>
        <div class="row">
            <form class="form-inline col-sm-offset-3" action="add.php" method="POST">
                <div class="input-group">
                    <span class="input-group-addon">
                    <i class="glyphicon glyphicon-pencil"></i>
                    </span>
                    <input type="text" class="form-control" name="task" placeholder="todo-item" id="box" style="width: 30vw" required />
                </div>
                <div class="form-group">
                    <input type="submit" class="btn btn-primary form-control" value="Add" style="width: 10vw" />
                </div>
            </form>
        </div>
        <div class="row">
            <ul id="list_item">
                <?php
                include 'db.php';

                // Fetch tasks from the database
                $result = $conn->query("SELECT * FROM tasks");
                while ($row = $result->fetch_assoc()) {
                    echo "<li onclick=\"deleteTask(" . $row['id'] . ")\">" . $row['task'] . "</li>";
                }
                $conn->close();
                ?>
            </ul>
        </div>
    </div>
    
    <script type="text/javascript">
        function deleteTask(id) {
            if (confirm("Are you sure you want to delete this task?")) {
                window.location.href = 'delete.php?id=' + id;
            }
        }
    </script>
</body>
</html>
