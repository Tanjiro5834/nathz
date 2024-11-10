<?php

$host = 'localhost';
$user = 'root';
$pass = '';
$db = 'todo_list';

$conn = new mysqli($host, $user, $pass, $db);

if($conn->connect_error){
    die("Connection error/failed: " .$conn->connect_error);
}

?>