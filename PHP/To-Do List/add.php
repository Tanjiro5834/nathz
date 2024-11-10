<?php
include 'db.php';
    if($SERVER['REQUEST-METHOD'] == 'POST' && isset($_POST['task'])){
        $task = $_POST['task'];
        $sql = "INSERT INTO tasks (task) VALUES (?)";
    
        $stmt = $conn->prepare($sql);
        $stmt->bind_param("s", $task);
        $stmt->execute();
        $stmt->close();
    }
    $conn->close();
    header("Location: showtasks.php");
    exit;
?>