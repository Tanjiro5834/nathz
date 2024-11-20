<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "inventory";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

mysqli_report(MYSQLI_REPORT_ERROR | MYSQLI_REPORT_STRICT);

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(isset($_POST['productName'], $_POST['quantity'], $_POST['price'])){
        $productname = $_POST['productName'];
        $quantity = $_POST['quantity'];
        $price = $_POST['price'];
    
        $stmt = $conn->prepare("INSERT INTO product (product_name, quantity, price) VALUES (?, ?, ?)");
        $stmt->bind_param("sid", $productname, $quantity, $price);
    
        if ($stmt->execute()) {
            echo "Product added successfully";
        } else {
            echo "Error: " . $stmt->error;
        }
        $stmt->close();
    }else{
        echo "Form data missing.";
    }
}
$conn->close();
?>
