package Object;

import java.util.ArrayList;

//A single Order/node in the OrderList linked list.
public class Order {
    Order next = null;
    private String restaurantName;
    private String deliveryType;
    private ArrayList<String> items;
    private Restaurant restaurant;
    private float total;

    Order(String restaurantName, String deliveryType , ArrayList<String> items, float total, Restaurant restaurant){
        this.restaurantName = restaurantName;
        this.deliveryType = deliveryType;
        this.items = items;
        this.total = total;
        this.restaurant = restaurant;
    }

    public Restaurant getRestaurant(){return restaurant;}
    public float getTotal(){return total;}
    public String getRestaurantName(){return restaurantName;}
    public String getDeliveryType(){return deliveryType;}
    ArrayList<String> getItems(){return items;}
}
