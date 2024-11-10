document.getElementById('inventoryForm').addEventListener('submit', function (e) {
    e.preventDefault();

    // Get form values
    const productName = document.getElementById('productName').value;
    const quantity = document.getElementById('quantity').value;
    const price = document.getElementById('price').value;

    // Add product to inventory list
    addToInventoryList(productName, quantity, price);

    // Reset the form
    e.target.reset();
});

function addToInventoryList(productName, quantity, price) {
    const productList = document.getElementById('productList');
    const listItem = document.createElement('li');
    listItem.textContent = `${productName} - Quantity: ${quantity}, Price: $${price}`;
    productList.appendChild(listItem);
}
