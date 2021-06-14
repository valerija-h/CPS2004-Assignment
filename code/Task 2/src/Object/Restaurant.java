package Object;

import java.util.ArrayList;

public class Restaurant {
    private String restaurantName;
    private String deliveryType;
    private float profit;
    private ArrayList<Item> items;

    public Restaurant(String restaurantName, String deliveryType){
        this.restaurantName = restaurantName;
        this.deliveryType = deliveryType;
        items = new ArrayList<>();
        profit = 0f;
    }

    //Returns a price for a particular item.
    public float getPrice(String name) throws Exception{
        for(Item item :items) {
            if (item.getItemName().equals(name)) {
                return item.getItemPrice();
            }
        }
        throw new Exception("Error getprice() - Item "+name+" can't be found in " + restaurantName + ".");
    }

    public void addItem(String itemName, float itemPrice){ items.add(new Item(itemName,itemPrice)); }
    public ArrayList<Item> getItems() { return items; }
    public void addProfit(float amount){ profit += amount; }
    public float getProfit(){ return profit; }
    public String getRestaurantName(){return restaurantName;}
    public String getDeliveryType(){return deliveryType;}
}
