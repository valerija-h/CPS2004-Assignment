package Object;

//Defines a single item in a Restaurant item list.
class Item {
    private String itemName;
    private float itemPrice;

    Item(String itemName, float itemPrice){
        this.itemName = itemName;
        this.itemPrice = itemPrice;
    }
    String getItemName() { return itemName; }
    float getItemPrice() { return itemPrice; }
}
